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


# :warning: algebraic/MyComplex.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c7f6ad568392380a8f4b4cecbaccb64c">algebraic</a>
* <a href="{{ site.github.repository_url }}/blob/master/algebraic/MyComplex.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 23:42:44+09:00




## Depends on

* :heavy_check_mark: <a href="../other/template.hpp.html">other/template.hpp</a>


## Required by

* :warning: <a href="FastFourierTransform.hpp.html">algebraic/FastFourierTransform.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../other/template.hpp"
class MyComplex{
	double realvalue, imagvalue;
public:
	MyComplex() :realvalue(0), imagvalue(0) {}
	MyComplex(const double& realvalue, const double& imagvalue) : realvalue(realvalue), imagvalue(imagvalue) {}
	MyComplex(const double& realvalue) : realvalue(realvalue), imagvalue(0) {}
	MyComplex(const std::complex<double>& c) :realvalue(c.real()), imagvalue(c.imag()) {}
	MyComplex(const MyComplex& rhs) :realvalue(rhs.realvalue), imagvalue(rhs.imagvalue) {}
	double& real(){ return this->realvalue; }
	double& imag(){ return this->imagvalue; }
	double abs()const{ return hypot(realvalue, imagvalue); }
	MyComplex& operator+=(const MyComplex& rhs) {
		this->realvalue += rhs.realvalue;
		this->imagvalue += rhs.imagvalue;
		return *this;
	}
	MyComplex& operator-=(const MyComplex& rhs) {
		this->realvalue -= rhs.realvalue;
		this->imagvalue -= rhs.imagvalue;
		return *this;
	}
	MyComplex& operator*=(const MyComplex& rhs) {
		double pastreal = this->realvalue;
		this->realvalue = this->realvalue * rhs.realvalue - this->imagvalue * rhs.imagvalue;
		this->imagvalue = pastreal * rhs.imagvalue + rhs.realvalue * this->imagvalue;
		return *this;
	}
	MyComplex& operator/=(const MyComplex& rhs) {
		*this *= MyComplex(rhs.realvalue, -rhs.imagvalue);
		double dnm = rhs.realvalue * rhs.realvalue - rhs.imagvalue * rhs.imagvalue;
		this->realvalue /= dnm;
		this->imagvalue /= dnm;
		return *this;
	}

	template<typename T>MyComplex operator+(const T& rhs)const {return MyComplex(*this)+=rhs;}
	template<typename T>MyComplex& operator+=(const T& rhs)const {return operator+=(MyComplex(rhs));}
	template<typename T>MyComplex operator-(const T& rhs)const {return MyComplex(*this)-=rhs;}
	template<typename T>MyComplex& operator-=(const T& rhs)const {return operator-=(MyComplex(rhs));}
	template<typename T>MyComplex operator*(const T& rhs)const {return MyComplex(*this)*=rhs;}
	template<typename T>MyComplex& operator*=(const T& rhs)const {return operator*=(MyComplex(rhs));}
	template<typename T>MyComplex operator/(const T& rhs)const {return MyComplex(*this)/=rhs;}
	template<typename T>MyComplex& operator/=(const T& rhs)const {return operator/=(MyComplex(rhs));}
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
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
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
			res*=a;res/=m;
		}
		a*=a;a/=m;
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
#line 3 "algebraic/MyComplex.hpp"
class MyComplex{
	double realvalue, imagvalue;
public:
	MyComplex() :realvalue(0), imagvalue(0) {}
	MyComplex(const double& realvalue, const double& imagvalue) : realvalue(realvalue), imagvalue(imagvalue) {}
	MyComplex(const double& realvalue) : realvalue(realvalue), imagvalue(0) {}
	MyComplex(const std::complex<double>& c) :realvalue(c.real()), imagvalue(c.imag()) {}
	MyComplex(const MyComplex& rhs) :realvalue(rhs.realvalue), imagvalue(rhs.imagvalue) {}
	double& real(){ return this->realvalue; }
	double& imag(){ return this->imagvalue; }
	double abs()const{ return hypot(realvalue, imagvalue); }
	MyComplex& operator+=(const MyComplex& rhs) {
		this->realvalue += rhs.realvalue;
		this->imagvalue += rhs.imagvalue;
		return *this;
	}
	MyComplex& operator-=(const MyComplex& rhs) {
		this->realvalue -= rhs.realvalue;
		this->imagvalue -= rhs.imagvalue;
		return *this;
	}
	MyComplex& operator*=(const MyComplex& rhs) {
		double pastreal = this->realvalue;
		this->realvalue = this->realvalue * rhs.realvalue - this->imagvalue * rhs.imagvalue;
		this->imagvalue = pastreal * rhs.imagvalue + rhs.realvalue * this->imagvalue;
		return *this;
	}
	MyComplex& operator/=(const MyComplex& rhs) {
		*this *= MyComplex(rhs.realvalue, -rhs.imagvalue);
		double dnm = rhs.realvalue * rhs.realvalue - rhs.imagvalue * rhs.imagvalue;
		this->realvalue /= dnm;
		this->imagvalue /= dnm;
		return *this;
	}

	template<typename T>MyComplex operator+(const T& rhs)const {return MyComplex(*this)+=rhs;}
	template<typename T>MyComplex& operator+=(const T& rhs)const {return operator+=(MyComplex(rhs));}
	template<typename T>MyComplex operator-(const T& rhs)const {return MyComplex(*this)-=rhs;}
	template<typename T>MyComplex& operator-=(const T& rhs)const {return operator-=(MyComplex(rhs));}
	template<typename T>MyComplex operator*(const T& rhs)const {return MyComplex(*this)*=rhs;}
	template<typename T>MyComplex& operator*=(const T& rhs)const {return operator*=(MyComplex(rhs));}
	template<typename T>MyComplex operator/(const T& rhs)const {return MyComplex(*this)/=rhs;}
	template<typename T>MyComplex& operator/=(const T& rhs)const {return operator/=(MyComplex(rhs));}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
