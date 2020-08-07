#pragma once
#include "../other/template.hpp"
#include "MyComplex.hpp"
class FastFourierTransform {
private:
	static void dft(std::vector<MyComplex>& poly, const int& inverse) {
		int sz = poly.size();
		if (sz == 1)return;
		std::vector<MyComplex> veca, vecb;
		rep(i, sz>>1) {
			veca[i]=poly[i<<1];
			vecb[i]=poly[i<<1|1];
		}
		dft(veca, inverse); dft(vecb, inverse);
		MyComplex now = 1, zeta = std::polar(1.0, inverse * 2.0 * acos(-1) / sz);
		rep(i, sz) {
			poly[i]=veca[i%(sz>>1)]+now*vecb[i%(sz>>1)];
			now *= zeta;
		}
	}
public:
	template<typename T>
	static std::vector<double> multiply(std::vector<T> f, std::vector<T> g) {
		if(f.size()<g.size())std::swap(f,g);
		std::vector<MyComplex> nf, ng;
		int sz = 1;
		while (sz < f.size() + g.size())sz *= 2;
		nf.resize(sz); ng.resize(sz);
		rep(i, f.size()) {
			nf[i] = f[i];
			if(i<g.size())ng[i] = g[i];
		}
		dft(nf, 1);
		dft(ng, 1);
		rep(i, sz)nf[i] *= ng[i];
		dft(nf, -1);
		std::vector<double> res(sz);
		rep(i, sz)res[i]=nf[i].real() / sz;
		return res;
	}
};