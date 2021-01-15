#include "../other/template.hpp"
template <class T, bool isMin>
class MonotoneConvexHullTrick {
	static constexpr double INF = DBL_MAX;
	using TP = std::pair<std::pair<T, T>, int>;
	int index = 0;
	std::deque<TP> deq;
	inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
	inline T eval(const TP& a, const T& x) {
		return a.first.first * x + a.first.second;
	}
	inline bool bad(const TP& l1, const TP& l2, const TP& l3) {
		if (l1.first.second == l2.first.second ||
			l2.first.second == l3.first.second) {
			return sgn(l2.first.first - l1.first.first) *
					   sgn(l3.first.second - l2.first.second) >=
				   sgn(l3.first.first - l2.first.first) *
					   sgn(l2.first.second - l1.first.second);
		}
		return (double)(l2.first.first - l1.first.first) *
				   sgn(l3.first.second - l2.first.second) /
				   std::abs(l2.first.second - l1.first.second) >=
			   (double)(l3.first.first - l2.first.first) *
				   sgn(l2.first.second - l1.first.second) /
				   std::abs(l3.first.second - l2.first.second);
	}

  public:
	void addLine(T m, T b) {
		if (!isMin) m = -m, b = -b;
		TP line = {{m, b}, index++};
		if (empty()) {
			deq.emplace_front(line);
			return;
		}
		if (deq.front().first.first <= m) {
			if (deq.front().first.first == m) {
				if (deq.front().first.second <= b) return;
				deq.pop_front();
			}
			while (deq.size() >= 2 && bad(line, deq[0], deq[1]))
				deq.pop_front();
			deq.emplace_front(line);
		} else {
			if (deq.back().first.first == m) {
				if (deq.back().first.second <= b) return;
				deq.pop_back();
			}
			while (deq.size() >= 2 &&
				   bad(deq[deq.size() - 2], deq.back(), line))
				deq.pop_back();
			deq.emplace_back(line);
		}
	}
	std::pair<T, int> query(T x) {
		int l = -1, r = deq.size() - 1;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (eval(deq[m], x) >= eval(deq[m + 1], x))
				l = m;
			else
				r = m;
		}
		return {(isMin ? 1 : -1) * eval(deq[r], x), deq[r].second};
	}
	std::pair<T, int> queryMonotoneInc(T x) {
		while (deq.size() >= 2 && eval(deq[0], x) >= eval(deq[1], x))
			deq.pop_front();
		return {(isMin ? 1 : -1) * eval(deq[0], x), deq[0].second};
	}
	std::pair<T, int> queryMonotoneDec(T x) {
		while (deq.size() >= 2 &&
			   eval(deq.back(), x) >= eval(deq[deq.size() - 2]))
			deq.pop_back();
		return {(isMin ? 1 : -1) * eval(deq.back(), x), deq.back().second};
	}
	bool empty() const { return deq.empty(); }
	void clear() {
		deq.clear();
		index = 0;
	}
};

/**
 * @title Convex Hull Trick for monotone queries
 */