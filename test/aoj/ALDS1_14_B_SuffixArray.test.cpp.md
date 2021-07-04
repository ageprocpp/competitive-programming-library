---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.hpp
    title: Suffix array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B_SuffixArray.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n#ifdef ONLINE_JUDGE\n#pragma\
    \ GCC target(\"avx512f\")\n#elif defined EVAL\n#else\n#pragma GCC target(\"avx2\"\
    )\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#endif\n#include <string.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cfloat>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define rep(i,\
    \ n) for (int i = 0; i < int(n); i++)\n#define REP(i, n) for (int i = 1; i <=\
    \ int(n); i++)\n#define all(V) V.begin(), V.end()\n\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing uint = unsigned int;\nusing lint = long long;\n\
    using ulint = unsigned long long;\nusing IP = std::pair<int, int>;\nusing LP =\
    \ std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF\
    \ = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON * 10;\nconstexpr double\
    \ PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique :\
    \ public std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\nint popcount(uint\
    \ x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n#else\n#ifndef\
    \ __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\tx = (x & 0x55555555)\
    \ + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >> 2 & 0x33333333);\n\t\
    x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x & 0x00ff00ff) + (x >>\
    \ 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);\n}\ntemplate\
    \ <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f\
    \ = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class\
    \ U>\nstd::istream& operator>>(std::istream& ist, std::pair<T, U>& x) {\n\treturn\
    \ ist >> x.first >> x.second;\n}\ntemplate <class T, class U>\nstd::ostream& operator<<(std::ostream&\
    \ ost, const std::pair<T, U>& x) {\n\treturn ost << x.first << \" \" << x.second;\n\
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
    \ m) noexcept {\n\ta %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\
    \t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\
    \t}\n\treturn res;\n}\ntemplate <class T>\nconstexpr void printArray(const std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <class InputIter>\nconstexpr void printArray(InputIter l, InputIter r, char\
    \ split = ' ') {\n\tauto rprev = std::prev(r);\n\tfor (auto i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? '\\n' : split);\n\t\
    }\n}\nLP extGcd(lint a, lint b) noexcept {\n\tif (b == 0) return {1, 0};\n\tLP\
    \ s = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b\
    \ * s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const\
    \ lint& b2,\n\t\t\t  const lint& m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\t\
    lint g = gcd(m1, m2), l = m1 / g * m2;\n\tlint tmp = (b2 - b1) / g * p.first %\
    \ (m2 / g);\n\tlint r = (b1 + m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const\
    \ std::string& a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size()\
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
    string/SuffixArray.hpp\"\nclass SuffixArray {\n\tstd::string S;\n\tstd::vector<int>\
    \ SA;\n\tstd::vector<int> InducedSorting(const std::vector<int> &S, int count)\
    \ {\n\t\tstd::vector<int> SA(S.size(), -1);\n\t\tstd::vector<char> type = AssignType(S);\n\
    \t\tstd::vector<int> bucket = GetBucket(S, count);\n\t\tstd::vector<int> nextLms(S.size(),\
    \ -1), orderedLms;\n\t\tint lastLms = -1;\n\t\trep(i, S.size()) {\n\t\t\tif (type[i]\
    \ == 2) {\n\t\t\t\tSA[--bucket[S[i]]] = i;\n\t\t\t\tif (lastLms != -1) nextLms[lastLms]\
    \ = i;\n\t\t\t\tlastLms = i;\n\t\t\t\torderedLms.emplace_back(i);\n\t\t\t}\n\t\
    \t}\n\t\tnextLms[lastLms] = lastLms;\n\t\tSortL(S, SA, type, count);\n\t\tSortS(S,\
    \ SA, type, count);\n\t\tstd::vector<int> lms;\n\t\tfor (int i : SA) {\n\t\t\t\
    if (type[i] == 2) lms.emplace_back(i);\n\t\t}\n\t\tint nowrank = 0;\n\t\tstd::vector<int>\
    \ newS = {0};\n\t\tREP(i, lms.size() - 1) {\n\t\t\tint pre = lms[i - 1], now =\
    \ lms[i];\n\t\t\tif (nextLms[pre] - pre != nextLms[now] - now)\n\t\t\t\tnewS.emplace_back(++nowrank);\n\
    \t\t\telse {\n\t\t\t\tbool flag = false;\n\t\t\t\trep(j, nextLms[pre] - pre +\
    \ 1) {\n\t\t\t\t\tif (S[pre + j] != S[now + j]) {\n\t\t\t\t\t\tflag = true;\n\t\
    \t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tif (flag) nowrank++;\n\t\t\t\
    \tnewS.emplace_back(nowrank);\n\t\t\t}\n\t\t}\n\t\tif (nowrank + 1 != lms.size())\
    \ {\n\t\t\tstd::vector<int> V(S.size(), -1);\n\t\t\trep(i, lms.size()) V[lms[i]]\
    \ = newS[i];\n\t\t\tnewS.clear();\n\t\t\trep(i, S.size()) {\n\t\t\t\tif (V[i]\
    \ != -1) newS.emplace_back(V[i]);\n\t\t\t}\n\t\t\tstd::vector<int> SA_ = InducedSorting(newS,\
    \ nowrank + 1);\n\t\t\trep(i, SA_.size()) lms[i] = orderedLms[SA_[i]];\n\t\t}\n\
    \t\tSA.assign(S.size(), -1);\n\t\tbucket = GetBucket(S, count);\n\t\tfor (int\
    \ i = lms.size() - 1; i >= 0; i--)\n\t\t\tSA[--bucket[S[lms[i]]]] = lms[i];\n\t\
    \tSortL(S, SA, type, count);\n\t\tSortS(S, SA, type, count);\n\t\treturn SA;\n\
    \t}\n\tstd::vector<char> AssignType(const std::vector<int> &S) {\n\t\tstd::vector<char>\
    \ type(S.size());\n\t\ttype.back() = 2;\n\t\tfor (int i = (int)S.size() - 2; i\
    \ >= 0; i--) {\n\t\t\tif (S[i] < S[i + 1])\n\t\t\t\ttype[i] = 0;\n\t\t\telse if\
    \ (S[i] > S[i + 1]) {\n\t\t\t\ttype[i] = 1;\n\t\t\t\tif (type[i + 1] == 0) type[i\
    \ + 1] = 2;\n\t\t\t} else\n\t\t\t\ttype[i] = type[i + 1];\n\t\t}\n\t\treturn type;\n\
    \t}\n\tstd::vector<int> GetBucket(const std::vector<int> &S, int count) {\n\t\t\
    std::vector<int> bucket(count);\n\t\tfor (int i : S) bucket[i]++;\n\t\trep(i,\
    \ count - 1) bucket[i + 1] += bucket[i];\n\t\treturn bucket;\n\t}\n\tvoid SortL(const\
    \ std::vector<int> &S, std::vector<int> &SA,\n\t\t\t   const std::vector<char>\
    \ &type, int count) {\n\t\tstd::vector<int> bucket = GetBucket(S, count);\n\t\t\
    for (int i : SA) {\n\t\t\tif (i > 0 && type[i - 1] == 1) SA[bucket[S[i - 1] -\
    \ 1]++] = i - 1;\n\t\t}\n\t}\n\tvoid SortS(const std::vector<int> &S, std::vector<int>\
    \ &SA,\n\t\t\t   const std::vector<char> &type, int count) {\n\t\tstd::vector<int>\
    \ bucket = GetBucket(S, count);\n\t\tfor (int i = S.size() - 1; i >= 0; i--) {\n\
    \t\t\tint j = SA[i];\n\t\t\tif (j > 0 && (type[j - 1] == 0 || type[j - 1] == 2))\n\
    \t\t\t\tSA[--bucket[S[j - 1]]] = j - 1;\n\t\t}\n\t}\n\tint match(const std::string\
    \ &T, int index) const {\n\t\trep(i, T.size()) {\n\t\t\tif (i + index >= S.size())\
    \ return 1;\n\t\t\tif (S[i + index] < T[i]) return 1;\n\t\t\tif (S[i + index]\
    \ > T[i]) return -1;\n\t\t}\n\t\treturn 0;\n\t}\n\n  public:\n\tSuffixArray(const\
    \ std::string &S) : S(S) {\n\t\tstd::vector<int> conv;\n\t\tint min = INF, max\
    \ = -INF;\n\t\tfor (char i : S) {\n\t\t\tchmin(min, i);\n\t\t\tchmax(max, i);\n\
    \t\t}\n\t\tfor (char i : S) conv.emplace_back(i - min + 1);\n\t\tconv.emplace_back(0);\n\
    \t\tSA = InducedSorting(conv, max - min + 2);\n\t}\n\tIP occ(const std::string\
    \ &T) const {\n\t\tint minl = 0, maxl = S.size() + 1;\n\t\twhile (minl + 1 < maxl)\
    \ {\n\t\t\tint mid = (minl + maxl) / 2;\n\t\t\tif (match(T, SA[mid]) <= 0)\n\t\
    \t\t\tmaxl = mid;\n\t\t\telse\n\t\t\t\tminl = mid;\n\t\t}\n\t\tint minr = 0, maxr\
    \ = S.size() + 1;\n\t\twhile (minr + 1 < maxr) {\n\t\t\tint mid = (minr + maxr)\
    \ / 2;\n\t\t\tif (match(T, SA[mid]) < 0)\n\t\t\t\tmaxr = mid;\n\t\t\telse\n\t\t\
    \t\tminr = mid;\n\t\t}\n\t\treturn {maxl, maxr};\n\t}\n\tstd::vector<int> locate(const\
    \ std::string &T) const {\n\t\tstd::vector<bool> v(S.size() + 1);\n\t\tstd::vector<int>\
    \ res;\n\t\tIP range = occ(T);\n\t\tfor (int i = range.first; i < range.second;\
    \ i++) v[SA[i]] = true;\n\t\trep(i, S.size() + 1) {\n\t\t\tif (v[i]) res.emplace_back(i);\n\
    \t\t}\n\t\treturn res;\n\t}\n\toperator std::vector<int>() const { return SA;\
    \ }\n};\n\n/**\n * @title Suffix array\n */\n#line 4 \"test/aoj/ALDS1_14_B_SuffixArray.test.cpp\"\
    \nstd::string t, p;\nint main() {\n\tstd::cin >> t >> p;\n\tSuffixArray sa(t);\n\
    \tstd::vector<int> vec = sa.locate(p);\n\tfor (int i : vec) printf(\"%d\\n\",\
    \ i);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\
    #include \"../../other/template.hpp\"\n#include \"../../string/SuffixArray.hpp\"\
    \nstd::string t, p;\nint main() {\n\tstd::cin >> t >> p;\n\tSuffixArray sa(t);\n\
    \tstd::vector<int> vec = sa.locate(p);\n\tfor (int i : vec) printf(\"%d\\n\",\
    \ i);\n}"
  dependsOn:
  - other/template.hpp
  - string/SuffixArray.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B_SuffixArray.test.cpp
  requiredBy: []
  timestamp: '2021-07-04 16:12:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B_SuffixArray.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B_SuffixArray.test.cpp
- /verify/test/aoj/ALDS1_14_B_SuffixArray.test.cpp.html
title: test/aoj/ALDS1_14_B_SuffixArray.test.cpp
---
