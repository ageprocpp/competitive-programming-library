---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/IntervalSegTree.hpp
    title: Interval Segment Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifndef __clang__\n#ifdef ONLINE_JUDGE\n#pragma GCC target(\"avx512f\")\n#elif\
    \ defined EVAL\n#else\n#pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"\
    O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n#include <string.h>\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n#define rep(i, n) for (int i = 0; i <\
    \ int(n); i++)\n#define REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V)\
    \ V.begin(), V.end()\n\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using uint = unsigned int;\nusing lint = long long;\nusing ulint = unsigned long\
    \ long;\nusing IP = std::pair<int, int>;\nusing LP = std::pair<lint, lint>;\n\n\
    constexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\nconstexpr\
    \ double eps = DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
    \ntemplate <class T>\nclass prique : public std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> {\n};\nint popcount(uint x) {\n#if __cplusplus >= 202002L\n\
    \treturn std::popcount(x);\n#else\n#ifndef __clang__\n\treturn __builtin_popcount(x);\n\
    #endif\n#endif\n\tx = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333)\
    \ + (x >> 2 & 0x33333333);\n\tx = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\t\
    x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x\
    \ >> 16 & 0x0000ffff);\n}\ntemplate <class F>\ninline constexpr decltype(auto)\
    \ lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\
    \treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\ntemplate <class\
    \ T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <class T, class... Args>\nconstexpr auto make_vec(size_t n, Args&&...\
    \ args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\nstd::istream& operator>>(std::istream& ist, std::pair<T,\
    \ U>& x) {\n\treturn ist >> x.first >> x.second;\n}\ntemplate <class T, class\
    \ U>\nstd::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& x) {\n\
    \treturn ost << x.first << \" \" << x.second;\n}\ntemplate <class T, class U>\n\
    constexpr inline bool chmax(T& lhs, const U& rhs) noexcept {\n\tif (lhs < rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class\
    \ T, class U>\nconstexpr inline bool chmin(T& lhs, const U& rhs) noexcept {\n\t\
    if (lhs > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    constexpr inline lint gcd(lint a, lint b) noexcept {\n\twhile (b) {\n\t\tlint\
    \ c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint\
    \ a, lint b) noexcept { return a / gcd(a, b) * b; }\nconstexpr bool isprime(lint\
    \ n) noexcept {\n\tif (n == 1) return false;\n\tfor (int i = 2; i * i <= n; i++)\
    \ {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\ntemplate <class\
    \ T>\nconstexpr T mypow(T a, lint b) noexcept {\n\tT res(1);\n\twhile (true) {\n\
    \t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\t}\n\
    \treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint m) noexcept {\n\t\
    a %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\
    \tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n\
    }\ntemplate <class T>\nconstexpr void printArray(const std::vector<T>& vec, char\
    \ split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout\
    \ << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate <class InputIter>\n\
    constexpr void printArray(InputIter l, InputIter r, char split = ' ') {\n\tauto\
    \ rprev = std::prev(r);\n\tfor (auto i = l; i != r; i++) {\n\t\tstd::cout << *i;\n\
    \t\tstd::cout << (i == rprev ? '\\n' : split);\n\t}\n}\nLP extGcd(lint a, lint\
    \ b) noexcept {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b, a % b);\n\t\
    std::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\treturn s;\n}\n\
    LP ChineseRem(const lint& b1, const lint& m1, const lint& b2,\n\t\t\t  const lint&\
    \ m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\tlint g = gcd(m1, m2), l = m1 /\
    \ g * m2;\n\tlint tmp = (b2 - b1) / g * p.first % (m2 / g);\n\tlint r = (b1 +\
    \ m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const std::string& a, const\
    \ std::string& b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\t\
    rep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\
    \t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j\
    \ + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\
    \t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn\
    \ dp[a.size()][b.size()];\n}\ntemplate <class T, std::enable_if_t<std::is_convertible<int,\
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
    data-structure/SegTree.hpp\"\ntemplate <class T, T (*nodef)(const T&, const T&)>\n\
    class SegTree {\n  protected:\n\tunsigned int n = 1, rank = 0;\n\tstd::vector<T>\
    \ node;\n\tT ident;\n\n  public:\n\tSegTree(unsigned int m, T e_) : ident(e_)\
    \ {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2\
    \ * n, ident);\n\t}\n\tSegTree(unsigned int m, T init, T e_) : ident(e_) {\n\t\
    \twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n,\
    \ ident);\n\t\tfor (unsigned int i = n; i < 2 * n; i++) node[i] = init;\n\t\t\
    for (unsigned int i = n - 1; i > 0; i--)\n\t\t\tnode[i] = nodef(node[i << 1],\
    \ node[i << 1 | 1]);\n\t}\n\ttemplate <class U>\n\tSegTree(const std::vector<U>&\
    \ initvec, T e_) : ident(e_) {\n\t\tunsigned int m = initvec.size();\n\t\twhile\
    \ (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\
    \t\tfor (unsigned int i = n; i < 2 * n; i++) {\n\t\t\tif (i - n < m) node[i] =\
    \ initvec[i - n];\n\t\t}\n\t\tfor (unsigned int i = n - 1; i > 0; i--)\n\t\t\t\
    node[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\t}\n\tvoid update(int i, T\
    \ x) {\n\t\ti += n;\n\t\tnode[i] = x;\n\t\twhile (i != 1) {\n\t\t\ti >>= 1;\n\t\
    \t\tnode[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t\t}\n\t}\n\tT query(int\
    \ l, int r) const {\n\t\tl += n;\n\t\tr += n;\n\t\tT ls = ident, rs = ident;\n\
    \t\twhile (l < r) {\n\t\t\tif (l & 1) ls = nodef(ls, node[l++]);\n\t\t\tif (r\
    \ & 1) rs = nodef(node[--r], rs);\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\t\
    return nodef(ls, rs);\n\t}\n\tconst T& operator[](const int& x) const { return\
    \ node[n + x]; }\n\tT queryForAll() const { return node[1]; }\n\n  private:\n\t\
    template <class F>\n\tint max_right(int st, F& check, T& acc, int k, int l, int\
    \ r) const {\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\t\
    return check(acc) ? -1 : k - n;\n\t\t}\n\t\tint m = (l + r) >> 1;\n\t\tif (m <=\
    \ st) return max_right(st, check, acc, (k << 1) | 1, m, r);\n\t\tif (st <= l &&\
    \ check(nodef(acc, node[k]))) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\treturn\
    \ -1;\n\t\t}\n\t\tint vl = max_right(st, check, acc, k << 1, l, m);\n\t\tif (vl\
    \ != -1) return vl;\n\t\treturn max_right(st, check, acc, (k << 1) | 1, m, r);\n\
    \t}\n\n  public:\n\ttemplate <class F>\n\tint max_right(int st, F check) const\
    \ {\n\t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n\
    \ttemplate <bool (*check)(const T&)>\n\tint max_right(int st) const {\n\t\tT acc\
    \ = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n};\nnamespace\
    \ {\n\tlint RSQ_nodef(const lint& lhs, const lint& rhs) {\n\t\treturn lhs + rhs;\n\
    \t}\n\tlint RMiQ_nodef(const lint& lhs, const lint& rhs) {\n\t\treturn std::min(lhs,\
    \ rhs);\n\t}\n\tlint RMaQ_nodef(const lint& lhs, const lint& rhs) {\n\t\treturn\
    \ std::max(lhs, rhs);\n\t}\n}  // namespace\n\nclass RSQ : public SegTree<lint,\
    \ RSQ_nodef> {\n\tusing Base = SegTree<lint, RSQ_nodef>;\n\n  public:\n\ttemplate\
    \ <class... Args>\n\tRSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0)\
    \ {}\n};\nclass RMiQ : public SegTree<lint, RMiQ_nodef> {\n\tusing Base = SegTree<lint,\
    \ RMiQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\tRMiQ(Args&&... args)\
    \ : Base(std::forward<Args>(args)..., LINF) {}\n};\nclass RMaQ : public SegTree<lint,\
    \ RMaQ_nodef> {\n\tusing Base = SegTree<lint, RMaQ_nodef>;\n\n  public:\n\ttemplate\
    \ <class... Args>\n\tRMaQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ -LINF) {}\n};\n\n/**\n * @title Segment Tree\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate <class T, T (*nodef)(const\
    \ T&, const T&)>\nclass SegTree {\n  protected:\n\tunsigned int n = 1, rank =\
    \ 0;\n\tstd::vector<T> node;\n\tT ident;\n\n  public:\n\tSegTree(unsigned int\
    \ m, T e_) : ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\
    \t}\n\t\tnode.resize(2 * n, ident);\n\t}\n\tSegTree(unsigned int m, T init, T\
    \ e_) : ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\
    \t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n; i++) node[i]\
    \ = init;\n\t\tfor (unsigned int i = n - 1; i > 0; i--)\n\t\t\tnode[i] = nodef(node[i\
    \ << 1], node[i << 1 | 1]);\n\t}\n\ttemplate <class U>\n\tSegTree(const std::vector<U>&\
    \ initvec, T e_) : ident(e_) {\n\t\tunsigned int m = initvec.size();\n\t\twhile\
    \ (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\
    \t\tfor (unsigned int i = n; i < 2 * n; i++) {\n\t\t\tif (i - n < m) node[i] =\
    \ initvec[i - n];\n\t\t}\n\t\tfor (unsigned int i = n - 1; i > 0; i--)\n\t\t\t\
    node[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\t}\n\tvoid update(int i, T\
    \ x) {\n\t\ti += n;\n\t\tnode[i] = x;\n\t\twhile (i != 1) {\n\t\t\ti >>= 1;\n\t\
    \t\tnode[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t\t}\n\t}\n\tT query(int\
    \ l, int r) const {\n\t\tl += n;\n\t\tr += n;\n\t\tT ls = ident, rs = ident;\n\
    \t\twhile (l < r) {\n\t\t\tif (l & 1) ls = nodef(ls, node[l++]);\n\t\t\tif (r\
    \ & 1) rs = nodef(node[--r], rs);\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\t\
    return nodef(ls, rs);\n\t}\n\tconst T& operator[](const int& x) const { return\
    \ node[n + x]; }\n\tT queryForAll() const { return node[1]; }\n\n  private:\n\t\
    template <class F>\n\tint max_right(int st, F& check, T& acc, int k, int l, int\
    \ r) const {\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\t\
    return check(acc) ? -1 : k - n;\n\t\t}\n\t\tint m = (l + r) >> 1;\n\t\tif (m <=\
    \ st) return max_right(st, check, acc, (k << 1) | 1, m, r);\n\t\tif (st <= l &&\
    \ check(nodef(acc, node[k]))) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\treturn\
    \ -1;\n\t\t}\n\t\tint vl = max_right(st, check, acc, k << 1, l, m);\n\t\tif (vl\
    \ != -1) return vl;\n\t\treturn max_right(st, check, acc, (k << 1) | 1, m, r);\n\
    \t}\n\n  public:\n\ttemplate <class F>\n\tint max_right(int st, F check) const\
    \ {\n\t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n\
    \ttemplate <bool (*check)(const T&)>\n\tint max_right(int st) const {\n\t\tT acc\
    \ = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n};\nnamespace\
    \ {\n\tlint RSQ_nodef(const lint& lhs, const lint& rhs) {\n\t\treturn lhs + rhs;\n\
    \t}\n\tlint RMiQ_nodef(const lint& lhs, const lint& rhs) {\n\t\treturn std::min(lhs,\
    \ rhs);\n\t}\n\tlint RMaQ_nodef(const lint& lhs, const lint& rhs) {\n\t\treturn\
    \ std::max(lhs, rhs);\n\t}\n}  // namespace\n\nclass RSQ : public SegTree<lint,\
    \ RSQ_nodef> {\n\tusing Base = SegTree<lint, RSQ_nodef>;\n\n  public:\n\ttemplate\
    \ <class... Args>\n\tRSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0)\
    \ {}\n};\nclass RMiQ : public SegTree<lint, RMiQ_nodef> {\n\tusing Base = SegTree<lint,\
    \ RMiQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\tRMiQ(Args&&... args)\
    \ : Base(std::forward<Args>(args)..., LINF) {}\n};\nclass RMaQ : public SegTree<lint,\
    \ RMaQ_nodef> {\n\tusing Base = SegTree<lint, RMaQ_nodef>;\n\n  public:\n\ttemplate\
    \ <class... Args>\n\tRMaQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ -LINF) {}\n};\n\n/**\n * @title Segment Tree\n */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/SegTree.hpp
  requiredBy:
  - data-structure/IntervalSegTree.hpp
  timestamp: '2021-05-20 00:07:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_B.test.cpp
documentation_of: data-structure/SegTree.hpp
layout: document
redirect_from:
- /library/data-structure/SegTree.hpp
- /library/data-structure/SegTree.hpp.html
title: Segment Tree
---