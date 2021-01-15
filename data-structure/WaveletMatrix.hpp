#pragma once
#include "../other/template.hpp"
#include "SuccinctBitVector.hpp"
template <typename T>
constexpr static int8_t bit_count() {
	int8_t res = 0;
	std::make_unsigned_t<T> x = ~0;
	while (x) {
		res++;
		x >>= 1;
	}
	return res;
}
template <typename T, int8_t word_size = bit_count<T>()>
class WaveletMatrix {
	using i8 = int8_t;

	int N;
	std::array<SuccinctBitVector, word_size> bit;
	std::array<int, word_size> zero_cnt;
	std::vector<int> head;

  public:
	WaveletMatrix(std::vector<T> vec) : N(vec.size()), head(vec.size()) {
		zero_cnt.fill(0);
		std::vector<T> nvec(N);
		std::vector<bool> bvec;
		bvec.reserve(N);
		for (i8 i = word_size - 1; i >= 0; i--) {
			int cnt[] = {0, 0};
			bvec.resize(0);
			for (T j : vec) {
				bvec.emplace_back(j & (1LL << i));
				if (!(j & (1LL << i))) {
					cnt[1]++;
					zero_cnt[i]++;
				}
			}
			nvec.resize(N);
			for (T j : vec) {
				if (j & (1LL << i))
					nvec[cnt[1]++] = j;
				else
					nvec[cnt[0]++] = j;
			}
			vec = std::move(nvec);
			bit[i].init(bvec);
		}
		REP(i, N - 1) {
			if (vec[i - 1] == vec[i])
				head[i] = head[i - 1];
			else
				head[i] = i;
		}
	}
	int rank(int r, lint c) const {
		for (i8 i = word_size - 1; i >= 0; i--) {
			r--;
			if (c & ((lint)1 << i))
				r = bit[i].rank(false, bit[i].size() - 1) +
					bit[i].rank(true, r);
			else
				r = bit[i].rank(false, r);
		}
		return r - head[r];
	}
	T quantile(int l, int r, int k) const {
		T res = 0;
		for (i8 i = word_size - 1; i >= 0; i--) {
			const int z_r = bit[i].rank(false, r - 1), o_r = r - z_r;
			const int z_l = !l ? 0 : bit[i].rank(false, l - 1), o_l = l - z_l;
			if (k <= z_r - z_l) {
				l = z_l;
				r = z_r;
			} else {
				l = r = zero_cnt[i];
				l += o_l;
				r += o_r;
				k -= z_r - z_l;
				res |= (1 << i);
			}
		}
		return res;
	}
};

/**
 * @title Wavelet Matrix
 */