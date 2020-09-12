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


# :heavy_check_mark: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 16:29:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum">https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/SegTreeBeats.hpp.html">data-structure/SegTreeBeats.hpp</a>
* :question: <a href="../../../library/other/template.hpp.html">other/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../../other/template.hpp"
#include "../../data-structure/SegTreeBeats.hpp"
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	std::vector<lint> vec(n);
	rep(i,n)scanf("%lld",vec.data()+i);
	SegTreeBeats beats(vec);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			lint l,r,b;
			scanf("%lld%lld%lld",&l,&r,&b);
			beats.update_chmin(l,r,b);
		}
		else if(t==1){
			lint l,r,b;
			scanf("%lld%lld%lld",&l,&r,&b);
			beats.update_chmax(l,r,b);
		}
		else if(t==2){
			lint l,r,b;
			scanf("%lld%lld%lld",&l,&r,&b);
			beats.update_add(l,r,b);
		}
		else{
			lint l,r;
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",beats.query_sum(l,r));
		}
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/range_chmin_chmax_add_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
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
#line 3 "data-structure/SegTreeBeats.hpp"
class SegTreeBeats{
    unsigned int n;
    std::vector<lint> width,min[2],minc,max[2],maxc,sum,lazy;
    void eval(int k){
        if(n-1<=k)return;
        if(lazy[k]){
            update_node_add(2*k+1,lazy[k]);
            update_node_add(2*k+2,lazy[k]);
            lazy[k]=0;
        }
        if(max[0][k]<max[0][2*k+1]){
            update_node_max(2*k+1,max[0][k]);
        }
        if(min[0][k]>min[0][2*k+1]){
            update_node_min(2*k+1,min[0][k]);
        }
        if(max[0][k]<max[0][2*k+2]){
            update_node_max(2*k+2,max[0][k]);
        }
        if(min[0][k]>min[0][2*k+2]){
            update_node_min(2*k+2,min[0][k]);
        }
    }
    void combine(int k){
        sum[k]=sum[2*k+1]+sum[2*k+2];
        if(min[0][2*k+1]<min[0][2*k+2]){
            min[0][k]=min[0][2*k+1];
            minc[k]=minc[2*k+1];
            min[1][k]=std::min(min[1][2*k+1],min[0][2*k+2]);
        }
        else if(min[0][2*k+1]>min[0][2*k+2]){
            min[0][k]=min[0][2*k+2];
            minc[k]=minc[2*k+2];
            min[1][k]=std::min(min[0][2*k+1],min[1][2*k+2]);
        }
        else{
            min[0][k]=min[0][2*k+1];
            minc[k]=minc[2*k+1]+minc[2*k+2];
            min[1][k]=std::min(min[1][2*k+1],min[1][2*k+2]);
        }
        if(max[0][2*k+1]>max[0][2*k+2]){
            max[0][k]=max[0][2*k+1];
            maxc[k]=maxc[2*k+1];
            max[1][k]=std::max(max[1][2*k+1],max[0][2*k+2]);
        }
        else if(max[0][2*k+1]<max[0][2*k+2]){
            max[0][k]=max[0][2*k+2];
            maxc[k]=maxc[2*k+2];
            max[1][k]=std::max(max[0][2*k+1],max[1][2*k+2]);
        }
        else{
            max[0][k]=max[0][2*k+1];
            maxc[k]=maxc[2*k+1]+maxc[2*k+2];
            max[1][k]=std::max(max[1][2*k+1],max[1][2*k+2]);
        }
    }
    void update_node_max(int k,lint x){
        sum[k]+=(x-max[0][k])*maxc[k];
        if(max[0][k]==min[0][k])min[0][k]=x;
        else if(max[0][k]==min[1][k])min[1][k]=x;
        max[0][k]=x;
    }
    void update_node_min(int k,lint x){
        sum[k]+=(x-min[0][k])*minc[k];
        if(min[0][k]==max[0][k])max[0][k]=x;
        else if(min[0][k]==max[1][k])max[1][k]=x;
        min[0][k]=x;
    }
    void update_node_add(int k,lint x){
        min[0][k]+=x;
        if(min[1][k]!=LINF)min[1][k]+=x;
        max[0][k]+=x;
        if(max[1][k]!=-LINF)max[1][k]+=x;
        sum[k]+=x*width[k];
        lazy[k]+=x;
    }
public:
    SegTreeBeats(unsigned int size,lint def=0){
        *this=SegTreeBeats(std::vector<lint>(size,def));
    }
    SegTreeBeats(std::vector<lint> initvec){
        n=1;
        while(n<initvec.size())n*=2;
        width.resize(2*n-1);
        min[0].resize(2*n-1);min[1].resize(2*n-1,LINF);
        minc.resize(2*n-1);
        max[0].resize(2*n-1);max[1].resize(2*n-1,-LINF);
        maxc.resize(2*n-1);
        sum.resize(2*n-1);
        lazy.resize(2*n-1);
        for(int i=n-1;i<n-1+initvec.size();i++){
            min[0][i]=max[0][i]=sum[i]=initvec[i-n+1];
            minc[i]=maxc[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            combine(i);
        }
        width[0]=n;
        REP(i,2*n-2)width[i]=width[(i-1)/2]/2;
    }
    void update_chmin(int a,int b,lint x,int k=0,int l=0,int r=-1){
        if(r==-1)r=n;
        if(b<=l||r<=a||max[0][k]<=x)return;
        if(a<=l&&r<=b&&max[1][k]<x){
            update_node_max(k,x);
            return;
        }
        eval(k);
        update_chmin(a,b,x,2*k+1,l,(l+r)/2);
        update_chmin(a,b,x,2*k+2,(l+r)/2,r);
        combine(k);
    }
    void update_chmax(int a,int b,lint x,int k=0,int l=0,int r=-1){
        if(r==-1)r=n;
        if(b<=l||r<=a||x<=min[0][k])return;
        if(a<=l&&r<=b&&x<min[1][k]){
            update_node_min(k,x);
            return;
        }
        eval(k);
        update_chmax(a,b,x,2*k+1,l,(l+r)/2);
        update_chmax(a,b,x,2*k+2,(l+r)/2,r);
        combine(k);
    }
    void update_add(int a,int b,lint x,int k=0,int l=0,int r=-1){
        if(r==-1)r=n;
        if(b<=l||r<=a)return;
        if(a<=l&&r<=b){
            update_node_add(k,x);
            return;
        }
        eval(k);
        update_add(a,b,x,2*k+1,l,(l+r)/2);
        update_add(a,b,x,2*k+2,(l+r)/2,r);
        combine(k);
    }
    void update(int a,int b,lint x){
        update_chmin(a,b,x);
        update_chmax(a,b,x);
    }
    lint query_sum(int a,int b,int k=0,int l=0,int r=-1){
        if(r==-1)r=n;
        if(b<=l||r<=a)return 0;
        if(a<=l&&r<=b)return sum[k];
        eval(k);
        lint vl=query_sum(a,b,2*k+1,l,(l+r)/2);
        lint vr=query_sum(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    lint query_min(int a,int b,int k=0,int l=0,int r=-1){
        if(r==-1)r=n;
        if(b<=l||r<=a)return LINF;
        if(a<=l&&r<=b)return min[0][k];
        eval(k);
        lint vl=query_min(a,b,2*k+1,l,(l+r)/2);
        lint vr=query_min(a,b,2*k+2,(l+r)/2,r);
        return std::min(vl,vr);
    }
    lint query_max(int a,int b,int k=0,int l=0,int r=-1){
        if(r==-1)r=n;
        if(b<=l||r<=a)return -LINF;
        if(a<=l&&r<=b)return max[0][k];
        eval(k);
        lint vl=query_max(a,b,2*k+1,l,(l+r)/2);
        lint vr=query_max(a,b,2*k+2,(l+r)/2,r);
        return std::max(vl,vr);
    }
};
#line 4 "test/yosupo/range_chmin_chmax_add_range_sum.test.cpp"
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	std::vector<lint> vec(n);
	rep(i,n)scanf("%lld",vec.data()+i);
	SegTreeBeats beats(vec);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			lint l,r,b;
			scanf("%lld%lld%lld",&l,&r,&b);
			beats.update_chmin(l,r,b);
		}
		else if(t==1){
			lint l,r,b;
			scanf("%lld%lld%lld",&l,&r,&b);
			beats.update_chmax(l,r,b);
		}
		else if(t==2){
			lint l,r,b;
			scanf("%lld%lld%lld",&l,&r,&b);
			beats.update_add(l,r,b);
		}
		else{
			lint l,r;
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",beats.query_sum(l,r));
		}
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

