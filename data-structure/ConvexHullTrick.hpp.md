---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp
    title: test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp
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
    \ PI = 3.141592653589793238462643383279;\ntemplate <class T>\nclass prique : public\
    \ std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\ntemplate <typename\
    \ F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&...\
    \ args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\n\
    template <typename T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <typename T, class... Args>\nauto make_vec(size_t n, Args&&... args)\
    \ {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
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
    }\n#line 2 \"data-structure/ConvexHullTrick.hpp\"\ntemplate <typename T, bool\
    \ isMin>\nclass ConvexHullTrick {\n\tstatic constexpr double DBL_INF = DBL_MAX;\n\
    \tclass Line {\n\t  public:\n\t\tT m, b;\n\t\tint id;\n\t\tdouble x;\n\t\tbool\
    \ isQuery;\n\t\tinline Line(int id = -1, T m = 0, T b = 0)\n\t\t\t: m(m), b(b),\
    \ id(id), isQuery(false) {}\n\t\tT eval(T x) const { return m * x + b; }\n\t\t\
    bool parallel(const Line& l) const { return m == l.m; }\n\t\tdouble intersect(const\
    \ Line& l) const {\n\t\t\treturn parallel(l) ? DBL_INF : double(l.b - b) / (m\
    \ - l.m);\n\t\t}\n\t\tinline bool operator<(const Line& l) const {\n\t\t\tif (l.isQuery)\
    \ return x < l.m;\n\t\t\tif (isQuery) return m < l.x;\n\t\t\treturn m < l.m;\n\
    \t\t}\n\t};\n\tint index = 1;\n\tstd::set<Line> st;\n\tusing iter = typename std::set<Line>::iterator;\n\
    \tinline bool cPrev(iter it) const { return it != st.begin(); }\n\tinline bool\
    \ cNext(iter it) const {\n\t\treturn it != st.end() && std::next(it) != st.end();\n\
    \t}\n\tbool bad(const Line& l1, const Line& l2, const Line& l3) const {\n\t\t\
    return l1.intersect(l3) <= l1.intersect(l2);\n\t}\n\tbool bad(iter it) const {\n\
    \t\treturn cPrev(it) && cNext(it) &&\n\t\t\t   bad(*std::prev(it), *it, *std::next(it));\n\
    \t}\n\titer update(iter it) {\n\t\tdouble x;\n\t\tif (!cPrev(it))\n\t\t\tx = -DBL_INF;\n\
    \t\telse\n\t\t\tx = it->intersect(*std::prev(it));\n\t\tLine tmp(*it);\n\t\ttmp.x\
    \ = x;\n\t\tit = st.erase(it);\n\t\treturn st.insert(it, tmp);\n\t}\n\n  public:\n\
    \tvoid addLine(T m, T b) {\n\t\tif (isMin) m = -m, b = -b;\n\t\tLine l(index++,\
    \ m, b);\n\t\tif (st.empty()) l.x = -DBL_INF;\n\t\titer it = st.lower_bound(l);\n\
    \t\tif (it != st.end() && l.parallel(*it)) {\n\t\t\tif (it->b < b)\n\t\t\t\tit\
    \ = st.erase(it);\n\t\t\telse\n\t\t\t\treturn;\n\t\t}\n\t\tit = st.insert(it,\
    \ l);\n\t\tif (bad(it)) {\n\t\t\tst.erase(it);\n\t\t\treturn;\n\t\t}\n\t\twhile\
    \ (cPrev(it) && bad(std::prev(it))) st.erase(std::prev(it));\n\t\twhile (cNext(it)\
    \ && bad(std::next(it))) st.erase(std::next(it));\n\t\tit = update(it);\n\t\t\
    if (cPrev(it)) update(std::prev(it));\n\t\tif (cNext(it)) update(std::next(it));\n\
    \t}\n\tstd::pair<T, int> query(T x) {\n\t\tLine q;\n\t\tq.m = x;\n\t\tq.isQuery\
    \ = true;\n\t\titer it = --st.upper_bound(q);\n\t\tif (isMin) return {-it->eval(x),\
    \ it->id};\n\t\treturn {it->eval(x), it->id};\n\t}\n\tvoid clear() {\n\t\tst.clear();\n\
    \t\tindex = 0;\n\t}\n};\n"
  code: "#include \"../other/template.hpp\"\ntemplate <typename T, bool isMin>\nclass\
    \ ConvexHullTrick {\n\tstatic constexpr double DBL_INF = DBL_MAX;\n\tclass Line\
    \ {\n\t  public:\n\t\tT m, b;\n\t\tint id;\n\t\tdouble x;\n\t\tbool isQuery;\n\
    \t\tinline Line(int id = -1, T m = 0, T b = 0)\n\t\t\t: m(m), b(b), id(id), isQuery(false)\
    \ {}\n\t\tT eval(T x) const { return m * x + b; }\n\t\tbool parallel(const Line&\
    \ l) const { return m == l.m; }\n\t\tdouble intersect(const Line& l) const {\n\
    \t\t\treturn parallel(l) ? DBL_INF : double(l.b - b) / (m - l.m);\n\t\t}\n\t\t\
    inline bool operator<(const Line& l) const {\n\t\t\tif (l.isQuery) return x <\
    \ l.m;\n\t\t\tif (isQuery) return m < l.x;\n\t\t\treturn m < l.m;\n\t\t}\n\t};\n\
    \tint index = 1;\n\tstd::set<Line> st;\n\tusing iter = typename std::set<Line>::iterator;\n\
    \tinline bool cPrev(iter it) const { return it != st.begin(); }\n\tinline bool\
    \ cNext(iter it) const {\n\t\treturn it != st.end() && std::next(it) != st.end();\n\
    \t}\n\tbool bad(const Line& l1, const Line& l2, const Line& l3) const {\n\t\t\
    return l1.intersect(l3) <= l1.intersect(l2);\n\t}\n\tbool bad(iter it) const {\n\
    \t\treturn cPrev(it) && cNext(it) &&\n\t\t\t   bad(*std::prev(it), *it, *std::next(it));\n\
    \t}\n\titer update(iter it) {\n\t\tdouble x;\n\t\tif (!cPrev(it))\n\t\t\tx = -DBL_INF;\n\
    \t\telse\n\t\t\tx = it->intersect(*std::prev(it));\n\t\tLine tmp(*it);\n\t\ttmp.x\
    \ = x;\n\t\tit = st.erase(it);\n\t\treturn st.insert(it, tmp);\n\t}\n\n  public:\n\
    \tvoid addLine(T m, T b) {\n\t\tif (isMin) m = -m, b = -b;\n\t\tLine l(index++,\
    \ m, b);\n\t\tif (st.empty()) l.x = -DBL_INF;\n\t\titer it = st.lower_bound(l);\n\
    \t\tif (it != st.end() && l.parallel(*it)) {\n\t\t\tif (it->b < b)\n\t\t\t\tit\
    \ = st.erase(it);\n\t\t\telse\n\t\t\t\treturn;\n\t\t}\n\t\tit = st.insert(it,\
    \ l);\n\t\tif (bad(it)) {\n\t\t\tst.erase(it);\n\t\t\treturn;\n\t\t}\n\t\twhile\
    \ (cPrev(it) && bad(std::prev(it))) st.erase(std::prev(it));\n\t\twhile (cNext(it)\
    \ && bad(std::next(it))) st.erase(std::next(it));\n\t\tit = update(it);\n\t\t\
    if (cPrev(it)) update(std::prev(it));\n\t\tif (cNext(it)) update(std::next(it));\n\
    \t}\n\tstd::pair<T, int> query(T x) {\n\t\tLine q;\n\t\tq.m = x;\n\t\tq.isQuery\
    \ = true;\n\t\titer it = --st.upper_bound(q);\n\t\tif (isMin) return {-it->eval(x),\
    \ it->id};\n\t\treturn {it->eval(x), it->id};\n\t}\n\tvoid clear() {\n\t\tst.clear();\n\
    \t\tindex = 0;\n\t}\n};"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/ConvexHullTrick.hpp
  requiredBy: []
  timestamp: '2020-12-26 00:19:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp
documentation_of: data-structure/ConvexHullTrick.hpp
layout: document
redirect_from:
- /library/data-structure/ConvexHullTrick.hpp
- /library/data-structure/ConvexHullTrick.hpp.html
title: data-structure/ConvexHullTrick.hpp
---
