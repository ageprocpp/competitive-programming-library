#pragma once
#include "../other/template.hpp"
#include "StaticModInt.hpp"
//1012924417,5,2^21
//924844033,5,2^21
//998244353,3,2^23
//1224736769,3,2^24
//167772161,3,2^25
//469762049,3,2^26
class NumberTheoreticTransform{
private:
	template<unsigned int modulo>
	static void ntt(std::vector<StaticModInt<modulo>>& a){
		int sz=a.size();
		if(sz==1)return;
		StaticModInt<modulo> root=modulo==924844033||modulo==1012924417?5:3;
		if(inverse)root=mypow(root,modulo-1-(modulo-1)/sz);
		else root=mypow(root,(modulo-1)/sz);
		std::vector<StaticModInt<modulo>> b(sz),roots((sz>>1)+1,1);
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
	template<unsigned int modulo,typename T>
	static std::vector<StaticModInt<modulo>> multiply(std::vector<T> f, std::vector<T> g) {
		if(f.size()<g.size())std::swap(f,g);
		std::vector<StaticModInt<modulo>> nf, ng;
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
		StaticModInt<modulo> szinv=StaticModInt<modulo>(sz).inv();
		rep(i,sz)nf[i]*=szinv;
		return nf;
	}
	template<typename T>
	static std::vector<lint> multiply_plain(std::vector<T> f,std::vector<T> g){
		const unsigned int mod1=998244353,mod2=1224736769;
		std::vector<StaticModInt<mod1>> mul1=multiply(f,g);
		std::vector<StaticModInt<mod2>> mul2=multiply(f,g,mod2);
		std::vector<lint> res(mul1.size());
		rep(i,mul1.size())res[i]=ChineseRem(mul1[i],mod1,mul2[i],mod2).first;
		return res;
	}
};
bool NumberTheoreticTransform::inverse=false;