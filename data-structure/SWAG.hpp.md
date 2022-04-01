---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Sliding Window Aggregation
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifndef __clang__\n#ifdef ONLINE_JUDGE\n#ifdef _WIN64\n#pragma GCC target(\"avx2\"\
    )\n#else\n#pragma GCC target(\"avx512f\")\n#endif\n#elif defined EVAL\n#else\n\
    #pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n#endif\n#include <string.h>\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n#define rep(i, n) for (int i = 0; i <\
    \ (n); i++)\n#define REP(i, n) for (int i = 1; i <= (n); i++)\n#define all(V)\
    \ V.begin(), V.end()\n\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using uint = unsigned int;\nusing lint = long long;\nusing ulint = unsigned long\
    \ long;\nusing IP = std::pair<int, int>;\nusing LP = std::pair<lint, lint>;\n\n\
    constexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\nconstexpr\
    \ double eps = DBL_EPSILON * 10;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
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
    \treturn ost << x.first << \" \" << x.second;\n}\ntemplate <class Container,\n\
    #if __cplusplus >= 201703L\n\t\t  std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>,\n#else\n\t\t  std::enable_if_t<!std::is_same<Container, std::string>::value,\n\
    #endif\n\t\t\t\t\t\t   std::nullptr_t> = nullptr>\nauto operator>>(std::istream&\
    \ ist, Container& cont)\n\t-> decltype(typename Container::iterator(), std::cin)&\
    \ {\n\tstd::vector<typename Container::value_type> tmp;\n\twhile (true) {\n\t\t\
    typename Container::value_type t;\n\t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\
    \tif (getchar() == '\\n') break;\n\t}\n\tcont = Container(std::move(tmp));\n\t\
    return ist;\n}\ntemplate <class Container,\n#if __cplusplus >= 201703L\n\t\t \
    \ std::enable_if_t<!std::is_same_v<Container, std::string>,\n#else\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value,\n#endif\n\t\t\t\t\t\t   std::nullptr_t> = nullptr>\nauto\
    \ operator<<(std::ostream& ost, const Container& cont)\n\t-> decltype(typename\
    \ Container::iterator(), std::cout)& {\n\tfor (auto it = cont.begin(); it != cont.end();\
    \ it++) {\n\t\tif (it != cont.begin()) ost << ' ';\n\t\tost << *it;\n\t}\n\treturn\
    \ ost;\n}\ntemplate <class Container>\nauto sum(const Container& cont)\n\t-> decltype(typename\
    \ Container::iterator(), 0LL) {\n\tlint res = 0;\n\tfor (auto it = cont.begin();\
    \ it != cont.end(); it++) res += *it;\n\treturn res;\n}\ntemplate <class T, class\
    \ U>\nconstexpr inline bool chmax(T& lhs, const U& rhs) noexcept {\n\tif (lhs\
    \ < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate\
    \ <class T, class U>\nconstexpr inline bool chmin(T& lhs, const U& rhs) noexcept\
    \ {\n\tif (lhs > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\nconstexpr inline lint gcd(lint a, lint b) noexcept {\n\twhile (b) {\n\t\tlint\
    \ c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint\
    \ a, lint b) noexcept { return a / gcd(a, b) * b; }\nconstexpr bool isprime(lint\
    \ n) noexcept {\n\tif (n == 1) return false;\n\tfor (int i = 2; i * i <= n; i++)\
    \ {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\ntemplate <class\
    \ T>\nconstexpr T mypow(T a, lint b) noexcept {\n\tT res(1);\n\twhile (true) {\n\
    \t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\t}\n\
    \treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint m) noexcept {\n\t\
    a %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) res *= a, res %= m;\n\t\
    \ta *= a, a %= m, b >>= 1;\n\t}\n\treturn res;\n}\nconstexpr i128 modpow(i128\
    \ a, i128 b, i128 m) noexcept {\n\ta %= m;\n\ti128 res(1);\n\twhile (b) {\n\t\t\
    if (b & 1) res *= a, res %= m;\n\t\ta *= a, a %= m, b >>= 1;\n\t}\n\treturn res;\n\
    }\nLP extGcd(lint a, lint b) noexcept {\n\tif (b == 0) return {1, 0};\n\tLP s\
    \ = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b *\
    \ s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const\
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
    data-structure/SWAG.hpp\"\ntemplate <class T, T (*op)(const T&, const T&)>\nclass\
    \ SWAG {\n\tstd::stack<std::pair<T, T>> front, back;\n\n  public:\n\tSWAG() {}\n\
    \tSWAG(const std::vector<T> vec) {\n\t\tfor (const T& i : vec) {\n\t\t\tback.emplace(i,\
    \ op(back.top().second, i));\n\t\t}\n\t}\n\tvoid push(const T& x) {\n\t\tif (back.empty())\n\
    \t\t\tback.emplace(x, x);\n\t\telse\n\t\t\tback.emplace(x, op(back.top().second,\
    \ x));\n\t}\n\tvoid pop() {\n\t\tif (!front.empty())\n\t\t\tfront.pop();\n\t\t\
    else {\n\t\t\tauto btop = back.top();\n\t\t\tfront.emplace(btop.first, btop.first);\n\
    \t\t\tback.pop();\n\t\t\twhile (!back.empty()) {\n\t\t\t\tbtop = back.top();\n\
    \t\t\t\tfront.emplace(btop.first, op(btop.first, front.top().second));\n\t\t\t\
    \tback.pop();\n\t\t\t}\n\t\t\tfront.pop();\n\t\t}\n\t}\n\tT fold() const {\n\t\
    \tif (front.empty()) return back.top().second;\n\t\tif (back.empty()) return front.top().second;\n\
    \t\treturn op(front.top().second, back.top().second);\n\t}\n\tunsigned int size()\
    \ const { return front.size() + back.size(); }\n\tbool empty() const { return\
    \ front.empty() && back.empty(); }\n};\n\nnamespace {\n\ttemplate <class T>\n\t\
    T minSWAG_op(const T& lhs, const T& rhs) {\n\t\treturn std::min(lhs, rhs);\n\t\
    }\n\ttemplate <class T>\n\tT maxSWAG_op(const T& lhs, const T& rhs) {\n\t\treturn\
    \ std::max(lhs, rhs);\n\t}\n}  // namespace\n\ntemplate <class T>\nclass minSWAG\
    \ : public SWAG<T, minSWAG_op> {};\ntemplate <class T>\nclass maxSWAG : public\
    \ SWAG<T, maxSWAG_op> {};\n\n/**\n * @title Sliding Window Aggregation\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate <class T, T (*op)(const\
    \ T&, const T&)>\nclass SWAG {\n\tstd::stack<std::pair<T, T>> front, back;\n\n\
    \  public:\n\tSWAG() {}\n\tSWAG(const std::vector<T> vec) {\n\t\tfor (const T&\
    \ i : vec) {\n\t\t\tback.emplace(i, op(back.top().second, i));\n\t\t}\n\t}\n\t\
    void push(const T& x) {\n\t\tif (back.empty())\n\t\t\tback.emplace(x, x);\n\t\t\
    else\n\t\t\tback.emplace(x, op(back.top().second, x));\n\t}\n\tvoid pop() {\n\t\
    \tif (!front.empty())\n\t\t\tfront.pop();\n\t\telse {\n\t\t\tauto btop = back.top();\n\
    \t\t\tfront.emplace(btop.first, btop.first);\n\t\t\tback.pop();\n\t\t\twhile (!back.empty())\
    \ {\n\t\t\t\tbtop = back.top();\n\t\t\t\tfront.emplace(btop.first, op(btop.first,\
    \ front.top().second));\n\t\t\t\tback.pop();\n\t\t\t}\n\t\t\tfront.pop();\n\t\t\
    }\n\t}\n\tT fold() const {\n\t\tif (front.empty()) return back.top().second;\n\
    \t\tif (back.empty()) return front.top().second;\n\t\treturn op(front.top().second,\
    \ back.top().second);\n\t}\n\tunsigned int size() const { return front.size()\
    \ + back.size(); }\n\tbool empty() const { return front.empty() && back.empty();\
    \ }\n};\n\nnamespace {\n\ttemplate <class T>\n\tT minSWAG_op(const T& lhs, const\
    \ T& rhs) {\n\t\treturn std::min(lhs, rhs);\n\t}\n\ttemplate <class T>\n\tT maxSWAG_op(const\
    \ T& lhs, const T& rhs) {\n\t\treturn std::max(lhs, rhs);\n\t}\n}  // namespace\n\
    \ntemplate <class T>\nclass minSWAG : public SWAG<T, minSWAG_op> {};\ntemplate\
    \ <class T>\nclass maxSWAG : public SWAG<T, maxSWAG_op> {};\n\n/**\n * @title\
    \ Sliding Window Aggregation\n */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/SWAG.hpp
  requiredBy: []
  timestamp: '2022-04-01 21:43:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/queue_operate_all_composite.test.cpp
documentation_of: data-structure/SWAG.hpp
layout: document
redirect_from:
- /library/data-structure/SWAG.hpp
- /library/data-structure/SWAG.hpp.html
title: Sliding Window Aggregation
---
