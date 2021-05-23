#pragma once
#include "../other/template.hpp"
template <class T, class Compare = std::less<>>
class BinaryHeap {
	std::vector<T> heap;
	Compare comp;

	void up_heap() {
		size_t id = heap.size() - 1;
		while (id > 1) {
			if (comp(heap[id >> 1], heap[id])) {
				std::swap(heap[id >> 1], heap[id]);
				id >>= 1;
			} else
				return;
		}
	}
	void down_heap() {
		size_t id = 1;
		while ((id << 1) < heap.size()) {
			if ((id << 1 | 1) == heap.size()) {
				if (comp(heap[id], heap[id << 1])) {
					std::swap(heap[id], heap[id << 1]);
					id <<= 1;
				} else
					return;
			} else {
				if (comp(heap[id << 1], heap[id << 1 | 1])) {
					if (comp(heap[id], heap[id << 1 | 1])) {
						std::swap(heap[id], heap[id << 1 | 1]);
						id = id << 1 | 1;
					} else
						return;
				} else if (comp(heap[id], heap[id << 1])) {
					std::swap(heap[id], heap[id << 1]);
					id <<= 1;
				} else
					return;
			}
		}
	}

  public:
	BinaryHeap() : heap(1) {}
	[[nodiscard]] bool empty() const noexcept { return heap.size() == 1; }
	[[nodiscard]] size_t size() const noexcept { return heap.size() - 1; }
	[[nodiscard]] T top() const { return heap[1]; }
	void pop() {
		heap[1] = std::move(heap.back());
		heap.pop_back();
		down_heap();
	}

	void push(const T& x) {
		heap.push_back(x);
		up_heap();
	}
	template <class... Args>
	void emplace(Args&&... args) {
		heap.emplace_back(std::forward<Args...>(args...));
		up_heap();
	}
};

/**
 * @title Binary Heap
 */