---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/RBSTset.hpp
    title: data-structure/RBSTset.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #pragma target(\"avx2\")\n#pragma optimize(\"O3\")\n#pragma optimize(\"unroll-loops\"\
    )\n#include <string.h>\n\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n\
    #include <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n\
    #include <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n#define rep(i, n) for\
    \ (int i = 0; i < (n); i++)\n#define REP(i, n) for (int i = 1; i <= (n); i++)\n\
    #define all(V) V.begin(), V.end()\ntypedef unsigned int uint;\ntypedef long long\
    \ lint;\ntypedef unsigned long long ulint;\ntypedef std::pair<int, int> P;\ntypedef\
    \ std::pair<lint, lint> LP;\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint\
    \ LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr double\
    \ PI = 3.141592653589793238462643383279;\ntemplate <class T>\nclass prique : public\
    \ std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\ntemplate <class\
    \ T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\tif (lhs < rhs) {\n\
    \t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class T,\
    \ class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs) {\n\t\t\
    lhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline lint gcd(lint a,\
    \ lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\
    \treturn a;\n}\ninline lint lcm(lint a, lint b) { return a / gcd(a, b) * b; }\n\
    bool isprime(lint n) {\n\tif (n == 1) return false;\n\tfor (int i = 2; i * i <=\
    \ n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\ntemplate\
    \ <typename T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile (b) {\n\t\tif (b\
    \ & 1) res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\nlint modpow(lint\
    \ a, lint b, lint m) {\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\t\
    res *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t\
    }\n\treturn res;\n}\ntemplate <typename T>\nvoid printArray(std::vector<T>& vec)\
    \ {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout << (i ==\
    \ (int)vec.size() - 1 ? \"\\n\" : \" \");\n\t}\n}\ntemplate <typename T>\nvoid\
    \ printArray(T l, T r) {\n\tT rprev = std::prev(r);\n\tfor (T i = l; i != rprev;\
    \ i++) {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == std::prev(rprev) ? \"\\\
    n\" : \" \");\n\t}\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\
    \tLP s = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a /\
    \ b * s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint& m1,\
    \ const lint& b2, const lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint\
    \ tmp = (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\
    \treturn std::make_pair(r, m1 * m2);\n}\ntemplate <typename F>\ninline constexpr\
    \ decltype(auto) lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&...\
    \ args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\n\
    template <typename T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <typename T, class... Args>\nauto make_vec(size_t n, Args&&... args)\
    \ {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\n#line 3 \"data-structure/RBST.hpp\"\ntemplate <typename T>\nclass RBST {\n\t\
    class Node {\n\t  public:\n\t\tNode *left = nullptr, *right = nullptr;\n\t\tT\
    \ value;\n\t\tint size;\n\t};\n\tNode* root = nullptr;\n\tRBST(Node* r) : root(r)\
    \ {}\n\tstatic ulint engine() {\n\t\tstatic ulint cur = std::clock();\n\t\tcur\
    \ ^= cur << 13;\n\t\tcur ^= cur >> 17;\n\t\tcur ^= cur << 5;\n\t\treturn cur;\n\
    \t}\n\tstatic int size(Node* trg) { return trg ? trg->size : 0; }\n\tstatic Node*\
    \ apply(Node* trg) {\n\t\ttrg->size = size(trg->left) + size(trg->right) + 1;\n\
    \t\treturn trg;\n\t}\n\tstatic Node* merge(Node* left, Node* right) {\n\t\tif\
    \ (!left) return right;\n\t\tif (!right) return left;\n\t\tif (engine() % (size(left)\
    \ + size(right)) < size(left)) {\n\t\t\tleft->right = merge(left->right, right);\n\
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
    \ { return !root; }\n};\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate <typename T>\n\
    class RBST {\n\tclass Node {\n\t  public:\n\t\tNode *left = nullptr, *right =\
    \ nullptr;\n\t\tT value;\n\t\tint size;\n\t};\n\tNode* root = nullptr;\n\tRBST(Node*\
    \ r) : root(r) {}\n\tstatic ulint engine() {\n\t\tstatic ulint cur = std::clock();\n\
    \t\tcur ^= cur << 13;\n\t\tcur ^= cur >> 17;\n\t\tcur ^= cur << 5;\n\t\treturn\
    \ cur;\n\t}\n\tstatic int size(Node* trg) { return trg ? trg->size : 0; }\n\t\
    static Node* apply(Node* trg) {\n\t\ttrg->size = size(trg->left) + size(trg->right)\
    \ + 1;\n\t\treturn trg;\n\t}\n\tstatic Node* merge(Node* left, Node* right) {\n\
    \t\tif (!left) return right;\n\t\tif (!right) return left;\n\t\tif (engine() %\
    \ (size(left) + size(right)) < size(left)) {\n\t\t\tleft->right = merge(left->right,\
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
    };"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-structure/RBST.hpp
  requiredBy:
  - data-structure/RBSTset.hpp
  timestamp: '2020-11-24 22:27:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/RBST.hpp
layout: document
redirect_from:
- /library/data-structure/RBST.hpp
- /library/data-structure/RBST.hpp.html
title: data-structure/RBST.hpp
---
