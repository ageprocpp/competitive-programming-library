---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: basic/template.hpp
    title: basic/template.hpp
  - icon: ':heavy_check_mark:'
    path: math/Factorize.hpp
    title: math/Factorize.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#line 2 \"basic/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n\
    #pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n\
    #include <string.h>\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cfloat>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i, n) for (int i = 0; i < int(n); i++)\n#define REP(i,\
    \ n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(), V.end()\n\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
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
    }\n#line 2 \"math/Factorize.hpp\"\n\n#line 4 \"math/Factorize.hpp\"\nnamespace\
    \ Factorize {\n\tinline static lint mul(lint a, lint b, lint n) { return i128(a)\
    \ * b % n; }\n\tinline static lint safemodpow(lint a, lint b, lint n) noexcept\
    \ {\n\t\ta %= n;\n\t\tlint res(1);\n\t\twhile (b) {\n\t\t\tif (b & 1) res = mul(res,\
    \ a, n);\n\t\t\ta = mul(a, a, n), a %= n, b >>= 1;\n\t\t}\n\t\treturn res;\n\t\
    }\n\tbool is_prime(lint n) {\n\t\tif (n == 2) return true;\n\t\tif (n == 1 ||\
    \ (~n & 1)) return false;\n\t\tlint d = n - 1;\n\t\twhile (~d & 1) d >>= 1;\n\t\
    \tstd::array<lint, 7> test = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\
    \t\tfor (lint i : test) {\n\t\t\tif (i % n == 0) continue;\n\t\t\tlint t = d;\n\
    \t\t\tlint y = safemodpow(i, t, n);\n\t\t\twhile (t != n - 1 && y != 1 && y !=\
    \ n - 1) {\n\t\t\t\ty = mul(y, y, n), t *= 2;\n\t\t\t}\n\t\t\tif (y != n - 1 &&\
    \ t % 2 == 0) return false;\n\t\t}\n\t\treturn true;\n\t}\n\tlint find_factor(lint\
    \ n) {\n\t\tif (~n & 1) return 2;\n\t\tfor (int c = 1; c < n; c++) {\n\t\t\tlint\
    \ y = 0, g = 1, r = 1, q = 1, k = 0, ys = 0, x = y;\n\t\t\tauto f = [&](lint x)\
    \ { return (mul(x, x, n) + c) % n; };\n\t\t\twhile (g == 1) {\n\t\t\t\tx = y;\n\
    \t\t\t\twhile (k < 3 * r / 4) y = f(y), k += 1;\n\t\t\t\twhile (k < r && g ==\
    \ 1) {\n\t\t\t\t\tys = y;\n\t\t\t\t\trep(i, std::min(lint(c), r - k)) {\n\t\t\t\
    \t\t\ty = f(y);\n\t\t\t\t\t\tq = mul(q, std::abs(x - y), n);\n\t\t\t\t\t}\n\t\t\
    \t\t\tg = std::gcd(q, n);\n\t\t\t\t\tk += c;\n\t\t\t\t}\n\t\t\t\tk = r, r *= 2;\n\
    \t\t\t}\n\t\t\tif (g == n) {\n\t\t\t\tg = 1;\n\t\t\t\ty = ys;\n\t\t\t\twhile (g\
    \ == 1) {\n\t\t\t\t\ty = f(y);\n\t\t\t\t\tg = std::gcd(std::abs(x - y), n);\n\t\
    \t\t\t}\n\t\t\t}\n\t\t\tif (g == n) continue;\n\t\t\tif (is_prime(g)) return g;\n\
    \t\t\tif (is_prime(n / g)) return n / g;\n\t\t\treturn find_factor(g);\n\t\t}\n\
    \t\tabort();\n\t}\n\n\t// Pollard's rho algorithm\n\tstd::vector<lint> factorize(lint\
    \ n) {\n\t\tif (n == 1) return {};\n\t\tstatic std::random_device rd;\n\t\tstatic\
    \ std::mt19937 mt(rd());\n\t\tauto trial = [](uint seed, lint m) {\n\t\t\tauto\
    \ gen_rand = [m, seed](lint s) { return (mul(s, s, m) + seed) % m; };\n\t\t\t\
    lint interval = mt(), x, y = m, r = 1, q = 1, ys, g;\n\t\t\tdo {\n\t\t\t\tx =\
    \ y;\n\t\t\t\tREP(i, r) y = gen_rand(y);\n\t\t\t\tlint k = 0;\n\t\t\t\tdo {\n\t\
    \t\t\t\tys = y;\n\t\t\t\t\tREP(i, std::min(interval, r - k)) {\n\t\t\t\t\t\ty\
    \ = gen_rand(y);\n\t\t\t\t\t\tq = mul(q, std::abs(x - y), m);\n\t\t\t\t\t}\n\t\
    \t\t\t\tg = gcd(q, m);\n\t\t\t\t\tk = k + interval;\n\t\t\t\t} while (k < r &&\
    \ g == 1);\n\t\t\t\tr *= 2;\n\t\t\t} while (g == 1);\n\t\t\tif (g == m) {\n\t\t\
    \t\tdo {\n\t\t\t\t\tys = gen_rand(ys);\n\t\t\t\t\tg = gcd(std::abs(x - ys), m);\n\
    \t\t\t\t} while (g == 1);\n\t\t\t}\n\t\t\treturn g == m ? -1 : g;\n\t\t};\n\t\t\
    std::vector<lint> res;\n\t\tlambda_fix([&res, &trial](auto self, lint m) {\n\t\
    \t\tif (is_prime(m)) {\n\t\t\t\tres.emplace_back(m);\n\t\t\t\treturn;\n\t\t\t\
    }\n\t\t\twhile (true) {\n\t\t\t\tlint f = trial(mt(), m);\n\t\t\t\tif (f != -1)\
    \ {\n\t\t\t\t\tself(self, f);\n\t\t\t\t\tself(self, m / f);\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t})(n);\n\t\tstd::sort(all(res));\n\t\treturn res;\n\t\
    }\n\n}  // namespace Factorize\n#line 4 \"test/yosupo/factorize.test.cpp\"\nint\
    \ main() {\n\tint Q;\n\tlint a;\n\tstd::cin >> Q;\n\twhile (Q--) {\n\t\tstd::cin\
    \ >> a;\n\t\tif (a == 1)\n\t\t\tstd::cout << 0 << std::endl;\n\t\telse {\n\t\t\
    \tstd::vector<lint> res = Factorize::factorize(a);\n\t\t\tstd::cout << res.size()\
    \ << ' ' << res << std::endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include \"\
    ../../basic/template.hpp\"\n#include \"../../math/Factorize.hpp\"\nint main()\
    \ {\n\tint Q;\n\tlint a;\n\tstd::cin >> Q;\n\twhile (Q--) {\n\t\tstd::cin >> a;\n\
    \t\tif (a == 1)\n\t\t\tstd::cout << 0 << std::endl;\n\t\telse {\n\t\t\tstd::vector<lint>\
    \ res = Factorize::factorize(a);\n\t\t\tstd::cout << res.size() << ' ' << res\
    \ << std::endl;\n\t\t}\n\t}\n}"
  dependsOn:
  - basic/template.hpp
  - math/Factorize.hpp
  isVerificationFile: true
  path: test/yosupo/factorize.test.cpp
  requiredBy: []
  timestamp: '2024-06-19 15:49:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/factorize.test.cpp
- /verify/test/yosupo/factorize.test.cpp.html
title: test/yosupo/factorize.test.cpp
---
