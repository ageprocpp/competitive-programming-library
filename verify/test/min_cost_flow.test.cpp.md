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


# :heavy_check_mark: test/min_cost_flow.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/min_cost_flow.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-29 13:50:01+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B">https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/graph/MinCostFlow.hpp.html">graph/MinCostFlow.hpp</a>
* :heavy_check_mark: <a href="../../library/other/template.hpp.html">other/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B"
#include "../other/template.hpp"
#include "../graph/MinCostFlow.hpp"
int n,m,f;
int main(){
    std::cin>>n>>m>>f;
    MinCostFlow mcf(n);
    rep(i,m){
        int u,v,c,d;
        std::cin>>u>>v>>c>>d;
        mcf.add_edge(u,v,c,d);
    }
    std::cout<<mcf.min_cost_flow(0,n-1,f)<<std::endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/min_cost_flow.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B"
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
#line 2 "graph/MinCostFlow.hpp"
class MinCostFlow{
    class edge{
    public:
        int to,cap;
        lint cost;
        int rev;
    };
    int n;
    std::vector<std::vector<edge>> vec;
    std::vector<int> prevv,preve;
    std::vector<lint> h,dist;
    bool negative=false;
    lint BellmanFord(int s,int t){
        dist.assign(n,LINF);
        dist[s]=0;
        rep(i,n-1){
            rep(j,n){
                rep(k,vec[j].size()){
                    const edge &e=vec[j][k];
                    if(e.cap>0&&chmin(dist[e.to],dist[j]+e.cost+h[j]-h[e.to])){
                        prevv[e.to]=j;
                        preve[e.to]=k;
                    }
                }
            }
        }
        if(dist[t]==LINF){
            std::cerr<<"The demand is over maximum flow."<<std::endl;
            return -1;
        }
        rep(i,n)h[i]+=dist[i];
        for(int i=t;i!=s;i=prevv[i]){
            vec[prevv[i]][preve[i]].cap--;
            vec[i][vec[prevv[i]][preve[i]].rev].cap++;
        }
        return h[t];
    }
public:
    MinCostFlow(int n):n(n){
        vec.resize(n);
        h.resize(n);
        dist.resize(n);
        prevv.resize(n);
        preve.resize(n);
    }
    void add_edge(int from,int to,int cap,lint cost){
        if(cost<0)negative=true;
        vec[from].push_back({to,cap,cost,(int)vec[to].size()});
        vec[to].push_back({from,0,-cost,(int)vec[from].size()-1});
    }
    lint min_cost_flow(int s,int t,int f){
        lint res=0;
        h.assign(n,0);
        if(negative){
            res+=BellmanFord(s,t);
            f--;
        }
        while(f>0){
            dist.assign(n,LINF);
            dist[s]=0;
            prique<LP> que;
            que.push({0,s});
            while(!que.empty()){
                LP p=que.top();
                que.pop();
                if(dist[p.second]<p.first)continue;
                rep(i,vec[p.second].size()){
                    edge &e=vec[p.second][i];
                    if(e.cap>0&&chmin(dist[e.to],dist[p.second]+e.cost+h[p.second]-h[e.to])){
                        prevv[e.to]=p.second;
                        preve[e.to]=i;
                        que.push({dist[e.to],e.to});
                    }
                }
            }
            if(dist[t]==LINF){
                std::cerr<<"The demand is over maximum flow."<<std::endl;
                return -1;
            }
            rep(i,n)h[i]+=dist[i];
            int d=f;
            for(int i=t;i!=s;i=prevv[i]){
                chmin(d,vec[prevv[i]][preve[i]].cap);
            }
            f-=d;
            res+=(lint)d*h[t];
            for(int i=t;i!=s;i=prevv[i]){
                vec[prevv[i]][preve[i]].cap-=d;
                vec[i][vec[prevv[i]][preve[i]].rev].cap+=d;
            }
        }
        return res;
    }
};
#line 4 "test/min_cost_flow.test.cpp"
int n,m,f;
int main(){
    std::cin>>n>>m>>f;
    MinCostFlow mcf(n);
    rep(i,m){
        int u,v,c,d;
        std::cin>>u>>v>>c>>d;
        mcf.add_edge(u,v,c,d);
    }
    std::cout<<mcf.min_cost_flow(0,n-1,f)<<std::endl;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

