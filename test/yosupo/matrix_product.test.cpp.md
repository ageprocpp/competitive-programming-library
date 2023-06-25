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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../math/StaticModInt.hpp\"\n#include\
    \ \"../../math/Matrix.hpp\"\nusing ModInt = StaticModInt<998244353>;\nint N, M,\
    \ K;\nint main() {\n\tscanf(\"%d%d%d\", &N, &M, &K);\n\tMatrix<ModInt> mat1(N,\
    \ M), mat2(M, K);\n\trep(i, N) rep(j, M) std::cin >> mat1[i][j];\n\trep(i, M)\
    \ rep(j, K) std::cin >> mat2[i][j];\n\tauto res = mat1 * mat2;\n\trep(i, N) std::cout\
    \ << res[i] << std::endl;\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/matrix_product.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_product.test.cpp
- /verify/test/yosupo/matrix_product.test.cpp.html
title: test/yosupo/matrix_product.test.cpp
---
