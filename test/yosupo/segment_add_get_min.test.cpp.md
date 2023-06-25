---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: basic/template.hpp
    title: basic/template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/LiChaoTree.hpp
    title: Li Chao Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/yosupo/segment_add_get_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n#line 2 \"basic/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n#pragma GCC optimize(\"\
    O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n#include <string.h>\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define rep(i,\
    \ n) for (int i = 0; i < int(n); i++)\n#define REP(i, n) for (int i = 1; i <=\
    \ int(n); i++)\n#define all(V) V.begin(), V.end()\n\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing uint = unsigned int;\nusing lint = long long;\n\
    using ulint = unsigned long long;\nusing IP = std::pair<int, int>;\nusing LP =\
    \ std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF\
    \ = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON * 10;\nconstexpr double\
    \ PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique :\
    \ public std::priority_queue<T, std::vector<T>, std::greater<T>> {};\nint popcount(uint\
    \ x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n#else\n#ifndef\
    \ __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\tx = (x & 0x55555555)\
    \ + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >> 2 & 0x33333333);\n\t\
    x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x & 0x00ff00ff) + (x >>\
    \ 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);\n}\ntemplate\
    \ <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f\
    \ = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(n,\
    \ make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class U, class\
    \ Stream>\nStream& operator>>(Stream& ist, std::pair<T, U>& x) {\n\treturn ist\
    \ >> x.first >> x.second;\n}\ntemplate <class T, class U, class Stream>\nStream&\
    \ operator<<(Stream& ost, const std::pair<T, U>& x) {\n\treturn ost << x.first\
    \ << \" \" << x.second;\n}\ntemplate <class Container,\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nauto operator>>(std::istream&\
    \ ist, Container& cont)\n\t-> decltype(typename Container::iterator(), std::cin)&\
    \ {\n\tContainer tmp;\n\twhile (true) {\n\t\ttypename Container::value_type t;\n\
    \t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\tif (getchar() == '\\n') break;\n\t\
    }\n\tcont = Container(std::move(tmp));\n\treturn ist;\n}\ntemplate <class Container,\
    \ class Stream,\n\t\t  std::enable_if_t<!std::is_same<Container, std::string>::value,\
    \ std::nullptr_t> = nullptr>\nauto operator<<(Stream& ost, const Container& cont)\n\
    \t-> decltype(typename Container::iterator(), ost)& {\n\tfor (auto it = cont.begin();\
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
    }\n#line 3 \"data-structure/LiChaoTree.hpp\"\ntemplate <bool isMin>\nclass LiChaoTree\
    \ {\n\tint n, id;\n\tstd::vector<std::tuple<lint, lint, lint>> interval;\n\tstd::vector<std::pair<LP,\
    \ int>> node;\n\tstd::vector<lint> cord;\n\tstatic lint calc(std::pair<LP, int>\
    \ l, lint x) { return l.first.first * x + l.first.second; }\n\tvoid addSegment(std::pair<LP,\
    \ int>& newLine, lint cnt) {\n\t\tlint l = std::get<0>(interval[cnt]), m = std::get<1>(interval[cnt]),\n\
    \t\t\t r = std::get<2>(interval[cnt]);\n\t\tif (n <= cnt) {\n\t\t\tif (calc(node[cnt],\
    \ l) > calc(newLine, l)) node[cnt] = newLine;\n\t\t\treturn;\n\t\t}\n\t\tif (calc(node[cnt],\
    \ l) < calc(newLine, l) && calc(node[cnt], r) < calc(newLine, r)) return;\n\t\t\
    if (calc(node[cnt], l) > calc(newLine, l) && calc(node[cnt], r) > calc(newLine,\
    \ r)) {\n\t\t\tnode[cnt] = newLine;\n\t\t\treturn;\n\t\t}\n\t\tif (calc(node[cnt],\
    \ m) > calc(newLine, m)) std::swap(node[cnt], newLine);\n\t\tif (calc(node[cnt],\
    \ l) > calc(newLine, l))\n\t\t\taddSegment(newLine, cnt << 1);\n\t\telse\n\t\t\
    \taddSegment(newLine, cnt << 1 | 1);\n\t}\n\n  public:\n\tLiChaoTree(const std::vector<lint>&\
    \ vec) { init(vec); }\n\tLiChaoTree(std::vector<lint>&& vec) { init(std::forward<std::vector<lint>>(vec));\
    \ }\n\tvoid init(const std::vector<lint>& vec) {\n\t\tstd::vector<lint> tmp =\
    \ vec;\n\t\tinit(std::forward<std::vector<lint>>(tmp));\n\t}\n\tvoid init(std::vector<lint>&&\
    \ vec) {\n\t\tinterval.clear();\n\t\tnode.clear();\n\t\tcord.clear();\n\t\tn =\
    \ 1;\n\t\tid = 0;\n\t\tvec.emplace_back(vec.back() + 1);\n\t\twhile (n < (int)vec.size())\
    \ n *= 2;\n\t\twhile ((int)vec.size() < n + 1) vec.emplace_back(vec.back() + 1);\n\
    \t\tnode.assign(2 * n, {{0, LINF}, -1});\n\t\tinterval.emplace_back(0, 0, 0);\n\
    \t\tfor (int range = n; range; range >>= 1) {\n\t\t\tfor (int i = 0; i < n; i\
    \ += range) {\n\t\t\t\tif (range == 1)\n\t\t\t\t\tinterval.emplace_back(vec[i],\
    \ 0, vec[i + range]);\n\t\t\t\telse\n\t\t\t\t\tinterval.emplace_back(vec[i], vec[i\
    \ + range / 2], vec[i + range]);\n\t\t\t}\n\t\t}\n\t\tcord = vec;\n\t}\n\tvoid\
    \ addLine(lint a, lint b) {\n\t\tstd::pair<LP, int> newLine = {{a, b}, id++};\n\
    \t\tif (!isMin) {\n\t\t\tnewLine.first.first *= -1;\n\t\t\tnewLine.first.second\
    \ *= -1;\n\t\t}\n\t\taddSegment(newLine, 1);\n\t}\n\tvoid addSegment(int l, int\
    \ r, lint a, lint b) {\n\t\tl += n;\n\t\tr += n;\n\t\tstd::pair<LP, int> newLine\
    \ = {{a, b}, id++};\n\t\tif (!isMin) {\n\t\t\tnewLine.first.first *= -1;\n\t\t\
    \tnewLine.first.second *= -1;\n\t\t}\n\t\twhile (l < r) {\n\t\t\tif (l & 1) {\n\
    \t\t\t\tauto tmp = newLine;\n\t\t\t\taddSegment(tmp, l++);\n\t\t\t}\n\t\t\tif\
    \ (r & 1) {\n\t\t\t\tauto tmp = newLine;\n\t\t\t\taddSegment(tmp, --r);\n\t\t\t\
    }\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t}\n\tstd::pair<lint, int> query(int\
    \ idx) const {\n\t\tlint x = cord[idx];\n\t\tidx += n;\n\t\tstd::pair<lint, int>\
    \ res = {LINF, -1};\n\t\twhile (idx) {\n\t\t\tif (chmin(res.first, calc(node[idx],\
    \ x))) res.second = node[idx].second;\n\t\t\tidx >>= 1;\n\t\t}\n\t\tif (!isMin)\
    \ res.first = -res.first;\n\t\treturn res;\n\t}\n\tvoid clear() {\n\t\tid = 0;\n\
    \t\tnode.assign(2 * n, {{0, LINF}, -1});\n\t}\n};\n\n/**\n * @title Li Chao Tree\n\
    \ */\n#line 4 \"test/yosupo/segment_add_get_min.test.cpp\"\nint n, q, l[200010],\
    \ r[200010], a[200010];\nlint b[200010];\nstd::vector<std::pair<IP, std::pair<int,\
    \ lint>>> vec;\nstd::vector<lint> cord;\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\
    \trep(i, n) {\n\t\tscanf(\"%d%d%d%lld\", l + i, r + i, a + i, b + i);\n\t\tcord.emplace_back(l[i]);\n\
    \t\tcord.emplace_back(r[i]);\n\t}\n\trep(i, q) {\n\t\tint type;\n\t\tscanf(\"\
    %d\", &type);\n\t\tif (type == 0) {\n\t\t\tint l, r, a;\n\t\t\tlint b;\n\t\t\t\
    scanf(\"%d%d%d%lld\", &l, &r, &a, &b);\n\t\t\tvec.push_back({{l, r}, {a, b}});\n\
    \t\t\tcord.emplace_back(l);\n\t\t\tcord.emplace_back(r);\n\t\t} else {\n\t\t\t\
    int p;\n\t\t\tscanf(\"%d\", &p);\n\t\t\tvec.push_back({{p, INF}, {0, 0}});\n\t\
    \t\tcord.emplace_back(p);\n\t\t}\n\t}\n\tstd::sort(all(cord));\n\tcord.erase(std::unique(all(cord)),\
    \ cord.end());\n\trep(i, n) {\n\t\tl[i] = std::lower_bound(all(cord), l[i]) -\
    \ cord.begin();\n\t\tr[i] = std::lower_bound(all(cord), r[i]) - cord.begin();\n\
    \t}\n\tfor (auto& i : vec) {\n\t\ti.first.first =\n\t\t\tstd::lower_bound(all(cord),\
    \ i.first.first) - cord.begin();\n\t\tif (i.first.second != INF)\n\t\t\ti.first.second\
    \ =\n\t\t\t\tstd::lower_bound(all(cord), i.first.second) - cord.begin();\n\t}\n\
    \tLiChaoTree<true> lct(cord);\n\trep(i, n) lct.addSegment(l[i], r[i], a[i], b[i]);\n\
    \tfor (auto i : vec) {\n\t\tif (i.first.second == INF) {\n\t\t\tlint ans = lct.query(i.first.first).first;\n\
    \t\t\tif (ans == LINF)\n\t\t\t\tputs(\"INFINITY\");\n\t\t\telse\n\t\t\t\tprintf(\"\
    %lld\\n\", ans);\n\t\t} else\n\t\t\tlct.addSegment(i.first.first, i.first.second,\
    \ i.second.first,\n\t\t\t\t\t\t   i.second.second);\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"../../data-structure/LiChaoTree.hpp\"\n#include \"../../basic/template.hpp\"\
    \nint n, q, l[200010], r[200010], a[200010];\nlint b[200010];\nstd::vector<std::pair<IP,\
    \ std::pair<int, lint>>> vec;\nstd::vector<lint> cord;\nint main() {\n\tscanf(\"\
    %d%d\", &n, &q);\n\trep(i, n) {\n\t\tscanf(\"%d%d%d%lld\", l + i, r + i, a + i,\
    \ b + i);\n\t\tcord.emplace_back(l[i]);\n\t\tcord.emplace_back(r[i]);\n\t}\n\t\
    rep(i, q) {\n\t\tint type;\n\t\tscanf(\"%d\", &type);\n\t\tif (type == 0) {\n\t\
    \t\tint l, r, a;\n\t\t\tlint b;\n\t\t\tscanf(\"%d%d%d%lld\", &l, &r, &a, &b);\n\
    \t\t\tvec.push_back({{l, r}, {a, b}});\n\t\t\tcord.emplace_back(l);\n\t\t\tcord.emplace_back(r);\n\
    \t\t} else {\n\t\t\tint p;\n\t\t\tscanf(\"%d\", &p);\n\t\t\tvec.push_back({{p,\
    \ INF}, {0, 0}});\n\t\t\tcord.emplace_back(p);\n\t\t}\n\t}\n\tstd::sort(all(cord));\n\
    \tcord.erase(std::unique(all(cord)), cord.end());\n\trep(i, n) {\n\t\tl[i] = std::lower_bound(all(cord),\
    \ l[i]) - cord.begin();\n\t\tr[i] = std::lower_bound(all(cord), r[i]) - cord.begin();\n\
    \t}\n\tfor (auto& i : vec) {\n\t\ti.first.first =\n\t\t\tstd::lower_bound(all(cord),\
    \ i.first.first) - cord.begin();\n\t\tif (i.first.second != INF)\n\t\t\ti.first.second\
    \ =\n\t\t\t\tstd::lower_bound(all(cord), i.first.second) - cord.begin();\n\t}\n\
    \tLiChaoTree<true> lct(cord);\n\trep(i, n) lct.addSegment(l[i], r[i], a[i], b[i]);\n\
    \tfor (auto i : vec) {\n\t\tif (i.first.second == INF) {\n\t\t\tlint ans = lct.query(i.first.first).first;\n\
    \t\t\tif (ans == LINF)\n\t\t\t\tputs(\"INFINITY\");\n\t\t\telse\n\t\t\t\tprintf(\"\
    %lld\\n\", ans);\n\t\t} else\n\t\t\tlct.addSegment(i.first.first, i.first.second,\
    \ i.second.first,\n\t\t\t\t\t\t   i.second.second);\n\t}\n}\n"
  dependsOn:
  - data-structure/LiChaoTree.hpp
  - basic/template.hpp
  isVerificationFile: true
  path: test/yosupo/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2023-06-25 16:24:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/segment_add_get_min.test.cpp
- /verify/test/yosupo/segment_add_get_min.test.cpp.html
title: test/yosupo/segment_add_get_min.test.cpp
---
