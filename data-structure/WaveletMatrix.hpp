#pragma once
#include "../other/template.hpp"
#include "SuccinctBitVector.hpp"
class WaveletMatrix {
	std::vector<SuccinctBitVector> bit;
	std::vector<int> head, fvec;

  public:
	template <class T>
	WaveletMatrix(std::vector<T> vec) {
		for (int i = 63; i >= 0; i--) {
			std::vector<bool> bvec;
			for (T j : vec) bvec.emplace_back(j & ((lint)1 << i));
			std::stable_sort(all(vec), [&i](const T& lhs, const T& rhs) {
				return (lhs & ((lint)1 << i)) < (rhs & ((lint)1 << i));
			});
			if (!(vec.back() & ((lint)1 << i))) continue;
			bit.emplace_back(bvec);
		}
		fvec = vec;
		std::reverse(all(bit));
		head.resize(vec.size());
		REP(i, vec.size() - 1) {
			if (vec[i - 1] == vec[i])
				head[i] = head[i - 1];
			else
				head[i] = i;
		}
	}
	int rank(int r, lint c) const {
		for (int i = bit.size() - 1; i >= 0; i--) {
			r--;
			if (c & ((lint)1 << i))
				r = bit[i].rank(false, bit[i].size() - 1) +
					bit[i].rank(true, r);
			else
				r = bit[i].rank(false, r);
		}
		return r - head[r];
	}
	int quantile(int l, int r, int k) const {
		for (int i = bit.size() - 1; i >= 0; i--) {
			int zeroc = bit[i].rank(false, r - 1),
				onec = bit[i].rank(true, r - 1);
			zeroc -= l == 0 ? 0 : bit[i].rank(false, l - 1);
			onec -= l == 0 ? 0 : bit[i].rank(true, l - 1);
			if (k <= zeroc) {
				l = l == 0 ? 0 : bit[i].rank(false, l - 1);
				r = l + zeroc;
			} else {
				l = bit[i].rank(false, bit[i].size() - 1) +
					(l == 0 ? 0 : bit[i].rank(true, l - 1));
				r = l + onec;
				k -= zeroc;
			}
		}
		return fvec[l];
	}
};