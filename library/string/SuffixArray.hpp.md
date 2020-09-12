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


# :heavy_check_mark: string/SuffixArray.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/SuffixArray.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 16:29:29+09:00




## Depends on

* :heavy_check_mark: <a href="../other/template.hpp.html">other/template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_B_SuffixArray.test.cpp.html">test/aoj/ALDS1_14_B_SuffixArray.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../other/template.hpp"
class SuffixArray{
	std::string S;
	std::vector<int> SA;
	std::vector<int> InducedSorting(const std::vector<int> &S,int count){
		std::vector<int> SA(S.size(),-1);
		std::vector<char> type=AssignType(S);
		std::vector<int> bucket=GetBucket(S,count);
		std::vector<int> nextLms(S.size(),-1),orderedLms;
		int lastLms=-1;
		rep(i,S.size()){
			if(type[i]==2){
				SA[--bucket[S[i]]]=i;
				if(lastLms!=-1)nextLms[lastLms]=i;
				lastLms=i;
				orderedLms.emplace_back(i);
			}
		}
		nextLms[lastLms]=lastLms;
		SortL(S,SA,type,count);
		SortS(S,SA,type,count);
		std::vector<int> lms;
		for(int i:SA){
			if(type[i]==2)lms.emplace_back(i);
		}
		int nowrank=0;
		std::vector<int> newS={0};
		REP(i,lms.size()-1){
			int pre=lms[i-1],now=lms[i];
			if(nextLms[pre]-pre!=nextLms[now]-now)newS.emplace_back(++nowrank);
			else{
				bool flag=false;
				rep(j,nextLms[pre]-pre+1){
					if(S[pre+j]!=S[now+j]){
						flag=true;
						break;
					}
				}
				if(flag)nowrank++;
				newS.emplace_back(nowrank);
			}
		}
		if(nowrank+1!=lms.size()){
			std::vector<int> V(S.size(),-1);
			rep(i,lms.size())V[lms[i]]=newS[i];
			newS.clear();
			rep(i,S.size()){
				if(V[i]!=-1)newS.emplace_back(V[i]);
			}
			std::vector<int> SA_=InducedSorting(newS,nowrank+1);
			rep(i,SA_.size())lms[i]=orderedLms[SA_[i]];
		}
		SA.assign(S.size(),-1);
		bucket=GetBucket(S,count);
		for(int i=lms.size()-1;i>=0;i--)SA[--bucket[S[lms[i]]]]=lms[i];
		SortL(S,SA,type,count);
		SortS(S,SA,type,count);
		return SA;
	}
	std::vector<char> AssignType(const std::vector<int> &S){
		std::vector<char>type(S.size());
		type.back()=2;
		for(int i=(int)S.size()-2;i>=0;i--){
			if(S[i]<S[i+1])type[i]=0;
			else if(S[i]>S[i+1]){
				type[i]=1;
				if(type[i+1]==0)type[i+1]=2;
			}
			else type[i]=type[i+1];
		}
		return type;
	}
	std::vector<int> GetBucket(const std::vector<int> &S,int count){
		std::vector<int> bucket(count);
		for(int i:S)bucket[i]++;
		rep(i,count-1)bucket[i+1]+=bucket[i];
		return bucket;
	}
	void SortL(const std::vector<int> &S,std::vector<int> &SA,const std::vector<char> &type,int count){
		std::vector<int> bucket=GetBucket(S,count);
		for(int i:SA){
			if(i>0&&type[i-1]==1)SA[bucket[S[i-1]-1]++]=i-1;
		}
	}
	void SortS(const std::vector<int> &S,std::vector<int> &SA,const std::vector<char> &type,int count){
		std::vector<int> bucket=GetBucket(S,count);
		for(int i=S.size()-1;i>=0;i--){
			int j=SA[i];
			if(j>0&&(type[j-1]==0||type[j-1]==2))SA[--bucket[S[j-1]]]=j-1;
		}
	}
	int match(const std::string& T,int index)const{
		rep(i,T.size()){
			if(i+index>=S.size())return 1;
			if(S[i+index]<T[i])return 1;
			if(S[i+index]>T[i])return -1;
		}
		return 0;
	}
public:
	SuffixArray(const std::string& S):S(S){
		std::vector<int> conv;
		int min=INF,max=-INF;
		for(char i:S){
			chmin(min,i);chmax(max,i);
		}
		for(char i:S)conv.emplace_back(i-min+1);
		conv.emplace_back(0);
		SA=InducedSorting(conv,max-min+2);
	}
	P occ(const std::string& T)const{
		int minl=0,maxl=S.size()+1;
		while(minl+1<maxl){
			int mid=(minl+maxl)/2;
			if(match(T,SA[mid])<=0)maxl=mid;
			else minl=mid;
		}
		int minr=0,maxr=S.size()+1;
		while(minr+1<maxr){
			int mid=(minr+maxr)/2;
			if(match(T,SA[mid])<0)maxr=mid;
			else minr=mid;
		}
		return {maxl,maxr};
	}
	std::vector<int> locate(const std::string &T)const{
		std::vector<bool> v(S.size()+1);
		std::vector<int> res;
		P range=occ(T);
		for(int i=range.first;i<range.second;i++)v[SA[i]]=true;
		rep(i,S.size()+1){
			if(v[i])res.emplace_back(i);
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
#line 3 "string/SuffixArray.hpp"
class SuffixArray{
	std::string S;
	std::vector<int> SA;
	std::vector<int> InducedSorting(const std::vector<int> &S,int count){
		std::vector<int> SA(S.size(),-1);
		std::vector<char> type=AssignType(S);
		std::vector<int> bucket=GetBucket(S,count);
		std::vector<int> nextLms(S.size(),-1),orderedLms;
		int lastLms=-1;
		rep(i,S.size()){
			if(type[i]==2){
				SA[--bucket[S[i]]]=i;
				if(lastLms!=-1)nextLms[lastLms]=i;
				lastLms=i;
				orderedLms.emplace_back(i);
			}
		}
		nextLms[lastLms]=lastLms;
		SortL(S,SA,type,count);
		SortS(S,SA,type,count);
		std::vector<int> lms;
		for(int i:SA){
			if(type[i]==2)lms.emplace_back(i);
		}
		int nowrank=0;
		std::vector<int> newS={0};
		REP(i,lms.size()-1){
			int pre=lms[i-1],now=lms[i];
			if(nextLms[pre]-pre!=nextLms[now]-now)newS.emplace_back(++nowrank);
			else{
				bool flag=false;
				rep(j,nextLms[pre]-pre+1){
					if(S[pre+j]!=S[now+j]){
						flag=true;
						break;
					}
				}
				if(flag)nowrank++;
				newS.emplace_back(nowrank);
			}
		}
		if(nowrank+1!=lms.size()){
			std::vector<int> V(S.size(),-1);
			rep(i,lms.size())V[lms[i]]=newS[i];
			newS.clear();
			rep(i,S.size()){
				if(V[i]!=-1)newS.emplace_back(V[i]);
			}
			std::vector<int> SA_=InducedSorting(newS,nowrank+1);
			rep(i,SA_.size())lms[i]=orderedLms[SA_[i]];
		}
		SA.assign(S.size(),-1);
		bucket=GetBucket(S,count);
		for(int i=lms.size()-1;i>=0;i--)SA[--bucket[S[lms[i]]]]=lms[i];
		SortL(S,SA,type,count);
		SortS(S,SA,type,count);
		return SA;
	}
	std::vector<char> AssignType(const std::vector<int> &S){
		std::vector<char>type(S.size());
		type.back()=2;
		for(int i=(int)S.size()-2;i>=0;i--){
			if(S[i]<S[i+1])type[i]=0;
			else if(S[i]>S[i+1]){
				type[i]=1;
				if(type[i+1]==0)type[i+1]=2;
			}
			else type[i]=type[i+1];
		}
		return type;
	}
	std::vector<int> GetBucket(const std::vector<int> &S,int count){
		std::vector<int> bucket(count);
		for(int i:S)bucket[i]++;
		rep(i,count-1)bucket[i+1]+=bucket[i];
		return bucket;
	}
	void SortL(const std::vector<int> &S,std::vector<int> &SA,const std::vector<char> &type,int count){
		std::vector<int> bucket=GetBucket(S,count);
		for(int i:SA){
			if(i>0&&type[i-1]==1)SA[bucket[S[i-1]-1]++]=i-1;
		}
	}
	void SortS(const std::vector<int> &S,std::vector<int> &SA,const std::vector<char> &type,int count){
		std::vector<int> bucket=GetBucket(S,count);
		for(int i=S.size()-1;i>=0;i--){
			int j=SA[i];
			if(j>0&&(type[j-1]==0||type[j-1]==2))SA[--bucket[S[j-1]]]=j-1;
		}
	}
	int match(const std::string& T,int index)const{
		rep(i,T.size()){
			if(i+index>=S.size())return 1;
			if(S[i+index]<T[i])return 1;
			if(S[i+index]>T[i])return -1;
		}
		return 0;
	}
public:
	SuffixArray(const std::string& S):S(S){
		std::vector<int> conv;
		int min=INF,max=-INF;
		for(char i:S){
			chmin(min,i);chmax(max,i);
		}
		for(char i:S)conv.emplace_back(i-min+1);
		conv.emplace_back(0);
		SA=InducedSorting(conv,max-min+2);
	}
	P occ(const std::string& T)const{
		int minl=0,maxl=S.size()+1;
		while(minl+1<maxl){
			int mid=(minl+maxl)/2;
			if(match(T,SA[mid])<=0)maxl=mid;
			else minl=mid;
		}
		int minr=0,maxr=S.size()+1;
		while(minr+1<maxr){
			int mid=(minr+maxr)/2;
			if(match(T,SA[mid])<0)maxr=mid;
			else minr=mid;
		}
		return {maxl,maxr};
	}
	std::vector<int> locate(const std::string &T)const{
		std::vector<bool> v(S.size()+1);
		std::vector<int> res;
		P range=occ(T);
		for(int i=range.first;i<range.second;i++)v[SA[i]]=true;
		rep(i,S.size()+1){
			if(v[i])res.emplace_back(i);
		}
		return res;
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

