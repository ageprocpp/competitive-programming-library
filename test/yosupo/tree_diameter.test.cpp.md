---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/Tree.hpp
    title: graph/Tree.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/yosupo/tree_diameter.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tree_diameter\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#pragma target(\"avx2\")\n#pragma optimize(\"\
    O3\")\n#pragma optimize(\"unroll-loops\")\n#include <string.h>\n#include <algorithm>\n\
    #include <bitset>\n#include <cassert>\n#include <cfloat>\n#include <climits>\n\
    #include <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n#define rep(i, n) for (int i = 0; i < (n); i++)\n#define REP(i, n)\
    \ for (int i = 1; i <= (n); i++)\n#define all(V) V.begin(), V.end()\ntypedef unsigned\
    \ int uint;\ntypedef long long lint;\ntypedef unsigned long long ulint;\ntypedef\
    \ std::pair<int, int> P;\ntypedef std::pair<lint, lint> LP;\nconstexpr int INF\
    \ = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps =\
    \ DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\ntemplate\
    \ <class T>\nclass prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {\n};\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs)\
    \ {\n\tif (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\ntemplate <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\t\
    if (lhs > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    inline lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\
    \t\tb = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) {\n\treturn\
    \ a / gcd(a, b) * b;\n}\nbool isprime(lint n) {\n\tif (n == 1) return false;\n\
    \tfor (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\
    \treturn true;\n}\ntemplate <typename T>\nT mypow(T a, lint b) {\n\tT res(1);\n\
    \twhile (b) {\n\t\tif (b & 1) res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn\
    \ res;\n}\nlint modpow(lint a, lint b, lint m) {\n\tlint res(1);\n\twhile (b)\
    \ {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\
    \ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate <typename T>\nvoid printArray(std::vector<T>&\
    \ vec) {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout << (i\
    \ == (int)vec.size() - 1 ? \"\\n\" : \" \");\n\t}\n}\ntemplate <typename T>\n\
    void printArray(T l, T r) {\n\tT rprev = std::prev(r);\n\tfor (T i = l; i != r;\
    \ i++) {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? \"\\n\" : \" \"\
    );\n\t}\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s\
    \ = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b *\
    \ s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const\
    \ lint& b2, const lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp =\
    \ (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn\
    \ std::make_pair(r, m1 * m2);\n}\ntemplate <typename F>\ninline constexpr decltype(auto)\
    \ lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\
    \treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\ntemplate <typename\
    \ T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n}\ntemplate\
    \ <typename T, class... Args>\nauto make_vec(size_t n, Args&&... args) {\n\treturn\
    \ std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\n#line 3 \"graph/Tree.hpp\"\nclass Tree {\n\tusing ET = std::pair<int, lint>;\n\
    \n  private:\n\tint N;\n\tstd::vector<std::vector<ET>> vec;\n\n  public:\n\ttemplate\
    \ <typename T, typename U>\n\tTree(int M, const std::vector<std::pair<T, U>> es)\
    \ : N(M) {\n\t\tvec.resize(N + 1);\n\t\tfor (const auto& e : es) {\n\t\t\tvec[e.first].emplace_back(e.second,\
    \ 1);\n\t\t\tvec[e.second].emplace_back(e.first, 1);\n\t\t}\n\t}\n\ttemplate <typename\
    \ T, typename U, typename V>\n\tTree(int M, const std::vector<std::pair<std::pair<T,\
    \ U>, V>> es) : N(M) {\n\t\tvec.resize(N + 1);\n\t\tfor (const auto& e : es) {\n\
    \t\t\tvec[e.first.first].emplace_back(e.first.second, e.second);\n\t\t\tvec[e.first.second].emplace_back(e.first.first,\
    \ e.second);\n\t\t}\n\t}\n\tstd::vector<lint> GetDist(int s) {\n\t\tstd::vector<lint>\
    \ dist(N + 1, LINF);\n\t\tdist[0] = -LINF;\n\t\tdist[s] = 0;\n\t\tlambda_fix([&](auto\
    \ self, int node) -> void {\n\t\t\tfor (const auto& e : vec[node]) {\n\t\t\t\t\
    if (dist[e.first] == LINF) {\n\t\t\t\t\tdist[e.first] = dist[node] + e.second;\n\
    \t\t\t\t\tself(self, e.first);\n\t\t\t\t}\n\t\t\t}\n\t\t})(s);\n\t\treturn dist;\n\
    \t}\n\tstd::pair<P, lint> Diameter() {\n\t\tauto d = GetDist(1);\n\t\tint x =\
    \ std::max_element(all(d)) - d.begin();\n\t\td = GetDist(x);\n\t\tauto mit = std::max_element(all(d));\n\
    \t\treturn {{x, mit - d.begin()}, *mit};\n\t}\n\tstd::pair<std::vector<int>, lint>\
    \ DiameterPath() {\n\t\tauto tmp = Diameter();\n\t\tauto [x, y] = tmp.first;\n\
    \t\tlint dist = tmp.second;\n\t\tstd::vector<bool> used(N + 1);\n\t\tstd::vector<int>\
    \ res;\n\t\tbool f = false;\n\t\tlambda_fix([&, y = y](auto self, int node) ->\
    \ void {\n\t\t\tused[node] = true;\n\t\t\tif (node == y) f = true;\n\t\t\tfor\
    \ (const auto& e : vec[node]) {\n\t\t\t\tif (!used[e.first]) {\n\t\t\t\t\tself(self,\
    \ e.first);\n\t\t\t\t\tif (f) break;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (f) res.push_back(node);\n\
    \t\t})(x);\n\t\tstd::reverse(all(res));\n\t\treturn {res, dist};\n\t}\n};\n#line\
    \ 4 \"test/yosupo/tree_diameter.test.cpp\"\nint N;\nint main() {\n\tscanf(\"%d\"\
    , &N);\n\tstd::vector<std::pair<P, int>> vec;\n\trep(i, N - 1) {\n\t\tint a, b,\
    \ c;\n\t\tscanf(\"%d%d%d\", &a, &b, &c);\n\t\ta++;\n\t\tb++;\n\t\tvec.push_back({{a,\
    \ b}, c});\n\t}\n\tTree tree(N, vec);\n\tauto res = tree.DiameterPath();\n\tprintf(\"\
    %lld %d\\n\", res.second, res.first.size());\n\tstd::for_each(all(res.first),\
    \ [](int &n) { n--; });\n\tprintArray(res.first);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n#include\
    \ \"../../graph/Tree.hpp\"\n#include \"../../other/template.hpp\"\nint N;\nint\
    \ main() {\n\tscanf(\"%d\", &N);\n\tstd::vector<std::pair<P, int>> vec;\n\trep(i,\
    \ N - 1) {\n\t\tint a, b, c;\n\t\tscanf(\"%d%d%d\", &a, &b, &c);\n\t\ta++;\n\t\
    \tb++;\n\t\tvec.push_back({{a, b}, c});\n\t}\n\tTree tree(N, vec);\n\tauto res\
    \ = tree.DiameterPath();\n\tprintf(\"%lld %d\\n\", res.second, res.first.size());\n\
    \tstd::for_each(all(res.first), [](int &n) { n--; });\n\tprintArray(res.first);\n\
    }"
  dependsOn:
  - graph/Tree.hpp
  - other/template.hpp
  isVerificationFile: true
  path: test/yosupo/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2020-12-08 15:45:19+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_diameter.test.cpp
- /verify/test/yosupo/tree_diameter.test.cpp.html
title: test/yosupo/tree_diameter.test.cpp
---
