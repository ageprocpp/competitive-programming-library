#pragma once
#include "../basic/template.hpp"

// assign priorities to indexed nodes
template <class T, class Compare = std::less<>>
class PrioritizableBinaryHeap {
	std::vector<std::pair<int, T>> heap;
	std::vector<int> rev;
	Compare comp;

	void up_heap(int id = -1) {
		if (id == -1) id = heap.size() - 1;
		while (id > 1) {
			auto &vp = heap[id >> 1], &vx = heap[id];
			if (comp(vp.second, vx.second)) {
				std::swap(rev[vp.first], rev[vx.first]);
				std::swap(vp, vx);
				id >>= 1;
			} else
				return;
		}
	}
	void down_heap(int id = 1) {
		while ((id << 1) < heap.size()) {
			int il = id << 1, ir = id << 1 | 1, swap = -1;
			auto &vl = heap[il], &vx = heap[id];
			if (comp(vx.second, vl.second)) swap = il;
			if (ir < heap.size()) {
				auto& vr = heap[ir];
				if (comp(vx.second, vr.second)) {
					if (swap == -1 || comp(vl.second, vr.second)) swap = ir;
				}
			}
			if (swap == -1) return;
			std::swap(rev[vx.first], rev[heap[swap].first]);
			std::swap(vx, heap[swap]);
			id = swap;
		}
	}

  public:
	PrioritizableBinaryHeap(int n) : heap(1), rev(n, -1) {}
	[[nodiscard]] bool empty() const noexcept { return heap.size() == 1; }
	[[nodiscard]] size_t size() const noexcept { return heap.size() - 1; }
	[[nodiscard]] auto top() const noexcept { return heap[1]; }
	auto pop() {
		const auto tmp = heap[1];
		rev[heap.back().first] = 1;
		rev[heap[1].first] = -1;
		heap[1] = std::move(heap.back());
		heap.pop_back();
		down_heap();
		return tmp;
	}
	void push(int id, const T& x) {
		rev[id] = heap.size();
		heap.emplace_back(id, x);
		up_heap();
	}
	void prioritize(int id, const T& x) {
		if (heap[rev[id]].second > x)
			decrease_key(id, x);
		else
			increase_key(id, x);
	}
	void decrease_key(int id, const T& x) {
		if (rev[id] == -1) {
			push(id, x);
			return;
		}
		heap[rev[id]].second = x;
		down_heap(rev[id]);
	}
	void increase_key(int id, const T& x) {
		if (rev[id] == -1) {
			push(id, x);
			return;
		}
		heap[rev[id]].second = x;
		up_heap(rev[id]);
	}
};

/**
 * @title Prioritizable Binary Heap
 */