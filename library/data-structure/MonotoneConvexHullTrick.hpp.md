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


# :warning: data-structure/MonotoneConvexHullTrick.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/MonotoneConvexHullTrick.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-16 18:26:54+09:00




## Depends on

* :heavy_check_mark: <a href="../other/template.hpp.html">other/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../other/template.hpp"
template<typename T,bool isMin>
class MonotoneConvexHullTrick{
	static constexpr double INF=DBL_MAX;
	using TP=std::pair<std::pair<T,T>,int>;
	int index=0;
	std::deque<TP> deq;
	inline int sgn(T x){return x==0?0:(x<0?-1:1);}
	inline T eval(const TP& a,const T& x){return a.first.first*x+a.first.second;}
	inline bool bad(const TP& l1,const TP& l2,const TP& l3){
		if(l1.first.second==l2.first.second||l2.first.second==l3.first.second){
			return sgn(l2.first.first-l1.first.first)*sgn(l3.first.second-l2.first.second)>=sgn(l3.first.first-l2.first.first)*sgn(l2.first.second-l1.first.second);
		}
		return (double)(l2.first.first-l1.first.first)*sgn(l3.first.second-l2.first.second)/std::abs(l2.first.second-l1.first.second)
			>=(double)(l3.first.first-l2.first.first)*sgn(l2.first.second-l1.first.second)/std::abs(l3.first.second-l2.first.second);
	}
public:
	void addLine(T m,T b){
		if(!isMin)m=-m;b=-b;
		TP line={{m,b},index++};
		if(empty()){
			deq.emplace_front(line);
			return;
		}
		if(deq.front().first.first<=m){
			if(deq.front().first.first==m){
				if(deq.front().first.second<=b)return;
				deq.pop_front();
			}
			while(deq.size()>=2&&bad(line,deq[0],deq[1]))deq.pop_front();
			deq.emplace_front(line);
		}
		else{
			if(deq.back().first.first==m){
				if(deq.back().first.second<=b)return;
				deq.pop_back();
			}
			while(deq.size()>=2&&bad(deq[deq.size()-2],deq.back(),line))deq.pop_back();
			deq.emplace_back(line);
		}
	}
	std::pair<T,int> query(T x){
		int l=-1,r=deq.size()-1;
		while(l+1<r){
			int m=(l+r)/2;
			if(eval(deq[m],x)>=eval(deq[m+1],x))l=m;
			else r=m;
		}
		return {(isMin?1:-1)*eval(deq[r],x),deq[r].second};
	}
	std::pair<T,int> queryMonotoneInc(T x){
		while(deq.size()>=2&&eval(deq[0],x)>=eval(deq[1],x))deq.pop_front();
		return {(isMin?1:-1)*eval(deq[0],x),deq[0].second};
	}
	std::pair<T,int> queryMonotoneDec(T x){
		while(deq.size()>=2&&eval(deq.back(),x)>=eval(deq[deq.size()-2]))deq.pop_back();
		return {(isMin?1:-1)*eval(deq.back(),x),deq.back().second};
	}
	bool empty()const{return deq.empty();}
	void clear(){deq.clear();index=0;}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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
#line 2 "data-structure/MonotoneConvexHullTrick.hpp"
template<typename T,bool isMin>
class MonotoneConvexHullTrick{
	static constexpr double INF=DBL_MAX;
	using TP=std::pair<std::pair<T,T>,int>;
	int index=0;
	std::deque<TP> deq;
	inline int sgn(T x){return x==0?0:(x<0?-1:1);}
	inline T eval(const TP& a,const T& x){return a.first.first*x+a.first.second;}
	inline bool bad(const TP& l1,const TP& l2,const TP& l3){
		if(l1.first.second==l2.first.second||l2.first.second==l3.first.second){
			return sgn(l2.first.first-l1.first.first)*sgn(l3.first.second-l2.first.second)>=sgn(l3.first.first-l2.first.first)*sgn(l2.first.second-l1.first.second);
		}
		return (double)(l2.first.first-l1.first.first)*sgn(l3.first.second-l2.first.second)/std::abs(l2.first.second-l1.first.second)
			>=(double)(l3.first.first-l2.first.first)*sgn(l2.first.second-l1.first.second)/std::abs(l3.first.second-l2.first.second);
	}
public:
	void addLine(T m,T b){
		if(!isMin)m=-m;b=-b;
		TP line={{m,b},index++};
		if(empty()){
			deq.emplace_front(line);
			return;
		}
		if(deq.front().first.first<=m){
			if(deq.front().first.first==m){
				if(deq.front().first.second<=b)return;
				deq.pop_front();
			}
			while(deq.size()>=2&&bad(line,deq[0],deq[1]))deq.pop_front();
			deq.emplace_front(line);
		}
		else{
			if(deq.back().first.first==m){
				if(deq.back().first.second<=b)return;
				deq.pop_back();
			}
			while(deq.size()>=2&&bad(deq[deq.size()-2],deq.back(),line))deq.pop_back();
			deq.emplace_back(line);
		}
	}
	std::pair<T,int> query(T x){
		int l=-1,r=deq.size()-1;
		while(l+1<r){
			int m=(l+r)/2;
			if(eval(deq[m],x)>=eval(deq[m+1],x))l=m;
			else r=m;
		}
		return {(isMin?1:-1)*eval(deq[r],x),deq[r].second};
	}
	std::pair<T,int> queryMonotoneInc(T x){
		while(deq.size()>=2&&eval(deq[0],x)>=eval(deq[1],x))deq.pop_front();
		return {(isMin?1:-1)*eval(deq[0],x),deq[0].second};
	}
	std::pair<T,int> queryMonotoneDec(T x){
		while(deq.size()>=2&&eval(deq.back(),x)>=eval(deq[deq.size()-2]))deq.pop_back();
		return {(isMin?1:-1)*eval(deq.back(),x),deq.back().second};
	}
	bool empty()const{return deq.empty();}
	void clear(){deq.clear();index=0;}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

