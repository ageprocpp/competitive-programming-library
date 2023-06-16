---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/predecessor_problem.test.cpp
    title: test/yosupo/predecessor_problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
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
    }\n#line 3 \"data-structure/vanEmdeBoasTree.hpp\"\n\ntemplate <uint bit>\nclass\
    \ vanEmdeBoasTree {\n\tint min = -1, max = -1;\n\tstatic int upper(int x) { return\
    \ x >> bit / 2; }\n\tstatic int lower(int x) { return x & (1 << bit / 2) - 1;\
    \ }\n\tstatic int index(int x, int y) { return (x << bit / 2) | y; }\n\tvanEmdeBoasTree<(bit\
    \ + 1) / 2> summary;\n\tstd::array<vanEmdeBoasTree<bit / 2>, 1 << (bit + 1) /\
    \ 2> cluster;\n\n  public:\n\tvanEmdeBoasTree() = default;\n\tint minimum() const\
    \ { return min; }\n\tint maximum() const { return max; }\n\tbool contains(int\
    \ x) const {\n\t\tif (x == min || x == max) return true;\n\t\treturn cluster[upper(x)].contains(lower(x));\n\
    \t}\n\tint successor(int x) const {\n\t\tif (min != -1 && x < min) return min;\n\
    \t\tconst int x_upper = upper(x), x_lower = lower(x);\n\t\tconst int max_low =\
    \ cluster[x_upper].maximum();\n\t\tif (max_low != -1 && x_lower < max_low)\n\t\
    \t\treturn index(x_upper, cluster[x_upper].successor(x_lower));\n\t\tconst int\
    \ succ_cluster = summary.successor(x_upper);\n\t\tif (succ_cluster == -1) return\
    \ -1;\n\t\treturn index(succ_cluster, cluster[succ_cluster].minimum());\n\t}\n\
    \tint predecessor(int x) const {\n\t\tif (max != -1 && max < x) return max;\n\t\
    \tconst int x_upper = upper(x), x_lower = lower(x);\n\t\tconst int min_low = cluster[x_upper].minimum();\n\
    \t\tif (min_low != -1 && min_low < x_lower)\n\t\t\treturn index(x_upper, cluster[x_upper].predecessor(x_lower));\n\
    \t\tconst int pred_cluster = summary.predecessor(x_upper);\n\t\tif (pred_cluster\
    \ == -1) {\n\t\t\tif (min != -1 && min < x) return min;\n\t\t\treturn -1;\n\t\t\
    }\n\t\treturn index(pred_cluster, cluster[pred_cluster].maximum());\n\t}\n\tvoid\
    \ insert(int x) {\n\t\tif (min == -1) {\n\t\t\tmin = max = x;\n\t\t\treturn;\n\
    \t\t}\n\t\tif (x == min) return;\n\t\tif (x < min) std::swap(x, min);\n\n\t\t\
    const int x_upper = upper(x), x_lower = lower(x);\n\t\tif (cluster[x_upper].minimum()\
    \ == -1) summary.insert(x_upper);\n\t\tcluster[x_upper].insert(x_lower);\n\t\t\
    if (x > max) max = x;\n\t}\n\tvoid erase(int x) {\n\t\tif (min == max) {\n\t\t\
    \tif (x == min) min = max = -1;\n\t\t\treturn;\n\t\t}\n\t\tif (x == min) {\n\t\
    \t\tint first_cluster = summary.minimum();\n\t\t\tx = index(first_cluster, cluster[first_cluster].minimum());\n\
    \t\t\tmin = x;\n\t\t}\n\t\tconst int x_upper = upper(x), x_lower = lower(x);\n\
    \t\tcluster[x_upper].erase(x_lower);\n\t\tif (cluster[x_upper].minimum() == -1)\
    \ {\n\t\t\tsummary.erase(x_upper);\n\t\t\tif (x == max) {\n\t\t\t\tint summary_max\
    \ = summary.maximum();\n\t\t\t\tif (summary_max == -1)\n\t\t\t\t\tmax = min;\n\
    \t\t\t\telse\n\t\t\t\t\tmax = index(summary_max, cluster[summary_max].maximum());\n\
    \t\t\t}\n\t\t} else if (x == max)\n\t\t\tmax = index(x_upper, cluster[x_upper].maximum());\n\
    \t}\n};\n\ntemplate <>\nclass vanEmdeBoasTree<1> {\n\tint min = -1, max = -1;\n\
    \n  public:\n\tvanEmdeBoasTree() {}\n\tint minimum() const { return min; }\n\t\
    int maximum() const { return max; }\n\tbool contains(int x) const {\n\t\tif (x\
    \ == min || x == max) return true;\n\t\treturn false;\n\t}\n\tint successor(int\
    \ x) const {\n\t\tif (x == 0 && max == 1) return 1;\n\t\treturn -1;\n\t}\n\tint\
    \ predecessor(int x) const {\n\t\tif (x == 1 && min == 0) return 0;\n\t\treturn\
    \ -1;\n\t}\n\tvoid insert(int x) {\n\t\tif (min == -1) min = max = x;\n\t\tif\
    \ (x < min) std::swap(x, min);\n\t\tif (x > max) max = x;\n\t}\n\tvoid erase(int\
    \ x) {\n\t\tif (min == max) {\n\t\t\tif (x == min) min = max = -1;\n\t\t\treturn;\n\
    \t\t}\n\t\tif (x == 0)\n\t\t\tmin = max = 1;\n\t\telse\n\t\t\tmin = max = 0;\n\
    \t}\n};\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n\ntemplate <uint bit>\n\
    class vanEmdeBoasTree {\n\tint min = -1, max = -1;\n\tstatic int upper(int x)\
    \ { return x >> bit / 2; }\n\tstatic int lower(int x) { return x & (1 << bit /\
    \ 2) - 1; }\n\tstatic int index(int x, int y) { return (x << bit / 2) | y; }\n\
    \tvanEmdeBoasTree<(bit + 1) / 2> summary;\n\tstd::array<vanEmdeBoasTree<bit /\
    \ 2>, 1 << (bit + 1) / 2> cluster;\n\n  public:\n\tvanEmdeBoasTree() = default;\n\
    \tint minimum() const { return min; }\n\tint maximum() const { return max; }\n\
    \tbool contains(int x) const {\n\t\tif (x == min || x == max) return true;\n\t\
    \treturn cluster[upper(x)].contains(lower(x));\n\t}\n\tint successor(int x) const\
    \ {\n\t\tif (min != -1 && x < min) return min;\n\t\tconst int x_upper = upper(x),\
    \ x_lower = lower(x);\n\t\tconst int max_low = cluster[x_upper].maximum();\n\t\
    \tif (max_low != -1 && x_lower < max_low)\n\t\t\treturn index(x_upper, cluster[x_upper].successor(x_lower));\n\
    \t\tconst int succ_cluster = summary.successor(x_upper);\n\t\tif (succ_cluster\
    \ == -1) return -1;\n\t\treturn index(succ_cluster, cluster[succ_cluster].minimum());\n\
    \t}\n\tint predecessor(int x) const {\n\t\tif (max != -1 && max < x) return max;\n\
    \t\tconst int x_upper = upper(x), x_lower = lower(x);\n\t\tconst int min_low =\
    \ cluster[x_upper].minimum();\n\t\tif (min_low != -1 && min_low < x_lower)\n\t\
    \t\treturn index(x_upper, cluster[x_upper].predecessor(x_lower));\n\t\tconst int\
    \ pred_cluster = summary.predecessor(x_upper);\n\t\tif (pred_cluster == -1) {\n\
    \t\t\tif (min != -1 && min < x) return min;\n\t\t\treturn -1;\n\t\t}\n\t\treturn\
    \ index(pred_cluster, cluster[pred_cluster].maximum());\n\t}\n\tvoid insert(int\
    \ x) {\n\t\tif (min == -1) {\n\t\t\tmin = max = x;\n\t\t\treturn;\n\t\t}\n\t\t\
    if (x == min) return;\n\t\tif (x < min) std::swap(x, min);\n\n\t\tconst int x_upper\
    \ = upper(x), x_lower = lower(x);\n\t\tif (cluster[x_upper].minimum() == -1) summary.insert(x_upper);\n\
    \t\tcluster[x_upper].insert(x_lower);\n\t\tif (x > max) max = x;\n\t}\n\tvoid\
    \ erase(int x) {\n\t\tif (min == max) {\n\t\t\tif (x == min) min = max = -1;\n\
    \t\t\treturn;\n\t\t}\n\t\tif (x == min) {\n\t\t\tint first_cluster = summary.minimum();\n\
    \t\t\tx = index(first_cluster, cluster[first_cluster].minimum());\n\t\t\tmin =\
    \ x;\n\t\t}\n\t\tconst int x_upper = upper(x), x_lower = lower(x);\n\t\tcluster[x_upper].erase(x_lower);\n\
    \t\tif (cluster[x_upper].minimum() == -1) {\n\t\t\tsummary.erase(x_upper);\n\t\
    \t\tif (x == max) {\n\t\t\t\tint summary_max = summary.maximum();\n\t\t\t\tif\
    \ (summary_max == -1)\n\t\t\t\t\tmax = min;\n\t\t\t\telse\n\t\t\t\t\tmax = index(summary_max,\
    \ cluster[summary_max].maximum());\n\t\t\t}\n\t\t} else if (x == max)\n\t\t\t\
    max = index(x_upper, cluster[x_upper].maximum());\n\t}\n};\n\ntemplate <>\nclass\
    \ vanEmdeBoasTree<1> {\n\tint min = -1, max = -1;\n\n  public:\n\tvanEmdeBoasTree()\
    \ {}\n\tint minimum() const { return min; }\n\tint maximum() const { return max;\
    \ }\n\tbool contains(int x) const {\n\t\tif (x == min || x == max) return true;\n\
    \t\treturn false;\n\t}\n\tint successor(int x) const {\n\t\tif (x == 0 && max\
    \ == 1) return 1;\n\t\treturn -1;\n\t}\n\tint predecessor(int x) const {\n\t\t\
    if (x == 1 && min == 0) return 0;\n\t\treturn -1;\n\t}\n\tvoid insert(int x) {\n\
    \t\tif (min == -1) min = max = x;\n\t\tif (x < min) std::swap(x, min);\n\t\tif\
    \ (x > max) max = x;\n\t}\n\tvoid erase(int x) {\n\t\tif (min == max) {\n\t\t\t\
    if (x == min) min = max = -1;\n\t\t\treturn;\n\t\t}\n\t\tif (x == 0)\n\t\t\tmin\
    \ = max = 1;\n\t\telse\n\t\t\tmin = max = 0;\n\t}\n};"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/vanEmdeBoasTree.hpp
  requiredBy: []
  timestamp: '2023-06-16 19:42:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/predecessor_problem.test.cpp
documentation_of: data-structure/vanEmdeBoasTree.hpp
layout: document
title: van Emde Boas Tree
---

整数の集合を高速に扱うデータ構造です。

## Declaration

```cpp
template <uint bit>
class vanEmdeBoasTree;
```

`bit` は扱う整数のビット幅を表し、$1\leq$ `bit` $< 32$ である必要があります。

## Constructor

```cpp
vanEmdeBoasTree() = default;
```

$O(1)$ で動作します。

## Methods

### minimum

```cpp
int minimum() const;
```

最小値を返します。$O(1)$ で動作します。

### maximum

```cpp
int maximum() const;
```

最大値を返します。$O(1)$ で動作します。

### contains

```cpp
bool contains(int x) const;
```

$x$ が集合に含まれるかを返します。$O(\log \mathrm{bit})$ で動作します。

### successor

```cpp
int successor(int x) const;
```
集合に含まれる、$x$ より大きい最小の値を返します。そのような値がない場合は $-1$ を返します。$O(\log \mathrm{bit})$ で動作します。

### predecessor

```cpp
int predecessor(int x) const;
```
集合に含まれる、$x$ より小さい最大の値を返します。そのような値がない場合は $-1$ を返します。$O(\log \mathrm{bit})$ で動作します。

### insert

```cpp
void insert(int x);
```
集合に $x$ が含まれていない場合、挿入します。$O(\log \mathrm{bit})$ で動作します。

### erase

```cpp
void erase(int x);
```
集合に $x$ が含まれていない場合、削除します。$O(\log \mathrm{bit})$ で動作します。
