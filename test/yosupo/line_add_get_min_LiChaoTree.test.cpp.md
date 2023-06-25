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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"../../data-structure/LiChaoTree.hpp\"\n#include \"../../other/template.hpp\"\
    \nint n, q;\nlint a[200010], b[200010];\nstd::vector<std::pair<int, lint>> vec;\n\
    std::vector<lint> cord;\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\trep(i, n)\
    \ scanf(\"%lld%lld\", a + i, b + i);\n\trep(i, q) {\n\t\tint t;\n\t\tscanf(\"\
    %d\", &t);\n\t\tif (t == 0) {\n\t\t\tint a;\n\t\t\tlint b;\n\t\t\tscanf(\"%d%lld\"\
    , &a, &b);\n\t\t\tvec.emplace_back(a, b);\n\t\t} else {\n\t\t\tint p;\n\t\t\t\
    scanf(\"%d\", &p);\n\t\t\tvec.emplace_back(p, LINF);\n\t\t\tcord.emplace_back(p);\n\
    \t\t}\n\t}\n\tstd::sort(all(cord));\n\tcord.erase(std::unique(all(cord)), cord.end());\n\
    \tLiChaoTree<true> lct(cord);\n\trep(i, n) lct.addLine(a[i], b[i]);\n\tfor (auto\
    \ i : vec) {\n\t\tif (i.second == LINF)\n\t\t\tprintf(\"%lld\\n\", lct.query(std::lower_bound(all(cord),\
    \ i.first) -\n\t\t\t\t\t\t\t\t\t   cord.begin())\n\t\t\t\t\t\t\t\t .first);\n\t\
    \telse\n\t\t\tlct.addLine(i.first, i.second);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/line_add_get_min_LiChaoTree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/line_add_get_min_LiChaoTree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/line_add_get_min_LiChaoTree.test.cpp
- /verify/test/yosupo/line_add_get_min_LiChaoTree.test.cpp.html
title: test/yosupo/line_add_get_min_LiChaoTree.test.cpp
---
