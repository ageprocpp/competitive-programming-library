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


# :heavy_check_mark: data-structure/BIT.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/BIT.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-01 00:12:07+09:00




## Depends on

* :heavy_check_mark: <a href="../other/template.hpp.html">other/template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/point_add_range_sum.test.cpp.html">test/point_add_range_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../other/template.hpp"
class BIT {
	int n;
	std::vector<lint> bit;
public:
	BIT(unsigned int n) :n(n) {
		bit.resize(n + 1, 0);
	}
	void add(int a, lint x) {
		while (a <= n) {
			bit[a] += x;
			a += a & -a;
		}
	}
	lint query(int a) {
		lint cnt = 0;
		while (a > 0) {
			cnt += bit[a];
			a -= a & -a;
		}
		return cnt;
	}
	void clear() {
		bit.assign(n + 1, 0);
	}
	unsigned int lower_bound(int x){
		int p=0,k=1;
		while(k*2<=n)k*=2;
		while(k>0){
			if(p+k<=n&&bit[p+k]<x){
				x-=bit[p+k];
				p+=k;
			}
			k/=2;
		}
		return p+1;
	}
	unsigned int upper_bound(int x){
		int p=0,k=1;
		while(k*2<=n)k*=2;
		while(k>0){
			if(p+k<=n&&bit[p+k]<=x){
				x-=bit[p+k];
				p+=k;
			}
			k/=2;
		}
		return p+1;
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
#include <string.h>
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
T mypow(T a, lint b) {
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
#line 3 "data-structure/BIT.hpp"
class BIT {
	int n;
	std::vector<lint> bit;
public:
	BIT(unsigned int n) :n(n) {
		bit.resize(n + 1, 0);
	}
	void add(int a, lint x) {
		while (a <= n) {
			bit[a] += x;
			a += a & -a;
		}
	}
	lint query(int a) {
		lint cnt = 0;
		while (a > 0) {
			cnt += bit[a];
			a -= a & -a;
		}
		return cnt;
	}
	void clear() {
		bit.assign(n + 1, 0);
	}
	unsigned int lower_bound(int x){
		int p=0,k=1;
		while(k*2<=n)k*=2;
		while(k>0){
			if(p+k<=n&&bit[p+k]<x){
				x-=bit[p+k];
				p+=k;
			}
			k/=2;
		}
		return p+1;
	}
	unsigned int upper_bound(int x){
		int p=0,k=1;
		while(k*2<=n)k*=2;
		while(k>0){
			if(p+k<=n&&bit[p+k]<=x){
				x-=bit[p+k];
				p+=k;
			}
			k/=2;
		}
		return p+1;
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

