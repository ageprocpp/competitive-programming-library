---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/0789.test.cpp
    title: test/yukicoder/0789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ int(n); i++)\n#define REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V)\
    \ V.begin(), V.end()\n\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using uint = unsigned int;\nusing lint = long long;\nusing ulint = unsigned long\
    \ long;\nusing IP = std::pair<int, int>;\nusing LP = std::pair<lint, lint>;\n\n\
    constexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\nconstexpr\
    \ double eps = DBL_EPSILON * 10;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
    \ntemplate <class T>\nclass prique : public std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> {};\nint popcount(uint x) {\n#if __cplusplus >= 202002L\n\t\
    return std::popcount(x);\n#else\n#ifndef __clang__\n\treturn __builtin_popcount(x);\n\
    #endif\n#endif\n\tx = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333)\
    \ + (x >> 2 & 0x33333333);\n\tx = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\t\
    x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x\
    \ >> 16 & 0x0000ffff);\n}\ntemplate <class F>\ninline constexpr decltype(auto)\
    \ lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\
    \treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\ntemplate <class\
    \ T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <class T, class... Args>\nconstexpr auto make_vec(size_t n, Args&&...\
    \ args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(n, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\nstd::istream& operator>>(std::istream& ist, std::pair<T,\
    \ U>& x) {\n\treturn ist >> x.first >> x.second;\n}\ntemplate <class T, class\
    \ U>\nstd::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& x) {\n\
    \treturn ost << x.first << \" \" << x.second;\n}\ntemplate <class Container,\n\
    \t\t  std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t>\
    \ = nullptr>\nauto operator>>(std::istream& ist, Container& cont)\n\t-> decltype(typename\
    \ Container::iterator(), std::cin)& {\n\tContainer tmp;\n\twhile (true) {\n\t\t\
    typename Container::value_type t;\n\t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\
    \tif (getchar() == '\\n') break;\n\t}\n\tcont = Container(std::move(tmp));\n\t\
    return ist;\n}\ntemplate <class Container,\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nauto operator<<(std::ostream&\
    \ ost, const Container& cont)\n\t-> decltype(typename Container::iterator(), std::cout)&\
    \ {\n\tfor (auto it = cont.begin(); it != cont.end(); it++) {\n\t\tif (it != cont.begin())\
    \ ost << ' ';\n\t\tost << *it;\n\t}\n\treturn ost;\n}\ntemplate <class Container>\n\
    auto sum(const Container& cont) -> decltype(typename Container::iterator(), 0LL)\
    \ {\n\tlint res = 0;\n\tfor (auto it = cont.begin(); it != cont.end(); it++) res\
    \ += *it;\n\treturn res;\n}\ntemplate <class T, class U>\nconstexpr inline bool\
    \ chmax(T& lhs, const U& rhs) noexcept {\n\tif (lhs < rhs) {\n\t\tlhs = rhs;\n\
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
    \ m1, const lint& b2, const lint& m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\
    \tlint g = gcd(m1, m2), l = m1 / g * m2;\n\tlint tmp = (b2 - b1) / g * p.first\
    \ % (m2 / g);\n\tlint r = (b1 + m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const\
    \ std::string& a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size()\
    \ + 1, b.size() + 1);\n\trep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i\
    \ + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] ==\
    \ b[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()],\
    \ dp[i][b.size()]);\n\t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\
    \treturn dp[a.size()][b.size()];\n}\ntemplate <class T, std::enable_if_t<std::is_convertible<int,\
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
    }\n#line 3 \"data-structure/DynamicSegTree.hpp\"\ntemplate <class T, T (*nodef)(const\
    \ T &, const T &), T (*ident)(), T (*init)() = ident>\nclass DynamicSegTree {\n\
    \tclass Node {\n\t\tNode *par;\n\t\tstd::shared_ptr<Node> left = nullptr, right\
    \ = nullptr;\n\n\t  public:\n\t\tT value;\n\t\tNode() : value(init()) {}\n\t\t\
    Node(Node *p) : par(p), value(ident()) {}\n\t\tvoid set(const T &v) { value =\
    \ v; }\n\t\tconst T &get() const { return value; }\n\t\tbool exist_left() const\
    \ { return bool(left); }\n\t\tbool exist_right() const { return bool(right); }\n\
    \t\tvoid eval() {\n\t\t\tT l = !exist_left() ? ident() : left->value;\n\t\t\t\
    T r = !exist_right() ? ident() : right->value;\n\t\t\tvalue = nodef(l, r);\n\t\
    \t}\n\t\tauto get_left() {\n\t\t\tif (!exist_left()) left.reset(new Node(this));\n\
    \t\t\treturn left;\n\t\t}\n\t\tauto get_right() {\n\t\t\tif (!exist_right()) right.reset(new\
    \ Node(this));\n\t\t\treturn right;\n\t\t}\n\t\tauto get_parent() const { return\
    \ par; }\n\t};\n\tlint n = 1;\n\tstd::shared_ptr<Node> root;\n\n\tauto ptr_from_id(lint\
    \ id) {\n\t\tauto cur = root;\n\t\tlint width = n >> 1;\n\t\twhile (width) {\n\
    \t\t\tif (id & width)\n\t\t\t\tcur = cur->get_right();\n\t\t\telse\n\t\t\t\tcur\
    \ = cur->get_left();\n\t\t\twidth >>= 1;\n\t\t}\n\t\treturn cur;\n\t}\n\n\tT query(lint\
    \ a, lint b, lint l, lint r, std::shared_ptr<Node> ptr) const {\n\t\tif (r ==\
    \ -1) r = n;\n\t\tif (r <= a || b <= l) return ident();\n\t\tif (a <= l && r <=\
    \ b) return ptr->value;\n\t\tT vl = ptr->exist_left() ? query(a, b, l, (l + r)\
    \ >> 1, ptr->get_left()) : ident();\n\t\tT vr = ptr->exist_right() ? query(a,\
    \ b, (l + r) >> 1, r, ptr->get_right()) : ident();\n\t\treturn nodef(vl, vr);\n\
    \t}\n\n  public:\n\tDynamicSegTree(lint m) {\n\t\twhile (n < m) n <<= 1;\n\t\t\
    root = std::shared_ptr<Node>(new Node);\n\t}\n\tvoid update(lint i, T x) {\n\t\
    \tNode *cur = ptr_from_id(i).get();\n\t\tcur->set(x);\n\t\twhile (cur != root.get())\
    \ {\n\t\t\tcur = cur->get_parent();\n\t\t\tcur->eval();\n\t\t}\n\t}\n\tT query(lint\
    \ l, lint r) const { return query(l, r, 0, n, root); }\n\tconst T &operator[](const\
    \ lint &x) { return ptr_from_id(x)->get(); }\n};\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate <class T, T (*nodef)(const\
    \ T &, const T &), T (*ident)(), T (*init)() = ident>\nclass DynamicSegTree {\n\
    \tclass Node {\n\t\tNode *par;\n\t\tstd::shared_ptr<Node> left = nullptr, right\
    \ = nullptr;\n\n\t  public:\n\t\tT value;\n\t\tNode() : value(init()) {}\n\t\t\
    Node(Node *p) : par(p), value(ident()) {}\n\t\tvoid set(const T &v) { value =\
    \ v; }\n\t\tconst T &get() const { return value; }\n\t\tbool exist_left() const\
    \ { return bool(left); }\n\t\tbool exist_right() const { return bool(right); }\n\
    \t\tvoid eval() {\n\t\t\tT l = !exist_left() ? ident() : left->value;\n\t\t\t\
    T r = !exist_right() ? ident() : right->value;\n\t\t\tvalue = nodef(l, r);\n\t\
    \t}\n\t\tauto get_left() {\n\t\t\tif (!exist_left()) left.reset(new Node(this));\n\
    \t\t\treturn left;\n\t\t}\n\t\tauto get_right() {\n\t\t\tif (!exist_right()) right.reset(new\
    \ Node(this));\n\t\t\treturn right;\n\t\t}\n\t\tauto get_parent() const { return\
    \ par; }\n\t};\n\tlint n = 1;\n\tstd::shared_ptr<Node> root;\n\n\tauto ptr_from_id(lint\
    \ id) {\n\t\tauto cur = root;\n\t\tlint width = n >> 1;\n\t\twhile (width) {\n\
    \t\t\tif (id & width)\n\t\t\t\tcur = cur->get_right();\n\t\t\telse\n\t\t\t\tcur\
    \ = cur->get_left();\n\t\t\twidth >>= 1;\n\t\t}\n\t\treturn cur;\n\t}\n\n\tT query(lint\
    \ a, lint b, lint l, lint r, std::shared_ptr<Node> ptr) const {\n\t\tif (r ==\
    \ -1) r = n;\n\t\tif (r <= a || b <= l) return ident();\n\t\tif (a <= l && r <=\
    \ b) return ptr->value;\n\t\tT vl = ptr->exist_left() ? query(a, b, l, (l + r)\
    \ >> 1, ptr->get_left()) : ident();\n\t\tT vr = ptr->exist_right() ? query(a,\
    \ b, (l + r) >> 1, r, ptr->get_right()) : ident();\n\t\treturn nodef(vl, vr);\n\
    \t}\n\n  public:\n\tDynamicSegTree(lint m) {\n\t\twhile (n < m) n <<= 1;\n\t\t\
    root = std::shared_ptr<Node>(new Node);\n\t}\n\tvoid update(lint i, T x) {\n\t\
    \tNode *cur = ptr_from_id(i).get();\n\t\tcur->set(x);\n\t\twhile (cur != root.get())\
    \ {\n\t\t\tcur = cur->get_parent();\n\t\t\tcur->eval();\n\t\t}\n\t}\n\tT query(lint\
    \ l, lint r) const { return query(l, r, 0, n, root); }\n\tconst T &operator[](const\
    \ lint &x) { return ptr_from_id(x)->get(); }\n};"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/DynamicSegTree.hpp
  requiredBy: []
  timestamp: '2023-01-14 13:46:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0789.test.cpp
documentation_of: data-structure/DynamicSegTree.hpp
layout: document
title: Dynamic Segment Tree
---

Segment Tree で必要な部分だけ追加的にメモリを確保してメモリ使用量を抑えます。

## Declaration
```cpp
template<class T, T (*nodef)(const T&, const T&), T (*ident)(), T (*init)() = ident>
class DynamicSegTree;
```

`T` は扱うデータの型、`nodef` は扱う演算、`ident` は `nodef` の単位元、`init` は各要素の初期値を扱います。
`nodef` は結合法則を満たす必要があります。

## Constructor
```cpp
DynamicSegTree(lint m);
```

長さ $m$ の Segment Tree を構築します。

## Methods

### update
```cpp
void update(lint i, T x);
```

$i$ 番目の要素を $x$ に変更します。$O(\log m)$ で動作します。

### query
```cpp
T query(lint a, lint b);
```

$[l, r)$ に `nodef` を作用させた結果を返します。$O(\log m)$ で動作します。

### operator[]
```cpp
const T& operator[](const lint& x);
```

$x$ 番目の要素への `const` な参照を返します。$O(\log m)$ で動作します。