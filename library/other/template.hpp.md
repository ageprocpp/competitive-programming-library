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


# :heavy_check_mark: other/template.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#795f3202b17cb6bc3d4b771d8c6c9eaf">other</a>
* <a href="{{ site.github.repository_url }}/blob/master/other/template.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 16:29:29+09:00




## Required by

* :warning: <a href="../algebraic/FastFourierTransform.hpp.html">algebraic/FastFourierTransform.hpp</a>
* :heavy_check_mark: <a href="../algebraic/FloorSum.hpp.html">algebraic/FloorSum.hpp</a>
* :warning: <a href="../algebraic/LagrangeInterpolation.hpp.html">algebraic/LagrangeInterpolation.hpp</a>
* :heavy_check_mark: <a href="../algebraic/ModInt.hpp.html">algebraic/ModInt.hpp</a>
* :warning: <a href="../algebraic/MyComplex.hpp.html">algebraic/MyComplex.hpp</a>
* :heavy_check_mark: <a href="../algebraic/NumberTheoreticTransform.hpp.html">algebraic/NumberTheoreticTransform.hpp</a>
* :heavy_check_mark: <a href="../data-structure/BIT.hpp.html">data-structure/BIT.hpp</a>
* :warning: <a href="../data-structure/ConvexHullTrick.hpp.html">data-structure/ConvexHullTrick.hpp</a>
* :heavy_check_mark: <a href="../data-structure/IntervalSegTree.hpp.html">data-structure/IntervalSegTree.hpp</a>
* :heavy_check_mark: <a href="../data-structure/LiChaoTree.hpp.html">data-structure/LiChaoTree.hpp</a>
* :warning: <a href="../data-structure/MonotoneConvexHullTrick.hpp.html">data-structure/MonotoneConvexHullTrick.hpp</a>
* :warning: <a href="../data-structure/RBST.hpp.html">data-structure/RBST.hpp</a>
* :warning: <a href="../data-structure/RBSTset.hpp.html">data-structure/RBSTset.hpp</a>
* :heavy_check_mark: <a href="../data-structure/SegTree.hpp.html">data-structure/SegTree.hpp</a>
* :heavy_check_mark: <a href="../data-structure/SegTreeBeats.hpp.html">data-structure/SegTreeBeats.hpp</a>
* :heavy_check_mark: <a href="../data-structure/SparseTable.hpp.html">data-structure/SparseTable.hpp</a>
* :heavy_check_mark: <a href="../data-structure/WaveletMatrix.hpp.html">data-structure/WaveletMatrix.hpp</a>
* :heavy_check_mark: <a href="../graph/FordFulkerson.hpp.html">graph/FordFulkerson.hpp</a>
* :heavy_check_mark: <a href="../graph/HeavyLightDecomposition.hpp.html">graph/HeavyLightDecomposition.hpp</a>
* :heavy_check_mark: <a href="../graph/MinCostFlow.hpp.html">graph/MinCostFlow.hpp</a>
* :warning: <a href="../graph/PersistentUnionFind.hpp.html">graph/PersistentUnionFind.hpp</a>
* :heavy_check_mark: <a href="../graph/Tree.hpp.html">graph/Tree.hpp</a>
* :heavy_check_mark: <a href="../graph/UnionFind.hpp.html">graph/UnionFind.hpp</a>
* :heavy_check_mark: <a href="../string/RollingHash.hpp.html">string/RollingHash.hpp</a>
* :heavy_check_mark: <a href="../string/SuffixArray.hpp.html">string/SuffixArray.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_B_RollingHash.test.cpp.html">test/aoj/ALDS1_14_B_RollingHash.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_B_SuffixArray.test.cpp.html">test/aoj/ALDS1_14_B_SuffixArray.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_D.test.cpp.html">test/aoj/DSL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_E.test.cpp.html">test/aoj/DSL_2_E.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_F.test.cpp.html">test/aoj/DSL_2_F.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_G.test.cpp.html">test/aoj/DSL_2_G.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_H.test.cpp.html">test/aoj/DSL_2_H.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_I.test.cpp.html">test/aoj/DSL_2_I.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_6_A.test.cpp.html">test/aoj/GRL_6_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_6_B.test.cpp.html">test/aoj/GRL_6_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/aplusb.test.cpp.html">test/yosupo/aplusb.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/associative_array.test.cpp.html">test/yosupo/associative_array.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod.test.cpp.html">test/yosupo/convolution_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/lca.test.cpp.html">test/yosupo/lca.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/line_add_get_min.test.cpp.html">test/yosupo/line_add_get_min.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/many_aplusb.test.cpp.html">test/yosupo/many_aplusb.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_add_range_sum.test.cpp.html">test/yosupo/point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/range_affine_range_sum.test.cpp.html">test/yosupo/range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp.html">test/yosupo/range_chmin_chmax_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/range_kth_smallest.test.cpp.html">test/yosupo/range_kth_smallest.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/segment_add_get_min.test.cpp.html">test/yosupo/segment_add_get_min.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/static_range_sum.test.cpp.html">test/yosupo/static_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/staticrmq.test.cpp.html">test/yosupo/staticrmq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/suffixarray.test.cpp.html">test/yosupo/suffixarray.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sum_of_floor_of_linear.test.cpp.html">test/yosupo/sum_of_floor_of_linear.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/tree_diameter.test.cpp.html">test/yosupo/tree_diameter.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/unionfind.test.cpp.html">test/yosupo/unionfind.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_path_sum.test.cpp.html">test/yosupo/vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html">test/yosupo/vertex_add_subtree_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_set_path_composite.test.cpp.html">test/yosupo/vertex_set_path_composite.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

