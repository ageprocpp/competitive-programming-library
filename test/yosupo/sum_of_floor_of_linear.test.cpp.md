---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic/FloorSum.hpp
    title: algebraic/FloorSum.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#ifdef ONLINE_JUDGE\n#pragma GCC target(\"\
    avx512f\")\n#else\n#pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"\
    O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#include <string.h>\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#define rep(i, n) for (int i = 0; i < int(n); i++)\n#define\
    \ REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(), V.end()\n\
    \nusing uint = unsigned int; \nusing lint = long long;\nusing ulint = unsigned\
    \ long long;\nusing P = std::pair<int, int>;\nusing LP = std::pair<lint, lint>;\n\
    \nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\nconstexpr\
    \ double eps = DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
    \nnamespace std {\n\ttemplate <template <class...> class Temp, class T>\n\tclass\
    \ is_template_with_type_of : public std::false_type {};\n\ttemplate <template\
    \ <class...> class Temp, class... Args>\n\tclass is_template_with_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n\ttemplate <template <auto...>\
    \ class Temp, class T>\n\tclass is_template_with_non_type_of : public std::false_type\
    \ {};\n\ttemplate <template <auto...> class Temp, auto... Args>\n\tclass is_template_with_non_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n};\t// namespace std\ntemplate\
    \ <class T>\nclass prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
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
    \ true;\n}\ntemplate <class T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile (true)\
    \ {\n\t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\
    \t}\n\treturn res;\n}\nlint modpow(lint a, lint b, lint m) {\n\ta %= m;\n\tlint\
    \ res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\
    \t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate\
    \ <class T>\nvoid printArray(const std::vector<T>& vec, char split = ' ') {\n\t\
    rep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout << (i == (int)vec.size()\
    \ - 1 ? '\\n' : split);\n\t}\n}\ntemplate <class T>\nvoid printArray(T l, T r,\
    \ char split = ' ') {\n\tT rprev = std::prev(r);\n\tfor (T i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? '\\n' : split);\n\t\
    }\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b,\
    \ a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\t\
    return s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const\
    \ lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp = (b2 - b1) * p %\
    \ m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn std::make_pair(r,\
    \ m1 * m2);\n}\nint LCS(const std::string& a, const std::string& b) {\n\tauto\
    \ dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\trep(i, a.size()) {\n\t\t\
    rep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j\
    \ + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\t}\n\trep(j,\
    \ b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn dp[a.size()][b.size()];\n\
    }\n#line 2 \"algebraic/FloorSum.hpp\"\nlint FloorSum(lint N, lint M, lint A, lint\
    \ B) {\n\tlint ans = 0;\n\tif (A >= M) {\n\t\tans += (N - 1) * N / 2 * (A / M);\n\
    \t\tA %= M;\n\t}\n\tif (B >= M) {\n\t\tans += B / M * N;\n\t\tB %= M;\n\t}\n\t\
    lint ymax = (A * N + B) / M, xmax = ymax * M - B;\n\tif (ymax == 0) return ans;\n\
    \tans += (N - (xmax + A - 1) / A) * ymax;\n\tans += FloorSum(ymax, A, M, (A -\
    \ xmax % A) % A);\n\treturn ans;\n}\n#line 4 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\
    \nint main() {\n\tint T, N, M, A, B;\n\tscanf(\"%d\", &T);\n\trep(_, T) {\n\t\t\
    scanf(\"%d%d%d%d\", &N, &M, &A, &B);\n\t\tprintf(\"%lld\\n\", FloorSum(N, M, A,\
    \ B));\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n#include \"../../algebraic/FloorSum.hpp\"\n#include \"../../other/template.hpp\"\
    \nint main() {\n\tint T, N, M, A, B;\n\tscanf(\"%d\", &T);\n\trep(_, T) {\n\t\t\
    scanf(\"%d%d%d%d\", &N, &M, &A, &B);\n\t\tprintf(\"%lld\\n\", FloorSum(N, M, A,\
    \ B));\n\t}\n}"
  dependsOn:
  - algebraic/FloorSum.hpp
  - other/template.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2021-01-14 16:55:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp.html
title: test/yosupo/sum_of_floor_of_linear.test.cpp
---
