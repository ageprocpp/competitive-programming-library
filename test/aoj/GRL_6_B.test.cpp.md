---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/PrimalDual.hpp
    title: graph/PrimalDual.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
  bundledCode: "#line 1 \"test/aoj/GRL_6_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\"\
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
    namespace std {\n\ttemplate <template <class...> class Temp, class T>\n\tclass\
    \ is_template_with_type_of : public std::false_type {};\n\ttemplate <template\
    \ <class...> class Temp, class... Args>\n\tclass is_template_with_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n\ttemplate <template <auto...>\
    \ class Temp, class T>\n\tclass is_template_with_non_type_of : public std::false_type\
    \ {};\n\ttemplate <template <auto...> class Temp, auto... Args>\n\tclass is_template_with_non_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n};\t// namespace std\ntemplate\
    \ <class T>\nclass prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {\n};\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f)\
    \ {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <class T, class... Args>\nauto make_vec(size_t n, Args&&... args)\
    \ {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\t\
    if (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    template <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs\
    \ > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\t\
    b = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) { return a /\
    \ gcd(a, b) * b; }\nbool isprime(lint n) {\n\tif (n == 1) return false;\n\tfor\
    \ (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn\
    \ true;\n}\ntemplate <class T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile (b)\
    \ {\n\t\tif (b & 1) res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn res;\n\
    }\nlint modpow(lint a, lint b, lint m) {\n\ta %= m;\n\tlint res(1);\n\twhile (b)\
    \ {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\
    \ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate <class T>\nvoid printArray(std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <class T>\nvoid printArray(T l, T r, char split = ' ') {\n\tT rprev = std::prev(r);\n\
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
    }\n#line 3 \"graph/PrimalDual.hpp\"\nclass PrimalDual {\n\tclass edge {\n\t  public:\n\
    \t\tint to, cap;\n\t\tlint cost;\n\t\tint rev, id;\n\t};\n\tint n, idx = 0, s,\
    \ t;\n\tlint curres = 0;\n\tstd::vector<std::vector<edge>> vec;\n\tstd::vector<int>\
    \ prevv, preve;\n\tstd::vector<lint> h, dist;\n\tbool negative = false;\n\tlint\
    \ BellmanFord() {\n\t\tdist.assign(n, LINF);\n\t\tdist[s] = 0;\n\t\trep(i, n -\
    \ 1) {\n\t\t\trep(j, n) {\n\t\t\t\trep(k, vec[j].size()) {\n\t\t\t\t\tconst edge&\
    \ e = vec[j][k];\n\t\t\t\t\tif (e.cap > 0 &&\n\t\t\t\t\t\tchmin(dist[e.to], dist[j]\
    \ + e.cost + h[j] - h[e.to])) {\n\t\t\t\t\t\tprevv[e.to] = j;\n\t\t\t\t\t\tpreve[e.to]\
    \ = k;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif (dist[t] == LINF) {\n\t\
    \t\tstd::cerr << \"The demand is over maximum flow.\" << std::endl;\n\t\t\treturn\
    \ -1;\n\t\t}\n\t\trep(i, n) h[i] += dist[i];\n\t\tfor (int i = t; i != s; i =\
    \ prevv[i]) {\n\t\t\tvec[prevv[i]][preve[i]].cap--;\n\t\t\tvec[i][vec[prevv[i]][preve[i]].rev].cap++;\n\
    \t\t}\n\t\treturn h[t];\n\t}\n\n  public:\n\tPrimalDual(int n, int s, int t) :\
    \ n(n), s(s), t(t) {\n\t\tvec.resize(n);\n\t\th.resize(n);\n\t\tdist.resize(n);\n\
    \t\tprevv.resize(n);\n\t\tpreve.resize(n);\n\t}\n\tvoid add_edge(int from, int\
    \ to, int cap, lint cost) {\n\t\tif (cost < 0) negative = true;\n\t\tvec[from].push_back({to,\
    \ cap, cost, (int)vec[to].size(), -1});\n\t\tvec[to].push_back({from, 0, -cost,\
    \ (int)vec[from].size() - 1, idx++});\n\t}\n\tlint add_flow(int f) {\n\t\tif (negative)\
    \ {\n\t\t\tcurres += BellmanFord();\n\t\t\tf--;\n\t\t\tnegative = false;\n\t\t\
    }\n\t\twhile (f > 0) {\n\t\t\tdist.assign(n, LINF);\n\t\t\tdist[s] = 0;\n\t\t\t\
    prique<std::pair<lint, int>> que;\n\t\t\tque.push({0, s});\n\t\t\twhile (!que.empty())\
    \ {\n\t\t\t\tauto p = que.top();\n\t\t\t\tque.pop();\n\t\t\t\tif (dist[p.second]\
    \ < p.first) continue;\n\t\t\t\trep(i, vec[p.second].size()) {\n\t\t\t\t\tedge&\
    \ e = vec[p.second][i];\n\t\t\t\t\tif (e.cap > 0 &&\n\t\t\t\t\t\tchmin(dist[e.to],\
    \ dist[p.second] + e.cost +\n\t\t\t\t\t\t\t\t\t\t\t  h[p.second] - h[e.to])) {\n\
    \t\t\t\t\t\tprevv[e.to] = p.second;\n\t\t\t\t\t\tpreve[e.to] = i;\n\t\t\t\t\t\t\
    que.push({dist[e.to], e.to});\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (dist[t]\
    \ == LINF) {\n\t\t\t\tstd::cerr << \"The demand is over the maximum flow.\"\n\t\
    \t\t\t\t\t  << std::endl;\n\t\t\t\treturn -1;\n\t\t\t}\n\t\t\trep(i, n) h[i] +=\
    \ dist[i];\n\t\t\tint d = f;\n\t\t\tfor (int i = t; i != s; i = prevv[i]) {\n\t\
    \t\t\tchmin(d, vec[prevv[i]][preve[i]].cap);\n\t\t\t}\n\t\t\tf -= d;\n\t\t\tcurres\
    \ += (lint)d * h[t];\n\t\t\tfor (int i = t; i != s; i = prevv[i]) {\n\t\t\t\t\
    vec[prevv[i]][preve[i]].cap -= d;\n\t\t\t\tvec[i][vec[prevv[i]][preve[i]].rev].cap\
    \ += d;\n\t\t\t}\n\t\t}\n\t\treturn curres;\n\t}\n\tstd::vector<lint> restore()\
    \ {\n\t\tstd::vector<lint> res(idx);\n\t\trep(i, n) {\n\t\t\tfor (const auto&\
    \ j : vec[i]) {\n\t\t\t\tif (j.id != -1) res[j.id] = j.cap;\n\t\t\t}\n\t\t}\n\t\
    \treturn res;\n\t}\n\tvoid reset() {\n\t\trep(i, n) {\n\t\t\tfor (auto& j : vec[i])\
    \ {\n\t\t\t\tif (j.id != -1) {\n\t\t\t\t\tvec[j.to][j.rev].cap += j.cap;\n\t\t\
    \t\t\tj.cap = 0;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n};\n#line 4 \"test/aoj/GRL_6_B.test.cpp\"\
    \nint n, m, f;\nint main() {\n\tscanf(\"%d%d%d\", &n, &m, &f);\n\tPrimalDual mcf(n,\
    \ 0, n - 1);\n\trep(i, m) {\n\t\tint u, v, c, d;\n\t\tscanf(\"%d%d%d%d\", &u,\
    \ &v, &c, &d);\n\t\tmcf.add_edge(u, v, c, d);\n\t}\n\tprintf(\"%d\\n\", mcf.add_flow(f));\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\"\n#include\
    \ \"../../graph/PrimalDual.hpp\"\n#include \"../../other/template.hpp\"\nint n,\
    \ m, f;\nint main() {\n\tscanf(\"%d%d%d\", &n, &m, &f);\n\tPrimalDual mcf(n, 0,\
    \ n - 1);\n\trep(i, m) {\n\t\tint u, v, c, d;\n\t\tscanf(\"%d%d%d%d\", &u, &v,\
    \ &c, &d);\n\t\tmcf.add_edge(u, v, c, d);\n\t}\n\tprintf(\"%d\\n\", mcf.add_flow(f));\n\
    }"
  dependsOn:
  - graph/PrimalDual.hpp
  - other/template.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2021-01-10 18:28:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_B.test.cpp
- /verify/test/aoj/GRL_6_B.test.cpp.html
title: test/aoj/GRL_6_B.test.cpp
---
