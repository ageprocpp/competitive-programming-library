---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/PrimalDual.hpp
    title: Primal-dual algorithm
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
  bundledCode: "#line 1 \"test/aoj/GRL_6_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\"\
    \n#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n\
    #pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n\
    #include <string.h>\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cfloat>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i, n) for (int i = 0; i < int(n); i++)\n#define REP(i,\
    \ n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(), V.end()\n\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
    using lint = long long;\nusing ulint = unsigned long long;\nusing IP = std::pair<int,\
    \ int>;\nusing LP = std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\n\
    constexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON * 10;\n\
    constexpr double PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\n\
    class prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {};\nint popcount(uint x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n\
    #else\n#ifndef __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\t\
    x = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >>\
    \ 2 & 0x33333333);\n\tx = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x\
    \ & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16\
    \ & 0x0000ffff);\n}\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&&\
    \ f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(n,\
    \ make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class U, class\
    \ Stream>\nStream& operator>>(Stream& ist, std::pair<T, U>& x) {\n\treturn ist\
    \ >> x.first >> x.second;\n}\ntemplate <class T, class U, class Stream>\nStream&\
    \ operator<<(Stream& ost, const std::pair<T, U>& x) {\n\treturn ost << x.first\
    \ << \" \" << x.second;\n}\ntemplate <class Container,\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nauto operator>>(std::istream&\
    \ ist, Container& cont)\n\t-> decltype(typename Container::iterator(), std::cin)&\
    \ {\n\tContainer tmp;\n\twhile (true) {\n\t\ttypename Container::value_type t;\n\
    \t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\tif (getchar() == '\\n') break;\n\t\
    }\n\tcont = Container(std::move(tmp));\n\treturn ist;\n}\ntemplate <class Container,\
    \ class Stream,\n\t\t  std::enable_if_t<!std::is_same<Container, std::string>::value,\
    \ std::nullptr_t> = nullptr>\nauto operator<<(Stream& ost, const Container& cont)\n\
    \t-> decltype(typename Container::iterator(), ost)& {\n\tfor (auto it = cont.begin();\
    \ it != cont.end(); it++) {\n\t\tif (it != cont.begin()) ost << ' ';\n\t\tost\
    \ << *it;\n\t}\n\treturn ost;\n}\ntemplate <class Container>\nauto sum(const Container&\
    \ cont) -> decltype(typename Container::iterator(), 0LL) {\n\tlint res = 0;\n\t\
    for (auto it = cont.begin(); it != cont.end(); it++) res += *it;\n\treturn res;\n\
    }\ntemplate <class T, class U>\nconstexpr inline bool chmax(T& lhs, const U& rhs)\
    \ noexcept {\n\tif (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn\
    \ false;\n}\ntemplate <class T, class U>\nconstexpr inline bool chmin(T& lhs,\
    \ const U& rhs) noexcept {\n\tif (lhs > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\
    \t}\n\treturn false;\n}\nconstexpr inline lint gcd(lint a, lint b) noexcept {\n\
    \twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\treturn a;\n\
    }\ninline lint lcm(lint a, lint b) noexcept { return a / gcd(a, b) * b; }\nconstexpr\
    \ bool isprime(lint n) noexcept {\n\tif (n == 1) return false;\n\tfor (int i =\
    \ 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n\
    }\ntemplate <class T>\nconstexpr T mypow(T a, lint b) noexcept {\n\tT res(1);\n\
    \twhile (true) {\n\t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\
    \t\ta *= a;\n\t}\n\treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint\
    \ m) noexcept {\n\ta %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) res\
    \ *= a, res %= m;\n\t\ta *= a, a %= m, b >>= 1;\n\t}\n\treturn res;\n}\nLP extGcd(lint\
    \ a, lint b) noexcept {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b, a %\
    \ b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\treturn\
    \ s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const lint&\
    \ m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\tlint g = gcd(m1, m2), l = m1 /\
    \ g * m2;\n\tlint tmp = (b2 - b1) / g * p.first % (m2 / g);\n\tlint r = (b1 +\
    \ m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const std::string& a, const\
    \ std::string& b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\t\
    rep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\
    \t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j\
    \ + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\
    \t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn\
    \ dp[a.size()][b.size()];\n}\ntemplate <class T, std::enable_if_t<std::is_convertible<int,\
    \ T>::value, std::nullptr_t> = nullptr>\nvoid compress(std::vector<T>& vec) {\n\
    \tauto tmp = vec;\n\tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)),\
    \ tmp.end());\n\tfor (T& i : vec) i = std::lower_bound(all(tmp), i) - tmp.begin();\n\
    }\ntemplate <class T>\nvoid compress(T* l, T* r) {\n\tstd::vector<T> tmp(l, r);\n\
    \tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor\
    \ (auto i = l; i < r; i++) {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\
    \t}\n}\ntemplate <class InputIter>\nvoid compress(InputIter l, InputIter r) {\n\
    \tstd::vector<typename InputIter::value_type> tmp(l, r);\n\tstd::sort(all(tmp));\n\
    \ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor (auto i = l; i < r; i++)\
    \ {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\t}\n}\ntemplate\
    \ <class InputIter,\n\t\t  std::enable_if_t<std::is_same<typename InputIter::value_type,\
    \ std::pair<IP, int>>::value,\n\t\t\t\t\t\t   std::nullptr_t> = nullptr>\nvoid\
    \ mo_sort(InputIter l, InputIter r, int N) {\n\tconst int M = std::max(1.0, std::sqrt(lint(N)\
    \ * N / std::distance(l, r)));\n\tstd::sort(l, r, [M](const auto& lhs, const auto&\
    \ rhs) {\n\t\tif (lhs.first.first / M < rhs.first.first / M) return true;\n\t\t\
    if (lhs.first.first / M == rhs.first.first / M) return lhs.first.second < rhs.first.second;\n\
    \t\treturn false;\n\t});\n\tint before = -1, cnt = 0;\n\tbool f = false;\n\tfor\
    \ (InputIter i = l; i != r; i++) {\n\t\tif (before != i->first.first / M) {\n\t\
    \t\tif (f) std::reverse(i - cnt, i);\n\t\t\tf ^= true, before = i->first.first\
    \ / M, cnt = 1;\n\t\t} else\n\t\t\tcnt++;\n\t}\n\tif (f) std::reverse(r - cnt,\
    \ r);\n}\ntemplate <class T>\nstd::vector<T> xor_bases(const std::vector<T>& vec)\
    \ {\n\tstd::vector<T> res;\n\tfor (T i : vec) {\n\t\tfor (T j : res) {\n\t\t\t\
    chmin(i, i ^ j);\n\t\t}\n\t\tif (i) res.emplace_back(i);\n\t}\n\treturn res;\n\
    }\n#line 3 \"graph/PrimalDual.hpp\"\nclass PrimalDualDemandOver {};\nclass PrimalDual\
    \ {\n\tclass edge {\n\t  public:\n\t\tint to, cap;\n\t\tlint cost;\n\t\tint rev,\
    \ id;\n\t};\n\tint n, idx = 0, s, t;\n\tlint curres = 0;\n\tstd::vector<std::vector<edge>>\
    \ vec;\n\tstd::vector<int> prevv, preve;\n\tstd::vector<lint> h, dist;\n\tbool\
    \ negative = false;\n\tlint BellmanFord() {\n\t\tdist.assign(n, LINF);\n\t\tdist[s]\
    \ = 0;\n\t\trep(i, n - 1) {\n\t\t\trep(j, n) {\n\t\t\t\trep(k, vec[j].size())\
    \ {\n\t\t\t\t\tconst edge& e = vec[j][k];\n\t\t\t\t\tif (e.cap > 0 && chmin(dist[e.to],\
    \ dist[j] + e.cost + h[j] - h[e.to])) {\n\t\t\t\t\t\tprevv[e.to] = j;\n\t\t\t\t\
    \t\tpreve[e.to] = k;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (dist[t]\
    \ == LINF) throw PrimalDualDemandOver();\n\t\trep(i, n) h[i] += dist[i];\n\t\t\
    for (int i = t; i != s; i = prevv[i]) {\n\t\t\tvec[prevv[i]][preve[i]].cap--;\n\
    \t\t\tvec[i][vec[prevv[i]][preve[i]].rev].cap++;\n\t\t}\n\t\treturn h[t];\n\t\
    }\n\n  public:\n\tPrimalDual(int n, int s, int t) : n(n), s(s), t(t) {\n\t\tvec.resize(n);\n\
    \t\th.resize(n);\n\t\tdist.resize(n);\n\t\tprevv.resize(n);\n\t\tpreve.resize(n);\n\
    \t}\n\tvoid add_edge(int from, int to, int cap, lint cost) {\n\t\tif (cost < 0)\
    \ negative = true;\n\t\tvec[from].push_back({to, cap, cost, (int)vec[to].size(),\
    \ -1});\n\t\tvec[to].push_back({from, 0, -cost, (int)vec[from].size() - 1, idx++});\n\
    \t}\n\tlint add_flow(int f) {\n\t\tif (negative) {\n\t\t\tcurres += BellmanFord();\n\
    \t\t\tf--;\n\t\t\tnegative = false;\n\t\t}\n\t\twhile (f > 0) {\n\t\t\tdist.assign(n,\
    \ LINF);\n\t\t\tdist[s] = 0;\n\t\t\tprique<std::pair<lint, int>> que;\n\t\t\t\
    que.push({0, s});\n\t\t\twhile (!que.empty()) {\n\t\t\t\tauto p = que.top();\n\
    \t\t\t\tque.pop();\n\t\t\t\tif (dist[p.second] < p.first) continue;\n\t\t\t\t\
    rep(i, vec[p.second].size()) {\n\t\t\t\t\tedge& e = vec[p.second][i];\n\t\t\t\t\
    \tif (e.cap > 0 &&\n\t\t\t\t\t\tchmin(dist[e.to], dist[p.second] + e.cost + h[p.second]\
    \ - h[e.to])) {\n\t\t\t\t\t\tprevv[e.to] = p.second;\n\t\t\t\t\t\tpreve[e.to]\
    \ = i;\n\t\t\t\t\t\tque.push({dist[e.to], e.to});\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\tif (dist[t] == LINF) throw PrimalDualDemandOver();\n\t\t\trep(i, n)\
    \ h[i] += dist[i];\n\t\t\tint d = f;\n\t\t\tfor (int i = t; i != s; i = prevv[i])\
    \ {\n\t\t\t\tchmin(d, vec[prevv[i]][preve[i]].cap);\n\t\t\t}\n\t\t\tf -= d;\n\t\
    \t\tcurres += (lint)d * h[t];\n\t\t\tfor (int i = t; i != s; i = prevv[i]) {\n\
    \t\t\t\tvec[prevv[i]][preve[i]].cap -= d;\n\t\t\t\tvec[i][vec[prevv[i]][preve[i]].rev].cap\
    \ += d;\n\t\t\t}\n\t\t}\n\t\treturn curres;\n\t}\n\tstd::vector<lint> restore()\
    \ {\n\t\tstd::vector<lint> res(idx);\n\t\trep(i, n) {\n\t\t\tfor (const auto&\
    \ j : vec[i]) {\n\t\t\t\tif (j.id != -1) res[j.id] = j.cap;\n\t\t\t}\n\t\t}\n\t\
    \treturn res;\n\t}\n\tvoid reset() {\n\t\trep(i, n) {\n\t\t\tfor (auto& j : vec[i])\
    \ {\n\t\t\t\tif (j.id != -1) {\n\t\t\t\t\tvec[j.to][j.rev].cap += j.cap;\n\t\t\
    \t\t\tj.cap = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n};\n\n/**\n * @title Primal-dual\
    \ algorithm\n */\n#line 4 \"test/aoj/GRL_6_B.test.cpp\"\nint n, m, f;\nint main()\
    \ {\n\tscanf(\"%d%d%d\", &n, &m, &f);\n\tPrimalDual mcf(n, 0, n - 1);\n\trep(i,\
    \ m) {\n\t\tint u, v, c, d;\n\t\tscanf(\"%d%d%d%d\", &u, &v, &c, &d);\n\t\tmcf.add_edge(u,\
    \ v, c, d);\n\t}\n\ttry {\n\t\tprintf(\"%d\\n\", mcf.add_flow(f));\n\t} catch\
    \ (const PrimalDualDemandOver& e) {\n\t\tprintf(\"-1\\n\");\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\"\n#include\
    \ \"../../graph/PrimalDual.hpp\"\n#include \"../../other/template.hpp\"\nint n,\
    \ m, f;\nint main() {\n\tscanf(\"%d%d%d\", &n, &m, &f);\n\tPrimalDual mcf(n, 0,\
    \ n - 1);\n\trep(i, m) {\n\t\tint u, v, c, d;\n\t\tscanf(\"%d%d%d%d\", &u, &v,\
    \ &c, &d);\n\t\tmcf.add_edge(u, v, c, d);\n\t}\n\ttry {\n\t\tprintf(\"%d\\n\"\
    , mcf.add_flow(f));\n\t} catch (const PrimalDualDemandOver& e) {\n\t\tprintf(\"\
    -1\\n\");\n\t}\n}"
  dependsOn:
  - graph/PrimalDual.hpp
  - other/template.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2023-06-16 19:42:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_B.test.cpp
- /verify/test/aoj/GRL_6_B.test.cpp.html
title: test/aoj/GRL_6_B.test.cpp
---
