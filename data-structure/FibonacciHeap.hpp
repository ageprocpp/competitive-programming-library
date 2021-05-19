#pragma once
#include "../other/template.hpp"
template <class T, class Compare = std::less<T>>
class FibonacciHeap {
	class Tree {
	  public:
		Tree* par;
		typename std::list<Tree*>::iterator in_par;
		int root_index;
		T root_key;
		std::list<Tree*> children;
		int rank = 0;
		bool damaged = false;

		Tree(int index, T key, Tree* par_ = nullptr)
			: root_index(index), root_key(key), par(par_) {}
		Tree& meld(Tree& t) {
			if (comp(root_key, t.root_key)) std::swap(*this, t);
			children.push_back(&t);
			rank++;
			return *this;
		}
		void cut(FibonacciHeap& heap) {
			if (!par) return;
			if (par->damaged) par->cut(heap);
			par->children.erase(in_par);
			heap.l.emplace_front(this);
		}
	};

	static constexpr int MAX_DEPTH = 30;

	size_t n = 0;
	std::list<Tree*> l;
	std::vector<Tree*> rev;
	typename std::list<Tree*>::iterator top_itr = l.end();
	static Compare comp;
	void update_top() {
		if (empty()) return;
		top_itr = l.begin();
		auto itr = l.begin();
		while (++itr != l.end()) {
			if (comp((*top_itr)->root_key, (*itr)->root_key)) top_itr = itr;
		}
	}

  public:
	FibonacciHeap(int n_) : rev(n_) {}
	~FibonacciHeap() {
		lambda_fix([&](auto self, std::list<Tree*> l) -> void {
			for (auto& i : l) {
				self(self, i->children);
				delete i;
			}
		})(l);
	}
	[[nodiscard]] bool empty() const { return l.empty(); }
	[[nodiscard]] size_t size() const { return n; }
	void push(int index, T key) {
		n++;
		l.emplace_front(new Tree(index, key));
		if (top_itr == l.end() || (*top_itr)->root_key < key)
			top_itr = l.begin();
	}
	void meld(FibonacciHeap& t) { meld(t.l); }
	void meld(std::list<Tree*>& l_) {
		std::array<Tree*, MAX_DEPTH> ar;
		ar.fill(nullptr);
		l.splice(l.end(), l_);
		auto add = lambda_fix([&](auto self, Tree* t) -> void {
			if (!ar[t->rank])
				ar[t->rank] = t;
			else {
				int rank = t->rank;
				t->meld(*ar[rank]);
				ar[rank] = nullptr;
				self(self, t);
			}
		});
		for (const auto& i : l) add(i);
		l.clear();
		for (const auto& i : ar)
			if (i) l.emplace_back(i);
		update_top();
	}
	[[nodiscard]] std::pair<int, T> top() const {
		return {(*top_itr)->root_index, (*top_itr)->root_key};
	}
	void pop() {
		n--;
		auto new_trees = (*top_itr)->children;
		auto tree_address = *top_itr;
		l.erase(top_itr);
		top_itr = l.end();
		meld(new_trees);
		delete tree_address;
		update_top();
	}
	void increase_key(int id, T key) {
		rev[id]->root_key = key;
		rev[id]->cut(*this);
	}
};
template <class T, class Compare>
Compare FibonacciHeap<T, Compare>::comp = Compare();