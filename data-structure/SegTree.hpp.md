---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/IntervalSegTree.hpp
    title: data-structure/IntervalSegTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ 3 \"data-structure/SegTree.hpp\"\ntemplate<class T, T (*nodef)(const T&, const\
    \ T&)>\nclass SegTree {\nprotected:\n\tunsigned int n = 1, rank = 0;\n\tstd::vector<T>\
    \ node;\n\tT ident;\npublic:\n\tSegTree(unsigned int m, T init, T e_):ident(e_)\
    \ {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2\
    \ * n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n; i++)node[i] = init;\n\t\
    \tfor (unsigned int i = n - 1; i > 0; i--)node[i] = nodef(node[i << 1], node[i\
    \ << 1 | 1]);\n\t}\n\tSegTree(const std::vector<T>& initvec, T e_):ident(e_) {\n\
    \t\tunsigned int m = initvec.size();\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\
    \trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i = n;\
    \ i < 2 * n; i++) {\n\t\t\tif (i - n < m)node[i] = initvec[i - n];\n\t\t}\n\t\t\
    for (unsigned int i = n - 1; i > 0; i--)node[i] = nodef(node[i << 1], node[i <<\
    \ 1 | 1]);\n\t}\n\tvirtual void update(int i, T x) {\n\t\ti += n;\n\t\tnode[i]\
    \ = x;\n\t\twhile (i != 1) {\n\t\t\ti >>= 1;\n\t\t\tnode[i] = nodef(node[2 * i],\
    \ node[2 * i + 1]);\n\t\t}\n\t}\n\tvirtual T query(int l, int r) {\n\t\tl += n;\
    \ r += n;\n\t\tT ls = ident, rs = ident;\n\t\twhile (l < r) {\n\t\t\tif (l & 1)\
    \ ls = nodef(ls, node[l++]);\n\t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\t\t\
    \tl >>= 1; r >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\tvirtual T operator[](const\
    \ int& x) {\n\t\treturn node[n + x];\n\t}\n\tvoid print() {\n\t\trep(i, n)std::cout\
    \ << operator[](i) << \" \";\n\t\tstd::cout << std::endl;\n\t}\n};\nstatic lint\
    \ RSQ_nodef(const lint& lhs, const lint& rhs){return lhs + rhs;}\nclass RSQ :public\
    \ SegTree<lint, RSQ_nodef> {\n\tusing Base = SegTree<lint, RSQ_nodef>;\npublic:\n\
    \ttemplate<class... Args>\n\tRSQ(Args... args):Base(args..., 0){}\n};\nstatic\
    \ lint RMiQ_nodef(const lint& lhs, const lint& rhs){return std::min(lhs, rhs);}\n\
    class RMiQ :public SegTree<lint, RMiQ_nodef> {\n\tusing Base = SegTree<lint, RMiQ_nodef>;\n\
    public:\n\ttemplate<class... Args>\n\tRMiQ(Args... args):Base(args..., LINF){}\n\
    };\nstatic lint RMaQ_nodef(const lint& lhs, const lint& rhs){return std::max(lhs,rhs);}\n\
    class RMaQ :public SegTree<lint, RMaQ_nodef> {\n\tusing Base = SegTree<lint, RMaQ_nodef>;\n\
    public:\n\ttemplate<class... Args>\n\tRMaQ(Args... args):Base(args..., -LINF){}\n\
    };\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate<class T, T (*nodef)(const\
    \ T&, const T&)>\nclass SegTree {\nprotected:\n\tunsigned int n = 1, rank = 0;\n\
    \tstd::vector<T> node;\n\tT ident;\npublic:\n\tSegTree(unsigned int m, T init,\
    \ T e_):ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\
    \t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n; i++)node[i]\
    \ = init;\n\t\tfor (unsigned int i = n - 1; i > 0; i--)node[i] = nodef(node[i\
    \ << 1], node[i << 1 | 1]);\n\t}\n\tSegTree(const std::vector<T>& initvec, T e_):ident(e_)\
    \ {\n\t\tunsigned int m = initvec.size();\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\
    \t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i\
    \ = n; i < 2 * n; i++) {\n\t\t\tif (i - n < m)node[i] = initvec[i - n];\n\t\t\
    }\n\t\tfor (unsigned int i = n - 1; i > 0; i--)node[i] = nodef(node[i << 1], node[i\
    \ << 1 | 1]);\n\t}\n\tvirtual void update(int i, T x) {\n\t\ti += n;\n\t\tnode[i]\
    \ = x;\n\t\twhile (i != 1) {\n\t\t\ti >>= 1;\n\t\t\tnode[i] = nodef(node[2 * i],\
    \ node[2 * i + 1]);\n\t\t}\n\t}\n\tvirtual T query(int l, int r) {\n\t\tl += n;\
    \ r += n;\n\t\tT ls = ident, rs = ident;\n\t\twhile (l < r) {\n\t\t\tif (l & 1)\
    \ ls = nodef(ls, node[l++]);\n\t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\t\t\
    \tl >>= 1; r >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\tvirtual T operator[](const\
    \ int& x) {\n\t\treturn node[n + x];\n\t}\n\tvoid print() {\n\t\trep(i, n)std::cout\
    \ << operator[](i) << \" \";\n\t\tstd::cout << std::endl;\n\t}\n};\nstatic lint\
    \ RSQ_nodef(const lint& lhs, const lint& rhs){return lhs + rhs;}\nclass RSQ :public\
    \ SegTree<lint, RSQ_nodef> {\n\tusing Base = SegTree<lint, RSQ_nodef>;\npublic:\n\
    \ttemplate<class... Args>\n\tRSQ(Args... args):Base(args..., 0){}\n};\nstatic\
    \ lint RMiQ_nodef(const lint& lhs, const lint& rhs){return std::min(lhs, rhs);}\n\
    class RMiQ :public SegTree<lint, RMiQ_nodef> {\n\tusing Base = SegTree<lint, RMiQ_nodef>;\n\
    public:\n\ttemplate<class... Args>\n\tRMiQ(Args... args):Base(args..., LINF){}\n\
    };\nstatic lint RMaQ_nodef(const lint& lhs, const lint& rhs){return std::max(lhs,rhs);}\n\
    class RMaQ :public SegTree<lint, RMaQ_nodef> {\n\tusing Base = SegTree<lint, RMaQ_nodef>;\n\
    public:\n\ttemplate<class... Args>\n\tRMaQ(Args... args):Base(args..., -LINF){}\n\
    };"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/SegTree.hpp
  requiredBy:
  - data-structure/IntervalSegTree.hpp
  timestamp: '2020-11-21 16:06:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_E.test.cpp
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: data-structure/SegTree.hpp
layout: document
redirect_from:
- /library/data-structure/SegTree.hpp
- /library/data-structure/SegTree.hpp.html
title: data-structure/SegTree.hpp
---
