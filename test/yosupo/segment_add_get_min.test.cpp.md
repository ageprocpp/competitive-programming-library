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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"../../data-structure/LiChaoTree.hpp\"\n#include \"../../other/template.hpp\"\
    \nint n, q, l[200010], r[200010], a[200010];\nlint b[200010];\nstd::vector<std::pair<IP,\
    \ std::pair<int, lint>>> vec;\nstd::vector<lint> cord;\nint main() {\n\tscanf(\"\
    %d%d\", &n, &q);\n\trep(i, n) {\n\t\tscanf(\"%d%d%d%lld\", l + i, r + i, a + i,\
    \ b + i);\n\t\tcord.emplace_back(l[i]);\n\t\tcord.emplace_back(r[i]);\n\t}\n\t\
    rep(i, q) {\n\t\tint type;\n\t\tscanf(\"%d\", &type);\n\t\tif (type == 0) {\n\t\
    \t\tint l, r, a;\n\t\t\tlint b;\n\t\t\tscanf(\"%d%d%d%lld\", &l, &r, &a, &b);\n\
    \t\t\tvec.push_back({{l, r}, {a, b}});\n\t\t\tcord.emplace_back(l);\n\t\t\tcord.emplace_back(r);\n\
    \t\t} else {\n\t\t\tint p;\n\t\t\tscanf(\"%d\", &p);\n\t\t\tvec.push_back({{p,\
    \ INF}, {0, 0}});\n\t\t\tcord.emplace_back(p);\n\t\t}\n\t}\n\tstd::sort(all(cord));\n\
    \tcord.erase(std::unique(all(cord)), cord.end());\n\trep(i, n) {\n\t\tl[i] = std::lower_bound(all(cord),\
    \ l[i]) - cord.begin();\n\t\tr[i] = std::lower_bound(all(cord), r[i]) - cord.begin();\n\
    \t}\n\tfor (auto& i : vec) {\n\t\ti.first.first =\n\t\t\tstd::lower_bound(all(cord),\
    \ i.first.first) - cord.begin();\n\t\tif (i.first.second != INF)\n\t\t\ti.first.second\
    \ =\n\t\t\t\tstd::lower_bound(all(cord), i.first.second) - cord.begin();\n\t}\n\
    \tLiChaoTree<true> lct(cord);\n\trep(i, n) lct.addSegment(l[i], r[i], a[i], b[i]);\n\
    \tfor (auto i : vec) {\n\t\tif (i.first.second == INF) {\n\t\t\tlint ans = lct.query(i.first.first).first;\n\
    \t\t\tif (ans == LINF)\n\t\t\t\tputs(\"INFINITY\");\n\t\t\telse\n\t\t\t\tprintf(\"\
    %lld\\n\", ans);\n\t\t} else\n\t\t\tlct.addSegment(i.first.first, i.first.second,\
    \ i.second.first,\n\t\t\t\t\t\t   i.second.second);\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/segment_add_get_min.test.cpp
- /verify/test/yosupo/segment_add_get_min.test.cpp.html
title: test/yosupo/segment_add_get_min.test.cpp
---
