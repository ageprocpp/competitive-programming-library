---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic/DynamicModInt.hpp
    title: algebraic/DynamicModInt.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic/NumberTheoreticTransform.hpp
    title: algebraic/NumberTheoreticTransform.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic/StaticModInt.hpp
    title: algebraic/StaticModInt.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/yosupo/convolution_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n#line 2 \"other/template.hpp\"\
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
    \ 3 \"algebraic/DynamicModInt.hpp\"\nclass DynamicModInt {\n\tlint value;\npublic:\n\
    \tstatic unsigned int modulo;\n\tDynamicModInt() : value(0) {}\n\ttemplate<typename\
    \ T>\n\tDynamicModInt(T value = 0) : value(value) {\n\t\tif (value < 0)value =\
    \ -(lint)(-value % modulo) + modulo;\n\t\tthis->value = value % modulo;\n\t}\n\
    \tstatic inline void setMod(const unsigned int& mod){modulo=mod;}\n\tinline DynamicModInt\
    \ inv()const{return mypow(*this,modulo-2);}\n\tinline operator int()const { return\
    \ value; }\n\tinline DynamicModInt& operator+=(const DynamicModInt& x) {\n\t\t\
    value += x.value;\n\t\tif (value >= modulo)value -= modulo;\n\t\treturn *this;\n\
    \t}\n\tinline DynamicModInt& operator++() {\n\t\tif (value == modulo - 1)value\
    \ = 0;\n\t\telse value++;\n\t\treturn *this;\n\t}\n\tinline DynamicModInt operator++(int){\n\
    \t\tDynamicModInt res=*this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline DynamicModInt\
    \ operator-()const {\n\t\treturn DynamicModInt(0) -= *this;\n\t}\n\tinline DynamicModInt&\
    \ operator-=(const DynamicModInt& x) {\n\t\tvalue -= x.value;\n\t\tif (value <\
    \ 0)value += modulo;\n\t\treturn *this;\n\t}\n\tinline DynamicModInt& operator--()\
    \ {\n\t\tif (value == 0)value = modulo - 1;\n\t\telse value--;\n\t\treturn *this;\n\
    \t}\n\tinline DynamicModInt operator--(int){\n\t\tDynamicModInt res=*this;\n\t\
    \t--*this;\n\t\treturn res;\n\t}\n\tinline DynamicModInt& operator*=(const DynamicModInt&\
    \ x) {\n\t\tvalue = value * x.value % modulo;\n\t\treturn *this;\n\t}\n\tinline\
    \ DynamicModInt& operator/=(const DynamicModInt& rhs) {\n\t\treturn *this*=rhs.inv();\n\
    \t}\n\ttemplate<typename T> DynamicModInt operator+(const T& rhs)const { return\
    \ DynamicModInt(*this) += rhs; }\n\ttemplate<typename T> DynamicModInt& operator+=(const\
    \ T& rhs) { return operator+=(DynamicModInt(rhs)); }\n\ttemplate<typename T> DynamicModInt\
    \ operator-(const T& rhs)const { return DynamicModInt(*this) -= rhs; }\n\ttemplate<typename\
    \ T> DynamicModInt& operator-=(const T& rhs) { return operator-=(DynamicModInt(rhs));\
    \ }\n\ttemplate<typename T> DynamicModInt operator*(const T& rhs)const { return\
    \ DynamicModInt(*this) *= rhs; }\n\ttemplate<typename T> DynamicModInt& operator*=(const\
    \ T& rhs) { return operator*=(DynamicModInt(rhs)); }\n\ttemplate<typename T> DynamicModInt\
    \ operator/(const T& rhs)const { return DynamicModInt(*this) /= rhs; }\n\ttemplate<typename\
    \ T> DynamicModInt& operator/=(const T& rhs) { return operator/=(DynamicModInt(rhs));\
    \ }\n};\nunsigned int DynamicModInt::modulo=1000000007;\nstd::istream& operator>>(std::istream&\
    \ ist, DynamicModInt& x) {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n\
    }\n#line 4 \"algebraic/StaticModInt.hpp\"\ntemplate<unsigned int modulo>\nclass\
    \ StaticModInt {\n\tlint value;\npublic:\n\tstatic constexpr unsigned int mod_value\
    \ = modulo;\n\tStaticModInt() : value(0) {}\n\ttemplate<typename T>\n\tStaticModInt(T\
    \ value = 0) : value(value) {\n\t\tthis -> value = (value < 0 ? -(-value % modulo)\
    \ + modulo : value) % modulo;\n\t}\n\tinline StaticModInt inv()const{return mypow(*this,modulo-2);}\n\
    \tinline operator int()const { return value; }\n\tinline StaticModInt& operator+=(const\
    \ StaticModInt& x) {\n\t\tvalue += x.value;\n\t\tif (value >= modulo)value -=\
    \ modulo;\n\t\treturn *this;\n\t}\n\tinline StaticModInt& operator++() {\n\t\t\
    if (value == modulo - 1)value = 0;\n\t\telse value++;\n\t\treturn *this;\n\t}\n\
    \tinline StaticModInt operator++(int){\n\t\tStaticModInt res=*this;\n\t\t--*this;\n\
    \t\treturn res;\n\t}\n\tinline StaticModInt operator-()const {\n\t\treturn StaticModInt(0)\
    \ -= *this;\n\t}\n\tinline StaticModInt& operator-=(const StaticModInt& x) {\n\
    \t\tvalue -= x.value;\n\t\tif (value < 0)value += modulo;\n\t\treturn *this;\n\
    \t}\n\tinline StaticModInt& operator--() {\n\t\tif (value == 0)value = modulo\
    \ - 1;\n\t\telse value--;\n\t\treturn *this;\n\t}\n\tinline StaticModInt operator--(int){\n\
    \t\tStaticModInt res=*this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline StaticModInt&\
    \ operator*=(const StaticModInt& x) {\n\t\tvalue = value * x.value % modulo;\n\
    \t\treturn *this;\n\t}\n\tinline StaticModInt& operator/=(const StaticModInt&\
    \ rhs) {\n\t\treturn *this*=rhs.inv();\n\t}\n\ttemplate<typename T> StaticModInt\
    \ operator+(const T& rhs)const { return StaticModInt(*this) += rhs; }\n\ttemplate<typename\
    \ T> StaticModInt& operator+=(const T& rhs) { return operator+=(StaticModInt(rhs));\
    \ }\n\ttemplate<typename T> StaticModInt operator-(const T& rhs)const { return\
    \ StaticModInt(*this) -= rhs; }\n\ttemplate<typename T> StaticModInt& operator-=(const\
    \ T& rhs) { return operator-=(StaticModInt(rhs)); }\n\ttemplate<typename T> StaticModInt\
    \ operator*(const T& rhs)const { return StaticModInt(*this) *= rhs; }\n\ttemplate<typename\
    \ T> StaticModInt& operator*=(const T& rhs) { return operator*=(StaticModInt(rhs));\
    \ }\n\ttemplate<typename T> StaticModInt operator/(const T& rhs)const { return\
    \ StaticModInt(*this) /= rhs; }\n\ttemplate<typename T> StaticModInt& operator/=(const\
    \ T& rhs) { return operator/=(StaticModInt(rhs)); }\n};\ntemplate<unsigned int\
    \ modulo>\nstd::istream& operator>>(std::istream& ist, StaticModInt<modulo>& x)\
    \ {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n}\n#line 4 \"algebraic/NumberTheoreticTransform.hpp\"\
    \n//1012924417,5,2^21\n//924844033,5,2^21\n//998244353,3,2^23\n//1224736769,3,2^24\n\
    //167772161,3,2^25\n//469762049,3,2^26\nclass NumberTheoreticTransform{\nprivate:\n\
    \ttemplate<unsigned int modulo>\n\tstatic void ntt(std::vector<StaticModInt<modulo>>&\
    \ a){\n\t\tint sz=a.size();\n\t\tif(sz==1)return;\n\t\tStaticModInt<modulo> root=modulo==924844033||modulo==1012924417?5:3;\n\
    \t\tif(inverse)root=mypow(root,modulo-1-(modulo-1)/sz);\n\t\telse root=mypow(root,(modulo-1)/sz);\n\
    \t\tstd::vector<StaticModInt<modulo>> b(sz),roots((sz>>1)+1,1);\n\t\trep(i,sz>>1)roots[i+1]=roots[i]*root;\n\
    \t\tfor(int i=sz>>1,w=1;w<sz;i>>=1,w<<=1){\n\t\t\tfor(int j=0;j<i;j++){\n\t\t\t\
    \tfor(int k=0;k<w;k++){\n\t\t\t\t\tb[k+((w*j)<<1)]=a[k+w*j]+a[k+w*j+(sz>>1)];\n\
    \t\t\t\t\tb[k+((w*j)<<1)+w]=roots[w*j]*(a[k+w*j]-a[k+w*j+(sz>>1)]);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\tstd::swap(a,b);\n\t\t}\n\t}\npublic:\n\tstatic bool inverse;\n\
    \ttemplate<unsigned int modulo,typename T>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ multiply(std::vector<T> f, std::vector<T> g) {\n\t\tif(f.size()<g.size())std::swap(f,g);\n\
    \t\tstd::vector<StaticModInt<modulo>> nf, ng;\n\t\tint sz=1;\n\t\twhile (sz<f.size()+g.size())sz<<=1;\n\
    \t\tnf.resize(sz);ng.resize(sz);\n\t\trep(i,f.size()) {\n\t\t\tnf[i]=f[i];\n\t\
    \t\tif(i<g.size())ng[i]=g[i];\n\t\t}\n\t\tinverse=false;\n\t\tntt(nf);ntt(ng);\n\
    \t\trep(i, sz)nf[i]*=ng[i];\n\t\tinverse=true;\n\t\tntt(nf);\n\t\tStaticModInt<modulo>\
    \ szinv=StaticModInt<modulo>(sz).inv();\n\t\trep(i,sz)nf[i]*=szinv;\n\t\treturn\
    \ nf;\n\t}\n\ttemplate<typename T>\n\tstatic std::vector<lint> multiply_plain(std::vector<T>\
    \ f,std::vector<T> g){\n\t\tconst unsigned int mod1=998244353,mod2=1224736769;\n\
    \t\tstd::vector<StaticModInt<mod1>> mul1=multiply(f,g);\n\t\tstd::vector<StaticModInt<mod2>>\
    \ mul2=multiply(f,g,mod2);\n\t\tstd::vector<lint> res(mul1.size());\n\t\trep(i,mul1.size())res[i]=ChineseRem(mul1[i],mod1,mul2[i],mod2).first;\n\
    \t\treturn res;\n\t}\n};\nbool NumberTheoreticTransform::inverse=false;\n#line\
    \ 4 \"test/yosupo/convolution_mod.test.cpp\"\nint n,m;\nstd::vector<int> a,b;\n\
    int main(){\n\tscanf(\"%d%d\",&n,&m);\n\ta.resize(n);b.resize(m);\n\trep(i,n)scanf(\"\
    %d\",a.data()+i);\n\trep(i,m)scanf(\"%d\",b.data()+i);\n\tstd::vector<StaticModInt<998244353>>\
    \ c=NumberTheoreticTransform::multiply<998244353>(a,b);\n\trep(i,n+m-1)printf((i==n+m?\"\
    %d\\n\":\"%d \"),c[i]);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../algebraic/NumberTheoreticTransform.hpp\"\
    \nint n,m;\nstd::vector<int> a,b;\nint main(){\n\tscanf(\"%d%d\",&n,&m);\n\ta.resize(n);b.resize(m);\n\
    \trep(i,n)scanf(\"%d\",a.data()+i);\n\trep(i,m)scanf(\"%d\",b.data()+i);\n\tstd::vector<StaticModInt<998244353>>\
    \ c=NumberTheoreticTransform::multiply<998244353>(a,b);\n\trep(i,n+m-1)printf((i==n+m?\"\
    %d\\n\":\"%d \"),c[i]);\n}"
  dependsOn:
  - other/template.hpp
  - algebraic/NumberTheoreticTransform.hpp
  - algebraic/StaticModInt.hpp
  - algebraic/DynamicModInt.hpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2020-11-21 16:06:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod.test.cpp
- /verify/test/yosupo/convolution_mod.test.cpp.html
title: test/yosupo/convolution_mod.test.cpp
---
