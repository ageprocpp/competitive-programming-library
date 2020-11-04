---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Dijkstra.hpp
    title: graph/Dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo/shortest_path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"other/template.hpp\"\
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
    \ 3 \"graph/Dijkstra.hpp\"\ntemplate<typename T>\nclass Dijkstra{\n\tint N;\n\t\
    std::vector<std::vector<std::pair<int,T>>> vec,rev;\n\tbool exec(int s,int t,std::vector<T>\
    \ &dist){\n\t\tdist.assign(N,std::numeric_limits<T>::max());\n\t\tdist[s]=0;\n\
    \t\tprique<std::pair<T,int>> que;\n\t\tque.push({0,s});\n\t\twhile(!que.empty()){\n\
    \t\t\tauto p=que.top();\n\t\t\tque.pop();\n\t\t\tif(dist[p.second]<p.first)continue;\n\
    \t\t\tfor(auto i:vec[p.second]){\n\t\t\t\tif(chmin(dist[i.first],p.first+i.second)){\n\
    \t\t\t\t\tque.push({dist[i.first],i.first});\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return dist[t]!=std::numeric_limits<T>::max();\n\t}\npublic:\n\tDijkstra(int N):N(N),vec(N),rev(N){}\n\
    \tvoid add_edge(int from,int to,T cost){\n\t\tvec[from].emplace_back(std::pair<int,T>{to,cost});\n\
    \t\trev[to].emplace_back(std::pair<int,T>{from,cost});\n\t}\n\tT get_dist(int\
    \ s,int t){\n\t\treturn get_dist_and_path(s,t).first;\n\t}\n\tstd::vector<int>\
    \ get_path(int s,int t){\n\t\treturn get_dist_and_path(s,t).second;\n\t}\n\tstd::pair<T,std::vector<int>>\
    \ get_dist_and_path(int s,int t){\n\t\tstd::vector<T> dist;\n\t\tstd::vector<int>\
    \ res={t};\n\t\tstd::vector<bool> used(N);\n\t\tif(!exec(s,t,dist))return {-1,{}};\n\
    \t\tused[t]=true;\n\t\tint head=t;\n\t\twhile(head!=s){\n\t\t\tfor(auto i:rev[head]){\n\
    \t\t\t\tif(!used[i.first]&&dist[i.first]+i.second==dist[head]){\n\t\t\t\t\tused[i.first]=true;\n\
    \t\t\t\t\thead=i.first;\n\t\t\t\t\tres.emplace_back(head);\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tstd::reverse(all(res));\n\t\treturn {dist[t],res};\n\
    \t}\n};\n#line 4 \"test/yosupo/shortest_path.test.cpp\"\nint N,M,s,t,a,b,c;\n\
    int main(){\n\tscanf(\"%d%d%d%d\",&N,&M,&s,&t);\n\tDijkstra<lint> d(N);\n\trep(i,M){\n\
    \t\tscanf(\"%d%d%d\",&a,&b,&c);\n\t\td.add_edge(a,b,c);\n\t}\n\tauto res=d.get_dist_and_path(s,t);\n\
    \tif(res.first==-1)puts(\"-1\");\n\telse{\n\t\tprintf(\"%lld %d\\n\",res.first,res.second.size()-1);\n\
    \t\trep(i,res.second.size()-1){\n\t\t\tprintf(\"%d %d\\n\",res.second[i],res.second[i+1]);\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../graph/Dijkstra.hpp\"\nint N,M,s,t,a,b,c;\n\
    int main(){\n\tscanf(\"%d%d%d%d\",&N,&M,&s,&t);\n\tDijkstra<lint> d(N);\n\trep(i,M){\n\
    \t\tscanf(\"%d%d%d\",&a,&b,&c);\n\t\td.add_edge(a,b,c);\n\t}\n\tauto res=d.get_dist_and_path(s,t);\n\
    \tif(res.first==-1)puts(\"-1\");\n\telse{\n\t\tprintf(\"%lld %d\\n\",res.first,res.second.size()-1);\n\
    \t\trep(i,res.second.size()-1){\n\t\t\tprintf(\"%d %d\\n\",res.second[i],res.second[i+1]);\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - other/template.hpp
  - graph/Dijkstra.hpp
  isVerificationFile: true
  path: test/yosupo/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2020-11-04 15:01:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shortest_path.test.cpp
- /verify/test/yosupo/shortest_path.test.cpp.html
title: test/yosupo/shortest_path.test.cpp
---
