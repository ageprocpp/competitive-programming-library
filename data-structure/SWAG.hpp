#pragma once
#include "../other/template.hpp"
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

/**
 * @title Sliding Window Aggregation
 */