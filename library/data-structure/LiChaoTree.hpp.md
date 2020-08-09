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


# :heavy_check_mark: data-structure/LiChaoTree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/LiChaoTree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-09 16:53:29+09:00




## Depends on

* :heavy_check_mark: <a href="../other/template.hpp.html">other/template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/line_add_get_min.test.cpp.html">test/line_add_get_min.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../other/template.hpp"
class LiChaoTree{
    int n=1;
    std::vector<std::tuple<lint,lint,lint>> interval;
    std::vector<LP> node;
    std::vector<lint> cord;
    lint calc(LP l,lint x){
        return l.first*x+l.second;
    }
public:
    LiChaoTree(std::vector<lint> vec){
        vec.emplace_back(vec.back()+1);
        while(n<(int)vec.size())n*=2;
        while((int)vec.size()<n+1)vec.emplace_back(vec.back()+1);
        node.assign(2*n,{0,LINF});
        interval.emplace_back(0,0,0);
        for(int range=n;range;range>>=1){
            for(int i=0;i<n;i+=range){
                if(range==1)interval.emplace_back(vec[i],0,vec[i+range]);
                else interval.emplace_back(vec[i],vec[i+range/2],vec[i+range]);
            }
        }
        cord=std::move(vec);
    }
    void addLine(lint a,lint b){
        int cnt=1;
        while(true){
            lint l=std::get<0>(interval[cnt]),m=std::get<1>(interval[cnt]),r=std::get<2>(interval[cnt]);
            if(n<=cnt){
                if(calc(node[cnt],l)>calc({a,b},l))node[cnt]={a,b};
                break;
            }
            if(calc(node[cnt],l)<calc({a,b},l)&&calc(node[cnt],r)<calc({a,b},r))break;
            if(calc(node[cnt],l)>calc({a,b},l)&&calc(node[cnt],r)>calc({a,b},r)){
                node[cnt]={a,b};
                break;
            }
            if(calc(node[cnt],m)>calc({a,b},m)){
                LP memo=node[cnt];
                node[cnt]={a,b};
                a=memo.first;b=memo.second;
            }
            if(calc(node[cnt],l)>calc({a,b},l))cnt=cnt<<1;
            else cnt=cnt<<1|1;
        }
    }
    lint query(int idx){
        lint x=cord[idx];
        idx+=n;
        lint res=LINF;
        while(idx){
            chmin(res,calc(node[idx],x));
            idx>>=1;
        }
        return res;
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
#line 3 "data-structure/LiChaoTree.hpp"
class LiChaoTree{
    int n=1;
    std::vector<std::tuple<lint,lint,lint>> interval;
    std::vector<LP> node;
    std::vector<lint> cord;
    lint calc(LP l,lint x){
        return l.first*x+l.second;
    }
public:
    LiChaoTree(std::vector<lint> vec){
        vec.emplace_back(vec.back()+1);
        while(n<(int)vec.size())n*=2;
        while((int)vec.size()<n+1)vec.emplace_back(vec.back()+1);
        node.assign(2*n,{0,LINF});
        interval.emplace_back(0,0,0);
        for(int range=n;range;range>>=1){
            for(int i=0;i<n;i+=range){
                if(range==1)interval.emplace_back(vec[i],0,vec[i+range]);
                else interval.emplace_back(vec[i],vec[i+range/2],vec[i+range]);
            }
        }
        cord=std::move(vec);
    }
    void addLine(lint a,lint b){
        int cnt=1;
        while(true){
            lint l=std::get<0>(interval[cnt]),m=std::get<1>(interval[cnt]),r=std::get<2>(interval[cnt]);
            if(n<=cnt){
                if(calc(node[cnt],l)>calc({a,b},l))node[cnt]={a,b};
                break;
            }
            if(calc(node[cnt],l)<calc({a,b},l)&&calc(node[cnt],r)<calc({a,b},r))break;
            if(calc(node[cnt],l)>calc({a,b},l)&&calc(node[cnt],r)>calc({a,b},r)){
                node[cnt]={a,b};
                break;
            }
            if(calc(node[cnt],m)>calc({a,b},m)){
                LP memo=node[cnt];
                node[cnt]={a,b};
                a=memo.first;b=memo.second;
            }
            if(calc(node[cnt],l)>calc({a,b},l))cnt=cnt<<1;
            else cnt=cnt<<1|1;
        }
    }
    lint query(int idx){
        lint x=cord[idx];
        idx+=n;
        lint res=LINF;
        while(idx){
            chmin(res,calc(node[idx],x));
            idx>>=1;
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

