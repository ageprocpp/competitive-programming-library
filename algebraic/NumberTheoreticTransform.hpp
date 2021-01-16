#pragma once
#include "../other/template.hpp"
#include "StaticModInt.hpp"
// 1012924417, 5, 2^21
// 924844033, 5, 2^21
// 998244353, 3, 2^23
// 1224736769, 3, 2^24
// 167772161, 3, 2^25
// 469762049, 3, 2^26
class NumberTheoreticTransform {
	static constexpr uint bases[] = {1012924417, 924844033, 998244353,
									1224736769, 167772161, 469762049};

  private:
	template <unsigned int modulo>
	static void ntt(std::vector<StaticModInt<modulo>>& a) {
		int sz = a.size();
		if (sz == 1) return;
		StaticModInt<modulo> root =
			modulo == 924844033 || modulo == 1012924417 ? 5 : 3;
		if (inverse)
			root = mypow(root, modulo - 1 - (modulo - 1) / sz);
		else
			root = mypow(root, (modulo - 1) / sz);
		std::vector<StaticModInt<modulo>> b(sz), roots((sz >> 1) + 1, 1);
		rep(i, sz >> 1) roots[i + 1] = roots[i] * root;
		for (int i = sz >> 1, w = 1; w < sz; i >>= 1, w <<= 1) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < w; k++) {
					b[k + ((w * j) << 1)] =
						a[k + w * j] + a[k + w * j + (sz >> 1)];
					b[k + ((w * j) << 1) + w] =
						roots[w * j] *
						(a[k + w * j] - a[k + w * j + (sz >> 1)]);
				}
			}
			std::swap(a, b);
		}
	}
	template <uint modulo, typename T>
	static std::vector<StaticModInt<modulo>> internal_multiply(
		const std::vector<T>& f, const std::vector<T>& g) {
		std::vector<StaticModInt<modulo>> nf(f.size()), ng(g.size());
		rep(j, f.size()) nf[j] = f[j];
		rep(j, g.size()) ng[j] = g[j];
		inverse = false;
		ntt(nf);
		ntt(ng);
		rep(i, nf.size()) nf[i] *= ng[i];
		inverse = true;
		ntt(nf);
		StaticModInt<modulo> inv = StaticModInt<modulo>(nf.size()).inv();
		rep(i, nf.size()) nf[i] *= inv;
		return nf;
	}

  public:
	static bool inverse;

	template <uint modulo, typename T>
	static std::vector<StaticModInt<modulo>> multiply(std::vector<T> f,
													  std::vector<T> g) {
		size_t sz = 1;
		while (sz < f.size() + g.size()) sz <<= 1;
		f.resize(sz);
		g.resize(sz);
		rep(i, 6) {
			if (modulo == bases[i]) return internal_multiply<modulo>(f, g);
		}
		constexpr uint base1 = 998244353, base2 = 1224736769, base3 = 469762049;
		auto re1 = internal_multiply<base1>(f, g);
		auto re2 = internal_multiply<base2>(f, g);
		auto re3 = internal_multiply<base3>(f, g);
		std::vector<StaticModInt<modulo>> res(re1.size());
		constexpr int r12 = StaticModInt<base2>(base1).inv();
		constexpr int r13 = StaticModInt<base3>(base1).inv();
		constexpr int r23 = StaticModInt<base3>(base2).inv();
		constexpr int p12 = StaticModInt<modulo>(base1) * base2;
		rep(i, re1.size()) {
			re2[i] = StaticModInt<base2>(re2[i] - re1[i]) * r12;
			re3[i] =
				(StaticModInt<base3>(re3[i] - re1[i]) * r13 - re2[i]) * r23;
			res[i] = (StaticModInt<modulo>(re1[i]) +
					  StaticModInt<modulo>(re2[i]) * base1 +
					  StaticModInt<modulo>(re3[i]) * base1 * base2);
		}
		return res;
	}
	template <class T>
	static std::vector<lint> multiply_plain(std::vector<T> f,
											std::vector<T> g) {
		const uint mod1 = 998244353, mod2 = 1224736769;
		std::vector<StaticModInt<mod1>> mul1 = internal_multiply<mod1>(f, g);
		std::vector<StaticModInt<mod2>> mul2 = internal_multiply<mod2>(f, g);
		std::vector<lint> res(mul1.size());
		rep(i, mul1.size()) res[i] =
			ChineseRem(mul1[i], mod1, mul2[i], mod2).first;
		return res;
	}
};
bool NumberTheoreticTransform::inverse = false;

/**
 * @title NumberTheoreticTransform
 */