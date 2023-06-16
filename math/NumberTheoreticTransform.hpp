#pragma once
#include "../other/template.hpp"
#include "StaticModInt.hpp"
// 1012924417, 5, 2^21
// 924844033, 5, 2^21
// 998244353, 3, 2^23
// 1224736769, 3, 2^24
// 167772161, 3, 2^25
// 1107296257, 10, 2^25
// 469762049, 3, 2^26
class NumberTheoreticTransform {
	static int constexpr friendly_limit(int p) { return __builtin_ffs(p - 1) - 1; }

  public:
	template <int modulo>
	static void ntt(std::vector<StaticModInt<modulo>>& a, bool inverse,
					int size = -1) {  // size should be one of powers of two
		if (size == -1) size = a.size();
		if (size == 1) return;
		a.resize(size);
		const StaticModInt<modulo> root = StaticModInt<modulo>::primitive_root().pow(
			inverse ? modulo - 1 - (modulo - 1) / size : (modulo - 1) / size);

		std::vector<StaticModInt<modulo>> b(size);
		StaticModInt<modulo> r_p = root;
		for (int i = size >> 1, w = 1; w < size; i >>= 1, w <<= 1) {
			StaticModInt<modulo> r_pp = 1;
			for (int j = 0; j < i; j++, r_pp *= r_p) {
				for (int k = 0; k < w; k++) {
					b[k + ((w * j) << 1)] = a[k + w * j] + a[k + w * j + (size >> 1)];
					b[k + ((w * j) << 1) + w] = r_pp * (a[k + w * j] - a[k + w * j + (size >> 1)]);
				}
			}
			std::swap(a, b);
			r_p *= r_p;
		}
	}

  private:
	template <class T, int modulo>
	static std::vector<StaticModInt<modulo>> internal_convolution(const std::vector<T>& f_,
																  const std::vector<T>& g_) {
		std::vector<StaticModInt<modulo>> f(f_.size()), g(g_.size());
		rep(i, f_.size()) f[i] = f_[i];
		rep(i, g_.size()) g[i] = g_[i];
		return internal_convolution(std::move(f), std::move(g));
	}
	template <int modulo>
	static std::vector<StaticModInt<modulo>> internal_convolution(
		const std::vector<StaticModInt<modulo>>& f, const std::vector<StaticModInt<modulo>>& g) {
		auto f_ = f, g_ = g;
		return internal_convolution(std::move(f_), std::move(g_));
	}
	template <int modulo>
	static std::vector<StaticModInt<modulo>> internal_convolution(
		const std::vector<StaticModInt<modulo>>& f, std::vector<StaticModInt<modulo>>&& g) {
		auto f_ = f;
		return internal_convolution(std::move(f_), std::move(g));
	}
	template <int modulo>
	static std::vector<StaticModInt<modulo>> internal_convolution(
		std::vector<StaticModInt<modulo>>& f, const std::vector<StaticModInt<modulo>>&& g) {
		auto g_ = g;
		return internal_convolution(std::move(f), std::move(g_));
	}
	template <int modulo>
	static std::vector<StaticModInt<modulo>> internal_convolution(
		std::vector<StaticModInt<modulo>>&& f, std::vector<StaticModInt<modulo>>&& g) {
		size_t target_size = f.size() + g.size() - 1, sz = 1;
		while (sz < target_size) sz <<= 1;
		f.resize(sz), g.resize(sz);
		ntt(f, false), ntt(g, false);
		rep(i, f.size()) f[i] *= g[i];
		ntt(f, true);
		StaticModInt<modulo> inv = StaticModInt<modulo>(sz).inv();
		rep(i, f.size()) f[i] *= inv;
		f.resize(target_size);
		return std::move(f);
	}

  public:
	template <int modulo>
	static std::vector<StaticModInt<modulo>> convolution(
		const std::vector<StaticModInt<modulo>>& f, const std::vector<StaticModInt<modulo>>& g) {
		if (1 << friendly_limit(modulo) >= f.size() + g.size() - 1) {
			auto f_ = f, g_ = g;
			return internal_convolution<modulo>(std::move(f_), std::move(g_));
		} else if (1 << friendly_limit(modulo) + 2 >= f.size() + g.size() - 1) {
			int sz = 1 << friendly_limit(modulo) - 1;
			std::vector<std::vector<StaticModInt<modulo>>> f_, g_;
			for (int i = 0; i * sz < f.size(); i++)
				f_.emplace_back(f.begin() + i * sz,
								f.begin() + std::min((int)f.size(), (i + 1) * sz));
			for (int i = 0; i * sz < g.size(); i++)
				g_.emplace_back(g.begin() + i * sz,
								g.begin() + std::min((int)g.size(), (i + 1) * sz));
			std::vector<StaticModInt<modulo>> res(f.size() + g.size() - 1);
			rep(i, f_.size()) {
				rep(j, g_.size()) {
					auto tmp =
						internal_convolution<modulo>(j == g_.size() - 1 ? std::move(f_[i]) : f_[i],
													 i == f_.size() - 1 ? std::move(g_[j]) : g_[j]);
					rep(k, tmp.size()) res[(i + j) * sz + k] += tmp[k];
				}
			}
			return res;
		}
		constexpr int base1 = 167772161, base2 = 1107296257, base3 = 469762049;
		auto re1 = internal_convolution<StaticModInt<modulo>, base1>(f, g);
		auto re2 = internal_convolution<StaticModInt<modulo>, base2>(f, g);
		auto re3 = internal_convolution<StaticModInt<modulo>, base3>(f, g);
		std::vector<StaticModInt<modulo>> res(re1.size());
		constexpr int r12 = StaticModInt<base2>(base1).inv();
		constexpr int r13 = StaticModInt<base3>(base1).inv();
		constexpr int r23 = StaticModInt<base3>(base2).inv();
		rep(i, re1.size()) {
			re2[i] = StaticModInt<base2>(re2[i] - re1[i]) * r12;
			re3[i] = (StaticModInt<base3>(re3[i] - re1[i]) * r13 - re2[i]) * r23;
			res[i] = StaticModInt<modulo>(re1[i]) + StaticModInt<modulo>(re2[i]) * base1 +
					 StaticModInt<modulo>(re3[i]) * base1 * base2;
		}
		return res;
	}
	template <int modulo, class T>
	static std::vector<StaticModInt<modulo>> convolution(const std::vector<T>& f,
														 const std::vector<T>& g) {
		std::vector<StaticModInt<modulo>> f_(f.size()), g_(g.size());
		rep(i, f.size()) f_[i] = f[i];
		rep(i, g.size()) g_[i] = g[i];
		return convolution(f_, g_);
	}
	template <class T>
	static std::vector<lint> convolution_plain(const std::vector<T>& f, const std::vector<T>& g) {
		const int mod1 = 998244353, mod2 = 1224736769;
		std::vector<StaticModInt<mod1>> mul1 = internal_convolution<T, mod1>(f, g);
		std::vector<StaticModInt<mod2>> mul2 = internal_convolution<T, mod2>(f, g);
		std::vector<lint> res(mul1.size());
		rep(i, mul1.size()) res[i] = ChineseRem(mul1[i], mod1, mul2[i], mod2).first;
		return res;
	}
};

/**
 * @title NumberTheoreticTransform
 */