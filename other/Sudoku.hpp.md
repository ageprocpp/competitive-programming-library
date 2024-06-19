---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: basic/template.hpp
    title: basic/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"basic/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifndef __clang__\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
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
    }\n#line 3 \"other/Sudoku.hpp\"\nclass Sudoku {\n\tstatic void determine(int i,\
    \ int j, int x,\n\t\t\t\t\t\t  std::array<std::array<std::array<bool, 9>, 9>,\
    \ 9>& flag,\n\t\t\t\t\t\t  std::array<std::array<int, 9>, 9>& target) {\n\t\t\
    target[i][j] = x;\n\t\trep(k, 9) flag[i][k][x - 1] = flag[k][j][x - 1] = false;\n\
    \t\trep(k, 3) rep(l, 3) flag[i / 3 * 3 + k][j / 3 * 3 + l][x - 1] = false;\n\t\
    \trep(k, 9) flag[i][j][k] = false;\n\t\tflag[i][j][x - 1] = true;\n\t}\n\tstatic\
    \ bool completed(const std::array<std::array<int, 9>, 9>& ans) {\n\t\trep(i, 9)\
    \ rep(j, 9) if (!ans[i][j]) return false;\n\t\treturn true;\n\t}\n\tstatic bool\
    \ solvable(const std::array<std::array<std::array<bool, 9>, 9>, 9>& flag,\n\t\t\
    \t\t\t\t const std::array<std::array<int, 9>, 9>& ans) {\n\t\trep(i, 9) {\n\t\t\
    \trep(j, 9) {\n\t\t\t\tif (!ans[i][j]) {\n\t\t\t\t\tbool ok = false;\n\t\t\t\t\
    \trep(k, 9) ok |= flag[i][j][k];\n\t\t\t\t\tif (!ok) return false;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\treturn true;\n\t}\n\tstatic void logic(std::array<std::array<std::array<bool,\
    \ 9>, 9>, 9>& flag,\n\t\t\t\t\t  std::array<std::array<int, 9>, 9>& ans) {\n\t\
    \twhile (true) {\n\t\t\tbool updated = false;\n\t\t\trep(i, 9) rep(j, 9) {\n\t\
    \t\t\tint cand = 0, cnt = 0;\n\t\t\t\trep(k, 9) {\n\t\t\t\t\tif (!ans[i][j] &&\
    \ flag[i][j][k]) {\n\t\t\t\t\t\tcand = k + 1, cnt++;\n\t\t\t\t\t\tif (cnt > 1)\
    \ break;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif (cnt == 1) determine(i, j, cand,\
    \ flag, ans), updated = true;\n\t\t\t}\n\t\t\trep(i, 9) {\n\t\t\t\trep(j, 9) {\n\
    \t\t\t\t\tint cand = -1;\n\t\t\t\t\trep(k, 9) {\n\t\t\t\t\t\tif (ans[i][k] ==\
    \ j + 1) {\n\t\t\t\t\t\t\tcand = -1;\n\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t}\n\t\t\
    \t\t\t\tif (flag[i][k][j]) {\n\t\t\t\t\t\t\tif (cand != -1) {\n\t\t\t\t\t\t\t\t\
    cand = -1;\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\tcand = k;\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tif (cand != -1) determine(i, cand, j + 1,\
    \ flag, ans), updated = true;\n\t\t\t\t\tcand = -1;\n\t\t\t\t\trep(k, 9) {\n\t\
    \t\t\t\t\tif (ans[k][i] == j + 1) {\n\t\t\t\t\t\t\tcand = -1;\n\t\t\t\t\t\t\t\
    break;\n\t\t\t\t\t\t}\n\t\t\t\t\t\tif (flag[k][i][j]) {\n\t\t\t\t\t\t\tif (cand\
    \ != -1) {\n\t\t\t\t\t\t\t\tcand = -1;\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\
    }\n\t\t\t\t\t\t\tcand = k;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tif (cand !=\
    \ -1) determine(cand, i, j + 1, flag, ans), updated = true;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\trep(i, 3) {\n\t\t\t\trep(j, 3) {\n\t\t\t\t\trep(k, 9) {\n\t\t\t\t\t\t\
    IP cand = {-1, -1};\n\t\t\t\t\t\tbool ng = false;\n\t\t\t\t\t\trep(l, 3) {\n\t\
    \t\t\t\t\t\trep(m, 3) {\n\t\t\t\t\t\t\t\tif (ans[i * 3 + l][j * 3 + m] == k +\
    \ 1) {\n\t\t\t\t\t\t\t\t\tcand = IP{-1, -1};\n\t\t\t\t\t\t\t\t\tng = true;\n\t\
    \t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\tif (flag[i * 3 + l][j\
    \ * 3 + m][k]) {\n\t\t\t\t\t\t\t\t\tif (cand != IP{-1, -1}) {\n\t\t\t\t\t\t\t\t\
    \t\tcand = IP{-1, -1};\n\t\t\t\t\t\t\t\t\t\tng = true;\n\t\t\t\t\t\t\t\t\t\tbreak;\n\
    \t\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\t\tcand = IP{l, m};\n\t\t\t\t\t\t\t\t}\n\t\
    \t\t\t\t\t\t}\n\t\t\t\t\t\t\tif (ng) break;\n\t\t\t\t\t\t}\n\t\t\t\t\t\tif (!ng\
    \ && cand != IP{-1, -1})\n\t\t\t\t\t\t\tdetermine(i * 3 + cand.first, j * 3 +\
    \ cand.second, k + 1, flag, ans),\n\t\t\t\t\t\t\t\tupdated = true;\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (!updated) break;\n\t\t}\n\t}\n\tstatic bool solve(std::array<std::array<std::array<bool,\
    \ 9>, 9>, 9>& flag,\n\t\t\t\t\t  std::array<std::array<int, 9>, 9>& ans) {\n\t\
    \tlogic(flag, ans);\n\t\tauto nflag = flag;\n\t\tauto nans = ans;\n\t\trep(i,\
    \ 9) {\n\t\t\trep(j, 9) {\n\t\t\t\tif (!nans[i][j]) {\n\t\t\t\t\trep(k, 9) {\n\
    \t\t\t\t\t\tif (nflag[i][j][k]) {\n\t\t\t\t\t\t\tdetermine(i, j, k + 1, nflag,\
    \ nans);\n\t\t\t\t\t\t\tif (!solvable(nflag, nans) || !solve(nflag, nans)) {\n\
    \t\t\t\t\t\t\t\tflag[i][j][k] = false;\n\t\t\t\t\t\t\t\tnflag = flag, nans = ans;\n\
    \t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif\
    \ (completed(nans)) {\n\t\t\tflag = nflag, ans = nans;\n\t\t\treturn true;\n\t\
    \t}\n\t\treturn false;\n\t}\n\n  public:\n\tstatic std::array<std::array<int,\
    \ 9>, 9> solve(const std::array<std::array<int, 9>, 9>& prob) {\n\t\tstd::array<std::array<std::array<bool,\
    \ 9>, 9>, 9> flag;\n\t\tauto ans = prob;\n\t\trep(i, 9) rep(j, 9) rep(k, 9) flag[i][j][k]\
    \ = true;\n\t\trep(i, 9) rep(j, 9) if (prob[i][j]) determine(i, j, prob[i][j],\
    \ flag, ans);\n\t\tsolve(flag, ans);\n\t\treturn ans;\n\t}\n};\n"
  code: "#pragma once\n#include \"../basic/template.hpp\"\nclass Sudoku {\n\tstatic\
    \ void determine(int i, int j, int x,\n\t\t\t\t\t\t  std::array<std::array<std::array<bool,\
    \ 9>, 9>, 9>& flag,\n\t\t\t\t\t\t  std::array<std::array<int, 9>, 9>& target)\
    \ {\n\t\ttarget[i][j] = x;\n\t\trep(k, 9) flag[i][k][x - 1] = flag[k][j][x - 1]\
    \ = false;\n\t\trep(k, 3) rep(l, 3) flag[i / 3 * 3 + k][j / 3 * 3 + l][x - 1]\
    \ = false;\n\t\trep(k, 9) flag[i][j][k] = false;\n\t\tflag[i][j][x - 1] = true;\n\
    \t}\n\tstatic bool completed(const std::array<std::array<int, 9>, 9>& ans) {\n\
    \t\trep(i, 9) rep(j, 9) if (!ans[i][j]) return false;\n\t\treturn true;\n\t}\n\
    \tstatic bool solvable(const std::array<std::array<std::array<bool, 9>, 9>, 9>&\
    \ flag,\n\t\t\t\t\t\t const std::array<std::array<int, 9>, 9>& ans) {\n\t\trep(i,\
    \ 9) {\n\t\t\trep(j, 9) {\n\t\t\t\tif (!ans[i][j]) {\n\t\t\t\t\tbool ok = false;\n\
    \t\t\t\t\trep(k, 9) ok |= flag[i][j][k];\n\t\t\t\t\tif (!ok) return false;\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn true;\n\t}\n\tstatic void logic(std::array<std::array<std::array<bool,\
    \ 9>, 9>, 9>& flag,\n\t\t\t\t\t  std::array<std::array<int, 9>, 9>& ans) {\n\t\
    \twhile (true) {\n\t\t\tbool updated = false;\n\t\t\trep(i, 9) rep(j, 9) {\n\t\
    \t\t\tint cand = 0, cnt = 0;\n\t\t\t\trep(k, 9) {\n\t\t\t\t\tif (!ans[i][j] &&\
    \ flag[i][j][k]) {\n\t\t\t\t\t\tcand = k + 1, cnt++;\n\t\t\t\t\t\tif (cnt > 1)\
    \ break;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif (cnt == 1) determine(i, j, cand,\
    \ flag, ans), updated = true;\n\t\t\t}\n\t\t\trep(i, 9) {\n\t\t\t\trep(j, 9) {\n\
    \t\t\t\t\tint cand = -1;\n\t\t\t\t\trep(k, 9) {\n\t\t\t\t\t\tif (ans[i][k] ==\
    \ j + 1) {\n\t\t\t\t\t\t\tcand = -1;\n\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t}\n\t\t\
    \t\t\t\tif (flag[i][k][j]) {\n\t\t\t\t\t\t\tif (cand != -1) {\n\t\t\t\t\t\t\t\t\
    cand = -1;\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\tcand = k;\n\
    \t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tif (cand != -1) determine(i, cand, j + 1,\
    \ flag, ans), updated = true;\n\t\t\t\t\tcand = -1;\n\t\t\t\t\trep(k, 9) {\n\t\
    \t\t\t\t\tif (ans[k][i] == j + 1) {\n\t\t\t\t\t\t\tcand = -1;\n\t\t\t\t\t\t\t\
    break;\n\t\t\t\t\t\t}\n\t\t\t\t\t\tif (flag[k][i][j]) {\n\t\t\t\t\t\t\tif (cand\
    \ != -1) {\n\t\t\t\t\t\t\t\tcand = -1;\n\t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\
    }\n\t\t\t\t\t\t\tcand = k;\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t\tif (cand !=\
    \ -1) determine(cand, i, j + 1, flag, ans), updated = true;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\trep(i, 3) {\n\t\t\t\trep(j, 3) {\n\t\t\t\t\trep(k, 9) {\n\t\t\t\t\t\t\
    IP cand = {-1, -1};\n\t\t\t\t\t\tbool ng = false;\n\t\t\t\t\t\trep(l, 3) {\n\t\
    \t\t\t\t\t\trep(m, 3) {\n\t\t\t\t\t\t\t\tif (ans[i * 3 + l][j * 3 + m] == k +\
    \ 1) {\n\t\t\t\t\t\t\t\t\tcand = IP{-1, -1};\n\t\t\t\t\t\t\t\t\tng = true;\n\t\
    \t\t\t\t\t\t\t\tbreak;\n\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\tif (flag[i * 3 + l][j\
    \ * 3 + m][k]) {\n\t\t\t\t\t\t\t\t\tif (cand != IP{-1, -1}) {\n\t\t\t\t\t\t\t\t\
    \t\tcand = IP{-1, -1};\n\t\t\t\t\t\t\t\t\t\tng = true;\n\t\t\t\t\t\t\t\t\t\tbreak;\n\
    \t\t\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\t\t\tcand = IP{l, m};\n\t\t\t\t\t\t\t\t}\n\t\
    \t\t\t\t\t\t}\n\t\t\t\t\t\t\tif (ng) break;\n\t\t\t\t\t\t}\n\t\t\t\t\t\tif (!ng\
    \ && cand != IP{-1, -1})\n\t\t\t\t\t\t\tdetermine(i * 3 + cand.first, j * 3 +\
    \ cand.second, k + 1, flag, ans),\n\t\t\t\t\t\t\t\tupdated = true;\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (!updated) break;\n\t\t}\n\t}\n\tstatic bool solve(std::array<std::array<std::array<bool,\
    \ 9>, 9>, 9>& flag,\n\t\t\t\t\t  std::array<std::array<int, 9>, 9>& ans) {\n\t\
    \tlogic(flag, ans);\n\t\tauto nflag = flag;\n\t\tauto nans = ans;\n\t\trep(i,\
    \ 9) {\n\t\t\trep(j, 9) {\n\t\t\t\tif (!nans[i][j]) {\n\t\t\t\t\trep(k, 9) {\n\
    \t\t\t\t\t\tif (nflag[i][j][k]) {\n\t\t\t\t\t\t\tdetermine(i, j, k + 1, nflag,\
    \ nans);\n\t\t\t\t\t\t\tif (!solvable(nflag, nans) || !solve(nflag, nans)) {\n\
    \t\t\t\t\t\t\t\tflag[i][j][k] = false;\n\t\t\t\t\t\t\t\tnflag = flag, nans = ans;\n\
    \t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tif\
    \ (completed(nans)) {\n\t\t\tflag = nflag, ans = nans;\n\t\t\treturn true;\n\t\
    \t}\n\t\treturn false;\n\t}\n\n  public:\n\tstatic std::array<std::array<int,\
    \ 9>, 9> solve(const std::array<std::array<int, 9>, 9>& prob) {\n\t\tstd::array<std::array<std::array<bool,\
    \ 9>, 9>, 9> flag;\n\t\tauto ans = prob;\n\t\trep(i, 9) rep(j, 9) rep(k, 9) flag[i][j][k]\
    \ = true;\n\t\trep(i, 9) rep(j, 9) if (prob[i][j]) determine(i, j, prob[i][j],\
    \ flag, ans);\n\t\tsolve(flag, ans);\n\t\treturn ans;\n\t}\n};"
  dependsOn:
  - basic/template.hpp
  isVerificationFile: false
  path: other/Sudoku.hpp
  requiredBy: []
  timestamp: '2024-06-19 15:49:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/Sudoku.hpp
layout: document
redirect_from:
- /library/other/Sudoku.hpp
- /library/other/Sudoku.hpp.html
title: other/Sudoku.hpp
---