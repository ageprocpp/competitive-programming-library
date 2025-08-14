#pragma once
#include "../basic/template.hpp"
class WordsizeTree {
	using Word = ulint;
	static constexpr int W = 64;
	int N;
	std::vector<std::vector<Word>> vec;
	static int highBit(Word x) {
		if (!x) return 0;
		return W - 1 - __builtin_clzll(x);
	}
	static int lowBit(Word x) {
		if (!x) return W;
		return __builtin_ctzll(x);
	}

  public:
	WordsizeTree(int N_) : N(N_) {
		int tmp = N;
		do {
			vec.emplace_back(std::vector<Word>(tmp / W + 1, 0));
			tmp /= W;
		} while (tmp);
	}
	void insert(int x) {
		for (auto& v : vec) {
			v[x / W] |= Word(1) << (x % W);
			x /= W;
		}
	}
	void erase(int x) {
		for (auto& v : vec) {
			v[x / W] &= ~(Word(1) << (x % W));
			if (v[x / W]) return;
			x /= W;
		}
	}
	bool contains(int x) const { return (vec[0][x / W] >> (x % W)) & 1; }
	int successor(int x) const {
		if (x < 0) x = -1;
		if (N <= x) return N;
		int d = 0, i = x + 1;
		while (true) {
			if (d >= vec.size()) return N;
			if (i / W >= vec[d].size()) return N;
			Word m = vec[d][i / W] & ((~Word(0)) << (i % W));
			if (!m) {
				d++, i /= W, i++;
			} else {
				i = i / W * W + lowBit(m);
				if (d == 0) break;
				i *= W, d--;
			}
		}
		return i;
	}
	int predecessor(int x) const {
		if (x <= 0) return -1;
		if (N <= x) x = N;
		int d = 0, i = x - 1;
		while (true) {
			if (i < 0) return -1;
			if (d >= vec.size()) return -1;
			Word m = vec[d][i / W] & ~((~Word(1)) << (i % W));
			if (!m) {
				d++, i /= W, i--;
			} else {
				i = i / W * W + highBit(m);
				if (d == 0) break;
				i *= W, i += W - 1, d--;
			}
		}
		return i;
	}
};