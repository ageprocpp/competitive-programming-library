---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../other/template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include \"../../data-structure/BIT.hpp\"\n#include \"../../graph/HeavyLightDecomposition.hpp\"\
    \n#include \"../../other/template.hpp\"\nint n, q, a[500010];\nint main() {\n\t\
    scanf(\"%d%d\", &n, &q);\n\trep(i, n) scanf(\"%d\", a + i);\n\tHeavyLightDecomposition\
    \ hld(n);\n\tBIT<lint> bit(n);\n\trep(i, n - 1) {\n\t\tint u, v;\n\t\tscanf(\"\
    %d%d\", &u, &v);\n\t\thld.add_edge(u, v);\n\t}\n\thld.build(0);\n\trep(i, n) bit.add(hld.label[i],\
    \ a[i]);\n\trep(i, q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\
    \t\t\tint p, x;\n\t\t\tscanf(\"%d%d\", &p, &x);\n\t\t\tbit.add(hld.label[p], x);\n\
    \t\t} else {\n\t\t\tint u, v;\n\t\t\tscanf(\"%d%d\", &u, &v);\n\t\t\tlint ans\
    \ = 0;\n\t\t\thld.each_vertex(u, v,\n\t\t\t\t\t\t\t[&](int l, int r) { ans +=\
    \ bit.query(l, r + 1); });\n\t\t\tprintf(\"%lld\\n\", ans);\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_path_sum.test.cpp
- /verify/test/yosupo/vertex_add_path_sum.test.cpp.html
title: test/yosupo/vertex_add_path_sum.test.cpp
---
