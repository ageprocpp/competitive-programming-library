#pragma once
#include "../other/template.hpp"
#include "MyComplex.hpp"
class FastFourierTransform {
private:
	/*static void dft(std::vector<MyComplex>& poly, const int& inverse) {
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
	}*/
	static void dft(std::vector<MyComplex>& a){
		int sz=a.size();
		if(sz==1)return;
		MyComplex root=std::polar(1.0,(inverse?-1:1)*2.0*acos(-1)/sz);
		std::vector<MyComplex> b(sz),roots((sz>>1)+1,1);
		rep(i,sz>>1)roots[i+1]=roots[i]*root;
		for(int i=sz>>1,w=1;w<sz;i>>=1,w<<=1){
			for(int j=0;j<i;j++){
				for(int k=0;k<w;k++){
					b[k+((w*j)<<1)]=a[k+w*j]+a[k+w*j+(sz>>1)];
					b[k+((w*j)<<1)+w]=roots[w*j]*(a[k+w*j]-a[k+w*j+(sz>>1)]);
				}
			}
			std::swap(a,b);
		}
	}
public:
	static bool inverse;
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
		inverse=false;
		dft(nf);dft(ng);
		rep(i, sz)nf[i] *= ng[i];
		inverse=true;
		dft(nf);
		std::vector<double> res(sz);
		rep(i, sz)res[i]=nf[i].real() / sz;
		return res;
	}
};
bool FastFourierTransform::inverse=false;