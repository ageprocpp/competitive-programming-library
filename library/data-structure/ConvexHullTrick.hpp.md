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


# :warning: data-structure/ConvexHullTrick.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/ConvexHullTrick.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-16 18:26:54+09:00




## Depends on

* :question: <a href="../other/template.hpp.html">other/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../other/template.hpp"
template<typename T,bool isMin>
class ConvexHullTrick{
	static constexpr double INF=DBL_MAX;
	class Line{
	public:
		T m,b,val;
		int id;
		double x;
		bool isQuery;
		inline Line(int id=-1,T m=0,T b=0):id(id),m(m),b(b),isQuery(false){}
		T eval(T x)const{return m*x+b;}
		bool parallel(const Line& l)const{return m==l.m;}
		double intersect(const Line& l)const{
			return parallel(l)?INF:(l.b-b)/(m-l.m);
		}
		inline bool operator<(const Line &l)const{
			if(l.isQuery)return x<l.val;
			return m<l.m;
		}
	};
	int index=1;
	std::set<Line> st;
	using iter=typename std::set<Line>::iterator;
	inline bool cPrev(iter it)const{return it!=st.begin();}
	inline bool cNext(iter it)const{return it!=st.end()&&std::next(it)!=st.end();}
	bool bad(const Line& l1,const Line& l2,const Line& l3)const{
		return l1.intersect(l3)<=l1.intersect(l2);
	}
	bool bad(iter it)const{
		return cPrev(it)&&cNext(it)&&bad(*std::prev(it),*it,*std::next(it));
	}
	iter update(iter it){
		if(!cPrev(it))return it;
		double x=it->intersect(*std::prev(it));
		Line tmp(*it);
		tmp.x=x;
		it=st.erase(it);
		return st.insert(it,tmp);
	}
public:
	void addLine(T m,T b){
		if(isMin)m=-m,b=-b;
		Line l(index++,m,b);
		if(st.empty())l.x=-INF;
		iter it=st.lower_bound(l);
		if(it!=st.end()&&l.parallel(*it)){
			if(it->b<b)it=st.erase(it);
			else return;
		}
		it=st.insert(it,l);
		if(bad(it)){
			st.erase(it);
			return;
		}
		while(cPrev(it)&&bad(std::prev(it)))st.erase(std::prev(it));
		while(cNext(it)&&bad(std::next(it)))st.erase(std::next(it));
		it=update(it);
		if(cPrev(it))update(std::prev(it));
		if(cNext(it))update(std::next(it));
	}
	std::pair<T,int> query(T x){
		Line q;
		q.val=x;q.isQuery=true;
		iter it=--st.lower_bound(q);
		if(isMin)return {-it->eval(x),it->id};
		return {it->eval(x),it->id};
	}
	void clear(){
		st.clear();index=0;
	}
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
#line 2 "data-structure/ConvexHullTrick.hpp"
template<typename T,bool isMin>
class ConvexHullTrick{
	static constexpr double INF=DBL_MAX;
	class Line{
	public:
		T m,b,val;
		int id;
		double x;
		bool isQuery;
		inline Line(int id=-1,T m=0,T b=0):id(id),m(m),b(b),isQuery(false){}
		T eval(T x)const{return m*x+b;}
		bool parallel(const Line& l)const{return m==l.m;}
		double intersect(const Line& l)const{
			return parallel(l)?INF:(l.b-b)/(m-l.m);
		}
		inline bool operator<(const Line &l)const{
			if(l.isQuery)return x<l.val;
			return m<l.m;
		}
	};
	int index=1;
	std::set<Line> st;
	using iter=typename std::set<Line>::iterator;
	inline bool cPrev(iter it)const{return it!=st.begin();}
	inline bool cNext(iter it)const{return it!=st.end()&&std::next(it)!=st.end();}
	bool bad(const Line& l1,const Line& l2,const Line& l3)const{
		return l1.intersect(l3)<=l1.intersect(l2);
	}
	bool bad(iter it)const{
		return cPrev(it)&&cNext(it)&&bad(*std::prev(it),*it,*std::next(it));
	}
	iter update(iter it){
		if(!cPrev(it))return it;
		double x=it->intersect(*std::prev(it));
		Line tmp(*it);
		tmp.x=x;
		it=st.erase(it);
		return st.insert(it,tmp);
	}
public:
	void addLine(T m,T b){
		if(isMin)m=-m,b=-b;
		Line l(index++,m,b);
		if(st.empty())l.x=-INF;
		iter it=st.lower_bound(l);
		if(it!=st.end()&&l.parallel(*it)){
			if(it->b<b)it=st.erase(it);
			else return;
		}
		it=st.insert(it,l);
		if(bad(it)){
			st.erase(it);
			return;
		}
		while(cPrev(it)&&bad(std::prev(it)))st.erase(std::prev(it));
		while(cNext(it)&&bad(std::next(it)))st.erase(std::next(it));
		it=update(it);
		if(cPrev(it))update(std::prev(it));
		if(cNext(it))update(std::next(it));
	}
	std::pair<T,int> query(T x){
		Line q;
		q.val=x;q.isQuery=true;
		iter it=--st.lower_bound(q);
		if(isMin)return {-it->eval(x),it->id};
		return {it->eval(x),it->id};
	}
	void clear(){
		st.clear();index=0;
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

