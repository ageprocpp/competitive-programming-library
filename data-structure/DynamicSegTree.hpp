#pragma once
#include "../other/template.hpp"
template <class T, T (*nodef)(const T &, const T &), T (*ident)(),
		  T (*init)() = ident>
class DynamicSegTree {
	class Node {
		Node *par;
		std::shared_ptr<Node> left = nullptr, right = nullptr;

	  public:
		T value;
		Node() : value(init()) {}
		Node(Node *p) : par(p), value(ident()) {}
		void set(const T &v) { value = v; }
		const T &get() const { return value; }
		bool exist_left() const { return bool(left); }
		bool exist_right() const { return bool(right); }
		void eval() {
			T l = !exist_left() ? ident() : left->value;
			T r = !exist_right() ? ident() : right->value;
			value = nodef(l, r);
		}
		auto get_left() {
			if (!exist_left()) left.reset(new Node(this));
			return left;
		}
		auto get_right() {
			if (!exist_right()) right.reset(new Node(this));
			return right;
		}
		auto get_parent() { return par; }
	};
	lint n = 1;
	std::shared_ptr<Node> root;

	auto ptr_from_id(lint id) {
		auto cur = root;
		lint width = n >> 1;
		while (width) {
			if (id & width)
				cur = cur->get_right();
			else
				cur = cur->get_left();
			width >>= 1;
		}
		return cur;
	}

	T query(lint a, lint b, lint l, lint r, std::shared_ptr<Node> ptr) {
		if (r == -1) r = n;
		if (r <= a || b <= l) return ident();
		if (a <= l && r <= b) return ptr->value;
		T vl = ptr->exist_left() ? query(a, b, l, (l + r) >> 1, ptr->get_left())
								 : ident();
		T vr = ptr->exist_right()
				   ? query(a, b, (l + r) >> 1, r, ptr->get_right())
				   : ident();
		return nodef(vl, vr);
	}

  public:
	DynamicSegTree(lint m) {
		while (n < m) n <<= 1;
		root = std::shared_ptr<Node>(new Node);
	}
	void update(lint i, T x) {
		Node *cur = ptr_from_id(i).get();
		cur->set(x);
		while (cur != root.get()) {
			cur = cur->get_parent();
			cur->eval();
		}
	}
	T query(lint a, lint b) { return query(a, b, 0, n, root); }
	const T &operator[](const lint &x) { return ptr_from_id(x)->get(); }
};

/**
 * @title Dynamic Segment Tree
 */