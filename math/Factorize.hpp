#pragma once

#include "../basic/template.hpp"
namespace Factorize {
	inline static lint mul(lint a, lint b, lint n) { return i128(a) * b % n; }
	inline static lint safemodpow(lint a, lint b, lint n) noexcept {
		a %= n;
		lint res(1);
		while (b) {
			if (b & 1) res = mul(res, a, n);
			a = mul(a, a, n), a %= n, b >>= 1;
		}
		return res;
	}
	bool is_prime(lint n) {
		if (n == 2) return true;
		if (n == 1 || (~n & 1)) return false;
		lint d = n - 1;
		while (~d & 1) d >>= 1;
		std::array<lint, 7> test = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
		for (lint i : test) {
			if (i % n == 0) continue;
			lint t = d;
			lint y = safemodpow(i, t, n);
			while (t != n - 1 && y != 1 && y != n - 1) {
				y = mul(y, y, n), t *= 2;
			}
			if (y != n - 1 && t % 2 == 0) return false;
		}
		return true;
	}
	lint find_factor(lint n) {
		if (~n & 1) return 2;
		for (int c = 1; c < n; c++) {
			lint y = 0, g = 1, r = 1, q = 1, k = 0, ys = 0, x = y;
			auto f = [&](lint x) { return (mul(x, x, n) + c) % n; };
			while (g == 1) {
				x = y;
				while (k < 3 * r / 4) y = f(y), k += 1;
				while (k < r && g == 1) {
					ys = y;
					rep(i, std::min(lint(c), r - k)) {
						y = f(y);
						q = mul(q, std::abs(x - y), n);
					}
					g = std::gcd(q, n);
					k += c;
				}
				k = r, r *= 2;
			}
			if (g == n) {
				g = 1;
				y = ys;
				while (g == 1) {
					y = f(y);
					g = std::gcd(std::abs(x - y), n);
				}
			}
			if (g == n) continue;
			if (is_prime(g)) return g;
			if (is_prime(n / g)) return n / g;
			return find_factor(g);
		}
		abort();
	}

	// Pollard's rho algorithm
	std::vector<lint> factorize(lint n) {
		if (n == 1) return {};
		static std::random_device rd;
		static std::mt19937 mt(rd());
		auto trial = [](uint seed, lint m) {
			auto gen_rand = [m, seed](lint s) { return (mul(s, s, m) + seed) % m; };
			lint interval = mt(), x, y = m, r = 1, q = 1, ys, g;
			do {
				x = y;
				REP(i, r) y = gen_rand(y);
				lint k = 0;
				do {
					ys = y;
					REP(i, std::min(interval, r - k)) {
						y = gen_rand(y);
						q = mul(q, std::abs(x - y), m);
					}
					g = gcd(q, m);
					k = k + interval;
				} while (k < r && g == 1);
				r *= 2;
			} while (g == 1);
			if (g == m) {
				do {
					ys = gen_rand(ys);
					g = gcd(std::abs(x - ys), m);
				} while (g == 1);
			}
			return g == m ? -1 : g;
		};
		std::vector<lint> res;
		lambda_fix([&res, &trial](auto self, lint m) {
			if (is_prime(m)) {
				res.emplace_back(m);
				return;
			}
			while (true) {
				lint f = trial(mt(), m);
				if (f != -1) {
					self(self, f);
					self(self, m / f);
					break;
				}
			}
		})(n);
		std::sort(all(res));
		return res;
	}

}  // namespace Factorize