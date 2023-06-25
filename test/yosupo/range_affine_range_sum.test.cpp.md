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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../../math/StaticModInt.hpp\"\n#include \"../../data-structure/IntervalSegTree.hpp\"\
    \n#include \"../../other/template.hpp\"\nusing ModInt = StaticModInt<998244353>;\n\
    using MP = std::pair<ModInt, ModInt>;\nModInt nodef(const ModInt& a, const ModInt&\
    \ b) { return a + b; }\nvoid lazyf(MP& a, const MP& b) {\n\ta = {a.first * b.first,\
    \ a.second * b.first + b.second};\n}\nvoid updf(ModInt& a, const MP& b, const\
    \ unsigned int& width) {\n\ta = b.first * a + b.second * width;\n}\nclass MySeg\
    \ : public IntervalSegTree<ModInt, MP, nodef, lazyf, updf> {\n\tusing Base = IntervalSegTree<ModInt,\
    \ MP, nodef, lazyf, updf>;\n\n  public:\n\tMySeg(const std::vector<ModInt>& initvec)\
    \ : Base(initvec, 0) {}\n};\nint n, q;\nstd::vector<ModInt> vec;\nint main() {\n\
    \tscanf(\"%d%d\", &n, &q);\n\tvec.resize(n);\n\trep(i, n) {\n\t\tint tmp;\n\t\t\
    scanf(\"%d\", &tmp);\n\t\tvec[i] = tmp;\n\t}\n\tMySeg st(vec);\n\trep(i, q) {\n\
    \t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tint l, r, b, c;\n\
    \t\t\tscanf(\"%d%d%d%d\", &l, &r, &b, &c);\n\t\t\tst.update(l, r, {b, c});\n\t\
    \t} else {\n\t\t\tint l, r;\n\t\t\tscanf(\"%d%d\", &l, &r);\n\t\t\tprintf(\"%d\\\
    n\", st.query(l, r));\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
