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


# :question: graph/HeavyLightDecomposition.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/HeavyLightDecomposition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-14 20:28:30+09:00




## Depends on

* :question: <a href="../other/template.hpp.html">other/template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/lca.test.cpp.html">test/lca.test.cpp</a>
* :x: <a href="../../verify/test/vertex_add_path_sum.test.cpp.html">test/vertex_add_path_sum.test.cpp</a>
* :x: <a href="../../verify/test/vertex_add_subtree_sum.test.cpp.html">test/vertex_add_subtree_sum.test.cpp</a>
* :x: <a href="../../verify/test/vertex_set_path_composite.test.cpp.html">test/vertex_set_path_composite.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../other/template.hpp"
class HeavyLightDecomposition{
	int n,index=0;
	void size_dfs(int node){
		size[node]=1;
		for(int &i:vec[node]){
			if(par[node]==i)continue;
			par[i]=node;
			size_dfs(i);
			size[node]+=size[i];
			if(size[i]>size[vec[node][0]])std::swap(i,vec[node][0]);
		}
	}
	void build_dfs(int node){
		label[node]=index++;
		for(int& i:vec[node]){
			if(par[node]!=i){
				head[i]=(i==vec[node][0]?head[node]:i);
				build_dfs(i);
			}
		}
		last[node]=index;
	}
public:
	std::vector<std::vector<int>> vec;
	std::vector<int> size,par,head,label,last;
	HeavyLightDecomposition(){}
	HeavyLightDecomposition(int m):n(m){
		vec.resize(n);size.resize(n);par.resize(n);head.resize(n);label.resize(n);last.resize(n);
	}
	void add_edge(int u,int v){
		vec[u].emplace_back(v);
		vec[v].emplace_back(u);
	}
	void build(int root){
		std::fill(all(par),-1);
		size_dfs(root);
		build_dfs(root);
	}
	template<typename F>
	void each_edge(int u,int v,const F &func)const{
		while(true){
			if(label[u]>label[v])std::swap(u,v);
			if(head[u]==head[v]){
				if(label[u]!=label[v])func(label[u]+1,label[v]);
				return;
			}
			func(label[head[v]],label[v]);
			v=par[head[v]];
		}
	}
	template<typename F>
	void each_vertex(int u,int v,const F& func)const{
		while(true){
			if(label[u]>label[v])std::swap(u,v);
			if(head[u]==head[v]){
				func(label[u],label[v]);
				return;
			}
			func(label[head[v]],label[v]);
			v=par[head[v]];
		}
	}
	int lca(int u,int v)const{
		while(true){
			if(label[u]>label[v])std::swap(u,v);
			if(head[u]==head[v])return u;
			v=par[head[v]];
		}
	}
	void clear(){
		vec.clear();size.clear();par.clear();head.clear();label.clear();last.clear();
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
/*template<typename F>
inline constexpr decltype(auto) lambda_fix(F&& f){
	return [f=std::forward<F>(f)](auto&&... args){
		return f(f,std::forward<decltype(args)>(args)...);
	};
}*/
#line 3 "graph/HeavyLightDecomposition.hpp"
class HeavyLightDecomposition{
	int n,index=0;
	void size_dfs(int node){
		size[node]=1;
		for(int &i:vec[node]){
			if(par[node]==i)continue;
			par[i]=node;
			size_dfs(i);
			size[node]+=size[i];
			if(size[i]>size[vec[node][0]])std::swap(i,vec[node][0]);
		}
	}
	void build_dfs(int node){
		label[node]=index++;
		for(int& i:vec[node]){
			if(par[node]!=i){
				head[i]=(i==vec[node][0]?head[node]:i);
				build_dfs(i);
			}
		}
		last[node]=index;
	}
public:
	std::vector<std::vector<int>> vec;
	std::vector<int> size,par,head,label,last;
	HeavyLightDecomposition(){}
	HeavyLightDecomposition(int m):n(m){
		vec.resize(n);size.resize(n);par.resize(n);head.resize(n);label.resize(n);last.resize(n);
	}
	void add_edge(int u,int v){
		vec[u].emplace_back(v);
		vec[v].emplace_back(u);
	}
	void build(int root){
		std::fill(all(par),-1);
		size_dfs(root);
		build_dfs(root);
	}
	template<typename F>
	void each_edge(int u,int v,const F &func)const{
		while(true){
			if(label[u]>label[v])std::swap(u,v);
			if(head[u]==head[v]){
				if(label[u]!=label[v])func(label[u]+1,label[v]);
				return;
			}
			func(label[head[v]],label[v]);
			v=par[head[v]];
		}
	}
	template<typename F>
	void each_vertex(int u,int v,const F& func)const{
		while(true){
			if(label[u]>label[v])std::swap(u,v);
			if(head[u]==head[v]){
				func(label[u],label[v]);
				return;
			}
			func(label[head[v]],label[v]);
			v=par[head[v]];
		}
	}
	int lca(int u,int v)const{
		while(true){
			if(label[u]>label[v])std::swap(u,v);
			if(head[u]==head[v])return u;
			v=par[head[v]];
		}
	}
	void clear(){
		vec.clear();size.clear();par.clear();head.clear();label.clear();last.clear();
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

