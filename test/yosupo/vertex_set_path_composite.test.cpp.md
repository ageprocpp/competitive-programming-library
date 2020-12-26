---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic/DynamicModInt.hpp
    title: algebraic/DynamicModInt.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic/StaticModInt.hpp
    title: algebraic/StaticModInt.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/SegTree.hpp
    title: data-structure/SegTree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/HeavyLightDecomposition.hpp
    title: graph/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo/vertex_set_path_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n#line\
    \ 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifdef ONLINE_JUDGE\n\
    #pragma GCC target(\"avx512f\")\n#else\n#pragma GCC target(\"avx2\")\n#endif\n\
    #pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#include\
    \ <string.h>\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#define rep(i, n) for (int i = 0; i < int(n);\
    \ i++)\n#define REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(),\
    \ V.end()\ntypedef unsigned int uint;\ntypedef long long lint;\ntypedef unsigned\
    \ long long ulint;\ntypedef std::pair<int, int> P;\ntypedef std::pair<lint, lint>\
    \ LP;\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\n\
    constexpr double eps = DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
    namespace std {\n\ttemplate <template <class...> class Temp, class T>\n\tclass\
    \ is_template_with_type_of : public std::false_type {};\n\ttemplate <template\
    \ <class...> class Temp, class... Args>\n\tclass is_template_with_type_of<Temp,\
    \ Temp<Args...>> : public std::true_type {};\n\ttemplate <template <auto...> class\
    \ Temp, class T>\n\tclass is_template_with_non_type_of : public std::false_type\
    \ {};\n\ttemplate <template <auto...> class Temp, auto... Args>\n\tclass is_template_with_non_type_of<Temp,\
    \ Temp<Args...>> : public std::true_type {};\n};\t// namespace std\ntemplate <class\
    \ T>\nclass prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {\n};\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f)\
    \ {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <class T, class... Args>\nauto make_vec(size_t n, Args&&... args)\
    \ {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\t\
    if (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    template <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs\
    \ > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\t\
    b = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) { return a /\
    \ gcd(a, b) * b; }\nbool isprime(lint n) {\n\tif (n == 1) return false;\n\tfor\
    \ (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn\
    \ true;\n}\ntemplate <class T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile (b)\
    \ {\n\t\tif (b & 1) res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn res;\n\
    }\nlint modpow(lint a, lint b, lint m) {\n\ta %= m;\n\tlint res(1);\n\twhile (b)\
    \ {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\
    \ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate <class T>\nvoid printArray(std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <class T>\nvoid printArray(T l, T r, char split = ' ') {\n\tT rprev = std::prev(r);\n\
    \tfor (T i = l; i != r; i++) {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev\
    \ ? '\\n' : split);\n\t}\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return\
    \ {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second\
    \ -= a / b * s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint&\
    \ m1, const lint& b2, const lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\t\
    lint tmp = (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\
    \treturn std::make_pair(r, m1 * m2);\n}\nint LCS(const std::string& a, const std::string&\
    \ b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\trep(i, a.size())\
    \ {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j\
    \ + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\t}\n\trep(j,\
    \ b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn dp[a.size()][b.size()];\n\
    }\n#line 3 \"algebraic/DynamicModInt.hpp\"\nclass DynamicModInt {\n\tlint value;\n\
    \n  public:\n\tstatic uint modulo;\n\tDynamicModInt() : value(0) {}\n\ttemplate\
    \ <class T>\n\tDynamicModInt(T value = 0) : value(value) {\n\t\tif (value < 0)\
    \ value = -(lint)(-value % modulo) + modulo;\n\t\tthis->value = value % modulo;\n\
    \t}\n\tstatic inline void setMod(const uint& mod) { modulo = mod; }\n\tinline\
    \ DynamicModInt inv() const { return mypow(*this, modulo - 2); }\n\tinline operator\
    \ int() const { return value; }\n\tinline DynamicModInt& operator+=(const DynamicModInt&\
    \ x) {\n\t\tvalue += x.value;\n\t\tif (value >= modulo) value -= modulo;\n\t\t\
    return *this;\n\t}\n\tinline DynamicModInt& operator++() {\n\t\tif (value == modulo\
    \ - 1)\n\t\t\tvalue = 0;\n\t\telse\n\t\t\tvalue++;\n\t\treturn *this;\n\t}\n\t\
    inline DynamicModInt operator++(int) {\n\t\tDynamicModInt res = *this;\n\t\t--*this;\n\
    \t\treturn res;\n\t}\n\tinline DynamicModInt operator-() const { return DynamicModInt(0)\
    \ -= *this; }\n\tinline DynamicModInt& operator-=(const DynamicModInt& x) {\n\t\
    \tvalue -= x.value;\n\t\tif (value < 0) value += modulo;\n\t\treturn *this;\n\t\
    }\n\tinline DynamicModInt& operator--() {\n\t\tif (value == 0)\n\t\t\tvalue =\
    \ modulo - 1;\n\t\telse\n\t\t\tvalue--;\n\t\treturn *this;\n\t}\n\tinline DynamicModInt\
    \ operator--(int) {\n\t\tDynamicModInt res = *this;\n\t\t--*this;\n\t\treturn\
    \ res;\n\t}\n\tinline DynamicModInt& operator*=(const DynamicModInt& x) {\n\t\t\
    value = value * x.value % modulo;\n\t\treturn *this;\n\t}\n\tinline DynamicModInt&\
    \ operator/=(const DynamicModInt& rhs) {\n\t\treturn *this *= rhs.inv();\n\t}\n\
    \ttemplate <class T>\n\tDynamicModInt operator+(const T& rhs) const {\n\t\treturn\
    \ DynamicModInt(*this) += rhs;\n\t}\n\ttemplate <class T>\n\tDynamicModInt& operator+=(const\
    \ T& rhs) {\n\t\treturn operator+=(DynamicModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tDynamicModInt operator-(const T& rhs) const {\n\t\treturn DynamicModInt(*this)\
    \ -= rhs;\n\t}\n\ttemplate <class T>\n\tDynamicModInt& operator-=(const T& rhs)\
    \ {\n\t\treturn operator-=(DynamicModInt(rhs));\n\t}\n\ttemplate <class T>\n\t\
    DynamicModInt operator*(const T& rhs) const {\n\t\treturn DynamicModInt(*this)\
    \ *= rhs;\n\t}\n\ttemplate <class T>\n\tDynamicModInt& operator*=(const T& rhs)\
    \ {\n\t\treturn operator*=(DynamicModInt(rhs));\n\t}\n\ttemplate <class T>\n\t\
    DynamicModInt operator/(const T& rhs) const {\n\t\treturn DynamicModInt(*this)\
    \ /= rhs;\n\t}\n\ttemplate <class T>\n\tDynamicModInt& operator/=(const T& rhs)\
    \ {\n\t\treturn operator/=(DynamicModInt(rhs));\n\t}\n};\nuint DynamicModInt::modulo\
    \ = 1000000007;\nstd::istream& operator>>(std::istream& ist, DynamicModInt& x)\
    \ {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n}\n#line 4 \"algebraic/StaticModInt.hpp\"\
    \ntemplate <uint modulo>\nclass StaticModInt {\n\tlint value;\n\n  public:\n\t\
    static constexpr uint mod_value = modulo;\n\tStaticModInt() : value(0) {}\n\t\
    template <class T>\n\tStaticModInt(T value = 0) : value(value) {\n\t\tthis->value\
    \ =\n\t\t\t(value < 0 ? -(-value % modulo) + modulo : value) % modulo;\n\t}\n\t\
    inline StaticModInt inv() const { return mypow(*this, modulo - 2); }\n\tinline\
    \ operator int() const { return value; }\n\tinline StaticModInt& operator+=(const\
    \ StaticModInt& x) {\n\t\tvalue += x.value;\n\t\tif (value >= modulo) value -=\
    \ modulo;\n\t\treturn *this;\n\t}\n\tinline StaticModInt& operator++() {\n\t\t\
    if (value == modulo - 1)\n\t\t\tvalue = 0;\n\t\telse\n\t\t\tvalue++;\n\t\treturn\
    \ *this;\n\t}\n\tinline StaticModInt operator++(int) {\n\t\tStaticModInt res =\
    \ *this;\n\t\t++*this;\n\t\treturn res;\n\t}\n\tinline StaticModInt operator-()\
    \ const { return StaticModInt(0) -= *this; }\n\tinline StaticModInt& operator-=(const\
    \ StaticModInt& x) {\n\t\tvalue -= x.value;\n\t\tif (value < 0) value += modulo;\n\
    \t\treturn *this;\n\t}\n\tinline StaticModInt& operator--() {\n\t\tif (value ==\
    \ 0)\n\t\t\tvalue = modulo - 1;\n\t\telse\n\t\t\tvalue--;\n\t\treturn *this;\n\
    \t}\n\tinline StaticModInt operator--(int) {\n\t\tStaticModInt res = *this;\n\t\
    \t--*this;\n\t\treturn res;\n\t}\n\tinline StaticModInt& operator*=(const StaticModInt&\
    \ x) {\n\t\tvalue = value * x.value % modulo;\n\t\treturn *this;\n\t}\n\tinline\
    \ StaticModInt& operator/=(const StaticModInt& rhs) {\n\t\treturn *this *= rhs.inv();\n\
    \t}\n\ttemplate <class T>\n\tStaticModInt operator+(const T& rhs) const {\n\t\t\
    return StaticModInt(*this) += rhs;\n\t}\n\ttemplate <class T>\n\tStaticModInt&\
    \ operator+=(const T& rhs) {\n\t\treturn operator+=(StaticModInt(rhs));\n\t}\n\
    \ttemplate <class T>\n\tStaticModInt operator-(const T& rhs) const {\n\t\treturn\
    \ StaticModInt(*this) -= rhs;\n\t}\n\ttemplate <class T>\n\tStaticModInt& operator-=(const\
    \ T& rhs) {\n\t\treturn operator-=(StaticModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tStaticModInt operator*(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ *= rhs;\n\t}\n\ttemplate <class T>\n\tStaticModInt& operator*=(const T& rhs)\
    \ {\n\t\treturn operator*=(StaticModInt(rhs));\n\t}\n\ttemplate <class T>\n\t\
    StaticModInt operator/(const T& rhs) const {\n\t\treturn StaticModInt(*this) /=\
    \ rhs;\n\t}\n\ttemplate <class T>\n\tStaticModInt& operator/=(const T& rhs) {\n\
    \t\treturn operator/=(StaticModInt(rhs));\n\t}\n};\ntemplate <uint modulo>\nstd::istream&\
    \ operator>>(std::istream& ist, StaticModInt<modulo>& x) {\n\tlint a;\n\tist >>\
    \ a;\n\tx = a;\n\treturn ist;\n}\n#line 3 \"data-structure/SegTree.hpp\"\ntemplate\
    \ <class T, T (*nodef)(const T&, const T&)>\nclass SegTree {\n  protected:\n\t\
    unsigned int n = 1, rank = 0;\n\tstd::vector<T> node;\n\tT ident;\n\n  public:\n\
    \tSegTree(unsigned int m, T e_) : ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *=\
    \ 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\t}\n\tSegTree(unsigned\
    \ int m, T init, T e_) : ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\
    \trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i = n;\
    \ i < 2 * n; i++) node[i] = init;\n\t\tfor (unsigned int i = n - 1; i > 0; i--)\n\
    \t\t\tnode[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\t}\n\ttemplate <class\
    \ U>\n\tSegTree(const std::vector<U>& initvec, T e_) : ident(e_) {\n\t\tunsigned\
    \ int m = initvec.size();\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\
    \t\t}\n\t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n;\
    \ i++) {\n\t\t\tif (i - n < m) node[i] = initvec[i - n];\n\t\t}\n\t\tfor (unsigned\
    \ int i = n - 1; i > 0; i--)\n\t\t\tnode[i] = nodef(node[i << 1], node[i << 1\
    \ | 1]);\n\t}\n\tvoid update(int i, T x) {\n\t\ti += n;\n\t\tnode[i] = x;\n\t\t\
    while (i != 1) {\n\t\t\ti >>= 1;\n\t\t\tnode[i] = nodef(node[2 * i], node[2 *\
    \ i + 1]);\n\t\t}\n\t}\n\tT query(int l, int r) const {\n\t\tl += n;\n\t\tr +=\
    \ n;\n\t\tT ls = ident, rs = ident;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls\
    \ = nodef(ls, node[l++]);\n\t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\t\t\t\
    l >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\tT operator[](const\
    \ int& x) const { return node[n + x]; }\n\tT queryForAll() const { return node[1];\
    \ }\n\n  private:\n\ttemplate <class F>\n\tint max_right(int st, F& check, T&\
    \ acc, int k, int l, int r) const {\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(acc,\
    \ node[k]);\n\t\t\treturn check(acc) ? -1 : k - n;\n\t\t}\n\t\tint m = (l + r)\
    \ >> 1;\n\t\tif (m <= st) return max_right(st, check, acc, (k << 1) | 1, m, r);\n\
    \t\tif (st <= l && check(nodef(acc, node[k]))) {\n\t\t\tacc = nodef(acc, node[k]);\n\
    \t\t\treturn -1;\n\t\t}\n\t\tint vl = max_right(st, check, acc, k << 1, l, m);\n\
    \t\tif (vl != -1) return vl;\n\t\treturn max_right(st, check, acc, (k << 1) |\
    \ 1, m, r);\n\t}\n\n  public:\n\ttemplate <class F>\n\tint max_right(int st, F\
    \ check) const {\n\t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1,\
    \ 0, n);\n\t}\n\ttemplate <bool (*check)(const T&)>\n\tint max_right(int st) const\
    \ {\n\t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n\
    };\nstatic lint RSQ_nodef(const lint& lhs, const lint& rhs) { return lhs + rhs;\
    \ }\nclass RSQ : public SegTree<lint, RSQ_nodef> {\n\tusing Base = SegTree<lint,\
    \ RSQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\tRSQ(Args&&... args)\
    \ : Base(std::forward<Args>(args)..., 0) {}\n};\nstatic lint RMiQ_nodef(const\
    \ lint& lhs, const lint& rhs) {\n\treturn std::min(lhs, rhs);\n}\nclass RMiQ :\
    \ public SegTree<lint, RMiQ_nodef> {\n\tusing Base = SegTree<lint, RMiQ_nodef>;\n\
    \n  public:\n\ttemplate <class... Args>\n\tRMiQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ LINF) {}\n};\nstatic lint RMaQ_nodef(const lint& lhs, const lint& rhs) {\n\t\
    return std::max(lhs, rhs);\n}\nclass RMaQ : public SegTree<lint, RMaQ_nodef> {\n\
    \tusing Base = SegTree<lint, RMaQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\
    \tRMaQ(Args&&... args) : Base(std::forward<Args>(args)..., -LINF) {}\n};\n#line\
    \ 3 \"graph/HeavyLightDecomposition.hpp\"\nclass HeavyLightDecomposition {\n\t\
    int n, index = 0;\n\tvoid size_dfs(int node) {\n\t\tsize[node] = 1;\n\t\tfor (int&\
    \ i : vec[node]) {\n\t\t\tif (par[node] == i) continue;\n\t\t\tpar[i] = node;\n\
    \t\t\tsize_dfs(i);\n\t\t\tsize[node] += size[i];\n\t\t\tif (size[i] > size[vec[node][0]])\
    \ std::swap(i, vec[node][0]);\n\t\t}\n\t}\n\tvoid build_dfs(int node) {\n\t\t\
    label[node] = index++;\n\t\tfor (int& i : vec[node]) {\n\t\t\tif (par[node] !=\
    \ i) {\n\t\t\t\thead[i] = (i == vec[node][0] ? head[node] : i);\n\t\t\t\tbuild_dfs(i);\n\
    \t\t\t}\n\t\t}\n\t\tlast[node] = index;\n\t}\n\n  public:\n\tstd::vector<std::vector<int>>\
    \ vec;\n\tstd::vector<int> size, par, head, label, last;\n\tHeavyLightDecomposition()\
    \ {}\n\tHeavyLightDecomposition(int m) : n(m) { init(n); }\n\tvoid init(int m)\
    \ {\n\t\tn = m;\n\t\tvec.resize(n);\n\t\tsize.resize(n);\n\t\tpar.resize(n);\n\
    \t\thead.resize(n);\n\t\tlabel.resize(n);\n\t\tlast.resize(n);\n\t}\n\tvoid add_edge(int\
    \ u, int v) {\n\t\tvec[u].emplace_back(v);\n\t\tvec[v].emplace_back(u);\n\t}\n\
    \tvoid build(int root) {\n\t\tstd::fill(all(par), -1);\n\t\tsize_dfs(root);\n\t\
    \tbuild_dfs(root);\n\t}\n\ttemplate <class F>\n\tvoid each_edge(int u, int v,\
    \ const F& func) const {\n\t\twhile (true) {\n\t\t\tif (label[u] > label[v]) std::swap(u,\
    \ v);\n\t\t\tif (head[u] == head[v]) {\n\t\t\t\tif (label[u] != label[v]) func(label[u]\
    \ + 1, label[v]);\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tfunc(label[head[v]], label[v]);\n\
    \t\t\tv = par[head[v]];\n\t\t}\n\t}\n\ttemplate <class F>\n\tvoid each_vertex(int\
    \ u, int v, const F& func) const {\n\t\twhile (true) {\n\t\t\tif (label[u] > label[v])\
    \ std::swap(u, v);\n\t\t\tif (head[u] == head[v]) {\n\t\t\t\tfunc(label[u], label[v]);\n\
    \t\t\t\treturn;\n\t\t\t}\n\t\t\tfunc(label[head[v]], label[v]);\n\t\t\tv = par[head[v]];\n\
    \t\t}\n\t}\n\tint lca(int u, int v) const {\n\t\twhile (true) {\n\t\t\tif (label[u]\
    \ > label[v]) std::swap(u, v);\n\t\t\tif (head[u] == head[v]) return u;\n\t\t\t\
    v = par[head[v]];\n\t\t}\n\t}\n\tvoid clear() {\n\t\tvec.clear();\n\t\tsize.clear();\n\
    \t\tpar.clear();\n\t\thead.clear();\n\t\tlabel.clear();\n\t\tlast.clear();\n\t\
    }\n};\n#line 6 \"test/yosupo/vertex_set_path_composite.test.cpp\"\nusing ModInt\
    \ = StaticModInt<998244353>;\nusing MP = std::pair<ModInt, ModInt>;\nMP nodef(const\
    \ MP& lhs, const MP& rhs) {\n\treturn {lhs.first * rhs.first, lhs.second * rhs.first\
    \ + rhs.second};\n}\nclass MySeg : public SegTree<MP, nodef> {\n\tusing Base =\
    \ SegTree<MP, nodef>;\n\n  public:\n\tMySeg(int n) : Base(n, {1, 0}, {1, 0}) {}\n\
    };\nint n, q;\nP a[200010];\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\trep(i,\
    \ n) scanf(\"%d%d\", &a[i].first, &a[i].second);\n\tHeavyLightDecomposition hld(n);\n\
    \tMySeg st1(n), st2(n);\n\trep(i, n - 1) {\n\t\tint u, v;\n\t\tscanf(\"%d%d\"\
    , &u, &v);\n\t\thld.add_edge(u, v);\n\t}\n\thld.build(0);\n\trep(i, n) {\n\t\t\
    st1.update(hld.label[i], a[i]);\n\t\tst2.update(n - 1 - hld.label[i], a[i]);\n\
    \t}\n\trep(i, q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\
    \tint p, c, d;\n\t\t\tscanf(\"%d%d%d\", &p, &c, &d);\n\t\t\ta[p] = {c, d};\n\t\
    \t\tst1.update(hld.label[p], {c, d});\n\t\t\tst2.update(n - 1 - hld.label[p],\
    \ {c, d});\n\t\t} else {\n\t\t\tint u, v, x;\n\t\t\tscanf(\"%d%d%d\", &u, &v,\
    \ &x);\n\t\t\tint t = hld.lca(u, v);\n\t\t\tstd::pair<ModInt, ModInt> f1 = {1,\
    \ 0}, f2 = {1, 0};\n\t\t\thld.each_vertex(u, t, [&](int l, int r) {\n\t\t\t\t\
    auto p = st2.query(n - 1 - r, n - 1 - l + 1);\n\t\t\t\tf1 = {f1.first * p.first,\
    \ f1.second * p.first + p.second};\n\t\t\t});\n\t\t\tf1 = {f1.first / a[t].first,\n\
    \t\t\t\t  (f1.second - a[t].second) / a[t].first};\n\t\t\thld.each_vertex(t, v,\
    \ [&](int l, int r) {\n\t\t\t\tauto p = st1.query(l, r + 1);\n\t\t\t\tf2 = {p.first\
    \ * f2.first, p.second * f2.first + f2.second};\n\t\t\t});\n\t\t\tf1 = {f1.first\
    \ * f2.first, f1.second * f2.first + f2.second};\n\t\t\tprintf(\"%d\\n\", ModInt(x)\
    \ * f1.first + f1.second);\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"../../algebraic/StaticModInt.hpp\"\n#include \"../../data-structure/SegTree.hpp\"\
    \n#include \"../../graph/HeavyLightDecomposition.hpp\"\n#include \"../../other/template.hpp\"\
    \nusing ModInt = StaticModInt<998244353>;\nusing MP = std::pair<ModInt, ModInt>;\n\
    MP nodef(const MP& lhs, const MP& rhs) {\n\treturn {lhs.first * rhs.first, lhs.second\
    \ * rhs.first + rhs.second};\n}\nclass MySeg : public SegTree<MP, nodef> {\n\t\
    using Base = SegTree<MP, nodef>;\n\n  public:\n\tMySeg(int n) : Base(n, {1, 0},\
    \ {1, 0}) {}\n};\nint n, q;\nP a[200010];\nint main() {\n\tscanf(\"%d%d\", &n,\
    \ &q);\n\trep(i, n) scanf(\"%d%d\", &a[i].first, &a[i].second);\n\tHeavyLightDecomposition\
    \ hld(n);\n\tMySeg st1(n), st2(n);\n\trep(i, n - 1) {\n\t\tint u, v;\n\t\tscanf(\"\
    %d%d\", &u, &v);\n\t\thld.add_edge(u, v);\n\t}\n\thld.build(0);\n\trep(i, n) {\n\
    \t\tst1.update(hld.label[i], a[i]);\n\t\tst2.update(n - 1 - hld.label[i], a[i]);\n\
    \t}\n\trep(i, q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\
    \tint p, c, d;\n\t\t\tscanf(\"%d%d%d\", &p, &c, &d);\n\t\t\ta[p] = {c, d};\n\t\
    \t\tst1.update(hld.label[p], {c, d});\n\t\t\tst2.update(n - 1 - hld.label[p],\
    \ {c, d});\n\t\t} else {\n\t\t\tint u, v, x;\n\t\t\tscanf(\"%d%d%d\", &u, &v,\
    \ &x);\n\t\t\tint t = hld.lca(u, v);\n\t\t\tstd::pair<ModInt, ModInt> f1 = {1,\
    \ 0}, f2 = {1, 0};\n\t\t\thld.each_vertex(u, t, [&](int l, int r) {\n\t\t\t\t\
    auto p = st2.query(n - 1 - r, n - 1 - l + 1);\n\t\t\t\tf1 = {f1.first * p.first,\
    \ f1.second * p.first + p.second};\n\t\t\t});\n\t\t\tf1 = {f1.first / a[t].first,\n\
    \t\t\t\t  (f1.second - a[t].second) / a[t].first};\n\t\t\thld.each_vertex(t, v,\
    \ [&](int l, int r) {\n\t\t\t\tauto p = st1.query(l, r + 1);\n\t\t\t\tf2 = {p.first\
    \ * f2.first, p.second * f2.first + f2.second};\n\t\t\t});\n\t\t\tf1 = {f1.first\
    \ * f2.first, f1.second * f2.first + f2.second};\n\t\t\tprintf(\"%d\\n\", ModInt(x)\
    \ * f1.first + f1.second);\n\t\t}\n\t}\n}"
  dependsOn:
  - algebraic/StaticModInt.hpp
  - other/template.hpp
  - algebraic/DynamicModInt.hpp
  - data-structure/SegTree.hpp
  - graph/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2020-12-26 20:49:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_set_path_composite.test.cpp
- /verify/test/yosupo/vertex_set_path_composite.test.cpp.html
title: test/yosupo/vertex_set_path_composite.test.cpp
---
