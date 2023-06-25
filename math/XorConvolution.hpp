#pragma once
#include "../basic/template.hpp"
class XorConvolution {
  private:
	template <typename T>
	static void fwt(std::vector<T>& f) {
		size_t n = f.size();
		for (int i = 1; i < n; i <<= 1) {
			rep(j, n) {
				if ((j & i) == 0) {
					T x = f[j], y = f[j | i];
					f[j] = x + y, f[j | i] = x - y;
				}
			}
		}
	}

	template <typename T>
	static void ifwt(std::vector<T>& f) {
		int n = f.size();
		for (int i = 1; i < n; i <<= 1) {
			rep(j, n) {
				if ((j & i) == 0) {
					T x = f[j], y = f[j | i];
					f[j] = (x + y) / 2, f[j | i] = (x - y) / 2;
				}
			}
		}
	}

	template <typename T>
	static std::vector<T> convolution(const std::vector<T>& f,
									  const std::vector<T>& g) {
		auto nf = f, ng = g;
		int tmp = 1;
		while (tmp < nf.size() || tmp < ng.size()) tmp <<= 1;
		nf.resize(tmp), ng.resize(tmp);
		fwt(f), fwt(g);
		rep(i, nf.size()) nf[i] *= ng[i];
		ifwt(f);
		return nf;
	}
};