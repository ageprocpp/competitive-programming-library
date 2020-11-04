---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#pragma target(\"avx2\")\n#pragma optimize(\"\
    O3\")\n#pragma optimize(\"unroll-loops\")\n#include <algorithm>\n#include <bitset>\n\
    #include <cassert>\n#include <cfloat>\n#include <climits>\n#include <cmath>\n\
    #include <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <string.h>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define REP(i,n) for(int\
    \ i=1;i<=(n);i++)\n#define all(V) V.begin(),V.end()\ntypedef unsigned int uint;\n\
    typedef long long lint;\ntypedef unsigned long long ulint;\ntypedef std::pair<int,\
    \ int> P;\ntypedef std::pair<lint, lint> LP;\nconstexpr int INF = INT_MAX/2;\n\
    constexpr lint LINF = LLONG_MAX/2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr\
    \ double PI=3.141592653589793238462643383279;\ntemplate<class T>\nclass prique\
    \ :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};\ntemplate\
    \ <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\tif (lhs < rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ntemplate <class T, class\
    \ U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs) {\n\t\tlhs =\
    \ rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ninline lint gcd(lint a, lint b) {\n\
    \twhile (b) {\n\t\tlint c = a;\n\t\ta = b; b = c % b;\n\t}\n\treturn a;\n}\ninline\
    \ lint lcm(lint a, lint b) {\n\treturn a / gcd(a, b) * b;\n}\nbool isprime(lint\
    \ n) {\n\tif (n == 1)return false;\n\tfor (int i = 2; i * i <= n; i++) {\n\t\t\
    if (n % i == 0)return false;\n\t}\n\treturn true;\n}\ntemplate<typename T>\nT\
    \ mypow(T a, lint b) {\n\tT res(1);\n\twhile(b){\n\t\tif(b&1)res*=a;\n\t\ta*=a;\n\
    \t\tb>>=1;\n\t}\n\treturn res;\n}\nlint modpow(lint a, lint b, lint m) {\n\tlint\
    \ res(1);\n\twhile(b){\n\t\tif(b&1){\n\t\t\tres*=a;res%=m;\n\t\t}\n\t\ta*=a;a%=m;\n\
    \t\tb>>=1;\n\t}\n\treturn res;\n}\ntemplate<typename T>\nvoid printArray(std::vector<T>&\
    \ vec) {\n\trep(i, vec.size()){\n\t\tstd::cout << vec[i];\n\t\tstd::cout<<(i==(int)vec.size()-1?\"\
    \\n\":\" \");\n\t}\n}\ntemplate<typename T>\nvoid printArray(T l, T r) {\n\tT\
    \ rprev = std::prev(r);\n\tfor (T i = l; i != rprev; i++) {\n\t\tstd::cout <<\
    \ *i << \" \";\n\t}\n\tstd::cout << *rprev << std::endl;\n}\nLP extGcd(lint a,lint\
    \ b) {\n\tif(b==0)return {1,0};\n\tLP s=extGcd(b,a%b);\n\tstd::swap(s.first,s.second);\n\
    \ts.second-=a/b*s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1,const lint&\
    \ m1,const lint& b2,const lint& m2) {\n\tlint p=extGcd(m1,m2).first;\n\tlint tmp=(b2-b1)*p%m2;\n\
    \tlint r=(b1+m1*tmp+m1*m2)%(m1*m2);\n\treturn std::make_pair(r,m1*m2);\n}\ntemplate<typename\
    \ F>\ninline constexpr decltype(auto) lambda_fix(F&& f){\n\treturn [f=std::forward<F>(f)](auto&&...\
    \ args){\n\t\treturn f(f,std::forward<decltype(args)>(args)...);\n\t};\n}\n#line\
    \ 3 \"test/yosupo/static_range_sum.test.cpp\"\nint n,q,l,r;\nlint a[500010];\n\
    int main(){\n\tscanf(\"%d%d\",&n,&q);\n\trep(i,n){\n\t\tscanf(\"%lld\",a+i);\n\
    \t\tif(i)a[i]+=a[i-1];\n\t}\n\trep(i,q){\n\t\tscanf(\"%d%d\",&l,&r);\n\t\tprintf(\"\
    %lld\\n\",a[r-1]-(l==0?0:a[l-1]));\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"../../other/template.hpp\"\nint n,q,l,r;\nlint a[500010];\nint main(){\n\t\
    scanf(\"%d%d\",&n,&q);\n\trep(i,n){\n\t\tscanf(\"%lld\",a+i);\n\t\tif(i)a[i]+=a[i-1];\n\
    \t}\n\trep(i,q){\n\t\tscanf(\"%d%d\",&l,&r);\n\t\tprintf(\"%lld\\n\",a[r-1]-(l==0?0:a[l-1]));\n\
    \t}\n\treturn 0;\n}"
  dependsOn:
  - other/template.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-12 16:29:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_sum.test.cpp
- /verify/test/yosupo/static_range_sum.test.cpp.html
title: test/yosupo/static_range_sum.test.cpp
---