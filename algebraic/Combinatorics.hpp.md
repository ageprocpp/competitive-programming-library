---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Combinatorics/ModCombinatorics
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: DynamicModInt.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n#include \"DynamicModInt.hpp\"\
    \n#include \"StaticModInt.hpp\"\ntemplate <typename T>\nclass Combinatorics {\n\
    \  protected:\n\tstd::vector<T> factorial;\n\tvoid append(int n) noexcept {\n\t\
    \twhile (factorial.size() <= n) {\n\t\t\tfactorial.emplace_back(factorial.back()\
    \ * factorial.size());\n\t\t}\n\t}\n\n  public:\n\tCombinatorics() noexcept :\
    \ factorial(1, 1) {}\n\tCombinatorics(int n) noexcept : factorial(1, 1) { append(n);\
    \ }\n\tvirtual T getComb(int a, int b) noexcept {\n\t\tappend(a);\n\t\treturn\
    \ factorial[a] / factorial[a - b] / factorial[b];\n\t}\n\tvirtual T getDcomb(int\
    \ a, int b) noexcept { return getComb(a + b - 1, b); }\n};\ntemplate <typename\
    \ T, typename std::enable_if_t<\n\t\t\t\t\t\t  std::disjunction_v<std::is_template_with_non_type_of<StaticModInt,\
    \ T>,\n\t\t\t\t\t\t\t\t\t\t\t std::is_same<DynamicModInt, T>>,\n\t\t\t\t\t\t \
    \ std::nullptr_t> = nullptr>\nclass ModCombinatorics : Combinatorics<T> {\n\t\
    using Combinatorics<T>::factorial;\n\tstd::vector<T> inv;\n\tvoid append(int n)\
    \ noexcept {\n\t\tint tmp = factorial.size();\n\t\tif (n < tmp) return;\n\t\t\
    Combinatorics<T>::append(n);\n\t\tinv.resize(n + 1);\n\t\tinv[n] = T(1) / factorial.back();\n\
    \t\tfor (int i = n; i > tmp; i--) inv[i - 1] = inv[i] * i;\n\t}\n\n  public:\n\
    \tModCombinatorics() noexcept : Combinatorics<T>(), inv(1, 1) {}\n\tModCombinatorics(int\
    \ n) noexcept : Combinatorics<T>(n), inv(1, 1) {\n\t\tappend(n);\n\t}\n\tT getComb(int\
    \ a, int b) noexcept override {\n\t\tappend(a);\n\t\treturn factorial[a] * inv[a\
    \ - b] * inv[b];\n\t}\n\tT getDcomb(int a, int b) noexcept override { return getComb(a\
    \ + b - 1, b); }\n\tT perm(int a, int b) noexcept {\n\t\tappend(a);\n\t\treturn\
    \ factorial[a] * inv[a - b];\n\t}\n};\n\n/*\n * @title Combinatorics/ModCombinatorics\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: algebraic/Combinatorics.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebraic/Combinatorics.hpp
layout: document
redirect_from:
- /library/algebraic/Combinatorics.hpp
- /library/algebraic/Combinatorics.hpp.html
title: Combinatorics/ModCombinatorics
---
