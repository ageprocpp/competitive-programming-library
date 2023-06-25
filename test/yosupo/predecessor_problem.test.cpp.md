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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include \"../../other/template.hpp\"\n#include \"../../other/FastIO.hpp\"\n#include\
    \ \"../../data-structure/vanEmdeBoasTree.hpp\"\nFastIO::Scanner cin;\nFastIO::Printer\
    \ cout;\nint N, Q;\nstd::string T;\nvanEmdeBoasTree<24> ebt;\nint main() {\n\t\
    cin >> N >> Q >> T;\n\trep(i, N) if (T[i] == '1') ebt.insert(i + 1);\n\trep(i,\
    \ Q) {\n\t\tint c, k;\n\t\tcin >> c >> k;\n\t\tk++;\n\t\tif (c == 0) {\n\t\t\t\
    ebt.insert(k);\n\t\t} else if (c == 1) {\n\t\t\tebt.erase(k);\n\t\t} else if (c\
    \ == 2)\n\t\t\tcout << ebt.contains(k) << '\\n';\n\t\telse if (c == 3) {\n\t\t\
    \tint ans = ebt.successor(k - 1);\n\t\t\tcout << (ans == -1 ? -1 : ans - 1) <<\
    \ '\\n';\n\t\t} else {\n\t\t\tint ans = ebt.predecessor(k + 1);\n\t\t\tcout <<\
    \ (ans == -1 ? -1 : ans - 1) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/predecessor_problem.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/predecessor_problem.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/predecessor_problem.test.cpp
- /verify/test/yosupo/predecessor_problem.test.cpp.html
title: test/yosupo/predecessor_problem.test.cpp
---
