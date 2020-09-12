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


# :warning: data-structure/RBST.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/RBST.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 16:29:29+09:00




## Depends on

* :heavy_check_mark: <a href="../other/template.hpp.html">other/template.hpp</a>


## Required by

* :warning: <a href="RBSTset.hpp.html">data-structure/RBSTset.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../other/template.hpp"
template<typename T>
class RBST{
	class Node{
	public:
		Node *left=nullptr,*right=nullptr;
		T value;
		int size;
	};
	Node* root=nullptr;
	RBST(Node* r):root(r){}
	static ulint engine(){
		static ulint cur=std::clock();
		cur^=cur<<13;
		cur^=cur>>17;
		cur^=cur<<5;
		return cur;
	}
	static int size(Node* trg){return trg?trg->size:0;}
	static Node* apply(Node* trg){
		trg->size=size(trg->left)+size(trg->right)+1;
		return trg;
	}
	static Node* merge(Node* left,Node* right){
		if(!left)return right;
		if(!right)return left;
		if(engine()%(size(left)+size(right))<size(left)){
			left->right=merge(left->right,right);
			return apply(left);
		}
		else{
			right->left=merge(left,right->left);
			return apply(right);
		}
	}
	static std::pair<Node*,Node*> split(Node* trg,int pos){
		if(!trg)return {nullptr,nullptr};
		if(pos<=size(trg->left)){
			auto tmp=split(trg->left,pos);
			trg->left=tmp.second;
			return {tmp.first,apply(trg)};
		}
		else{
			auto tmp=split(trg->right,pos-size(trg->left)-1);
			trg->right=tmp.first;
			return {apply(trg),tmp.second};
		}
	}
	static Node* insert(Node* node,int idx,const T& val){
		auto tmp=split(node,idx);
		return merge(merge(tmp.first,new Node{nullptr,nullptr,val,1}),tmp.second);
	}
	static Node* erase(Node* node,int idx){
		auto left=split(node,idx);
		auto right=split(left.second,1);
		delete right.first;
		return merge(left.first,right.second);
	}
	static Node* build(const std::vector<T> &data,int l,int r){
		if(r==-1)r=data.size();
		if(data.empty()||l>=r)return nullptr;
		int idx=engine()%(r-l)+l;
		return apply(new Node{build(data,l,idx),build(data,idx+1,r),data[idx],1});
	}
	void clear(Node* trg){
		if(!trg)return;
		clear(trg->left);
		clear(trg->right);
		delete trg;
	}
public:
	RBST(){}
	RBST(const std::vector<T> &data){this->build(data);}
	RBST merge(const RBST& trg){return RBST(merge(root,trg.root));}
	std::pair<RBST,RBST> split(int pos){
		auto tmp=split(root,pos);
		return {RBST(tmp.first),RBST(tmp.second)};
	}
	T& find(int idx)const{
		Node* cur=root;
		int cnt=0;
		while(true){
			if(cnt+size(cur->left)==idx)return cur->value;
			else if(cnt+size(cur->left)>idx)cur=cur->left;
			else cnt+=size(cur->left)+1,cur=cur->right;
		}
	}
	void insert(int idx,const T& val){root=insert(root,idx,val);}
	void erase(int idx){root=erase(root,idx);}
	int upper_bound(int val)const{
		Node* cur=root;
		int res=0,cnt=0;
		while(cur){
			if(cur->value<=val)cnt+=size(cur->left)+1,cur=cur->right;
			else{
				res+=cnt;
				cnt=0;
				cur=cur->left;
			}
		}
		return res+cnt;
	}
	int lower_bound(int val)const{
		Node* cur=root;
		int res=0,cnt=0;
		while(cur){
			if(cur->value<val)cnt+=size(cur->left)+1,cur=cur->right;
			else{
				res+=cnt;
				cnt=0;
				cur=cur->left;
			}
		}
		return res+cnt;
	}
	void build(const std::vector<T> &data){root=build(data,0,-1);}
	void clear(){clear(root);root=nullptr;}
	int size()const{return empty()?0:root->size;}
	bool empty()const{return !root;}
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
#line 3 "data-structure/RBST.hpp"
template<typename T>
class RBST{
	class Node{
	public:
		Node *left=nullptr,*right=nullptr;
		T value;
		int size;
	};
	Node* root=nullptr;
	RBST(Node* r):root(r){}
	static ulint engine(){
		static ulint cur=std::clock();
		cur^=cur<<13;
		cur^=cur>>17;
		cur^=cur<<5;
		return cur;
	}
	static int size(Node* trg){return trg?trg->size:0;}
	static Node* apply(Node* trg){
		trg->size=size(trg->left)+size(trg->right)+1;
		return trg;
	}
	static Node* merge(Node* left,Node* right){
		if(!left)return right;
		if(!right)return left;
		if(engine()%(size(left)+size(right))<size(left)){
			left->right=merge(left->right,right);
			return apply(left);
		}
		else{
			right->left=merge(left,right->left);
			return apply(right);
		}
	}
	static std::pair<Node*,Node*> split(Node* trg,int pos){
		if(!trg)return {nullptr,nullptr};
		if(pos<=size(trg->left)){
			auto tmp=split(trg->left,pos);
			trg->left=tmp.second;
			return {tmp.first,apply(trg)};
		}
		else{
			auto tmp=split(trg->right,pos-size(trg->left)-1);
			trg->right=tmp.first;
			return {apply(trg),tmp.second};
		}
	}
	static Node* insert(Node* node,int idx,const T& val){
		auto tmp=split(node,idx);
		return merge(merge(tmp.first,new Node{nullptr,nullptr,val,1}),tmp.second);
	}
	static Node* erase(Node* node,int idx){
		auto left=split(node,idx);
		auto right=split(left.second,1);
		delete right.first;
		return merge(left.first,right.second);
	}
	static Node* build(const std::vector<T> &data,int l,int r){
		if(r==-1)r=data.size();
		if(data.empty()||l>=r)return nullptr;
		int idx=engine()%(r-l)+l;
		return apply(new Node{build(data,l,idx),build(data,idx+1,r),data[idx],1});
	}
	void clear(Node* trg){
		if(!trg)return;
		clear(trg->left);
		clear(trg->right);
		delete trg;
	}
public:
	RBST(){}
	RBST(const std::vector<T> &data){this->build(data);}
	RBST merge(const RBST& trg){return RBST(merge(root,trg.root));}
	std::pair<RBST,RBST> split(int pos){
		auto tmp=split(root,pos);
		return {RBST(tmp.first),RBST(tmp.second)};
	}
	T& find(int idx)const{
		Node* cur=root;
		int cnt=0;
		while(true){
			if(cnt+size(cur->left)==idx)return cur->value;
			else if(cnt+size(cur->left)>idx)cur=cur->left;
			else cnt+=size(cur->left)+1,cur=cur->right;
		}
	}
	void insert(int idx,const T& val){root=insert(root,idx,val);}
	void erase(int idx){root=erase(root,idx);}
	int upper_bound(int val)const{
		Node* cur=root;
		int res=0,cnt=0;
		while(cur){
			if(cur->value<=val)cnt+=size(cur->left)+1,cur=cur->right;
			else{
				res+=cnt;
				cnt=0;
				cur=cur->left;
			}
		}
		return res+cnt;
	}
	int lower_bound(int val)const{
		Node* cur=root;
		int res=0,cnt=0;
		while(cur){
			if(cur->value<val)cnt+=size(cur->left)+1,cur=cur->right;
			else{
				res+=cnt;
				cnt=0;
				cur=cur->left;
			}
		}
		return res+cnt;
	}
	void build(const std::vector<T> &data){root=build(data,0,-1);}
	void clear(){clear(root);root=nullptr;}
	int size()const{return empty()?0:root->size;}
	bool empty()const{return !root;}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

