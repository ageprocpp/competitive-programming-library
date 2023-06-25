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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"../../math/StaticModInt.hpp\"\n#include \"../../data-structure/SegTree.hpp\"\
    \n#include \"../../other/template.hpp\"\nusing ModInt = StaticModInt<998244353>;\n\
    using MP = std::pair<ModInt, ModInt>;\nMP nodef(const MP& lhs, const MP& rhs)\
    \ {\n\treturn {lhs.first * rhs.first, lhs.second * rhs.first + rhs.second};\n\
    }\nclass MySeg : public SegTree<MP, nodef> {\n\tusing Base = SegTree<MP, nodef>;\n\
    \n  public:\n\tMySeg(int n) : Base(n, MP{0, 0}, MP{1, 0}) {}\n};\nint n, q;\n\
    int main() {\n\tscanf(\"%d%d\", &n, &q);\n\tMySeg st(n);\n\trep(i, n) {\n\t\t\
    int a, b;\n\t\tscanf(\"%d%d\", &a, &b);\n\t\tst.update(i, {a, b});\n\t}\n\trep(i,\
    \ q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tint p, c,\
    \ d;\n\t\t\tscanf(\"%d%d%d\", &p, &c, &d);\n\t\t\tst.update(p, {c, d});\n\t\t\
    } else {\n\t\t\tint l, r, x;\n\t\t\tscanf(\"%d%d%d\", &l, &r, &x);\n\t\t\tauto\
    \ p = st.query(l, r);\n\t\t\tprintf(\"%d\\n\", p.first * x + p.second);\n\t\t\
    }\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
