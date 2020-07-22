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


# :heavy_check_mark: data-structure/IntervalSegTree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/IntervalSegTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-22 15:32:27+09:00




## Depends on

* :heavy_check_mark: <a href="SegTree.hpp.html">data-structure/SegTree.hpp</a>
* :question: <a href="../other/template.hpp.html">other/template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/range_affine_range_sum.test.cpp.html">test/range_affine_range_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../other/template.hpp"
#include "SegTree.hpp"
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
		int ls = nodee, rs = nodee;
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
	RUQRSQ(int size, const int& def = 0) :IntervalSegTree<lint, lint>(size, def, 0) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	RUQRSQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>((lint)0, initvec) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
};
class RUQRMiQ :public IntervalSegTree<lint, lint> {
	lint nodef(const int& a, const int& b)const { return std::min(a, b); }
	void lazyf(int& a, const int& b) { a = b; }
	void updf(int& a, const int& b, const unsigned int& width) { a = b; }
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
typedef std::pair<int, int> P;
typedef std::pair<lint, lint> LP;
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
		int ls = nodee, rs = nodee;
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
	RUQRSQ(int size, const int& def = 0) :IntervalSegTree<lint, lint>(size, def, 0) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	RUQRSQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>((lint)0, initvec) {
		for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
};
class RUQRMiQ :public IntervalSegTree<lint, lint> {
	lint nodef(const int& a, const int& b)const { return std::min(a, b); }
	void lazyf(int& a, const int& b) { a = b; }
	void updf(int& a, const int& b, const unsigned int& width) { a = b; }
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

