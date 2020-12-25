---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Dinic.hpp
    title: graph/Dinic.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A_Dinic.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\
    \n#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifdef ONLINE_JUDGE\n\
    #pragma GCC target(\"avx512f\")\n#else\n#pragma GCC target(\"avx2\")\n#endif\n\
    #pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#include\
    \ <string.h>\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#define rep(i, n) for (int i = 0; i < int(n);\
    \ i++)\n#define REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(),\
    \ V.end()\ntypedef unsigned int uint;\ntypedef long long lint;\ntypedef unsigned\
    \ long long ulint;\ntypedef std::pair<int, int> P;\ntypedef std::pair<lint, lint>\
    \ LP;\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\n\
    constexpr double eps = DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
    template <class T>\nclass prique : public std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> {\n};\ntemplate <typename F>\ninline constexpr decltype(auto)\
    \ lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\
    \treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\ntemplate <typename\
    \ T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n}\ntemplate\
    \ <typename T, class... Args>\nauto make_vec(size_t n, Args&&... args) {\n\treturn\
    \ std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\t\
    if (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    template <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs\
    \ > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\t\
    b = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) { return a /\
    \ gcd(a, b) * b; }\nbool isprime(lint n) {\n\tif (n == 1) return false;\n\tfor\
    \ (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn\
    \ true;\n}\ntemplate <typename T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile\
    \ (b) {\n\t\tif (b & 1) res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn res;\n\
    }\nlint modpow(lint a, lint b, lint m) {\n\ta %= m;\n\tlint res(1);\n\twhile (b)\
    \ {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\
    \ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate <typename T>\nvoid printArray(std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <typename T>\nvoid printArray(T l, T r, char split = ' ') {\n\tT rprev = std::prev(r);\n\
    \tfor (T i = l; i != r; i++) {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev\
    \ ? '\\n' : split);\n\t}\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return\
    \ {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second\
    \ -= a / b * s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint&\
    \ m1, const lint& b2, const lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\t\
    lint tmp = (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\
    \treturn std::make_pair(r, m1 * m2);\n}\nint LCS(const std::string& a, const std::string&\
    \ b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\trep(i, a.size())\
    \ {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j\
    \ + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\t}\n\trep(j,\
    \ b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn dp[a.size()][b.size()];\n\
    }\n#line 3 \"graph/Dinic.hpp\"\nclass Dinic {\n\tclass edge {\n\t  public:\n\t\
    \tint to;\n\t\tlint cap;\n\t\tint rev, id;\n\t};\n\tint N, idx = 0;\n\tstd::vector<std::vector<edge>>\
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
    \t}\n};\n#line 4 \"test/aoj/GRL_6_A_Dinic.test.cpp\"\nint v, e;\nint main() {\n\
    \tscanf(\"%d%d\", &v, &e);\n\tDinic flow(v);\n\trep(i, e) {\n\t\tint a, b, c;\n\
    \t\tscanf(\"%d%d%d\", &a, &b, &c);\n\t\tflow.add_edge(a, b, c);\n\t}\n\tprintf(\"\
    %d\\n\", flow.max_flow(0, v - 1));\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\n#include\
    \ \"../../graph/Dinic.hpp\"\n#include \"../../other/template.hpp\"\nint v, e;\n\
    int main() {\n\tscanf(\"%d%d\", &v, &e);\n\tDinic flow(v);\n\trep(i, e) {\n\t\t\
    int a, b, c;\n\t\tscanf(\"%d%d%d\", &a, &b, &c);\n\t\tflow.add_edge(a, b, c);\n\
    \t}\n\tprintf(\"%d\\n\", flow.max_flow(0, v - 1));\n\treturn 0;\n}"
  dependsOn:
  - graph/Dinic.hpp
  - other/template.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A_Dinic.test.cpp
  requiredBy: []
  timestamp: '2020-12-26 00:19:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A_Dinic.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A_Dinic.test.cpp
- /verify/test/aoj/GRL_6_A_Dinic.test.cpp.html
title: test/aoj/GRL_6_A_Dinic.test.cpp
---
