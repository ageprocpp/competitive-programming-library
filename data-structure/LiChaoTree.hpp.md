---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min_LiChaoTree.test.cpp
    title: test/yosupo/line_add_get_min_LiChaoTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Li Chao Tree
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifndef __clang__\n#ifdef ONLINE_JUDGE\n#ifdef _WIN64\n#pragma GCC target(\"avx2\"\
    )\n#else\n#pragma GCC target(\"avx512f\")\n#endif\n#elif defined EVAL\n#else\n\
    #pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n#endif\n#include <string.h>\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#define rep(i, n) for (int i = 0; i < lint(n); i++)\n#define\
    \ REP(i, n) for (int i = 1; i <= lint(n); i++)\n#define all(V) V.begin(), V.end()\n\
    \nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
    using lint = long long;\nusing ulint = unsigned long long;\nusing IP = std::pair<int,\
    \ int>;\nusing LP = std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\n\
    constexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON * 10;\n\
    constexpr double PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\n\
    class prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {\n};\nint popcount(uint x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n\
    #else\n#ifndef __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\t\
    x = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >>\
    \ 2 & 0x33333333);\n\tx = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x\
    \ & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16\
    \ & 0x0000ffff);\n}\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&&\
    \ f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
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
    data-structure/LiChaoTree.hpp\"\ntemplate <bool isMin>\nclass LiChaoTree {\n\t\
    int n, id;\n\tstd::vector<std::tuple<lint, lint, lint>> interval;\n\tstd::vector<std::pair<LP,\
    \ int>> node;\n\tstd::vector<lint> cord;\n\tlint calc(std::pair<LP, int> l, lint\
    \ x) {\n\t\treturn l.first.first * x + l.first.second;\n\t}\n\tvoid addSegment(std::pair<LP,\
    \ int>& newLine, lint cnt) {\n\t\tlint l = std::get<0>(interval[cnt]), m = std::get<1>(interval[cnt]),\n\
    \t\t\t r = std::get<2>(interval[cnt]);\n\t\tif (n <= cnt) {\n\t\t\tif (calc(node[cnt],\
    \ l) > calc(newLine, l)) node[cnt] = newLine;\n\t\t\treturn;\n\t\t}\n\t\tif (calc(node[cnt],\
    \ l) < calc(newLine, l) &&\n\t\t\tcalc(node[cnt], r) < calc(newLine, r))\n\t\t\
    \treturn;\n\t\tif (calc(node[cnt], l) > calc(newLine, l) &&\n\t\t\tcalc(node[cnt],\
    \ r) > calc(newLine, r)) {\n\t\t\tnode[cnt] = newLine;\n\t\t\treturn;\n\t\t}\n\
    \t\tif (calc(node[cnt], m) > calc(newLine, m))\n\t\t\tstd::swap(node[cnt], newLine);\n\
    \t\tif (calc(node[cnt], l) > calc(newLine, l))\n\t\t\taddSegment(newLine, cnt\
    \ << 1);\n\t\telse\n\t\t\taddSegment(newLine, cnt << 1 | 1);\n\t}\n\n  public:\n\
    \tLiChaoTree() {}\n\tLiChaoTree(std::vector<lint> vec) { init(vec); }\n\tvoid\
    \ init(std::vector<lint> con) {\n\t\tinterval.clear();\n\t\tnode.clear();\n\t\t\
    cord.clear();\n\t\tn = 1;\n\t\tid = 0;\n\t\tcon.emplace_back(con.back() + 1);\n\
    \t\twhile (n < (int)con.size()) n *= 2;\n\t\twhile ((int)con.size() < n + 1) con.emplace_back(con.back()\
    \ + 1);\n\t\tnode.assign(2 * n, {{0, LINF}, -1});\n\t\tinterval.emplace_back(0,\
    \ 0, 0);\n\t\tfor (int range = n; range; range >>= 1) {\n\t\t\tfor (int i = 0;\
    \ i < n; i += range) {\n\t\t\t\tif (range == 1)\n\t\t\t\t\tinterval.emplace_back(con[i],\
    \ 0, con[i + range]);\n\t\t\t\telse\n\t\t\t\t\tinterval.emplace_back(con[i], con[i\
    \ + range / 2],\n\t\t\t\t\t\t\t\t\t\t  con[i + range]);\n\t\t\t}\n\t\t}\n\t\t\
    cord = con;\n\t}\n\tvoid addLine(lint a, lint b) {\n\t\tstd::pair<LP, int> newLine\
    \ = {{a, b}, id++};\n\t\tif (!isMin) {\n\t\t\tnewLine.first.first *= -1;\n\t\t\
    \tnewLine.first.second *= -1;\n\t\t}\n\t\taddSegment(newLine, 1);\n\t}\n\tvoid\
    \ addSegment(int l, int r, lint a, lint b) {\n\t\tl += n;\n\t\tr += n;\n\t\tstd::pair<LP,\
    \ int> newLine = {{a, b}, id++};\n\t\tif (!isMin) {\n\t\t\tnewLine.first.first\
    \ *= -1;\n\t\t\tnewLine.first.second *= -1;\n\t\t}\n\t\twhile (l < r) {\n\t\t\t\
    if (l & 1) {\n\t\t\t\tauto tmp = newLine;\n\t\t\t\taddSegment(tmp, l++);\n\t\t\
    \t}\n\t\t\tif (r & 1) {\n\t\t\t\tauto tmp = newLine;\n\t\t\t\taddSegment(tmp,\
    \ --r);\n\t\t\t}\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t}\n\tstd::pair<lint,\
    \ int> query(int idx) {\n\t\tlint x = cord[idx];\n\t\tidx += n;\n\t\tstd::pair<lint,\
    \ int> res = {LINF, -1};\n\t\twhile (idx) {\n\t\t\tif (chmin(res.first, calc(node[idx],\
    \ x)))\n\t\t\t\tres.second = node[idx].second;\n\t\t\tidx >>= 1;\n\t\t}\n\t\t\
    if (!isMin) res.first = -res.first;\n\t\treturn res;\n\t}\n\tvoid clear() {\n\t\
    \tid = 0;\n\t\tnode.assign(2 * n, {{0, LINF}, -1});\n\t}\n};\n\n/**\n * @title\
    \ Li Chao Tree\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate <bool isMin>\n\
    class LiChaoTree {\n\tint n, id;\n\tstd::vector<std::tuple<lint, lint, lint>>\
    \ interval;\n\tstd::vector<std::pair<LP, int>> node;\n\tstd::vector<lint> cord;\n\
    \tlint calc(std::pair<LP, int> l, lint x) {\n\t\treturn l.first.first * x + l.first.second;\n\
    \t}\n\tvoid addSegment(std::pair<LP, int>& newLine, lint cnt) {\n\t\tlint l =\
    \ std::get<0>(interval[cnt]), m = std::get<1>(interval[cnt]),\n\t\t\t r = std::get<2>(interval[cnt]);\n\
    \t\tif (n <= cnt) {\n\t\t\tif (calc(node[cnt], l) > calc(newLine, l)) node[cnt]\
    \ = newLine;\n\t\t\treturn;\n\t\t}\n\t\tif (calc(node[cnt], l) < calc(newLine,\
    \ l) &&\n\t\t\tcalc(node[cnt], r) < calc(newLine, r))\n\t\t\treturn;\n\t\tif (calc(node[cnt],\
    \ l) > calc(newLine, l) &&\n\t\t\tcalc(node[cnt], r) > calc(newLine, r)) {\n\t\
    \t\tnode[cnt] = newLine;\n\t\t\treturn;\n\t\t}\n\t\tif (calc(node[cnt], m) > calc(newLine,\
    \ m))\n\t\t\tstd::swap(node[cnt], newLine);\n\t\tif (calc(node[cnt], l) > calc(newLine,\
    \ l))\n\t\t\taddSegment(newLine, cnt << 1);\n\t\telse\n\t\t\taddSegment(newLine,\
    \ cnt << 1 | 1);\n\t}\n\n  public:\n\tLiChaoTree() {}\n\tLiChaoTree(std::vector<lint>\
    \ vec) { init(vec); }\n\tvoid init(std::vector<lint> con) {\n\t\tinterval.clear();\n\
    \t\tnode.clear();\n\t\tcord.clear();\n\t\tn = 1;\n\t\tid = 0;\n\t\tcon.emplace_back(con.back()\
    \ + 1);\n\t\twhile (n < (int)con.size()) n *= 2;\n\t\twhile ((int)con.size() <\
    \ n + 1) con.emplace_back(con.back() + 1);\n\t\tnode.assign(2 * n, {{0, LINF},\
    \ -1});\n\t\tinterval.emplace_back(0, 0, 0);\n\t\tfor (int range = n; range; range\
    \ >>= 1) {\n\t\t\tfor (int i = 0; i < n; i += range) {\n\t\t\t\tif (range == 1)\n\
    \t\t\t\t\tinterval.emplace_back(con[i], 0, con[i + range]);\n\t\t\t\telse\n\t\t\
    \t\t\tinterval.emplace_back(con[i], con[i + range / 2],\n\t\t\t\t\t\t\t\t\t\t\
    \  con[i + range]);\n\t\t\t}\n\t\t}\n\t\tcord = con;\n\t}\n\tvoid addLine(lint\
    \ a, lint b) {\n\t\tstd::pair<LP, int> newLine = {{a, b}, id++};\n\t\tif (!isMin)\
    \ {\n\t\t\tnewLine.first.first *= -1;\n\t\t\tnewLine.first.second *= -1;\n\t\t\
    }\n\t\taddSegment(newLine, 1);\n\t}\n\tvoid addSegment(int l, int r, lint a, lint\
    \ b) {\n\t\tl += n;\n\t\tr += n;\n\t\tstd::pair<LP, int> newLine = {{a, b}, id++};\n\
    \t\tif (!isMin) {\n\t\t\tnewLine.first.first *= -1;\n\t\t\tnewLine.first.second\
    \ *= -1;\n\t\t}\n\t\twhile (l < r) {\n\t\t\tif (l & 1) {\n\t\t\t\tauto tmp = newLine;\n\
    \t\t\t\taddSegment(tmp, l++);\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tauto tmp =\
    \ newLine;\n\t\t\t\taddSegment(tmp, --r);\n\t\t\t}\n\t\t\tl >>= 1;\n\t\t\tr >>=\
    \ 1;\n\t\t}\n\t}\n\tstd::pair<lint, int> query(int idx) {\n\t\tlint x = cord[idx];\n\
    \t\tidx += n;\n\t\tstd::pair<lint, int> res = {LINF, -1};\n\t\twhile (idx) {\n\
    \t\t\tif (chmin(res.first, calc(node[idx], x)))\n\t\t\t\tres.second = node[idx].second;\n\
    \t\t\tidx >>= 1;\n\t\t}\n\t\tif (!isMin) res.first = -res.first;\n\t\treturn res;\n\
    \t}\n\tvoid clear() {\n\t\tid = 0;\n\t\tnode.assign(2 * n, {{0, LINF}, -1});\n\
    \t}\n};\n\n/**\n * @title Li Chao Tree\n */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/LiChaoTree.hpp
  requiredBy: []
  timestamp: '2021-08-31 00:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/line_add_get_min_LiChaoTree.test.cpp
  - test/yosupo/segment_add_get_min.test.cpp
documentation_of: data-structure/LiChaoTree.hpp
layout: document
redirect_from:
- /library/data-structure/LiChaoTree.hpp
- /library/data-structure/LiChaoTree.hpp.html
title: Li Chao Tree
---
