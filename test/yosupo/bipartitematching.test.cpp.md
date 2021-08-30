---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Dinic.hpp
    title: Dinic's algorithm
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n#ifdef ONLINE_JUDGE\n#ifdef\
    \ _WIN64\n#pragma GCC target(\"avx2\")\n#else\n#pragma GCC target(\"avx512f\"\
    )\n#endif\n#elif defined EVAL\n#else\n#pragma GCC target(\"avx2\")\n#endif\n#pragma\
    \ GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n#include\
    \ <string.h>\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cfloat>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define rep(i,\
    \ n) for (int i = 0; i < lint(n); i++)\n#define REP(i, n) for (int i = 1; i <=\
    \ lint(n); i++)\n#define all(V) V.begin(), V.end()\n\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing uint = unsigned int;\nusing lint = long long;\n\
    using ulint = unsigned long long;\nusing IP = std::pair<int, int>;\nusing LP =\
    \ std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF\
    \ = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON * 10;\nconstexpr double\
    \ PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique :\
    \ public std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\nint popcount(uint\
    \ x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n#else\n#ifndef\
    \ __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\tx = (x & 0x55555555)\
    \ + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >> 2 & 0x33333333);\n\t\
    x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x & 0x00ff00ff) + (x >>\
    \ 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);\n}\ntemplate\
    \ <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f\
    \ = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class\
    \ U>\nstd::istream& operator>>(std::istream& ist, std::pair<T, U>& x) {\n\treturn\
    \ ist >> x.first >> x.second;\n}\ntemplate <class T, class U>\nstd::ostream& operator<<(std::ostream&\
    \ ost, const std::pair<T, U>& x) {\n\treturn ost << x.first << \" \" << x.second;\n\
    }\ntemplate <\n\tclass Container,\n\tstd::enable_if_t<std::negation_v<std::is_same<Container,\
    \ std::string>>,\n\t\t\t\t\t std::nullptr_t> = nullptr>\nauto operator>>(std::istream&\
    \ ist, Container& cont)\n\t-> decltype(typename Container::iterator(), std::cin)&\
    \ {\n\tstd::vector<typename Container::value_type> tmp;\n\twhile (true) {\n\t\t\
    typename Container::value_type t;\n\t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\
    \tif (getchar() == '\\n') break;\n\t}\n\tcont = Container(std::move(tmp));\n\t\
    return ist;\n}\ntemplate <class Container,\n\t\t  std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>,\n\t\t\t\t\t\t   std::nullptr_t> = nullptr>\nauto operator<<(std::ostream&\
    \ ost, const Container& cont)\n\t-> decltype(typename Container::iterator(), std::cout)&\
    \ {\n\tfor (auto it = cont.begin(); it != cont.end(); it++) {\n\t\tif (it != cont.begin())\
    \ ost << ' ';\n\t\tost << *it;\n\t}\n\treturn ost;\n}\ntemplate <class Container>\n\
    auto sum(const Container& cont)\n\t-> decltype(typename Container::iterator(),\
    \ 0LL) {\n\tlint res = 0;\n\tfor (auto it = cont.begin(); it != cont.end(); it++)\
    \ res += *it;\n\treturn res;\n}\ntemplate <class T, class U>\nconstexpr inline\
    \ bool chmax(T& lhs, const U& rhs) noexcept {\n\tif (lhs < rhs) {\n\t\tlhs = rhs;\n\
    \t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class T, class U>\nconstexpr\
    \ inline bool chmin(T& lhs, const U& rhs) noexcept {\n\tif (lhs > rhs) {\n\t\t\
    lhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\nconstexpr inline lint gcd(lint\
    \ a, lint b) noexcept {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\tb = c\
    \ % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) noexcept { return\
    \ a / gcd(a, b) * b; }\nconstexpr bool isprime(lint n) noexcept {\n\tif (n ==\
    \ 1) return false;\n\tfor (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0)\
    \ return false;\n\t}\n\treturn true;\n}\ntemplate <class T>\nconstexpr T mypow(T\
    \ a, lint b) noexcept {\n\tT res(1);\n\twhile (true) {\n\t\tif (b & 1) res *=\
    \ a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\t}\n\treturn res;\n}\nconstexpr\
    \ lint modpow(lint a, lint b, lint m) noexcept {\n\ta %= m;\n\tlint res(1);\n\t\
    while (b) {\n\t\tif (b & 1) res *= a, res %= m;\n\t\ta *= a, a %= m, b >>= 1;\n\
    \t}\n\treturn res;\n}\nLP extGcd(lint a, lint b) noexcept {\n\tif (b == 0) return\
    \ {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second\
    \ -= a / b * s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint&\
    \ m1, const lint& b2,\n\t\t\t  const lint& m2) noexcept {\n\tauto p = extGcd(m1,\
    \ m2);\n\tlint g = gcd(m1, m2), l = m1 / g * m2;\n\tlint tmp = (b2 - b1) / g *\
    \ p.first % (m2 / g);\n\tlint r = (b1 + m1 * tmp + l) % l;\n\treturn {r, l};\n\
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
    \ = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tvoid clear() { *this = Dinic(N); }\n\
    \tvoid add_edge(int from, int to, lint cap) {\n\t\tvec[from].push_back({to, cap,\
    \ (int)vec[to].size(), -1});\n\t\tvec[to].push_back({from, 0, (int)vec[from].size()\
    \ - 1, idx++});\n\t}\n\tlint max_flow(int s, int t) {\n\t\tlint res = 0;\n\t\t\
    while (true) {\n\t\t\tbfs(s, t);\n\t\t\tif (level[t] < 0) return res;\n\t\t\t\
    iter.assign(N, 0);\n\t\t\tlint f;\n\t\t\twhile ((f = dfs(s, t, LINF)) > 0) res\
    \ += f;\n\t\t}\n\t}\n\tstd::vector<lint> restore() const {\n\t\tstd::vector<lint>\
    \ res(idx);\n\t\trep(i, N) {\n\t\t\tfor (const auto& j : vec[i]) {\n\t\t\t\tif\
    \ (j.id != -1) res[j.id] = j.cap;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n\
    /**\n * @title Dinic's algorithm\n */\n#line 4 \"test/yosupo/bipartitematching.test.cpp\"\
    \nint L, R, M, a[200010], b[200010];\nint main() {\n\tscanf(\"%d%d%d\", &L, &R,\
    \ &M);\n\tDinic flow(L + R + 2);\n\tREP(i, L) flow.add_edge(0, i, 1);\n\tfor (int\
    \ i = L + 1; i <= L + R; i++) flow.add_edge(i, L + R + 1, 1);\n\trep(i, M) {\n\
    \t\tscanf(\"%d%d\", a + i, b + i);\n\t\tflow.add_edge(a[i] + 1, b[i] + L + 1,\
    \ 1);\n\t}\n\tstd::cout << flow.max_flow(0, L + R + 1) << std::endl;\n\tauto vec\
    \ = flow.restore();\n\trep(i, M) {\n\t\tif (vec[i + L + R]) std::cout << a[i]\
    \ << \" \" << b[i] << std::endl;\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../graph/Dinic.hpp\"\nint L, R,\
    \ M, a[200010], b[200010];\nint main() {\n\tscanf(\"%d%d%d\", &L, &R, &M);\n\t\
    Dinic flow(L + R + 2);\n\tREP(i, L) flow.add_edge(0, i, 1);\n\tfor (int i = L\
    \ + 1; i <= L + R; i++) flow.add_edge(i, L + R + 1, 1);\n\trep(i, M) {\n\t\tscanf(\"\
    %d%d\", a + i, b + i);\n\t\tflow.add_edge(a[i] + 1, b[i] + L + 1, 1);\n\t}\n\t\
    std::cout << flow.max_flow(0, L + R + 1) << std::endl;\n\tauto vec = flow.restore();\n\
    \trep(i, M) {\n\t\tif (vec[i + L + R]) std::cout << a[i] << \" \" << b[i] << std::endl;\n\
    \t}\n\treturn 0;\n}"
  dependsOn:
  - other/template.hpp
  - graph/Dinic.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2021-08-31 00:37:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
