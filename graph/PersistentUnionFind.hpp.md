---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/UnionFind.hpp
    title: Disjoint set
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Partially persistent disjoint set
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifdef ONLINE_JUDGE\n#pragma GCC target(\"avx512f\")\n#elif defined EVAL\n#else\n\
    #pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n#include <string.h>\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#define rep(i, n) for (int i = 0; i < int(n); i++)\n#define\
    \ REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(), V.end()\n\
    \nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
    using lint = long long;\nusing ulint = unsigned long long;\nusing IP = std::pair<int,\
    \ int>;\nusing LP = std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\n\
    constexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr\
    \ double PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique\
    \ : public std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\ntemplate\
    \ <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f\
    \ = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class\
    \ U>\nconstexpr inline bool chmax(T& lhs, const U& rhs) {\n\tif (lhs < rhs) {\n\
    \t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class T,\
    \ class U>\nconstexpr inline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\nconstexpr inline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\t\
    b = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) { return a /\
    \ gcd(a, b) * b; }\nconstexpr bool isprime(lint n) {\n\tif (n == 1) return false;\n\
    \tfor (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\
    \treturn true;\n}\ntemplate <class T>\nconstexpr T mypow(T a, lint b) {\n\tT res(1);\n\
    \twhile (true) {\n\t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\
    \t\ta *= a;\n\t}\n\treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint\
    \ m) {\n\ta %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres\
    \ *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t}\n\
    \treturn res;\n}\ntemplate <class T>\nconstexpr void printArray(const std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <class InputIter>\nconstexpr void printArray(InputIter l, InputIter r, char\
    \ split = ' ') {\n\tauto rprev = std::prev(r);\n\tfor (auto i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? '\\n' : split);\n\t\
    }\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b,\
    \ a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\t\
    return s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const\
    \ lint& m2) {\n\tauto p = extGcd(m1, m2);\n\tlint g = gcd(m1, m2), l = m1 / g\
    \ * m2;\n\tlint tmp = (b2 - b1) / g * p.first % (m2 / g);\n\tlint r = (b1 + m1\
    \ * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const std::string& a, const std::string&\
    \ b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\trep(i, a.size())\
    \ {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j\
    \ + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\t}\n\trep(j,\
    \ b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn dp[a.size()][b.size()];\n\
    }\ntemplate <class T, std::enable_if_t<std::is_convertible<int, T>::value,\n\t\
    \t\t\t\t\t\t\t\tstd::nullptr_t> = nullptr>\nvoid compress(std::vector<T>& vec)\
    \ {\n\tauto tmp = vec;\n\tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)),\
    \ tmp.end());\n\tfor (T& i : vec) i = std::lower_bound(all(tmp), i) - tmp.begin();\n\
    }\ntemplate <class T>\nvoid compress(T* l, T* r) {\n\tstd::vector<T> tmp(l, r);\n\
    \tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor\
    \ (auto i = l; i < r; i++) {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\
    \t}\n}\ntemplate <class InputIter>\nvoid compress(InputIter l, InputIter r) {\n\
    \tstd::vector<typename InputIter::value_type> tmp(l, r);\n\tstd::sort(all(tmp));\n\
    \ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor (auto i = l; i < r; i++)\
    \ {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\t}\n}\n#line 3 \"\
    graph/UnionFind.hpp\"\nclass UnionFind {\n  protected:\n\tstd::vector<int> par,\
    \ size;\n\n  public:\n\tUnionFind() {}\n\tUnionFind(int size) { init(size); }\n\
    \tvoid init(int size) {\n\t\tpar.resize(size);\n\t\tthis->size.resize(size, 1);\n\
    \t\tstd::iota(all(par), 0);\n\t}\n\tint find(int n) {\n\t\tif (par[n] == n) return\
    \ n;\n\t\treturn par[n] = find(par[n]);\n\t}\n\tvoid unite(int n, int m) {\n\t\
    \tn = find(n);\n\t\tm = find(m);\n\t\tif (n == m) return;\n\t\tint a = n, b =\
    \ m;\n\t\tif (size[a] > size[b]) std::swap(a, b);\n\t\tpar[a] = b;\n\t\tsize[b]\
    \ += size[a];\n\t}\n\tbool same(int n, int m) { return find(n) == find(m); }\n\
    \tint getsize(int n) { return size[find(n)]; }\n\tbool is_root(int n) { return\
    \ find(n) == n; }\n};\n\n/**\n * @title Disjoint set\n */\n#line 4 \"graph/PersistentUnionFind.hpp\"\
    \nclass PersistentUnionFind : UnionFind {\n\tstd::vector<P> notparent;\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> sizevec;\n\tint opcount = 0;\n\n  public:\n\tPersistentUnionFind(unsigned\
    \ int size) : UnionFind(size) {\n\t\tnotparent.resize(size);\n\t\tsizevec.resize(size);\n\
    \t\trep(i, size) {\n\t\t\tpar[i] = i;\n\t\t\tsizevec[i].push_back(std::make_pair(-1,\
    \ 1));\n\t\t\tnotparent[i] = std::make_pair(INF, i);\n\t\t}\n\t}\n\tint find(int\
    \ n, int t = INF) {\n\t\tif (opcount <= t) {\n\t\t\tif (par[n] == n) return n;\n\
    \t\t\treturn par[n] = find(par[n]);\n\t\t}\n\t\tif (notparent[n].first <= t) return\
    \ find(notparent[n].second, t);\n\t\treturn n;\n\t}\n\tvoid unite(int n, int m)\
    \ {\n\t\tn = find(n);\n\t\tm = find(m);\n\t\tif (n == m) {\n\t\t\topcount++;\n\
    \t\t\treturn;\n\t\t}\n\t\tif (size[n] > size[m]) std::swap(n, m);\n\t\tpar[n]\
    \ = m;\n\t\tnotparent[n] = std::make_pair(opcount, m);\n\t\tsizevec[m].emplace_back(\n\
    \t\t\topcount, sizevec[m].back().second + sizevec[n].back().second);\n\t\topcount++;\n\
    \t}\n\tbool same(int n, int m, int t = INF) { return find(n, t) == find(m, t);\
    \ }\n\tint getsize(int n, int t = INF) {\n\t\tn = find(n, t);\n\t\tauto ite =\
    \ std::lower_bound(all(sizevec[n]), std::make_pair(t, 0));\n\t\tif (ite == sizevec[n].end())\
    \ ite--;\n\t\tif (t < (*ite).first) ite--;\n\t\treturn (*ite).second;\n\t}\n};\n\
    \n/**\n * @title Partially persistent disjoint set\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n#include \"UnionFind.hpp\"\
    \nclass PersistentUnionFind : UnionFind {\n\tstd::vector<P> notparent;\n\tstd::vector<std::vector<std::pair<int,\
    \ int>>> sizevec;\n\tint opcount = 0;\n\n  public:\n\tPersistentUnionFind(unsigned\
    \ int size) : UnionFind(size) {\n\t\tnotparent.resize(size);\n\t\tsizevec.resize(size);\n\
    \t\trep(i, size) {\n\t\t\tpar[i] = i;\n\t\t\tsizevec[i].push_back(std::make_pair(-1,\
    \ 1));\n\t\t\tnotparent[i] = std::make_pair(INF, i);\n\t\t}\n\t}\n\tint find(int\
    \ n, int t = INF) {\n\t\tif (opcount <= t) {\n\t\t\tif (par[n] == n) return n;\n\
    \t\t\treturn par[n] = find(par[n]);\n\t\t}\n\t\tif (notparent[n].first <= t) return\
    \ find(notparent[n].second, t);\n\t\treturn n;\n\t}\n\tvoid unite(int n, int m)\
    \ {\n\t\tn = find(n);\n\t\tm = find(m);\n\t\tif (n == m) {\n\t\t\topcount++;\n\
    \t\t\treturn;\n\t\t}\n\t\tif (size[n] > size[m]) std::swap(n, m);\n\t\tpar[n]\
    \ = m;\n\t\tnotparent[n] = std::make_pair(opcount, m);\n\t\tsizevec[m].emplace_back(\n\
    \t\t\topcount, sizevec[m].back().second + sizevec[n].back().second);\n\t\topcount++;\n\
    \t}\n\tbool same(int n, int m, int t = INF) { return find(n, t) == find(m, t);\
    \ }\n\tint getsize(int n, int t = INF) {\n\t\tn = find(n, t);\n\t\tauto ite =\
    \ std::lower_bound(all(sizevec[n]), std::make_pair(t, 0));\n\t\tif (ite == sizevec[n].end())\
    \ ite--;\n\t\tif (t < (*ite).first) ite--;\n\t\treturn (*ite).second;\n\t}\n};\n\
    \n/**\n * @title Partially persistent disjoint set\n */"
  dependsOn:
  - other/template.hpp
  - graph/UnionFind.hpp
  isVerificationFile: false
  path: graph/PersistentUnionFind.hpp
  requiredBy: []
  timestamp: '2021-02-28 19:01:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/PersistentUnionFind.hpp
layout: document
redirect_from:
- /library/graph/PersistentUnionFind.hpp
- /library/graph/PersistentUnionFind.hpp.html
title: Partially persistent disjoint set
---
