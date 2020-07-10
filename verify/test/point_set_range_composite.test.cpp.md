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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: test/point_set_range_composite.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/point_set_range_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-11 01:46:56+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data-structure/ModInt.hpp.html">data-structure/ModInt.hpp</a>
* :heavy_check_mark: <a href="../../library/data-structure/SegTree.hpp.html">data-structure/SegTree.hpp</a>
* :heavy_check_mark: <a href="../../library/other/template.hpp.html">other/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../other/template.hpp"
#include "../data-structure/ModInt.hpp"
#include "../data-structure/SegTree.hpp"
const unsigned int ModInt::modulo=998244353;
class MySeg:public SegTree<std::pair<ModInt,ModInt>>{
	using mp=std::pair<ModInt,ModInt>;
	mp nodef(const mp& lhs,const mp& rhs)const{return {lhs.first*rhs.first,lhs.second*rhs.first+rhs.second};}
public:
	MySeg(int size):SegTree<mp>(size,{0,0},{1,0}){}
};
lint n,q;
int main(){
	std::cin>>n>>q;
	MySeg st(n);
	rep(i,n){
		lint a,b;
		std::cin>>a>>b;
		st.update(i,{a,b});
	}
	rep(i,q){
		int t;
		std::cin>>t;
		if(t==0){
			int p,c,d;
			std::cin>>p>>c>>d;
			st.update(p,{c,d});
		}
		else{
			int l,r,x;
			std::cin>>l>>r>>x;
			auto p=st.query(l,r);
			std::cout<<p.first*x+p.second<<std::endl;
		}
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/point_set_range_composite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#line 2 "other/template.hpp"
#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i,n) for(int i=0;i<(lint)(n);i++)
#define REP(i,n) for(int i=1;i<=(lint)(n);i++)
#define all(V) V.begin(),V.end()
typedef long long lint;
typedef unsigned long long ulint;
typedef std::pair<lint, lint> P;
constexpr int INF = INT_MAX/2;
constexpr lint LINF = LLONG_MAX/2;
constexpr double eps = DBL_EPSILON;
constexpr double PI=3.141592653589793238462643383279;
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
T mypow(T a, unsigned int b) {
	if (!b)return T(1);
	if (b & 1)return mypow(a, b - 1) * a;
	T memo = mypow(a, b >> 1);
	return memo * memo;
}
lint modpow(lint a, lint b, lint m) {
	if (!b)return 1;
	if (b & 1)return modpow(a, b - 1, m) * a % m;
	lint memo = modpow(a, b >> 1, m);
	return memo * memo % m;
}
template<typename T>
void printArray(std::vector<T>& vec) {
	rep(i, vec.size() - 1)std::cout << vec[i] << " ";
	std::cout << vec.back() << std::endl;
}
template<typename T>
void printArray(T l, T r) {
	T rprev = r;
	rprev--;
	for (T i = l; i != rprev; i++) {
		std::cout << *i << " ";
	}
	std::cout << *rprev << std::endl;
}
#line 3 "data-structure/ModInt.hpp"
class ModInt {
    lint value;
public:
    static const unsigned int modulo;
    ModInt() : value(0) {}
    template<typename T>
    ModInt(T value = 0) : value(value) {
        if (value < 0)value = -(lint)(-value % modulo) + modulo;
        this->value = value % modulo;
    }
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
    inline ModInt& operator/=(ModInt rhs) {
        int exp = modulo - 2;
        while (exp) {
            if (exp & 1)*this *= rhs;
            rhs *= rhs;
            exp >>= 1;
        }
        return *this;
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
		node.resize(2 * n);
		for (unsigned int i = n; i < 2 * n; i++)node[i] = init;
	}
	SegTree(const std::vector<T>& initvec, T nodee):nodee(nodee) {
		unsigned int m = initvec.size();
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n);
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
			if (l & 1) {
				ls = nodef(ls, node[l]);
				l++;
			}
			if (r & 1) {
				r--;
				rs = nodef(node[r], rs);
			}
			l >>= 1; r >>= 1;
		}
		return nodef(ls, rs);
	}
	virtual T operator[](const int& x) {
		return node[n + x];
	}
	void fill(T x) {
		std::fill(all(node), x);
	}
	void print() {
		rep(i, n)std::cout << operator[](i) << " ";
		std::cout << std::endl;
	}
};
class RSQ :public SegTree<lint> {
	lint nodef(const lint& lhs,const lint& rhs)const{return lhs+rhs;}
public:
	RSQ(int size, const lint& def = 0) :SegTree<lint>(size, def, 0) {}
	RSQ(const std::vector<lint>& initvec) :SegTree<lint>(initvec, 0) {}
};
class RMiQ :public SegTree<lint> {
	lint nodef(const lint& lhs,const lint& rhs)const{return std::min(lhs,rhs);}
public:
	RMiQ(int size, const lint& def = 0) :SegTree<lint>(size, def, LINF) {}
	RMiQ(const std::vector<lint>& initvec) :SegTree<lint>(initvec, LINF) {}
};
class RMaQ :public SegTree<lint> {
	lint nodef(const lint& lhs,const lint& rhs)const{return std::max(lhs,rhs);}
public:
	RMaQ(int size, const lint& def = 0) :SegTree<lint>(size, def, -LINF) {}
	RMaQ(const std::vector<lint>& initvec) :SegTree<lint>(initvec, -LINF) {}
};
#line 5 "test/point_set_range_composite.test.cpp"
const unsigned int ModInt::modulo=998244353;
class MySeg:public SegTree<std::pair<ModInt,ModInt>>{
	using mp=std::pair<ModInt,ModInt>;
	mp nodef(const mp& lhs,const mp& rhs)const{return {lhs.first*rhs.first,lhs.second*rhs.first+rhs.second};}
public:
	MySeg(int size):SegTree<mp>(size,{0,0},{1,0}){}
};
lint n,q;
int main(){
	std::cin>>n>>q;
	MySeg st(n);
	rep(i,n){
		lint a,b;
		std::cin>>a>>b;
		st.update(i,{a,b});
	}
	rep(i,q){
		int t;
		std::cin>>t;
		if(t==0){
			int p,c,d;
			std::cin>>p>>c>>d;
			st.update(p,{c,d});
		}
		else{
			int l,r,x;
			std::cin>>l>>r>>x;
			auto p=st.query(l,r);
			std::cout<<p.first*x+p.second<<std::endl;
		}
	}
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

