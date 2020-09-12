---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: test/yosupo/convolution_mod.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/convolution_mod.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 16:11:04+09:00


* see: <a href="https://judge.yosupo.jp/problem/convolution_mod">https://judge.yosupo.jp/problem/convolution_mod</a>


## Depends on

* :x: <a href="../../../library/algebraic/ModInt.hpp.html">algebraic/ModInt.hpp</a>
* :x: <a href="../../../library/algebraic/NumberTheoreticTransform.hpp.html">algebraic/NumberTheoreticTransform.hpp</a>
* :x: <a href="../../../library/other/template.hpp.html">other/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../other/template.hpp"
#include "../../algebraic/NumberTheoreticTransform.hpp"
int n,m;
std::vector<int> a,b;
int main(){
	scanf("%d%d",&n,&m);
	a.resize(n);b.resize(m);
	rep(i,n)scanf("%d",a.data()+i);
	rep(i,m)scanf("%d",b.data()+i);
	std::vector<ModInt> c=NumberTheoreticTransform::multiply(a,b,998244353);
	rep(i,n+m-1)printf((i==n+m?"%d\n":"%d "),c[i]);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/convolution_mod.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#line 2 "other/template.hpp"
#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx2")
#pragma optimize("O3")
#pragma optimize("unroll-loops")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define all(V) V.begin(),V.end()
typedef unsigned int uint;
typedef long long lint;
typedef unsigned long long ulint;
typedef std::pair<int, int> P;
typedef std::pair<lint, lint> LP;
constexpr int INF = INT_MAX/2;
constexpr lint LINF = LLONG_MAX/2;
constexpr double eps = DBL_EPSILON;
constexpr double PI=acos(-1);
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
inline lint gcd(lint a, lint b) {
	while (b) {
		lint c = a;
		a = b; b = c % b;
	}
	return a;
}
inline lint lcm(lint a, lint b) {
	return a / gcd(a, b) * b;
}
bool isprime(lint n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
template<typename T>
T mypow(T a, lint b) {
	T res(1);
	while(b){
		if(b&1)res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}
lint modpow(lint a, lint b, lint m) {
	lint res(1);
	while(b){
		if(b&1){
			res*=a;res%=m;
		}
		a*=a;a%=m;
		b>>=1;
	}
	return res;
}
template<typename T>
void printArray(std::vector<T>& vec) {
	rep(i, vec.size()){
		std::cout << vec[i];
		std::cout<<(i==(int)vec.size()-1?"\n":" ");
	}
}
template<typename T>
void printArray(T l, T r) {
	T rprev = std::prev(r);
	for (T i = l; i != rprev; i++) {
		std::cout << *i << " ";
	}
	std::cout << *rprev << std::endl;
}
LP extGcd(lint a,lint b) {
	if(b==0)return {1,0};
	LP s=extGcd(b,a%b);
	std::swap(s.first,s.second);
	s.second-=a/b*s.first;
	return s;
}
LP ChineseRem(const lint& b1,const lint& m1,const lint& b2,const lint& m2) {
	lint p=extGcd(m1,m2).first;
	lint tmp=(b2-b1)*p%m2;
	lint r=(b1+m1*tmp+m1*m2)%(m1*m2);
	return std::make_pair(r,m1*m2);
}
template<typename F>
inline constexpr decltype(auto) lambda_fix(F&& f){
	return [f=std::forward<F>(f)](auto&&... args){
		return f(f,std::forward<decltype(args)>(args)...);
	};
}
#line 3 "algebraic/ModInt.hpp"
class ModInt {
	lint value;
public:
	static unsigned int modulo;
	ModInt() : value(0) {}
	template<typename T>
	ModInt(T value = 0) : value(value) {
		if (value < 0)value = -(lint)(-value % modulo) + modulo;
		this->value = value % modulo;
	}
	static inline void setMod(const unsigned int& mod){modulo=mod;}
	inline ModInt inv()const{return mypow(*this,modulo-2);}
	inline operator int()const { return value; }
	inline ModInt& operator+=(const ModInt& x) {
		value += x.value;
		if (value >= modulo)value -= modulo;
		return *this;
	}
	inline ModInt& operator++() {
		if (value == modulo - 1)value = 0;
		else value++;
		return *this;
	}
	inline ModInt operator-()const {
		return ModInt(0) -= *this;
	}
	inline ModInt& operator-=(const ModInt& x) {
		value -= x.value;
		if (value < 0)value += modulo;
		return *this;
	}
	inline ModInt& operator--() {
		if (value == 0)value = modulo - 1;
		else value--;
		return *this;
	}
	inline ModInt& operator*=(const ModInt& x) {
		value = value * x.value % modulo;
		return *this;
	}
	inline ModInt& operator/=(const ModInt& rhs) {
		return *this*=rhs.inv();
	}
	template<typename T> ModInt operator+(const T& rhs)const { return ModInt(*this) += rhs; }
	template<typename T> ModInt& operator+=(const T& rhs) { return operator+=(ModInt(rhs)); }
	template<typename T> ModInt operator-(const T& rhs)const { return ModInt(*this) -= rhs; }
	template<typename T> ModInt& operator-=(const T& rhs) { return operator-=(ModInt(rhs)); }
	template<typename T> ModInt operator*(const T& rhs)const { return ModInt(*this) *= rhs; }
	template<typename T> ModInt& operator*=(const T& rhs) { return operator*=(ModInt(rhs)); }
	template<typename T> ModInt operator/(const T& rhs)const { return ModInt(*this) /= rhs; }
	template<typename T> ModInt& operator/=(const T& rhs) { return operator/=(ModInt(rhs)); }
};
unsigned int ModInt::modulo=1000000007;
std::istream& operator>>(std::istream& ist, ModInt& x) {
	lint a;
	ist >> a;
	x = a;
	return ist;
}
#line 4 "algebraic/NumberTheoreticTransform.hpp"
//1012924417,5,2^21
//924844033,5,2^21
//998244353,3,2^23
//1224736769,3,2^24
//167772161,3,2^25
//469762049,3,2^26
class NumberTheoreticTransform{
private:
	static void ntt(std::vector<ModInt>& a){
		int sz=a.size();
		if(sz==1)return;
		ModInt root=ModInt::modulo==924844033||ModInt::modulo==1012924417?5:3;
		if(inverse)root=mypow(root,ModInt::modulo-1-(ModInt::modulo-1)/sz);
		else root=mypow(root,(ModInt::modulo-1)/sz);
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
	static std::vector<ModInt> multiply(std::vector<T> f, std::vector<T> g, const unsigned int& mod) {
		unsigned int beforeMod=ModInt::modulo;
		ModInt::setMod(mod);
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
		ModInt::setMod(beforeMod);
		return nf;
	}
	template<typename T>
	static std::vector<lint> multiply_plain(std::vector<T> f,std::vector<T> g){
		const unsigned int mod1=998244353,mod2=1224736769;
		std::vector<ModInt> mul1=multiply(f,g,mod1);
		std::vector<ModInt> mul2=multiply(f,g,mod2);
		std::vector<lint> res(mul1.size());
		rep(i,mul1.size())res[i]=ChineseRem(mul1[i],mod1,mul2[i],mod2).first;
		return res;
	}
};
bool NumberTheoreticTransform::inverse=false;
#line 4 "test/yosupo/convolution_mod.test.cpp"
int n,m;
std::vector<int> a,b;
int main(){
	scanf("%d%d",&n,&m);
	a.resize(n);b.resize(m);
	rep(i,n)scanf("%d",a.data()+i);
	rep(i,m)scanf("%d",b.data()+i);
	std::vector<ModInt> c=NumberTheoreticTransform::multiply(a,b,998244353);
	rep(i,n+m-1)printf((i==n+m?"%d\n":"%d "),c[i]);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

