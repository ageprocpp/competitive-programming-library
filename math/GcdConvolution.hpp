#pragma once
#include "../basic/template.hpp"
class GcdConvolution {
  private:
	static std::vector<int> primes;
	static std::vector<bool> is_prime;
	static void update(int N) {
		if (N <= is_prime.size()) return;
		is_prime.resize(N + 1), std::fill(all(is_prime), true), primes.clear();
		for (int i = 2; i <= N; i++) {
			if (!is_prime[i]) continue;
			primes.emplace_back(i);
			for (int j = 2 * i; j <= N; j += i) is_prime[j] = false;
		}
	}
	template <typename T>
	static void fwt(std::vector<T>& f) {
		size_t n = f.size() - 1;
		update(n);
		for (int p : primes) {
			if (p > n) break;
			for (int j = n / p; j >= 1; j--) f[j] += f[j * p];
		}
	}

	template <typename T>
	static void ifwt(std::vector<T>& f) {
		size_t n = f.size() - 1;
		update(n);
		for (int p : primes) {
			if (p > n) break;
			for (int j = 1; j * p <= n; j++) f[j] -= f[j * p];
		}
	}

  public:
	template <typename T>
	static std::vector<T> convolution(const std::vector<T>& f, const std::vector<T>& g) {
		auto nf = f, ng = g;
		fwt(nf), fwt(ng);
		rep(i, nf.size()) nf[i] *= ng[i];
		ifwt(nf);
		return nf;
	}
};
std::vector<int> GcdConvolution::primes = {};
std::vector<bool> GcdConvolution::is_prime = {};