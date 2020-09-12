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


# :x: test/yosupo/range_affine_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 16:11:04+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :x: <a href="../../../library/algebraic/ModInt.hpp.html">algebraic/ModInt.hpp</a>
* :x: <a href="../../../library/data-structure/IntervalSegTree.hpp.html">data-structure/IntervalSegTree.hpp</a>
* :x: <a href="../../../library/data-structure/SegTree.hpp.html">data-structure/SegTree.hpp</a>
* :x: <a href="../../../library/other/template.hpp.html">other/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../other/template.hpp"
#include "../../algebraic/ModInt.hpp"
#include "../../data-structure/IntervalSegTree.hpp"
class MySeg:public IntervalSegTree<ModInt,std::pair<ModInt,ModInt>>{
	using mp=std::pair<ModInt,ModInt>;
	ModInt nodef(const ModInt& a,const ModInt& b)const{return a+b;}
	void lazyf(mp& a,const mp& b){a={a.first*b.first,a.second*b.first+b.second};}
	void updf(ModInt& a,const mp& b,const unsigned int& width){a=b.first*a+b.second*width;}
public:
	MySeg(const std::vector<ModInt>& initvec):IntervalSegTree<ModInt,mp>(0,initvec){
		for(int i=n-1;i>0;i--)node[i]=nodef(node[2*i],node[2*i+1]);
	}
};
int n,q;
std::vector<ModInt> vec;
int main(){
	ModInt::setMod(998244353);
	scanf("%d%d",&n,&q);
	vec.resize(n);
	rep(i,n){
		int tmp;
		scanf("%d",&tmp);
		vec[i]=tmp;
	}
	MySeg st(vec);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int l,r,b,c;
			scanf("%d%d%d%d",&l,&r,&b,&c);
			st.update(l,r,{b,c});
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",st.query(l,r));
		}
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/range_affine_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
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
#line 3 "data-structure/SegTree.hpp"
template<typename T>
class SegTree {
protected:
	unsigned int n = 1, rank = 0;
	std::vector<T> node;
	T nodee;
	virtual T nodef(const T&, const T&)const = 0;
public:
	SegTree(unsigned int m, T init, T nodee):nodee(nodee) {
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n, nodee);
		for (unsigned int i = n; i < 2 * n; i++)node[i] = init;
	}
	SegTree(const std::vector<T>& initvec, T nodee):nodee(nodee) {
		unsigned int m = initvec.size();
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n, nodee);
		for (unsigned int i = n; i < 2 * n; i++) {
			if (i - n < m)node[i] = initvec[i - n];
		}
	}
	virtual void update(int i, T x) {
		i += n;
		node[i] = x;
		while (i != 1) {
			i >>= 1;
			node[i] = nodef(node[2 * i], node[2 * i + 1]);
		}
	}
	virtual T query(int l, int r) {
		l += n; r += n;
		T ls = nodee, rs = nodee;
		while (l < r) {
			if (l & 1) ls = nodef(ls, node[l++]);
			if (r & 1) rs = nodef(node[--r], rs);
			l >>= 1; r >>= 1;
		}
		return nodef(ls, rs);
	}
	virtual T operator[](const int& x) {
		return node[n + x];
	}
	void print() {
		rep(i, n)std::cout << operator[](i) << " ";
		std::cout << std::endl;
	}
};
class RSQ :public SegTree<lint> {
	lint nodef(const lint& lhs,const lint& rhs)const{return lhs+rhs;}
public:
	RSQ(int size, const lint& def = 0) :SegTree<lint>(size, def, 0) {
		for(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);
	}
	RSQ(const std::vector<lint>& initvec) :SegTree<lint>(initvec, 0) {
		for(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);
	}
};
class RMiQ :public SegTree<lint> {
	lint nodef(const lint& lhs,const lint& rhs)const{return std::min(lhs,rhs);}
public:
	RMiQ(int size, const lint& def = 0) :SegTree<lint>(size, def, LINF) {
		for(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);
	}
	RMiQ(const std::vector<lint>& initvec) :SegTree<lint>(initvec, LINF) {
		for(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);
	}
};
class RMaQ :public SegTree<lint> {
	lint nodef(const lint& lhs,const lint& rhs)const{return std::max(lhs,rhs);}
public:
	RMaQ(int size, const lint& def = 0) :SegTree<lint>(size, def, -LINF) {
		for(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);
	}
	RMaQ(const std::vector<lint>& initvec) :SegTree<lint>(initvec, -LINF) {
		for(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);
	}
};
#line 4 "data-structure/IntervalSegTree.hpp"
template<typename T, typename U>
class IntervalSegTree :public SegTree<T> {
protected:
	using SegTree<T>::n;
	using SegTree<T>::rank;
	using SegTree<T>::node;
	using SegTree<T>::nodef;
	using SegTree<T>::nodee;
	std::vector<U> lazy;
	std::vector<bool> lazyflag;
	std::vector<int> width;
	virtual void lazyf(U&, const U&) = 0;
	virtual void updf(T&, const U&, const unsigned int&) = 0;
	void eval(int k) {
		for (int i = rank; i > 0; i--) {
			int nk = k >> i;
			if (lazyflag[nk]) {
				updf(node[2 * nk], lazy[nk], width[2 * nk]);
				updf(node[2 * nk + 1], lazy[nk], width[2 * nk + 1]);
				if (lazyflag[2 * nk])lazyf(lazy[2 * nk], lazy[nk]);
				else lazy[2 * nk] = lazy[nk];
				if (lazyflag[2 * nk + 1])lazyf(lazy[2 * nk + 1], lazy[nk]);
				else lazy[2 * nk + 1] = lazy[nk];
				lazyflag[2 * nk] = lazyflag[2 * nk + 1] = true;
				lazyflag[nk] = false;
			}
		}
	}
public:
	IntervalSegTree(unsigned int m, T init, T nodee) :SegTree<T>(m, init, nodee) {
		lazy.resize(2 * n); lazyflag.resize(2 * n); width.resize(2 * n);
		width[1] = n;
		for (unsigned int i = 2; i < 2 * n; i++) {
			width[i] = width[i >> 1] >> 1;
		}
	}
	IntervalSegTree(T nodee, const std::vector<T>& initvec) :SegTree<T>(initvec, nodee) {
		lazy.resize(2 * n); lazyflag.resize(2 * n); width.resize(2 * n);
		width[1] = n;
		for (unsigned int i = 2; i < 2 * n; i++) {
			width[i] = width[i >> 1] >> 1;
		}
	}
	void update(int i, U x) {
		i += n;
		eval(i);
		updf(node[i], x, width[i]);
		if (lazyflag[i])lazyf(lazy[i], x);
		else {
			lazyflag[i] = true;
			lazy[i] = x;
		}
		while (i /= 2)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	void update(int l, int r, U x) {
		l += n; r += n;
		int nl = l, nr = r;
		while (!(nl & 1))nl >>= 1;
		while (!(nr & 1))nr >>= 1;
		nr--;
		eval(nl); eval(nr);
		while (l < r) {
			if (l & 1) {
				updf(node[l], x, width[l]);
				if (lazyflag[l])lazyf(lazy[l], x);
				else {
					lazyflag[l] = true;
					lazy[l] = x;
				}
				l++;
			}
			if (r & 1) {
				r--;
				updf(node[r], x, width[r]);
				if (lazyflag[r])lazyf(lazy[r], x);
				else {
					lazyflag[r] = true;
					lazy[r] = x;
				}
			}
			l >>= 1; r >>= 1;
		}
		while (nl >>= 1)node[nl] = nodef(node[2 * nl], node[2 * nl + 1]);
		while (nr >>= 1)node[nr] = nodef(node[2 * nr], node[2 * nr + 1]);
	}
	T query(int l, int r) {
		l += n; r += n;
		eval(l); eval(r - 1);
		T ls = nodee, rs = nodee;
		while (l < r) {
			if (l & 1)ls = nodef(ls, node[l++]);
			if (r & 1)rs = nodef(node[--r], rs);
			l >>= 1; r >>= 1;
		}
		return nodef(ls, rs);
	}
	T operator[](const int& x) {
		eval(n + x);
		return node[n + x];
	}
	T queryForAll() {
		return node[1];
	}
};
class RAQRSQ :public IntervalSegTree<lint, lint> {
	lint nodef(const lint& a, const lint& b)const { return a + b; }
	void lazyf(lint& a, const lint& b) { a += b; }
	void updf(lint& a, const lint& b, const unsigned int& width) { a += width * b; }
public:
	RAQRSQ(int size, const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, 0) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	RAQRSQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>((lint)0, initvec) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
};
class RAQRMiQ :public IntervalSegTree<lint, lint> {
	lint nodef(const lint& a, const lint& b)const { return std::min(a, b); }
	void lazyf(lint& a, const lint& b) { a += b; }
	void updf(lint& a, const lint& b, const unsigned int& width) { a += b; }
public:
	RAQRMiQ(int size, const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, LINF) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	RAQRMiQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>(LINF, initvec) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
};
class RAQRMaQ :public IntervalSegTree<lint, lint> {
	lint nodef(const lint& a, const lint& b)const { return std::max(a, b); }
	void lazyf(lint& a, const lint& b) { a += b; }
	void updf(lint& a, const lint& b, const unsigned int& width) { a += b; }
public:
	RAQRMaQ(unsigned int size, const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, -LINF) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	RAQRMaQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>(-LINF, initvec) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
};
class RUQRSQ :public IntervalSegTree<lint, lint> {
	lint nodef(const lint& a, const lint& b)const { return a + b; }
	void lazyf(lint& a, const lint& b) { a = b; }
	void updf(lint& a, const lint& b, const unsigned int& width) { a = width * b; }
public:
	RUQRSQ(int size, const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, 0) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	RUQRSQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>((lint)0, initvec) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
};
class RUQRMiQ :public IntervalSegTree<lint, lint> {
	lint nodef(const lint& a, const lint& b)const { return std::min(a, b); }
	void lazyf(lint& a, const lint& b) { a = b; }
	void updf(lint& a, const lint& b, const unsigned int& width) { a = b; }
public:
	RUQRMiQ(int size, const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, LINF) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	RUQRMiQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>(LINF, initvec) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
};
class RUQRMaQ :public IntervalSegTree<lint, lint> {
	lint nodef(const lint& a, const lint& b)const { return std::max(a, b); }
	void lazyf(lint& a, const lint& b) { a = b; }
	void updf(lint& a, const lint& b, const unsigned int& width) { a = b; }
public:
	RUQRMaQ(int size, const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, -LINF) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	RUQRMaQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>(-LINF, initvec) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
};
#line 5 "test/yosupo/range_affine_range_sum.test.cpp"
class MySeg:public IntervalSegTree<ModInt,std::pair<ModInt,ModInt>>{
	using mp=std::pair<ModInt,ModInt>;
	ModInt nodef(const ModInt& a,const ModInt& b)const{return a+b;}
	void lazyf(mp& a,const mp& b){a={a.first*b.first,a.second*b.first+b.second};}
	void updf(ModInt& a,const mp& b,const unsigned int& width){a=b.first*a+b.second*width;}
public:
	MySeg(const std::vector<ModInt>& initvec):IntervalSegTree<ModInt,mp>(0,initvec){
		for(int i=n-1;i>0;i--)node[i]=nodef(node[2*i],node[2*i+1]);
	}
};
int n,q;
std::vector<ModInt> vec;
int main(){
	ModInt::setMod(998244353);
	scanf("%d%d",&n,&q);
	vec.resize(n);
	rep(i,n){
		int tmp;
		scanf("%d",&tmp);
		vec[i]=tmp;
	}
	MySeg st(vec);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int l,r,b,c;
			scanf("%d%d%d%d",&l,&r,&b,&c);
			st.update(l,r,{b,c});
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",st.query(l,r));
		}
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

