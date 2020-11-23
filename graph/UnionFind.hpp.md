---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/PersistentUnionFind.hpp
    title: graph/PersistentUnionFind.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\ntemplate\
    \ <class T>\nclass prique :public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {};\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\
    \tif (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    template <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs\
    \ > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b; b = c\
    \ % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) {\n\treturn a / gcd(a,\
    \ b) * b;\n}\nbool isprime(lint n) {\n\tif (n == 1)return false;\n\tfor (int i\
    \ = 2; i * i <= n; i++) {\n\t\tif (n % i == 0)return false;\n\t}\n\treturn true;\n\
    }\ntemplate<typename T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile(b){\n\t\t\
    if(b & 1)res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\nlint modpow(lint\
    \ a, lint b, lint m) {\n\tlint res(1);\n\twhile(b){\n\t\tif(b & 1){\n\t\t\tres\
    \ *= a;res %= m;\n\t\t}\n\t\ta *= a;a %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n\
    }\ntemplate<typename T>\nvoid printArray(std::vector<T> &vec) {\n\trep(i, vec.size()){\n\
    \t\tstd::cout << vec[i];\n\t\tstd::cout << (i == (int)vec.size() - 1 ? \"\\n\"\
    \ : \" \");\n\t}\n}\ntemplate<typename T>\nvoid printArray(T l, T r) {\n\tT rprev\
    \ = std::prev(r);\n\tfor (T i = l; i != rprev; i++) {\n\t\tstd::cout << *i;\n\t\
    \tstd::cout << (i == std::prev(rprev) ? \"\\n\" : \" \");\n\t}\n}\nLP extGcd(lint\
    \ a, lint b) {\n\tif(b == 0)return {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first,\
    \ s.second);\n\ts.second -= a / b * s.first;\n\treturn s;\n}\nLP ChineseRem(const\
    \ lint& b1, const lint& m1, const lint& b2, const lint& m2) {\n\tlint p = extGcd(m1,m2).first;\n\
    \tlint tmp = (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 *\
    \ m2);\n\treturn std::make_pair(r, m1*m2);\n}\ntemplate<typename F>\ninline constexpr\
    \ decltype(auto) lambda_fix(F&& f){\n\treturn [f = std::forward<F>(f)](auto&&...\
    \ args){\n\t\treturn f(f,std::forward<decltype(args)>(args)...);\n\t};\n}\ntemplate<typename\
    \ T>\nstd::vector<T> make_vec(size_t n){\n\treturn std::vector<T>(n);\n}\ntemplate<typename\
    \ T, class... Args>\nauto make_vec(size_t n, Args&&... args){\n\treturn std::vector<decltype(make_vec<T>(args...))>(n,\
    \ make_vec<T>(std::forward<Args>(args)...));\n}\n#line 3 \"graph/UnionFind.hpp\"\
    \nclass UnionFind {\nprotected:\n\tstd::vector<int> par, size;\npublic:\n\tUnionFind(){}\n\
    \tUnionFind(int size) {init(size);}\n\tvoid init(int size){\n\t\tpar.resize(size);\
    \ this->size.resize(size, 1);\n\t\trep(i, size) {\n\t\t\tpar[i] = i;\n\t\t}\n\t\
    }\n\tint find(int n) {\n\t\tif (par[n] == n)return n;\n\t\treturn par[n] = find(par[n]);\n\
    \t}\n\tvoid unite(int n, int m) {\n\t\tn = find(n);\n\t\tm = find(m);\n\t\tif\
    \ (n == m)return;\n\t\tint a=n,b=m;\n\t\tif(size[a]>size[b])std::swap(a,b);\n\t\
    \tpar[a] = b;\n\t\tsize[b] += size[a];\n\t}\n\tbool same(int n, int m) {\n\t\t\
    return find(n) == find(m);\n\t}\n\tint getsize(int n) {\n\t\treturn size[find(n)];\n\
    \t}\n};\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\nclass UnionFind {\nprotected:\n\
    \tstd::vector<int> par, size;\npublic:\n\tUnionFind(){}\n\tUnionFind(int size)\
    \ {init(size);}\n\tvoid init(int size){\n\t\tpar.resize(size); this->size.resize(size,\
    \ 1);\n\t\trep(i, size) {\n\t\t\tpar[i] = i;\n\t\t}\n\t}\n\tint find(int n) {\n\
    \t\tif (par[n] == n)return n;\n\t\treturn par[n] = find(par[n]);\n\t}\n\tvoid\
    \ unite(int n, int m) {\n\t\tn = find(n);\n\t\tm = find(m);\n\t\tif (n == m)return;\n\
    \t\tint a=n,b=m;\n\t\tif(size[a]>size[b])std::swap(a,b);\n\t\tpar[a] = b;\n\t\t\
    size[b] += size[a];\n\t}\n\tbool same(int n, int m) {\n\t\treturn find(n) == find(m);\n\
    \t}\n\tint getsize(int n) {\n\t\treturn size[find(n)];\n\t}\n};"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: graph/UnionFind.hpp
  requiredBy:
  - graph/PersistentUnionFind.hpp
  timestamp: '2020-11-24 01:15:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/unionfind.test.cpp
documentation_of: graph/UnionFind.hpp
layout: document
redirect_from:
- /library/graph/UnionFind.hpp
- /library/graph/UnionFind.hpp.html
title: graph/UnionFind.hpp
---
