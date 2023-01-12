---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/ConvexHullTrick.hpp
    title: Convex Hull Trick
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line 2\
    \ \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n\
    #ifdef ONLINE_JUDGE\n#ifdef _WIN64\n#pragma GCC target(\"avx2\")\n#else\n#pragma\
    \ GCC target(\"avx512f\")\n#endif\n#elif defined EVAL\n#else\n#pragma GCC target(\"\
    avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#endif\n#include <string.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#define rep(i, n) for (int i = 0; i < int(n); i++)\n#define\
    \ REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(), V.end()\n\
    \nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
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
    \ make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class U>\n\
    std::istream& operator>>(std::istream& ist, std::pair<T, U>& x) {\n\treturn ist\
    \ >> x.first >> x.second;\n}\ntemplate <class T, class U>\nstd::ostream& operator<<(std::ostream&\
    \ ost, const std::pair<T, U>& x) {\n\treturn ost << x.first << \" \" << x.second;\n\
    }\ntemplate <class Container,\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nauto operator>>(std::istream&\
    \ ist, Container& cont)\n\t-> decltype(typename Container::iterator(), std::cin)&\
    \ {\n\tContainer tmp;\n\twhile (true) {\n\t\ttypename Container::value_type t;\n\
    \t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\tif (getchar() == '\\n') break;\n\t\
    }\n\tcont = Container(std::move(tmp));\n\treturn ist;\n}\ntemplate <class Container,\n\
    \t\t  std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t>\
    \ = nullptr>\nauto operator<<(std::ostream& ost, const Container& cont)\n\t->\
    \ decltype(typename Container::iterator(), std::cout)& {\n\tfor (auto it = cont.begin();\
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
    }\n#line 2 \"data-structure/ConvexHullTrick.hpp\"\ntemplate <class T, bool isMin>\n\
    class ConvexHullTrick {\n\tstatic constexpr double DBL_INF = DBL_MAX;\n\tclass\
    \ Line {\n\t  public:\n\t\tT m, b;\n\t\tint id;\n\t\tdouble x;\n\t\tbool isQuery;\n\
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
    \t\tindex = 0;\n\t}\n};\n\n/**\n * @title Convex Hull Trick\n */\n#line 4 \"test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp\"\
    \nint N, Q;\nint main() {\n\tscanf(\"%d%d\", &N, &Q);\n\tConvexHullTrick<lint,\
    \ true> cht;\n\trep(i, N) {\n\t\tint a;\n\t\tlint b;\n\t\tscanf(\"%d%lld\", &a,\
    \ &b);\n\t\tcht.addLine(a, b);\n\t}\n\trep(i, Q) {\n\t\tint t;\n\t\tscanf(\"%d\"\
    , &t);\n\t\tif (t == 0) {\n\t\t\tint a;\n\t\t\tlint b;\n\t\t\tscanf(\"%d%lld\"\
    , &a, &b);\n\t\t\tcht.addLine(a, b);\n\t\t} else {\n\t\t\tint p;\n\t\t\tscanf(\"\
    %d\", &p);\n\t\t\tprintf(\"%lld\\n\", cht.query(p).first);\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../data-structure/ConvexHullTrick.hpp\"\
    \nint N, Q;\nint main() {\n\tscanf(\"%d%d\", &N, &Q);\n\tConvexHullTrick<lint,\
    \ true> cht;\n\trep(i, N) {\n\t\tint a;\n\t\tlint b;\n\t\tscanf(\"%d%lld\", &a,\
    \ &b);\n\t\tcht.addLine(a, b);\n\t}\n\trep(i, Q) {\n\t\tint t;\n\t\tscanf(\"%d\"\
    , &t);\n\t\tif (t == 0) {\n\t\t\tint a;\n\t\t\tlint b;\n\t\t\tscanf(\"%d%lld\"\
    , &a, &b);\n\t\t\tcht.addLine(a, b);\n\t\t} else {\n\t\t\tint p;\n\t\t\tscanf(\"\
    %d\", &p);\n\t\t\tprintf(\"%lld\\n\", cht.query(p).first);\n\t\t}\n\t}\n}\n"
  dependsOn:
  - other/template.hpp
  - data-structure/ConvexHullTrick.hpp
  isVerificationFile: true
  path: test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 03:21:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp
- /verify/test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp.html
title: test/yosupo/line_add_get_min_ConvexHullTrick.test.cpp
---
