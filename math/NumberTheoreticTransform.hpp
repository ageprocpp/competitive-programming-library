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
	static constexpr int bases[] = {1012924417, 924844033, 998244353,
									1224736769, 167772161, 469762049};
	static constexpr int roots[] = {5, 5, 3, 3, 3, 3};

  private:
	template <int modulo>
	static void ntt(std::vector<StaticModInt<modulo>>& a,
					StaticModInt<modulo> root) {
		int sz = a.size();
		if (sz == 1) return;
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
	template <class T, int modulo>
	static std::vector<StaticModInt<modulo>> internal_convolution(
		const std::vector<T>& f_, const std::vector<T>& g_,
		StaticModInt<modulo> root) {
		std::vector<StaticModInt<modulo>> f(f_.size()), g(g_.size());
		rep(j, f_.size()) f[j] = f_[j];
		rep(j, g_.size()) g[j] = g_[j];
		return internal_convolution(f, g, root);
	}
	template <int modulo>
	static std::vector<StaticModInt<modulo>> internal_convolution(
		std::vector<StaticModInt<modulo>> f,
		std::vector<StaticModInt<modulo>> g, StaticModInt<modulo> root) {
		size_t target_size = f.size() + g.size() - 1, sz = 1;
		while (sz < f.size() + g.size()) sz <<= 1;
		f.resize(sz), g.resize(sz);

		inverse = false;
		ntt(f, root), ntt(g, root);
		rep(i, f.size()) f[i] *= g[i];
		inverse = true;
		ntt(f, root);
		StaticModInt<modulo> inv = StaticModInt<modulo>(f.size()).inv();
		rep(i, f.size()) f[i] *= inv;
		f.resize(target_size);
		return f;
	}

  public:
	static bool inverse;

	template <int modulo, class T>
	static std::vector<StaticModInt<modulo>> convolution(
		const std::vector<T>& f, const std::vector<T>& g) {
#if __cplusplus >= 201703L
		if constexpr
#else
		if
#endif
			(modulo == bases[0] || modulo == bases[1] || modulo == bases[2] ||
			 modulo == bases[3] || modulo == bases[4] || modulo == bases[5]) {
			std::vector<StaticModInt<modulo>> f_(f.size()), g_(g.size());
			rep(i, f.size()) f_[i] = f[i];
			rep(i, g.size()) g_[i] = g[i];
#if __cplusplus >= 201703L
			if constexpr (modulo == bases[0]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[0]));
			} else if constexpr (modulo == bases[1]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[1]));
			} else if constexpr (modulo == bases[2]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[2]));
			} else if constexpr (modulo == bases[3]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[3]));
			} else if constexpr (modulo == bases[4]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[4]));
			} else {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[5]));
			}
#else

			if (modulo == bases[0]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[0]));
			} else if (modulo == bases[1]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[1]));
			} else if (modulo == bases[2]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[2]));
			} else if (modulo == bases[3]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[3]));
			} else if (modulo == bases[4]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[4]));
			} else {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[5]));
			}
#endif
		}
		constexpr int base1 = 998244353, base2 = 1224736769, base3 = 469762049;
		auto re1 = internal_convolution<T, base1>(f, g, 3);
		auto re2 = internal_convolution<T, base2>(f, g, 3);
		auto re3 = internal_convolution<T, base3>(f, g, 3);
		std::vector<StaticModInt<modulo>> res(re1.size());
		constexpr int r12 = StaticModInt<base2>(base1).inv();
		constexpr int r13 = StaticModInt<base3>(base1).inv();
		constexpr int r23 = StaticModInt<base3>(base2).inv();
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
	template <int modulo>
	static std::vector<StaticModInt<modulo>> convolution(
		std::vector<StaticModInt<modulo>> f,
		std::vector<StaticModInt<modulo>> g) {
#if __cplusplus >= 201703L
		if constexpr
#else
		if
#endif
			(modulo == bases[0] || modulo == bases[1] || modulo == bases[2] ||
			 modulo == bases[3] || modulo == bases[4] || modulo == bases[5]) {
			std::vector<StaticModInt<modulo>> f_(f.size()), g_(g.size());
			rep(i, f.size()) f_[i] = f[i];
			rep(i, g.size()) g_[i] = g[i];
#if __cplusplus >= 201703L
			if constexpr (modulo == bases[0]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[0]));
			} else if constexpr (modulo == bases[1]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[1]));
			} else if constexpr (modulo == bases[2]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[2]));
			} else if constexpr (modulo == bases[3]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[3]));
			} else if constexpr (modulo == bases[4]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[4]));
			} else {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[5]));
			}
#else

			if (modulo == bases[0]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[0]));
			} else if (modulo == bases[1]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[1]));
			} else if (modulo == bases[2]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[2]));
			} else if (modulo == bases[3]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[3]));
			} else if (modulo == bases[4]) {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[4]));
			} else {
				return internal_convolution<modulo>(
					f_, g_, StaticModInt<modulo>(roots[5]));
			}
#endif
		}
		constexpr int base1 = 998244353, base2 = 1224736769, base3 = 469762049;
		auto re1 = internal_convolution<StaticModInt<modulo>, base1>(
			f, g, StaticModInt<base1>(3));
		auto re2 = internal_convolution<StaticModInt<modulo>, base2>(
			f, g, StaticModInt<base2>(3));
		auto re3 = internal_convolution<StaticModInt<modulo>, base3>(
			f, g, StaticModInt<base3>(3));
		std::vector<StaticModInt<modulo>> res(re1.size());
		constexpr int r12 = StaticModInt<base2>(base1).inv();
		constexpr int r13 = StaticModInt<base3>(base1).inv();
		constexpr int r23 = StaticModInt<base3>(base2).inv();
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
	static std::vector<lint> convolution_plain(std::vector<T> f,
											   std::vector<T> g) {
		const int mod1 = 998244353, mod2 = 1224736769;
		std::vector<StaticModInt<mod1>> mul1 =
			internal_convolution<T, mod1>(f, g, StaticModInt<mod1>(3));
		std::vector<StaticModInt<mod2>> mul2 =
			internal_convolution<T, mod2>(f, g, StaticModInt<mod2>(3));
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