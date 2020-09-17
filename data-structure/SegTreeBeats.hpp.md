---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
    title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #pragma target(\"avx2\")\n#pragma optimize(\"O3\")\n#pragma optimize(\"unroll-loops\"\
    )\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <string.h>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#define rep(i,n) for(int i=0;i<(n);i++)\n\
    #define REP(i,n) for(int i=1;i<=(n);i++)\n#define all(V) V.begin(),V.end()\ntypedef\
    \ unsigned int uint;\ntypedef long long lint;\ntypedef unsigned long long ulint;\n\
    typedef std::pair<int, int> P;\ntypedef std::pair<lint, lint> LP;\nconstexpr int\
    \ INF = INT_MAX/2;\nconstexpr lint LINF = LLONG_MAX/2;\nconstexpr double eps =\
    \ DBL_EPSILON;\nconstexpr double PI=3.141592653589793238462643383279;\ntemplate<class\
    \ T>\nclass prique :public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {};\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\
    \tif (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ntemplate\
    \ <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ninline lint gcd(lint\
    \ a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b; b = c % b;\n\t}\n\t\
    return a;\n}\ninline lint lcm(lint a, lint b) {\n\treturn a / gcd(a, b) * b;\n\
    }\nbool isprime(lint n) {\n\tif (n == 1)return false;\n\tfor (int i = 2; i * i\
    \ <= n; i++) {\n\t\tif (n % i == 0)return false;\n\t}\n\treturn true;\n}\ntemplate<typename\
    \ T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile(b){\n\t\tif(b&1)res*=a;\n\t\
    \ta*=a;\n\t\tb>>=1;\n\t}\n\treturn res;\n}\nlint modpow(lint a, lint b, lint m)\
    \ {\n\tlint res(1);\n\twhile(b){\n\t\tif(b&1){\n\t\t\tres*=a;res%=m;\n\t\t}\n\t\
    \ta*=a;a%=m;\n\t\tb>>=1;\n\t}\n\treturn res;\n}\ntemplate<typename T>\nvoid printArray(std::vector<T>&\
    \ vec) {\n\trep(i, vec.size()){\n\t\tstd::cout << vec[i];\n\t\tstd::cout<<(i==(int)vec.size()-1?\"\
    \\n\":\" \");\n\t}\n}\ntemplate<typename T>\nvoid printArray(T l, T r) {\n\tT\
    \ rprev = std::prev(r);\n\tfor (T i = l; i != rprev; i++) {\n\t\tstd::cout <<\
    \ *i << \" \";\n\t}\n\tstd::cout << *rprev << std::endl;\n}\nLP extGcd(lint a,lint\
    \ b) {\n\tif(b==0)return {1,0};\n\tLP s=extGcd(b,a%b);\n\tstd::swap(s.first,s.second);\n\
    \ts.second-=a/b*s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1,const lint&\
    \ m1,const lint& b2,const lint& m2) {\n\tlint p=extGcd(m1,m2).first;\n\tlint tmp=(b2-b1)*p%m2;\n\
    \tlint r=(b1+m1*tmp+m1*m2)%(m1*m2);\n\treturn std::make_pair(r,m1*m2);\n}\ntemplate<typename\
    \ F>\ninline constexpr decltype(auto) lambda_fix(F&& f){\n\treturn [f=std::forward<F>(f)](auto&&...\
    \ args){\n\t\treturn f(f,std::forward<decltype(args)>(args)...);\n\t};\n}\n#line\
    \ 3 \"data-structure/SegTreeBeats.hpp\"\nclass SegTreeBeats{\n    unsigned int\
    \ n;\n    std::vector<lint> width,min[2],minc,max[2],maxc,sum,lazy;\n    void\
    \ eval(int k){\n        if(n-1<=k)return;\n        if(lazy[k]){\n            update_node_add(2*k+1,lazy[k]);\n\
    \            update_node_add(2*k+2,lazy[k]);\n            lazy[k]=0;\n       \
    \ }\n        if(max[0][k]<max[0][2*k+1]){\n            update_node_max(2*k+1,max[0][k]);\n\
    \        }\n        if(min[0][k]>min[0][2*k+1]){\n            update_node_min(2*k+1,min[0][k]);\n\
    \        }\n        if(max[0][k]<max[0][2*k+2]){\n            update_node_max(2*k+2,max[0][k]);\n\
    \        }\n        if(min[0][k]>min[0][2*k+2]){\n            update_node_min(2*k+2,min[0][k]);\n\
    \        }\n    }\n    void combine(int k){\n        sum[k]=sum[2*k+1]+sum[2*k+2];\n\
    \        if(min[0][2*k+1]<min[0][2*k+2]){\n            min[0][k]=min[0][2*k+1];\n\
    \            minc[k]=minc[2*k+1];\n            min[1][k]=std::min(min[1][2*k+1],min[0][2*k+2]);\n\
    \        }\n        else if(min[0][2*k+1]>min[0][2*k+2]){\n            min[0][k]=min[0][2*k+2];\n\
    \            minc[k]=minc[2*k+2];\n            min[1][k]=std::min(min[0][2*k+1],min[1][2*k+2]);\n\
    \        }\n        else{\n            min[0][k]=min[0][2*k+1];\n            minc[k]=minc[2*k+1]+minc[2*k+2];\n\
    \            min[1][k]=std::min(min[1][2*k+1],min[1][2*k+2]);\n        }\n   \
    \     if(max[0][2*k+1]>max[0][2*k+2]){\n            max[0][k]=max[0][2*k+1];\n\
    \            maxc[k]=maxc[2*k+1];\n            max[1][k]=std::max(max[1][2*k+1],max[0][2*k+2]);\n\
    \        }\n        else if(max[0][2*k+1]<max[0][2*k+2]){\n            max[0][k]=max[0][2*k+2];\n\
    \            maxc[k]=maxc[2*k+2];\n            max[1][k]=std::max(max[0][2*k+1],max[1][2*k+2]);\n\
    \        }\n        else{\n            max[0][k]=max[0][2*k+1];\n            maxc[k]=maxc[2*k+1]+maxc[2*k+2];\n\
    \            max[1][k]=std::max(max[1][2*k+1],max[1][2*k+2]);\n        }\n   \
    \ }\n    void update_node_max(int k,lint x){\n        sum[k]+=(x-max[0][k])*maxc[k];\n\
    \        if(max[0][k]==min[0][k])min[0][k]=x;\n        else if(max[0][k]==min[1][k])min[1][k]=x;\n\
    \        max[0][k]=x;\n    }\n    void update_node_min(int k,lint x){\n      \
    \  sum[k]+=(x-min[0][k])*minc[k];\n        if(min[0][k]==max[0][k])max[0][k]=x;\n\
    \        else if(min[0][k]==max[1][k])max[1][k]=x;\n        min[0][k]=x;\n   \
    \ }\n    void update_node_add(int k,lint x){\n        min[0][k]+=x;\n        if(min[1][k]!=LINF)min[1][k]+=x;\n\
    \        max[0][k]+=x;\n        if(max[1][k]!=-LINF)max[1][k]+=x;\n        sum[k]+=x*width[k];\n\
    \        lazy[k]+=x;\n    }\npublic:\n    SegTreeBeats(unsigned int size,lint\
    \ def=0){\n        *this=SegTreeBeats(std::vector<lint>(size,def));\n    }\n \
    \   SegTreeBeats(std::vector<lint> initvec){\n        n=1;\n        while(n<initvec.size())n*=2;\n\
    \        width.resize(2*n-1);\n        min[0].resize(2*n-1);min[1].resize(2*n-1,LINF);\n\
    \        minc.resize(2*n-1);\n        max[0].resize(2*n-1);max[1].resize(2*n-1,-LINF);\n\
    \        maxc.resize(2*n-1);\n        sum.resize(2*n-1);\n        lazy.resize(2*n-1);\n\
    \        for(int i=n-1;i<n-1+initvec.size();i++){\n            min[0][i]=max[0][i]=sum[i]=initvec[i-n+1];\n\
    \            minc[i]=maxc[i]=1;\n        }\n        for(int i=n-2;i>=0;i--){\n\
    \            combine(i);\n        }\n        width[0]=n;\n        REP(i,2*n-2)width[i]=width[(i-1)/2]/2;\n\
    \    }\n    void update_chmin(int a,int b,lint x,int k=0,int l=0,int r=-1){\n\
    \        if(r==-1)r=n;\n        if(b<=l||r<=a||max[0][k]<=x)return;\n        if(a<=l&&r<=b&&max[1][k]<x){\n\
    \            update_node_max(k,x);\n            return;\n        }\n        eval(k);\n\
    \        update_chmin(a,b,x,2*k+1,l,(l+r)/2);\n        update_chmin(a,b,x,2*k+2,(l+r)/2,r);\n\
    \        combine(k);\n    }\n    void update_chmax(int a,int b,lint x,int k=0,int\
    \ l=0,int r=-1){\n        if(r==-1)r=n;\n        if(b<=l||r<=a||x<=min[0][k])return;\n\
    \        if(a<=l&&r<=b&&x<min[1][k]){\n            update_node_min(k,x);\n   \
    \         return;\n        }\n        eval(k);\n        update_chmax(a,b,x,2*k+1,l,(l+r)/2);\n\
    \        update_chmax(a,b,x,2*k+2,(l+r)/2,r);\n        combine(k);\n    }\n  \
    \  void update_add(int a,int b,lint x,int k=0,int l=0,int r=-1){\n        if(r==-1)r=n;\n\
    \        if(b<=l||r<=a)return;\n        if(a<=l&&r<=b){\n            update_node_add(k,x);\n\
    \            return;\n        }\n        eval(k);\n        update_add(a,b,x,2*k+1,l,(l+r)/2);\n\
    \        update_add(a,b,x,2*k+2,(l+r)/2,r);\n        combine(k);\n    }\n    void\
    \ update(int a,int b,lint x){\n        update_chmin(a,b,x);\n        update_chmax(a,b,x);\n\
    \    }\n    lint query_sum(int a,int b,int k=0,int l=0,int r=-1){\n        if(r==-1)r=n;\n\
    \        if(b<=l||r<=a)return 0;\n        if(a<=l&&r<=b)return sum[k];\n     \
    \   eval(k);\n        lint vl=query_sum(a,b,2*k+1,l,(l+r)/2);\n        lint vr=query_sum(a,b,2*k+2,(l+r)/2,r);\n\
    \        return vl+vr;\n    }\n    lint query_min(int a,int b,int k=0,int l=0,int\
    \ r=-1){\n        if(r==-1)r=n;\n        if(b<=l||r<=a)return LINF;\n        if(a<=l&&r<=b)return\
    \ min[0][k];\n        eval(k);\n        lint vl=query_min(a,b,2*k+1,l,(l+r)/2);\n\
    \        lint vr=query_min(a,b,2*k+2,(l+r)/2,r);\n        return std::min(vl,vr);\n\
    \    }\n    lint query_max(int a,int b,int k=0,int l=0,int r=-1){\n        if(r==-1)r=n;\n\
    \        if(b<=l||r<=a)return -LINF;\n        if(a<=l&&r<=b)return max[0][k];\n\
    \        eval(k);\n        lint vl=query_max(a,b,2*k+1,l,(l+r)/2);\n        lint\
    \ vr=query_max(a,b,2*k+2,(l+r)/2,r);\n        return std::max(vl,vr);\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\nclass SegTreeBeats{\n \
    \   unsigned int n;\n    std::vector<lint> width,min[2],minc,max[2],maxc,sum,lazy;\n\
    \    void eval(int k){\n        if(n-1<=k)return;\n        if(lazy[k]){\n    \
    \        update_node_add(2*k+1,lazy[k]);\n            update_node_add(2*k+2,lazy[k]);\n\
    \            lazy[k]=0;\n        }\n        if(max[0][k]<max[0][2*k+1]){\n   \
    \         update_node_max(2*k+1,max[0][k]);\n        }\n        if(min[0][k]>min[0][2*k+1]){\n\
    \            update_node_min(2*k+1,min[0][k]);\n        }\n        if(max[0][k]<max[0][2*k+2]){\n\
    \            update_node_max(2*k+2,max[0][k]);\n        }\n        if(min[0][k]>min[0][2*k+2]){\n\
    \            update_node_min(2*k+2,min[0][k]);\n        }\n    }\n    void combine(int\
    \ k){\n        sum[k]=sum[2*k+1]+sum[2*k+2];\n        if(min[0][2*k+1]<min[0][2*k+2]){\n\
    \            min[0][k]=min[0][2*k+1];\n            minc[k]=minc[2*k+1];\n    \
    \        min[1][k]=std::min(min[1][2*k+1],min[0][2*k+2]);\n        }\n       \
    \ else if(min[0][2*k+1]>min[0][2*k+2]){\n            min[0][k]=min[0][2*k+2];\n\
    \            minc[k]=minc[2*k+2];\n            min[1][k]=std::min(min[0][2*k+1],min[1][2*k+2]);\n\
    \        }\n        else{\n            min[0][k]=min[0][2*k+1];\n            minc[k]=minc[2*k+1]+minc[2*k+2];\n\
    \            min[1][k]=std::min(min[1][2*k+1],min[1][2*k+2]);\n        }\n   \
    \     if(max[0][2*k+1]>max[0][2*k+2]){\n            max[0][k]=max[0][2*k+1];\n\
    \            maxc[k]=maxc[2*k+1];\n            max[1][k]=std::max(max[1][2*k+1],max[0][2*k+2]);\n\
    \        }\n        else if(max[0][2*k+1]<max[0][2*k+2]){\n            max[0][k]=max[0][2*k+2];\n\
    \            maxc[k]=maxc[2*k+2];\n            max[1][k]=std::max(max[0][2*k+1],max[1][2*k+2]);\n\
    \        }\n        else{\n            max[0][k]=max[0][2*k+1];\n            maxc[k]=maxc[2*k+1]+maxc[2*k+2];\n\
    \            max[1][k]=std::max(max[1][2*k+1],max[1][2*k+2]);\n        }\n   \
    \ }\n    void update_node_max(int k,lint x){\n        sum[k]+=(x-max[0][k])*maxc[k];\n\
    \        if(max[0][k]==min[0][k])min[0][k]=x;\n        else if(max[0][k]==min[1][k])min[1][k]=x;\n\
    \        max[0][k]=x;\n    }\n    void update_node_min(int k,lint x){\n      \
    \  sum[k]+=(x-min[0][k])*minc[k];\n        if(min[0][k]==max[0][k])max[0][k]=x;\n\
    \        else if(min[0][k]==max[1][k])max[1][k]=x;\n        min[0][k]=x;\n   \
    \ }\n    void update_node_add(int k,lint x){\n        min[0][k]+=x;\n        if(min[1][k]!=LINF)min[1][k]+=x;\n\
    \        max[0][k]+=x;\n        if(max[1][k]!=-LINF)max[1][k]+=x;\n        sum[k]+=x*width[k];\n\
    \        lazy[k]+=x;\n    }\npublic:\n    SegTreeBeats(unsigned int size,lint\
    \ def=0){\n        *this=SegTreeBeats(std::vector<lint>(size,def));\n    }\n \
    \   SegTreeBeats(std::vector<lint> initvec){\n        n=1;\n        while(n<initvec.size())n*=2;\n\
    \        width.resize(2*n-1);\n        min[0].resize(2*n-1);min[1].resize(2*n-1,LINF);\n\
    \        minc.resize(2*n-1);\n        max[0].resize(2*n-1);max[1].resize(2*n-1,-LINF);\n\
    \        maxc.resize(2*n-1);\n        sum.resize(2*n-1);\n        lazy.resize(2*n-1);\n\
    \        for(int i=n-1;i<n-1+initvec.size();i++){\n            min[0][i]=max[0][i]=sum[i]=initvec[i-n+1];\n\
    \            minc[i]=maxc[i]=1;\n        }\n        for(int i=n-2;i>=0;i--){\n\
    \            combine(i);\n        }\n        width[0]=n;\n        REP(i,2*n-2)width[i]=width[(i-1)/2]/2;\n\
    \    }\n    void update_chmin(int a,int b,lint x,int k=0,int l=0,int r=-1){\n\
    \        if(r==-1)r=n;\n        if(b<=l||r<=a||max[0][k]<=x)return;\n        if(a<=l&&r<=b&&max[1][k]<x){\n\
    \            update_node_max(k,x);\n            return;\n        }\n        eval(k);\n\
    \        update_chmin(a,b,x,2*k+1,l,(l+r)/2);\n        update_chmin(a,b,x,2*k+2,(l+r)/2,r);\n\
    \        combine(k);\n    }\n    void update_chmax(int a,int b,lint x,int k=0,int\
    \ l=0,int r=-1){\n        if(r==-1)r=n;\n        if(b<=l||r<=a||x<=min[0][k])return;\n\
    \        if(a<=l&&r<=b&&x<min[1][k]){\n            update_node_min(k,x);\n   \
    \         return;\n        }\n        eval(k);\n        update_chmax(a,b,x,2*k+1,l,(l+r)/2);\n\
    \        update_chmax(a,b,x,2*k+2,(l+r)/2,r);\n        combine(k);\n    }\n  \
    \  void update_add(int a,int b,lint x,int k=0,int l=0,int r=-1){\n        if(r==-1)r=n;\n\
    \        if(b<=l||r<=a)return;\n        if(a<=l&&r<=b){\n            update_node_add(k,x);\n\
    \            return;\n        }\n        eval(k);\n        update_add(a,b,x,2*k+1,l,(l+r)/2);\n\
    \        update_add(a,b,x,2*k+2,(l+r)/2,r);\n        combine(k);\n    }\n    void\
    \ update(int a,int b,lint x){\n        update_chmin(a,b,x);\n        update_chmax(a,b,x);\n\
    \    }\n    lint query_sum(int a,int b,int k=0,int l=0,int r=-1){\n        if(r==-1)r=n;\n\
    \        if(b<=l||r<=a)return 0;\n        if(a<=l&&r<=b)return sum[k];\n     \
    \   eval(k);\n        lint vl=query_sum(a,b,2*k+1,l,(l+r)/2);\n        lint vr=query_sum(a,b,2*k+2,(l+r)/2,r);\n\
    \        return vl+vr;\n    }\n    lint query_min(int a,int b,int k=0,int l=0,int\
    \ r=-1){\n        if(r==-1)r=n;\n        if(b<=l||r<=a)return LINF;\n        if(a<=l&&r<=b)return\
    \ min[0][k];\n        eval(k);\n        lint vl=query_min(a,b,2*k+1,l,(l+r)/2);\n\
    \        lint vr=query_min(a,b,2*k+2,(l+r)/2,r);\n        return std::min(vl,vr);\n\
    \    }\n    lint query_max(int a,int b,int k=0,int l=0,int r=-1){\n        if(r==-1)r=n;\n\
    \        if(b<=l||r<=a)return -LINF;\n        if(a<=l&&r<=b)return max[0][k];\n\
    \        eval(k);\n        lint vl=query_max(a,b,2*k+1,l,(l+r)/2);\n        lint\
    \ vr=query_max(a,b,2*k+2,(l+r)/2,r);\n        return std::max(vl,vr);\n    }\n\
    };"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/SegTreeBeats.hpp
  requiredBy: []
  timestamp: '2020-09-12 16:29:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: data-structure/SegTreeBeats.hpp
layout: document
redirect_from:
- /library/data-structure/SegTreeBeats.hpp
- /library/data-structure/SegTreeBeats.hpp.html
title: data-structure/SegTreeBeats.hpp
---
