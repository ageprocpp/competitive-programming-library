#pragma once
#include "../other/template.hpp"
template <class T, bool withindex = false>
class SparseTable {
	using U = std::conditional_t<withindex, std::pair<T, int>, T>;
	std::vector<std::vector<U>> table;
	std::vector<int> logtable;

	template <bool wi, class dummy_type = void>
	class initializer {
	  public:
		void operator()(SparseTable<T, wi>& st, const std::vector<T>& vec) {
			int maxlength = 0;
			while ((1 << (maxlength + 1)) <= vec.size()) maxlength++;
			st.table.resize(maxlength + 1, std::vector<T>(vec.size()));
			st.logtable.resize(vec.size() + 1);
			rep(i, maxlength + 1) {
				rep(j, vec.size() - (1 << i) + 1) {
					if (i) {
						st.table[i][j] =
							std::min(st.table[i - 1][j],
									 st.table[i - 1][j + (1 << (i - 1))]);
					} else {
						st.table[i][j] = vec[j];
					}
				}
			}
			st.logtable[1] = 0;
			for (int i = 2; i <= vec.size(); i++) {
				st.logtable[i] = st.logtable[i >> 1] + 1;
			}
		}
	};
	template <class dummy_type>
	class initializer<true, dummy_type> {
	  public:
		void operator()(SparseTable<T, true>& st, const std::vector<T>& vec) {
			int maxlength = 0;
			while ((1 << (maxlength + 1)) <= vec.size()) maxlength++;
			st.table.resize(maxlength + 1, std::vector<T>(vec.size()));
			st.logtable.resize(vec.size() + 1);
			rep(i, maxlength + 1) {
				rep(j, vec.size() - (1 << i) + 1) {
					if (i) {
						st.table[i][j] =
							std::min(st.table[i - 1][j],
									 st.table[i - 1][j + (1 << (i - 1))]);
					} else {
						st.table[i][j] = {vec[j], j};
					}
				}
			}
			st.logtable[1] = 0;
			for (int i = 2; i <= vec.size(); i++) {
				st.logtable[i] = st.logtable[i >> 1] + 1;
			}
		}
	};

  public:
	SparseTable() {}
	SparseTable(const std::vector<T>& vec) { init(vec); }
	void init(const std::vector<T>& vec) { initializer<withindex>()(*this, vec); }
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