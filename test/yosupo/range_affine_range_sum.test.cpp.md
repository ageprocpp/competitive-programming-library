---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic/StaticModInt.hpp
    title: StaticModInt
  - icon: ':heavy_check_mark:'
    path: data-structure/IntervalSegTree.hpp
    title: Interval Segment Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/SegTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: other/type_traits.hpp
    title: other/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n#ifdef ONLINE_JUDGE\n#pragma\
    \ GCC target(\"avx512f\")\n#elif defined EVAL\n#else\n#pragma GCC target(\"avx2\"\
    )\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#endif\n#include <string.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cfloat>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define rep(i,\
    \ n) for (int i = 0; i < int(n); i++)\n#define REP(i, n) for (int i = 1; i <=\
    \ int(n); i++)\n#define all(V) V.begin(), V.end()\n\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing uint = unsigned int;\nusing lint = long long;\n\
    using ulint = unsigned long long;\nusing IP = std::pair<int, int>;\nusing LP =\
    \ std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF\
    \ = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr double PI =\
    \ 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique : public\
    \ std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\nint popcount(uint\
    \ x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n#else\n#ifndef\
    \ __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\tx = (x & 0x55555555)\
    \ + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >> 2 & 0x33333333);\n\t\
    x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x & 0x00ff00ff) + (x >>\
    \ 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);\n}\ntemplate\
    \ <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f\
    \ = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class\
    \ U>\nstd::istream& operator>>(std::istream& ist, std::pair<T, U>& x) {\n\treturn\
    \ ist >> x.first >> x.second;\n}\ntemplate <class T, class U>\nstd::ostream& operator<<(std::ostream&\
    \ ost, const std::pair<T, U>& x) {\n\treturn ost << x.first << \" \" << x.second;\n\
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
    \ m) noexcept {\n\ta %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\
    \t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\
    \t}\n\treturn res;\n}\ntemplate <class T>\nconstexpr void printArray(const std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <class InputIter>\nconstexpr void printArray(InputIter l, InputIter r, char\
    \ split = ' ') {\n\tauto rprev = std::prev(r);\n\tfor (auto i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? '\\n' : split);\n\t\
    }\n}\nLP extGcd(lint a, lint b) noexcept {\n\tif (b == 0) return {1, 0};\n\tLP\
    \ s = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b\
    \ * s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const\
    \ lint& b2,\n\t\t\t  const lint& m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\t\
    lint g = gcd(m1, m2), l = m1 / g * m2;\n\tlint tmp = (b2 - b1) / g * p.first %\
    \ (m2 / g);\n\tlint r = (b1 + m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const\
    \ std::string& a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size()\
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
    other/type_traits.hpp\"\n\nclass ModInt__Base {};\nclass StaticModInt__Base :\
    \ ModInt__Base {};\nclass DynamicModInt__Base : ModInt__Base {};\n\ntemplate <class\
    \ T>\nclass is_ModInt : public std::is_base_of<ModInt__Base, T> {};\ntemplate\
    \ <class T>\nconstexpr bool is_ModInt_v = is_ModInt<T>::value;\n\ntemplate <class\
    \ T>\nclass is_StaticModInt : public std::is_base_of<StaticModInt__Base, T> {};\n\
    template <class T>\nconstexpr bool is_StaticModInt_v = is_StaticModInt<T>::value;\n\
    \ntemplate <class T>\nclass is_DynamicModInt : public std::is_base_of<DynamicModInt__Base,\
    \ T> {};\ntemplate <class T>\nconstexpr bool is_DynamicModInt_v = is_DynamicModInt<T>::value;\n\
    #line 4 \"algebraic/StaticModInt.hpp\"\ntemplate <uint modulo>\nclass StaticModInt\
    \ : StaticModInt__Base {\n\tstd::conditional_t<(modulo > INT_MAX >> 1), lint,\
    \ int> value;\n\n  public:\n\tstatic constexpr uint mod_value = modulo;\n\tconstexpr\
    \ StaticModInt() : value(0) {}\n\ttemplate <class T,\n\t\t\t  std::enable_if_t<!std::is_convertible<T,\
    \ StaticModInt>::value,\n\t\t\t\t\t\t\t   std::nullptr_t> = nullptr>\n\tconstexpr\
    \ StaticModInt(T value = 0) : value(value) {\n\t\tthis->value =\n\t\t\t(value\
    \ < 0 ? -(-value % modulo) + modulo : lint(value)) % modulo;\n\t}\n\tinline constexpr\
    \ StaticModInt inv() const {\n\t\treturn mypow(*this, modulo - 2);\n\t}\n\tinline\
    \ constexpr operator int() const { return value; }\n\tinline constexpr StaticModInt&\
    \ operator+=(const StaticModInt& x) {\n\t\tvalue = value + x.value;\n\t\tif (value\
    \ >= modulo) value -= modulo;\n\t\treturn *this;\n\t}\n\tinline constexpr StaticModInt&\
    \ operator++() {\n\t\tif (value == modulo - 1)\n\t\t\tvalue = 0;\n\t\telse\n\t\
    \t\tvalue++;\n\t\treturn *this;\n\t}\n\tinline constexpr StaticModInt operator++(int)\
    \ {\n\t\tStaticModInt res = *this;\n\t\t++*this;\n\t\treturn res;\n\t}\n\tinline\
    \ constexpr StaticModInt operator-() const {\n\t\treturn StaticModInt(0) -= *this;\n\
    \t}\n\tinline constexpr StaticModInt& operator-=(const StaticModInt& x) {\n\t\t\
    value -= x.value;\n\t\tif (value < 0) value += modulo;\n\t\treturn *this;\n\t\
    }\n\tinline constexpr StaticModInt& operator--() {\n\t\tif (value == 0)\n\t\t\t\
    value = modulo - 1;\n\t\telse\n\t\t\tvalue--;\n\t\treturn *this;\n\t}\n\tinline\
    \ constexpr StaticModInt operator--(int) {\n\t\tStaticModInt res = *this;\n\t\t\
    --*this;\n\t\treturn res;\n\t}\n\tinline constexpr StaticModInt& operator*=(const\
    \ StaticModInt& x) {\n\t\tvalue = (lint)value * x.value % modulo;\n\t\treturn\
    \ *this;\n\t}\n\tinline constexpr StaticModInt& operator/=(const StaticModInt&\
    \ rhs) {\n\t\treturn *this *= rhs.inv();\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ StaticModInt operator+(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ += rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr StaticModInt& operator+=(const\
    \ T& rhs) {\n\t\treturn operator+=(StaticModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr StaticModInt operator-(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ -= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr StaticModInt& operator-=(const\
    \ T& rhs) {\n\t\treturn operator-=(StaticModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr StaticModInt operator*(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ *= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr StaticModInt& operator*=(const\
    \ T& rhs) {\n\t\treturn operator*=(StaticModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr StaticModInt operator/(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ /= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr StaticModInt& operator/=(const\
    \ T& rhs) {\n\t\treturn operator/=(StaticModInt(rhs));\n\t}\n\tstatic int primitive_root()\
    \ {\n\t\tstatic int p = 0;\n\t\tstatic std::random_device rd;\n\t\tstatic std::mt19937\
    \ mt(rd());\n\t\tstatic std::uniform_int_distribution<> uid(1, modulo - 1);\n\t\
    \tif (p) return 0;\n\n\t\t// use naive factorize due to file size limit\n\t\t\
    std::vector<int> vec;\n\t\tint tmp = modulo - 1;\n\t\tfor (int i = 2; i * i <=\
    \ tmp; i++) {\n\t\t\tif (tmp % i == 0) {\n\t\t\t\tvec.emplace_back(i);\n\t\t\t\
    \tdo {\n\t\t\t\t\ttmp /= i;\n\t\t\t\t} while (tmp % i == 0);\n\t\t\t}\n\t\t}\n\
    \t\tif (tmp != 1) vec.emplace_back(tmp);\n\n\t\tvec.erase(std::unique(all(vec)),\
    \ vec.end());\n\t\twhile (true) {\n\t\t\tp = uid(mt);\n\t\t\tbool f = true;\n\t\
    \t\tfor (const auto& i : vec) {\n\t\t\t\tif (mypow(StaticModInt(p), (modulo -\
    \ 1) / i) == 1) {\n\t\t\t\t\tf = false;\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t\tif (f) return p;\n\t\t}\n\t}\n};\ntemplate <uint modulo>\nstd::istream&\
    \ operator>>(std::istream& ist, StaticModInt<modulo>& x) {\n\tlint a;\n\tist >>\
    \ a;\n\tx = a;\n\treturn ist;\n}\n\n/**\n * @title StaticModInt\n */\n#line 3\
    \ \"data-structure/SegTree.hpp\"\ntemplate <class T, T (*nodef)(const T&, const\
    \ T&)>\nclass SegTree {\n  protected:\n\tunsigned int n = 1, rank = 0;\n\tstd::vector<T>\
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
    \ -LINF) {}\n};\n\n/**\n * @title Segment Tree\n */\n#line 4 \"data-structure/IntervalSegTree.hpp\"\
    \ntemplate <class T, class U, T (*nodef)(const T&, const T&),\n\t\t  void (*lazyf)(U&,\
    \ const U&),\n\t\t  void (*updf)(T&, const U&, const unsigned int&)>\nclass IntervalSegTree\
    \ : public SegTree<T, nodef> {\n\tusing Base = SegTree<T, nodef>;\n\tusing Base::ident;\n\
    \tusing Base::n;\n\tusing Base::node;\n\tusing Base::rank;\n\tstd::vector<U> lazy;\n\
    \tstd::vector<bool> lazyflag;\n\tstd::vector<int> width;\n\tvoid eval(int k) {\n\
    \t\tfor (int i = rank; i > 0; i--) {\n\t\t\tint nk = k >> i;\n\t\t\tif (lazyflag[nk])\
    \ {\n\t\t\t\tupdf(node[2 * nk], lazy[nk], width[2 * nk]);\n\t\t\t\tupdf(node[2\
    \ * nk + 1], lazy[nk], width[2 * nk + 1]);\n\t\t\t\tif (lazyflag[2 * nk])\n\t\t\
    \t\t\tlazyf(lazy[2 * nk], lazy[nk]);\n\t\t\t\telse\n\t\t\t\t\tlazy[2 * nk] = lazy[nk];\n\
    \t\t\t\tif (lazyflag[2 * nk + 1])\n\t\t\t\t\tlazyf(lazy[2 * nk + 1], lazy[nk]);\n\
    \t\t\t\telse\n\t\t\t\t\tlazy[2 * nk + 1] = lazy[nk];\n\t\t\t\tlazyflag[2 * nk]\
    \ = lazyflag[2 * nk + 1] = true;\n\t\t\t\tlazyflag[nk] = false;\n\t\t\t}\n\t\t\
    }\n\t}\n\n  public:\n\tIntervalSegTree(unsigned int m, T e_) : Base(m, T(), e_)\
    \ {\n\t\tlazy.resize(2 * n);\n\t\tlazyflag.resize(2 * n);\n\t\twidth.resize(2\
    \ * n);\n\t\twidth[1] = n;\n\t\tfor (unsigned int i = 2; i < 2 * n; i++) {\n\t\
    \t\twidth[i] = width[i >> 1] >> 1;\n\t\t}\n\t}\n\tIntervalSegTree(unsigned int\
    \ m, T init, T e_) : Base(m, init, e_) {\n\t\tlazy.resize(2 * n);\n\t\tlazyflag.resize(2\
    \ * n);\n\t\twidth.resize(2 * n);\n\t\twidth[1] = n;\n\t\tfor (unsigned int i\
    \ = 2; i < 2 * n; i++) {\n\t\t\twidth[i] = width[i >> 1] >> 1;\n\t\t}\n\t}\n\t\
    IntervalSegTree(const std::vector<T>& initvec, T e_) : Base(initvec, e_) {\n\t\
    \tlazy.resize(2 * n);\n\t\tlazyflag.resize(2 * n);\n\t\twidth.resize(2 * n);\n\
    \t\twidth[1] = n;\n\t\tfor (unsigned int i = 2; i < 2 * n; i++) {\n\t\t\twidth[i]\
    \ = width[i >> 1] >> 1;\n\t\t}\n\t}\n\tvoid update(int i, U x) {\n\t\ti += n;\n\
    \t\teval(i);\n\t\tupdf(node[i], x, width[i]);\n\t\tif (lazyflag[i])\n\t\t\tlazyf(lazy[i],\
    \ x);\n\t\telse {\n\t\t\tlazyflag[i] = true;\n\t\t\tlazy[i] = x;\n\t\t}\n\t\t\
    while (i /= 2) node[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t}\n\tvoid update(int\
    \ l, int r, U x) {\n\t\tl += n, r += n;\n\t\tint nl = l, nr = r;\n\t\twhile (!(nl\
    \ & 1)) nl >>= 1;\n\t\twhile (!(nr & 1)) nr >>= 1;\n\t\tnr--;\n\t\teval(nl), eval(nr);\n\
    \t\twhile (l < r) {\n\t\t\tif (l & 1) {\n\t\t\t\tupdf(node[l], x, width[l]);\n\
    \t\t\t\tif (lazyflag[l])\n\t\t\t\t\tlazyf(lazy[l], x);\n\t\t\t\telse {\n\t\t\t\
    \t\tlazyflag[l] = true;\n\t\t\t\t\tlazy[l] = x;\n\t\t\t\t}\n\t\t\t\tl++;\n\t\t\
    \t}\n\t\t\tif (r & 1) {\n\t\t\t\tr--;\n\t\t\t\tupdf(node[r], x, width[r]);\n\t\
    \t\t\tif (lazyflag[r])\n\t\t\t\t\tlazyf(lazy[r], x);\n\t\t\t\telse {\n\t\t\t\t\
    \tlazyflag[r] = true;\n\t\t\t\t\tlazy[r] = x;\n\t\t\t\t}\n\t\t\t}\n\t\t\tl >>=\
    \ 1, r >>= 1;\n\t\t}\n\t\twhile (nl >>= 1) node[nl] = nodef(node[2 * nl], node[2\
    \ * nl + 1]);\n\t\twhile (nr >>= 1) node[nr] = nodef(node[2 * nr], node[2 * nr\
    \ + 1]);\n\t}\n\tT query(int l, int r) {\n\t\tl += n, r += n, eval(l);\n\t\teval(r\
    \ - 1);\n\t\tT ls = ident, rs = ident;\n\t\twhile (l < r) {\n\t\t\tif (l & 1)\
    \ ls = nodef(ls, node[l++]);\n\t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\t\t\
    \tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\tT operator[](const\
    \ int& x) {\n\t\teval(n + x);\n\t\treturn node[n + x];\n\t}\n\n  private:\n\t\
    template <class F>\n\tint max_right(int st, F& check, T& acc, int k, int l, int\
    \ r) {\n\t\teval(k);\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(acc, node[k]);\n\
    \t\t\treturn check(acc) ? -1 : k - n;\n\t\t}\n\t\tint m = (l + r) >> 1;\n\t\t\
    if (m <= st) return max_right(st, check, acc, (k << 1) | 1, m, r);\n\t\tif (st\
    \ <= l && check(nodef(acc, node[k]))) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\
    \treturn -1;\n\t\t}\n\t\tint vl = max_right(st, check, acc, k << 1, l, m);\n\t\
    \tif (vl != -1) return vl;\n\t\treturn max_right(st, check, acc, (k << 1) | 1,\
    \ m, r);\n\t}\n\n\ttemplate <class F>\n\tint min_left(int st, F& check, T& acc,\
    \ int k, int l, int r) {\n\t\teval(k);\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(node[k],\
    \ acc);\n\t\t\treturn check(acc) ? -1 : k - n + 1;\n\t\t}\n\t\tint m = (l + r)\
    \ >> 1;\n\t\tif (st <= m) return min_left(st, check, acc, k << 1, l, m);\n\t\t\
    if (r <= st && check(nodef(node[k], acc))) {\n\t\t\tacc = nodef(node[k], acc);\n\
    \t\t\treturn -1;\n\t\t}\n\t\tint vr = min_left(st, check, acc, (k << 1) | 1, m,\
    \ r);\n\t\tif (vr != -1) return vr;\n\t\treturn min_left(st, check, acc, k <<\
    \ 1, l, m);\n\t}\n\n  public:\n\ttemplate <class F>\n\tint max_right(int st, F\
    \ check) {\n\t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\
    \t}\n\ttemplate <bool (*check)(const T&)>\n\tint max_right(int st) {\n\t\tT acc\
    \ = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n\n\ttemplate\
    \ <class F>\n\tint min_left(int st, F check) {\n\t\tT acc = ident;\n\t\treturn\
    \ min_left(st, check, acc, 1, 0, n);\n\t}\n\ttemplate <bool (*check)(const T&)>\n\
    \tint min_left(int st) {\n\t\tT acc = ident;\n\t\treturn min_left(st, check, acc,\
    \ 1, 0, n);\n\t}\n};\nnamespace {\n\tlint RAQRSQ_nodef(const lint& a, const lint&\
    \ b) { return a + b; }\n\tvoid RAQRSQ_lazyf(lint& a, const lint& b) { a += b;\
    \ }\n\tvoid RAQRSQ_updf(lint& a, const lint& b, const unsigned int& width) {\n\
    \t\ta += width * b;\n\t}\n\tlint RAQRMiQ_nodef(const lint& a, const lint& b) {\
    \ return std::min(a, b); }\n\tvoid RAQRMiQ_lazyf(lint& a, const lint& b) { a +=\
    \ b; }\n\tvoid RAQRMiQ_updf(lint& a, const lint& b, const unsigned int& width)\
    \ {\n\t\ta += b;\n\t}\n\tlint RAQRMaQ_nodef(const lint& a, const lint& b) { return\
    \ std::max(a, b); }\n\tvoid RAQRMaQ_lazyf(lint& a, const lint& b) { a += b; }\n\
    \tvoid RAQRMaQ_updf(lint& a, const lint& b, const unsigned int& width) {\n\t\t\
    a += b;\n\t}\n\tlint RUQRSQ_nodef(const lint& a, const lint& b) { return a + b;\
    \ }\n\tvoid RUQRSQ_lazyf(lint& a, const lint& b) { a = b; }\n\tvoid RUQRSQ_updf(lint&\
    \ a, const lint& b, const unsigned int& width) {\n\t\ta = width * b;\n\t}\n\t\
    lint RUQRMiQ_nodef(const lint& a, const lint& b) { return std::min(a, b); }\n\t\
    void RUQRMiQ_lazyf(lint& a, const lint& b) { a = b; }\n\tvoid RUQRMiQ_updf(lint&\
    \ a, const lint& b, const unsigned int& width) {\n\t\ta = b;\n\t}\n\tlint RUQRMaQ_nodef(const\
    \ lint& a, const lint& b) { return std::max(a, b); }\n\tvoid RUQRMaQ_lazyf(lint&\
    \ a, const lint& b) { a = b; }\n\tvoid RUQRMaQ_updf(lint& a, const lint& b, const\
    \ unsigned int& width) {\n\t\ta = b;\n\t}\n}  // namespace\n\nclass RAQRSQ : public\
    \ IntervalSegTree<lint, lint, RAQRSQ_nodef, RAQRSQ_lazyf,\n\t\t\t\t\t\t\t\t\t\
    \  RAQRSQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint, lint, RAQRSQ_nodef,\
    \ RAQRSQ_lazyf, RAQRSQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\tRAQRSQ(Args&&...\
    \ args) : Base(std::forward<Args>(args)..., 0) {}\n};\nclass RAQRMiQ : public\
    \ IntervalSegTree<lint, lint, RAQRMiQ_nodef, RAQRMiQ_lazyf,\n\t\t\t\t\t\t\t\t\t\
    \   RAQRMiQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint, lint, RAQRMiQ_nodef,\
    \ RAQRMiQ_lazyf, RAQRMiQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\tRAQRMiQ(Args&&...\
    \ args) : Base(std::forward<Args>(args)..., LINF) {}\n};\nclass RAQRMaQ : public\
    \ IntervalSegTree<lint, lint, RAQRMaQ_nodef, RAQRMaQ_lazyf,\n\t\t\t\t\t\t\t\t\t\
    \   RAQRMaQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint, lint, RAQRMaQ_nodef,\
    \ RAQRMaQ_lazyf, RAQRMaQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\tRAQRMaQ(Args&&...\
    \ args) : Base(std::forward<Args>(args)..., -LINF) {}\n};\nclass RUQRSQ : public\
    \ IntervalSegTree<lint, lint, RUQRSQ_nodef, RUQRSQ_lazyf,\n\t\t\t\t\t\t\t\t\t\
    \  RUQRSQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint, lint, RUQRSQ_nodef,\
    \ RUQRSQ_lazyf, RUQRSQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\tRUQRSQ(Args&&...\
    \ args) : Base(std::forward<Args>(args)..., 0) {}\n};\nclass RUQRMiQ : public\
    \ IntervalSegTree<lint, lint, RUQRMiQ_nodef, RUQRMiQ_lazyf,\n\t\t\t\t\t\t\t\t\t\
    \   RUQRMiQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint, lint, RUQRMiQ_nodef,\
    \ RUQRMiQ_lazyf, RUQRMiQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\tRUQRMiQ(Args&&...\
    \ args) : Base(std::forward<Args>(args)..., LINF) {}\n};\nclass RUQRMaQ : public\
    \ IntervalSegTree<lint, lint, RUQRMaQ_nodef, RUQRMaQ_lazyf,\n\t\t\t\t\t\t\t\t\t\
    \   RUQRMaQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint, lint, RUQRMaQ_nodef,\
    \ RUQRMaQ_lazyf, RUQRMaQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\tRUQRMaQ(Args&&...\
    \ args) : Base(std::forward<Args>(args)..., -LINF) {}\n};\n\n/**\n * @title Interval\
    \ Segment Tree\n */\n#line 5 \"test/yosupo/range_affine_range_sum.test.cpp\"\n\
    using ModInt = StaticModInt<998244353>;\nusing MP = std::pair<ModInt, ModInt>;\n\
    ModInt nodef(const ModInt& a, const ModInt& b) { return a + b; }\nvoid lazyf(MP&\
    \ a, const MP& b) {\n\ta = {a.first * b.first, a.second * b.first + b.second};\n\
    }\nvoid updf(ModInt& a, const MP& b, const unsigned int& width) {\n\ta = b.first\
    \ * a + b.second * width;\n}\nclass MySeg : public IntervalSegTree<ModInt, MP,\
    \ nodef, lazyf, updf> {\n\tusing Base = IntervalSegTree<ModInt, MP, nodef, lazyf,\
    \ updf>;\n\n  public:\n\tMySeg(const std::vector<ModInt>& initvec) : Base(initvec,\
    \ 0) {}\n};\nint n, q;\nstd::vector<ModInt> vec;\nint main() {\n\tscanf(\"%d%d\"\
    , &n, &q);\n\tvec.resize(n);\n\trep(i, n) {\n\t\tint tmp;\n\t\tscanf(\"%d\", &tmp);\n\
    \t\tvec[i] = tmp;\n\t}\n\tMySeg st(vec);\n\trep(i, q) {\n\t\tint t;\n\t\tscanf(\"\
    %d\", &t);\n\t\tif (t == 0) {\n\t\t\tint l, r, b, c;\n\t\t\tscanf(\"%d%d%d%d\"\
    , &l, &r, &b, &c);\n\t\t\tst.update(l, r, {b, c});\n\t\t} else {\n\t\t\tint l,\
    \ r;\n\t\t\tscanf(\"%d%d\", &l, &r);\n\t\t\tprintf(\"%d\\n\", st.query(l, r));\n\
    \t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../../algebraic/StaticModInt.hpp\"\n#include \"../../data-structure/IntervalSegTree.hpp\"\
    \n#include \"../../other/template.hpp\"\nusing ModInt = StaticModInt<998244353>;\n\
    using MP = std::pair<ModInt, ModInt>;\nModInt nodef(const ModInt& a, const ModInt&\
    \ b) { return a + b; }\nvoid lazyf(MP& a, const MP& b) {\n\ta = {a.first * b.first,\
    \ a.second * b.first + b.second};\n}\nvoid updf(ModInt& a, const MP& b, const\
    \ unsigned int& width) {\n\ta = b.first * a + b.second * width;\n}\nclass MySeg\
    \ : public IntervalSegTree<ModInt, MP, nodef, lazyf, updf> {\n\tusing Base = IntervalSegTree<ModInt,\
    \ MP, nodef, lazyf, updf>;\n\n  public:\n\tMySeg(const std::vector<ModInt>& initvec)\
    \ : Base(initvec, 0) {}\n};\nint n, q;\nstd::vector<ModInt> vec;\nint main() {\n\
    \tscanf(\"%d%d\", &n, &q);\n\tvec.resize(n);\n\trep(i, n) {\n\t\tint tmp;\n\t\t\
    scanf(\"%d\", &tmp);\n\t\tvec[i] = tmp;\n\t}\n\tMySeg st(vec);\n\trep(i, q) {\n\
    \t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tint l, r, b, c;\n\
    \t\t\tscanf(\"%d%d%d%d\", &l, &r, &b, &c);\n\t\t\tst.update(l, r, {b, c});\n\t\
    \t} else {\n\t\t\tint l, r;\n\t\t\tscanf(\"%d%d\", &l, &r);\n\t\t\tprintf(\"%d\\\
    n\", st.query(l, r));\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - algebraic/StaticModInt.hpp
  - other/template.hpp
  - other/type_traits.hpp
  - data-structure/IntervalSegTree.hpp
  - data-structure/SegTree.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-05-20 00:07:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
