#pragma once
#include "../other/template.hpp"
template <class T, bool withindex = false>
class SparseTable {
	using U = std::conditional_t<withindex, std::pair<T, int>, T>;
	std::vector<std::vector<U>> table;
	std::vector<int> logtable;

  public:
	SparseTable() {}
	SparseTable(const std::vector<T>& vec) { init(vec); }
	void init(const std::vector<T>& vec) {
		int maxlength = 0;
		while ((1 << (maxlength + 1)) <= vec.size()) maxlength++;
		table.resize(maxlength + 1, std::vector<U>(vec.size()));
		logtable.resize(vec.size() + 1);
		rep(i, vec.size()) {
			if constexpr (withindex)
				table[0][i] = {vec[i], i};
			else
				table[0][i] = vec[i];
		}
		REP(i, maxlength) {
			rep(j, vec.size() - (1 << i) + 1) {
				table[i][j] =
					std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
			}
		}
		logtable[1] = 0;
		for (int i = 2; i <= vec.size(); i++) {
			logtable[i] = logtable[i >> 1] + 1;
		}
	}
	template <class InputIter>
	SparseTable(InputIter first, InputIter last) {
		std::vector<T> vec;
		while (first != last) {
			vec.emplace_back(*first);
		}
		init(vec);
	}
	U query(int l, int r) {
		int length = r - l;
		return std::min(table[logtable[length]][l],
						table[logtable[length]][r - (1 << logtable[length])]);
	}
};

/**
 * @title Sparse Table
 */