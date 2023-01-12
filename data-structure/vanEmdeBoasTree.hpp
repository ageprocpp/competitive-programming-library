#pragma once
#include "../other/template.hpp"

template <uint bit>
class vanEmdeBoasTree {
	int min = -1, max = -1;
	static int upper(int x) { return x >> bit / 2; }
	static int lower(int x) { return x & (1 << bit / 2) - 1; }
	static int index(int x, int y) { return (x << bit / 2) | y; }
	vanEmdeBoasTree<(bit + 1) / 2> summary;
	std::array<vanEmdeBoasTree<bit / 2>, 1 << (bit + 1) / 2> cluster;

  public:
	vanEmdeBoasTree() = default;
	int minimum() const { return min; }
	int maximum() const { return max; }
	bool contains(int x) const {
		if (x == min || x == max) return true;
		return cluster[upper(x)].contains(lower(x));
	}
	int successor(int x) const {
		if (min != -1 && x < min) return min;
		const int x_upper = upper(x), x_lower = lower(x);
		const int max_low = cluster[x_upper].maximum();
		if (max_low != -1 && x_lower < max_low)
			return index(x_upper, cluster[x_upper].successor(x_lower));
		const int succ_cluster = summary.successor(x_upper);
		if (succ_cluster == -1) return -1;
		return index(succ_cluster, cluster[succ_cluster].minimum());
	}
	int predecessor(int x) const {
		if (max != -1 && max < x) return max;
		const int x_upper = upper(x), x_lower = lower(x);
		const int min_low = cluster[x_upper].minimum();
		if (min_low != -1 && min_low < x_lower)
			return index(x_upper, cluster[x_upper].predecessor(x_lower));
		const int pred_cluster = summary.predecessor(x_upper);
		if (pred_cluster == -1) {
			if (min != -1 && min < x) return min;
			return -1;
		}
		return index(pred_cluster, cluster[pred_cluster].maximum());
	}
	void insert(int x) {
		if (min == -1) {
			min = max = x;
			return;
		}
		if (x == min) return;
		if (x < min) std::swap(x, min);

		const int x_upper = upper(x), x_lower = lower(x);
		if (cluster[x_upper].minimum() == -1) summary.insert(x_upper);
		cluster[x_upper].insert(x_lower);
		if (x > max) max = x;
	}
	void erase(int x) {
		if (min == max) {
			if (x == min) min = max = -1;
			return;
		}
		if (x == min) {
			int first_cluster = summary.minimum();
			x = index(first_cluster, cluster[first_cluster].minimum());
			min = x;
		}
		const int x_upper = upper(x), x_lower = lower(x);
		cluster[x_upper].erase(x_lower);
		if (cluster[x_upper].minimum() == -1) {
			summary.erase(x_upper);
			if (x == max) {
				int summary_max = summary.maximum();
				if (summary_max == -1)
					max = min;
				else
					max = index(summary_max, cluster[summary_max].maximum());
			}
		} else if (x == max)
			max = index(x_upper, cluster[x_upper].maximum());
	}
};

template <>
class vanEmdeBoasTree<1> {
	int min = -1, max = -1;

  public:
	vanEmdeBoasTree() {}
	int minimum() const { return min; }
	int maximum() const { return max; }
	bool contains(int x) const {
		if (x == min || x == max) return true;
		return false;
	}
	int successor(int x) const {
		if (x == 0 && max == 1) return 1;
		return -1;
	}
	int predecessor(int x) const {
		if (x == 1 && min == 0) return 0;
		return -1;
	}
	void insert(int x) {
		if (min == -1) min = max = x;
		if (x < min) std::swap(x, min);
		if (x > max) max = x;
	}
	void erase(int x) {
		if (min == max) {
			if (x == min) min = max = -1;
			return;
		}
		if (x == 0)
			min = max = 1;
		else
			min = max = 0;
	}
};