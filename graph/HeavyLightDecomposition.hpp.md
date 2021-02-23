---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Heavy light decomposition
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
    #include <vector>\n\n#define rep(i, n) for (int i = 0; i < (n); i++)\n#define\
    \ REP(i, n) for (int i = 1; i <= (n); i++)\n#define all(V) V.begin(), V.end()\n\
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
    \ lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp = (b2 - b1) * p %\
    \ m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn {r, m1 * m2};\n\
    }\nint LCS(const std::string& a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size()\
    \ + 1, b.size() + 1);\n\trep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i\
    \ + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] ==\
    \ b[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()],\
    \ dp[i][b.size()]);\n\t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\
    \treturn dp[a.size()][b.size()];\n}\ntemplate <class T, std::enable_if_t<std::is_convertible<int,\
    \ T>::value,\n\t\t\t\t\t\t\t\t\tstd::nullptr_t> = nullptr>\nvoid compress(std::vector<T>&\
    \ vec) {\n\tauto tmp = vec;\n\tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)),\
    \ tmp.end());\n\tfor (T& i : vec) i = std::lower_bound(all(tmp), i) - tmp.begin();\n\
    }\ntemplate <class T>\nvoid compress(T* l, T* r) {\n\tstd::vector<T> tmp(l, r);\n\
    \tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor\
    \ (auto i = l; i < r; i++) {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\
    \t}\n}\ntemplate <class InputIter>\nvoid compress(InputIter l, InputIter r) {\n\
    \tstd::vector<typename InputIter::value_type> tmp(l, r);\n\tstd::sort(all(tmp));\n\
    \ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor (auto i = l; i < r; i++)\
    \ {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\t}\n}\n#line 3 \"\
    graph/HeavyLightDecomposition.hpp\"\nclass HeavyLightDecomposition {\n\tint n,\
    \ index = 0;\n\tvoid size_dfs(int node) {\n\t\tsize[node] = 1;\n\t\tfor (int&\
    \ i : vec[node]) {\n\t\t\tif (par[node] == i) continue;\n\t\t\tpar[i] = node;\n\
    \t\t\tsize_dfs(i);\n\t\t\tsize[node] += size[i];\n\t\t\tif (size[i] > size[vec[node][0]])\
    \ std::swap(i, vec[node][0]);\n\t\t}\n\t}\n\tvoid build_dfs(int node) {\n\t\t\
    label[node] = index++;\n\t\tfor (int& i : vec[node]) {\n\t\t\tif (par[node] !=\
    \ i) {\n\t\t\t\thead[i] = (i == vec[node][0] ? head[node] : i);\n\t\t\t\tbuild_dfs(i);\n\
    \t\t\t}\n\t\t}\n\t\tlast[node] = index;\n\t}\n\n  public:\n\tstd::vector<std::vector<int>>\
    \ vec;\n\tstd::vector<int> size, par, head, label, last;\n\tHeavyLightDecomposition()\
    \ {}\n\tHeavyLightDecomposition(int m) : n(m) { init(n); }\n\tvoid init(int m)\
    \ {\n\t\tn = m;\n\t\tvec.resize(n);\n\t\tsize.resize(n);\n\t\tpar.resize(n);\n\
    \t\thead.resize(n);\n\t\tlabel.resize(n);\n\t\tlast.resize(n);\n\t}\n\tvoid add_edge(int\
    \ u, int v) {\n\t\tvec[u].emplace_back(v);\n\t\tvec[v].emplace_back(u);\n\t}\n\
    \tvoid build(int root) {\n\t\tstd::fill(all(par), -1);\n\t\tsize_dfs(root);\n\t\
    \tbuild_dfs(root);\n\t}\n\ttemplate <class F>\n\tvoid each_edge(int u, int v,\
    \ const F& func) const {\n\t\twhile (true) {\n\t\t\tif (label[u] > label[v]) std::swap(u,\
    \ v);\n\t\t\tif (head[u] == head[v]) {\n\t\t\t\tif (label[u] != label[v]) func(label[u]\
    \ + 1, label[v]);\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tfunc(label[head[v]], label[v]);\n\
    \t\t\tv = par[head[v]];\n\t\t}\n\t}\n\ttemplate <class F>\n\tvoid each_vertex(int\
    \ u, int v, const F& func) const {\n\t\twhile (true) {\n\t\t\tif (label[u] > label[v])\
    \ std::swap(u, v);\n\t\t\tif (head[u] == head[v]) {\n\t\t\t\tfunc(label[u], label[v]);\n\
    \t\t\t\treturn;\n\t\t\t}\n\t\t\tfunc(label[head[v]], label[v]);\n\t\t\tv = par[head[v]];\n\
    \t\t}\n\t}\n\ttemplate <class F>\n\tvoid each_vertex_subtree(int u, const F& func)\
    \ const {\n\t\tfunc(label[u], last[u]);\n\t}\n\tint lca(int u, int v) const {\n\
    \t\twhile (true) {\n\t\t\tif (label[u] > label[v]) std::swap(u, v);\n\t\t\tif\
    \ (head[u] == head[v]) return u;\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\tvoid\
    \ clear() {\n\t\tvec.clear();\n\t\tsize.clear();\n\t\tpar.clear();\n\t\thead.clear();\n\
    \t\tlabel.clear();\n\t\tlast.clear();\n\t}\n};\n\n/**\n * @title Heavy light decomposition\n\
    \ */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\nclass HeavyLightDecomposition\
    \ {\n\tint n, index = 0;\n\tvoid size_dfs(int node) {\n\t\tsize[node] = 1;\n\t\
    \tfor (int& i : vec[node]) {\n\t\t\tif (par[node] == i) continue;\n\t\t\tpar[i]\
    \ = node;\n\t\t\tsize_dfs(i);\n\t\t\tsize[node] += size[i];\n\t\t\tif (size[i]\
    \ > size[vec[node][0]]) std::swap(i, vec[node][0]);\n\t\t}\n\t}\n\tvoid build_dfs(int\
    \ node) {\n\t\tlabel[node] = index++;\n\t\tfor (int& i : vec[node]) {\n\t\t\t\
    if (par[node] != i) {\n\t\t\t\thead[i] = (i == vec[node][0] ? head[node] : i);\n\
    \t\t\t\tbuild_dfs(i);\n\t\t\t}\n\t\t}\n\t\tlast[node] = index;\n\t}\n\n  public:\n\
    \tstd::vector<std::vector<int>> vec;\n\tstd::vector<int> size, par, head, label,\
    \ last;\n\tHeavyLightDecomposition() {}\n\tHeavyLightDecomposition(int m) : n(m)\
    \ { init(n); }\n\tvoid init(int m) {\n\t\tn = m;\n\t\tvec.resize(n);\n\t\tsize.resize(n);\n\
    \t\tpar.resize(n);\n\t\thead.resize(n);\n\t\tlabel.resize(n);\n\t\tlast.resize(n);\n\
    \t}\n\tvoid add_edge(int u, int v) {\n\t\tvec[u].emplace_back(v);\n\t\tvec[v].emplace_back(u);\n\
    \t}\n\tvoid build(int root) {\n\t\tstd::fill(all(par), -1);\n\t\tsize_dfs(root);\n\
    \t\tbuild_dfs(root);\n\t}\n\ttemplate <class F>\n\tvoid each_edge(int u, int v,\
    \ const F& func) const {\n\t\twhile (true) {\n\t\t\tif (label[u] > label[v]) std::swap(u,\
    \ v);\n\t\t\tif (head[u] == head[v]) {\n\t\t\t\tif (label[u] != label[v]) func(label[u]\
    \ + 1, label[v]);\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tfunc(label[head[v]], label[v]);\n\
    \t\t\tv = par[head[v]];\n\t\t}\n\t}\n\ttemplate <class F>\n\tvoid each_vertex(int\
    \ u, int v, const F& func) const {\n\t\twhile (true) {\n\t\t\tif (label[u] > label[v])\
    \ std::swap(u, v);\n\t\t\tif (head[u] == head[v]) {\n\t\t\t\tfunc(label[u], label[v]);\n\
    \t\t\t\treturn;\n\t\t\t}\n\t\t\tfunc(label[head[v]], label[v]);\n\t\t\tv = par[head[v]];\n\
    \t\t}\n\t}\n\ttemplate <class F>\n\tvoid each_vertex_subtree(int u, const F& func)\
    \ const {\n\t\tfunc(label[u], last[u]);\n\t}\n\tint lca(int u, int v) const {\n\
    \t\twhile (true) {\n\t\t\tif (label[u] > label[v]) std::swap(u, v);\n\t\t\tif\
    \ (head[u] == head[v]) return u;\n\t\t\tv = par[head[v]];\n\t\t}\n\t}\n\tvoid\
    \ clear() {\n\t\tvec.clear();\n\t\tsize.clear();\n\t\tpar.clear();\n\t\thead.clear();\n\
    \t\tlabel.clear();\n\t\tlast.clear();\n\t}\n};\n\n/**\n * @title Heavy light decomposition\n\
    \ */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: graph/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2021-02-24 00:36:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
  - test/yosupo/lca.test.cpp
documentation_of: graph/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/graph/HeavyLightDecomposition.hpp
- /library/graph/HeavyLightDecomposition.hpp.html
title: Heavy light decomposition
---
