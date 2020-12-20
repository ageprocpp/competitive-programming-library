#pragma once
#include "../other/template.hpp"
template <typename T>
class RBST {
	class Node {
	  public:
		Node *left = nullptr, *right = nullptr;
		T value;
		size_t size;
	};
	Node* root = nullptr;
	RBST(Node* r) : root(r) {}
	static ulint engine() {
		static ulint cur = std::clock();
		cur ^= cur << 13;
		cur ^= cur >> 17;
		cur ^= cur << 5;
		return cur;
	}
	static size_t size(Node* trg) { return trg ? trg->size : 0; }
	static Node* apply(Node* trg) {
		trg->size = size(trg->left) + size(trg->right) + 1;
		return trg;
	}
	static Node* merge(Node* left, Node* right) {
		if (!left) return right;
		if (!right) return left;
		if (engine() % (size(left) + size(right)) < size(left)) {
			left->right = merge(left->right, right);
			return apply(left);
		} else {
			right->left = merge(left, right->left);
			return apply(right);
		}
	}
	static std::pair<Node*, Node*> split(Node* trg, int pos) {
		if (!trg) return {nullptr, nullptr};
		if (pos <= size(trg->left)) {
			auto tmp = split(trg->left, pos);
			trg->left = tmp.second;
			return {tmp.first, apply(trg)};
		} else {
			auto tmp = split(trg->right, pos - size(trg->left) - 1);
			trg->right = tmp.first;
			return {apply(trg), tmp.second};
		}
	}
	static Node* insert(Node* node, int idx, const T& val) {
		auto tmp = split(node, idx);
		return merge(merge(tmp.first, new Node{nullptr, nullptr, val, 1}),
					 tmp.second);
	}
	static Node* erase(Node* node, int idx) {
		auto left = split(node, idx);
		auto right = split(left.second, 1);
		delete right.first;
		return merge(left.first, right.second);
	}
	static Node* build(const std::vector<T>& data, int l, int r) {
		if (r == -1) r = data.size();
		if (data.empty() || l >= r) return nullptr;
		int idx = engine() % (r - l) + l;
		return apply(new Node{build(data, l, idx), build(data, idx + 1, r),
							  data[idx], 1});
	}
	void clear(Node* trg) {
		if (!trg) return;
		clear(trg->left);
		clear(trg->right);
		delete trg;
	}

  public:
	RBST() {}
	RBST(const std::vector<T>& data) { this->build(data); }
	RBST merge(const RBST& trg) { return RBST(merge(root, trg.root)); }
	std::pair<RBST, RBST> split(int pos) {
		auto tmp = split(root, pos);
		return {RBST(tmp.first), RBST(tmp.second)};
	}
	T& find(int idx) const {
		Node* cur = root;
		int cnt = 0;
		while (true) {
			if (cnt + size(cur->left) == idx)
				return cur->value;
			else if (cnt + size(cur->left) > idx)
				cur = cur->left;
			else
				cnt += size(cur->left) + 1, cur = cur->right;
		}
	}
	void insert(int idx, const T& val) { root = insert(root, idx, val); }
	void erase(int idx) { root = erase(root, idx); }
	int upper_bound(int val) const {
		Node* cur = root;
		int res = 0, cnt = 0;
		while (cur) {
			if (cur->value <= val)
				cnt += size(cur->left) + 1, cur = cur->right;
			else {
				res += cnt;
				cnt = 0;
				cur = cur->left;
			}
		}
		return res + cnt;
	}
	int lower_bound(int val) const {
		Node* cur = root;
		int res = 0, cnt = 0;
		while (cur) {
			if (cur->value < val)
				cnt += size(cur->left) + 1, cur = cur->right;
			else {
				res += cnt;
				cnt = 0;
				cur = cur->left;
			}
		}
		return res + cnt;
	}
	void build(const std::vector<T>& data) { root = build(data, 0, -1); }
	void clear() {
		clear(root);
		root = nullptr;
	}
	int size() const { return empty() ? 0 : root->size; }
	bool empty() const { return !root; }
};