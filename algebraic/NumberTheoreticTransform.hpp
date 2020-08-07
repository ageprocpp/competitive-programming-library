#pragma once
#include "../other/template.hpp"
#include "ModInt.hpp"
//167772161,3,2^25
//469762049,3,2^26
//924844033,5,2^21
//998244353,3,2^23
//1012924417,5
//1224736769,3
const unsigned int ModInt::modulo=998244353;
class NumberTheoreticTransform{
private:
	/*static void ntt(std::vector<ModInt>& poly) {
		int sz = poly.size();
		if (sz == 1)return;
		std::vector<ModInt> veca(sz>>1),vecb(sz>>1);
		rep(i, sz>>1) {
			veca[i]=poly[i<<1];
			vecb[i]=poly[i<<1|1];
		}
		ntt(veca);ntt(vecb);
		ModInt now = 1, zeta;
		if(inverse)zeta=mypow(ModInt(3),ModInt::modulo-1-(ModInt::modulo-1)/sz);
		else zeta=mypow(ModInt(3),(ModInt::modulo-1)/sz);
		rep(i, sz) {
			poly[i]=veca[i%(sz>>1)]+now*vecb[i%(sz>>1)];
			now*=zeta;
		}
	}*/
	static void ntt(std::vector<ModInt>& a){
		int sz=a.size();
		if(sz==1)return;
		ModInt root;
		if(inverse)root=mypow(ModInt(3),ModInt::modulo-1-(ModInt::modulo-1)/sz);
		else root=mypow(ModInt(3),(ModInt::modulo-1)/sz);
		std::vector<ModInt> b(sz),roots((sz>>1)+1,1);
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
	static std::vector<ModInt> multiply(std::vector<T> f, std::vector<T> g) {
		if(f.size()<g.size())std::swap(f,g);
		std::vector<ModInt> nf, ng;
		int sz=1;
		while (sz<f.size()+g.size())sz<<=1;
		nf.resize(sz);ng.resize(sz);
		rep(i,f.size()) {
			nf[i]=f[i];
			if(i<g.size())ng[i]=g[i];
		}
		inverse=false;
		ntt(nf);ntt(ng);
		rep(i, sz)nf[i]*=ng[i];
		inverse=true;
		ntt(nf);
		ModInt szinv=ModInt(sz).inv();
		rep(i,sz)nf[i]*=szinv;
		return nf;
	}
};
bool NumberTheoreticTransform::inverse=false;