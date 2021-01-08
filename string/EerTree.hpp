#pragma once
#include "../other/template.hpp"
class EerTree {
	class Node {
	  public:
		int len;
		Node* suffix_link;
		std::map<char, Node*> edges;
		Node(int len) : len(len), suffix_link(nullptr) {}
	};
	std::vector<Node*> last;
	Node* root[2];
	std::string s;
	size_t size_ = 0;
	Node* make(Node* par, char c) {
		if (par->edges.find(c) == par->edges.end()) {
			par->edges[c] = new Node(par->len + 2);
			size_++;
			Node* sl = par->suffix_link;
			if (par->len == -1)
				sl = root[0];
			else {
				while (true) {
					if (s[s.size() - sl->len - 2] == c) {
						sl = sl->edges[c];
						break;
					} else if (sl->len < 0) {
						sl = root[0];
						break;
					} else
						sl = sl->suffix_link;
				}
			}
			par->edges[c]->suffix_link = sl;
		}
		return par->edges[c];
	}

  public:
	void push(char c) {
		Node* last_node = last.empty ? root[1] : last.back();
		for (s += c; s.size() - last_node->len - 2 < 0 ||
					 s[s.size() - last_node->len - 2] != c;
			 last_node = last_node->suffix_link) {
			last_node = make(last_node, c);
		}
		last.emplace_back(last_node);
	}
	EerTree() {
		root[0] = new Node(0);
		root[0]->suffix_link = root[1] = new Node(-1);
		root[1]->suffix_link = root[1];
	}
	EerTree(const std::string& s) : eerTree() {
		for (const char c : s) push(c);
	}
	size_t size() const { return size_; }
	size_t count_end_with(int idx) {
		size_t res = 0;
		for (Node* node = last[idx]; node != root[0] && node != root[1];
			 node = node->suffix_link)
			res++;
		return res;
	}
};