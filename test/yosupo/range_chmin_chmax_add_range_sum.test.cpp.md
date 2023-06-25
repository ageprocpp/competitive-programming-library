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
  code: "#define PROBLEM \\\n\t\"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n#include \"../../data-structure/SegTreeBeats.hpp\"\n#include \"../../other/template.hpp\"\
    \nint n, q;\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\tstd::vector<lint> vec(n);\n\
    \trep(i, n) scanf(\"%lld\", vec.data() + i);\n\tSegTreeBeats beats(vec);\n\trep(i,\
    \ q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tlint l, r,\
    \ b;\n\t\t\tscanf(\"%lld%lld%lld\", &l, &r, &b);\n\t\t\tbeats.update_chmin(l,\
    \ r, b);\n\t\t} else if (t == 1) {\n\t\t\tlint l, r, b;\n\t\t\tscanf(\"%lld%lld%lld\"\
    , &l, &r, &b);\n\t\t\tbeats.update_chmax(l, r, b);\n\t\t} else if (t == 2) {\n\
    \t\t\tlint l, r, b;\n\t\t\tscanf(\"%lld%lld%lld\", &l, &r, &b);\n\t\t\tbeats.update_add(l,\
    \ r, b);\n\t\t} else {\n\t\t\tlint l, r;\n\t\t\tscanf(\"%lld%lld\", &l, &r);\n\
    \t\t\tprintf(\"%lld\\n\", beats.query_sum(l, r));\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
---
