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
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Li Chao Tree
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifdef ONLINE_JUDGE\n#pragma GCC target(\"avx512f\")\n#else\n#pragma GCC target(\"\
    avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <string.h>\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cfloat>\n#include <climits>\n#include <cmath>\n\
    #include <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define rep(i,\
    \ n) for (int i = 0; i < int(n); i++)\n#define REP(i, n) for (int i = 1; i <=\
    \ int(n); i++)\n#define all(V) V.begin(), V.end()\n\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing uint = unsigned int;\nusing lint = long long;\n\
    using ulint = unsigned long long;\nusing P = std::pair<int, int>;\nusing LP =\
    \ std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF\
    \ = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr double PI =\
    \ 3.141592653589793238462643383279;\n\nnamespace std {\n\ttemplate <template <class...>\
    \ class Temp, class T>\n\tclass is_template_with_type_of : public std::false_type\
    \ {};\n\ttemplate <template <class...> class Temp, class... Args>\n\tclass is_template_with_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n\ttemplate <template <auto...>\
    \ class Temp, class T>\n\tclass is_template_with_non_type_of : public std::false_type\
    \ {};\n\ttemplate <template <auto...> class Temp, auto... Args>\n\tclass is_template_with_non_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n};\t// namespace std\ntemplate\
    \ <class T>\nclass prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {\n};\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f)\
    \ {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class\
    \ U>\nconstexpr inline bool chmax(T& lhs, const U& rhs) {\n\tif (lhs < rhs) {\n\
    \t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class T,\
    \ class U>\nconstexpr inline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\nconstexpr inline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\t\
    b = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) { return a /\
    \ gcd(a, b) * b; }\nconstexpr bool isprime(lint n) {\n\tif (n == 1) return false;\n\
    \tfor (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\
    \treturn true;\n}\ntemplate <class T>\nconstexpr T mypow(T a, lint b) {\n\tT res(1);\n\
    \twhile (true) {\n\t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\
    \t\ta *= a;\n\t}\n\treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint\
    \ m) {\n\ta %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres\
    \ *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t}\n\
    \treturn res;\n}\ntemplate <class T>\nconstexpr void printArray(const std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <class T>\nconstexpr void printArray(T l, T r, char split = ' ') {\n\tT rprev\
    \ = std::prev(r);\n\tfor (T i = l; i != r; i++) {\n\t\tstd::cout << *i;\n\t\t\
    std::cout << (i == rprev ? '\\n' : split);\n\t}\n}\nconstexpr LP extGcd(lint a,\
    \ lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first,\
    \ s.second);\n\ts.second -= a / b * s.first;\n\treturn s;\n}\nconstexpr LP ChineseRem(const\
    \ lint& b1, const lint& m1, const lint& b2, const lint& m2) {\n\tlint p = extGcd(m1,\
    \ m2).first;\n\tlint tmp = (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1\
    \ * m2) % (m1 * m2);\n\treturn std::make_pair(r, m1 * m2);\n}\nint LCS(const std::string&\
    \ a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size()\
    \ + 1);\n\trep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j],\
    \ dp[i][j]);\n\t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i\
    \ + 1][j + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\
    \t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn\
    \ dp[a.size()][b.size()];\n}\n#line 3 \"data-structure/LiChaoTree.hpp\"\ntemplate\
    \ <bool isMin>\nclass LiChaoTree {\n\tint n, id;\n\tstd::vector<std::tuple<lint,\
    \ lint, lint>> interval;\n\tstd::vector<std::pair<LP, int>> node;\n\tstd::vector<lint>\
    \ cord;\n\tlint calc(std::pair<LP, int> l, lint x) {\n\t\treturn l.first.first\
    \ * x + l.first.second;\n\t}\n\tvoid addSegment(std::pair<LP, int>& newLine, lint\
    \ cnt) {\n\t\tlint l = std::get<0>(interval[cnt]), m = std::get<1>(interval[cnt]),\n\
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
  timestamp: '2021-01-16 15:12:02+09:00'
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
