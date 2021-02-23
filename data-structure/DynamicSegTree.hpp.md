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
    #ifdef ONLINE_JUDGE\n#pragma GCC target(\"avx512f\")\n#elif defined EVAL\n#else\n\
    #pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n#include <string.h>\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#define rep(i, n) for (int i = 0; i < (n); i++)\n#define\
    \ REP(i, n) for (int i = 1; i <= (n); i++)\n#define all(V) V.begin(), V.end()\n\
    \nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
    using lint = long long;\nusing ulint = unsigned long long;\nusing IP = std::pair<int,\
    \ int>;\nusing LP = std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\n\
    constexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr\
    \ double PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique\
    \ : public std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\ntemplate\
    \ <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f\
    \ = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
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
    \ <class InputIter>\nconstexpr void printArray(InputIter l, InputIter r, char\
    \ split = ' ') {\n\tauto rprev = std::prev(r);\n\tfor (auto i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? '\\n' : split);\n\t\
    }\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b,\
    \ a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\t\
    return s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const\
    \ lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp = (b2 - b1) * p %\
    \ m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn {r, m1 * m2};\n\
    }\nint LCS(const std::string& a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size()\
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
    data-structure/DynamicSegTree.hpp\"\ntemplate <class T, T (*nodef)(const T &,\
    \ const T &), T (*ident)(),\n\t\t  T (*init)() = ident>\nclass DynamicSegTree\
    \ {\n\tclass Node {\n\t\tNode *par;\n\t\tstd::shared_ptr<Node> left = nullptr,\
    \ right = nullptr;\n\n\t  public:\n\t\tT value;\n\t\tNode() : value(init()) {}\n\
    \t\tNode(Node *p) : par(p), value(ident()) {}\n\t\tvoid set(const T &v) { value\
    \ = v; }\n\t\tconst T &get() const { return value; }\n\t\tbool exist_left() const\
    \ { return bool(left); }\n\t\tbool exist_right() const { return bool(right); }\n\
    \t\tvoid eval() {\n\t\t\tT l = !exist_left() ? ident() : left->value;\n\t\t\t\
    T r = !exist_right() ? ident() : right->value;\n\t\t\tvalue = nodef(l, r);\n\t\
    \t}\n\t\tauto get_left() {\n\t\t\tif (!exist_left()) left.reset(new Node(this));\n\
    \t\t\treturn left;\n\t\t}\n\t\tauto get_right() {\n\t\t\tif (!exist_right()) right.reset(new\
    \ Node(this));\n\t\t\treturn right;\n\t\t}\n\t\tauto get_parent() { return par;\
    \ }\n\t};\n\tlint n = 1;\n\tstd::shared_ptr<Node> root;\n\n\tauto ptr_from_id(lint\
    \ id) {\n\t\tauto cur = root;\n\t\tlint width = n >> 1;\n\t\twhile (width) {\n\
    \t\t\tif (id & width)\n\t\t\t\tcur = cur->get_right();\n\t\t\telse\n\t\t\t\tcur\
    \ = cur->get_left();\n\t\t\twidth >>= 1;\n\t\t}\n\t\treturn cur;\n\t}\n\n\tT query(lint\
    \ a, lint b, lint l, lint r, std::shared_ptr<Node> ptr) {\n\t\tif (r == -1) r\
    \ = n;\n\t\tif (r <= a || b <= l) return ident();\n\t\tif (a <= l && r <= b) return\
    \ ptr->value;\n\t\tT vl = ptr->exist_left() ? query(a, b, l, (l + r) >> 1, ptr->get_left())\n\
    \t\t\t\t\t\t\t\t : ident();\n\t\tT vr = ptr->exist_right()\n\t\t\t\t   ? query(a,\
    \ b, (l + r) >> 1, r, ptr->get_right())\n\t\t\t\t   : ident();\n\t\treturn nodef(vl,\
    \ vr);\n\t}\n\n  public:\n\tDynamicSegTree(lint m) {\n\t\twhile (n < m) n <<=\
    \ 1;\n\t\troot = std::shared_ptr<Node>(new Node);\n\t}\n\tvoid update(lint i,\
    \ T x) {\n\t\tNode *cur = ptr_from_id(i).get();\n\t\tcur->set(x);\n\t\twhile (cur\
    \ != root.get()) {\n\t\t\tcur = cur->get_parent();\n\t\t\tcur->eval();\n\t\t}\n\
    \t}\n\tT query(lint a, lint b) { return query(a, b, 0, n, root); }\n\tconst T\
    \ &operator[](const lint &x) { return ptr_from_id(x)->get(); }\n};\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate <class T, T (*nodef)(const\
    \ T &, const T &), T (*ident)(),\n\t\t  T (*init)() = ident>\nclass DynamicSegTree\
    \ {\n\tclass Node {\n\t\tNode *par;\n\t\tstd::shared_ptr<Node> left = nullptr,\
    \ right = nullptr;\n\n\t  public:\n\t\tT value;\n\t\tNode() : value(init()) {}\n\
    \t\tNode(Node *p) : par(p), value(ident()) {}\n\t\tvoid set(const T &v) { value\
    \ = v; }\n\t\tconst T &get() const { return value; }\n\t\tbool exist_left() const\
    \ { return bool(left); }\n\t\tbool exist_right() const { return bool(right); }\n\
    \t\tvoid eval() {\n\t\t\tT l = !exist_left() ? ident() : left->value;\n\t\t\t\
    T r = !exist_right() ? ident() : right->value;\n\t\t\tvalue = nodef(l, r);\n\t\
    \t}\n\t\tauto get_left() {\n\t\t\tif (!exist_left()) left.reset(new Node(this));\n\
    \t\t\treturn left;\n\t\t}\n\t\tauto get_right() {\n\t\t\tif (!exist_right()) right.reset(new\
    \ Node(this));\n\t\t\treturn right;\n\t\t}\n\t\tauto get_parent() { return par;\
    \ }\n\t};\n\tlint n = 1;\n\tstd::shared_ptr<Node> root;\n\n\tauto ptr_from_id(lint\
    \ id) {\n\t\tauto cur = root;\n\t\tlint width = n >> 1;\n\t\twhile (width) {\n\
    \t\t\tif (id & width)\n\t\t\t\tcur = cur->get_right();\n\t\t\telse\n\t\t\t\tcur\
    \ = cur->get_left();\n\t\t\twidth >>= 1;\n\t\t}\n\t\treturn cur;\n\t}\n\n\tT query(lint\
    \ a, lint b, lint l, lint r, std::shared_ptr<Node> ptr) {\n\t\tif (r == -1) r\
    \ = n;\n\t\tif (r <= a || b <= l) return ident();\n\t\tif (a <= l && r <= b) return\
    \ ptr->value;\n\t\tT vl = ptr->exist_left() ? query(a, b, l, (l + r) >> 1, ptr->get_left())\n\
    \t\t\t\t\t\t\t\t : ident();\n\t\tT vr = ptr->exist_right()\n\t\t\t\t   ? query(a,\
    \ b, (l + r) >> 1, r, ptr->get_right())\n\t\t\t\t   : ident();\n\t\treturn nodef(vl,\
    \ vr);\n\t}\n\n  public:\n\tDynamicSegTree(lint m) {\n\t\twhile (n < m) n <<=\
    \ 1;\n\t\troot = std::shared_ptr<Node>(new Node);\n\t}\n\tvoid update(lint i,\
    \ T x) {\n\t\tNode *cur = ptr_from_id(i).get();\n\t\tcur->set(x);\n\t\twhile (cur\
    \ != root.get()) {\n\t\t\tcur = cur->get_parent();\n\t\t\tcur->eval();\n\t\t}\n\
    \t}\n\tT query(lint a, lint b) { return query(a, b, 0, n, root); }\n\tconst T\
    \ &operator[](const lint &x) { return ptr_from_id(x)->get(); }\n};"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/DynamicSegTree.hpp
  requiredBy: []
  timestamp: '2021-02-24 00:36:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/0789.test.cpp
documentation_of: data-structure/DynamicSegTree.hpp
layout: document
redirect_from:
- /library/data-structure/DynamicSegTree.hpp
- /library/data-structure/DynamicSegTree.hpp.html
title: data-structure/DynamicSegTree.hpp
---
