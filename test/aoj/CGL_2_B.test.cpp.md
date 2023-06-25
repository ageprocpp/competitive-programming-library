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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_B\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../math/Geometry.hpp\"\nint main()\
    \ {\n\tint q;\n\tstd::cin >> q;\n\trep(i, q) {\n\t\tint x0, y0, x1, y1, x2, y2,\
    \ x3, y3;\n\t\tstd::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;\n\t\t\
    Segment2D s0(Point2D(x0, y0), Point2D(x1, y1)),\n\t\t\ts1(Point2D(x2, y2), Point2D(x3,\
    \ y3));\n\t\tstd::cout << is_intersect(s0, s1) << std::endl;\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL_2_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_2_B.test.cpp
- /verify/test/aoj/CGL_2_B.test.cpp.html
title: test/aoj/CGL_2_B.test.cpp
---
