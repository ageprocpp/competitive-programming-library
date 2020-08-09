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


# :heavy_check_mark: test/range_kth_smallest.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/range_kth_smallest.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-09 16:53:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_kth_smallest">https://judge.yosupo.jp/problem/range_kth_smallest</a>


## Depends on

* :heavy_check_mark: <a href="../../library/data-structure/WaveletMatrix.hpp.html">data-structure/WaveletMatrix.hpp</a>
* :heavy_check_mark: <a href="../../library/other/template.hpp.html">other/template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../other/template.hpp"
#include "../data-structure/WaveletMatrix.hpp"
int n,q;
std::vector<int> a;
int main(){
    std::cin>>n>>q;
    a.resize(n);
    rep(i,n)std::cin>>a[i];
    WaveletMatrix wm(a);
    rep(i,q){
        int l,r,k;
        std::cin>>l>>r>>k;
        std::cout<<wm.quantile(l,r,k+1)<<std::endl;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/range_kth_smallest.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
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
#line 3 "data-structure/WaveletMatrix.hpp"
class WaveletMatrix{
    class BitVector{
        std::vector<bool> vec;
        std::vector<int> zerocnt,place[2];
    public:
        BitVector(const std::vector<bool>& vec):vec(vec){
            zerocnt.resize(vec.size());
            rep(i,vec.size()){
                if(!vec[i]){
                    zerocnt[i]++;
                    place[0].emplace_back(i);
                }
                else place[1].emplace_back(i);
                if(i)zerocnt[i]+=zerocnt[i-1];
            }
        }
        bool access(int x)const{
            return vec[x];
        }
        int rank(bool b,int x)const{
            if(!b)return zerocnt[x];
            return x+1-zerocnt[x];
        }
        int select(bool b,int x)const{
            return place[b][x];
        }
        unsigned int size()const{
            return vec.size();
        }
    };
    std::vector<BitVector> bit;
    std::vector<int> bound,head,fvec;
public:
    template<typename T>
    WaveletMatrix(std::vector<T> vec){
        for(int i=63;i>=0;i--){
            std::vector<bool> bvec;
            for(T j:vec)bvec.emplace_back(j&((lint)1<<i));
            std::stable_sort(all(vec),[&i](const T& lhs,const T& rhs){
                return (lhs&((lint)1<<i))<(rhs&((lint)1<<i));
            });
            if(!(vec.back()&((lint)1<<i)))continue;
            bit.emplace_back(bvec);
            bound.emplace_back(std::upper_bound(all(bvec),false)-bvec.begin());
        }
        fvec=vec;
        std::reverse(all(bit));
        std::reverse(all(bound));
        head.resize(vec.size());
        REP(i,vec.size()-1){
            if(vec[i-1]==vec[i])head[i]=head[i-1];
            else head[i]=i;
        }
    }
    int rank(int r,lint c)const{
        for(int i=bit.size()-1;i>=0;i--){
            r--;
            if(c&((lint)1<<i))r=bit[i].rank(false,bit[i].size()-1)+bit[i].rank(true,r);
            else r=bit[i].rank(false,r);
        }
        return r-head[r];
    }
    int quantile(int l,int r,int k){
        for(int i=bit.size()-1;i>=0;i--){
            int zeroc=bit[i].rank(false,r-1),onec=bit[i].rank(true,r-1);
            zeroc-=l==0?0:bit[i].rank(false,l-1);
            onec-=l==0?0:bit[i].rank(true,l-1);
            if(k<=zeroc){
                l=l==0?0:bit[i].rank(false,l-1);
                r=l+zeroc;
            }
            else{
                l=bit[i].rank(false,bit[i].size()-1)+(l==0?0:bit[i].rank(true,l-1));
                r=l+onec;
                k-=zeroc;
            }
        }
        return fvec[l];
    }
};
#line 4 "test/range_kth_smallest.test.cpp"
int n,q;
std::vector<int> a;
int main(){
    std::cin>>n>>q;
    a.resize(n);
    rep(i,n)std::cin>>a[i];
    WaveletMatrix wm(a);
    rep(i,q){
        int l,r,k;
        std::cin>>l>>r>>k;
        std::cout<<wm.quantile(l,r,k+1)<<std::endl;
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

