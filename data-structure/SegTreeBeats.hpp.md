---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
    title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Segment Tree Beats
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
    data-structure/SegTreeBeats.hpp\"\nclass SegTreeBeats {\n\tunsigned int n;\n\t\
    std::vector<lint> width, min[2], minc, max[2], maxc, sum, lazy;\n\tvoid eval(int\
    \ k) {\n\t\tif (n - 1 <= k) return;\n\t\tif (lazy[k]) {\n\t\t\tupdate_node_add(2\
    \ * k + 1, lazy[k]);\n\t\t\tupdate_node_add(2 * k + 2, lazy[k]);\n\t\t\tlazy[k]\
    \ = 0;\n\t\t}\n\t\tif (max[0][k] < max[0][2 * k + 1]) {\n\t\t\tupdate_node_max(2\
    \ * k + 1, max[0][k]);\n\t\t}\n\t\tif (min[0][k] > min[0][2 * k + 1]) {\n\t\t\t\
    update_node_min(2 * k + 1, min[0][k]);\n\t\t}\n\t\tif (max[0][k] < max[0][2 *\
    \ k + 2]) {\n\t\t\tupdate_node_max(2 * k + 2, max[0][k]);\n\t\t}\n\t\tif (min[0][k]\
    \ > min[0][2 * k + 2]) {\n\t\t\tupdate_node_min(2 * k + 2, min[0][k]);\n\t\t}\n\
    \t}\n\tvoid combine(int k) {\n\t\tsum[k] = sum[2 * k + 1] + sum[2 * k + 2];\n\t\
    \tif (min[0][2 * k + 1] < min[0][2 * k + 2]) {\n\t\t\tmin[0][k] = min[0][2 * k\
    \ + 1];\n\t\t\tminc[k] = minc[2 * k + 1];\n\t\t\tmin[1][k] = std::min(min[1][2\
    \ * k + 1], min[0][2 * k + 2]);\n\t\t} else if (min[0][2 * k + 1] > min[0][2 *\
    \ k + 2]) {\n\t\t\tmin[0][k] = min[0][2 * k + 2];\n\t\t\tminc[k] = minc[2 * k\
    \ + 2];\n\t\t\tmin[1][k] = std::min(min[0][2 * k + 1], min[1][2 * k + 2]);\n\t\
    \t} else {\n\t\t\tmin[0][k] = min[0][2 * k + 1];\n\t\t\tminc[k] = minc[2 * k +\
    \ 1] + minc[2 * k + 2];\n\t\t\tmin[1][k] = std::min(min[1][2 * k + 1], min[1][2\
    \ * k + 2]);\n\t\t}\n\t\tif (max[0][2 * k + 1] > max[0][2 * k + 2]) {\n\t\t\t\
    max[0][k] = max[0][2 * k + 1];\n\t\t\tmaxc[k] = maxc[2 * k + 1];\n\t\t\tmax[1][k]\
    \ = std::max(max[1][2 * k + 1], max[0][2 * k + 2]);\n\t\t} else if (max[0][2 *\
    \ k + 1] < max[0][2 * k + 2]) {\n\t\t\tmax[0][k] = max[0][2 * k + 2];\n\t\t\t\
    maxc[k] = maxc[2 * k + 2];\n\t\t\tmax[1][k] = std::max(max[0][2 * k + 1], max[1][2\
    \ * k + 2]);\n\t\t} else {\n\t\t\tmax[0][k] = max[0][2 * k + 1];\n\t\t\tmaxc[k]\
    \ = maxc[2 * k + 1] + maxc[2 * k + 2];\n\t\t\tmax[1][k] = std::max(max[1][2 *\
    \ k + 1], max[1][2 * k + 2]);\n\t\t}\n\t}\n\tvoid update_node_max(int k, lint\
    \ x) {\n\t\tsum[k] += (x - max[0][k]) * maxc[k];\n\t\tif (max[0][k] == min[0][k])\n\
    \t\t\tmin[0][k] = x;\n\t\telse if (max[0][k] == min[1][k])\n\t\t\tmin[1][k] =\
    \ x;\n\t\tmax[0][k] = x;\n\t}\n\tvoid update_node_min(int k, lint x) {\n\t\tsum[k]\
    \ += (x - min[0][k]) * minc[k];\n\t\tif (min[0][k] == max[0][k])\n\t\t\tmax[0][k]\
    \ = x;\n\t\telse if (min[0][k] == max[1][k])\n\t\t\tmax[1][k] = x;\n\t\tmin[0][k]\
    \ = x;\n\t}\n\tvoid update_node_add(int k, lint x) {\n\t\tmin[0][k] += x;\n\t\t\
    if (min[1][k] != LINF) min[1][k] += x;\n\t\tmax[0][k] += x;\n\t\tif (max[1][k]\
    \ != -LINF) max[1][k] += x;\n\t\tsum[k] += x * width[k];\n\t\tlazy[k] += x;\n\t\
    }\n\n  public:\n\tSegTreeBeats(unsigned int size, lint def = 0) {\n\t\t*this =\
    \ SegTreeBeats(std::vector<lint>(size, def));\n\t}\n\tSegTreeBeats(std::vector<lint>\
    \ initvec) {\n\t\tn = 1;\n\t\twhile (n < initvec.size()) n *= 2;\n\t\twidth.resize(2\
    \ * n - 1);\n\t\tmin[0].resize(2 * n - 1);\n\t\tmin[1].resize(2 * n - 1, LINF);\n\
    \t\tminc.resize(2 * n - 1);\n\t\tmax[0].resize(2 * n - 1);\n\t\tmax[1].resize(2\
    \ * n - 1, -LINF);\n\t\tmaxc.resize(2 * n - 1);\n\t\tsum.resize(2 * n - 1);\n\t\
    \tlazy.resize(2 * n - 1);\n\t\tfor (int i = n - 1; i < n - 1 + initvec.size();\
    \ i++) {\n\t\t\tmin[0][i] = max[0][i] = sum[i] = initvec[i - n + 1];\n\t\t\tminc[i]\
    \ = maxc[i] = 1;\n\t\t}\n\t\tfor (int i = n - 2; i >= 0; i--) {\n\t\t\tcombine(i);\n\
    \t\t}\n\t\twidth[0] = n;\n\t\tREP(i, 2 * n - 2) width[i] = width[(i - 1) / 2]\
    \ / 2;\n\t}\n\tvoid update_chmin(int a, int b, lint x, int k = 0, int l = 0, int\
    \ r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <= l || r <= a || max[0][k] <=\
    \ x) return;\n\t\tif (a <= l && r <= b && max[1][k] < x) {\n\t\t\tupdate_node_max(k,\
    \ x);\n\t\t\treturn;\n\t\t}\n\t\teval(k);\n\t\tupdate_chmin(a, b, x, 2 * k + 1,\
    \ l, (l + r) / 2);\n\t\tupdate_chmin(a, b, x, 2 * k + 2, (l + r) / 2, r);\n\t\t\
    combine(k);\n\t}\n\tvoid update_chmax(int a, int b, lint x, int k = 0, int l =\
    \ 0, int r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <= l || r <= a || x <=\
    \ min[0][k]) return;\n\t\tif (a <= l && r <= b && x < min[1][k]) {\n\t\t\tupdate_node_min(k,\
    \ x);\n\t\t\treturn;\n\t\t}\n\t\teval(k);\n\t\tupdate_chmax(a, b, x, 2 * k + 1,\
    \ l, (l + r) / 2);\n\t\tupdate_chmax(a, b, x, 2 * k + 2, (l + r) / 2, r);\n\t\t\
    combine(k);\n\t}\n\tvoid update_add(int a, int b, lint x, int k = 0, int l = 0,\
    \ int r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <= l || r <= a) return;\n\t\
    \tif (a <= l && r <= b) {\n\t\t\tupdate_node_add(k, x);\n\t\t\treturn;\n\t\t}\n\
    \t\teval(k);\n\t\tupdate_add(a, b, x, 2 * k + 1, l, (l + r) / 2);\n\t\tupdate_add(a,\
    \ b, x, 2 * k + 2, (l + r) / 2, r);\n\t\tcombine(k);\n\t}\n\tvoid update(int a,\
    \ int b, lint x) {\n\t\tupdate_chmin(a, b, x);\n\t\tupdate_chmax(a, b, x);\n\t\
    }\n\tlint query_sum(int a, int b, int k = 0, int l = 0, int r = -1) {\n\t\tif\
    \ (r == -1) r = n;\n\t\tif (b <= l || r <= a) return 0;\n\t\tif (a <= l && r <=\
    \ b) return sum[k];\n\t\teval(k);\n\t\tlint vl = query_sum(a, b, 2 * k + 1, l,\
    \ (l + r) / 2);\n\t\tlint vr = query_sum(a, b, 2 * k + 2, (l + r) / 2, r);\n\t\
    \treturn vl + vr;\n\t}\n\tlint query_min(int a, int b, int k = 0, int l = 0, int\
    \ r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <= l || r <= a) return LINF;\n\
    \t\tif (a <= l && r <= b) return min[0][k];\n\t\teval(k);\n\t\tlint vl = query_min(a,\
    \ b, 2 * k + 1, l, (l + r) / 2);\n\t\tlint vr = query_min(a, b, 2 * k + 2, (l\
    \ + r) / 2, r);\n\t\treturn std::min(vl, vr);\n\t}\n\tlint query_max(int a, int\
    \ b, int k = 0, int l = 0, int r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <=\
    \ l || r <= a) return -LINF;\n\t\tif (a <= l && r <= b) return max[0][k];\n\t\t\
    eval(k);\n\t\tlint vl = query_max(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tlint\
    \ vr = query_max(a, b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn std::max(vl, vr);\n\
    \t}\n};\n\n/**\n * @title Segment Tree Beats\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\nclass SegTreeBeats {\n\t\
    unsigned int n;\n\tstd::vector<lint> width, min[2], minc, max[2], maxc, sum, lazy;\n\
    \tvoid eval(int k) {\n\t\tif (n - 1 <= k) return;\n\t\tif (lazy[k]) {\n\t\t\t\
    update_node_add(2 * k + 1, lazy[k]);\n\t\t\tupdate_node_add(2 * k + 2, lazy[k]);\n\
    \t\t\tlazy[k] = 0;\n\t\t}\n\t\tif (max[0][k] < max[0][2 * k + 1]) {\n\t\t\tupdate_node_max(2\
    \ * k + 1, max[0][k]);\n\t\t}\n\t\tif (min[0][k] > min[0][2 * k + 1]) {\n\t\t\t\
    update_node_min(2 * k + 1, min[0][k]);\n\t\t}\n\t\tif (max[0][k] < max[0][2 *\
    \ k + 2]) {\n\t\t\tupdate_node_max(2 * k + 2, max[0][k]);\n\t\t}\n\t\tif (min[0][k]\
    \ > min[0][2 * k + 2]) {\n\t\t\tupdate_node_min(2 * k + 2, min[0][k]);\n\t\t}\n\
    \t}\n\tvoid combine(int k) {\n\t\tsum[k] = sum[2 * k + 1] + sum[2 * k + 2];\n\t\
    \tif (min[0][2 * k + 1] < min[0][2 * k + 2]) {\n\t\t\tmin[0][k] = min[0][2 * k\
    \ + 1];\n\t\t\tminc[k] = minc[2 * k + 1];\n\t\t\tmin[1][k] = std::min(min[1][2\
    \ * k + 1], min[0][2 * k + 2]);\n\t\t} else if (min[0][2 * k + 1] > min[0][2 *\
    \ k + 2]) {\n\t\t\tmin[0][k] = min[0][2 * k + 2];\n\t\t\tminc[k] = minc[2 * k\
    \ + 2];\n\t\t\tmin[1][k] = std::min(min[0][2 * k + 1], min[1][2 * k + 2]);\n\t\
    \t} else {\n\t\t\tmin[0][k] = min[0][2 * k + 1];\n\t\t\tminc[k] = minc[2 * k +\
    \ 1] + minc[2 * k + 2];\n\t\t\tmin[1][k] = std::min(min[1][2 * k + 1], min[1][2\
    \ * k + 2]);\n\t\t}\n\t\tif (max[0][2 * k + 1] > max[0][2 * k + 2]) {\n\t\t\t\
    max[0][k] = max[0][2 * k + 1];\n\t\t\tmaxc[k] = maxc[2 * k + 1];\n\t\t\tmax[1][k]\
    \ = std::max(max[1][2 * k + 1], max[0][2 * k + 2]);\n\t\t} else if (max[0][2 *\
    \ k + 1] < max[0][2 * k + 2]) {\n\t\t\tmax[0][k] = max[0][2 * k + 2];\n\t\t\t\
    maxc[k] = maxc[2 * k + 2];\n\t\t\tmax[1][k] = std::max(max[0][2 * k + 1], max[1][2\
    \ * k + 2]);\n\t\t} else {\n\t\t\tmax[0][k] = max[0][2 * k + 1];\n\t\t\tmaxc[k]\
    \ = maxc[2 * k + 1] + maxc[2 * k + 2];\n\t\t\tmax[1][k] = std::max(max[1][2 *\
    \ k + 1], max[1][2 * k + 2]);\n\t\t}\n\t}\n\tvoid update_node_max(int k, lint\
    \ x) {\n\t\tsum[k] += (x - max[0][k]) * maxc[k];\n\t\tif (max[0][k] == min[0][k])\n\
    \t\t\tmin[0][k] = x;\n\t\telse if (max[0][k] == min[1][k])\n\t\t\tmin[1][k] =\
    \ x;\n\t\tmax[0][k] = x;\n\t}\n\tvoid update_node_min(int k, lint x) {\n\t\tsum[k]\
    \ += (x - min[0][k]) * minc[k];\n\t\tif (min[0][k] == max[0][k])\n\t\t\tmax[0][k]\
    \ = x;\n\t\telse if (min[0][k] == max[1][k])\n\t\t\tmax[1][k] = x;\n\t\tmin[0][k]\
    \ = x;\n\t}\n\tvoid update_node_add(int k, lint x) {\n\t\tmin[0][k] += x;\n\t\t\
    if (min[1][k] != LINF) min[1][k] += x;\n\t\tmax[0][k] += x;\n\t\tif (max[1][k]\
    \ != -LINF) max[1][k] += x;\n\t\tsum[k] += x * width[k];\n\t\tlazy[k] += x;\n\t\
    }\n\n  public:\n\tSegTreeBeats(unsigned int size, lint def = 0) {\n\t\t*this =\
    \ SegTreeBeats(std::vector<lint>(size, def));\n\t}\n\tSegTreeBeats(std::vector<lint>\
    \ initvec) {\n\t\tn = 1;\n\t\twhile (n < initvec.size()) n *= 2;\n\t\twidth.resize(2\
    \ * n - 1);\n\t\tmin[0].resize(2 * n - 1);\n\t\tmin[1].resize(2 * n - 1, LINF);\n\
    \t\tminc.resize(2 * n - 1);\n\t\tmax[0].resize(2 * n - 1);\n\t\tmax[1].resize(2\
    \ * n - 1, -LINF);\n\t\tmaxc.resize(2 * n - 1);\n\t\tsum.resize(2 * n - 1);\n\t\
    \tlazy.resize(2 * n - 1);\n\t\tfor (int i = n - 1; i < n - 1 + initvec.size();\
    \ i++) {\n\t\t\tmin[0][i] = max[0][i] = sum[i] = initvec[i - n + 1];\n\t\t\tminc[i]\
    \ = maxc[i] = 1;\n\t\t}\n\t\tfor (int i = n - 2; i >= 0; i--) {\n\t\t\tcombine(i);\n\
    \t\t}\n\t\twidth[0] = n;\n\t\tREP(i, 2 * n - 2) width[i] = width[(i - 1) / 2]\
    \ / 2;\n\t}\n\tvoid update_chmin(int a, int b, lint x, int k = 0, int l = 0, int\
    \ r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <= l || r <= a || max[0][k] <=\
    \ x) return;\n\t\tif (a <= l && r <= b && max[1][k] < x) {\n\t\t\tupdate_node_max(k,\
    \ x);\n\t\t\treturn;\n\t\t}\n\t\teval(k);\n\t\tupdate_chmin(a, b, x, 2 * k + 1,\
    \ l, (l + r) / 2);\n\t\tupdate_chmin(a, b, x, 2 * k + 2, (l + r) / 2, r);\n\t\t\
    combine(k);\n\t}\n\tvoid update_chmax(int a, int b, lint x, int k = 0, int l =\
    \ 0, int r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <= l || r <= a || x <=\
    \ min[0][k]) return;\n\t\tif (a <= l && r <= b && x < min[1][k]) {\n\t\t\tupdate_node_min(k,\
    \ x);\n\t\t\treturn;\n\t\t}\n\t\teval(k);\n\t\tupdate_chmax(a, b, x, 2 * k + 1,\
    \ l, (l + r) / 2);\n\t\tupdate_chmax(a, b, x, 2 * k + 2, (l + r) / 2, r);\n\t\t\
    combine(k);\n\t}\n\tvoid update_add(int a, int b, lint x, int k = 0, int l = 0,\
    \ int r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <= l || r <= a) return;\n\t\
    \tif (a <= l && r <= b) {\n\t\t\tupdate_node_add(k, x);\n\t\t\treturn;\n\t\t}\n\
    \t\teval(k);\n\t\tupdate_add(a, b, x, 2 * k + 1, l, (l + r) / 2);\n\t\tupdate_add(a,\
    \ b, x, 2 * k + 2, (l + r) / 2, r);\n\t\tcombine(k);\n\t}\n\tvoid update(int a,\
    \ int b, lint x) {\n\t\tupdate_chmin(a, b, x);\n\t\tupdate_chmax(a, b, x);\n\t\
    }\n\tlint query_sum(int a, int b, int k = 0, int l = 0, int r = -1) {\n\t\tif\
    \ (r == -1) r = n;\n\t\tif (b <= l || r <= a) return 0;\n\t\tif (a <= l && r <=\
    \ b) return sum[k];\n\t\teval(k);\n\t\tlint vl = query_sum(a, b, 2 * k + 1, l,\
    \ (l + r) / 2);\n\t\tlint vr = query_sum(a, b, 2 * k + 2, (l + r) / 2, r);\n\t\
    \treturn vl + vr;\n\t}\n\tlint query_min(int a, int b, int k = 0, int l = 0, int\
    \ r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <= l || r <= a) return LINF;\n\
    \t\tif (a <= l && r <= b) return min[0][k];\n\t\teval(k);\n\t\tlint vl = query_min(a,\
    \ b, 2 * k + 1, l, (l + r) / 2);\n\t\tlint vr = query_min(a, b, 2 * k + 2, (l\
    \ + r) / 2, r);\n\t\treturn std::min(vl, vr);\n\t}\n\tlint query_max(int a, int\
    \ b, int k = 0, int l = 0, int r = -1) {\n\t\tif (r == -1) r = n;\n\t\tif (b <=\
    \ l || r <= a) return -LINF;\n\t\tif (a <= l && r <= b) return max[0][k];\n\t\t\
    eval(k);\n\t\tlint vl = query_max(a, b, 2 * k + 1, l, (l + r) / 2);\n\t\tlint\
    \ vr = query_max(a, b, 2 * k + 2, (l + r) / 2, r);\n\t\treturn std::max(vl, vr);\n\
    \t}\n};\n\n/**\n * @title Segment Tree Beats\n */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/SegTreeBeats.hpp
  requiredBy: []
  timestamp: '2021-07-04 16:12:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: data-structure/SegTreeBeats.hpp
layout: document
redirect_from:
- /library/data-structure/SegTreeBeats.hpp
- /library/data-structure/SegTreeBeats.hpp.html
title: Segment Tree Beats
---
