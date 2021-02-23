---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A_Dinic.test.cpp
    title: test/aoj/GRL_6_A_Dinic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Dinic's algorithm
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
    graph/Dinic.hpp\"\nclass Dinic {\n\tclass edge {\n\t  public:\n\t\tint to;\n\t\
    \tlint cap;\n\t\tint rev, id;\n\t};\n\tint N, idx = 0;\n\tstd::vector<std::vector<edge>>\
    \ vec;\n\tstd::vector<int> iter, level;\n\tbool bfs(int s, int t) {\n\t\tlevel.assign(N,\
    \ -1);\n\t\tlevel[s] = 0;\n\t\tstd::queue<int> que;\n\t\tque.push(s);\n\t\twhile\
    \ (!que.empty()) {\n\t\t\tint node = que.front();\n\t\t\tque.pop();\n\t\t\tfor\
    \ (const auto& i : vec[node]) {\n\t\t\t\tif (i.cap > 0 && level[i.to] == -1) {\n\
    \t\t\t\t\tlevel[i.to] = level[node] + 1;\n\t\t\t\t\tque.push(i.to);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\treturn level[t] != -1;\n\t}\n\tlint dfs(int node, int t,\
    \ lint f) {\n\t\tif (node == t) return f;\n\t\tfor (int& i = iter[node]; i < vec[node].size();\
    \ i++) {\n\t\t\tedge& e = vec[node][i];\n\t\t\tif (e.cap > 0 && level[node] <\
    \ level[e.to]) {\n\t\t\t\tlint d = dfs(e.to, t, std::min(f, e.cap));\n\t\t\t\t\
    if (d > 0) {\n\t\t\t\t\te.cap -= d;\n\t\t\t\t\tvec[e.to][e.rev].cap += d;\n\t\t\
    \t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n  public:\n\t\
    Dinic(int n) : N(n) {\n\t\tvec.resize(N);\n\t\tlevel.resize(N);\n\t\titer.resize(N);\n\
    \t}\n\tvoid reset() {\n\t\trep(i, N) {\n\t\t\tfor (auto& j : vec[i]) {\n\t\t\t\
    \tif (j.id != -1) {\n\t\t\t\t\tvec[j.to][j.rev].cap += j.cap;\n\t\t\t\t\tj.cap\
    \ = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tvoid add_edge(int from, int to, lint\
    \ cap) {\n\t\tvec[from].push_back({to, cap, (int)vec[to].size(), -1});\n\t\tvec[to].push_back({from,\
    \ 0, (int)vec[from].size() - 1, idx++});\n\t}\n\tlint max_flow(int s, int t) {\n\
    \t\tlint res = 0;\n\t\twhile (true) {\n\t\t\tbfs(s, t);\n\t\t\tif (level[t] <\
    \ 0) return res;\n\t\t\titer.assign(N, 0);\n\t\t\tlint f;\n\t\t\twhile ((f = dfs(s,\
    \ t, LINF)) > 0) res += f;\n\t\t}\n\t}\n\tstd::vector<lint> restore() const {\n\
    \t\tstd::vector<lint> res(idx);\n\t\trep(i, N) {\n\t\t\tfor (const auto& j : vec[i])\
    \ {\n\t\t\t\tif (j.id != -1) res[j.id] = j.cap;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\
    \t}\n};\n\n/**\n * @title Dinic's algorithm\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\nclass Dinic {\n\tclass\
    \ edge {\n\t  public:\n\t\tint to;\n\t\tlint cap;\n\t\tint rev, id;\n\t};\n\t\
    int N, idx = 0;\n\tstd::vector<std::vector<edge>> vec;\n\tstd::vector<int> iter,\
    \ level;\n\tbool bfs(int s, int t) {\n\t\tlevel.assign(N, -1);\n\t\tlevel[s] =\
    \ 0;\n\t\tstd::queue<int> que;\n\t\tque.push(s);\n\t\twhile (!que.empty()) {\n\
    \t\t\tint node = que.front();\n\t\t\tque.pop();\n\t\t\tfor (const auto& i : vec[node])\
    \ {\n\t\t\t\tif (i.cap > 0 && level[i.to] == -1) {\n\t\t\t\t\tlevel[i.to] = level[node]\
    \ + 1;\n\t\t\t\t\tque.push(i.to);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn level[t]\
    \ != -1;\n\t}\n\tlint dfs(int node, int t, lint f) {\n\t\tif (node == t) return\
    \ f;\n\t\tfor (int& i = iter[node]; i < vec[node].size(); i++) {\n\t\t\tedge&\
    \ e = vec[node][i];\n\t\t\tif (e.cap > 0 && level[node] < level[e.to]) {\n\t\t\
    \t\tlint d = dfs(e.to, t, std::min(f, e.cap));\n\t\t\t\tif (d > 0) {\n\t\t\t\t\
    \te.cap -= d;\n\t\t\t\t\tvec[e.to][e.rev].cap += d;\n\t\t\t\t\treturn d;\n\t\t\
    \t\t}\n\t\t\t}\n\t\t}\n\t\treturn 0;\n\t}\n\n  public:\n\tDinic(int n) : N(n)\
    \ {\n\t\tvec.resize(N);\n\t\tlevel.resize(N);\n\t\titer.resize(N);\n\t}\n\tvoid\
    \ reset() {\n\t\trep(i, N) {\n\t\t\tfor (auto& j : vec[i]) {\n\t\t\t\tif (j.id\
    \ != -1) {\n\t\t\t\t\tvec[j.to][j.rev].cap += j.cap;\n\t\t\t\t\tj.cap = 0;\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tvoid add_edge(int from, int to, lint cap) {\n\t\
    \tvec[from].push_back({to, cap, (int)vec[to].size(), -1});\n\t\tvec[to].push_back({from,\
    \ 0, (int)vec[from].size() - 1, idx++});\n\t}\n\tlint max_flow(int s, int t) {\n\
    \t\tlint res = 0;\n\t\twhile (true) {\n\t\t\tbfs(s, t);\n\t\t\tif (level[t] <\
    \ 0) return res;\n\t\t\titer.assign(N, 0);\n\t\t\tlint f;\n\t\t\twhile ((f = dfs(s,\
    \ t, LINF)) > 0) res += f;\n\t\t}\n\t}\n\tstd::vector<lint> restore() const {\n\
    \t\tstd::vector<lint> res(idx);\n\t\trep(i, N) {\n\t\t\tfor (const auto& j : vec[i])\
    \ {\n\t\t\t\tif (j.id != -1) res[j.id] = j.cap;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\
    \t}\n};\n\n/**\n * @title Dinic's algorithm\n */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: graph/Dinic.hpp
  requiredBy: []
  timestamp: '2021-02-24 00:36:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bipartitematching.test.cpp
  - test/aoj/GRL_6_A_Dinic.test.cpp
documentation_of: graph/Dinic.hpp
layout: document
redirect_from:
- /library/graph/Dinic.hpp
- /library/graph/Dinic.hpp.html
title: Dinic's algorithm
---
