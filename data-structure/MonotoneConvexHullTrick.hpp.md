---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #pragma target(\"avx2\")\n#pragma optimize(\"O3\")\n#pragma optimize(\"unroll-loops\"\
    )\n#include <string.h>\n\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n\
    #include <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n\
    #include <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n#define rep(i, n) for\
    \ (int i = 0; i < (n); i++)\n#define REP(i, n) for (int i = 1; i <= (n); i++)\n\
    #define all(V) V.begin(), V.end()\ntypedef unsigned int uint;\ntypedef long long\
    \ lint;\ntypedef unsigned long long ulint;\ntypedef std::pair<int, int> P;\ntypedef\
    \ std::pair<lint, lint> LP;\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint\
    \ LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr double\
    \ PI = 3.141592653589793238462643383279;\ntemplate <class T>\nclass prique : public\
    \ std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\ntemplate <class\
    \ T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\tif (lhs < rhs) {\n\
    \t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class T,\
    \ class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs) {\n\t\t\
    lhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline lint gcd(lint a,\
    \ lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\
    \treturn a;\n}\ninline lint lcm(lint a, lint b) {\n\treturn a / gcd(a, b) * b;\n\
    }\nbool isprime(lint n) {\n\tif (n == 1) return false;\n\tfor (int i = 2; i *\
    \ i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\n\
    template <typename T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile (b) {\n\t\t\
    if (b & 1) res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\nlint modpow(lint\
    \ a, lint b, lint m) {\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\t\
    res *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t\
    }\n\treturn res;\n}\ntemplate <typename T>\nvoid printArray(std::vector<T>& vec)\
    \ {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout << (i ==\
    \ (int)vec.size() - 1 ? \"\\n\" : \" \");\n\t}\n}\ntemplate <typename T>\nvoid\
    \ printArray(T l, T r) {\n\tT rprev = std::prev(r);\n\tfor (T i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? \"\\n\" : \" \");\n\t\
    }\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b,\
    \ a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\t\
    return s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const\
    \ lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp = (b2 - b1) * p %\
    \ m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn std::make_pair(r,\
    \ m1 * m2);\n}\ntemplate <typename F>\ninline constexpr decltype(auto) lambda_fix(F&&\
    \ f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <typename T>\nstd::vector<T> make_vec(size_t n) {\n\treturn\
    \ std::vector<T>(n);\n}\ntemplate <typename T, class... Args>\nauto make_vec(size_t\
    \ n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\n#line 2 \"data-structure/MonotoneConvexHullTrick.hpp\"\
    \ntemplate <typename T, bool isMin>\nclass MonotoneConvexHullTrick {\n\tstatic\
    \ constexpr double INF = DBL_MAX;\n\tusing TP = std::pair<std::pair<T, T>, int>;\n\
    \tint index = 0;\n\tstd::deque<TP> deq;\n\tinline int sgn(T x) { return x == 0\
    \ ? 0 : (x < 0 ? -1 : 1); }\n\tinline T eval(const TP& a, const T& x) {\n\t\t\
    return a.first.first * x + a.first.second;\n\t}\n\tinline bool bad(const TP& l1,\
    \ const TP& l2, const TP& l3) {\n\t\tif (l1.first.second == l2.first.second ||\n\
    \t\t\tl2.first.second == l3.first.second) {\n\t\t\treturn sgn(l2.first.first -\
    \ l1.first.first) *\n\t\t\t\t\t   sgn(l3.first.second - l2.first.second) >=\n\t\
    \t\t\t   sgn(l3.first.first - l2.first.first) *\n\t\t\t\t\t   sgn(l2.first.second\
    \ - l1.first.second);\n\t\t}\n\t\treturn (double)(l2.first.first - l1.first.first)\
    \ *\n\t\t\t\t   sgn(l3.first.second - l2.first.second) /\n\t\t\t\t   std::abs(l2.first.second\
    \ - l1.first.second) >=\n\t\t\t   (double)(l3.first.first - l2.first.first) *\n\
    \t\t\t\t   sgn(l2.first.second - l1.first.second) /\n\t\t\t\t   std::abs(l3.first.second\
    \ - l2.first.second);\n\t}\n\n  public:\n\tvoid addLine(T m, T b) {\n\t\tif (!isMin)\
    \ m = -m, b = -b;\n\t\tTP line = {{m, b}, index++};\n\t\tif (empty()) {\n\t\t\t\
    deq.emplace_front(line);\n\t\t\treturn;\n\t\t}\n\t\tif (deq.front().first.first\
    \ <= m) {\n\t\t\tif (deq.front().first.first == m) {\n\t\t\t\tif (deq.front().first.second\
    \ <= b) return;\n\t\t\t\tdeq.pop_front();\n\t\t\t}\n\t\t\twhile (deq.size() >=\
    \ 2 && bad(line, deq[0], deq[1]))\n\t\t\t\tdeq.pop_front();\n\t\t\tdeq.emplace_front(line);\n\
    \t\t} else {\n\t\t\tif (deq.back().first.first == m) {\n\t\t\t\tif (deq.back().first.second\
    \ <= b) return;\n\t\t\t\tdeq.pop_back();\n\t\t\t}\n\t\t\twhile (deq.size() >=\
    \ 2 &&\n\t\t\t\t   bad(deq[deq.size() - 2], deq.back(), line))\n\t\t\t\tdeq.pop_back();\n\
    \t\t\tdeq.emplace_back(line);\n\t\t}\n\t}\n\tstd::pair<T, int> query(T x) {\n\t\
    \tint l = -1, r = deq.size() - 1;\n\t\twhile (l + 1 < r) {\n\t\t\tint m = (l +\
    \ r) / 2;\n\t\t\tif (eval(deq[m], x) >= eval(deq[m + 1], x))\n\t\t\t\tl = m;\n\
    \t\t\telse\n\t\t\t\tr = m;\n\t\t}\n\t\treturn {(isMin ? 1 : -1) * eval(deq[r],\
    \ x), deq[r].second};\n\t}\n\tstd::pair<T, int> queryMonotoneInc(T x) {\n\t\t\
    while (deq.size() >= 2 && eval(deq[0], x) >= eval(deq[1], x))\n\t\t\tdeq.pop_front();\n\
    \t\treturn {(isMin ? 1 : -1) * eval(deq[0], x), deq[0].second};\n\t}\n\tstd::pair<T,\
    \ int> queryMonotoneDec(T x) {\n\t\twhile (deq.size() >= 2 &&\n\t\t\t   eval(deq.back(),\
    \ x) >= eval(deq[deq.size() - 2]))\n\t\t\tdeq.pop_back();\n\t\treturn {(isMin\
    \ ? 1 : -1) * eval(deq.back(), x), deq.back().second};\n\t}\n\tbool empty() const\
    \ { return deq.empty(); }\n\tvoid clear() {\n\t\tdeq.clear();\n\t\tindex = 0;\n\
    \t}\n};\n"
  code: "#include \"../other/template.hpp\"\ntemplate <typename T, bool isMin>\nclass\
    \ MonotoneConvexHullTrick {\n\tstatic constexpr double INF = DBL_MAX;\n\tusing\
    \ TP = std::pair<std::pair<T, T>, int>;\n\tint index = 0;\n\tstd::deque<TP> deq;\n\
    \tinline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }\n\tinline T eval(const\
    \ TP& a, const T& x) {\n\t\treturn a.first.first * x + a.first.second;\n\t}\n\t\
    inline bool bad(const TP& l1, const TP& l2, const TP& l3) {\n\t\tif (l1.first.second\
    \ == l2.first.second ||\n\t\t\tl2.first.second == l3.first.second) {\n\t\t\treturn\
    \ sgn(l2.first.first - l1.first.first) *\n\t\t\t\t\t   sgn(l3.first.second - l2.first.second)\
    \ >=\n\t\t\t\t   sgn(l3.first.first - l2.first.first) *\n\t\t\t\t\t   sgn(l2.first.second\
    \ - l1.first.second);\n\t\t}\n\t\treturn (double)(l2.first.first - l1.first.first)\
    \ *\n\t\t\t\t   sgn(l3.first.second - l2.first.second) /\n\t\t\t\t   std::abs(l2.first.second\
    \ - l1.first.second) >=\n\t\t\t   (double)(l3.first.first - l2.first.first) *\n\
    \t\t\t\t   sgn(l2.first.second - l1.first.second) /\n\t\t\t\t   std::abs(l3.first.second\
    \ - l2.first.second);\n\t}\n\n  public:\n\tvoid addLine(T m, T b) {\n\t\tif (!isMin)\
    \ m = -m, b = -b;\n\t\tTP line = {{m, b}, index++};\n\t\tif (empty()) {\n\t\t\t\
    deq.emplace_front(line);\n\t\t\treturn;\n\t\t}\n\t\tif (deq.front().first.first\
    \ <= m) {\n\t\t\tif (deq.front().first.first == m) {\n\t\t\t\tif (deq.front().first.second\
    \ <= b) return;\n\t\t\t\tdeq.pop_front();\n\t\t\t}\n\t\t\twhile (deq.size() >=\
    \ 2 && bad(line, deq[0], deq[1]))\n\t\t\t\tdeq.pop_front();\n\t\t\tdeq.emplace_front(line);\n\
    \t\t} else {\n\t\t\tif (deq.back().first.first == m) {\n\t\t\t\tif (deq.back().first.second\
    \ <= b) return;\n\t\t\t\tdeq.pop_back();\n\t\t\t}\n\t\t\twhile (deq.size() >=\
    \ 2 &&\n\t\t\t\t   bad(deq[deq.size() - 2], deq.back(), line))\n\t\t\t\tdeq.pop_back();\n\
    \t\t\tdeq.emplace_back(line);\n\t\t}\n\t}\n\tstd::pair<T, int> query(T x) {\n\t\
    \tint l = -1, r = deq.size() - 1;\n\t\twhile (l + 1 < r) {\n\t\t\tint m = (l +\
    \ r) / 2;\n\t\t\tif (eval(deq[m], x) >= eval(deq[m + 1], x))\n\t\t\t\tl = m;\n\
    \t\t\telse\n\t\t\t\tr = m;\n\t\t}\n\t\treturn {(isMin ? 1 : -1) * eval(deq[r],\
    \ x), deq[r].second};\n\t}\n\tstd::pair<T, int> queryMonotoneInc(T x) {\n\t\t\
    while (deq.size() >= 2 && eval(deq[0], x) >= eval(deq[1], x))\n\t\t\tdeq.pop_front();\n\
    \t\treturn {(isMin ? 1 : -1) * eval(deq[0], x), deq[0].second};\n\t}\n\tstd::pair<T,\
    \ int> queryMonotoneDec(T x) {\n\t\twhile (deq.size() >= 2 &&\n\t\t\t   eval(deq.back(),\
    \ x) >= eval(deq[deq.size() - 2]))\n\t\t\tdeq.pop_back();\n\t\treturn {(isMin\
    \ ? 1 : -1) * eval(deq.back(), x), deq.back().second};\n\t}\n\tbool empty() const\
    \ { return deq.empty(); }\n\tvoid clear() {\n\t\tdeq.clear();\n\t\tindex = 0;\n\
    \t}\n};"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/MonotoneConvexHullTrick.hpp
  requiredBy: []
  timestamp: '2020-12-05 13:29:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/MonotoneConvexHullTrick.hpp
layout: document
redirect_from:
- /library/data-structure/MonotoneConvexHullTrick.hpp
- /library/data-structure/MonotoneConvexHullTrick.hpp.html
title: data-structure/MonotoneConvexHullTrick.hpp
---
