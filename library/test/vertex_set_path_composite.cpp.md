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


# :warning: test/vertex_set_path_composite.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/vertex_set_path_composite.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-12 17:20:13+09:00


* see: <a href="https://judge.yosupo.jp/problem/vertex_set_path_composite">https://judge.yosupo.jp/problem/vertex_set_path_composite</a>


## Depends on

* :heavy_check_mark: <a href="../algebraic/ModInt.hpp.html">algebraic/ModInt.hpp</a>
* :heavy_check_mark: <a href="../data-structure/SegTree.hpp.html">data-structure/SegTree.hpp</a>
* :heavy_check_mark: <a href="../graph/HeavyLightDecomposition.hpp.html">graph/HeavyLightDecomposition.hpp</a>
* :heavy_check_mark: <a href="../other/template.hpp.html">other/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../other/template.hpp"
#include "../algebraic/ModInt.hpp"
#include "../graph/HeavyLightDecomposition.hpp"
#include "../data-structure/SegTree.hpp"
class MySeg:public SegTree<std::pair<ModInt,ModInt>>{
	using MP=std::pair<ModInt,ModInt>;
	MP nodef(const MP& lhs,const MP& rhs)const{
		return {lhs.first*rhs.first,lhs.second*rhs.first+rhs.second};
	}
public:
	MySeg(int n):SegTree<MP>(n,{1,0},{1,0}){}
};
int n,q;
P a[200010];
int main(){
	ModInt::setMod(998244353);
	std::cin>>n>>q;
	rep(i,n)std::cin>>a[i].first>>a[i].second;
	HeavyLightDecomposition hld(n);
	MySeg st1(n),st2(n);
	rep(i,n-1){
		int u,v;
		std::cin>>u>>v;
		hld.add_edge(u,v);
	}
	hld.build(0);
	rep(i,n){
		st1.update(hld.label[i],a[i]);
		st2.update(n-1-hld.label[i],a[i]);
	}
	rep(i,q){
		int type;
		std::cin>>type;
		if(type==0){
			int p,c,d;
			std::cin>>p>>c>>d;
			a[p]={c,d};
			st1.update(hld.label[p],{c,d});
			st2.update(n-1-hld.label[p],{c,d});
		}
		else{
			int u,v,x;
			std::cin>>u>>v>>x;
			int t=hld.lca(u,v);
			std::pair<ModInt,ModInt> f1={1,0},f2={1,0};
			hld.each_vertex(u,t,[&](int l,int r){
				auto p=st2.query(n-1-r,n-1-l+1);
				f1={f1.first*p.first,f1.second*p.first+p.second};
			});
			f1={f1.first/a[t].first,(f1.second-a[t].second)/a[t].first};
			hld.each_vertex(t,v,[&](int l,int r){
				auto p=st1.query(l,r+1);
				f2={p.first*f2.first,p.second*f2.first+f2.second};
			});
			f1={f1.first*f2.first,f1.second*f2.first+f2.second};
			std::cout<<ModInt(x)*f1.first+f1.second<<std::endl;
		}
	}
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/vertex_set_path_composite.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
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
	}
public:
	std::vector<std::vector<int>> vec;
	std::vector<int> size,par,head,label;
	HeavyLightDecomposition(){}
	HeavyLightDecomposition(int m):n(m){
		vec.resize(n);size.resize(n);par.resize(n);head.resize(n);label.resize(n);
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
		vec.clear();size.clear();par.clear();head.clear();label.clear();
	}
};
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
#line 6 "test/vertex_set_path_composite.cpp"
class MySeg:public SegTree<std::pair<ModInt,ModInt>>{
	using MP=std::pair<ModInt,ModInt>;
	MP nodef(const MP& lhs,const MP& rhs)const{
		return {lhs.first*rhs.first,lhs.second*rhs.first+rhs.second};
	}
public:
	MySeg(int n):SegTree<MP>(n,{1,0},{1,0}){}
};
int n,q;
P a[200010];
int main(){
	ModInt::setMod(998244353);
	std::cin>>n>>q;
	rep(i,n)std::cin>>a[i].first>>a[i].second;
	HeavyLightDecomposition hld(n);
	MySeg st1(n),st2(n);
	rep(i,n-1){
		int u,v;
		std::cin>>u>>v;
		hld.add_edge(u,v);
	}
	hld.build(0);
	rep(i,n){
		st1.update(hld.label[i],a[i]);
		st2.update(n-1-hld.label[i],a[i]);
	}
	rep(i,q){
		int type;
		std::cin>>type;
		if(type==0){
			int p,c,d;
			std::cin>>p>>c>>d;
			a[p]={c,d};
			st1.update(hld.label[p],{c,d});
			st2.update(n-1-hld.label[p],{c,d});
		}
		else{
			int u,v,x;
			std::cin>>u>>v>>x;
			int t=hld.lca(u,v);
			std::pair<ModInt,ModInt> f1={1,0},f2={1,0};
			hld.each_vertex(u,t,[&](int l,int r){
				auto p=st2.query(n-1-r,n-1-l+1);
				f1={f1.first*p.first,f1.second*p.first+p.second};
			});
			f1={f1.first/a[t].first,(f1.second-a[t].second)/a[t].first};
			hld.each_vertex(t,v,[&](int l,int r){
				auto p=st1.query(l,r+1);
				f2={p.first*f2.first,p.second*f2.first+f2.second};
			});
			f1={f1.first*f2.first,f1.second*f2.first+f2.second};
			std::cout<<ModInt(x)*f1.first+f1.second<<std::endl;
		}
	}
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

