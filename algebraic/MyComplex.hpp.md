---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebraic/FastFourierTransform.hpp
    title: algebraic/FastFourierTransform.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #pragma target(\"avx2\")\n#pragma optimize(\"O3\")\n#pragma optimize(\"unroll-loops\"\
    )\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n\
    #include <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <string.h>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#define rep(i,n) for(int i=0;i<(n);i++)\n\
    #define REP(i,n) for(int i=1;i<=(n);i++)\n#define all(V) V.begin(),V.end()\ntypedef\
    \ unsigned int uint;\ntypedef long long lint;\ntypedef unsigned long long ulint;\n\
    typedef std::pair<int, int> P;\ntypedef std::pair<lint, lint> LP;\nconstexpr int\
    \ INF = INT_MAX/2;\nconstexpr lint LINF = LLONG_MAX/2;\nconstexpr double eps =\
    \ DBL_EPSILON;\nconstexpr double PI=3.141592653589793238462643383279;\ntemplate<class\
    \ T>\nclass prique :public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {};\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\
    \tif (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ntemplate\
    \ <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ninline lint gcd(lint\
    \ a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b; b = c % b;\n\t}\n\t\
    return a;\n}\ninline lint lcm(lint a, lint b) {\n\treturn a / gcd(a, b) * b;\n\
    }\nbool isprime(lint n) {\n\tif (n == 1)return false;\n\tfor (int i = 2; i * i\
    \ <= n; i++) {\n\t\tif (n % i == 0)return false;\n\t}\n\treturn true;\n}\ntemplate<typename\
    \ T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile(b){\n\t\tif(b&1)res*=a;\n\t\
    \ta*=a;\n\t\tb>>=1;\n\t}\n\treturn res;\n}\nlint modpow(lint a, lint b, lint m)\
    \ {\n\tlint res(1);\n\twhile(b){\n\t\tif(b&1){\n\t\t\tres*=a;res%=m;\n\t\t}\n\t\
    \ta*=a;a%=m;\n\t\tb>>=1;\n\t}\n\treturn res;\n}\ntemplate<typename T>\nvoid printArray(std::vector<T>&\
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
    \ 3 \"algebraic/MyComplex.hpp\"\nclass MyComplex{\n\tdouble realvalue, imagvalue;\n\
    public:\n\tMyComplex() :realvalue(0), imagvalue(0) {}\n\ttemplate<typename T,typename\
    \ U>MyComplex(const T& realvalue, const U& imagvalue) : realvalue(realvalue),\
    \ imagvalue(imagvalue) {}\n\ttemplate<typename T>MyComplex(const T& realvalue)\
    \ : realvalue(realvalue), imagvalue(0) {}\n\ttemplate<typename T>MyComplex(const\
    \ std::complex<T>& c) :realvalue(c.real()), imagvalue(c.imag()) {}\n\tdouble&\
    \ real(){ return this->realvalue; }\n\tdouble& imag(){ return this->imagvalue;\
    \ }\n\tdouble abs()const{ return hypot(realvalue, imagvalue); }\n\tMyComplex&\
    \ operator+=(const MyComplex& rhs) {\n\t\tthis->realvalue += rhs.realvalue;\n\t\
    \tthis->imagvalue += rhs.imagvalue;\n\t\treturn *this;\n\t}\n\tMyComplex& operator-=(const\
    \ MyComplex& rhs) {\n\t\tthis->realvalue -= rhs.realvalue;\n\t\tthis->imagvalue\
    \ -= rhs.imagvalue;\n\t\treturn *this;\n\t}\n\tMyComplex& operator*=(const MyComplex&\
    \ rhs) {\n\t\tdouble pastreal = this->realvalue;\n\t\tthis->realvalue = this->realvalue\
    \ * rhs.realvalue - this->imagvalue * rhs.imagvalue;\n\t\tthis->imagvalue = pastreal\
    \ * rhs.imagvalue + rhs.realvalue * this->imagvalue;\n\t\treturn *this;\n\t}\n\
    \tMyComplex& operator/=(const MyComplex& rhs) {\n\t\t*this *= MyComplex(rhs.realvalue,\
    \ -rhs.imagvalue);\n\t\tdouble dnm = rhs.realvalue * rhs.realvalue - rhs.imagvalue\
    \ * rhs.imagvalue;\n\t\tthis->realvalue /= dnm;\n\t\tthis->imagvalue /= dnm;\n\
    \t\treturn *this;\n\t}\n\n\ttemplate<typename T>MyComplex operator+(const T& rhs)const\
    \ {return MyComplex(*this)+=rhs;}\n\ttemplate<typename T>MyComplex& operator+=(const\
    \ T& rhs)const {return operator+=(MyComplex(rhs));}\n\ttemplate<typename T>MyComplex\
    \ operator-(const T& rhs)const {return MyComplex(*this)-=rhs;}\n\ttemplate<typename\
    \ T>MyComplex& operator-=(const T& rhs)const {return operator-=(MyComplex(rhs));}\n\
    \ttemplate<typename T>MyComplex operator*(const T& rhs)const {return MyComplex(*this)*=rhs;}\n\
    \ttemplate<typename T>MyComplex& operator*=(const T& rhs)const {return operator*=(MyComplex(rhs));}\n\
    \ttemplate<typename T>MyComplex operator/(const T& rhs)const {return MyComplex(*this)/=rhs;}\n\
    \ttemplate<typename T>MyComplex& operator/=(const T& rhs)const {return operator/=(MyComplex(rhs));}\n\
    };\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\nclass MyComplex{\n\tdouble\
    \ realvalue, imagvalue;\npublic:\n\tMyComplex() :realvalue(0), imagvalue(0) {}\n\
    \ttemplate<typename T,typename U>MyComplex(const T& realvalue, const U& imagvalue)\
    \ : realvalue(realvalue), imagvalue(imagvalue) {}\n\ttemplate<typename T>MyComplex(const\
    \ T& realvalue) : realvalue(realvalue), imagvalue(0) {}\n\ttemplate<typename T>MyComplex(const\
    \ std::complex<T>& c) :realvalue(c.real()), imagvalue(c.imag()) {}\n\tdouble&\
    \ real(){ return this->realvalue; }\n\tdouble& imag(){ return this->imagvalue;\
    \ }\n\tdouble abs()const{ return hypot(realvalue, imagvalue); }\n\tMyComplex&\
    \ operator+=(const MyComplex& rhs) {\n\t\tthis->realvalue += rhs.realvalue;\n\t\
    \tthis->imagvalue += rhs.imagvalue;\n\t\treturn *this;\n\t}\n\tMyComplex& operator-=(const\
    \ MyComplex& rhs) {\n\t\tthis->realvalue -= rhs.realvalue;\n\t\tthis->imagvalue\
    \ -= rhs.imagvalue;\n\t\treturn *this;\n\t}\n\tMyComplex& operator*=(const MyComplex&\
    \ rhs) {\n\t\tdouble pastreal = this->realvalue;\n\t\tthis->realvalue = this->realvalue\
    \ * rhs.realvalue - this->imagvalue * rhs.imagvalue;\n\t\tthis->imagvalue = pastreal\
    \ * rhs.imagvalue + rhs.realvalue * this->imagvalue;\n\t\treturn *this;\n\t}\n\
    \tMyComplex& operator/=(const MyComplex& rhs) {\n\t\t*this *= MyComplex(rhs.realvalue,\
    \ -rhs.imagvalue);\n\t\tdouble dnm = rhs.realvalue * rhs.realvalue - rhs.imagvalue\
    \ * rhs.imagvalue;\n\t\tthis->realvalue /= dnm;\n\t\tthis->imagvalue /= dnm;\n\
    \t\treturn *this;\n\t}\n\n\ttemplate<typename T>MyComplex operator+(const T& rhs)const\
    \ {return MyComplex(*this)+=rhs;}\n\ttemplate<typename T>MyComplex& operator+=(const\
    \ T& rhs)const {return operator+=(MyComplex(rhs));}\n\ttemplate<typename T>MyComplex\
    \ operator-(const T& rhs)const {return MyComplex(*this)-=rhs;}\n\ttemplate<typename\
    \ T>MyComplex& operator-=(const T& rhs)const {return operator-=(MyComplex(rhs));}\n\
    \ttemplate<typename T>MyComplex operator*(const T& rhs)const {return MyComplex(*this)*=rhs;}\n\
    \ttemplate<typename T>MyComplex& operator*=(const T& rhs)const {return operator*=(MyComplex(rhs));}\n\
    \ttemplate<typename T>MyComplex operator/(const T& rhs)const {return MyComplex(*this)/=rhs;}\n\
    \ttemplate<typename T>MyComplex& operator/=(const T& rhs)const {return operator/=(MyComplex(rhs));}\n\
    };"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: algebraic/MyComplex.hpp
  requiredBy:
  - algebraic/FastFourierTransform.hpp
  timestamp: '2020-09-12 16:29:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebraic/MyComplex.hpp
layout: document
redirect_from:
- /library/algebraic/MyComplex.hpp
- /library/algebraic/MyComplex.hpp.html
title: algebraic/MyComplex.hpp
---
