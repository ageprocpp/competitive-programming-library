---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/RBSTset.hpp
    title: Set based on Randomized Binary Search Tree
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Randomized Binary Search Tree
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
    data-structure/RBST.hpp\"\ntemplate <class T>\nclass RBST {\n\tclass Node {\n\t\
    \  public:\n\t\tNode *left = nullptr, *right = nullptr;\n\t\tT value;\n\t\tsize_t\
    \ size;\n\t};\n\tNode* root = nullptr;\n\tRBST(Node* r) : root(r) {}\n\tstatic\
    \ ulint engine() {\n\t\tstatic ulint cur = std::clock();\n\t\tcur ^= cur << 13;\n\
    \t\tcur ^= cur >> 17;\n\t\tcur ^= cur << 5;\n\t\treturn cur;\n\t}\n\tstatic size_t\
    \ size(Node* trg) { return trg ? trg->size : 0; }\n\tstatic Node* apply(Node*\
    \ trg) {\n\t\ttrg->size = size(trg->left) + size(trg->right) + 1;\n\t\treturn\
    \ trg;\n\t}\n\tstatic Node* merge(Node* left, Node* right) {\n\t\tif (!left) return\
    \ right;\n\t\tif (!right) return left;\n\t\tif (size_t(engine() % (size(left)\
    \ + size(right))) < size(left)) {\n\t\t\tleft->right = merge(left->right, right);\n\
    \t\t\treturn apply(left);\n\t\t} else {\n\t\t\tright->left = merge(left, right->left);\n\
    \t\t\treturn apply(right);\n\t\t}\n\t}\n\tstatic std::pair<Node*, Node*> split(Node*\
    \ trg, int pos) {\n\t\tif (!trg) return {nullptr, nullptr};\n\t\tif (pos <= size(trg->left))\
    \ {\n\t\t\tauto tmp = split(trg->left, pos);\n\t\t\ttrg->left = tmp.second;\n\t\
    \t\treturn {tmp.first, apply(trg)};\n\t\t} else {\n\t\t\tauto tmp = split(trg->right,\
    \ pos - size(trg->left) - 1);\n\t\t\ttrg->right = tmp.first;\n\t\t\treturn {apply(trg),\
    \ tmp.second};\n\t\t}\n\t}\n\tstatic Node* insert(Node* node, int idx, const T&\
    \ val) {\n\t\tauto tmp = split(node, idx);\n\t\treturn merge(merge(tmp.first,\
    \ new Node{nullptr, nullptr, val, 1}),\n\t\t\t\t\t tmp.second);\n\t}\n\tstatic\
    \ Node* erase(Node* node, int idx) {\n\t\tauto left = split(node, idx);\n\t\t\
    auto right = split(left.second, 1);\n\t\tdelete right.first;\n\t\treturn merge(left.first,\
    \ right.second);\n\t}\n\tstatic Node* build(const std::vector<T>& data, int l,\
    \ int r) {\n\t\tif (r == -1) r = data.size();\n\t\tif (data.empty() || l >= r)\
    \ return nullptr;\n\t\tint idx = engine() % (r - l) + l;\n\t\treturn apply(new\
    \ Node{build(data, l, idx), build(data, idx + 1, r),\n\t\t\t\t\t\t\t  data[idx],\
    \ 1});\n\t}\n\tvoid clear(Node* trg) {\n\t\tif (!trg) return;\n\t\tclear(trg->left);\n\
    \t\tclear(trg->right);\n\t\tdelete trg;\n\t}\n\n  public:\n\tRBST() {}\n\tRBST(const\
    \ std::vector<T>& data) { this->build(data); }\n\tRBST merge(const RBST& trg)\
    \ { return RBST(merge(root, trg.root)); }\n\tstd::pair<RBST, RBST> split(int pos)\
    \ {\n\t\tauto tmp = split(root, pos);\n\t\treturn {RBST(tmp.first), RBST(tmp.second)};\n\
    \t}\n\tT& find(int idx) const {\n\t\tNode* cur = root;\n\t\tint cnt = 0;\n\t\t\
    while (true) {\n\t\t\tif (cnt + size(cur->left) == idx)\n\t\t\t\treturn cur->value;\n\
    \t\t\telse if (cnt + size(cur->left) > idx)\n\t\t\t\tcur = cur->left;\n\t\t\t\
    else\n\t\t\t\tcnt += size(cur->left) + 1, cur = cur->right;\n\t\t}\n\t}\n\tvoid\
    \ insert(int idx, const T& val) { root = insert(root, idx, val); }\n\tvoid erase(int\
    \ idx) { root = erase(root, idx); }\n\tint upper_bound(int val) const {\n\t\t\
    Node* cur = root;\n\t\tint res = 0, cnt = 0;\n\t\twhile (cur) {\n\t\t\tif (cur->value\
    \ <= val)\n\t\t\t\tcnt += size(cur->left) + 1, cur = cur->right;\n\t\t\telse {\n\
    \t\t\t\tres += cnt;\n\t\t\t\tcnt = 0;\n\t\t\t\tcur = cur->left;\n\t\t\t}\n\t\t\
    }\n\t\treturn res + cnt;\n\t}\n\tint lower_bound(int val) const {\n\t\tNode* cur\
    \ = root;\n\t\tint res = 0, cnt = 0;\n\t\twhile (cur) {\n\t\t\tif (cur->value\
    \ < val)\n\t\t\t\tcnt += size(cur->left) + 1, cur = cur->right;\n\t\t\telse {\n\
    \t\t\t\tres += cnt;\n\t\t\t\tcnt = 0;\n\t\t\t\tcur = cur->left;\n\t\t\t}\n\t\t\
    }\n\t\treturn res + cnt;\n\t}\n\tvoid build(const std::vector<T>& data) { root\
    \ = build(data, 0, -1); }\n\tvoid clear() {\n\t\tclear(root);\n\t\troot = nullptr;\n\
    \t}\n\tint size() const { return empty() ? 0 : root->size; }\n\tbool empty() const\
    \ { return !root; }\n};\n\n/**\n * @title Randomized Binary Search Tree\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate <class T>\nclass\
    \ RBST {\n\tclass Node {\n\t  public:\n\t\tNode *left = nullptr, *right = nullptr;\n\
    \t\tT value;\n\t\tsize_t size;\n\t};\n\tNode* root = nullptr;\n\tRBST(Node* r)\
    \ : root(r) {}\n\tstatic ulint engine() {\n\t\tstatic ulint cur = std::clock();\n\
    \t\tcur ^= cur << 13;\n\t\tcur ^= cur >> 17;\n\t\tcur ^= cur << 5;\n\t\treturn\
    \ cur;\n\t}\n\tstatic size_t size(Node* trg) { return trg ? trg->size : 0; }\n\
    \tstatic Node* apply(Node* trg) {\n\t\ttrg->size = size(trg->left) + size(trg->right)\
    \ + 1;\n\t\treturn trg;\n\t}\n\tstatic Node* merge(Node* left, Node* right) {\n\
    \t\tif (!left) return right;\n\t\tif (!right) return left;\n\t\tif (size_t(engine()\
    \ % (size(left) + size(right))) < size(left)) {\n\t\t\tleft->right = merge(left->right,\
    \ right);\n\t\t\treturn apply(left);\n\t\t} else {\n\t\t\tright->left = merge(left,\
    \ right->left);\n\t\t\treturn apply(right);\n\t\t}\n\t}\n\tstatic std::pair<Node*,\
    \ Node*> split(Node* trg, int pos) {\n\t\tif (!trg) return {nullptr, nullptr};\n\
    \t\tif (pos <= size(trg->left)) {\n\t\t\tauto tmp = split(trg->left, pos);\n\t\
    \t\ttrg->left = tmp.second;\n\t\t\treturn {tmp.first, apply(trg)};\n\t\t} else\
    \ {\n\t\t\tauto tmp = split(trg->right, pos - size(trg->left) - 1);\n\t\t\ttrg->right\
    \ = tmp.first;\n\t\t\treturn {apply(trg), tmp.second};\n\t\t}\n\t}\n\tstatic Node*\
    \ insert(Node* node, int idx, const T& val) {\n\t\tauto tmp = split(node, idx);\n\
    \t\treturn merge(merge(tmp.first, new Node{nullptr, nullptr, val, 1}),\n\t\t\t\
    \t\t tmp.second);\n\t}\n\tstatic Node* erase(Node* node, int idx) {\n\t\tauto\
    \ left = split(node, idx);\n\t\tauto right = split(left.second, 1);\n\t\tdelete\
    \ right.first;\n\t\treturn merge(left.first, right.second);\n\t}\n\tstatic Node*\
    \ build(const std::vector<T>& data, int l, int r) {\n\t\tif (r == -1) r = data.size();\n\
    \t\tif (data.empty() || l >= r) return nullptr;\n\t\tint idx = engine() % (r -\
    \ l) + l;\n\t\treturn apply(new Node{build(data, l, idx), build(data, idx + 1,\
    \ r),\n\t\t\t\t\t\t\t  data[idx], 1});\n\t}\n\tvoid clear(Node* trg) {\n\t\tif\
    \ (!trg) return;\n\t\tclear(trg->left);\n\t\tclear(trg->right);\n\t\tdelete trg;\n\
    \t}\n\n  public:\n\tRBST() {}\n\tRBST(const std::vector<T>& data) { this->build(data);\
    \ }\n\tRBST merge(const RBST& trg) { return RBST(merge(root, trg.root)); }\n\t\
    std::pair<RBST, RBST> split(int pos) {\n\t\tauto tmp = split(root, pos);\n\t\t\
    return {RBST(tmp.first), RBST(tmp.second)};\n\t}\n\tT& find(int idx) const {\n\
    \t\tNode* cur = root;\n\t\tint cnt = 0;\n\t\twhile (true) {\n\t\t\tif (cnt + size(cur->left)\
    \ == idx)\n\t\t\t\treturn cur->value;\n\t\t\telse if (cnt + size(cur->left) >\
    \ idx)\n\t\t\t\tcur = cur->left;\n\t\t\telse\n\t\t\t\tcnt += size(cur->left) +\
    \ 1, cur = cur->right;\n\t\t}\n\t}\n\tvoid insert(int idx, const T& val) { root\
    \ = insert(root, idx, val); }\n\tvoid erase(int idx) { root = erase(root, idx);\
    \ }\n\tint upper_bound(int val) const {\n\t\tNode* cur = root;\n\t\tint res =\
    \ 0, cnt = 0;\n\t\twhile (cur) {\n\t\t\tif (cur->value <= val)\n\t\t\t\tcnt +=\
    \ size(cur->left) + 1, cur = cur->right;\n\t\t\telse {\n\t\t\t\tres += cnt;\n\t\
    \t\t\tcnt = 0;\n\t\t\t\tcur = cur->left;\n\t\t\t}\n\t\t}\n\t\treturn res + cnt;\n\
    \t}\n\tint lower_bound(int val) const {\n\t\tNode* cur = root;\n\t\tint res =\
    \ 0, cnt = 0;\n\t\twhile (cur) {\n\t\t\tif (cur->value < val)\n\t\t\t\tcnt +=\
    \ size(cur->left) + 1, cur = cur->right;\n\t\t\telse {\n\t\t\t\tres += cnt;\n\t\
    \t\t\tcnt = 0;\n\t\t\t\tcur = cur->left;\n\t\t\t}\n\t\t}\n\t\treturn res + cnt;\n\
    \t}\n\tvoid build(const std::vector<T>& data) { root = build(data, 0, -1); }\n\
    \tvoid clear() {\n\t\tclear(root);\n\t\troot = nullptr;\n\t}\n\tint size() const\
    \ { return empty() ? 0 : root->size; }\n\tbool empty() const { return !root; }\n\
    };\n\n/**\n * @title Randomized Binary Search Tree\n */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/RBST.hpp
  requiredBy:
  - data-structure/RBSTset.hpp
  timestamp: '2021-02-24 00:36:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/RBST.hpp
layout: document
redirect_from:
- /library/data-structure/RBST.hpp
- /library/data-structure/RBST.hpp.html
title: Randomized Binary Search Tree
---
