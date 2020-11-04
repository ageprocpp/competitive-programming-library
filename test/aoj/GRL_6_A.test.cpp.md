---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/FordFulkerson.hpp
    title: graph/FordFulkerson.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\
    \n#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#pragma target(\"\
    avx2\")\n#pragma optimize(\"O3\")\n#pragma optimize(\"unroll-loops\")\n#include\
    \ <algorithm>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
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
    \ 3 \"graph/FordFulkerson.hpp\"\nclass FordFulkerson{\n\tclass edge{\n\tpublic:\n\
    \t\tint to;\n\t\tlint cap;\n\t\tint rev,id;\n\t};\n\tint n,idx=0;\n\tstd::vector<std::vector<edge>>\
    \ vec;\n\tstd::vector<bool> used;\n\tlint dfs(int v,int t,lint f){\n\t\tif(v==t)return\
    \ f;\n\t\tused[v]=true;\n\t\tfor(edge& e:vec[v]){\n\t\t\tif(!used[e.to]&&e.cap>0){\n\
    \t\t\t\tlint d=dfs(e.to,t,std::min(f,e.cap));\n\t\t\t\tif(d){\n\t\t\t\t\te.cap-=d;\n\
    \t\t\t\t\tvec[e.to][e.rev].cap+=d;\n\t\t\t\t\treturn d;\n\t\t\t\t}\n\t\t\t}\n\t\
    \t}\n\t\treturn 0;\n\t}\npublic:\n\tFordFulkerson(int n):n(n){\n\t\tvec.resize(n);\n\
    \t\tused.resize(n);\n\t}\n\tvoid add_edge(int from,int to,lint cap){\n\t\tvec[from].push_back({to,cap,(int)vec[to].size(),-1});\n\
    \t\tvec[to].push_back({from,0,(int)vec[from].size()-1,idx++});\n\t}\n\tlint max_flow(int\
    \ s,int t){\n\t\tlint res=0;\n\t\twhile(true){\n\t\t\tused.assign(n,false);\n\t\
    \t\tlint f=dfs(s,t,LINF);\n\t\t\tif(!f)return res;\n\t\t\tres+=f;\n\t\t}\n\t}\n\
    \tstd::vector<lint> restore()const{\n\t\tstd::vector<lint> res(idx);\n\t\trep(i,n){\n\
    \t\t\tfor(const auto& j:vec[i]){\n\t\t\t\tif(j.id!=-1)res[j.id]=j.cap;\n\t\t\t\
    }\n\t\t}\n\t\treturn res;\n\t}\n};\n#line 4 \"test/aoj/GRL_6_A.test.cpp\"\nint\
    \ v,e;\nint main() {\n\tscanf(\"%d%d\",&v,&e);\n\tFordFulkerson flow(v);\n\trep(i,e){\n\
    \t\tint a,b,c;\n\t\tscanf(\"%d%d%d\",&a,&b,&c);\n\t\tflow.add_edge(a,b,c);\n\t\
    }\n\tprintf(\"%d\\n\",flow.max_flow(0,v-1));\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../graph/FordFulkerson.hpp\"\nint\
    \ v,e;\nint main() {\n\tscanf(\"%d%d\",&v,&e);\n\tFordFulkerson flow(v);\n\trep(i,e){\n\
    \t\tint a,b,c;\n\t\tscanf(\"%d%d%d\",&a,&b,&c);\n\t\tflow.add_edge(a,b,c);\n\t\
    }\n\tprintf(\"%d\\n\",flow.max_flow(0,v-1));\n\treturn 0;\n}"
  dependsOn:
  - other/template.hpp
  - graph/FordFulkerson.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-20 14:20:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---