---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/WaveletMatrix.hpp
    title: data-structure/WaveletMatrix.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/yosupo/range_kth_smallest.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#ifdef ONLINE_JUDGE\n#pragma GCC target(\"\
    avx512f\")\n#else\n#pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"\
    O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#include <string.h>\n#include <algorithm>\n\
    #include <bitset>\n#include <cassert>\n#include <cfloat>\n#include <climits>\n\
    #include <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n#define rep(i, n) for (int i = 0; i < int(n); i++)\n#define REP(i,\
    \ n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(), V.end()\ntypedef\
    \ unsigned int uint;\ntypedef long long lint;\ntypedef unsigned long long ulint;\n\
    typedef std::pair<int, int> P;\ntypedef std::pair<lint, lint> LP;\nconstexpr int\
    \ INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps\
    \ = DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\nnamespace\
    \ std {\n\ttemplate <template <class...> class Temp, class T>\n\tclass is_template_with_type_of\
    \ : public std::false_type {};\n\ttemplate <template <class...> class Temp, class...\
    \ Args>\n\tclass is_template_with_type_of<Temp, Temp<Args...>> : public std::true_type\
    \ {};\n\ttemplate <template <auto...> class Temp, class T>\n\tclass is_template_with_non_type_of\
    \ : public std::false_type {};\n\ttemplate <template <auto...> class Temp, auto...\
    \ Args>\n\tclass is_template_with_non_type_of<Temp, Temp<Args...>> : public std::true_type\
    \ {};\n};\t// namespace std\ntemplate <class T>\nclass prique : public std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>> {\n};\ntemplate <class F>\ninline constexpr\
    \ decltype(auto) lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&...\
    \ args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\n\
    template <class T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
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
    }\n#line 3 \"data-structure/WaveletMatrix.hpp\"\nclass WaveletMatrix {\n\tclass\
    \ BitVector {\n\t\tstd::vector<bool> vec;\n\t\tstd::vector<int> zerocnt, place[2];\n\
    \n\t  public:\n\t\tBitVector(const std::vector<bool>& vec) : vec(vec) {\n\t\t\t\
    zerocnt.resize(vec.size());\n\t\t\trep(i, vec.size()) {\n\t\t\t\tif (!vec[i])\
    \ {\n\t\t\t\t\tzerocnt[i]++;\n\t\t\t\t\tplace[0].emplace_back(i);\n\t\t\t\t} else\n\
    \t\t\t\t\tplace[1].emplace_back(i);\n\t\t\t\tif (i) zerocnt[i] += zerocnt[i -\
    \ 1];\n\t\t\t}\n\t\t}\n\t\tbool access(int x) const { return vec[x]; }\n\t\tint\
    \ rank(bool b, int x) const {\n\t\t\tif (!b) return zerocnt[x];\n\t\t\treturn\
    \ x + 1 - zerocnt[x];\n\t\t}\n\t\tint select(bool b, int x) const { return place[b][x];\
    \ }\n\t\tunsigned int size() const { return vec.size(); }\n\t};\n\tstd::vector<BitVector>\
    \ bit;\n\tstd::vector<int> bound, head, fvec;\n\n  public:\n\ttemplate <class\
    \ T>\n\tWaveletMatrix(std::vector<T> vec) {\n\t\tfor (int i = 63; i >= 0; i--)\
    \ {\n\t\t\tstd::vector<bool> bvec;\n\t\t\tfor (T j : vec) bvec.emplace_back(j\
    \ & ((lint)1 << i));\n\t\t\tstd::stable_sort(all(vec), [&i](const T& lhs, const\
    \ T& rhs) {\n\t\t\t\treturn (lhs & ((lint)1 << i)) < (rhs & ((lint)1 << i));\n\
    \t\t\t});\n\t\t\tif (!(vec.back() & ((lint)1 << i))) continue;\n\t\t\tbit.emplace_back(bvec);\n\
    \t\t\tbound.emplace_back(std::upper_bound(all(bvec), false) -\n\t\t\t\t\t\t\t\
    \   bvec.begin());\n\t\t}\n\t\tfvec = vec;\n\t\tstd::reverse(all(bit));\n\t\t\
    std::reverse(all(bound));\n\t\thead.resize(vec.size());\n\t\tREP(i, vec.size()\
    \ - 1) {\n\t\t\tif (vec[i - 1] == vec[i])\n\t\t\t\thead[i] = head[i - 1];\n\t\t\
    \telse\n\t\t\t\thead[i] = i;\n\t\t}\n\t}\n\tint rank(int r, lint c) const {\n\t\
    \tfor (int i = bit.size() - 1; i >= 0; i--) {\n\t\t\tr--;\n\t\t\tif (c & ((lint)1\
    \ << i))\n\t\t\t\tr = bit[i].rank(false, bit[i].size() - 1) +\n\t\t\t\t\tbit[i].rank(true,\
    \ r);\n\t\t\telse\n\t\t\t\tr = bit[i].rank(false, r);\n\t\t}\n\t\treturn r - head[r];\n\
    \t}\n\tint quantile(int l, int r, int k) const {\n\t\tfor (int i = bit.size()\
    \ - 1; i >= 0; i--) {\n\t\t\tint zeroc = bit[i].rank(false, r - 1),\n\t\t\t\t\
    onec = bit[i].rank(true, r - 1);\n\t\t\tzeroc -= l == 0 ? 0 : bit[i].rank(false,\
    \ l - 1);\n\t\t\tonec -= l == 0 ? 0 : bit[i].rank(true, l - 1);\n\t\t\tif (k <=\
    \ zeroc) {\n\t\t\t\tl = l == 0 ? 0 : bit[i].rank(false, l - 1);\n\t\t\t\tr = l\
    \ + zeroc;\n\t\t\t} else {\n\t\t\t\tl = bit[i].rank(false, bit[i].size() - 1)\
    \ +\n\t\t\t\t\t(l == 0 ? 0 : bit[i].rank(true, l - 1));\n\t\t\t\tr = l + onec;\n\
    \t\t\t\tk -= zeroc;\n\t\t\t}\n\t\t}\n\t\treturn fvec[l];\n\t}\n};\n#line 4 \"\
    test/yosupo/range_kth_smallest.test.cpp\"\nint n, q;\nstd::vector<int> a;\nint\
    \ main() {\n\tscanf(\"%d%d\", &n, &q);\n\ta.resize(n);\n\trep(i, n) scanf(\"%d\"\
    , a.data() + i);\n\tWaveletMatrix wm(a);\n\trep(i, q) {\n\t\tint l, r, k;\n\t\t\
    scanf(\"%d%d%d\", &l, &r, &k);\n\t\tprintf(\"%d\\n\", wm.quantile(l, r, k + 1));\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include \"../../data-structure/WaveletMatrix.hpp\"\n#include \"../../other/template.hpp\"\
    \nint n, q;\nstd::vector<int> a;\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\t\
    a.resize(n);\n\trep(i, n) scanf(\"%d\", a.data() + i);\n\tWaveletMatrix wm(a);\n\
    \trep(i, q) {\n\t\tint l, r, k;\n\t\tscanf(\"%d%d%d\", &l, &r, &k);\n\t\tprintf(\"\
    %d\\n\", wm.quantile(l, r, k + 1));\n\t}\n}"
  dependsOn:
  - data-structure/WaveletMatrix.hpp
  - other/template.hpp
  isVerificationFile: true
  path: test/yosupo/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2020-12-26 20:49:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_kth_smallest.test.cpp
- /verify/test/yosupo/range_kth_smallest.test.cpp.html
title: test/yosupo/range_kth_smallest.test.cpp
---
