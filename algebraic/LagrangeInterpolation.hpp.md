---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
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
    \nDynamicModInt arithmetic_lagrange_interpolation(\n\tconst DynamicModInt& a,\
    \ const DynamicModInt& d,\n\tconst std::vector<DynamicModInt>& y, const DynamicModInt&\
    \ t) {\n\tconst int n = y.size() - 1;\n\tDynamicModInt res = 0, ft = 1;\n\trep(i,\
    \ n + 1) ft *= t - (a + d * i);\n\tDynamicModInt f = 1;\n\tREP(i, n) f *= -d *\
    \ i;\n\tres += y[0] / f * ft / (t - a);\n\trep(i, n) {\n\t\tf *= i + 1;\n\t\t\
    f /= i - n;\n\t\tres += y[i + 1] / f * ft / (t - (a + d * (i + 1)));\n\t}\n\t\
    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: algebraic/LagrangeInterpolation.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebraic/LagrangeInterpolation.hpp
layout: document
redirect_from:
- /library/algebraic/LagrangeInterpolation.hpp
- /library/algebraic/LagrangeInterpolation.hpp.html
title: algebraic/LagrangeInterpolation.hpp
---
