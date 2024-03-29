#pragma once
#include "../basic/template.hpp"
template <class T, T (*op)(const T&, const T&)>
class SWAG {
	std::stack<std::pair<T, T>> front, back;

  public:
	SWAG() {}
	SWAG(const std::vector<T> vec) {
		for (const T& i : vec) {
			back.emplace(i, op(back.top().second, i));
		}
	}
	void push(const T& x) {
		if (back.empty())
			back.emplace(x, x);
		else
			back.emplace(x, op(back.top().second, x));
	}
	void pop() {
		if (!front.empty())
			front.pop();
		else {
			auto btop = back.top();
			front.emplace(btop.first, btop.first);
			back.pop();
			while (!back.empty()) {
				btop = back.top();
				front.emplace(btop.first, op(btop.first, front.top().second));
				back.pop();
			}
			front.pop();
		}
	}
	T fold() const {
		if (front.empty()) return back.top().second;
		if (back.empty()) return front.top().second;
		return op(front.top().second, back.top().second);
	}
	unsigned int size() const { return front.size() + back.size(); }
	bool empty() const { return front.empty() && back.empty(); }
};

namespace {
	template <class T>
	T minSWAG_op(const T& lhs, const T& rhs) {
		return std::min(lhs, rhs);
	}
	template <class T>
	T maxSWAG_op(const T& lhs, const T& rhs) {
		return std::max(lhs, rhs);
	}
}  // namespace

template <class T>
class minSWAG : public SWAG<T, minSWAG_op> {};
template <class T>
class maxSWAG : public SWAG<T, maxSWAG_op> {};

/**
 * @title Sliding Window Aggregation
 */