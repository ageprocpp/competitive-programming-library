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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"../../math/StaticModInt.hpp\"\n#include \"../../data-structure/SegTree.hpp\"\
    \n#include \"../../graph/HeavyLightDecomposition.hpp\"\n#include \"../../other/template.hpp\"\
    \nusing ModInt = StaticModInt<998244353>;\nusing MP = std::pair<ModInt, ModInt>;\n\
    MP nodef(const MP& lhs, const MP& rhs) {\n\treturn {lhs.first * rhs.first, lhs.second\
    \ * rhs.first + rhs.second};\n}\nclass MySeg : public SegTree<MP, nodef> {\n\t\
    using Base = SegTree<MP, nodef>;\n\n  public:\n\tMySeg(int n) : Base(n, MP{1,\
    \ 0}, MP{1, 0}) {}\n};\nint n, q;\nIP a[200010];\nint main() {\n\tscanf(\"%d%d\"\
    , &n, &q);\n\trep(i, n) scanf(\"%d%d\", &a[i].first, &a[i].second);\n\tHeavyLightDecomposition\
    \ hld(n);\n\tMySeg st1(n), st2(n);\n\trep(i, n - 1) {\n\t\tint u, v;\n\t\tscanf(\"\
    %d%d\", &u, &v);\n\t\thld.add_edge(u, v);\n\t}\n\thld.build(0);\n\trep(i, n) {\n\
    \t\tst1.update(hld.label[i], a[i]);\n\t\tst2.update(n - 1 - hld.label[i], a[i]);\n\
    \t}\n\trep(i, q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\
    \tint p, c, d;\n\t\t\tscanf(\"%d%d%d\", &p, &c, &d);\n\t\t\ta[p] = {c, d};\n\t\
    \t\tst1.update(hld.label[p], {c, d});\n\t\t\tst2.update(n - 1 - hld.label[p],\
    \ {c, d});\n\t\t} else {\n\t\t\tint u, v, x;\n\t\t\tscanf(\"%d%d%d\", &u, &v,\
    \ &x);\n\t\t\tint t = hld.lca(u, v);\n\t\t\tstd::pair<ModInt, ModInt> f1(1, 0),\
    \ f2(1, 0);\n\t\t\thld.each_vertex(u, t, [&](int l, int r) {\n\t\t\t\tauto p =\
    \ st2.query(n - 1 - r, n - 1 - l + 1);\n\t\t\t\tf1 = {f1.first * p.first, f1.second\
    \ * p.first + p.second};\n\t\t\t});\n\t\t\tf1 = {f1.first / a[t].first,\n\t\t\t\
    \t  (f1.second - a[t].second) / a[t].first};\n\t\t\thld.each_vertex(t, v, [&](int\
    \ l, int r) {\n\t\t\t\tauto p = st1.query(l, r + 1);\n\t\t\t\tf2 = {p.first *\
    \ f2.first, p.second * f2.first + f2.second};\n\t\t\t});\n\t\t\tf1 = {f1.first\
    \ * f2.first, f1.second * f2.first + f2.second};\n\t\t\tprintf(\"%d\\n\", ModInt(x)\
    \ * f1.first + f1.second);\n\t\t}\n\t}\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_set_path_composite.test.cpp
- /verify/test/yosupo/vertex_set_path_composite.test.cpp.html
title: test/yosupo/vertex_set_path_composite.test.cpp
---
