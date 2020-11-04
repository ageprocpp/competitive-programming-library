---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
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
    \ 3 \"string/Trie.hpp\"\ntemplate<int char_size,int base>\nclass Trie{\n\tclass\
    \ Node{\n\tpublic:\n\t\tstd::vector<int> next;\n\t\tint c,cnt=0,lastcnt=0;\n\t\
    \tNode(int c_):c(c_){next.assign(char_size,-1);}\n\t};\nprotected:\n\tstd::vector<Node>\
    \ nodes;\npublic:\n\tTrie():nodes(1,0){}\n\tvoid insert(const std::string &word,int\
    \ word_id){\n\t\tint node_id=0;\n\t\tfor(char i:word){\n\t\t\tint c=i-base;\n\t\
    \t\tint &next_id=nodes[node_id].next[c];\n\t\t\tif(next_id==-1){\n\t\t\t\tnext_id=nodes.size();\n\
    \t\t\t\tnodes.push_back(Node(c));\n\t\t\t}\n\t\t\tnodes[node_id].cnt++;\n\t\t\t\
    node_id=next_id;\n\t\t}\n\t\tnodes[node_id].cnt++;\n\t\tnodes[node_id].lastcnt++;\n\
    \t}\n\tvoid insert(const std::string &word){insert(word,nodes[0].cnt);}\n\tvoid\
    \ erase(const std::string &word){\n\t\tstd::vector<int> path;\n\t\tpath.reserve(word.size());\n\
    \t\tint node_id=0;\n\t\tfor(char i:word){\n\t\t\tint c=i-base;\n\t\t\tif(nodes[node_id].next[c]==-1||nodes[node_id].cnt==0)return;\n\
    \t\t\tpath.emplace_back(node_id);\n\t\t\tnode_id=nodes[node_id].next[c];\n\t\t\
    }\n\t\tnodes[node_id].lastcnt--;\n\t\tnodes[node_id].cnt--;\n\t\tfor(int i:path)nodes[i].cnt--;\n\
    \t}\n\tbool search(const std::string &word,bool prefix=false)const{\n\t\tint node_id=0;\n\
    \t\tfor(char i:word){\n\t\t\tint c=i-base;\n\t\t\tif(nodes[node_id].next[c]==-1||nodes[node_id].cnt==0)return\
    \ false;\n\t\t\tnode_id=nodes[node_id].next[c];\n\t\t}\n\t\treturn prefix||nodes[node_id].lastcnt;\n\
    \t}\n\tbool start_with(const std::string& prefix)const{return search(prefix,true);}\n\
    \tint size()const{return nodes[0].cnt;}\n};\ntemplate<unsigned int bit>\nclass\
    \ BinaryTrie:public Trie<2,'0'>{\npublic:\n\tvoid insert(int n){Trie<2,'0'>::insert(std::bitset<bit>(n).to_string());}\n\
    \tvoid erase(int n){Trie<2,'0'>::erase(std::bitset<bit>(n).to_string());}\n\t\
    bool search(int n,bool prefix=false)const{return Trie<2,'0'>::search(std::bitset<bit>(n).to_string());}\n\
    \tbool start_with(int n)const{return Trie<2,'0'>::start_with(std::bitset<bit>(n).to_string());}\n\
    \tint xor_min(int n)const{\n\t\tint node_id=0,res=0;\n\t\tstd::string binary=std::bitset<bit>(n).to_string();\n\
    \t\trep(i,bit){\n\t\t\tint c=binary[i]-'0';\n\t\t\tif(nodes[node_id].next[c]==-1||nodes[nodes[node_id].next[c]].cnt==0){\n\
    \t\t\t\tres+=1<<(bit-i-1);\n\t\t\t\tnode_id=nodes[node_id].next[1-c];\n\t\t\t\
    }\n\t\t\telse node_id=nodes[node_id].next[c];\n\t\t}\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate<int char_size,int\
    \ base>\nclass Trie{\n\tclass Node{\n\tpublic:\n\t\tstd::vector<int> next;\n\t\
    \tint c,cnt=0,lastcnt=0;\n\t\tNode(int c_):c(c_){next.assign(char_size,-1);}\n\
    \t};\nprotected:\n\tstd::vector<Node> nodes;\npublic:\n\tTrie():nodes(1,0){}\n\
    \tvoid insert(const std::string &word,int word_id){\n\t\tint node_id=0;\n\t\t\
    for(char i:word){\n\t\t\tint c=i-base;\n\t\t\tint &next_id=nodes[node_id].next[c];\n\
    \t\t\tif(next_id==-1){\n\t\t\t\tnext_id=nodes.size();\n\t\t\t\tnodes.push_back(Node(c));\n\
    \t\t\t}\n\t\t\tnodes[node_id].cnt++;\n\t\t\tnode_id=next_id;\n\t\t}\n\t\tnodes[node_id].cnt++;\n\
    \t\tnodes[node_id].lastcnt++;\n\t}\n\tvoid insert(const std::string &word){insert(word,nodes[0].cnt);}\n\
    \tvoid erase(const std::string &word){\n\t\tstd::vector<int> path;\n\t\tpath.reserve(word.size());\n\
    \t\tint node_id=0;\n\t\tfor(char i:word){\n\t\t\tint c=i-base;\n\t\t\tif(nodes[node_id].next[c]==-1||nodes[node_id].cnt==0)return;\n\
    \t\t\tpath.emplace_back(node_id);\n\t\t\tnode_id=nodes[node_id].next[c];\n\t\t\
    }\n\t\tnodes[node_id].lastcnt--;\n\t\tnodes[node_id].cnt--;\n\t\tfor(int i:path)nodes[i].cnt--;\n\
    \t}\n\tbool search(const std::string &word,bool prefix=false)const{\n\t\tint node_id=0;\n\
    \t\tfor(char i:word){\n\t\t\tint c=i-base;\n\t\t\tif(nodes[node_id].next[c]==-1||nodes[node_id].cnt==0)return\
    \ false;\n\t\t\tnode_id=nodes[node_id].next[c];\n\t\t}\n\t\treturn prefix||nodes[node_id].lastcnt;\n\
    \t}\n\tbool start_with(const std::string& prefix)const{return search(prefix,true);}\n\
    \tint size()const{return nodes[0].cnt;}\n};\ntemplate<unsigned int bit>\nclass\
    \ BinaryTrie:public Trie<2,'0'>{\npublic:\n\tvoid insert(int n){Trie<2,'0'>::insert(std::bitset<bit>(n).to_string());}\n\
    \tvoid erase(int n){Trie<2,'0'>::erase(std::bitset<bit>(n).to_string());}\n\t\
    bool search(int n,bool prefix=false)const{return Trie<2,'0'>::search(std::bitset<bit>(n).to_string());}\n\
    \tbool start_with(int n)const{return Trie<2,'0'>::start_with(std::bitset<bit>(n).to_string());}\n\
    \tint xor_min(int n)const{\n\t\tint node_id=0,res=0;\n\t\tstd::string binary=std::bitset<bit>(n).to_string();\n\
    \t\trep(i,bit){\n\t\t\tint c=binary[i]-'0';\n\t\t\tif(nodes[node_id].next[c]==-1||nodes[nodes[node_id].next[c]].cnt==0){\n\
    \t\t\t\tres+=1<<(bit-i-1);\n\t\t\t\tnode_id=nodes[node_id].next[1-c];\n\t\t\t\
    }\n\t\t\telse node_id=nodes[node_id].next[c];\n\t\t}\n\t\treturn res;\n\t}\n};"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: string/Trie.hpp
  requiredBy: []
  timestamp: '2020-11-04 15:01:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/set_xor_min.test.cpp
documentation_of: string/Trie.hpp
layout: document
redirect_from:
- /library/string/Trie.hpp
- /library/string/Trie.hpp.html
title: string/Trie.hpp
---