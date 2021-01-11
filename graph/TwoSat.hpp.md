---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/StronglyConnectedComponents.hpp
    title: graph/StronglyConnectedComponents.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifdef ONLINE_JUDGE\n#pragma GCC target(\"avx512f\")\n#else\n#pragma GCC target(\"\
    avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <string.h>\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n\
    #include <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n\
    #include <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n#define rep(i, n) for\
    \ (int i = 0; i < int(n); i++)\n#define REP(i, n) for (int i = 1; i <= int(n);\
    \ i++)\n#define all(V) V.begin(), V.end()\ntypedef unsigned int uint;\ntypedef\
    \ long long lint;\ntypedef unsigned long long ulint;\ntypedef std::pair<int, int>\
    \ P;\ntypedef std::pair<lint, lint> LP;\nconstexpr int INF = INT_MAX / 2;\nconstexpr\
    \ lint LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr double\
    \ PI = 3.141592653589793238462643383279;\nnamespace std {\n\ttemplate <template\
    \ <class...> class Temp, class T>\n\tclass is_template_with_type_of : public std::false_type\
    \ {};\n\ttemplate <template <class...> class Temp, class... Args>\n\tclass is_template_with_type_of<Temp,\
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
    \ true;\n}\ntemplate <class T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile (true)\
    \ {\n\t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\
    \t}\n\treturn res;\n}\nlint modpow(lint a, lint b, lint m) {\n\ta %= m;\n\tlint\
    \ res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\
    \t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate\
    \ <class T>\nvoid printArray(const std::vector<T>& vec, char split = ' ') {\n\t\
    rep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout << (i == (int)vec.size()\
    \ - 1 ? '\\n' : split);\n\t}\n}\ntemplate <class T>\nvoid printArray(T l, T r,\
    \ char split = ' ') {\n\tT rprev = std::prev(r);\n\tfor (T i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? '\\n' : split);\n\t\
    }\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b,\
    \ a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\t\
    return s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const\
    \ lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp = (b2 - b1) * p %\
    \ m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn std::make_pair(r,\
    \ m1 * m2);\n}\nint LCS(const std::string& a, const std::string& b) {\n\tauto\
    \ dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\trep(i, a.size()) {\n\t\t\
    rep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j\
    \ + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\t}\n\trep(j,\
    \ b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn dp[a.size()][b.size()];\n\
    }\n#line 3 \"graph/StronglyConnectedComponents.hpp\"\nclass StronglyConnectedComponents\
    \ {\n\tint N;\n\tstd::vector<std::vector<int>> vec, rvec;\n\n  public:\n\tStronglyConnectedComponents(int\
    \ N_) : N(N_) {\n\t\tvec.resize(N);\n\t\trvec.resize(N);\n\t}\n\tvoid add_edge(int\
    \ from, int to) {\n\t\tvec[from].emplace_back(to);\n\t\trvec[to].emplace_back(from);\n\
    \t}\n\tstd::vector<std::vector<int>> get_scc() {\n\t\tstd::vector<bool> used(N);\n\
    \t\tstd::vector<int> vs;\n\t\tstd::vector<std::vector<int>> res;\n\t\tauto dfs\
    \ = lambda_fix([&](auto self, int node) -> void {\n\t\t\tused[node] = true;\n\t\
    \t\tfor (const int& i : vec[node]) {\n\t\t\t\tif (!used[i]) self(self, i);\n\t\
    \t\t}\n\t\t\tvs.emplace_back(node);\n\t\t});\n\t\tauto rdfs = lambda_fix([&](auto\
    \ self, int node) -> void {\n\t\t\tused[node] = true;\n\t\t\tres.back().emplace_back(node);\n\
    \t\t\tfor (const int& i : rvec[node]) {\n\t\t\t\tif (!used[i]) self(self, i);\n\
    \t\t\t}\n\t\t});\n\t\trep(i, N) {\n\t\t\tif (!used[i]) dfs(i);\n\t\t}\n\t\tused.assign(N,\
    \ false);\n\t\tfor (int i = N - 1; i >= 0; i--) {\n\t\t\tif (!used[vs[i]]) {\n\
    \t\t\t\tres.emplace_back();\n\t\t\t\trdfs(vs[i]);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\tstd::vector<int> get_ids() {\n\t\tauto vec = get_scc();\n\t\tstd::vector<int>\
    \ res(N);\n\t\trep(i, vec.size()) {\n\t\t\tfor (const auto& j : vec[i]) res[j]\
    \ = i;\n\t\t}\n\t\treturn res;\n\t}\n};\n#line 4 \"graph/TwoSat.hpp\"\nclass TwoSat\
    \ {\n\tint N;\n\tStronglyConnectedComponents scc;\n\tstd::vector<int> ans;\n\n\
    \  public:\n\tTwoSat(int N_) : N(N_), scc(2 * N_), ans(N_) {}\n\tvoid add_clause(int\
    \ i, bool f, int j, bool g) {\n\t\tscc.add_edge(2 * i + int(!f), 2 * j + int(g));\n\
    \t\tscc.add_edge(2 * j + int(!g), 2 * i + int(f));\n\t}\n\tbool satisfiable()\
    \ {\n\t\tauto ids = scc.get_ids();\n\t\trep(i, N) {\n\t\t\tif (ids[2 * i] == ids[2\
    \ * i + 1]) return false;\n\t\t\tans[i] = ids[2 * i] < ids[2 * i + 1];\n\t\t}\n\
    \t\treturn true;\n\t}\n\tstd::vector<int> answer() { return ans; }\n};\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n#include \"StronglyConnectedComponents.hpp\"\
    \nclass TwoSat {\n\tint N;\n\tStronglyConnectedComponents scc;\n\tstd::vector<int>\
    \ ans;\n\n  public:\n\tTwoSat(int N_) : N(N_), scc(2 * N_), ans(N_) {}\n\tvoid\
    \ add_clause(int i, bool f, int j, bool g) {\n\t\tscc.add_edge(2 * i + int(!f),\
    \ 2 * j + int(g));\n\t\tscc.add_edge(2 * j + int(!g), 2 * i + int(f));\n\t}\n\t\
    bool satisfiable() {\n\t\tauto ids = scc.get_ids();\n\t\trep(i, N) {\n\t\t\tif\
    \ (ids[2 * i] == ids[2 * i + 1]) return false;\n\t\t\tans[i] = ids[2 * i] < ids[2\
    \ * i + 1];\n\t\t}\n\t\treturn true;\n\t}\n\tstd::vector<int> answer() { return\
    \ ans; }\n};"
  dependsOn:
  - other/template.hpp
  - graph/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: graph/TwoSat.hpp
  requiredBy: []
  timestamp: '2021-01-12 02:03:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: graph/TwoSat.hpp
layout: document
redirect_from:
- /library/graph/TwoSat.hpp
- /library/graph/TwoSat.hpp.html
title: graph/TwoSat.hpp
---
