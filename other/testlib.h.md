---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/MikeMirzayanov/testlib/
  bundledCode: "#line 1 \"other/testlib.h\"\n/* \n * It is strictly recommended to\
    \ include \"testlib.h\" before any other include \n * in your code. In this case\
    \ testlib overrides compiler specific \"random()\".\n *\n * If you can't compile\
    \ your code and compiler outputs something about \n * ambiguous call of \"random_shuffle\"\
    , \"rand\" or \"srand\" it means that \n * you shouldn't use them. Use \"shuffle\"\
    , and \"rnd.next()\" instead of them\n * because these calls produce stable result\
    \ for any C++ compiler. Read \n * sample generator sources for clarification.\n\
    \ *\n * Please read the documentation for class \"random_t\" and use \"rnd\" instance\
    \ in\n * generators. Probably, these sample calls will be usefull for you:\n *\
    \              rnd.next(); rnd.next(100); rnd.next(1, 2); \n *              rnd.next(3.14);\
    \ rnd.next(\"[a-z]{1,100}\").\n *\n * Also read about wnext() to generate off-center\
    \ random distribution.\n *\n * See https://github.com/MikeMirzayanov/testlib/\
    \ to get latest version or bug tracker.\n */\n\n#ifndef _TESTLIB_H_\n#define _TESTLIB_H_\n\
    \n/*\n * Copyright (c) 2005-2020\n */\n\n#define VERSION \"0.9.34-SNAPSHOT\"\n\
    \n/* \n * Mike Mirzayanov\n *\n * This material is provided \"as is\", with absolutely\
    \ no warranty expressed\n * or implied. Any use is at your own risk.\n *\n * Permission\
    \ to use or copy this software for any purpose is hereby granted \n * without\
    \ fee, provided the above notices are retained on all copies.\n * Permission to\
    \ modify the code and to distribute modified code is granted,\n * provided the\
    \ above notices are retained, and a notice that the code was\n * modified is included\
    \ with the above copyright notice.\n *\n */\n\n/* NOTE: This file contains testlib\
    \ library for C++.\n *\n *   Check, using testlib running format:\n *     check.exe\
    \ <Input_File> <Output_File> <Answer_File> [<Result_File> [-appes]],\n *   If\
    \ result file is specified it will contain results.\n *\n *   Validator, using\
    \ testlib running format:                                          \n *     validator.exe\
    \ < input.txt,\n *   It will return non-zero exit code and writes message to standard\
    \ output.\n *\n *   Generator, using testlib running format:                 \
    \                         \n *     gen.exe [parameter-1] [parameter-2] [... paramerter-n]\n\
    \ *   You can write generated test(s) into standard output or into the file(s).\n\
    \ *\n *   Interactor, using testlib running format:                          \
    \                \n *     interactor.exe <Input_File> <Output_File> [<Answer_File>\
    \ [<Result_File> [-appes]]],\n *   Reads test from inf (mapped to args[1]), writes\
    \ result to tout (mapped to argv[2],\n *   can be judged by checker later), reads\
    \ program output from ouf (mapped to stdin),\n *   writes output to program via\
    \ stdout (use cout, printf, etc).\n */\n\nconst char *latestFeatures[] = {\n \
    \       \"Fixed hypothetical UB in stringToDouble and stringToStrictDouble\",\n\
    \        \"rnd.partition(size, sum[, min_part=0]) returns random (unsorted) partition\
    \ which is a representation of the given `sum` as a sum of `size` positive integers\
    \ (or >=min_part if specified)\",\n        \"rnd.distinct(size, n) and rnd.distinct(size,\
    \ from, to)\",\n        \"opt<bool>(\\\"some_missing_key\\\") returns false now\"\
    ,\n        \"has_opt(key)\",\n        \"Abort validator on validator.testset()/validator.group()\
    \ if registered without using command line\",\n        \"Print integer range violations\
    \ in a human readable way like `violates the range [1, 10^9]`\",\n        \"Opts\
    \ supported: use them like n = opt<int>(\\\"n\\\"), in a command line you can\
    \ use an exponential notation\",\n        \"Reformatted\",\n        \"Use setTestCase(i)\
    \ or unsetTestCase() to support test cases (you can use it in any type of program:\
    \ generator, interactor, validator or checker)\",\n        \"Fixed issue #87:\
    \ readStrictDouble accepts \\\"-0.00\\\"\",\n        \"Fixed issue #83: added\
    \ InStream::quitif(condition, ...)\",\n        \"Fixed issue #79: fixed missed\
    \ guard against repeated header include\",\n        \"Fixed issue #80: fixed UB\
    \ in case of huge quitf message\",\n        \"Fixed issue #84: added readXs(size,\
    \ indexBase = 1)\",\n        \"Fixed stringstream repeated usage issue\",\n  \
    \      \"Fixed compilation in g++ (for std=c++03)\",\n        \"Batch of println\
    \ functions (support collections, iterator ranges)\",\n        \"Introduced rnd.perm(size,\
    \ first = 0) to generate a `first`-indexed permutation\",\n        \"Allow any\
    \ whitespace in readInts-like functions for non-validators\",\n        \"Ignore\
    \ 4+ command line arguments ifdef EJUDGE\",\n        \"Speed up of vtos\",\n \
    \       \"Show line number in validators in case of incorrect format\",\n    \
    \    \"Truncate huge checker/validator/interactor message\",\n        \"Fixed\
    \ issue with readTokenTo of very long tokens, now aborts with _pe/_fail depending\
    \ of a stream type\",\n        \"Introduced InStream::ensure/ensuref checking\
    \ a condition, returns wa/fail depending of a stream type\",\n        \"Fixed\
    \ compilation in VS 2015+\",\n        \"Introduced space-separated read functions:\
    \ readWords/readTokens, multilines read functions: readStrings/readLines\",\n\
    \        \"Introduced space-separated read functions: readInts/readIntegers/readLongs/readUnsignedLongs/readDoubles/readReals/readStrictDoubles/readStrictReals\"\
    ,\n        \"Introduced split/tokenize functions to separate string by given char\"\
    ,\n        \"Introduced InStream::readUnsignedLong and InStream::readLong with\
    \ unsigned long long paramerters\",\n        \"Supported --testOverviewLogFileName\
    \ for validator: bounds hits + features\",\n        \"Fixed UB (sequence points)\
    \ in random_t\",\n        \"POINTS_EXIT_CODE returned back to 7 (instead of 0)\"\
    ,\n        \"Removed disable buffers for interactive problems, because it works\
    \ unexpectedly in wine\",\n        \"InStream over string: constructor of InStream\
    \ from base InStream to inherit policies and std::string\",\n        \"Added expectedButFound\
    \ quit function, examples: expectedButFound(_wa, 10, 20), expectedButFound(_fail,\
    \ ja, pa, \\\"[n=%d,m=%d]\\\", n, m)\",\n        \"Fixed incorrect interval parsing\
    \ in patterns\",\n        \"Use registerGen(argc, argv, 1) to develop new generator,\
    \ use registerGen(argc, argv, 0) to compile old generators (originally created\
    \ for testlib under 0.8.7)\",\n        \"Introduced disableFinalizeGuard() to\
    \ switch off finalization checkings\",\n        \"Use join() functions to format\
    \ a range of items as a single string (separated by spaces or other separators)\"\
    ,\n        \"Use -DENABLE_UNEXPECTED_EOF to enable special exit code (by default,\
    \ 8) in case of unexpected eof. It is good idea to use it in interactors\",\n\
    \        \"Use -DUSE_RND_AS_BEFORE_087 to compile in compatibility mode with random\
    \ behavior of versions before 0.8.7\",\n        \"Fixed bug with nan in stringToDouble\"\
    ,\n        \"Fixed issue around overloads for size_t on x64\",\n        \"Added\
    \ attribute 'points' to the XML output in case of result=_points\",\n        \"\
    Exit codes can be customized via macros, e.g. -DPE_EXIT_CODE=14\",\n        \"\
    Introduced InStream function readWordTo/readTokenTo/readStringTo/readLineTo for\
    \ faster reading\",\n        \"Introduced global functions: format(), englishEnding(),\
    \ upperCase(), lowerCase(), compress()\",\n        \"Manual buffer in InStreams,\
    \ some IO speed improvements\",\n        \"Introduced quitif(bool, const char*\
    \ pattern, ...) which delegates to quitf() in case of first argument is true\"\
    ,\n        \"Introduced guard against missed quitf() in checker or readEof() in\
    \ validators\",\n        \"Supported readStrictReal/readStrictDouble - to use\
    \ in validators to check strictly float numbers\",\n        \"Supported registerInteraction(argc,\
    \ argv)\",\n        \"Print checker message to the stderr instead of stdout\"\
    ,\n        \"Supported TResult _points to output calculated score, use quitp(...)\
    \ functions\",\n        \"Fixed to be compilable on Mac\",\n        \"PC_BASE_EXIT_CODE=50\
    \ in case of defined TESTSYS\",\n        \"Fixed issues 19-21, added __attribute__\
    \ format printf\",\n        \"Some bug fixes\",\n        \"ouf.readInt(1, 100)\
    \ and similar calls return WA\",\n        \"Modified random_t to avoid integer\
    \ overflow\",\n        \"Truncated checker output [patch by Stepan Gatilov]\"\
    ,\n        \"Renamed class random -> class random_t\",\n        \"Supported name\
    \ parameter for read-and-validation methods, like readInt(1, 2, \\\"n\\\")\",\n\
    \        \"Fixed bug in readDouble()\",\n        \"Improved ensuref(), fixed nextLine\
    \ to work in case of EOF, added startTest()\",\n        \"Supported \\\"partially\
    \ correct\\\", example: quitf(_pc(13), \\\"result=%d\\\", result)\",\n       \
    \ \"Added shuffle(begin, end), use it instead of random_shuffle(begin, end)\"\
    ,\n        \"Added readLine(const string& ptrn), fixed the logic of readLine()\
    \ in the validation mode\",\n        \"Package extended with samples of generators\
    \ and validators\",\n        \"Written the documentation for classes and public\
    \ methods in testlib.h\",\n        \"Implemented random routine to support generators,\
    \ use registerGen() to switch it on\",\n        \"Implemented strict mode to validate\
    \ tests, use registerValidation() to switch it on\",\n        \"Now ncmp.cpp and\
    \ wcmp.cpp are return WA if answer is suffix or prefix of the output\",\n    \
    \    \"Added InStream::readLong() and removed InStream::readLongint()\",\n   \
    \     \"Now no footer added to each report by default (use directive FOOTER to\
    \ switch on)\",\n        \"Now every checker has a name, use setName(const char*\
    \ format, ...) to set it\",\n        \"Now it is compatible with TTS (by Kittens\
    \ Computing)\",\n        \"Added \\'ensure(condition, message = \\\"\\\")\\' feature,\
    \ it works like assert()\",\n        \"Fixed compatibility with MS C++ 7.1\",\n\
    \        \"Added footer with exit code information\",\n        \"Added compatibility\
    \ with EJUDGE (compile with EJUDGE directive)\",\n        \"Added compatibility\
    \ with Contester (compile with CONTESTER directive)\"\n};\n\n#ifdef _MSC_VER\n\
    #define _CRT_SECURE_NO_DEPRECATE\n#define _CRT_SECURE_NO_WARNINGS\n#define _CRT_NO_VA_START_VALIDATION\n\
    #endif\n\n/* Overrides random() for Borland C++. */\n#define random __random_deprecated\n\
    #include <stdlib.h>\n#include <cstdlib>\n#include <climits>\n#include <algorithm>\n\
    #undef random\n\n#include <cstdio>\n#include <cctype>\n#include <string>\n#include\
    \ <vector>\n#include <map>\n#include <set>\n#include <cmath>\n#include <iostream>\n\
    #include <sstream>\n#include <fstream>\n#include <cstring>\n#include <limits>\n\
    #include <stdarg.h>\n#include <fcntl.h>\n\n#if (_WIN32 || __WIN32__ || _WIN64\
    \ || __WIN64__ || __CYGWIN__)\n#   if !defined(_MSC_VER) || _MSC_VER > 1400\n\
    #       define NOMINMAX 1\n#       include <windows.h>\n#   else\n#       define\
    \ WORD unsigned short\n#       include <unistd.h>\n#   endif\n#   include <io.h>\n\
    #   define ON_WINDOWS\n#   if defined(_MSC_VER) && _MSC_VER > 1400\n#       pragma\
    \ warning( disable : 4127 )\n#       pragma warning( disable : 4146 )\n#     \
    \  pragma warning( disable : 4458 )\n#   endif\n#else\n#   define WORD unsigned\
    \ short\n#   include <unistd.h>\n#endif\n\n#if defined(FOR_WINDOWS) && defined(FOR_LINUX)\n\
    #error Only one target system is allowed\n#endif\n\n#ifndef LLONG_MIN\n#define\
    \ LLONG_MIN   (-9223372036854775807LL - 1)\n#endif\n\n#ifndef ULLONG_MAX\n#define\
    \ ULLONG_MAX   (18446744073709551615)\n#endif\n\n#define LF ((char)10)\n#define\
    \ CR ((char)13)\n#define TAB ((char)9)\n#define SPACE ((char)' ')\n#define EOFC\
    \ (255)\n\n#ifndef OK_EXIT_CODE\n#   ifdef CONTESTER\n#       define OK_EXIT_CODE\
    \ 0xAC\n#   else\n#       define OK_EXIT_CODE 0\n#   endif\n#endif\n\n#ifndef\
    \ WA_EXIT_CODE\n#   ifdef EJUDGE\n#       define WA_EXIT_CODE 5\n#   elif defined(CONTESTER)\n\
    #       define WA_EXIT_CODE 0xAB\n#   else\n#       define WA_EXIT_CODE 1\n# \
    \  endif\n#endif\n\n#ifndef PE_EXIT_CODE\n#   ifdef EJUDGE\n#       define PE_EXIT_CODE\
    \ 4\n#   elif defined(CONTESTER)\n#       define PE_EXIT_CODE 0xAA\n#   else\n\
    #       define PE_EXIT_CODE 2\n#   endif\n#endif\n\n#ifndef FAIL_EXIT_CODE\n#\
    \   ifdef EJUDGE\n#       define FAIL_EXIT_CODE 6\n#   elif defined(CONTESTER)\n\
    #       define FAIL_EXIT_CODE 0xA3\n#   else\n#       define FAIL_EXIT_CODE 3\n\
    #   endif\n#endif\n\n#ifndef DIRT_EXIT_CODE\n#   ifdef EJUDGE\n#       define\
    \ DIRT_EXIT_CODE 6\n#   else\n#       define DIRT_EXIT_CODE 4\n#   endif\n#endif\n\
    \n#ifndef POINTS_EXIT_CODE\n#   define POINTS_EXIT_CODE 7\n#endif\n\n#ifndef UNEXPECTED_EOF_EXIT_CODE\n\
    #   define UNEXPECTED_EOF_EXIT_CODE 8\n#endif\n\n#ifndef PC_BASE_EXIT_CODE\n#\
    \   ifdef TESTSYS\n#       define PC_BASE_EXIT_CODE 50\n#   else\n#       define\
    \ PC_BASE_EXIT_CODE 0\n#   endif\n#endif\n\n#ifdef __GNUC__\n#    define __TESTLIB_STATIC_ASSERT(condition)\
    \ typedef void* __testlib_static_assert_type[(condition) ? 1 : -1] __attribute__((unused))\n\
    #else\n#    define __TESTLIB_STATIC_ASSERT(condition) typedef void* __testlib_static_assert_type[(condition)\
    \ ? 1 : -1]\n#endif\n\n#ifdef ON_WINDOWS\n#define I64 \"%I64d\"\n#define U64 \"\
    %I64u\"\n#else\n#define I64 \"%lld\"\n#define U64 \"%llu\"\n#endif\n\n#ifdef _MSC_VER\n\
    #   define NORETURN __declspec(noreturn)\n#elif defined __GNUC__\n#   define NORETURN\
    \ __attribute__ ((noreturn))\n#else\n#   define NORETURN\n#endif\n\nstatic char\
    \ __testlib_format_buffer[16777216];\nstatic int __testlib_format_buffer_usage_count\
    \ = 0;\n\n#define FMT_TO_RESULT(fmt, cstr, result)  std::string result;      \
    \                        \\\n            if (__testlib_format_buffer_usage_count\
    \ != 0)                                  \\\n                __testlib_fail(\"\
    FMT_TO_RESULT::__testlib_format_buffer_usage_count != 0\"); \\\n            __testlib_format_buffer_usage_count++;\
    \                                         \\\n            va_list ap;        \
    \                                                            \\\n            va_start(ap,\
    \ fmt);                                                             \\\n     \
    \       vsnprintf(__testlib_format_buffer, sizeof(__testlib_format_buffer), cstr,\
    \ ap); \\\n            va_end(ap);                                           \
    \                         \\\n            __testlib_format_buffer[sizeof(__testlib_format_buffer)\
    \ - 1] = 0;              \\\n            result = std::string(__testlib_format_buffer);\
    \                                 \\\n            __testlib_format_buffer_usage_count--;\
    \                                         \\\n\nconst long long __TESTLIB_LONGLONG_MAX\
    \ = 9223372036854775807LL;\n\nbool __testlib_hasTestCase;\nint __testlib_testCase\
    \ = -1;\n\nvoid setTestCase(int testCase) {\n    __testlib_hasTestCase = true;\n\
    \    __testlib_testCase = testCase;\n}\n\nvoid unsetTestCase() {\n    __testlib_hasTestCase\
    \ = false;\n    __testlib_testCase = -1;\n}\n\nNORETURN static void __testlib_fail(const\
    \ std::string &message);\n\ntemplate<typename T>\nstatic inline T __testlib_abs(const\
    \ T &x) {\n    return x > 0 ? x : -x;\n}\n\ntemplate<typename T>\nstatic inline\
    \ T __testlib_min(const T &a, const T &b) {\n    return a < b ? a : b;\n}\n\n\
    template<typename T>\nstatic inline T __testlib_max(const T &a, const T &b) {\n\
    \    return a > b ? a : b;\n}\n\nstatic bool __testlib_prelimIsNaN(double r) {\n\
    \    volatile double ra = r;\n#ifndef __BORLANDC__\n    return ((ra != ra) ==\
    \ true) && ((ra == ra) == false) && ((1.0 > ra) == false) && ((1.0 < ra) == false);\n\
    #else\n    return std::_isnan(ra);\n#endif\n}\n\nstatic std::string removeDoubleTrailingZeroes(std::string\
    \ value) {\n    while (!value.empty() && value[value.length() - 1] == '0' && value.find('.')\
    \ != std::string::npos)\n        value = value.substr(0, value.length() - 1);\n\
    \    return value + '0';\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf,\
    \ 1, 2)))\n#endif\nstd::string format(const char *fmt, ...) {\n    FMT_TO_RESULT(fmt,\
    \ fmt, result);\n    return result;\n}\n\nstd::string format(const std::string\
    \ fmt, ...) {\n    FMT_TO_RESULT(fmt, fmt.c_str(), result);\n    return result;\n\
    }\n\nstatic std::string __testlib_part(const std::string &s);\n\nstatic bool __testlib_isNaN(double\
    \ r) {\n    __TESTLIB_STATIC_ASSERT(sizeof(double) == sizeof(long long));\n  \
    \  volatile double ra = r;\n    long long llr1, llr2;\n    std::memcpy((void *)\
    \ &llr1, (void *) &ra, sizeof(double));\n    ra = -ra;\n    std::memcpy((void\
    \ *) &llr2, (void *) &ra, sizeof(double));\n    long long llnan = 0xFFF8000000000000LL;\n\
    \    return __testlib_prelimIsNaN(r) || llnan == llr1 || llnan == llr2;\n}\n\n\
    static double __testlib_nan() {\n    __TESTLIB_STATIC_ASSERT(sizeof(double) ==\
    \ sizeof(long long));\n#ifndef NAN\n    long long llnan = 0xFFF8000000000000LL;\n\
    \    double nan;\n    std::memcpy(&nan, &llnan, sizeof(double));\n    return nan;\n\
    #else\n    return NAN;\n#endif\n}\n\nstatic bool __testlib_isInfinite(double r)\
    \ {\n    volatile double ra = r;\n    return (ra > 1E300 || ra < -1E300);\n}\n\
    \n#ifdef __GNUC__\n__attribute__((const))\n#endif\ninline bool doubleCompare(double\
    \ expected, double result, double MAX_DOUBLE_ERROR) {\n    if (__testlib_isNaN(expected))\
    \ {\n        return __testlib_isNaN(result);\n    } else if (__testlib_isInfinite(expected))\
    \ {\n        if (expected > 0) {\n            return result > 0 && __testlib_isInfinite(result);\n\
    \        } else {\n            return result < 0 && __testlib_isInfinite(result);\n\
    \        }\n    } else if (__testlib_isNaN(result) || __testlib_isInfinite(result))\
    \ {\n        return false;\n    } else if (__testlib_abs(result - expected) <=\
    \ MAX_DOUBLE_ERROR + 1E-15) {\n        return true;\n    } else {\n        double\
    \ minv = __testlib_min(expected * (1.0 - MAX_DOUBLE_ERROR),\n                \
    \                    expected * (1.0 + MAX_DOUBLE_ERROR));\n        double maxv\
    \ = __testlib_max(expected * (1.0 - MAX_DOUBLE_ERROR),\n                     \
    \               expected * (1.0 + MAX_DOUBLE_ERROR));\n        return result +\
    \ 1E-15 >= minv && result <= maxv + 1E-15;\n    }\n}\n\n#ifdef __GNUC__\n__attribute__((const))\n\
    #endif\ninline double doubleDelta(double expected, double result) {\n    double\
    \ absolute = __testlib_abs(result - expected);\n\n    if (__testlib_abs(expected)\
    \ > 1E-9) {\n        double relative = __testlib_abs(absolute / expected);\n \
    \       return __testlib_min(absolute, relative);\n    } else\n        return\
    \ absolute;\n}\n\n#if !defined(_MSC_VER) || _MSC_VER < 1900\n#ifndef _fileno\n\
    #define _fileno(_stream)  ((_stream)->_file)\n#endif\n#endif\n\n#ifndef O_BINARY\n\
    static void __testlib_set_binary(\n#ifdef __GNUC__\n    __attribute__((unused))\
    \ \n#endif\n    std::FILE* file\n)\n#else\nstatic void __testlib_set_binary(std::FILE\
    \ *file)\n#endif\n{\n#ifdef O_BINARY\n    if (NULL != file) {\n#ifndef __BORLANDC__\n\
    \        _setmode(_fileno(file), O_BINARY);\n#else\n        setmode(fileno(file),\
    \ O_BINARY);\n#endif\n    }\n#endif\n}\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\n\
    /* opts */\nvoid prepareOpts(int argc, char* argv[]);\n#endif\n\n/*\n * Very simple\
    \ regex-like pattern.\n * It used for two purposes: validation and generation.\n\
    \ * \n * For example, pattern(\"[a-z]{1,5}\").next(rnd) will return\n * random\
    \ string from lowercase latin letters with length \n * from 1 to 5. It is easier\
    \ to call rnd.next(\"[a-z]{1,5}\") \n * for the same effect. \n * \n * Another\
    \ samples:\n * \"mike|john\" will generate (match) \"mike\" or \"john\";\n * \"\
    -?[1-9][0-9]{0,3}\" will generate (match) non-zero integers from -9999 to 9999;\n\
    \ * \"id-([ac]|b{2})\" will generate (match) \"id-a\", \"id-bb\", \"id-c\";\n\
    \ * \"[^0-9]*\" will match sequences (empty or non-empty) without digits, you\
    \ can't \n * use it for generations.\n *\n * You can't use pattern for generation\
    \ if it contains meta-symbol '*'. Also it\n * is not recommended to use it for\
    \ char-sets with meta-symbol '^' like [^a-z].\n *\n * For matching very simple\
    \ greedy algorithm is used. For example, pattern\n * \"[0-9]?1\" will not match\
    \ \"1\", because of greedy nature of matching.\n * Alternations (meta-symbols\
    \ \"|\") are processed with brute-force algorithm, so \n * do not use many alternations\
    \ in one expression.\n *\n * If you want to use one expression many times it is\
    \ better to compile it into\n * a single pattern like \"pattern p(\"[a-z]+\")\"\
    . Later you can use \n * \"p.matches(std::string s)\" or \"p.next(random_t& rd)\"\
    \ to check matching or generate\n * new string by pattern.\n * \n * Simpler way\
    \ to read token and check it for pattern matching is \"inf.readToken(\"[a-z]+\"\
    )\".\n */\nclass random_t;\n\nclass pattern {\npublic:\n    /* Create pattern\
    \ instance by string. */\n    pattern(std::string s);\n\n    /* Generate new string\
    \ by pattern and given random_t. */\n    std::string next(random_t &rnd) const;\n\
    \n    /* Checks if given string match the pattern. */\n    bool matches(const\
    \ std::string &s) const;\n\n    /* Returns source string of the pattern. */\n\
    \    std::string src() const;\n\nprivate:\n    bool matches(const std::string\
    \ &s, size_t pos) const;\n\n    std::string s;\n    std::vector<pattern> children;\n\
    \    std::vector<char> chars;\n    int from;\n    int to;\n};\n\n/* \n * Use random_t\
    \ instances to generate random values. It is preffered\n * way to use randoms\
    \ instead of rand() function or self-written \n * randoms.\n *\n * Testlib defines\
    \ global variable \"rnd\" of random_t class.\n * Use registerGen(argc, argv, 1)\
    \ to setup random_t seed be command\n * line (to use latest random generator version).\n\
    \ *\n * Random generates uniformly distributed values if another strategy is\n\
    \ * not specified explicitly.\n */\nclass random_t {\nprivate:\n    unsigned long\
    \ long seed;\n    static const unsigned long long multiplier;\n    static const\
    \ unsigned long long addend;\n    static const unsigned long long mask;\n    static\
    \ const int lim;\n\n    long long nextBits(int bits) {\n        if (bits <= 48)\
    \ {\n            seed = (seed * multiplier + addend) & mask;\n            return\
    \ (long long) (seed >> (48 - bits));\n        } else {\n            if (bits >\
    \ 63)\n                __testlib_fail(\"random_t::nextBits(int bits): n must be\
    \ less than 64\");\n\n            int lowerBitCount = (random_t::version == 0\
    \ ? 31 : 32);\n\n            long long left = (nextBits(31) << 32);\n        \
    \    long long right = nextBits(lowerBitCount);\n\n            return left ^ right;\n\
    \        }\n    }\n\npublic:\n    static int version;\n\n    /* New random_t with\
    \ fixed seed. */\n    random_t()\n            : seed(3905348978240129619LL) {\n\
    \    }\n\n    /* Sets seed by command line. */\n    void setSeed(int argc, char\
    \ *argv[]) {\n        random_t p;\n\n        seed = 3905348978240129619LL;\n \
    \       for (int i = 1; i < argc; i++) {\n            std::size_t le = std::strlen(argv[i]);\n\
    \            for (std::size_t j = 0; j < le; j++)\n                seed = seed\
    \ * multiplier + (unsigned int) (argv[i][j]) + addend;\n            seed += multiplier\
    \ / addend;\n        }\n\n        seed = seed & mask;\n    }\n\n    /* Sets seed\
    \ by given value. */\n    void setSeed(long long _seed) {\n        _seed = (_seed\
    \ ^ multiplier) & mask;\n        seed = _seed;\n    }\n\n#ifndef __BORLANDC__\n\
    \n    /* Random string value by given pattern (see pattern documentation). */\n\
    \    std::string next(const std::string &ptrn) {\n        pattern p(ptrn);\n \
    \       return p.next(*this);\n    }\n\n#else\n    /* Random string value by given\
    \ pattern (see pattern documentation). */\n    std::string next(std::string ptrn)\n\
    \    {\n        pattern p(ptrn);\n        return p.next(*this);\n    }\n#endif\n\
    \n    /* Random value in range [0, n-1]. */\n    int next(int n) {\n        if\
    \ (n <= 0)\n            __testlib_fail(\"random_t::next(int n): n must be positive\"\
    );\n\n        if ((n & -n) == n)  // n is a power of 2\n            return (int)\
    \ ((n * (long long) nextBits(31)) >> 31);\n\n        const long long limit = INT_MAX\
    \ / n * n;\n\n        long long bits;\n        do {\n            bits = nextBits(31);\n\
    \        } while (bits >= limit);\n\n        return int(bits % n);\n    }\n\n\
    \    /* Random value in range [0, n-1]. */\n    unsigned int next(unsigned int\
    \ n) {\n        if (n >= INT_MAX)\n            __testlib_fail(\"random_t::next(unsigned\
    \ int n): n must be less INT_MAX\");\n        return (unsigned int) next(int(n));\n\
    \    }\n\n    /* Random value in range [0, n-1]. */\n    long long next(long long\
    \ n) {\n        if (n <= 0)\n            __testlib_fail(\"random_t::next(long\
    \ long n): n must be positive\");\n\n        const long long limit = __TESTLIB_LONGLONG_MAX\
    \ / n * n;\n\n        long long bits;\n        do {\n            bits = nextBits(63);\n\
    \        } while (bits >= limit);\n\n        return bits % n;\n    }\n\n    /*\
    \ Random value in range [0, n-1]. */\n    unsigned long long next(unsigned long\
    \ long n) {\n        if (n >= (unsigned long long) (__TESTLIB_LONGLONG_MAX))\n\
    \            __testlib_fail(\"random_t::next(unsigned long long n): n must be\
    \ less LONGLONG_MAX\");\n        return (unsigned long long) next((long long)\
    \ (n));\n    }\n\n    /* Random value in range [0, n-1]. */\n    long next(long\
    \ n) {\n        return (long) next((long long) (n));\n    }\n\n    /* Random value\
    \ in range [0, n-1]. */\n    unsigned long next(unsigned long n) {\n        if\
    \ (n >= (unsigned long) (LONG_MAX))\n            __testlib_fail(\"random_t::next(unsigned\
    \ long n): n must be less LONG_MAX\");\n        return (unsigned long) next((unsigned\
    \ long long) (n));\n    }\n\n    /* Returns random value in range [from,to]. */\n\
    \    int next(int from, int to) {\n        return int(next((long long) to - from\
    \ + 1) + from);\n    }\n\n    /* Returns random value in range [from,to]. */\n\
    \    unsigned int next(unsigned int from, unsigned int to) {\n        return (unsigned\
    \ int) (next((long long) to - from + 1) + from);\n    }\n\n    /* Returns random\
    \ value in range [from,to]. */\n    long long next(long long from, long long to)\
    \ {\n        return next(to - from + 1) + from;\n    }\n\n    /* Returns random\
    \ value in range [from,to]. */\n    unsigned long long next(unsigned long long\
    \ from, unsigned long long to) {\n        if (from > to)\n            __testlib_fail(\"\
    random_t::next(unsigned long long from, unsigned long long to): from can't not\
    \ exceed to\");\n        return next(to - from + 1) + from;\n    }\n\n    /* Returns\
    \ random value in range [from,to]. */\n    long next(long from, long to) {\n \
    \       return next(to - from + 1) + from;\n    }\n\n    /* Returns random value\
    \ in range [from,to]. */\n    unsigned long next(unsigned long from, unsigned\
    \ long to) {\n        if (from > to)\n            __testlib_fail(\"random_t::next(unsigned\
    \ long from, unsigned long to): from can't not exceed to\");\n        return next(to\
    \ - from + 1) + from;\n    }\n\n    /* Random double value in range [0, 1). */\n\
    \    double next() {\n        long long left = ((long long) (nextBits(26)) <<\
    \ 27);\n        long long right = nextBits(27);\n        return (double) (left\
    \ + right) / (double) (1LL << 53);\n    }\n\n    /* Random double value in range\
    \ [0, n). */\n    double next(double n) {\n        return n * next();\n    }\n\
    \n    /* Random double value in range [from, to). */\n    double next(double from,\
    \ double to) {\n        if (from > to)\n            __testlib_fail(\"random_t::next(double\
    \ from, double to): from can't not exceed to\");\n        return next(to - from)\
    \ + from;\n    }\n\n    /* Returns random element from container. */\n    template<typename\
    \ Container>\n    typename Container::value_type any(const Container &c) {\n \
    \       size_t size = c.size();\n        if (size <= 0)\n            __testlib_fail(\"\
    random_t::any(const Container& c): c.size() must be positive\");\n        return\
    \ *(c.begin() + next(size));\n    }\n\n    /* Returns random element from iterator\
    \ range. */\n    template<typename Iter>\n    typename Iter::value_type any(const\
    \ Iter &begin, const Iter &end) {\n        int size = int(end - begin);\n    \
    \    if (size <= 0)\n            __testlib_fail(\"random_t::any(const Iter& begin,\
    \ const Iter& end): range must have positive length\");\n        return *(begin\
    \ + next(size));\n    }\n\n    /* Random string value by given pattern (see pattern\
    \ documentation). */\n#ifdef __GNUC__\n    __attribute__ ((format (printf, 2,\
    \ 3)))\n#endif\n    std::string next(const char *format, ...) {\n        FMT_TO_RESULT(format,\
    \ format, ptrn);\n        return next(ptrn);\n    }\n\n    /* \n     * Weighted\
    \ next. If type == 0 than it is usual \"next()\".\n     *\n     * If type = 1,\
    \ than it returns \"max(next(), next())\"\n     * (the number of \"max\" functions\
    \ equals to \"type\").\n     *\n     * If type < 0, than \"max\" function replaces\
    \ with \"min\".\n     */\n    int wnext(int n, int type) {\n        if (n <= 0)\n\
    \            __testlib_fail(\"random_t::wnext(int n, int type): n must be positive\"\
    );\n\n        if (abs(type) < random_t::lim) {\n            int result = next(n);\n\
    \n            for (int i = 0; i < +type; i++)\n                result = __testlib_max(result,\
    \ next(n));\n\n            for (int i = 0; i < -type; i++)\n                result\
    \ = __testlib_min(result, next(n));\n\n            return result;\n        } else\
    \ {\n            double p;\n\n            if (type > 0)\n                p = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n            else\n                p = 1 - std::pow(next()\
    \ + 0.0, 1.0 / (-type + 1));\n\n            return int(n * p);\n        }\n  \
    \  }\n\n    /* See wnext(int, int). It uses the same algorithms. */\n    long\
    \ long wnext(long long n, int type) {\n        if (n <= 0)\n            __testlib_fail(\"\
    random_t::wnext(long long n, int type): n must be positive\");\n\n        if (abs(type)\
    \ < random_t::lim) {\n            long long result = next(n);\n\n            for\
    \ (int i = 0; i < +type; i++)\n                result = __testlib_max(result,\
    \ next(n));\n\n            for (int i = 0; i < -type; i++)\n                result\
    \ = __testlib_min(result, next(n));\n\n            return result;\n        } else\
    \ {\n            double p;\n\n            if (type > 0)\n                p = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n            else\n                p = std::pow(next()\
    \ + 0.0, -type + 1);\n\n            return __testlib_min(__testlib_max((long long)\
    \ (double(n) * p), 0LL), n - 1LL);\n        }\n    }\n\n    /* See wnext(int,\
    \ int). It uses the same algorithms. */\n    double wnext(int type) {\n      \
    \  if (abs(type) < random_t::lim) {\n            double result = next();\n\n \
    \           for (int i = 0; i < +type; i++)\n                result = __testlib_max(result,\
    \ next());\n\n            for (int i = 0; i < -type; i++)\n                result\
    \ = __testlib_min(result, next());\n\n            return result;\n        } else\
    \ {\n            double p;\n\n            if (type > 0)\n                p = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n            else\n                p = std::pow(next()\
    \ + 0.0, -type + 1);\n\n            return p;\n        }\n    }\n\n    /* See\
    \ wnext(int, int). It uses the same algorithms. */\n    double wnext(double n,\
    \ int type) {\n        if (n <= 0)\n            __testlib_fail(\"random_t::wnext(double\
    \ n, int type): n must be positive\");\n\n        if (abs(type) < random_t::lim)\
    \ {\n            double result = next();\n\n            for (int i = 0; i < +type;\
    \ i++)\n                result = __testlib_max(result, next());\n\n          \
    \  for (int i = 0; i < -type; i++)\n                result = __testlib_min(result,\
    \ next());\n\n            return n * result;\n        } else {\n            double\
    \ p;\n\n            if (type > 0)\n                p = std::pow(next() + 0.0,\
    \ 1.0 / (type + 1));\n            else\n                p = std::pow(next() +\
    \ 0.0, -type + 1);\n\n            return n * p;\n        }\n    }\n\n    /* See\
    \ wnext(int, int). It uses the same algorithms. */\n    unsigned int wnext(unsigned\
    \ int n, int type) {\n        if (n >= INT_MAX)\n            __testlib_fail(\"\
    random_t::wnext(unsigned int n, int type): n must be less INT_MAX\");\n      \
    \  return (unsigned int) wnext(int(n), type);\n    }\n\n    /* See wnext(int,\
    \ int). It uses the same algorithms. */\n    unsigned long long wnext(unsigned\
    \ long long n, int type) {\n        if (n >= (unsigned long long) (__TESTLIB_LONGLONG_MAX))\n\
    \            __testlib_fail(\"random_t::wnext(unsigned long long n, int type):\
    \ n must be less LONGLONG_MAX\");\n\n        return (unsigned long long) wnext((long\
    \ long) (n), type);\n    }\n\n    /* See wnext(int, int). It uses the same algorithms.\
    \ */\n    long wnext(long n, int type) {\n        return (long) wnext((long long)\
    \ (n), type);\n    }\n\n    /* See wnext(int, int). It uses the same algorithms.\
    \ */\n    unsigned long wnext(unsigned long n, int type) {\n        if (n >= (unsigned\
    \ long) (LONG_MAX))\n            __testlib_fail(\"random_t::wnext(unsigned long\
    \ n, int type): n must be less LONG_MAX\");\n\n        return (unsigned long)\
    \ wnext((unsigned long long) (n), type);\n    }\n\n    /* Returns weighted random\
    \ value in range [from, to]. */\n    int wnext(int from, int to, int type) {\n\
    \        if (from > to)\n            __testlib_fail(\"random_t::wnext(int from,\
    \ int to, int type): from can't not exceed to\");\n        return wnext(to - from\
    \ + 1, type) + from;\n    }\n\n    /* Returns weighted random value in range [from,\
    \ to]. */\n    int wnext(unsigned int from, unsigned int to, int type) {\n   \
    \     if (from > to)\n            __testlib_fail(\"random_t::wnext(unsigned int\
    \ from, unsigned int to, int type): from can't not exceed to\");\n        return\
    \ int(wnext(to - from + 1, type) + from);\n    }\n\n    /* Returns weighted random\
    \ value in range [from, to]. */\n    long long wnext(long long from, long long\
    \ to, int type) {\n        if (from > to)\n            __testlib_fail(\"random_t::wnext(long\
    \ long from, long long to, int type): from can't not exceed to\");\n        return\
    \ wnext(to - from + 1, type) + from;\n    }\n\n    /* Returns weighted random\
    \ value in range [from, to]. */\n    unsigned long long wnext(unsigned long long\
    \ from, unsigned long long to, int type) {\n        if (from > to)\n         \
    \   __testlib_fail(\n                    \"random_t::wnext(unsigned long long\
    \ from, unsigned long long to, int type): from can't not exceed to\");\n     \
    \   return wnext(to - from + 1, type) + from;\n    }\n\n    /* Returns weighted\
    \ random value in range [from, to]. */\n    long wnext(long from, long to, int\
    \ type) {\n        if (from > to)\n            __testlib_fail(\"random_t::wnext(long\
    \ from, long to, int type): from can't not exceed to\");\n        return wnext(to\
    \ - from + 1, type) + from;\n    }\n\n    /* Returns weighted random value in\
    \ range [from, to]. */\n    unsigned long wnext(unsigned long from, unsigned long\
    \ to, int type) {\n        if (from > to)\n            __testlib_fail(\"random_t::wnext(unsigned\
    \ long from, unsigned long to, int type): from can't not exceed to\");\n     \
    \   return wnext(to - from + 1, type) + from;\n    }\n\n    /* Returns weighted\
    \ random double value in range [from, to). */\n    double wnext(double from, double\
    \ to, int type) {\n        if (from > to)\n            __testlib_fail(\"random_t::wnext(double\
    \ from, double to, int type): from can't not exceed to\");\n        return wnext(to\
    \ - from, type) + from;\n    }\n\n    /* Returns weighted random element from\
    \ container. */\n    template<typename Container>\n    typename Container::value_type\
    \ wany(const Container &c, int type) {\n        size_t size = c.size();\n    \
    \    if (size <= 0)\n            __testlib_fail(\"random_t::wany(const Container&\
    \ c, int type): c.size() must be positive\");\n        return *(c.begin() + wnext(size,\
    \ type));\n    }\n\n    /* Returns weighted random element from iterator range.\
    \ */\n    template<typename Iter>\n    typename Iter::value_type wany(const Iter\
    \ &begin, const Iter &end, int type) {\n        int size = int(end - begin);\n\
    \        if (size <= 0)\n            __testlib_fail(\n                    \"random_t::any(const\
    \ Iter& begin, const Iter& end, int type): range must have positive length\");\n\
    \        return *(begin + wnext(size, type));\n    }\n\n    /* Returns random\
    \ permutation of the given size (values are between `first` and `first`+size-1)*/\n\
    \    template<typename T, typename E>\n    std::vector<E> perm(T size, E first)\
    \ {\n        if (size <= 0)\n            __testlib_fail(\"random_t::perm(T size,\
    \ E first = 0): size must be positive\");\n        std::vector<E> p(size);\n \
    \       E current = first;\n        for (T i = 0; i < size; i++)\n           \
    \ p[i] = current++;\n        if (size > 1)\n            for (T i = 1; i < size;\
    \ i++)\n                std::swap(p[i], p[next(i + 1)]);\n        return p;\n\
    \    }\n\n    /* Returns random permutation of the given size (values are between\
    \ 0 and size-1)*/\n    template<typename T>\n    std::vector<T> perm(T size) {\n\
    \        return perm(size, T(0));\n    }\n    \n    /* Returns `size` unordered\
    \ (unsorted) distinct numbers between `from` and `to`. */\n    template<typename\
    \ T>\n    std::vector<T> distinct(int size, T from, T to) {\n        if (from\
    \ > to)\n            __testlib_fail(\"random_t::distinct expected from <= to\"\
    );\n\n        if (size < 0)\n            __testlib_fail(\"random_t::distinct expected\
    \ size >= 0\");\n\n        uint64_t n = to - from + 1;\n        if (uint64_t(size)\
    \ > n)\n            __testlib_fail(\"random_t::distinct expected size <= to -\
    \ from + 1\");\n\n        std::vector<T> result;\n        if (size == 0)\n   \
    \         return result;\n\n        double expected = 0.0;\n        for (int i\
    \ = 1; i <= size; i++)\n            expected += double(n) / double(n - i + 1);\n\
    \        \n        if (expected < double(n)) {\n            std::set<T> vals;\n\
    \            while (int(vals.size()) < size)\n                vals.insert(T(next(from,\
    \ to)));\n            result.insert(result.end(), vals.begin(), vals.end());\n\
    \        } else {\n            if (n > 1000000000)\n                __testlib_fail(\"\
    random_t::distinct here expected to - from + 1 <= 1000000000\");\n           \
    \ std::vector<T> p(perm(int(n), from));\n            result.insert(result.end(),\
    \ p.begin(), p.begin() + size);\n        }\n\n        return result;\n    }\n\n\
    \    /* Returns `size` unordered (unsorted) distinct numbers between `0` and `upper`-1.\
    \ */\n    template<typename T>\n    std::vector<T> distinct(int size, T upper)\
    \ {\n        if (size < 0)\n            __testlib_fail(\"random_t::distinct expected\
    \ size >= 0\");\n        if (size == 0)\n            return std::vector<T>();\n\
    \        \n        if (upper <= 0)\n            __testlib_fail(\"random_t::distinct\
    \ expected upper > 0\");\n        if (size > upper)\n            __testlib_fail(\"\
    random_t::distinct expected size <= upper\");\n            \n        return distinct(size,\
    \ T(0), upper - 1);\n    }\n\n    /* Returns random (unsorted) partition which\
    \ is a representation of sum as a sum of integers not less than min_part. */\n\
    \    template<typename T>\n    std::vector<T> partition(int size, T sum, T min_part)\
    \ {\n        if (size < 0)\n            __testlib_fail(\"random_t::partition:\
    \ size < 0\");\n        if (size == 0 && sum != 0)\n            __testlib_fail(\"\
    random_t::partition: size == 0 && sum != 0\");\n        if (min_part * size >\
    \ sum)\n            __testlib_fail(\"random_t::partition: min_part * size > sum\"\
    );\n\n        T sum_ = sum;\n        sum -= min_part * size;\n\n        std::vector<T>\
    \ septums(size);\n        std::vector<T> d = distinct(size - 1, T(1), T(sum +\
    \ size - 1));\n        for (int i = 0; i + 1 < size; i++)\n            septums[i\
    \ + 1] = d[i];\n        sort(septums.begin(), septums.end());\n\n        std::vector<T>\
    \ result(size);\n        for (int i = 0; i + 1 < size; i++)\n            result[i]\
    \ = septums[i + 1] - septums[i] - 1;\n        result[size - 1] = sum + size -\
    \ 1 - septums.back();\n\n        for (std::size_t i = 0; i < result.size(); i++)\n\
    \            result[i] += min_part;\n        \n        T result_sum = 0;\n   \
    \     for (std::size_t i = 0; i < result.size(); i++)\n            result_sum\
    \ += result[i];\n        if (result_sum != sum_)\n            __testlib_fail(\"\
    random_t::partition: partition sum is expeced to be the given sum\");\n      \
    \  \n        if (*std::min_element(result.begin(), result.end()) < min_part)\n\
    \            __testlib_fail(\"random_t::partition: partition min is expeced to\
    \ be to less than the given min_part\");\n        \n        if (int(result.size())\
    \ != size || result.size() != (size_t) size)\n            __testlib_fail(\"random_t::partition:\
    \ partition size is expected to be equal to the given size\");\n        \n   \
    \     return result;\n    }\n\n    /* Returns random (unsorted) partition which\
    \ is a representation of sum as a sum of positive integers. */\n    template<typename\
    \ T>\n    std::vector<T> partition(int size, T sum) {\n        return partition(size,\
    \ sum, T(1));\n    }\n};\n\nconst int random_t::lim = 25;\nconst unsigned long\
    \ long random_t::multiplier = 0x5DEECE66DLL;\nconst unsigned long long random_t::addend\
    \ = 0xBLL;\nconst unsigned long long random_t::mask = (1LL << 48) - 1;\nint random_t::version\
    \ = -1;\n\n/* Pattern implementation */\nbool pattern::matches(const std::string\
    \ &s) const {\n    return matches(s, 0);\n}\n\nstatic bool __pattern_isSlash(const\
    \ std::string &s, size_t pos) {\n    return s[pos] == '\\\\';\n}\n\n#ifdef __GNUC__\n\
    __attribute__((pure))\n#endif\nstatic bool __pattern_isCommandChar(const std::string\
    \ &s, size_t pos, char value) {\n    if (pos >= s.length())\n        return false;\n\
    \n    int slashes = 0;\n\n    int before = int(pos) - 1;\n    while (before >=\
    \ 0 && s[before] == '\\\\')\n        before--, slashes++;\n\n    return slashes\
    \ % 2 == 0 && s[pos] == value;\n}\n\nstatic char __pattern_getChar(const std::string\
    \ &s, size_t &pos) {\n    if (__pattern_isSlash(s, pos))\n        pos += 2;\n\
    \    else\n        pos++;\n\n    return s[pos - 1];\n}\n\n#ifdef __GNUC__\n__attribute__((pure))\n\
    #endif\nstatic int __pattern_greedyMatch(const std::string &s, size_t pos, const\
    \ std::vector<char> chars) {\n    int result = 0;\n\n    while (pos < s.length())\
    \ {\n        char c = s[pos++];\n        if (!std::binary_search(chars.begin(),\
    \ chars.end(), c))\n            break;\n        else\n            result++;\n\
    \    }\n\n    return result;\n}\n\nstd::string pattern::src() const {\n    return\
    \ s;\n}\n\nbool pattern::matches(const std::string &s, size_t pos) const {\n \
    \   std::string result;\n\n    if (to > 0) {\n        int size = __pattern_greedyMatch(s,\
    \ pos, chars);\n        if (size < from)\n            return false;\n        if\
    \ (size > to)\n            size = to;\n        pos += size;\n    }\n\n    if (children.size()\
    \ > 0) {\n        for (size_t child = 0; child < children.size(); child++)\n \
    \           if (children[child].matches(s, pos))\n                return true;\n\
    \        return false;\n    } else\n        return pos == s.length();\n}\n\nstd::string\
    \ pattern::next(random_t &rnd) const {\n    std::string result;\n    result.reserve(20);\n\
    \n    if (to == INT_MAX)\n        __testlib_fail(\"pattern::next(random_t& rnd):\
    \ can't process character '*' for generation\");\n\n    if (to > 0) {\n      \
    \  int count = rnd.next(to - from + 1) + from;\n        for (int i = 0; i < count;\
    \ i++)\n            result += chars[rnd.next(int(chars.size()))];\n    }\n\n \
    \   if (children.size() > 0) {\n        int child = rnd.next(int(children.size()));\n\
    \        result += children[child].next(rnd);\n    }\n\n    return result;\n}\n\
    \nstatic void __pattern_scanCounts(const std::string &s, size_t &pos, int &from,\
    \ int &to) {\n    if (pos >= s.length()) {\n        from = to = 1;\n        return;\n\
    \    }\n\n    if (__pattern_isCommandChar(s, pos, '{')) {\n        std::vector<std::string>\
    \ parts;\n        std::string part;\n\n        pos++;\n\n        while (pos <\
    \ s.length() && !__pattern_isCommandChar(s, pos, '}')) {\n            if (__pattern_isCommandChar(s,\
    \ pos, ','))\n                parts.push_back(part), part = \"\", pos++;\n   \
    \         else\n                part += __pattern_getChar(s, pos);\n        }\n\
    \n        if (part != \"\")\n            parts.push_back(part);\n\n        if\
    \ (!__pattern_isCommandChar(s, pos, '}'))\n            __testlib_fail(\"pattern:\
    \ Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n        pos++;\n\n    \
    \    if (parts.size() < 1 || parts.size() > 2)\n            __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n        std::vector<int>\
    \ numbers;\n\n        for (size_t i = 0; i < parts.size(); i++) {\n          \
    \  if (parts[i].length() == 0)\n                __testlib_fail(\"pattern: Illegal\
    \ pattern (or part) \\\"\" + s + \"\\\"\");\n            int number;\n       \
    \     if (std::sscanf(parts[i].c_str(), \"%d\", &number) != 1)\n             \
    \   __testlib_fail(\"pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\"\
    );\n            numbers.push_back(number);\n        }\n\n        if (numbers.size()\
    \ == 1)\n            from = to = numbers[0];\n        else\n            from =\
    \ numbers[0], to = numbers[1];\n\n        if (from > to)\n            __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n    } else {\n   \
    \     if (__pattern_isCommandChar(s, pos, '?')) {\n            from = 0, to =\
    \ 1, pos++;\n            return;\n        }\n\n        if (__pattern_isCommandChar(s,\
    \ pos, '*')) {\n            from = 0, to = INT_MAX, pos++;\n            return;\n\
    \        }\n\n        if (__pattern_isCommandChar(s, pos, '+')) {\n          \
    \  from = 1, to = INT_MAX, pos++;\n            return;\n        }\n\n        from\
    \ = to = 1;\n    }\n}\n\nstatic std::vector<char> __pattern_scanCharSet(const\
    \ std::string &s, size_t &pos) {\n    if (pos >= s.length())\n        __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n    std::vector<char>\
    \ result;\n\n    if (__pattern_isCommandChar(s, pos, '[')) {\n        pos++;\n\
    \        bool negative = __pattern_isCommandChar(s, pos, '^');\n        if (negative)\n\
    \            pos++;\n\n        char prev = 0;\n\n        while (pos < s.length()\
    \ && !__pattern_isCommandChar(s, pos, ']')) {\n            if (__pattern_isCommandChar(s,\
    \ pos, '-') && prev != 0) {\n                pos++;\n\n                if (pos\
    \ + 1 == s.length() || __pattern_isCommandChar(s, pos, ']')) {\n             \
    \       result.push_back(prev);\n                    prev = '-';\n           \
    \         continue;\n                }\n\n                char next = __pattern_getChar(s,\
    \ pos);\n                if (prev > next)\n                    __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n               \
    \ for (char c = prev; c != next; c++)\n                    result.push_back(c);\n\
    \                result.push_back(next);\n\n                prev = 0;\n      \
    \      } else {\n                if (prev != 0)\n                    result.push_back(prev);\n\
    \                prev = __pattern_getChar(s, pos);\n            }\n        }\n\
    \n        if (prev != 0)\n            result.push_back(prev);\n\n        if (!__pattern_isCommandChar(s,\
    \ pos, ']'))\n            __testlib_fail(\"pattern: Illegal pattern (or part)\
    \ \\\"\" + s + \"\\\"\");\n\n        pos++;\n\n        if (negative) {\n     \
    \       std::sort(result.begin(), result.end());\n            std::vector<char>\
    \ actuals;\n            for (int code = 0; code < 255; code++) {\n           \
    \     char c = char(code);\n                if (!std::binary_search(result.begin(),\
    \ result.end(), c))\n                    actuals.push_back(c);\n            }\n\
    \            result = actuals;\n        }\n\n        std::sort(result.begin(),\
    \ result.end());\n    } else\n        result.push_back(__pattern_getChar(s, pos));\n\
    \n    return result;\n}\n\npattern::pattern(std::string s) : s(s), from(0), to(0)\
    \ {\n    std::string t;\n    for (size_t i = 0; i < s.length(); i++)\n       \
    \ if (!__pattern_isCommandChar(s, i, ' '))\n            t += s[i];\n    s = t;\n\
    \n    int opened = 0;\n    int firstClose = -1;\n    std::vector<int> seps;\n\n\
    \    for (size_t i = 0; i < s.length(); i++) {\n        if (__pattern_isCommandChar(s,\
    \ i, '(')) {\n            opened++;\n            continue;\n        }\n\n    \
    \    if (__pattern_isCommandChar(s, i, ')')) {\n            opened--;\n      \
    \      if (opened == 0 && firstClose == -1)\n                firstClose = int(i);\n\
    \            continue;\n        }\n\n        if (opened < 0)\n            __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n        if (__pattern_isCommandChar(s,\
    \ i, '|') && opened == 0)\n            seps.push_back(int(i));\n    }\n\n    if\
    \ (opened != 0)\n        __testlib_fail(\"pattern: Illegal pattern (or part) \\\
    \"\" + s + \"\\\"\");\n\n    if (seps.size() == 0 && firstClose + 1 == (int) s.length()\n\
    \        && __pattern_isCommandChar(s, 0, '(') && __pattern_isCommandChar(s, s.length()\
    \ - 1, ')')) {\n        children.push_back(pattern(s.substr(1, s.length() - 2)));\n\
    \    } else {\n        if (seps.size() > 0) {\n            seps.push_back(int(s.length()));\n\
    \            int last = 0;\n\n            for (size_t i = 0; i < seps.size();\
    \ i++) {\n                children.push_back(pattern(s.substr(last, seps[i] -\
    \ last)));\n                last = seps[i] + 1;\n            }\n        } else\
    \ {\n            size_t pos = 0;\n            chars = __pattern_scanCharSet(s,\
    \ pos);\n            __pattern_scanCounts(s, pos, from, to);\n            if (pos\
    \ < s.length())\n                children.push_back(pattern(s.substr(pos)));\n\
    \        }\n    }\n}\n\n/* End of pattern implementation */\n\ntemplate<typename\
    \ C>\ninline bool isEof(C c) {\n    return c == EOFC;\n}\n\ntemplate<typename\
    \ C>\ninline bool isEoln(C c) {\n    return (c == LF || c == CR);\n}\n\ntemplate<typename\
    \ C>\ninline bool isBlanks(C c) {\n    return (c == LF || c == CR || c == SPACE\
    \ || c == TAB);\n}\n\ninline std::string trim(const std::string &s) {\n    if\
    \ (s.empty())\n        return s;\n\n    int left = 0;\n    while (left < int(s.length())\
    \ && isBlanks(s[left]))\n        left++;\n    if (left >= int(s.length()))\n \
    \       return \"\";\n\n    int right = int(s.length()) - 1;\n    while (right\
    \ >= 0 && isBlanks(s[right]))\n        right--;\n    if (right < 0)\n        return\
    \ \"\";\n\n    return s.substr(left, right - left + 1);\n}\n\nenum TMode {\n \
    \   _input, _output, _answer\n};\n\n/* Outcomes 6-15 are reserved for future use.\
    \ */\nenum TResult {\n    _ok = 0,\n    _wa = 1,\n    _pe = 2,\n    _fail = 3,\n\
    \    _dirt = 4,\n    _points = 5,\n    _unexpected_eof = 8,\n    _partially =\
    \ 16\n};\n\nenum TTestlibMode {\n    _unknown, _checker, _validator, _generator,\
    \ _interactor\n};\n\n#define _pc(exitCode) (TResult(_partially + (exitCode)))\n\
    \n/* Outcomes 6-15 are reserved for future use. */\nconst std::string outcomes[]\
    \ = {\n        \"accepted\",\n        \"wrong-answer\",\n        \"presentation-error\"\
    ,\n        \"fail\",\n        \"fail\",\n#ifndef PCMS2\n        \"points\",\n\
    #else\n        \"relative-scoring\",\n#endif\n        \"reserved\",\n        \"\
    reserved\",\n        \"unexpected-eof\",\n        \"reserved\",\n        \"reserved\"\
    ,\n        \"reserved\",\n        \"reserved\",\n        \"reserved\",\n     \
    \   \"reserved\",\n        \"reserved\",\n        \"partially-correct\"\n};\n\n\
    class InputStreamReader {\npublic:\n    virtual int curChar() = 0;\n\n    virtual\
    \ int nextChar() = 0;\n\n    virtual void skipChar() = 0;\n\n    virtual void\
    \ unreadChar(int c) = 0;\n\n    virtual std::string getName() = 0;\n\n    virtual\
    \ bool eof() = 0;\n\n    virtual void close() = 0;\n\n    virtual int getLine()\
    \ = 0;\n\n    virtual ~InputStreamReader() = 0;\n};\n\nInputStreamReader::~InputStreamReader()\
    \ {\n    // No operations.\n}\n\nclass StringInputStreamReader : public InputStreamReader\
    \ {\nprivate:\n    std::string s;\n    size_t pos;\n\npublic:\n    StringInputStreamReader(const\
    \ std::string &content) : s(content), pos(0) {\n        // No operations.\n  \
    \  }\n\n    int curChar() {\n        if (pos >= s.length())\n            return\
    \ EOFC;\n        else\n            return s[pos];\n    }\n\n    int nextChar()\
    \ {\n        if (pos >= s.length()) {\n            pos++;\n            return\
    \ EOFC;\n        } else\n            return s[pos++];\n    }\n\n    void skipChar()\
    \ {\n        pos++;\n    }\n\n    void unreadChar(int c) {\n        if (pos ==\
    \ 0)\n            __testlib_fail(\"FileFileInputStreamReader::unreadChar(int):\
    \ pos == 0.\");\n        pos--;\n        if (pos < s.length())\n            s[pos]\
    \ = char(c);\n    }\n\n    std::string getName() {\n        return __testlib_part(s);\n\
    \    }\n\n    int getLine() {\n        return -1;\n    }\n\n    bool eof() {\n\
    \        return pos >= s.length();\n    }\n\n    void close() {\n        // No\
    \ operations.\n    }\n};\n\nclass FileInputStreamReader : public InputStreamReader\
    \ {\nprivate:\n    std::FILE *file;\n    std::string name;\n    int line;\n  \
    \  std::vector<int> undoChars;\n\n    inline int postprocessGetc(int getcResult)\
    \ {\n        if (getcResult != EOF)\n            return getcResult;\n        else\n\
    \            return EOFC;\n    }\n\n    int getc(FILE *file) {\n        int c;\n\
    \        if (undoChars.empty())\n            c = ::getc(file);\n        else {\n\
    \            c = undoChars.back();\n            undoChars.pop_back();\n      \
    \  }\n\n        if (c == LF)\n            line++;\n        return c;\n    }\n\n\
    \    int ungetc(int c/*, FILE* file*/) {\n        if (c == LF)\n            line--;\n\
    \        undoChars.push_back(c);\n        return c;\n    }\n\npublic:\n    FileInputStreamReader(std::FILE\
    \ *file, const std::string &name) : file(file), name(name), line(1) {\n      \
    \  // No operations.\n    }\n\n    int curChar() {\n        if (feof(file))\n\
    \            return EOFC;\n        else {\n            int c = getc(file);\n \
    \           ungetc(c/*, file*/);\n            return postprocessGetc(c);\n   \
    \     }\n    }\n\n    int nextChar() {\n        if (feof(file))\n            return\
    \ EOFC;\n        else\n            return postprocessGetc(getc(file));\n    }\n\
    \n    void skipChar() {\n        getc(file);\n    }\n\n    void unreadChar(int\
    \ c) {\n        ungetc(c/*, file*/);\n    }\n\n    std::string getName() {\n \
    \       return name;\n    }\n\n    int getLine() {\n        return line;\n   \
    \ }\n\n    bool eof() {\n        if (NULL == file || feof(file))\n           \
    \ return true;\n        else {\n            int c = nextChar();\n            if\
    \ (c == EOFC || (c == EOF && feof(file)))\n                return true;\n    \
    \        unreadChar(c);\n            return false;\n        }\n    }\n\n    void\
    \ close() {\n        if (NULL != file) {\n            fclose(file);\n        \
    \    file = NULL;\n        }\n    }\n};\n\nclass BufferedFileInputStreamReader\
    \ : public InputStreamReader {\nprivate:\n    static const size_t BUFFER_SIZE;\n\
    \    static const size_t MAX_UNREAD_COUNT;\n\n    std::FILE *file;\n    char *buffer;\n\
    \    bool *isEof;\n    int bufferPos;\n    size_t bufferSize;\n\n    std::string\
    \ name;\n    int line;\n\n    bool refill() {\n        if (NULL == file)\n   \
    \         __testlib_fail(\"BufferedFileInputStreamReader: file == NULL (\" + getName()\
    \ + \")\");\n\n        if (bufferPos >= int(bufferSize)) {\n            size_t\
    \ readSize = fread(\n                    buffer + MAX_UNREAD_COUNT,\n        \
    \            1,\n                    BUFFER_SIZE - MAX_UNREAD_COUNT,\n       \
    \             file\n            );\n\n            if (readSize < BUFFER_SIZE -\
    \ MAX_UNREAD_COUNT\n                && ferror(file))\n                __testlib_fail(\"\
    BufferedFileInputStreamReader: unable to read (\" + getName() + \")\");\n\n  \
    \          bufferSize = MAX_UNREAD_COUNT + readSize;\n            bufferPos =\
    \ int(MAX_UNREAD_COUNT);\n            std::memset(isEof + MAX_UNREAD_COUNT, 0,\
    \ sizeof(isEof[0]) * readSize);\n\n            return readSize > 0;\n        }\
    \ else\n            return true;\n    }\n\n    char increment() {\n        char\
    \ c;\n        if ((c = buffer[bufferPos++]) == LF)\n            line++;\n    \
    \    return c;\n    }\n\npublic:\n    BufferedFileInputStreamReader(std::FILE\
    \ *file, const std::string &name) : file(file), name(name), line(1) {\n      \
    \  buffer = new char[BUFFER_SIZE];\n        isEof = new bool[BUFFER_SIZE];\n \
    \       bufferSize = MAX_UNREAD_COUNT;\n        bufferPos = int(MAX_UNREAD_COUNT);\n\
    \    }\n\n    ~BufferedFileInputStreamReader() {\n        if (NULL != buffer)\
    \ {\n            delete[] buffer;\n            buffer = NULL;\n        }\n   \
    \     if (NULL != isEof) {\n            delete[] isEof;\n            isEof = NULL;\n\
    \        }\n    }\n\n    int curChar() {\n        if (!refill())\n           \
    \ return EOFC;\n\n        return isEof[bufferPos] ? EOFC : buffer[bufferPos];\n\
    \    }\n\n    int nextChar() {\n        if (!refill())\n            return EOFC;\n\
    \n        return isEof[bufferPos] ? EOFC : increment();\n    }\n\n    void skipChar()\
    \ {\n        increment();\n    }\n\n    void unreadChar(int c) {\n        bufferPos--;\n\
    \        if (bufferPos < 0)\n            __testlib_fail(\"BufferedFileInputStreamReader::unreadChar(int):\
    \ bufferPos < 0\");\n        isEof[bufferPos] = (c == EOFC);\n        buffer[bufferPos]\
    \ = char(c);\n        if (c == LF)\n            line--;\n    }\n\n    std::string\
    \ getName() {\n        return name;\n    }\n\n    int getLine() {\n        return\
    \ line;\n    }\n\n    bool eof() {\n        return !refill() || EOFC == curChar();\n\
    \    }\n\n    void close() {\n        if (NULL != file) {\n            fclose(file);\n\
    \            file = NULL;\n        }\n    }\n};\n\nconst size_t BufferedFileInputStreamReader::BUFFER_SIZE\
    \ = 2000000;\nconst size_t BufferedFileInputStreamReader::MAX_UNREAD_COUNT = BufferedFileInputStreamReader::BUFFER_SIZE\
    \ / 2;\n\n/*\n * Streams to be used for reading data in checkers or validators.\n\
    \ * Each read*() method moves pointer to the next character after the\n * read\
    \ value.\n */\nstruct InStream {\n    /* Do not use them. */\n    InStream();\n\
    \n    ~InStream();\n\n    /* Wrap std::string with InStream. */\n    InStream(const\
    \ InStream &baseStream, std::string content);\n\n    InputStreamReader *reader;\n\
    \    int lastLine;\n\n    std::string name;\n    TMode mode;\n    bool opened;\n\
    \    bool stdfile;\n    bool strict;\n\n    std::string _tmpReadToken;\n\n   \
    \ int readManyIteration;\n    size_t maxFileSize;\n    size_t maxTokenLength;\n\
    \    size_t maxMessageLength;\n\n    void init(std::string fileName, TMode mode);\n\
    \n    void init(std::FILE *f, TMode mode);\n\n    /* Moves stream pointer to the\
    \ first non-white-space character or EOF. */\n    void skipBlanks();\n\n    /*\
    \ Returns current character in the stream. Doesn't remove it from stream. */\n\
    \    char curChar();\n\n    /* Moves stream pointer one character forward. */\n\
    \    void skipChar();\n\n    /* Returns current character and moves pointer one\
    \ character forward. */\n    char nextChar();\n\n    /* Returns current character\
    \ and moves pointer one character forward. */\n    char readChar();\n\n    /*\
    \ As \"readChar()\" but ensures that the result is equal to given parameter. */\n\
    \    char readChar(char c);\n\n    /* As \"readChar()\" but ensures that the result\
    \ is equal to the space (code=32). */\n    char readSpace();\n\n    /* Puts back\
    \ the character into the stream. */\n    void unreadChar(char c);\n\n    /* Reopens\
    \ stream, you should not use it. */\n    void reset(std::FILE *file = NULL);\n\
    \n    /* Checks that current position is EOF. If not it doesn't move stream pointer.\
    \ */\n    bool eof();\n\n    /* Moves pointer to the first non-white-space character\
    \ and calls \"eof()\". */\n    bool seekEof();\n\n    /* \n     * Checks that\
    \ current position contains EOLN. \n     * If not it doesn't move stream pointer.\
    \ \n     * In strict mode expects \"#13#10\" for windows or \"#10\" for other\
    \ platforms.\n     */\n    bool eoln();\n\n    /* Moves pointer to the first non-space\
    \ and non-tab character and calls \"eoln()\". */\n    bool seekEoln();\n\n   \
    \ /* Moves stream pointer to the first character of the next line (if exists).\
    \ */\n    void nextLine();\n\n    /* \n     * Reads new token. Ignores white-spaces\
    \ into the non-strict mode \n     * (strict mode is used in validators usually).\
    \ \n     */\n    std::string readWord();\n\n    /* The same as \"readWord()\"\
    , it is preffered to use \"readToken()\". */\n    std::string readToken();\n\n\
    \    /* The same as \"readWord()\", but ensures that token matches to given pattern.\
    \ */\n    std::string readWord(const std::string &ptrn, const std::string &variableName\
    \ = \"\");\n\n    std::string readWord(const pattern &p, const std::string &variableName\
    \ = \"\");\n\n    std::vector<std::string>\n    readWords(int size, const std::string\
    \ &ptrn, const std::string &variablesName = \"\", int indexBase = 1);\n\n    std::vector<std::string>\n\
    \    readWords(int size, const pattern &p, const std::string &variablesName =\
    \ \"\", int indexBase = 1);\n\n    std::vector<std::string> readWords(int size,\
    \ int indexBase = 1);\n\n    /* The same as \"readToken()\", but ensures that\
    \ token matches to given pattern. */\n    std::string readToken(const std::string\
    \ &ptrn, const std::string &variableName = \"\");\n\n    std::string readToken(const\
    \ pattern &p, const std::string &variableName = \"\");\n\n    std::vector<std::string>\n\
    \    readTokens(int size, const std::string &ptrn, const std::string &variablesName\
    \ = \"\", int indexBase = 1);\n\n    std::vector<std::string>\n    readTokens(int\
    \ size, const pattern &p, const std::string &variablesName = \"\", int indexBase\
    \ = 1);\n\n    std::vector<std::string> readTokens(int size, int indexBase = 1);\n\
    \n    void readWordTo(std::string &result);\n\n    void readWordTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n    void\
    \ readWordTo(std::string &result, const std::string &ptrn, const std::string &variableName\
    \ = \"\");\n\n    void readTokenTo(std::string &result);\n\n    void readTokenTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n    void\
    \ readTokenTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName = \"\");\n\n    /* \n     * Reads new long long value. Ignores\
    \ white-spaces into the non-strict mode \n     * (strict mode is used in validators\
    \ usually). \n     */\n    long long readLong();\n\n    unsigned long long readUnsignedLong();\n\
    \n    /*\n     * Reads new int. Ignores white-spaces into the non-strict mode\
    \ \n     * (strict mode is used in validators usually). \n     */\n    int readInteger();\n\
    \n    /*\n     * Reads new int. Ignores white-spaces into the non-strict mode\
    \ \n     * (strict mode is used in validators usually). \n     */\n    int readInt();\n\
    \n    /* As \"readLong()\" but ensures that value in the range [minv,maxv]. */\n\
    \    long long readLong(long long minv, long long maxv, const std::string &variableName\
    \ = \"\");\n\n    /* Reads space-separated sequence of long longs. */\n    std::vector<long\
    \ long>\n    readLongs(int size, long long minv, long long maxv, const std::string\
    \ &variablesName = \"\", int indexBase = 1);\n\n    /* Reads space-separated sequence\
    \ of long longs. */\n    std::vector<long long> readLongs(int size, int indexBase\
    \ = 1);\n\n    unsigned long long\n    readUnsignedLong(unsigned long long minv,\
    \ unsigned long long maxv, const std::string &variableName = \"\");\n\n    std::vector<unsigned\
    \ long long>\n    readUnsignedLongs(int size, unsigned long long minv, unsigned\
    \ long long maxv, const std::string &variablesName = \"\",\n                 \
    \     int indexBase = 1);\n\n    std::vector<unsigned long long> readUnsignedLongs(int\
    \ size, int indexBase = 1);\n\n    unsigned long long readLong(unsigned long long\
    \ minv, unsigned long long maxv, const std::string &variableName = \"\");\n\n\
    \    std::vector<unsigned long long>\n    readLongs(int size, unsigned long long\
    \ minv, unsigned long long maxv, const std::string &variablesName = \"\",\n  \
    \            int indexBase = 1);\n\n    /* As \"readInteger()\" but ensures that\
    \ value in the range [minv,maxv]. */\n    int readInteger(int minv, int maxv,\
    \ const std::string &variableName = \"\");\n\n    /* As \"readInt()\" but ensures\
    \ that value in the range [minv,maxv]. */\n    int readInt(int minv, int maxv,\
    \ const std::string &variableName = \"\");\n\n    /* Reads space-separated sequence\
    \ of integers. */\n    std::vector<int>\n    readIntegers(int size, int minv,\
    \ int maxv, const std::string &variablesName = \"\", int indexBase = 1);\n\n \
    \   /* Reads space-separated sequence of integers. */\n    std::vector<int> readIntegers(int\
    \ size, int indexBase = 1);\n\n    /* Reads space-separated sequence of integers.\
    \ */\n    std::vector<int> readInts(int size, int minv, int maxv, const std::string\
    \ &variablesName = \"\", int indexBase = 1);\n\n    /* Reads space-separated sequence\
    \ of integers. */\n    std::vector<int> readInts(int size, int indexBase = 1);\n\
    \n    /* \n     * Reads new double. Ignores white-spaces into the non-strict mode\
    \ \n     * (strict mode is used in validators usually). \n     */\n    double\
    \ readReal();\n\n    /*\n     * Reads new double. Ignores white-spaces into the\
    \ non-strict mode \n     * (strict mode is used in validators usually). \n   \
    \  */\n    double readDouble();\n\n    /* As \"readReal()\" but ensures that value\
    \ in the range [minv,maxv]. */\n    double readReal(double minv, double maxv,\
    \ const std::string &variableName = \"\");\n\n    std::vector<double>\n    readReals(int\
    \ size, double minv, double maxv, const std::string &variablesName = \"\", int\
    \ indexBase = 1);\n\n    std::vector<double> readReals(int size, int indexBase\
    \ = 1);\n\n    /* As \"readDouble()\" but ensures that value in the range [minv,maxv].\
    \ */\n    double readDouble(double minv, double maxv, const std::string &variableName\
    \ = \"\");\n\n    std::vector<double>\n    readDoubles(int size, double minv,\
    \ double maxv, const std::string &variablesName = \"\", int indexBase = 1);\n\n\
    \    std::vector<double> readDoubles(int size, int indexBase = 1);\n\n    /* \n\
    \     * As \"readReal()\" but ensures that value in the range [minv,maxv] and\n\
    \     * number of digit after the decimal point is in range [minAfterPointDigitCount,maxAfterPointDigitCount]\n\
    \     * and number is in the form \"[-]digit(s)[.digit(s)]\".\n     */\n    double\
    \ readStrictReal(double minv, double maxv,\n                          int minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n                          const std::string &variableName\
    \ = \"\");\n\n    std::vector<double> readStrictReals(int size, double minv, double\
    \ maxv,\n                                        int minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n                                        const\
    \ std::string &variablesName = \"\", int indexBase = 1);\n\n    /* \n     * As\
    \ \"readDouble()\" but ensures that value in the range [minv,maxv] and\n     *\
    \ number of digit after the decimal point is in range [minAfterPointDigitCount,maxAfterPointDigitCount]\n\
    \     * and number is in the form \"[-]digit(s)[.digit(s)]\".\n     */\n    double\
    \ readStrictDouble(double minv, double maxv,\n                            int\
    \ minAfterPointDigitCount, int maxAfterPointDigitCount,\n                    \
    \        const std::string &variableName = \"\");\n\n    std::vector<double> readStrictDoubles(int\
    \ size, double minv, double maxv,\n                                          int\
    \ minAfterPointDigitCount, int maxAfterPointDigitCount,\n                    \
    \                      const std::string &variablesName = \"\", int indexBase\
    \ = 1);\n\n    /* As readLine(). */\n    std::string readString();\n\n    /* Read\
    \ many lines. */\n    std::vector<std::string> readStrings(int size, int indexBase\
    \ = 1);\n\n    /* See readLine(). */\n    void readStringTo(std::string &result);\n\
    \n    /* The same as \"readLine()/readString()\", but ensures that line matches\
    \ to the given pattern. */\n    std::string readString(const pattern &p, const\
    \ std::string &variableName = \"\");\n\n    /* The same as \"readLine()/readString()\"\
    , but ensures that line matches to the given pattern. */\n    std::string readString(const\
    \ std::string &ptrn, const std::string &variableName = \"\");\n\n    /* Read many\
    \ lines. */\n    std::vector<std::string>\n    readStrings(int size, const pattern\
    \ &p, const std::string &variableName = \"\", int indexBase = 1);\n\n    /* Read\
    \ many lines. */\n    std::vector<std::string>\n    readStrings(int size, const\
    \ std::string &ptrn, const std::string &variableName = \"\", int indexBase = 1);\n\
    \n    /* The same as \"readLine()/readString()\", but ensures that line matches\
    \ to the given pattern. */\n    void readStringTo(std::string &result, const pattern\
    \ &p, const std::string &variableName = \"\");\n\n    /* The same as \"readLine()/readString()\"\
    , but ensures that line matches to the given pattern. */\n    void readStringTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName = \"\");\n\
    \n    /* \n     * Reads line from the current position to EOLN or EOF. Moves stream\
    \ pointer to \n     * the first character of the new line (if possible). \n  \
    \   */\n    std::string readLine();\n\n    /* Read many lines. */\n    std::vector<std::string>\
    \ readLines(int size, int indexBase = 1);\n\n    /* See readLine(). */\n    void\
    \ readLineTo(std::string &result);\n\n    /* The same as \"readLine()\", but ensures\
    \ that line matches to the given pattern. */\n    std::string readLine(const pattern\
    \ &p, const std::string &variableName = \"\");\n\n    /* The same as \"readLine()\"\
    , but ensures that line matches to the given pattern. */\n    std::string readLine(const\
    \ std::string &ptrn, const std::string &variableName = \"\");\n\n    /* Read many\
    \ lines. */\n    std::vector<std::string>\n    readLines(int size, const pattern\
    \ &p, const std::string &variableName = \"\", int indexBase = 1);\n\n    /* Read\
    \ many lines. */\n    std::vector<std::string>\n    readLines(int size, const\
    \ std::string &ptrn, const std::string &variableName = \"\", int indexBase = 1);\n\
    \n    /* The same as \"readLine()\", but ensures that line matches to the given\
    \ pattern. */\n    void readLineTo(std::string &result, const pattern &p, const\
    \ std::string &variableName = \"\");\n\n    /* The same as \"readLine()\", but\
    \ ensures that line matches to the given pattern. */\n    void readLineTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName = \"\");\n\
    \n    /* Reads EOLN or fails. Use it in validators. Calls \"eoln()\" method internally.\
    \ */\n    void readEoln();\n\n    /* Reads EOF or fails. Use it in validators.\
    \ Calls \"eof()\" method internally. */\n    void readEof();\n\n    /* \n    \
    \ * Quit-functions aborts program with <result> and <message>:\n     * input/answer\
    \ streams replace any result to FAIL.\n     */\n    NORETURN void quit(TResult\
    \ result, const char *msg);\n    /* \n     * Quit-functions aborts program with\
    \ <result> and <message>:\n     * input/answer streams replace any result to FAIL.\n\
    \     */\n    NORETURN void quitf(TResult result, const char *msg, ...);\n\n \
    \   /*\n     * Quit-functions aborts program with <result> and <message>:\n  \
    \   * input/answer streams replace any result to FAIL.\n     */\n    void quitif(bool\
    \ condition, TResult result, const char *msg, ...);\n    /* \n     * Quit-functions\
    \ aborts program with <result> and <message>:\n     * input/answer streams replace\
    \ any result to FAIL.\n     */\n    NORETURN void quits(TResult result, std::string\
    \ msg);\n\n    /* \n     * Checks condition and aborts a program if codition is\
    \ false.\n     * Returns _wa for ouf and _fail on any other streams.\n     */\n\
    #ifdef __GNUC__\n    __attribute__ ((format (printf, 3, 4)))\n#endif\n    void\
    \ ensuref(bool cond, const char *format, ...);\n\n    void __testlib_ensure(bool\
    \ cond, std::string message);\n\n    void close();\n\n    const static int NO_INDEX\
    \ = INT_MAX;\n    const static char OPEN_BRACKET = char(11);\n    const static\
    \ char CLOSE_BRACKET = char(17);\n\n    const static WORD LightGray = 0x07;\n\
    \    const static WORD LightRed = 0x0c;\n    const static WORD LightCyan = 0x0b;\n\
    \    const static WORD LightGreen = 0x0a;\n    const static WORD LightYellow =\
    \ 0x0e;\n\n    static void textColor(WORD color);\n\n    static void quitscr(WORD\
    \ color, const char *msg);\n\n    static void quitscrS(WORD color, std::string\
    \ msg);\n\n    void xmlSafeWrite(std::FILE *file, const char *msg);\n\nprivate:\n\
    \    InStream(const InStream &);\n\n    InStream &operator=(const InStream &);\n\
    };\n\nInStream inf;\nInStream ouf;\nInStream ans;\nbool appesMode;\nstd::string\
    \ resultName;\nstd::string checkerName = \"untitled checker\";\nrandom_t rnd;\n\
    TTestlibMode testlibMode = _unknown;\ndouble __testlib_points = std::numeric_limits<float>::infinity();\n\
    \nstruct ValidatorBoundsHit {\n    static const double EPS;\n    bool minHit;\n\
    \    bool maxHit;\n\n    ValidatorBoundsHit(bool minHit = false, bool maxHit =\
    \ false) : minHit(minHit), maxHit(maxHit) {\n    };\n\n    ValidatorBoundsHit\
    \ merge(const ValidatorBoundsHit &validatorBoundsHit) {\n        return ValidatorBoundsHit(\n\
    \                __testlib_max(minHit, validatorBoundsHit.minHit),\n         \
    \       __testlib_max(maxHit, validatorBoundsHit.maxHit)\n        );\n    }\n\
    };\n\nconst double ValidatorBoundsHit::EPS = 1E-12;\n\nclass Validator {\nprivate:\n\
    \    bool _initialized;\n    std::string _testset;\n    std::string _group;\n\
    \    std::string _testOverviewLogFileName;\n    std::map<std::string, ValidatorBoundsHit>\
    \ _boundsHitByVariableName;\n    std::set<std::string> _features;\n    std::set<std::string>\
    \ _hitFeatures;\n\n    bool isVariableNameBoundsAnalyzable(const std::string &variableName)\
    \ {\n        for (size_t i = 0; i < variableName.length(); i++)\n            if\
    \ ((variableName[i] >= '0' && variableName[i] <= '9') || variableName[i] < ' ')\n\
    \                return false;\n        return true;\n    }\n\n    bool isFeatureNameAnalyzable(const\
    \ std::string &featureName) {\n        for (size_t i = 0; i < featureName.length();\
    \ i++)\n            if (featureName[i] < ' ')\n                return false;\n\
    \        return true;\n    }\n\npublic:\n    Validator() : _initialized(false),\
    \ _testset(\"tests\"), _group() {\n    }\n\n    void initialize() {\n        _initialized\
    \ = true;\n    }\n\n    std::string testset() const {\n        if (!_initialized)\n\
    \            __testlib_fail(\"Validator should be initialized with registerValidation(argc,\
    \ argv) instead of registerValidation() to support validator.testset()\");\n \
    \       return _testset;\n    }\n\n    std::string group() const {\n        if\
    \ (!_initialized)\n            __testlib_fail(\"Validator should be initialized\
    \ with registerValidation(argc, argv) instead of registerValidation() to support\
    \ validator.group()\");\n        return _group;\n    }\n\n    std::string testOverviewLogFileName()\
    \ const {\n        return _testOverviewLogFileName;\n    }\n\n    void setTestset(const\
    \ char *const testset) {\n        _testset = testset;\n    }\n\n    void setGroup(const\
    \ char *const group) {\n        _group = group;\n    }\n\n    void setTestOverviewLogFileName(const\
    \ char *const testOverviewLogFileName) {\n        _testOverviewLogFileName = testOverviewLogFileName;\n\
    \    }\n\n    void addBoundsHit(const std::string &variableName, ValidatorBoundsHit\
    \ boundsHit) {\n        if (isVariableNameBoundsAnalyzable(variableName)) {\n\
    \            _boundsHitByVariableName[variableName]\n                    = boundsHit.merge(_boundsHitByVariableName[variableName]);\n\
    \        }\n    }\n\n    std::string getBoundsHitLog() {\n        std::string\
    \ result;\n        for (std::map<std::string, ValidatorBoundsHit>::iterator i\
    \ = _boundsHitByVariableName.begin();\n             i != _boundsHitByVariableName.end();\n\
    \             i++) {\n            result += \"\\\"\" + i->first + \"\\\":\";\n\
    \            if (i->second.minHit)\n                result += \" min-value-hit\"\
    ;\n            if (i->second.maxHit)\n                result += \" max-value-hit\"\
    ;\n            result += \"\\n\";\n        }\n        return result;\n    }\n\n\
    \    std::string getFeaturesLog() {\n        std::string result;\n        for\
    \ (std::set<std::string>::iterator i = _features.begin();\n             i != _features.end();\n\
    \             i++) {\n            result += \"feature \\\"\" + *i + \"\\\":\"\
    ;\n            if (_hitFeatures.count(*i))\n                result += \" hit\"\
    ;\n            result += \"\\n\";\n        }\n        return result;\n    }\n\n\
    \    void writeTestOverviewLog() {\n        if (!_testOverviewLogFileName.empty())\
    \ {\n            std::string fileName(_testOverviewLogFileName);\n           \
    \ _testOverviewLogFileName = \"\";\n            FILE *testOverviewLogFile = fopen(fileName.c_str(),\
    \ \"w\");\n            if (NULL == testOverviewLogFile)\n                __testlib_fail(\"\
    Validator::writeTestOverviewLog: can't test overview log to (\" + fileName + \"\
    )\");\n            fprintf(testOverviewLogFile, \"%s%s\", getBoundsHitLog().c_str(),\
    \ getFeaturesLog().c_str());\n            if (fclose(testOverviewLogFile))\n \
    \               __testlib_fail(\n                        \"Validator::writeTestOverviewLog:\
    \ can't close test overview log file (\" + fileName + \")\");\n        }\n   \
    \ }\n\n    void addFeature(const std::string &feature) {\n        if (_features.count(feature))\n\
    \            __testlib_fail(\"Feature \" + feature + \" registered twice.\");\n\
    \        if (!isFeatureNameAnalyzable(feature))\n            __testlib_fail(\"\
    Feature name '\" + feature + \"' contains restricted characters.\");\n\n     \
    \   _features.insert(feature);\n    }\n\n    void feature(const std::string &feature)\
    \ {\n        if (!isFeatureNameAnalyzable(feature))\n            __testlib_fail(\"\
    Feature name '\" + feature + \"' contains restricted characters.\");\n\n     \
    \   if (!_features.count(feature))\n            __testlib_fail(\"Feature \" +\
    \ feature + \" didn't registered via addFeature(feature).\");\n\n        _hitFeatures.insert(feature);\n\
    \    }\n} validator;\n\nstruct TestlibFinalizeGuard {\n    static bool alive;\n\
    \    int quitCount, readEofCount;\n\n    TestlibFinalizeGuard() : quitCount(0),\
    \ readEofCount(0) {\n        // No operations.\n    }\n\n    ~TestlibFinalizeGuard()\
    \ {\n        bool _alive = alive;\n        alive = false;\n\n        if (_alive)\
    \ {\n            if (testlibMode == _checker && quitCount == 0)\n            \
    \    __testlib_fail(\"Checker must end with quit or quitf call.\");\n\n      \
    \      if (testlibMode == _validator && readEofCount == 0 && quitCount == 0)\n\
    \                __testlib_fail(\"Validator must end with readEof call.\");\n\
    \        }\n\n        validator.writeTestOverviewLog();\n    }\n};\n\nbool TestlibFinalizeGuard::alive\
    \ = true;\nTestlibFinalizeGuard testlibFinalizeGuard;\n\n/*\n * Call it to disable\
    \ checks on finalization.\n */\nvoid disableFinalizeGuard() {\n    TestlibFinalizeGuard::alive\
    \ = false;\n}\n\n/* Interactor streams.\n */\nstd::fstream tout;\n\n/* implementation\n\
    \ */\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\ntemplate<typename T>\n\
    static std::string vtos(const T &t, std::true_type) {\n    if (t == 0)\n     \
    \   return \"0\";\n    else {\n        T n(t);\n        bool negative = n < 0;\n\
    \        std::string s;\n        while (n != 0) {\n            T digit = n % 10;\n\
    \            if (digit < 0)\n                digit = -digit;\n            s +=\
    \ char('0' + digit);\n            n /= 10;\n        }\n        std::reverse(s.begin(),\
    \ s.end());\n        return negative ? \"-\" + s : s;\n    }\n}\n\ntemplate<typename\
    \ T>\nstatic std::string vtos(const T &t, std::false_type) {\n    std::string\
    \ s;\n    static std::stringstream ss;\n    ss.str(std::string());\n    ss.clear();\n\
    \    ss << t;\n    ss >> s;\n    return s;\n}\n\ntemplate<typename T>\nstatic\
    \ std::string vtos(const T &t) {\n    return vtos(t, std::is_integral<T>());\n\
    }\n\n/* signed case. */\ntemplate<typename T>\nstatic std::string toHumanReadableString(const\
    \ T &n, std::false_type) {\n    if (n == 0)\n        return vtos(n);\n    int\
    \ trailingZeroCount = 0;\n    T n_ = n;\n    while (n_ % 10 == 0)\n        n_\
    \ /= 10, trailingZeroCount++;\n    if (trailingZeroCount >= 7) {\n        if (n_\
    \ == 1)\n            return \"10^\" + vtos(trailingZeroCount);\n        else if\
    \ (n_ == -1)\n            return \"-10^\" + vtos(trailingZeroCount);\n       \
    \ else\n            return vtos(n_) + \"*10^\" + vtos(trailingZeroCount);\n  \
    \  } else\n        return vtos(n);\n}\n\n/* unsigned case. */\ntemplate<typename\
    \ T>\nstatic std::string toHumanReadableString(const T &n, std::true_type) {\n\
    \    if (n == 0)\n        return vtos(n);\n    int trailingZeroCount = 0;\n  \
    \  T n_ = n;\n    while (n_ % 10 == 0)\n        n_ /= 10, trailingZeroCount++;\n\
    \    if (trailingZeroCount >= 7) {\n        if (n_ == 1)\n            return \"\
    10^\" + vtos(trailingZeroCount);\n        else\n            return vtos(n_) +\
    \ \"*10^\" + vtos(trailingZeroCount);\n    } else\n        return vtos(n);\n}\n\
    \ntemplate<typename T>\nstatic std::string toHumanReadableString(const T &n) {\n\
    \    return toHumanReadableString(n, std::is_unsigned<T>());\n}\n#else\ntemplate<typename\
    \ T>\nstatic std::string vtos(const T& t)\n{\n    std::string s;\n    static std::stringstream\
    \ ss;\n    ss.str(std::string());\n    ss.clear();\n    ss << t;\n    ss >> s;\n\
    \    return s;\n}\n\ntemplate<typename T>\nstatic std::string toHumanReadableString(const\
    \ T &n) {\n    return vtos(n);\n}\n#endif\n\ntemplate<typename T>\nstatic std::string\
    \ toString(const T &t) {\n    return vtos(t);\n}\n\nInStream::InStream() {\n \
    \   reader = NULL;\n    lastLine = -1;\n    opened = false;\n    name = \"\";\n\
    \    mode = _input;\n    strict = false;\n    stdfile = false;\n    readManyIteration\
    \ = NO_INDEX;\n    maxFileSize = 128 * 1024 * 1024; // 128MB.\n    maxTokenLength\
    \ = 32 * 1024 * 1024; // 32MB.\n    maxMessageLength = 32000;\n}\n\nInStream::InStream(const\
    \ InStream &baseStream, std::string content) {\n    reader = new StringInputStreamReader(content);\n\
    \    lastLine = -1;\n    opened = true;\n    strict = baseStream.strict;\n   \
    \ stdfile = false;\n    mode = baseStream.mode;\n    name = \"based on \" + baseStream.name;\n\
    \    readManyIteration = NO_INDEX;\n    maxFileSize = 128 * 1024 * 1024; // 128MB.\n\
    \    maxTokenLength = 32 * 1024 * 1024; // 32MB.\n    maxMessageLength = 32000;\n\
    }\n\nInStream::~InStream() {\n    if (NULL != reader) {\n        reader->close();\n\
    \        delete reader;\n        reader = NULL;\n    }\n}\n\n#ifdef __GNUC__\n\
    __attribute__((const))\n#endif\nint resultExitCode(TResult r) {\n    if (r ==\
    \ _ok)\n        return OK_EXIT_CODE;\n    if (r == _wa)\n        return WA_EXIT_CODE;\n\
    \    if (r == _pe)\n        return PE_EXIT_CODE;\n    if (r == _fail)\n      \
    \  return FAIL_EXIT_CODE;\n    if (r == _dirt)\n        return DIRT_EXIT_CODE;\n\
    \    if (r == _points)\n        return POINTS_EXIT_CODE;\n    if (r == _unexpected_eof)\n\
    #ifdef ENABLE_UNEXPECTED_EOF\n        return UNEXPECTED_EOF_EXIT_CODE;\n#else\n\
    \        return PE_EXIT_CODE;\n#endif\n    if (r >= _partially)\n        return\
    \ PC_BASE_EXIT_CODE + (r - _partially);\n    return FAIL_EXIT_CODE;\n}\n\nvoid\
    \ InStream::textColor(\n#if !(defined(ON_WINDOWS) && (!defined(_MSC_VER) || _MSC_VER\
    \ > 1400)) && defined(__GNUC__)\n        __attribute__((unused))\n#endif\n   \
    \     WORD color\n) {\n#if defined(ON_WINDOWS) && (!defined(_MSC_VER) || _MSC_VER\
    \ > 1400)\n    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);\n    SetConsoleTextAttribute(handle,\
    \ color);\n#endif\n#if !defined(ON_WINDOWS) && defined(__GNUC__)\n    if (isatty(2))\n\
    \    {\n        switch (color)\n        {\n        case LightRed:\n          \
    \  fprintf(stderr, \"\\033[1;31m\");\n            break;\n        case LightCyan:\n\
    \            fprintf(stderr, \"\\033[1;36m\");\n            break;\n        case\
    \ LightGreen:\n            fprintf(stderr, \"\\033[1;32m\");\n            break;\n\
    \        case LightYellow:\n            fprintf(stderr, \"\\033[1;33m\");\n  \
    \          break;\n        case LightGray:\n        default:\n            fprintf(stderr,\
    \ \"\\033[0m\");\n        }\n    }\n#endif\n}\n\nNORETURN void halt(int exitCode)\
    \ {\n#ifdef FOOTER\n    InStream::textColor(InStream::LightGray);\n    std::fprintf(stderr,\
    \ \"Checker: \\\"%s\\\"\\n\", checkerName.c_str());\n    std::fprintf(stderr,\
    \ \"Exit code: %d\\n\", exitCode);\n    InStream::textColor(InStream::LightGray);\n\
    #endif\n    std::exit(exitCode);\n}\n\nstatic bool __testlib_shouldCheckDirt(TResult\
    \ result) {\n    return result == _ok || result == _points || result >= _partially;\n\
    }\n\nstatic std::string __testlib_appendMessage(const std::string &message, const\
    \ std::string &extra) {\n    int openPos = -1, closePos = -1;\n    for (size_t\
    \ i = 0; i < message.length(); i++) {\n        if (message[i] == InStream::OPEN_BRACKET)\
    \ {\n            if (openPos == -1)\n                openPos = i;\n          \
    \  else\n                openPos = INT_MAX;\n        }\n        if (message[i]\
    \ == InStream::CLOSE_BRACKET) {\n            if (closePos == -1)\n           \
    \     closePos = i;\n            else\n                closePos = INT_MAX;\n \
    \       }\n    }\n    if (openPos != -1 && openPos != INT_MAX\n        && closePos\
    \ != -1 && closePos != INT_MAX\n        && openPos < closePos) {\n        size_t\
    \ index = message.find(extra, openPos);\n        if (index == std::string::npos\
    \ || int(index) >= closePos) {\n            std::string result(message);\n   \
    \         result.insert(closePos, \", \" + extra);\n            return result;\n\
    \        }\n        return message;\n    }\n\n    return message + \" \" + InStream::OPEN_BRACKET\
    \ + extra + InStream::CLOSE_BRACKET;\n}\n\nstatic std::string __testlib_toPrintableMessage(const\
    \ std::string &message) {\n    int openPos = -1, closePos = -1;\n    for (size_t\
    \ i = 0; i < message.length(); i++) {\n        if (message[i] == InStream::OPEN_BRACKET)\
    \ {\n            if (openPos == -1)\n                openPos = i;\n          \
    \  else\n                openPos = INT_MAX;\n        }\n        if (message[i]\
    \ == InStream::CLOSE_BRACKET) {\n            if (closePos == -1)\n           \
    \     closePos = i;\n            else\n                closePos = INT_MAX;\n \
    \       }\n    }\n    if (openPos != -1 && openPos != INT_MAX\n        && closePos\
    \ != -1 && closePos != INT_MAX\n        && openPos < closePos) {\n        std::string\
    \ result(message);\n        result[openPos] = '(';\n        result[closePos] =\
    \ ')';\n        return result;\n    }\n\n    return message;\n}\n\nNORETURN void\
    \ InStream::quit(TResult result, const char *msg) {\n    if (TestlibFinalizeGuard::alive)\n\
    \        testlibFinalizeGuard.quitCount++;\n\n    std::string message(msg);\n\
    \    message = trim(message);\n\n    if (__testlib_hasTestCase) {\n        if\
    \ (result != _ok)\n            message = __testlib_appendMessage(message, \"test\
    \ case \" + vtos(__testlib_testCase));\n        else {\n            if (__testlib_testCase\
    \ == 1)\n                message = __testlib_appendMessage(message, vtos(__testlib_testCase)\
    \ + \" test case\");\n            else\n                message = __testlib_appendMessage(message,\
    \ vtos(__testlib_testCase) + \" test cases\");\n        }\n    }\n\n    // You\
    \ can change maxMessageLength.\n    // Example: 'inf.maxMessageLength = 1024 *\
    \ 1024;'.\n    if (message.length() > maxMessageLength) {\n        std::string\
    \ warn = \"message length exceeds \" + vtos(maxMessageLength)\n              \
    \             + \", the message is truncated: \";\n        message = warn + message.substr(0,\
    \ maxMessageLength - warn.length());\n    }\n\n#ifndef ENABLE_UNEXPECTED_EOF\n\
    \    if (result == _unexpected_eof)\n        result = _pe;\n#endif\n\n    if (mode\
    \ != _output && result != _fail) {\n        if (mode == _input && testlibMode\
    \ == _validator && lastLine != -1)\n            quits(_fail, __testlib_appendMessage(__testlib_appendMessage(message,\
    \ name), \"line \" + vtos(lastLine)));\n        else\n            quits(_fail,\
    \ __testlib_appendMessage(message, name));\n    }\n\n    std::FILE *resultFile;\n\
    \    std::string errorName;\n\n    if (__testlib_shouldCheckDirt(result)) {\n\
    \        if (testlibMode != _interactor && !ouf.seekEof())\n            quit(_dirt,\
    \ \"Extra information in the output file\");\n    }\n\n    int pctype = result\
    \ - _partially;\n    bool isPartial = false;\n\n    switch (result) {\n      \
    \  case _ok:\n            errorName = \"ok \";\n            quitscrS(LightGreen,\
    \ errorName);\n            break;\n        case _wa:\n            errorName =\
    \ \"wrong answer \";\n            quitscrS(LightRed, errorName);\n           \
    \ break;\n        case _pe:\n            errorName = \"wrong output format \"\
    ;\n            quitscrS(LightRed, errorName);\n            break;\n        case\
    \ _fail:\n            errorName = \"FAIL \";\n            quitscrS(LightRed, errorName);\n\
    \            break;\n        case _dirt:\n            errorName = \"wrong output\
    \ format \";\n            quitscrS(LightCyan, errorName);\n            result\
    \ = _pe;\n            break;\n        case _points:\n            errorName = \"\
    points \";\n            quitscrS(LightYellow, errorName);\n            break;\n\
    \        case _unexpected_eof:\n            errorName = \"unexpected eof \";\n\
    \            quitscrS(LightCyan, errorName);\n            break;\n        default:\n\
    \            if (result >= _partially) {\n                errorName = format(\"\
    partially correct (%d) \", pctype);\n                isPartial = true;\n     \
    \           quitscrS(LightYellow, errorName);\n            } else\n          \
    \      quit(_fail, \"What is the code ??? \");\n    }\n\n    if (resultName !=\
    \ \"\") {\n        resultFile = std::fopen(resultName.c_str(), \"w\");\n     \
    \   if (resultFile == NULL) {\n            resultName = \"\";\n            quit(_fail,\
    \ \"Can not write to the result file\");\n        }\n        if (appesMode) {\n\
    \            std::fprintf(resultFile, \"<?xml version=\\\"1.0\\\" encoding=\\\"\
    windows-1251\\\"?>\");\n            if (isPartial)\n                std::fprintf(resultFile,\
    \ \"<result outcome = \\\"%s\\\" pctype = \\\"%d\\\">\",\n                   \
    \          outcomes[(int) _partially].c_str(), pctype);\n            else {\n\
    \                if (result != _points)\n                    std::fprintf(resultFile,\
    \ \"<result outcome = \\\"%s\\\">\", outcomes[(int) result].c_str());\n      \
    \          else {\n                    if (__testlib_points == std::numeric_limits<float>::infinity())\n\
    \                        quit(_fail, \"Expected points, but infinity found\");\n\
    \                    std::string stringPoints = removeDoubleTrailingZeroes(format(\"\
    %.10f\", __testlib_points));\n                    std::fprintf(resultFile, \"\
    <result outcome = \\\"%s\\\" points = \\\"%s\\\">\",\n                       \
    \          outcomes[(int) result].c_str(), stringPoints.c_str());\n          \
    \      }\n            }\n            xmlSafeWrite(resultFile, __testlib_toPrintableMessage(message).c_str());\n\
    \            std::fprintf(resultFile, \"</result>\\n\");\n        } else\n   \
    \         std::fprintf(resultFile, \"%s\", __testlib_toPrintableMessage(message).c_str());\n\
    \        if (NULL == resultFile || fclose(resultFile) != 0) {\n            resultName\
    \ = \"\";\n            quit(_fail, \"Can not write to the result file\");\n  \
    \      }\n    }\n\n    quitscr(LightGray, __testlib_toPrintableMessage(message).c_str());\n\
    \    std::fprintf(stderr, \"\\n\");\n\n    inf.close();\n    ouf.close();\n  \
    \  ans.close();\n    if (tout.is_open())\n        tout.close();\n\n    textColor(LightGray);\n\
    \n    if (resultName != \"\")\n        std::fprintf(stderr, \"See file to check\
    \ exit message\\n\");\n\n    halt(resultExitCode(result));\n}\n\n#ifdef __GNUC__\n\
    __attribute__ ((format (printf, 3, 4)))\n#endif\nNORETURN void InStream::quitf(TResult\
    \ result, const char *msg, ...) {\n    FMT_TO_RESULT(msg, msg, message);\n   \
    \ InStream::quit(result, message.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nvoid InStream::quitif(bool condition, TResult\
    \ result, const char *msg, ...) {\n    if (condition) {\n        FMT_TO_RESULT(msg,\
    \ msg, message);\n        InStream::quit(result, message.c_str());\n    }\n}\n\
    \nNORETURN void InStream::quits(TResult result, std::string msg) {\n    InStream::quit(result,\
    \ msg.c_str());\n}\n\nvoid InStream::xmlSafeWrite(std::FILE *file, const char\
    \ *msg) {\n    size_t lmsg = strlen(msg);\n    for (size_t i = 0; i < lmsg; i++)\
    \ {\n        if (msg[i] == '&') {\n            std::fprintf(file, \"%s\", \"&amp;\"\
    );\n            continue;\n        }\n        if (msg[i] == '<') {\n         \
    \   std::fprintf(file, \"%s\", \"&lt;\");\n            continue;\n        }\n\
    \        if (msg[i] == '>') {\n            std::fprintf(file, \"%s\", \"&gt;\"\
    );\n            continue;\n        }\n        if (msg[i] == '\"') {\n        \
    \    std::fprintf(file, \"%s\", \"&quot;\");\n            continue;\n        }\n\
    \        if (0 <= msg[i] && msg[i] <= 31) {\n            std::fprintf(file, \"\
    %c\", '.');\n            continue;\n        }\n        std::fprintf(file, \"%c\"\
    , msg[i]);\n    }\n}\n\nvoid InStream::quitscrS(WORD color, std::string msg) {\n\
    \    quitscr(color, msg.c_str());\n}\n\nvoid InStream::quitscr(WORD color, const\
    \ char *msg) {\n    if (resultName == \"\") {\n        textColor(color);\n   \
    \     std::fprintf(stderr, \"%s\", msg);\n        textColor(LightGray);\n    }\n\
    }\n\nvoid InStream::reset(std::FILE *file) {\n    if (opened && stdfile)\n   \
    \     quit(_fail, \"Can't reset standard handle\");\n\n    if (opened)\n     \
    \   close();\n\n    if (!stdfile)\n        if (NULL == (file = std::fopen(name.c_str(),\
    \ \"rb\"))) {\n            if (mode == _output)\n                quits(_pe, std::string(\"\
    Output file not found: \\\"\") + name + \"\\\"\");\n\n            if (mode ==\
    \ _answer)\n                quits(_fail, std::string(\"Answer file not found:\
    \ \\\"\") + name + \"\\\"\");\n        }\n\n    if (NULL != file) {\n        opened\
    \ = true;\n\n        __testlib_set_binary(file);\n\n        if (stdfile)\n   \
    \         reader = new FileInputStreamReader(file, name);\n        else\n    \
    \        reader = new BufferedFileInputStreamReader(file, name);\n    } else {\n\
    \        opened = false;\n        reader = NULL;\n    }\n}\n\nvoid InStream::init(std::string\
    \ fileName, TMode mode) {\n    opened = false;\n    name = fileName;\n    stdfile\
    \ = false;\n    this->mode = mode;\n\n    std::ifstream stream;\n    stream.open(fileName.c_str(),\
    \ std::ios::in);\n    if (stream.is_open()) {\n        std::streampos start =\
    \ stream.tellg();\n        stream.seekg(0, std::ios::end);\n        std::streampos\
    \ end = stream.tellg();\n        size_t fileSize = size_t(end - start);\n    \
    \    stream.close();\n\n        // You can change maxFileSize.\n        // Example:\
    \ 'inf.maxFileSize = 256 * 1024 * 1024;'.\n        if (fileSize > maxFileSize)\n\
    \            quitf(_pe, \"File size exceeds %d bytes, size is %d\", int(maxFileSize),\
    \ int(fileSize));\n    }\n\n    reset();\n}\n\nvoid InStream::init(std::FILE *f,\
    \ TMode mode) {\n    opened = false;\n    name = \"untitled\";\n    this->mode\
    \ = mode;\n\n    if (f == stdin)\n        name = \"stdin\", stdfile = true;\n\
    \    if (f == stdout)\n        name = \"stdout\", stdfile = true;\n    if (f ==\
    \ stderr)\n        name = \"stderr\", stdfile = true;\n\n    reset(f);\n}\n\n\
    char InStream::curChar() {\n    return char(reader->curChar());\n}\n\nchar InStream::nextChar()\
    \ {\n    return char(reader->nextChar());\n}\n\nchar InStream::readChar() {\n\
    \    return nextChar();\n}\n\nchar InStream::readChar(char c) {\n    lastLine\
    \ = reader->getLine();\n    char found = readChar();\n    if (c != found) {\n\
    \        if (!isEoln(found))\n            quit(_pe, (\"Unexpected character '\"\
    \ + std::string(1, found) + \"', but '\" + std::string(1, c) +\n             \
    \          \"' expected\").c_str());\n        else\n            quit(_pe, (\"\
    Unexpected character \" + (\"#\" + vtos(int(found))) + \", but '\" + std::string(1,\
    \ c) +\n                       \"' expected\").c_str());\n    }\n    return found;\n\
    }\n\nchar InStream::readSpace() {\n    return readChar(' ');\n}\n\nvoid InStream::unreadChar(char\
    \ c) {\n    reader->unreadChar(c);\n}\n\nvoid InStream::skipChar() {\n    reader->skipChar();\n\
    }\n\nvoid InStream::skipBlanks() {\n    while (isBlanks(reader->curChar()))\n\
    \        reader->skipChar();\n}\n\nstd::string InStream::readWord() {\n    readWordTo(_tmpReadToken);\n\
    \    return _tmpReadToken;\n}\n\nvoid InStream::readWordTo(std::string &result)\
    \ {\n    if (!strict)\n        skipBlanks();\n\n    lastLine = reader->getLine();\n\
    \    int cur = reader->nextChar();\n\n    if (cur == EOFC)\n        quit(_unexpected_eof,\
    \ \"Unexpected end of file - token expected\");\n\n    if (isBlanks(cur))\n  \
    \      quit(_pe, \"Unexpected white-space - token expected\");\n\n    result.clear();\n\
    \n    while (!(isBlanks(cur) || cur == EOFC)) {\n        result += char(cur);\n\
    \n        // You can change maxTokenLength.\n        // Example: 'inf.maxTokenLength\
    \ = 128 * 1024 * 1024;'.\n        if (result.length() > maxTokenLength)\n    \
    \        quitf(_pe, \"Length of token exceeds %d, token is '%s...'\", int(maxTokenLength),\n\
    \                  __testlib_part(result).c_str());\n\n        cur = reader->nextChar();\n\
    \    }\n\n    reader->unreadChar(cur);\n\n    if (result.length() == 0)\n    \
    \    quit(_unexpected_eof, \"Unexpected end of file or white-space - token expected\"\
    );\n}\n\nstd::string InStream::readToken() {\n    return readWord();\n}\n\nvoid\
    \ InStream::readTokenTo(std::string &result) {\n    readWordTo(result);\n}\n\n\
    static std::string __testlib_part(const std::string &s) {\n    if (s.length()\
    \ <= 64)\n        return s;\n    else\n        return s.substr(0, 30) + \"...\"\
    \ + s.substr(s.length() - 31, 31);\n}\n\n#define __testlib_readMany(readMany,\
    \ readOne, typeName, space)                  \\\n    if (size < 0)           \
    \                                                    \\\n        quit(_fail, #readMany\
    \ \": size should be non-negative.\");                \\\n    if (size > 100000000)\
    \                                                       \\\n        quit(_fail,\
    \ #readMany \": size should be at most 100000000.\");           \\\n         \
    \                                                                       \\\n \
    \   std::vector<typeName> result(size);                                      \
    \   \\\n    readManyIteration = indexBase;                                   \
    \           \\\n                                                             \
    \                   \\\n    for (int i = 0; i < size; i++)                   \
    \                           \\\n    {                                        \
    \                                   \\\n        result[i] = readOne;         \
    \                                           \\\n        readManyIteration++; \
    \                                                   \\\n        if (strict &&\
    \ space && i + 1 < size)                                              \\\n   \
    \         readSpace();                                                       \
    \ \\\n    }                                                                  \
    \         \\\n                                                               \
    \                 \\\n    readManyIteration = NO_INDEX;                      \
    \                         \\\n    return result;                             \
    \                                 \\\n\n\nstd::string InStream::readWord(const\
    \ pattern &p, const std::string &variableName) {\n    readWordTo(_tmpReadToken);\n\
    \    if (!p.matches(_tmpReadToken)) {\n        if (readManyIteration == NO_INDEX)\
    \ {\n            if (variableName.empty())\n                quit(_wa,\n      \
    \               (\"Token \\\"\" + __testlib_part(_tmpReadToken) + \"\\\" doesn't\
    \ correspond to pattern \\\"\" + p.src() +\n                      \"\\\"\").c_str());\n\
    \            else\n                quit(_wa, (\"Token parameter [name=\" + variableName\
    \ + \"] equals to \\\"\" + __testlib_part(_tmpReadToken) +\n                 \
    \          \"\\\", doesn't correspond to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n\
    \        } else {\n            if (variableName.empty())\n                quit(_wa,\
    \ (\"Token element [index=\" + vtos(readManyIteration) + \"] equals to \\\"\"\
    \ +\n                           __testlib_part(_tmpReadToken) + \"\\\" doesn't\
    \ correspond to pattern \\\"\" + p.src() +\n                           \"\\\"\"\
    ).c_str());\n            else\n                quit(_wa, (\"Token element \" +\
    \ variableName + \"[\" + vtos(readManyIteration) + \"] equals to \\\"\" +\n  \
    \                         __testlib_part(_tmpReadToken) + \"\\\", doesn't correspond\
    \ to pattern \\\"\" + p.src() +\n                           \"\\\"\").c_str());\n\
    \        }\n    }\n    return _tmpReadToken;\n}\n\nstd::vector<std::string>\n\
    InStream::readWords(int size, const pattern &p, const std::string &variablesName,\
    \ int indexBase) {\n    __testlib_readMany(readWords, readWord(p, variablesName),\
    \ std::string, true);\n}\n\nstd::vector<std::string> InStream::readWords(int size,\
    \ int indexBase) {\n    __testlib_readMany(readWords, readWord(), std::string,\
    \ true);\n}\n\nstd::string InStream::readWord(const std::string &ptrn, const std::string\
    \ &variableName) {\n    return readWord(pattern(ptrn), variableName);\n}\n\nstd::vector<std::string>\n\
    InStream::readWords(int size, const std::string &ptrn, const std::string &variablesName,\
    \ int indexBase) {\n    pattern p(ptrn);\n    __testlib_readMany(readWords, readWord(p,\
    \ variablesName), std::string, true);\n}\n\nstd::string InStream::readToken(const\
    \ pattern &p, const std::string &variableName) {\n    return readWord(p, variableName);\n\
    }\n\nstd::vector<std::string>\nInStream::readTokens(int size, const pattern &p,\
    \ const std::string &variablesName, int indexBase) {\n    __testlib_readMany(readTokens,\
    \ readToken(p, variablesName), std::string, true);\n}\n\nstd::vector<std::string>\
    \ InStream::readTokens(int size, int indexBase) {\n    __testlib_readMany(readTokens,\
    \ readToken(), std::string, true);\n}\n\nstd::string InStream::readToken(const\
    \ std::string &ptrn, const std::string &variableName) {\n    return readWord(ptrn,\
    \ variableName);\n}\n\nstd::vector<std::string>\nInStream::readTokens(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \    pattern p(ptrn);\n    __testlib_readMany(readTokens, readWord(p, variablesName),\
    \ std::string, true);\n}\n\nvoid InStream::readWordTo(std::string &result, const\
    \ pattern &p, const std::string &variableName) {\n    readWordTo(result);\n  \
    \  if (!p.matches(result)) {\n        if (variableName.empty())\n            quit(_wa,\
    \ (\"Token \\\"\" + __testlib_part(result) + \"\\\" doesn't correspond to pattern\
    \ \\\"\" + p.src() +\n                       \"\\\"\").c_str());\n        else\n\
    \            quit(_wa, (\"Token parameter [name=\" + variableName + \"] equals\
    \ to \\\"\" + __testlib_part(result) +\n                       \"\\\", doesn't\
    \ correspond to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n    }\n}\n\nvoid\
    \ InStream::readWordTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName) {\n    return readWordTo(result, pattern(ptrn), variableName);\n\
    }\n\nvoid InStream::readTokenTo(std::string &result, const pattern &p, const std::string\
    \ &variableName) {\n    return readWordTo(result, p, variableName);\n}\n\nvoid\
    \ InStream::readTokenTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName) {\n    return readWordTo(result, ptrn, variableName);\n}\n\n\
    #ifdef __GNUC__\n__attribute__((pure))\n#endif\nstatic inline bool equals(long\
    \ long integer, const char *s) {\n    if (integer == LLONG_MIN)\n        return\
    \ strcmp(s, \"-9223372036854775808\") == 0;\n\n    if (integer == 0LL)\n     \
    \   return strcmp(s, \"0\") == 0;\n\n    size_t length = strlen(s);\n\n    if\
    \ (length == 0)\n        return false;\n\n    if (integer < 0 && s[0] != '-')\n\
    \        return false;\n\n    if (integer < 0)\n        s++, length--, integer\
    \ = -integer;\n\n    if (length == 0)\n        return false;\n\n    while (integer\
    \ > 0) {\n        int digit = int(integer % 10);\n\n        if (s[length - 1]\
    \ != '0' + digit)\n            return false;\n\n        length--;\n        integer\
    \ /= 10;\n    }\n\n    return length == 0;\n}\n\n#ifdef __GNUC__\n__attribute__((pure))\n\
    #endif\nstatic inline bool equals(unsigned long long integer, const char *s) {\n\
    \    if (integer == ULLONG_MAX)\n        return strcmp(s, \"18446744073709551615\"\
    ) == 0;\n\n    if (integer == 0ULL)\n        return strcmp(s, \"0\") == 0;\n\n\
    \    size_t length = strlen(s);\n\n    if (length == 0)\n        return false;\n\
    \n    while (integer > 0) {\n        int digit = int(integer % 10);\n\n      \
    \  if (s[length - 1] != '0' + digit)\n            return false;\n\n        length--;\n\
    \        integer /= 10;\n    }\n\n    return length == 0;\n}\n\nstatic inline\
    \ double stringToDouble(InStream &in, const char *buffer) {\n    double retval;\n\
    \n    size_t length = strlen(buffer);\n\n    int minusCount = 0;\n    int plusCount\
    \ = 0;\n    int decimalPointCount = 0;\n    int digitCount = 0;\n    int eCount\
    \ = 0;\n\n    for (size_t i = 0; i < length; i++) {\n        if (('0' <= buffer[i]\
    \ && buffer[i] <= '9') || buffer[i] == '.'\n            || buffer[i] == 'e' ||\
    \ buffer[i] == 'E'\n            || buffer[i] == '-' || buffer[i] == '+') {\n \
    \           if ('0' <= buffer[i] && buffer[i] <= '9')\n                digitCount++;\n\
    \            if (buffer[i] == 'e' || buffer[i] == 'E')\n                eCount++;\n\
    \            if (buffer[i] == '-')\n                minusCount++;\n          \
    \  if (buffer[i] == '+')\n                plusCount++;\n            if (buffer[i]\
    \ == '.')\n                decimalPointCount++;\n        } else\n            in.quit(_pe,\
    \ (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \    }\n\n    // If for sure is not a number in standard notation or in e-notation.\n\
    \    if (digitCount == 0 || minusCount > 2 || plusCount > 2 || decimalPointCount\
    \ > 1 || eCount > 1)\n        in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n    char *suffix = new char[length + 1];\n  \
    \  std::memset(suffix, 0, length + 1);\n    int scanned = std::sscanf(buffer,\
    \ \"%lf%s\", &retval, suffix);\n    bool empty = strlen(suffix) == 0;\n    delete[]\
    \ suffix;\n\n    if (scanned == 1 || (scanned == 2 && empty)) {\n        if (__testlib_isNaN(retval))\n\
    \            in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n        return retval;\n    } else\n        in.quit(_pe,\
    \ (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    }\n\nstatic inline double\nstringToStrictDouble(InStream &in, const char *buffer,\
    \ int minAfterPointDigitCount, int maxAfterPointDigitCount) {\n    if (minAfterPointDigitCount\
    \ < 0)\n        in.quit(_fail, \"stringToStrictDouble: minAfterPointDigitCount\
    \ should be non-negative.\");\n\n    if (minAfterPointDigitCount > maxAfterPointDigitCount)\n\
    \        in.quit(_fail,\n                \"stringToStrictDouble: minAfterPointDigitCount\
    \ should be less or equal to maxAfterPointDigitCount.\");\n\n    double retval;\n\
    \n    size_t length = strlen(buffer);\n\n    if (length == 0 || length > 1000)\n\
    \        in.quit(_pe, (\"Expected strict double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n    if (buffer[0] != '-' && (buffer[0] < '0'\
    \ || buffer[0] > '9'))\n        in.quit(_pe, (\"Expected strict double, but \\\
    \"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n    int pointPos\
    \ = -1;\n    for (size_t i = 1; i + 1 < length; i++) {\n        if (buffer[i]\
    \ == '.') {\n            if (pointPos > -1)\n                in.quit(_pe, (\"\
    Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \            pointPos = int(i);\n        }\n        if (buffer[i] != '.' && (buffer[i]\
    \ < '0' || buffer[i] > '9'))\n            in.quit(_pe, (\"Expected strict double,\
    \ but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n    }\n\n \
    \   if (buffer[length - 1] < '0' || buffer[length - 1] > '9')\n        in.quit(_pe,\
    \ (\"Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n    int afterDigitsCount = (pointPos == -1 ? 0 : int(length) -\
    \ pointPos - 1);\n    if (afterDigitsCount < minAfterPointDigitCount || afterDigitsCount\
    \ > maxAfterPointDigitCount)\n        in.quit(_pe, (\"Expected strict double with\
    \ number of digits after point in range [\"\n                      + vtos(minAfterPointDigitCount)\n\
    \                      + \",\"\n                      + vtos(maxAfterPointDigitCount)\n\
    \                      + \"], but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str()\n        );\n\n    int firstDigitPos = -1;\n    for (size_t i = 0; i\
    \ < length; i++)\n        if (buffer[i] >= '0' && buffer[i] <= '9') {\n      \
    \      firstDigitPos = int(i);\n            break;\n        }\n\n    if (firstDigitPos\
    \ > 1 || firstDigitPos == -1)\n        in.quit(_pe, (\"Expected strict double,\
    \ but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n    if (buffer[firstDigitPos]\
    \ == '0' && firstDigitPos + 1 < int(length)\n        && buffer[firstDigitPos +\
    \ 1] >= '0' && buffer[firstDigitPos + 1] <= '9')\n        in.quit(_pe, (\"Expected\
    \ strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \n    char *suffix = new char[length + 1];\n    std::memset(suffix, 0, length\
    \ + 1);\n    int scanned = std::sscanf(buffer, \"%lf%s\", &retval, suffix);\n\
    \    bool empty = strlen(suffix) == 0;\n    delete[] suffix;\n\n    if (scanned\
    \ == 1 || (scanned == 2 && empty)) {\n        if (__testlib_isNaN(retval) || __testlib_isInfinite(retval))\n\
    \            in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n        if (buffer[0] == '-' && retval >= 0)\n\
    \            in.quit(_pe, (\"Redundant minus in \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n        return retval;\n    } else\n        in.quit(_pe,\
    \ (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    }\n\nstatic inline long long stringToLongLong(InStream &in, const char *buffer)\
    \ {\n    if (strcmp(buffer, \"-9223372036854775808\") == 0)\n        return LLONG_MIN;\n\
    \n    bool minus = false;\n    size_t length = strlen(buffer);\n\n    if (length\
    \ > 1 && buffer[0] == '-')\n        minus = true;\n\n    if (length > 20)\n  \
    \      in.quit(_pe, (\"Expected integer, but \\\"\" + __testlib_part(buffer) +\
    \ \"\\\" found\").c_str());\n\n    long long retval = 0LL;\n\n    int zeroes =\
    \ 0;\n    bool processingZeroes = true;\n\n    for (int i = (minus ? 1 : 0); i\
    \ < int(length); i++) {\n        if (buffer[i] == '0' && processingZeroes)\n \
    \           zeroes++;\n        else\n            processingZeroes = false;\n\n\
    \        if (buffer[i] < '0' || buffer[i] > '9')\n            in.quit(_pe, (\"\
    Expected integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \        retval = retval * 10 + (buffer[i] - '0');\n    }\n\n    if (retval <\
    \ 0)\n        in.quit(_pe, (\"Expected integer, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n    if ((zeroes > 0 && (retval != 0 || minus))\
    \ || zeroes > 1)\n        in.quit(_pe, (\"Expected integer, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n    retval = (minus ? -retval : +retval);\n\n\
    \    if (length < 19)\n        return retval;\n\n    if (equals(retval, buffer))\n\
    \        return retval;\n    else\n        in.quit(_pe, (\"Expected int64, but\
    \ \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n}\n\nstatic inline\
    \ unsigned long long stringToUnsignedLongLong(InStream &in, const char *buffer)\
    \ {\n    size_t length = strlen(buffer);\n\n    if (length > 20)\n        in.quit(_pe,\
    \ (\"Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n    if (length > 1 && buffer[0] == '0')\n        in.quit(_pe, (\"\
    Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n    unsigned long long retval = 0LL;\n    for (int i = 0; i < int(length);\
    \ i++) {\n        if (buffer[i] < '0' || buffer[i] > '9')\n            in.quit(_pe,\
    \ (\"Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n        retval = retval * 10 + (buffer[i] - '0');\n    }\n\n    if\
    \ (length < 19)\n        return retval;\n\n    if (length == 20 && strcmp(buffer,\
    \ \"18446744073709551615\") > 0)\n        in.quit(_pe, (\"Expected unsigned int64,\
    \ but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n    if (equals(retval,\
    \ buffer))\n        return retval;\n    else\n        in.quit(_pe, (\"Expected\
    \ unsigned int64, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    }\n\nint InStream::readInteger() {\n    if (!strict && seekEof())\n        quit(_unexpected_eof,\
    \ \"Unexpected end of file - int32 expected\");\n\n    readWordTo(_tmpReadToken);\n\
    \n    long long value = stringToLongLong(*this, _tmpReadToken.c_str());\n    if\
    \ (value < INT_MIN || value > INT_MAX)\n        quit(_pe, (\"Expected int32, but\
    \ \\\"\" + __testlib_part(_tmpReadToken) + \"\\\" found\").c_str());\n\n    return\
    \ int(value);\n}\n\nlong long InStream::readLong() {\n    if (!strict && seekEof())\n\
    \        quit(_unexpected_eof, \"Unexpected end of file - int64 expected\");\n\
    \n    readWordTo(_tmpReadToken);\n\n    return stringToLongLong(*this, _tmpReadToken.c_str());\n\
    }\n\nunsigned long long InStream::readUnsignedLong() {\n    if (!strict && seekEof())\n\
    \        quit(_unexpected_eof, \"Unexpected end of file - int64 expected\");\n\
    \n    readWordTo(_tmpReadToken);\n\n    return stringToUnsignedLongLong(*this,\
    \ _tmpReadToken.c_str());\n}\n\nlong long InStream::readLong(long long minv, long\
    \ long maxv, const std::string &variableName) {\n    long long result = readLong();\n\
    \n    if (result < minv || result > maxv) {\n        if (readManyIteration ==\
    \ NO_INDEX) {\n            if (variableName.empty())\n                quit(_wa,\
    \ (\"Integer \" + vtos(result) + \" violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) +\n                           \"]\").c_str());\n\
    \            else\n                quit(_wa, (\"Integer parameter [name=\" + std::string(variableName)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        } else {\n            if (variableName.empty())\n\
    \                quit(_wa, (\"Integer element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n            else\n                quit(_wa,\n          \
    \           (\"Integer element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ + \"] equals to \" +\n                      vtos(result) + \", violates the\
    \ range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        }\n    }\n\n    if (strict && !variableName.empty())\n\
    \        validator.addBoundsHit(variableName, ValidatorBoundsHit(minv == result,\
    \ maxv == result));\n\n    return result;\n}\n\nstd::vector<long long>\nInStream::readLongs(int\
    \ size, long long minv, long long maxv, const std::string &variablesName, int\
    \ indexBase) {\n    __testlib_readMany(readLongs, readLong(minv, maxv, variablesName),\
    \ long long, true)\n}\n\nstd::vector<long long> InStream::readLongs(int size,\
    \ int indexBase) {\n    __testlib_readMany(readLongs, readLong(), long long, true)\n\
    }\n\nunsigned long long\nInStream::readUnsignedLong(unsigned long long minv, unsigned\
    \ long long maxv, const std::string &variableName) {\n    unsigned long long result\
    \ = readUnsignedLong();\n\n    if (result < minv || result > maxv) {\n       \
    \ if (readManyIteration == NO_INDEX) {\n            if (variableName.empty())\n\
    \                quit(_wa,\n                     (\"Unsigned integer \" + vtos(result)\
    \ + \" violates the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ +\n                      \"]\").c_str());\n            else\n              \
    \  quit(_wa,\n                     (\"Unsigned integer parameter [name=\" + std::string(variableName)\
    \ + \"] equals to \" + vtos(result) +\n                      \", violates the\
    \ range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        } else {\n            if (variableName.empty())\n\
    \                quit(_wa,\n                     (\"Unsigned integer element [index=\"\
    \ + vtos(readManyIteration) + \"] equals to \" + vtos(result) +\n            \
    \          \", violates the range [\" + toHumanReadableString(minv) + \", \" +\
    \ toHumanReadableString(maxv) + \"]\").c_str());\n            else\n         \
    \       quit(_wa, (\"Unsigned integer element \" + std::string(variableName) +\
    \ \"[\" + vtos(readManyIteration) +\n                           \"] equals to\
    \ \" + vtos(result) + \", violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) +\n                           \"]\").c_str());\n\
    \        }\n    }\n\n    if (strict && !variableName.empty())\n        validator.addBoundsHit(variableName,\
    \ ValidatorBoundsHit(minv == result, maxv == result));\n\n    return result;\n\
    }\n\nstd::vector<unsigned long long> InStream::readUnsignedLongs(int size, unsigned\
    \ long long minv, unsigned long long maxv,\n                                 \
    \                           const std::string &variablesName, int indexBase) {\n\
    \    __testlib_readMany(readUnsignedLongs, readUnsignedLong(minv, maxv, variablesName),\
    \ unsigned long long, true)\n}\n\nstd::vector<unsigned long long> InStream::readUnsignedLongs(int\
    \ size, int indexBase) {\n    __testlib_readMany(readUnsignedLongs, readUnsignedLong(),\
    \ unsigned long long, true)\n}\n\nunsigned long long\nInStream::readLong(unsigned\
    \ long long minv, unsigned long long maxv, const std::string &variableName) {\n\
    \    return readUnsignedLong(minv, maxv, variableName);\n}\n\nint InStream::readInt()\
    \ {\n    return readInteger();\n}\n\nint InStream::readInt(int minv, int maxv,\
    \ const std::string &variableName) {\n    int result = readInt();\n\n    if (result\
    \ < minv || result > maxv) {\n        if (readManyIteration == NO_INDEX) {\n \
    \           if (variableName.empty())\n                quit(_wa, (\"Integer \"\
    \ + vtos(result) + \" violates the range [\" + toHumanReadableString(minv) + \"\
    , \" + toHumanReadableString(maxv) +\n                           \"]\").c_str());\n\
    \            else\n                quit(_wa, (\"Integer parameter [name=\" + std::string(variableName)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        } else {\n            if (variableName.empty())\n\
    \                quit(_wa, (\"Integer element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n            else\n                quit(_wa,\n          \
    \           (\"Integer element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ + \"] equals to \" +\n                      vtos(result) + \", violates the\
    \ range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        }\n    }\n\n    if (strict && !variableName.empty())\n\
    \        validator.addBoundsHit(variableName, ValidatorBoundsHit(minv == result,\
    \ maxv == result));\n\n    return result;\n}\n\nint InStream::readInteger(int\
    \ minv, int maxv, const std::string &variableName) {\n    return readInt(minv,\
    \ maxv, variableName);\n}\n\nstd::vector<int> InStream::readInts(int size, int\
    \ minv, int maxv, const std::string &variablesName, int indexBase) {\n    __testlib_readMany(readInts,\
    \ readInt(minv, maxv, variablesName), int, true)\n}\n\nstd::vector<int> InStream::readInts(int\
    \ size, int indexBase) {\n    __testlib_readMany(readInts, readInt(), int, true)\n\
    }\n\nstd::vector<int> InStream::readIntegers(int size, int minv, int maxv, const\
    \ std::string &variablesName, int indexBase) {\n    __testlib_readMany(readIntegers,\
    \ readInt(minv, maxv, variablesName), int, true)\n}\n\nstd::vector<int> InStream::readIntegers(int\
    \ size, int indexBase) {\n    __testlib_readMany(readIntegers, readInt(), int,\
    \ true)\n}\n\ndouble InStream::readReal() {\n    if (!strict && seekEof())\n \
    \       quit(_unexpected_eof, \"Unexpected end of file - double expected\");\n\
    \n    return stringToDouble(*this, readWord().c_str());\n}\n\ndouble InStream::readDouble()\
    \ {\n    return readReal();\n}\n\ndouble InStream::readReal(double minv, double\
    \ maxv, const std::string &variableName) {\n    double result = readReal();\n\n\
    \    if (result < minv || result > maxv) {\n        if (readManyIteration == NO_INDEX)\
    \ {\n            if (variableName.empty())\n                quit(_wa, (\"Double\
    \ \" + vtos(result) + \" violates the range [\" + vtos(minv) + \", \" + vtos(maxv)\
    \ +\n                           \"]\").c_str());\n            else\n         \
    \       quit(_wa, (\"Double parameter [name=\" + std::string(variableName) + \"\
    ] equals to \" + vtos(result) +\n                           \", violates the range\
    \ [\" + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n        } else {\n\
    \            if (variableName.empty())\n                quit(_wa, (\"Double element\
    \ [index=\" + vtos(readManyIteration) + \"] equals to \" + vtos(result) +\n  \
    \                         \", violates the range [\" + vtos(minv) + \", \" + vtos(maxv)\
    \ + \"]\").c_str());\n            else\n                quit(_wa,\n          \
    \           (\"Double element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ + \"] equals to \" +\n                      vtos(result) + \", violates the\
    \ range [\" + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n        }\n\
    \    }\n\n    if (strict && !variableName.empty())\n        validator.addBoundsHit(variableName,\
    \ ValidatorBoundsHit(\n                doubleDelta(minv, result) < ValidatorBoundsHit::EPS,\n\
    \                doubleDelta(maxv, result) < ValidatorBoundsHit::EPS\n       \
    \ ));\n\n    return result;\n}\n\nstd::vector<double>\nInStream::readReals(int\
    \ size, double minv, double maxv, const std::string &variablesName, int indexBase)\
    \ {\n    __testlib_readMany(readReals, readReal(minv, maxv, variablesName), double,\
    \ true)\n}\n\nstd::vector<double> InStream::readReals(int size, int indexBase)\
    \ {\n    __testlib_readMany(readReals, readReal(), double, true)\n}\n\ndouble\
    \ InStream::readDouble(double minv, double maxv, const std::string &variableName)\
    \ {\n    return readReal(minv, maxv, variableName);\n}\n\nstd::vector<double>\n\
    InStream::readDoubles(int size, double minv, double maxv, const std::string &variablesName,\
    \ int indexBase) {\n    __testlib_readMany(readDoubles, readDouble(minv, maxv,\
    \ variablesName), double, true)\n}\n\nstd::vector<double> InStream::readDoubles(int\
    \ size, int indexBase) {\n    __testlib_readMany(readDoubles, readDouble(), double,\
    \ true)\n}\n\ndouble InStream::readStrictReal(double minv, double maxv,\n    \
    \                            int minAfterPointDigitCount, int maxAfterPointDigitCount,\n\
    \                                const std::string &variableName) {\n    if (!strict\
    \ && seekEof())\n        quit(_unexpected_eof, \"Unexpected end of file - strict\
    \ double expected\");\n\n    double result = stringToStrictDouble(*this, readWord().c_str(),\n\
    \                                         minAfterPointDigitCount, maxAfterPointDigitCount);\n\
    \n    if (result < minv || result > maxv) {\n        if (readManyIteration ==\
    \ NO_INDEX) {\n            if (variableName.empty())\n                quit(_wa,\
    \ (\"Strict double \" + vtos(result) + \" violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) +\n                           \"]\").c_str());\n     \
    \       else\n                quit(_wa,\n                     (\"Strict double\
    \ parameter [name=\" + std::string(variableName) + \"] equals to \" + vtos(result)\
    \ +\n                      \", violates the range [\" + vtos(minv) + \", \" +\
    \ vtos(maxv) + \"]\").c_str());\n        } else {\n            if (variableName.empty())\n\
    \                quit(_wa, (\"Strict double element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n      \
    \      else\n                quit(_wa, (\"Strict double element \" + std::string(variableName)\
    \ + \"[\" + vtos(readManyIteration) +\n                           \"] equals to\
    \ \" + vtos(result) + \", violates the range [\" + vtos(minv) + \", \" + vtos(maxv)\
    \ +\n                           \"]\").c_str());\n        }\n    }\n\n    if (strict\
    \ && !variableName.empty())\n        validator.addBoundsHit(variableName, ValidatorBoundsHit(\n\
    \                doubleDelta(minv, result) < ValidatorBoundsHit::EPS,\n      \
    \          doubleDelta(maxv, result) < ValidatorBoundsHit::EPS\n        ));\n\n\
    \    return result;\n}\n\nstd::vector<double> InStream::readStrictReals(int size,\
    \ double minv, double maxv,\n                                              int\
    \ minAfterPointDigitCount, int maxAfterPointDigitCount,\n                    \
    \                          const std::string &variablesName, int indexBase) {\n\
    \    __testlib_readMany(readStrictReals,\n                       readStrictReal(minv,\
    \ maxv, minAfterPointDigitCount, maxAfterPointDigitCount, variablesName),\n  \
    \                     double, true)\n}\n\ndouble InStream::readStrictDouble(double\
    \ minv, double maxv,\n                                  int minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n                                  const std::string\
    \ &variableName) {\n    return readStrictReal(minv, maxv,\n                  \
    \        minAfterPointDigitCount, maxAfterPointDigitCount,\n                 \
    \         variableName);\n}\n\nstd::vector<double> InStream::readStrictDoubles(int\
    \ size, double minv, double maxv,\n                                          \
    \      int minAfterPointDigitCount, int maxAfterPointDigitCount,\n           \
    \                                     const std::string &variablesName, int indexBase)\
    \ {\n    __testlib_readMany(readStrictDoubles,\n                       readStrictDouble(minv,\
    \ maxv, minAfterPointDigitCount, maxAfterPointDigitCount, variablesName),\n  \
    \                     double, true)\n}\n\nbool InStream::eof() {\n    if (!strict\
    \ && NULL == reader)\n        return true;\n\n    return reader->eof();\n}\n\n\
    bool InStream::seekEof() {\n    if (!strict && NULL == reader)\n        return\
    \ true;\n    skipBlanks();\n    return eof();\n}\n\nbool InStream::eoln() {\n\
    \    if (!strict && NULL == reader)\n        return true;\n\n    int c = reader->nextChar();\n\
    \n    if (!strict) {\n        if (c == EOFC)\n            return true;\n\n   \
    \     if (c == CR) {\n            c = reader->nextChar();\n\n            if (c\
    \ != LF) {\n                reader->unreadChar(c);\n                reader->unreadChar(CR);\n\
    \                return false;\n            } else\n                return true;\n\
    \        }\n\n        if (c == LF)\n            return true;\n\n        reader->unreadChar(c);\n\
    \        return false;\n    } else {\n        bool returnCr = false;\n\n#if (defined(ON_WINDOWS)\
    \ && !defined(FOR_LINUX)) || defined(FOR_WINDOWS)\n        if (c != CR) {\n  \
    \          reader->unreadChar(c);\n            return false;\n        } else {\n\
    \            if (!returnCr)\n                returnCr = true;\n            c =\
    \ reader->nextChar();\n        }\n#endif\n        if (c != LF) {\n           \
    \ reader->unreadChar(c);\n            if (returnCr)\n                reader->unreadChar(CR);\n\
    \            return false;\n        }\n\n        return true;\n    }\n}\n\nvoid\
    \ InStream::readEoln() {\n    lastLine = reader->getLine();\n    if (!eoln())\n\
    \        quit(_pe, \"Expected EOLN\");\n}\n\nvoid InStream::readEof() {\n    lastLine\
    \ = reader->getLine();\n    if (!eof())\n        quit(_pe, \"Expected EOF\");\n\
    \n    if (TestlibFinalizeGuard::alive && this == &inf)\n        testlibFinalizeGuard.readEofCount++;\n\
    }\n\nbool InStream::seekEoln() {\n    if (!strict && NULL == reader)\n       \
    \ return true;\n\n    int cur;\n    do {\n        cur = reader->nextChar();\n\
    \    } while (cur == SPACE || cur == TAB);\n\n    reader->unreadChar(cur);\n \
    \   return eoln();\n}\n\nvoid InStream::nextLine() {\n    readLine();\n}\n\nvoid\
    \ InStream::readStringTo(std::string &result) {\n    if (NULL == reader)\n   \
    \     quit(_pe, \"Expected line\");\n\n    result.clear();\n\n    for (;;) {\n\
    \        int cur = reader->curChar();\n\n        if (cur == LF || cur == EOFC)\n\
    \            break;\n\n        if (cur == CR) {\n            cur = reader->nextChar();\n\
    \            if (reader->curChar() == LF) {\n                reader->unreadChar(cur);\n\
    \                break;\n            }\n        }\n\n        lastLine = reader->getLine();\n\
    \        result += char(reader->nextChar());\n    }\n\n    if (strict)\n     \
    \   readEoln();\n    else\n        eoln();\n}\n\nstd::string InStream::readString()\
    \ {\n    readStringTo(_tmpReadToken);\n    return _tmpReadToken;\n}\n\nstd::vector<std::string>\
    \ InStream::readStrings(int size, int indexBase) {\n    __testlib_readMany(readStrings,\
    \ readString(), std::string, false)\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result, const pattern &p, const std::string &variableName) {\n    readStringTo(result);\n\
    \    if (!p.matches(result)) {\n        if (readManyIteration == NO_INDEX) {\n\
    \            if (variableName.empty())\n                quit(_wa, (\"Line \\\"\
    \" + __testlib_part(result) + \"\\\" doesn't correspond to pattern \\\"\" + p.src()\
    \ +\n                           \"\\\"\").c_str());\n            else\n      \
    \          quit(_wa, (\"Line [name=\" + variableName + \"] equals to \\\"\" +\
    \ __testlib_part(result) +\n                           \"\\\", doesn't correspond\
    \ to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n        } else {\n      \
    \      if (variableName.empty())\n                quit(_wa,\n                \
    \     (\"Line element [index=\" + vtos(readManyIteration) + \"] equals to \\\"\
    \" + __testlib_part(result) +\n                      \"\\\" doesn't correspond\
    \ to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n            else\n      \
    \          quit(_wa,\n                     (\"Line element \" + std::string(variableName)\
    \ + \"[\" + vtos(readManyIteration) + \"] equals to \\\"\" +\n               \
    \       __testlib_part(result) + \"\\\", doesn't correspond to pattern \\\"\"\
    \ + p.src() + \"\\\"\").c_str());\n        }\n    }\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName) {\n    readStringTo(result,\
    \ pattern(ptrn), variableName);\n}\n\nstd::string InStream::readString(const pattern\
    \ &p, const std::string &variableName) {\n    readStringTo(_tmpReadToken, p, variableName);\n\
    \    return _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readStrings(int\
    \ size, const pattern &p, const std::string &variablesName, int indexBase) {\n\
    \    __testlib_readMany(readStrings, readString(p, variablesName), std::string,\
    \ false)\n}\n\nstd::string InStream::readString(const std::string &ptrn, const\
    \ std::string &variableName) {\n    readStringTo(_tmpReadToken, ptrn, variableName);\n\
    \    return _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readStrings(int\
    \ size, const std::string &ptrn, const std::string &variablesName, int indexBase)\
    \ {\n    pattern p(ptrn);\n    __testlib_readMany(readStrings, readString(p, variablesName),\
    \ std::string, false)\n}\n\nvoid InStream::readLineTo(std::string &result) {\n\
    \    readStringTo(result);\n}\n\nstd::string InStream::readLine() {\n    return\
    \ readString();\n}\n\nstd::vector<std::string> InStream::readLines(int size, int\
    \ indexBase) {\n    __testlib_readMany(readLines, readString(), std::string, false)\n\
    }\n\nvoid InStream::readLineTo(std::string &result, const pattern &p, const std::string\
    \ &variableName) {\n    readStringTo(result, p, variableName);\n}\n\nvoid InStream::readLineTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName) {\n    readStringTo(result,\
    \ ptrn, variableName);\n}\n\nstd::string InStream::readLine(const pattern &p,\
    \ const std::string &variableName) {\n    return readString(p, variableName);\n\
    }\n\nstd::vector<std::string>\nInStream::readLines(int size, const pattern &p,\
    \ const std::string &variablesName, int indexBase) {\n    __testlib_readMany(readLines,\
    \ readString(p, variablesName), std::string, false)\n}\n\nstd::string InStream::readLine(const\
    \ std::string &ptrn, const std::string &variableName) {\n    return readString(ptrn,\
    \ variableName);\n}\n\nstd::vector<std::string>\nInStream::readLines(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \    pattern p(ptrn);\n    __testlib_readMany(readLines, readString(p, variablesName),\
    \ std::string, false)\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 3,\
    \ 4)))\n#endif\nvoid InStream::ensuref(bool cond, const char *format, ...) {\n\
    \    if (!cond) {\n        FMT_TO_RESULT(format, format, message);\n        this->__testlib_ensure(cond,\
    \ message);\n    }\n}\n\nvoid InStream::__testlib_ensure(bool cond, std::string\
    \ message) {\n    if (!cond)\n        this->quit(_wa, message.c_str());\n}\n\n\
    void InStream::close() {\n    if (NULL != reader) {\n        reader->close();\n\
    \        delete reader;\n        reader = NULL;\n    }\n\n    opened = false;\n\
    }\n\nNORETURN void quit(TResult result, const std::string &msg) {\n    ouf.quit(result,\
    \ msg.c_str());\n}\n\nNORETURN void quit(TResult result, const char *msg) {\n\
    \    ouf.quit(result, msg);\n}\n\nNORETURN void __testlib_quitp(double points,\
    \ const char *message) {\n    __testlib_points = points;\n    std::string stringPoints\
    \ = removeDoubleTrailingZeroes(format(\"%.10f\", points));\n\n    std::string\
    \ quitMessage;\n    if (NULL == message || 0 == strlen(message))\n        quitMessage\
    \ = stringPoints;\n    else\n        quitMessage = stringPoints + \" \" + message;\n\
    \n    quit(_points, quitMessage.c_str());\n}\n\nNORETURN void __testlib_quitp(int\
    \ points, const char *message) {\n    __testlib_points = points;\n    std::string\
    \ stringPoints = format(\"%d\", points);\n\n    std::string quitMessage;\n   \
    \ if (NULL == message || 0 == strlen(message))\n        quitMessage = stringPoints;\n\
    \    else\n        quitMessage = stringPoints + \" \" + message;\n\n    quit(_points,\
    \ quitMessage.c_str());\n}\n\nNORETURN void quitp(float points, const std::string\
    \ &message = \"\") {\n    __testlib_quitp(double(points), message.c_str());\n\
    }\n\nNORETURN void quitp(double points, const std::string &message = \"\") {\n\
    \    __testlib_quitp(points, message.c_str());\n}\n\nNORETURN void quitp(long\
    \ double points, const std::string &message = \"\") {\n    __testlib_quitp(double(points),\
    \ message.c_str());\n}\n\nNORETURN void quitp(int points, const std::string &message\
    \ = \"\") {\n    __testlib_quitp(points, message.c_str());\n}\n\ntemplate<typename\
    \ F>\n#ifdef __GNUC__\n__attribute__ ((format (printf, 2, 3)))\n#endif\nNORETURN\
    \ void quitp(F points, const char *format, ...) {\n    FMT_TO_RESULT(format, format,\
    \ message);\n    quitp(points, message);\n}\n\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 2, 3)))\n#endif\nNORETURN void quitf(TResult result, const\
    \ char *format, ...) {\n    FMT_TO_RESULT(format, format, message);\n    quit(result,\
    \ message);\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 3, 4)))\n#endif\n\
    void quitif(bool condition, TResult result, const char *format, ...) {\n    if\
    \ (condition) {\n        FMT_TO_RESULT(format, format, message);\n        quit(result,\
    \ message);\n    }\n}\n\nNORETURN void __testlib_help() {\n    InStream::textColor(InStream::LightCyan);\n\
    \    std::fprintf(stderr, \"TESTLIB %s, https://github.com/MikeMirzayanov/testlib/\
    \ \", VERSION);\n    std::fprintf(stderr, \"by Mike Mirzayanov, copyright(c) 2005-2020\\\
    n\");\n    std::fprintf(stderr, \"Checker name: \\\"%s\\\"\\n\", checkerName.c_str());\n\
    \    InStream::textColor(InStream::LightGray);\n\n    std::fprintf(stderr, \"\\\
    n\");\n    std::fprintf(stderr, \"Latest features: \\n\");\n    for (size_t i\
    \ = 0; i < sizeof(latestFeatures) / sizeof(char *); i++) {\n        std::fprintf(stderr,\
    \ \"*) %s\\n\", latestFeatures[i]);\n    }\n    std::fprintf(stderr, \"\\n\");\n\
    \n    std::fprintf(stderr, \"Program must be run with the following arguments:\
    \ \\n\");\n    std::fprintf(stderr, \"    <input-file> <output-file> <answer-file>\
    \ [<report-file> [<-appes>]]\\n\\n\");\n\n    std::exit(FAIL_EXIT_CODE);\n}\n\n\
    static void __testlib_ensuresPreconditions() {\n    // testlib assumes: sizeof(int)\
    \ = 4.\n    __TESTLIB_STATIC_ASSERT(sizeof(int) == 4);\n\n    // testlib assumes:\
    \ INT_MAX == 2147483647.\n    __TESTLIB_STATIC_ASSERT(INT_MAX == 2147483647);\n\
    \n    // testlib assumes: sizeof(long long) = 8.\n    __TESTLIB_STATIC_ASSERT(sizeof(long\
    \ long) == 8);\n\n    // testlib assumes: sizeof(double) = 8.\n    __TESTLIB_STATIC_ASSERT(sizeof(double)\
    \ == 8);\n\n    // testlib assumes: no -ffast-math.\n    if (!__testlib_isNaN(+__testlib_nan()))\n\
    \        quit(_fail, \"Function __testlib_isNaN is not working correctly: possible\
    \ reason is '-ffast-math'\");\n    if (!__testlib_isNaN(-__testlib_nan()))\n \
    \       quit(_fail, \"Function __testlib_isNaN is not working correctly: possible\
    \ reason is '-ffast-math'\");\n}\n\nvoid registerGen(int argc, char *argv[], int\
    \ randomGeneratorVersion) {\n    if (randomGeneratorVersion < 0 || randomGeneratorVersion\
    \ > 1)\n        quitf(_fail, \"Random generator version is expected to be 0 or\
    \ 1.\");\n    random_t::version = randomGeneratorVersion;\n\n    __testlib_ensuresPreconditions();\n\
    \n    testlibMode = _generator;\n    __testlib_set_binary(stdin);\n    rnd.setSeed(argc,\
    \ argv);\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\n    prepareOpts(argc,\
    \ argv);\n#endif\n}\n\n#ifdef USE_RND_AS_BEFORE_087\nvoid registerGen(int argc,\
    \ char* argv[])\n{\n    registerGen(argc, argv, 0);\n}\n#else\n#ifdef __GNUC__\n\
    #if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 4))\n__attribute__\
    \ ((deprecated(\"Use registerGen(argc, argv, 0) or registerGen(argc, argv, 1).\"\
    \n\" The third parameter stands for the random generator version.\"\n\" If you\
    \ are trying to compile old generator use macro -DUSE_RND_AS_BEFORE_087 or registerGen(argc,\
    \ argv, 0).\"\n\" Version 1 has been released on Spring, 2013. Use it to write\
    \ new generators.\")))\n#else\n__attribute__ ((deprecated))\n#endif\n#endif\n\
    #ifdef _MSC_VER\n__declspec(deprecated(\"Use registerGen(argc, argv, 0) or registerGen(argc,\
    \ argv, 1).\"\n        \" The third parameter stands for the random generator\
    \ version.\"\n        \" If you are trying to compile old generator use macro\
    \ -DUSE_RND_AS_BEFORE_087 or registerGen(argc, argv, 0).\"\n        \" Version\
    \ 1 has been released on Spring, 2013. Use it to write new generators.\"))\n#endif\n\
    void registerGen(int argc, char *argv[]) {\n    std::fprintf(stderr, \"Use registerGen(argc,\
    \ argv, 0) or registerGen(argc, argv, 1).\"\n                         \" The third\
    \ parameter stands for the random generator version.\"\n                     \
    \    \" If you are trying to compile old generator use macro -DUSE_RND_AS_BEFORE_087\
    \ or registerGen(argc, argv, 0).\"\n                         \" Version 1 has\
    \ been released on Spring, 2013. Use it to write new generators.\\n\\n\");\n \
    \   registerGen(argc, argv, 0);\n}\n#endif\n\nvoid registerInteraction(int argc,\
    \ char *argv[]) {\n    __testlib_ensuresPreconditions();\n\n    testlibMode =\
    \ _interactor;\n    __testlib_set_binary(stdin);\n\n    if (argc > 1 && !strcmp(\"\
    --help\", argv[1]))\n        __testlib_help();\n\n    if (argc < 3 || argc > 6)\
    \ {\n        quit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n                    std::string(\"<input-file> <output-file>\
    \ [<answer-file> [<report-file> [<-appes>]]]\") +\n                    \"\\nUse\
    \ \\\"--help\\\" to get help information\");\n    }\n\n    if (argc <= 4) {\n\
    \        resultName = \"\";\n        appesMode = false;\n    }\n\n#ifndef EJUDGE\n\
    \    if (argc == 5) {\n        resultName = argv[4];\n        appesMode = false;\n\
    \    }\n\n    if (argc == 6) {\n        if (strcmp(\"-APPES\", argv[5]) && strcmp(\"\
    -appes\", argv[5])) {\n            quit(_fail, std::string(\"Program must be run\
    \ with the following arguments: \") +\n                        \"<input-file>\
    \ <output-file> <answer-file> [<report-file> [<-appes>]]\");\n        } else {\n\
    \            resultName = argv[4];\n            appesMode = true;\n        }\n\
    \    }\n#endif\n\n    inf.init(argv[1], _input);\n\n    tout.open(argv[2], std::ios_base::out);\n\
    \    if (tout.fail() || !tout.is_open())\n        quit(_fail, std::string(\"Can\
    \ not write to the test-output-file '\") + argv[2] + std::string(\"'\"));\n\n\
    \    ouf.init(stdin, _output);\n\n    if (argc >= 4)\n        ans.init(argv[3],\
    \ _answer);\n    else\n        ans.name = \"unopened answer stream\";\n}\n\nvoid\
    \ registerValidation() {\n    __testlib_ensuresPreconditions();\n\n    testlibMode\
    \ = _validator;\n    __testlib_set_binary(stdin);\n\n    inf.init(stdin, _input);\n\
    \    inf.strict = true;\n}\n\nvoid registerValidation(int argc, char *argv[])\
    \ {\n    registerValidation();\n    validator.initialize();\n\n    for (int i\
    \ = 1; i < argc; i++) {\n        if (!strcmp(\"--testset\", argv[i])) {\n    \
    \        if (i + 1 < argc && strlen(argv[i + 1]) > 0)\n                validator.setTestset(argv[++i]);\n\
    \            else\n                quit(_fail, std::string(\"Validator must be\
    \ run with the following arguments: \") +\n                            \"[--testset\
    \ testset] [--group group] [--testOverviewLogFileName fileName]\");\n        }\n\
    \        if (!strcmp(\"--group\", argv[i])) {\n            if (i + 1 < argc)\n\
    \                validator.setGroup(argv[++i]);\n            else\n          \
    \      quit(_fail, std::string(\"Validator must be run with the following arguments:\
    \ \") +\n                            \"[--testset testset] [--group group] [--testOverviewLogFileName\
    \ fileName]\");\n        }\n        if (!strcmp(\"--testOverviewLogFileName\"\
    , argv[i])) {\n            if (i + 1 < argc)\n                validator.setTestOverviewLogFileName(argv[++i]);\n\
    \            else\n                quit(_fail, std::string(\"Validator must be\
    \ run with the following arguments: \") +\n                            \"[--testset\
    \ testset] [--group group] [--testOverviewLogFileName fileName]\");\n        }\n\
    \    }\n}\n\nvoid addFeature(const std::string &feature) {\n    if (testlibMode\
    \ != _validator)\n        quit(_fail, \"Features are supported in validators only.\"\
    );\n    validator.addFeature(feature);\n}\n\nvoid feature(const std::string &feature)\
    \ {\n    if (testlibMode != _validator)\n        quit(_fail, \"Features are supported\
    \ in validators only.\");\n    validator.feature(feature);\n}\n\nvoid registerTestlibCmd(int\
    \ argc, char *argv[]) {\n    __testlib_ensuresPreconditions();\n\n    testlibMode\
    \ = _checker;\n    __testlib_set_binary(stdin);\n\n    if (argc > 1 && !strcmp(\"\
    --help\", argv[1]))\n        __testlib_help();\n\n    if (argc < 4 || argc > 6)\
    \ {\n        quit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n                    std::string(\"<input-file> <output-file>\
    \ <answer-file> [<report-file> [<-appes>]]\") +\n                    \"\\nUse\
    \ \\\"--help\\\" to get help information\");\n    }\n\n    if (argc == 4) {\n\
    \        resultName = \"\";\n        appesMode = false;\n    }\n\n    if (argc\
    \ == 5) {\n        resultName = argv[4];\n        appesMode = false;\n    }\n\n\
    \    if (argc == 6) {\n        if (strcmp(\"-APPES\", argv[5]) && strcmp(\"-appes\"\
    , argv[5])) {\n            quit(_fail, std::string(\"Program must be run with\
    \ the following arguments: \") +\n                        \"<input-file> <output-file>\
    \ <answer-file> [<report-file> [<-appes>]]\");\n        } else {\n           \
    \ resultName = argv[4];\n            appesMode = true;\n        }\n    }\n\n \
    \   inf.init(argv[1], _input);\n    ouf.init(argv[2], _output);\n    ans.init(argv[3],\
    \ _answer);\n}\n\nvoid registerTestlib(int argc, ...) {\n    if (argc < 3 || argc\
    \ > 5)\n        quit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n                    \"<input-file> <output-file> <answer-file>\
    \ [<report-file> [<-appes>]]\");\n\n    char **argv = new char *[argc + 1];\n\n\
    \    va_list ap;\n    va_start(ap, argc);\n    argv[0] = NULL;\n    for (int i\
    \ = 0; i < argc; i++) {\n        argv[i + 1] = va_arg(ap, char*);\n    }\n   \
    \ va_end(ap);\n\n    registerTestlibCmd(argc + 1, argv);\n    delete[] argv;\n\
    }\n\nstatic inline void __testlib_ensure(bool cond, const std::string &msg) {\n\
    \    if (!cond)\n        quit(_fail, msg.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__((unused))\n\
    #endif\nstatic inline void __testlib_ensure(bool cond, const char *msg) {\n  \
    \  if (!cond)\n        quit(_fail, msg);\n}\n\n#define ensure(cond) __testlib_ensure(cond,\
    \ \"Condition failed: \\\"\" #cond \"\\\"\")\n#define STRINGIZE_DETAIL(x) #x\n\
    #define STRINGIZE(x) STRINGIZE_DETAIL(x)\n#define ensure_ext(cond) __testlib_ensure(cond,\
    \ \"Line \" STRINGIZE(__LINE__) \": Condition failed: \\\"\" #cond \"\\\"\")\n\
    \n#ifdef __GNUC__\n__attribute__ ((format (printf, 2, 3)))\n#endif\ninline void\
    \ ensuref(bool cond, const char *format, ...) {\n    if (!cond) {\n        FMT_TO_RESULT(format,\
    \ format, message);\n        __testlib_ensure(cond, message);\n    }\n}\n\nNORETURN\
    \ static void __testlib_fail(const std::string &message) {\n    quitf(_fail, \"\
    %s\", message.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf,\
    \ 1, 2)))\n#endif\nvoid setName(const char *format, ...) {\n    FMT_TO_RESULT(format,\
    \ format, name);\n    checkerName = name;\n}\n\n/* \n * Do not use random_shuffle,\
    \ because it will produce different result\n * for different C++ compilers.\n\
    \ *\n * This implementation uses testlib random_t to produce random numbers, so\n\
    \ * it is stable.\n */\ntemplate<typename _RandomAccessIter>\nvoid shuffle(_RandomAccessIter\
    \ __first, _RandomAccessIter __last) {\n    if (__first == __last) return;\n \
    \   for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)\n        std::iter_swap(__i,\
    \ __first + rnd.next(int(__i - __first) + 1));\n}\n\n\ntemplate<typename _RandomAccessIter>\n\
    #if defined(__GNUC__) && !defined(__clang__)\n__attribute__ ((error(\"Don't use\
    \ random_shuffle(), use shuffle() instead\")))\n#endif\nvoid random_shuffle(_RandomAccessIter,\
    \ _RandomAccessIter) {\n    quitf(_fail, \"Don't use random_shuffle(), use shuffle()\
    \ instead\");\n}\n\n#ifdef __GLIBC__\n#  define RAND_THROW_STATEMENT throw()\n\
    #else\n#  define RAND_THROW_STATEMENT\n#endif\n\n#if defined(__GNUC__) && !defined(__clang__)\n\
    \n__attribute__ ((error(\"Don't use rand(), use rnd.next() instead\")))\n#endif\n\
    #ifdef _MSC_VER\n#   pragma warning( disable : 4273 )\n#endif\nint rand() RAND_THROW_STATEMENT\n\
    {\n    quitf(_fail, \"Don't use rand(), use rnd.next() instead\");\n\n    /* This\
    \ line never runs. */\n    //throw \"Don't use rand(), use rnd.next() instead\"\
    ;\n}\n\n#if defined(__GNUC__) && !defined(__clang__)\n\n__attribute__ ((error(\"\
    Don't use srand(), you should use \"\n\"'registerGen(argc, argv, 1);' to initialize\
    \ generator seed \"\n\"by hash code of the command line params. The third parameter\
    \ \"\n\"is randomGeneratorVersion (currently the latest is 1).\")))\n#endif\n\
    #ifdef _MSC_VER\n#   pragma warning( disable : 4273 )\n#endif\nvoid srand(unsigned\
    \ int seed) RAND_THROW_STATEMENT\n{\n    quitf(_fail, \"Don't use srand(), you\
    \ should use \"\n                 \"'registerGen(argc, argv, 1);' to initialize\
    \ generator seed \"\n                 \"by hash code of the command line params.\
    \ The third parameter \"\n                 \"is randomGeneratorVersion (currently\
    \ the latest is 1) [ignored seed=%u].\", seed);\n}\n\nvoid startTest(int test)\
    \ {\n    const std::string testFileName = vtos(test);\n    if (NULL == freopen(testFileName.c_str(),\
    \ \"wt\", stdout))\n        __testlib_fail(\"Unable to write file '\" + testFileName\
    \ + \"'\");\n}\n\ninline std::string upperCase(std::string s) {\n    for (size_t\
    \ i = 0; i < s.length(); i++)\n        if ('a' <= s[i] && s[i] <= 'z')\n     \
    \       s[i] = char(s[i] - 'a' + 'A');\n    return s;\n}\n\ninline std::string\
    \ lowerCase(std::string s) {\n    for (size_t i = 0; i < s.length(); i++)\n  \
    \      if ('A' <= s[i] && s[i] <= 'Z')\n            s[i] = char(s[i] - 'A' + 'a');\n\
    \    return s;\n}\n\ninline std::string compress(const std::string &s) {\n   \
    \ return __testlib_part(s);\n}\n\ninline std::string englishEnding(int x) {\n\
    \    x %= 100;\n    if (x / 10 == 1)\n        return \"th\";\n    if (x % 10 ==\
    \ 1)\n        return \"st\";\n    if (x % 10 == 2)\n        return \"nd\";\n \
    \   if (x % 10 == 3)\n        return \"rd\";\n    return \"th\";\n}\n\ntemplate<typename\
    \ _ForwardIterator, typename _Separator>\nstd::string join(_ForwardIterator first,\
    \ _ForwardIterator last, _Separator separator) {\n    std::stringstream ss;\n\
    \    bool repeated = false;\n    for (_ForwardIterator i = first; i != last; i++)\
    \ {\n        if (repeated)\n            ss << separator;\n        else\n     \
    \       repeated = true;\n        ss << *i;\n    }\n    return ss.str();\n}\n\n\
    template<typename _ForwardIterator>\nstd::string join(_ForwardIterator first,\
    \ _ForwardIterator last) {\n    return join(first, last, ' ');\n}\n\ntemplate<typename\
    \ _Collection, typename _Separator>\nstd::string join(const _Collection &collection,\
    \ _Separator separator) {\n    return join(collection.begin(), collection.end(),\
    \ separator);\n}\n\ntemplate<typename _Collection>\nstd::string join(const _Collection\
    \ &collection) {\n    return join(collection, ' ');\n}\n\n/**\n * Splits string\
    \ s by character separator returning exactly k+1 items,\n * where k is the number\
    \ of separator occurences.\n */\nstd::vector<std::string> split(const std::string\
    \ &s, char separator) {\n    std::vector<std::string> result;\n    std::string\
    \ item;\n    for (size_t i = 0; i < s.length(); i++)\n        if (s[i] == separator)\
    \ {\n            result.push_back(item);\n            item = \"\";\n        }\
    \ else\n            item += s[i];\n    result.push_back(item);\n    return result;\n\
    }\n\n/**\n * Splits string s by character separators returning exactly k+1 items,\n\
    \ * where k is the number of separator occurences.\n */\nstd::vector<std::string>\
    \ split(const std::string &s, const std::string &separators) {\n    if (separators.empty())\n\
    \        return std::vector<std::string>(1, s);\n\n    std::vector<bool> isSeparator(256);\n\
    \    for (size_t i = 0; i < separators.size(); i++)\n        isSeparator[(unsigned\
    \ char) (separators[i])] = true;\n\n    std::vector<std::string> result;\n   \
    \ std::string item;\n    for (size_t i = 0; i < s.length(); i++)\n        if (isSeparator[(unsigned\
    \ char) (s[i])]) {\n            result.push_back(item);\n            item = \"\
    \";\n        } else\n            item += s[i];\n    result.push_back(item);\n\
    \    return result;\n}\n\n/**\n * Splits string s by character separator returning\
    \ non-empty items.\n */\nstd::vector<std::string> tokenize(const std::string &s,\
    \ char separator) {\n    std::vector<std::string> result;\n    std::string item;\n\
    \    for (size_t i = 0; i < s.length(); i++)\n        if (s[i] == separator) {\n\
    \            if (!item.empty())\n                result.push_back(item);\n   \
    \         item = \"\";\n        } else\n            item += s[i];\n    if (!item.empty())\n\
    \        result.push_back(item);\n    return result;\n}\n\n/**\n * Splits string\
    \ s by character separators returning non-empty items.\n */\nstd::vector<std::string>\
    \ tokenize(const std::string &s, const std::string &separators) {\n    if (separators.empty())\n\
    \        return std::vector<std::string>(1, s);\n\n    std::vector<bool> isSeparator(256);\n\
    \    for (size_t i = 0; i < separators.size(); i++)\n        isSeparator[(unsigned\
    \ char) (separators[i])] = true;\n\n    std::vector<std::string> result;\n   \
    \ std::string item;\n    for (size_t i = 0; i < s.length(); i++)\n        if (isSeparator[(unsigned\
    \ char) (s[i])]) {\n            if (!item.empty())\n                result.push_back(item);\n\
    \            item = \"\";\n        } else\n            item += s[i];\n\n    if\
    \ (!item.empty())\n        result.push_back(item);\n\n    return result;\n}\n\n\
    NORETURN void __testlib_expectedButFound(TResult result, std::string expected,\
    \ std::string found, const char *prepend) {\n    std::string message;\n    if\
    \ (strlen(prepend) != 0)\n        message = format(\"%s: expected '%s', but found\
    \ '%s'\",\n                         compress(prepend).c_str(), compress(expected).c_str(),\
    \ compress(found).c_str());\n    else\n        message = format(\"expected '%s',\
    \ but found '%s'\",\n                         compress(expected).c_str(), compress(found).c_str());\n\
    \    quit(result, message);\n}\n\nNORETURN void __testlib_expectedButFound(TResult\
    \ result, double expected, double found, const char *prepend) {\n    std::string\
    \ expectedString = removeDoubleTrailingZeroes(format(\"%.12f\", expected));\n\
    \    std::string foundString = removeDoubleTrailingZeroes(format(\"%.12f\", found));\n\
    \    __testlib_expectedButFound(result, expectedString, foundString, prepend);\n\
    }\n\ntemplate<typename T>\n#ifdef __GNUC__\n__attribute__ ((format (printf, 4,\
    \ 5)))\n#endif\nNORETURN void expectedButFound(TResult result, T expected, T found,\
    \ const char *prependFormat = \"\", ...) {\n    FMT_TO_RESULT(prependFormat, prependFormat,\
    \ prepend);\n    std::string expectedString = vtos(expected);\n    std::string\
    \ foundString = vtos(found);\n    __testlib_expectedButFound(result, expectedString,\
    \ foundString, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<std::string>(TResult\
    \ result, std::string expected, std::string found, const char *prependFormat,\
    \ ...) {\n    FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n    __testlib_expectedButFound(result,\
    \ expected, found, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound<double>(TResult\
    \ result, double expected, double found, const char *prependFormat, ...) {\n \
    \   FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n    std::string expectedString\
    \ = removeDoubleTrailingZeroes(format(\"%.12f\", expected));\n    std::string\
    \ foundString = removeDoubleTrailingZeroes(format(\"%.12f\", found));\n    __testlib_expectedButFound(result,\
    \ expectedString, foundString, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n\
    __attribute__ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<const\
    \ char *>(TResult result, const char *expected, const char *found, const char\
    \ *prependFormat,\n                               ...) {\n    FMT_TO_RESULT(prependFormat,\
    \ prependFormat, prepend);\n    __testlib_expectedButFound(result, std::string(expected),\
    \ std::string(found), prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound<float>(TResult\
    \ result, float expected, float found, const char *prependFormat, ...) {\n   \
    \ FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n    __testlib_expectedButFound(result,\
    \ double(expected), double(found), prepend.c_str());\n}\n\ntemplate<>\n#ifdef\
    \ __GNUC__\n__attribute__ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<long\
    \ double>(TResult result, long double expected, long double found, const char\
    \ *prependFormat, ...) {\n    FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n\
    \    __testlib_expectedButFound(result, double(expected), double(found), prepend.c_str());\n\
    }\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\ntemplate<typename T>\nstruct\
    \ is_iterable {\n    template<typename U>\n    static char test(typename U::iterator\
    \ *x);\n\n    template<typename U>\n    static long test(U *x);\n\n    static\
    \ const bool value = sizeof(test<T>(0)) == 1;\n};\n\ntemplate<bool B, class T\
    \ = void>\nstruct __testlib_enable_if {\n};\n\ntemplate<class T>\nstruct __testlib_enable_if<true,\
    \ T> {\n    typedef T type;\n};\n\ntemplate<typename T>\ntypename __testlib_enable_if<!is_iterable<T>::value,\
    \ void>::type __testlib_print_one(const T &t) {\n    std::cout << t;\n}\n\ntemplate<typename\
    \ T>\ntypename __testlib_enable_if<is_iterable<T>::value, void>::type __testlib_print_one(const\
    \ T &t) {\n    bool first = true;\n    for (typename T::const_iterator i = t.begin();\
    \ i != t.end(); i++) {\n        if (first)\n            first = false;\n     \
    \   else\n            std::cout << \" \";\n        std::cout << *i;\n    }\n}\n\
    \ntemplate<>\ntypename __testlib_enable_if<is_iterable<std::string>::value, void>::type\n\
    __testlib_print_one<std::string>(const std::string &t) {\n    std::cout << t;\n\
    }\n\ntemplate<typename A, typename B>\nvoid __println_range(A begin, B end) {\n\
    \    bool first = true;\n    for (B i = B(begin); i != end; i++) {\n        if\
    \ (first)\n            first = false;\n        else\n            std::cout <<\
    \ \" \";\n        __testlib_print_one(*i);\n    }\n    std::cout << std::endl;\n\
    }\n\ntemplate<class T, class Enable = void>\nstruct is_iterator {\n    static\
    \ T makeT();\n\n    typedef void *twoptrs[2];\n\n    static twoptrs &test(...);\n\
    \n    template<class R>\n    static typename R::iterator_category *test(R);\n\n\
    \    template<class R>\n    static void *test(R *);\n\n    static const bool value\
    \ = sizeof(test(makeT())) == sizeof(void *);\n};\n\ntemplate<class T>\nstruct\
    \ is_iterator<T, typename __testlib_enable_if<std::is_array<T>::value>::type>\
    \ {\n    static const bool value = false;\n};\n\ntemplate<typename A, typename\
    \ B>\ntypename __testlib_enable_if<!is_iterator<B>::value, void>::type println(const\
    \ A &a, const B &b) {\n    __testlib_print_one(a);\n    std::cout << \" \";\n\
    \    __testlib_print_one(b);\n    std::cout << std::endl;\n}\n\ntemplate<typename\
    \ A, typename B>\ntypename __testlib_enable_if<is_iterator<B>::value, void>::type\
    \ println(const A &a, const B &b) {\n    __println_range(a, b);\n}\n\ntemplate<typename\
    \ A>\nvoid println(const A *a, const A *b) {\n    __println_range(a, b);\n}\n\n\
    template<>\nvoid println<char>(const char *a, const char *b) {\n    __testlib_print_one(a);\n\
    \    std::cout << \" \";\n    __testlib_print_one(b);\n    std::cout << std::endl;\n\
    }\n\ntemplate<typename T>\nvoid println(const T &x) {\n    __testlib_print_one(x);\n\
    \    std::cout << std::endl;\n}\n\ntemplate<typename A, typename B, typename C>\n\
    void println(const A &a, const B &b, const C &c) {\n    __testlib_print_one(a);\n\
    \    std::cout << \" \";\n    __testlib_print_one(b);\n    std::cout << \" \"\
    ;\n    __testlib_print_one(c);\n    std::cout << std::endl;\n}\n\ntemplate<typename\
    \ A, typename B, typename C, typename D>\nvoid println(const A &a, const B &b,\
    \ const C &c, const D &d) {\n    __testlib_print_one(a);\n    std::cout << \"\
    \ \";\n    __testlib_print_one(b);\n    std::cout << \" \";\n    __testlib_print_one(c);\n\
    \    std::cout << \" \";\n    __testlib_print_one(d);\n    std::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E>\nvoid\
    \ println(const A &a, const B &b, const C &c, const D &d, const E &e) {\n    __testlib_print_one(a);\n\
    \    std::cout << \" \";\n    __testlib_print_one(b);\n    std::cout << \" \"\
    ;\n    __testlib_print_one(c);\n    std::cout << \" \";\n    __testlib_print_one(d);\n\
    \    std::cout << \" \";\n    __testlib_print_one(e);\n    std::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E, typename\
    \ F>\nvoid println(const A &a, const B &b, const C &c, const D &d, const E &e,\
    \ const F &f) {\n    __testlib_print_one(a);\n    std::cout << \" \";\n    __testlib_print_one(b);\n\
    \    std::cout << \" \";\n    __testlib_print_one(c);\n    std::cout << \" \"\
    ;\n    __testlib_print_one(d);\n    std::cout << \" \";\n    __testlib_print_one(e);\n\
    \    std::cout << \" \";\n    __testlib_print_one(f);\n    std::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E, typename\
    \ F, typename G>\nvoid println(const A &a, const B &b, const C &c, const D &d,\
    \ const E &e, const F &f, const G &g) {\n    __testlib_print_one(a);\n    std::cout\
    \ << \" \";\n    __testlib_print_one(b);\n    std::cout << \" \";\n    __testlib_print_one(c);\n\
    \    std::cout << \" \";\n    __testlib_print_one(d);\n    std::cout << \" \"\
    ;\n    __testlib_print_one(e);\n    std::cout << \" \";\n    __testlib_print_one(f);\n\
    \    std::cout << \" \";\n    __testlib_print_one(g);\n    std::cout << std::endl;\n\
    }\n\n/* opts */\nsize_t getOptType(char* s) {\n    if (!s || strlen(s) <= 1)\n\
    \        return 0;\n\n    if (s[0] == '-') {\n        if (isalpha(s[1]))\n   \
    \         return 1;\n        else if (s[1] == '-')\n            return isalpha(s[2])\
    \ ? 2 : 0;\n    }\n\n    return 0;\n}\n\nsize_t parseOpt(size_t argc, char* argv[],\
    \ size_t index, std::map<std::string, std::string>& opts) {\n    if (index >=\
    \ argc)\n        return 0;\n\n    size_t type = getOptType(argv[index]), inc =\
    \ 1;\n    if (type > 0) {\n        std::string key(argv[index] + type), val;\n\
    \        size_t sep = key.find('=');\n        if (sep != std::string::npos) {\n\
    \            val = key.substr(sep + 1);\n            key = key.substr(0, sep);\n\
    \        } else {\n            if (index + 1 < argc && getOptType(argv[index +\
    \ 1]) == 0) {\n                val = argv[index + 1];\n                inc = 2;\n\
    \            } else {\n                if (key.length() > 1 && isdigit(key[1]))\
    \ {\n                    val = key.substr(1);\n                    key = key.substr(0,\
    \ 1);\n                } else {\n                    val = \"true\";\n       \
    \         }\n            }\n        }\n        opts[key] = val;\n    } else {\n\
    \        return inc;\n    }\n\n    return inc;\n}\n\nstd::vector<std::string>\
    \ __testlib_argv;\nstd::map<std::string, std::string> __testlib_opts;\n\nvoid\
    \ prepareOpts(int argc, char* argv[]) {\n    if (argc <= 0)\n        __testlib_fail(\"\
    Opts: expected argc>=0 but found \" + toString(argc));\n    size_t n = static_cast<size_t>(argc);\
    \ // NOLINT(hicpp-use-auto,modernize-use-auto)\n    __testlib_opts = std::map<std::string,\
    \ std::string>();\n    for (size_t index = 1; index < n; index += parseOpt(n,\
    \ argv, index, __testlib_opts));\n    __testlib_argv = std::vector<std::string>(n);\n\
    \    for (size_t index = 0; index < n; index++)\n        __testlib_argv[index]\
    \ = argv[index];\n}\n\nstd::string __testlib_indexToArgv(int index) {\n    if\
    \ (index < 0 || index >= int(__testlib_argv.size()))\n        __testlib_fail(\"\
    Opts: index '\" + toString(index) + \"' is out of range [0,\" + toString(__testlib_argv.size())\
    \ + \")\");\n    return __testlib_argv[size_t(index)];\n}\n\nstd::string __testlib_keyToOpts(const\
    \ std::string& key) {\n    if (__testlib_opts.count(key) == 0)\n        __testlib_fail(\"\
    Opts: unknown key '\" + compress(key) + \"'\");\n    return __testlib_opts[key];\n\
    }\n\ntemplate<typename T>\nT optValueToIntegral(const std::string& s, bool nonnegative);\n\
    \nlong double optValueToLongDouble(const std::string& s);\n\nstd::string parseExponentialOptValue(const\
    \ std::string& s) {\n    size_t pos = std::string::npos;\n    for (size_t i =\
    \ 0; i < s.length(); i++)\n        if (s[i] == 'e' || s[i] == 'E') {\n       \
    \     if (pos != std::string::npos)\n                __testlib_fail(\"Opts: expected\
    \ typical exponential notation but '\" + compress(s) + \"' found\");\n       \
    \     pos = i;\n        }\n    if (pos == std::string::npos)\n        return s;\n\
    \    std::string e = s.substr(pos + 1);\n    if (!e.empty() && e[0] == '+')\n\
    \        e = e.substr(1);\n    if (e.empty())\n        __testlib_fail(\"Opts:\
    \ expected typical exponential notation but '\" + compress(s) + \"' found\");\n\
    \    if (e.length() > 20)\n        __testlib_fail(\"Opts: expected typical exponential\
    \ notation but '\" + compress(s) + \"' found\");\n    int ne = optValueToIntegral<int>(e,\
    \ false);\n    std::string num = s.substr(0, pos);\n    if (num.length() > 20)\n\
    \        __testlib_fail(\"Opts: expected typical exponential notation but '\"\
    \ + compress(s) + \"' found\");\n    if (!num.empty() && num[0] == '+')\n    \
    \    num = num.substr(1);\n    optValueToLongDouble(num);\n    bool minus = false;\n\
    \    if (num[0] == '-') {\n        minus = true;\n        num = num.substr(1);\n\
    \    }\n    for (int i = 0; i < +ne; i++) {\n        size_t sep = num.find('.');\n\
    \        if (sep == std::string::npos)\n            num += '0';\n        else\
    \ {\n            if (sep + 1 == num.length())\n                num[sep] = '0';\n\
    \            else\n                std::swap(num[sep], num[sep + 1]);\n      \
    \  }\n    }\n    for (int i = 0; i < -ne; i++) {\n        size_t sep = num.find('.');\n\
    \        if (sep == std::string::npos)\n            num.insert(num.begin() + int(num.length())\
    \ - 1, '.');\n        else {\n            if (sep == 0)\n                num.insert(num.begin()\
    \ + 1, '0');\n            else\n                std::swap(num[sep - 1], num[sep]);\n\
    \        }\n    }\n    while (!num.empty() && num[0] == '0')\n        num = num.substr(1);\n\
    \    while (num.find('.') != std::string::npos && num.back() == '0')\n       \
    \ num = num.substr(0, num.length() - 1);\n    if (!num.empty() && num.back() ==\
    \ '.')\n        num = num.substr(0, num.length() - 1);\n    if ((!num.empty()\
    \ && num[0] == '.') || num.empty())\n        num.insert(num.begin(), '0');\n \
    \   return (minus ? \"-\" : \"\") + num;\n}\n\ntemplate<typename T>\nT optValueToIntegral(const\
    \ std::string& s_, bool nonnegative) {\n    std::string s(parseExponentialOptValue(s_));\n\
    \    if (s.empty())\n        __testlib_fail(\"Opts: expected integer but '\" +\
    \ compress(s_) + \"' found\");\n    T value = 0;\n    long double about = 0.0;\n\
    \    signed char sign = +1;\n    size_t pos = 0;\n    if (s[pos] == '-') {\n \
    \       if (nonnegative)\n            __testlib_fail(\"Opts: expected non-negative\
    \ integer but '\" + compress(s_) + \"' found\");\n        sign = -1;\n       \
    \ pos++;\n    }\n    for (size_t i = pos; i < s.length(); i++) {\n        if (s[i]\
    \ < '0' || s[i] > '9')\n            __testlib_fail(\"Opts: expected integer but\
    \ '\" + compress(s_) + \"' found\");\n        value = value * 10 + s[i] - '0';\n\
    \        about = about * 10 + s[i] - '0';\n    }\n    value *= sign;\n    about\
    \ *= sign;\n    if (fabsl(value - about) > 0.1)\n        __testlib_fail(\"Opts:\
    \ integer overflow: expected integer but '\" + compress(s_) + \"' found\");\n\
    \    return value;\n}\n\nlong double optValueToLongDouble(const std::string& s_)\
    \ {\n    std::string s(parseExponentialOptValue(s_));\n    if (s.empty())\n  \
    \      __testlib_fail(\"Opts: expected float number but '\" + compress(s_) + \"\
    ' found\");\n    long double value = 0.0;\n    signed char sign = +1;\n    size_t\
    \ pos = 0;\n    if (s[pos] == '-') {\n        sign = -1;\n        pos++;\n   \
    \ }\n    bool period = false;\n    long double mul = 1.0;\n    for (size_t i =\
    \ pos; i < s.length(); i++) {\n        if (s[i] == '.') {\n            if (period)\n\
    \                __testlib_fail(\"Opts: expected float number but '\" + compress(s_)\
    \ + \"' found\");\n            else {\n                period = true;\n      \
    \          continue;\n            }\n        }\n        if (period)\n        \
    \    mul *= 10.0;\n        if (s[i] < '0' || s[i] > '9')\n            __testlib_fail(\"\
    Opts: expected float number but '\" + compress(s_) + \"' found\");\n        if\
    \ (period)\n            value += (s[i] - '0') / mul;\n        else\n         \
    \   value = value * 10 + s[i] - '0';\n    }\n    value *= sign;\n    return value;\n\
    }\n\nbool has_opt(const std::string key) {\n    return __testlib_opts.count(key)\
    \ != 0;\n}\n\ntemplate<typename T>\nT opt(std::false_type, int index);\n\ntemplate<>\n\
    std::string opt(std::false_type, int index) {\n    return __testlib_indexToArgv(index);\n\
    }\n\ntemplate<typename T>\nT opt(std::true_type, int index) {\n    return T(optValueToLongDouble(__testlib_indexToArgv(index)));\n\
    }\n\ntemplate<typename T, typename U>\nT opt(std::false_type, U, int index) {\n\
    \    return opt<T>(std::is_floating_point<T>(), index);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::false_type, int index) {\n    return optValueToIntegral<T>(__testlib_indexToArgv(index),\
    \ false);\n}\n\ntemplate<typename T>\nT opt(std::true_type, std::true_type, int\
    \ index) {\n    return optValueToIntegral<T>(__testlib_indexToArgv(index), true);\n\
    }\n\ntemplate<>\nbool opt(std::true_type, std::true_type, int index) {\n    std::string\
    \ value = __testlib_indexToArgv(index);\n    if (value == \"true\" || value ==\
    \ \"1\")\n        return true;\n    if (value == \"false\" || value == \"0\")\n\
    \        return false;\n    __testlib_fail(\"Opts: opt by index '\" + toString(index)\
    \ + \"': expected bool true/false or 0/1 but '\" + compress(value) + \"' found\"\
    );\n}\n\ntemplate<typename T>\nT opt(int index) {\n    return opt<T>(std::is_integral<T>(),\
    \ std::is_unsigned<T>(), index);\n}\n\nstd::string opt(int index) {\n    return\
    \ opt<std::string>(index);\n}\n\ntemplate<typename T>\nT opt(std::false_type,\
    \ const std::string& key);\n\ntemplate<>\nstd::string opt(std::false_type, const\
    \ std::string& key) {\n    return __testlib_keyToOpts(key);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, const std::string& key) {\n    return T(optValueToLongDouble(__testlib_keyToOpts(key)));\n\
    }\n\ntemplate<typename T, typename U>\nT opt(std::false_type, U, const std::string&\
    \ key) {\n    return opt<T>(std::is_floating_point<T>(), key);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::false_type, const std::string& key) {\n    return\
    \ optValueToIntegral<T>(__testlib_keyToOpts(key), false);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::true_type, const std::string& key) {\n    return\
    \ optValueToIntegral<T>(__testlib_keyToOpts(key), true);\n}\n\ntemplate<>\nbool\
    \ opt(std::true_type, std::true_type, const std::string& key) {\n    if (!has_opt(key))\n\
    \        return false;\n    std::string value = __testlib_keyToOpts(key);\n  \
    \  if (value == \"true\" || value == \"1\")\n        return true;\n    if (value\
    \ == \"false\" || value == \"0\")\n        return false;\n    __testlib_fail(\"\
    Opts: key '\" + compress(key) + \"': expected bool true/false or 0/1 but '\" +\
    \ compress(value) + \"' found\");\n}\n\ntemplate<typename T>\nT opt(const std::string\
    \ key) {\n    return opt<T>(std::is_integral<T>(), std::is_unsigned<T>(), key);\n\
    }\n\nstd::string opt(const std::string key) {\n    return opt<std::string>(key);\n\
    }\n#endif\n#endif\n"
  code: "/* \n * It is strictly recommended to include \"testlib.h\" before any other\
    \ include \n * in your code. In this case testlib overrides compiler specific\
    \ \"random()\".\n *\n * If you can't compile your code and compiler outputs something\
    \ about \n * ambiguous call of \"random_shuffle\", \"rand\" or \"srand\" it means\
    \ that \n * you shouldn't use them. Use \"shuffle\", and \"rnd.next()\" instead\
    \ of them\n * because these calls produce stable result for any C++ compiler.\
    \ Read \n * sample generator sources for clarification.\n *\n * Please read the\
    \ documentation for class \"random_t\" and use \"rnd\" instance in\n * generators.\
    \ Probably, these sample calls will be usefull for you:\n *              rnd.next();\
    \ rnd.next(100); rnd.next(1, 2); \n *              rnd.next(3.14); rnd.next(\"\
    [a-z]{1,100}\").\n *\n * Also read about wnext() to generate off-center random\
    \ distribution.\n *\n * See https://github.com/MikeMirzayanov/testlib/ to get\
    \ latest version or bug tracker.\n */\n\n#ifndef _TESTLIB_H_\n#define _TESTLIB_H_\n\
    \n/*\n * Copyright (c) 2005-2020\n */\n\n#define VERSION \"0.9.34-SNAPSHOT\"\n\
    \n/* \n * Mike Mirzayanov\n *\n * This material is provided \"as is\", with absolutely\
    \ no warranty expressed\n * or implied. Any use is at your own risk.\n *\n * Permission\
    \ to use or copy this software for any purpose is hereby granted \n * without\
    \ fee, provided the above notices are retained on all copies.\n * Permission to\
    \ modify the code and to distribute modified code is granted,\n * provided the\
    \ above notices are retained, and a notice that the code was\n * modified is included\
    \ with the above copyright notice.\n *\n */\n\n/* NOTE: This file contains testlib\
    \ library for C++.\n *\n *   Check, using testlib running format:\n *     check.exe\
    \ <Input_File> <Output_File> <Answer_File> [<Result_File> [-appes]],\n *   If\
    \ result file is specified it will contain results.\n *\n *   Validator, using\
    \ testlib running format:                                          \n *     validator.exe\
    \ < input.txt,\n *   It will return non-zero exit code and writes message to standard\
    \ output.\n *\n *   Generator, using testlib running format:                 \
    \                         \n *     gen.exe [parameter-1] [parameter-2] [... paramerter-n]\n\
    \ *   You can write generated test(s) into standard output or into the file(s).\n\
    \ *\n *   Interactor, using testlib running format:                          \
    \                \n *     interactor.exe <Input_File> <Output_File> [<Answer_File>\
    \ [<Result_File> [-appes]]],\n *   Reads test from inf (mapped to args[1]), writes\
    \ result to tout (mapped to argv[2],\n *   can be judged by checker later), reads\
    \ program output from ouf (mapped to stdin),\n *   writes output to program via\
    \ stdout (use cout, printf, etc).\n */\n\nconst char *latestFeatures[] = {\n \
    \       \"Fixed hypothetical UB in stringToDouble and stringToStrictDouble\",\n\
    \        \"rnd.partition(size, sum[, min_part=0]) returns random (unsorted) partition\
    \ which is a representation of the given `sum` as a sum of `size` positive integers\
    \ (or >=min_part if specified)\",\n        \"rnd.distinct(size, n) and rnd.distinct(size,\
    \ from, to)\",\n        \"opt<bool>(\\\"some_missing_key\\\") returns false now\"\
    ,\n        \"has_opt(key)\",\n        \"Abort validator on validator.testset()/validator.group()\
    \ if registered without using command line\",\n        \"Print integer range violations\
    \ in a human readable way like `violates the range [1, 10^9]`\",\n        \"Opts\
    \ supported: use them like n = opt<int>(\\\"n\\\"), in a command line you can\
    \ use an exponential notation\",\n        \"Reformatted\",\n        \"Use setTestCase(i)\
    \ or unsetTestCase() to support test cases (you can use it in any type of program:\
    \ generator, interactor, validator or checker)\",\n        \"Fixed issue #87:\
    \ readStrictDouble accepts \\\"-0.00\\\"\",\n        \"Fixed issue #83: added\
    \ InStream::quitif(condition, ...)\",\n        \"Fixed issue #79: fixed missed\
    \ guard against repeated header include\",\n        \"Fixed issue #80: fixed UB\
    \ in case of huge quitf message\",\n        \"Fixed issue #84: added readXs(size,\
    \ indexBase = 1)\",\n        \"Fixed stringstream repeated usage issue\",\n  \
    \      \"Fixed compilation in g++ (for std=c++03)\",\n        \"Batch of println\
    \ functions (support collections, iterator ranges)\",\n        \"Introduced rnd.perm(size,\
    \ first = 0) to generate a `first`-indexed permutation\",\n        \"Allow any\
    \ whitespace in readInts-like functions for non-validators\",\n        \"Ignore\
    \ 4+ command line arguments ifdef EJUDGE\",\n        \"Speed up of vtos\",\n \
    \       \"Show line number in validators in case of incorrect format\",\n    \
    \    \"Truncate huge checker/validator/interactor message\",\n        \"Fixed\
    \ issue with readTokenTo of very long tokens, now aborts with _pe/_fail depending\
    \ of a stream type\",\n        \"Introduced InStream::ensure/ensuref checking\
    \ a condition, returns wa/fail depending of a stream type\",\n        \"Fixed\
    \ compilation in VS 2015+\",\n        \"Introduced space-separated read functions:\
    \ readWords/readTokens, multilines read functions: readStrings/readLines\",\n\
    \        \"Introduced space-separated read functions: readInts/readIntegers/readLongs/readUnsignedLongs/readDoubles/readReals/readStrictDoubles/readStrictReals\"\
    ,\n        \"Introduced split/tokenize functions to separate string by given char\"\
    ,\n        \"Introduced InStream::readUnsignedLong and InStream::readLong with\
    \ unsigned long long paramerters\",\n        \"Supported --testOverviewLogFileName\
    \ for validator: bounds hits + features\",\n        \"Fixed UB (sequence points)\
    \ in random_t\",\n        \"POINTS_EXIT_CODE returned back to 7 (instead of 0)\"\
    ,\n        \"Removed disable buffers for interactive problems, because it works\
    \ unexpectedly in wine\",\n        \"InStream over string: constructor of InStream\
    \ from base InStream to inherit policies and std::string\",\n        \"Added expectedButFound\
    \ quit function, examples: expectedButFound(_wa, 10, 20), expectedButFound(_fail,\
    \ ja, pa, \\\"[n=%d,m=%d]\\\", n, m)\",\n        \"Fixed incorrect interval parsing\
    \ in patterns\",\n        \"Use registerGen(argc, argv, 1) to develop new generator,\
    \ use registerGen(argc, argv, 0) to compile old generators (originally created\
    \ for testlib under 0.8.7)\",\n        \"Introduced disableFinalizeGuard() to\
    \ switch off finalization checkings\",\n        \"Use join() functions to format\
    \ a range of items as a single string (separated by spaces or other separators)\"\
    ,\n        \"Use -DENABLE_UNEXPECTED_EOF to enable special exit code (by default,\
    \ 8) in case of unexpected eof. It is good idea to use it in interactors\",\n\
    \        \"Use -DUSE_RND_AS_BEFORE_087 to compile in compatibility mode with random\
    \ behavior of versions before 0.8.7\",\n        \"Fixed bug with nan in stringToDouble\"\
    ,\n        \"Fixed issue around overloads for size_t on x64\",\n        \"Added\
    \ attribute 'points' to the XML output in case of result=_points\",\n        \"\
    Exit codes can be customized via macros, e.g. -DPE_EXIT_CODE=14\",\n        \"\
    Introduced InStream function readWordTo/readTokenTo/readStringTo/readLineTo for\
    \ faster reading\",\n        \"Introduced global functions: format(), englishEnding(),\
    \ upperCase(), lowerCase(), compress()\",\n        \"Manual buffer in InStreams,\
    \ some IO speed improvements\",\n        \"Introduced quitif(bool, const char*\
    \ pattern, ...) which delegates to quitf() in case of first argument is true\"\
    ,\n        \"Introduced guard against missed quitf() in checker or readEof() in\
    \ validators\",\n        \"Supported readStrictReal/readStrictDouble - to use\
    \ in validators to check strictly float numbers\",\n        \"Supported registerInteraction(argc,\
    \ argv)\",\n        \"Print checker message to the stderr instead of stdout\"\
    ,\n        \"Supported TResult _points to output calculated score, use quitp(...)\
    \ functions\",\n        \"Fixed to be compilable on Mac\",\n        \"PC_BASE_EXIT_CODE=50\
    \ in case of defined TESTSYS\",\n        \"Fixed issues 19-21, added __attribute__\
    \ format printf\",\n        \"Some bug fixes\",\n        \"ouf.readInt(1, 100)\
    \ and similar calls return WA\",\n        \"Modified random_t to avoid integer\
    \ overflow\",\n        \"Truncated checker output [patch by Stepan Gatilov]\"\
    ,\n        \"Renamed class random -> class random_t\",\n        \"Supported name\
    \ parameter for read-and-validation methods, like readInt(1, 2, \\\"n\\\")\",\n\
    \        \"Fixed bug in readDouble()\",\n        \"Improved ensuref(), fixed nextLine\
    \ to work in case of EOF, added startTest()\",\n        \"Supported \\\"partially\
    \ correct\\\", example: quitf(_pc(13), \\\"result=%d\\\", result)\",\n       \
    \ \"Added shuffle(begin, end), use it instead of random_shuffle(begin, end)\"\
    ,\n        \"Added readLine(const string& ptrn), fixed the logic of readLine()\
    \ in the validation mode\",\n        \"Package extended with samples of generators\
    \ and validators\",\n        \"Written the documentation for classes and public\
    \ methods in testlib.h\",\n        \"Implemented random routine to support generators,\
    \ use registerGen() to switch it on\",\n        \"Implemented strict mode to validate\
    \ tests, use registerValidation() to switch it on\",\n        \"Now ncmp.cpp and\
    \ wcmp.cpp are return WA if answer is suffix or prefix of the output\",\n    \
    \    \"Added InStream::readLong() and removed InStream::readLongint()\",\n   \
    \     \"Now no footer added to each report by default (use directive FOOTER to\
    \ switch on)\",\n        \"Now every checker has a name, use setName(const char*\
    \ format, ...) to set it\",\n        \"Now it is compatible with TTS (by Kittens\
    \ Computing)\",\n        \"Added \\'ensure(condition, message = \\\"\\\")\\' feature,\
    \ it works like assert()\",\n        \"Fixed compatibility with MS C++ 7.1\",\n\
    \        \"Added footer with exit code information\",\n        \"Added compatibility\
    \ with EJUDGE (compile with EJUDGE directive)\",\n        \"Added compatibility\
    \ with Contester (compile with CONTESTER directive)\"\n};\n\n#ifdef _MSC_VER\n\
    #define _CRT_SECURE_NO_DEPRECATE\n#define _CRT_SECURE_NO_WARNINGS\n#define _CRT_NO_VA_START_VALIDATION\n\
    #endif\n\n/* Overrides random() for Borland C++. */\n#define random __random_deprecated\n\
    #include <stdlib.h>\n#include <cstdlib>\n#include <climits>\n#include <algorithm>\n\
    #undef random\n\n#include <cstdio>\n#include <cctype>\n#include <string>\n#include\
    \ <vector>\n#include <map>\n#include <set>\n#include <cmath>\n#include <iostream>\n\
    #include <sstream>\n#include <fstream>\n#include <cstring>\n#include <limits>\n\
    #include <stdarg.h>\n#include <fcntl.h>\n\n#if (_WIN32 || __WIN32__ || _WIN64\
    \ || __WIN64__ || __CYGWIN__)\n#   if !defined(_MSC_VER) || _MSC_VER > 1400\n\
    #       define NOMINMAX 1\n#       include <windows.h>\n#   else\n#       define\
    \ WORD unsigned short\n#       include <unistd.h>\n#   endif\n#   include <io.h>\n\
    #   define ON_WINDOWS\n#   if defined(_MSC_VER) && _MSC_VER > 1400\n#       pragma\
    \ warning( disable : 4127 )\n#       pragma warning( disable : 4146 )\n#     \
    \  pragma warning( disable : 4458 )\n#   endif\n#else\n#   define WORD unsigned\
    \ short\n#   include <unistd.h>\n#endif\n\n#if defined(FOR_WINDOWS) && defined(FOR_LINUX)\n\
    #error Only one target system is allowed\n#endif\n\n#ifndef LLONG_MIN\n#define\
    \ LLONG_MIN   (-9223372036854775807LL - 1)\n#endif\n\n#ifndef ULLONG_MAX\n#define\
    \ ULLONG_MAX   (18446744073709551615)\n#endif\n\n#define LF ((char)10)\n#define\
    \ CR ((char)13)\n#define TAB ((char)9)\n#define SPACE ((char)' ')\n#define EOFC\
    \ (255)\n\n#ifndef OK_EXIT_CODE\n#   ifdef CONTESTER\n#       define OK_EXIT_CODE\
    \ 0xAC\n#   else\n#       define OK_EXIT_CODE 0\n#   endif\n#endif\n\n#ifndef\
    \ WA_EXIT_CODE\n#   ifdef EJUDGE\n#       define WA_EXIT_CODE 5\n#   elif defined(CONTESTER)\n\
    #       define WA_EXIT_CODE 0xAB\n#   else\n#       define WA_EXIT_CODE 1\n# \
    \  endif\n#endif\n\n#ifndef PE_EXIT_CODE\n#   ifdef EJUDGE\n#       define PE_EXIT_CODE\
    \ 4\n#   elif defined(CONTESTER)\n#       define PE_EXIT_CODE 0xAA\n#   else\n\
    #       define PE_EXIT_CODE 2\n#   endif\n#endif\n\n#ifndef FAIL_EXIT_CODE\n#\
    \   ifdef EJUDGE\n#       define FAIL_EXIT_CODE 6\n#   elif defined(CONTESTER)\n\
    #       define FAIL_EXIT_CODE 0xA3\n#   else\n#       define FAIL_EXIT_CODE 3\n\
    #   endif\n#endif\n\n#ifndef DIRT_EXIT_CODE\n#   ifdef EJUDGE\n#       define\
    \ DIRT_EXIT_CODE 6\n#   else\n#       define DIRT_EXIT_CODE 4\n#   endif\n#endif\n\
    \n#ifndef POINTS_EXIT_CODE\n#   define POINTS_EXIT_CODE 7\n#endif\n\n#ifndef UNEXPECTED_EOF_EXIT_CODE\n\
    #   define UNEXPECTED_EOF_EXIT_CODE 8\n#endif\n\n#ifndef PC_BASE_EXIT_CODE\n#\
    \   ifdef TESTSYS\n#       define PC_BASE_EXIT_CODE 50\n#   else\n#       define\
    \ PC_BASE_EXIT_CODE 0\n#   endif\n#endif\n\n#ifdef __GNUC__\n#    define __TESTLIB_STATIC_ASSERT(condition)\
    \ typedef void* __testlib_static_assert_type[(condition) ? 1 : -1] __attribute__((unused))\n\
    #else\n#    define __TESTLIB_STATIC_ASSERT(condition) typedef void* __testlib_static_assert_type[(condition)\
    \ ? 1 : -1]\n#endif\n\n#ifdef ON_WINDOWS\n#define I64 \"%I64d\"\n#define U64 \"\
    %I64u\"\n#else\n#define I64 \"%lld\"\n#define U64 \"%llu\"\n#endif\n\n#ifdef _MSC_VER\n\
    #   define NORETURN __declspec(noreturn)\n#elif defined __GNUC__\n#   define NORETURN\
    \ __attribute__ ((noreturn))\n#else\n#   define NORETURN\n#endif\n\nstatic char\
    \ __testlib_format_buffer[16777216];\nstatic int __testlib_format_buffer_usage_count\
    \ = 0;\n\n#define FMT_TO_RESULT(fmt, cstr, result)  std::string result;      \
    \                        \\\n            if (__testlib_format_buffer_usage_count\
    \ != 0)                                  \\\n                __testlib_fail(\"\
    FMT_TO_RESULT::__testlib_format_buffer_usage_count != 0\"); \\\n            __testlib_format_buffer_usage_count++;\
    \                                         \\\n            va_list ap;        \
    \                                                            \\\n            va_start(ap,\
    \ fmt);                                                             \\\n     \
    \       vsnprintf(__testlib_format_buffer, sizeof(__testlib_format_buffer), cstr,\
    \ ap); \\\n            va_end(ap);                                           \
    \                         \\\n            __testlib_format_buffer[sizeof(__testlib_format_buffer)\
    \ - 1] = 0;              \\\n            result = std::string(__testlib_format_buffer);\
    \                                 \\\n            __testlib_format_buffer_usage_count--;\
    \                                         \\\n\nconst long long __TESTLIB_LONGLONG_MAX\
    \ = 9223372036854775807LL;\n\nbool __testlib_hasTestCase;\nint __testlib_testCase\
    \ = -1;\n\nvoid setTestCase(int testCase) {\n    __testlib_hasTestCase = true;\n\
    \    __testlib_testCase = testCase;\n}\n\nvoid unsetTestCase() {\n    __testlib_hasTestCase\
    \ = false;\n    __testlib_testCase = -1;\n}\n\nNORETURN static void __testlib_fail(const\
    \ std::string &message);\n\ntemplate<typename T>\nstatic inline T __testlib_abs(const\
    \ T &x) {\n    return x > 0 ? x : -x;\n}\n\ntemplate<typename T>\nstatic inline\
    \ T __testlib_min(const T &a, const T &b) {\n    return a < b ? a : b;\n}\n\n\
    template<typename T>\nstatic inline T __testlib_max(const T &a, const T &b) {\n\
    \    return a > b ? a : b;\n}\n\nstatic bool __testlib_prelimIsNaN(double r) {\n\
    \    volatile double ra = r;\n#ifndef __BORLANDC__\n    return ((ra != ra) ==\
    \ true) && ((ra == ra) == false) && ((1.0 > ra) == false) && ((1.0 < ra) == false);\n\
    #else\n    return std::_isnan(ra);\n#endif\n}\n\nstatic std::string removeDoubleTrailingZeroes(std::string\
    \ value) {\n    while (!value.empty() && value[value.length() - 1] == '0' && value.find('.')\
    \ != std::string::npos)\n        value = value.substr(0, value.length() - 1);\n\
    \    return value + '0';\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf,\
    \ 1, 2)))\n#endif\nstd::string format(const char *fmt, ...) {\n    FMT_TO_RESULT(fmt,\
    \ fmt, result);\n    return result;\n}\n\nstd::string format(const std::string\
    \ fmt, ...) {\n    FMT_TO_RESULT(fmt, fmt.c_str(), result);\n    return result;\n\
    }\n\nstatic std::string __testlib_part(const std::string &s);\n\nstatic bool __testlib_isNaN(double\
    \ r) {\n    __TESTLIB_STATIC_ASSERT(sizeof(double) == sizeof(long long));\n  \
    \  volatile double ra = r;\n    long long llr1, llr2;\n    std::memcpy((void *)\
    \ &llr1, (void *) &ra, sizeof(double));\n    ra = -ra;\n    std::memcpy((void\
    \ *) &llr2, (void *) &ra, sizeof(double));\n    long long llnan = 0xFFF8000000000000LL;\n\
    \    return __testlib_prelimIsNaN(r) || llnan == llr1 || llnan == llr2;\n}\n\n\
    static double __testlib_nan() {\n    __TESTLIB_STATIC_ASSERT(sizeof(double) ==\
    \ sizeof(long long));\n#ifndef NAN\n    long long llnan = 0xFFF8000000000000LL;\n\
    \    double nan;\n    std::memcpy(&nan, &llnan, sizeof(double));\n    return nan;\n\
    #else\n    return NAN;\n#endif\n}\n\nstatic bool __testlib_isInfinite(double r)\
    \ {\n    volatile double ra = r;\n    return (ra > 1E300 || ra < -1E300);\n}\n\
    \n#ifdef __GNUC__\n__attribute__((const))\n#endif\ninline bool doubleCompare(double\
    \ expected, double result, double MAX_DOUBLE_ERROR) {\n    if (__testlib_isNaN(expected))\
    \ {\n        return __testlib_isNaN(result);\n    } else if (__testlib_isInfinite(expected))\
    \ {\n        if (expected > 0) {\n            return result > 0 && __testlib_isInfinite(result);\n\
    \        } else {\n            return result < 0 && __testlib_isInfinite(result);\n\
    \        }\n    } else if (__testlib_isNaN(result) || __testlib_isInfinite(result))\
    \ {\n        return false;\n    } else if (__testlib_abs(result - expected) <=\
    \ MAX_DOUBLE_ERROR + 1E-15) {\n        return true;\n    } else {\n        double\
    \ minv = __testlib_min(expected * (1.0 - MAX_DOUBLE_ERROR),\n                \
    \                    expected * (1.0 + MAX_DOUBLE_ERROR));\n        double maxv\
    \ = __testlib_max(expected * (1.0 - MAX_DOUBLE_ERROR),\n                     \
    \               expected * (1.0 + MAX_DOUBLE_ERROR));\n        return result +\
    \ 1E-15 >= minv && result <= maxv + 1E-15;\n    }\n}\n\n#ifdef __GNUC__\n__attribute__((const))\n\
    #endif\ninline double doubleDelta(double expected, double result) {\n    double\
    \ absolute = __testlib_abs(result - expected);\n\n    if (__testlib_abs(expected)\
    \ > 1E-9) {\n        double relative = __testlib_abs(absolute / expected);\n \
    \       return __testlib_min(absolute, relative);\n    } else\n        return\
    \ absolute;\n}\n\n#if !defined(_MSC_VER) || _MSC_VER < 1900\n#ifndef _fileno\n\
    #define _fileno(_stream)  ((_stream)->_file)\n#endif\n#endif\n\n#ifndef O_BINARY\n\
    static void __testlib_set_binary(\n#ifdef __GNUC__\n    __attribute__((unused))\
    \ \n#endif\n    std::FILE* file\n)\n#else\nstatic void __testlib_set_binary(std::FILE\
    \ *file)\n#endif\n{\n#ifdef O_BINARY\n    if (NULL != file) {\n#ifndef __BORLANDC__\n\
    \        _setmode(_fileno(file), O_BINARY);\n#else\n        setmode(fileno(file),\
    \ O_BINARY);\n#endif\n    }\n#endif\n}\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\n\
    /* opts */\nvoid prepareOpts(int argc, char* argv[]);\n#endif\n\n/*\n * Very simple\
    \ regex-like pattern.\n * It used for two purposes: validation and generation.\n\
    \ * \n * For example, pattern(\"[a-z]{1,5}\").next(rnd) will return\n * random\
    \ string from lowercase latin letters with length \n * from 1 to 5. It is easier\
    \ to call rnd.next(\"[a-z]{1,5}\") \n * for the same effect. \n * \n * Another\
    \ samples:\n * \"mike|john\" will generate (match) \"mike\" or \"john\";\n * \"\
    -?[1-9][0-9]{0,3}\" will generate (match) non-zero integers from -9999 to 9999;\n\
    \ * \"id-([ac]|b{2})\" will generate (match) \"id-a\", \"id-bb\", \"id-c\";\n\
    \ * \"[^0-9]*\" will match sequences (empty or non-empty) without digits, you\
    \ can't \n * use it for generations.\n *\n * You can't use pattern for generation\
    \ if it contains meta-symbol '*'. Also it\n * is not recommended to use it for\
    \ char-sets with meta-symbol '^' like [^a-z].\n *\n * For matching very simple\
    \ greedy algorithm is used. For example, pattern\n * \"[0-9]?1\" will not match\
    \ \"1\", because of greedy nature of matching.\n * Alternations (meta-symbols\
    \ \"|\") are processed with brute-force algorithm, so \n * do not use many alternations\
    \ in one expression.\n *\n * If you want to use one expression many times it is\
    \ better to compile it into\n * a single pattern like \"pattern p(\"[a-z]+\")\"\
    . Later you can use \n * \"p.matches(std::string s)\" or \"p.next(random_t& rd)\"\
    \ to check matching or generate\n * new string by pattern.\n * \n * Simpler way\
    \ to read token and check it for pattern matching is \"inf.readToken(\"[a-z]+\"\
    )\".\n */\nclass random_t;\n\nclass pattern {\npublic:\n    /* Create pattern\
    \ instance by string. */\n    pattern(std::string s);\n\n    /* Generate new string\
    \ by pattern and given random_t. */\n    std::string next(random_t &rnd) const;\n\
    \n    /* Checks if given string match the pattern. */\n    bool matches(const\
    \ std::string &s) const;\n\n    /* Returns source string of the pattern. */\n\
    \    std::string src() const;\n\nprivate:\n    bool matches(const std::string\
    \ &s, size_t pos) const;\n\n    std::string s;\n    std::vector<pattern> children;\n\
    \    std::vector<char> chars;\n    int from;\n    int to;\n};\n\n/* \n * Use random_t\
    \ instances to generate random values. It is preffered\n * way to use randoms\
    \ instead of rand() function or self-written \n * randoms.\n *\n * Testlib defines\
    \ global variable \"rnd\" of random_t class.\n * Use registerGen(argc, argv, 1)\
    \ to setup random_t seed be command\n * line (to use latest random generator version).\n\
    \ *\n * Random generates uniformly distributed values if another strategy is\n\
    \ * not specified explicitly.\n */\nclass random_t {\nprivate:\n    unsigned long\
    \ long seed;\n    static const unsigned long long multiplier;\n    static const\
    \ unsigned long long addend;\n    static const unsigned long long mask;\n    static\
    \ const int lim;\n\n    long long nextBits(int bits) {\n        if (bits <= 48)\
    \ {\n            seed = (seed * multiplier + addend) & mask;\n            return\
    \ (long long) (seed >> (48 - bits));\n        } else {\n            if (bits >\
    \ 63)\n                __testlib_fail(\"random_t::nextBits(int bits): n must be\
    \ less than 64\");\n\n            int lowerBitCount = (random_t::version == 0\
    \ ? 31 : 32);\n\n            long long left = (nextBits(31) << 32);\n        \
    \    long long right = nextBits(lowerBitCount);\n\n            return left ^ right;\n\
    \        }\n    }\n\npublic:\n    static int version;\n\n    /* New random_t with\
    \ fixed seed. */\n    random_t()\n            : seed(3905348978240129619LL) {\n\
    \    }\n\n    /* Sets seed by command line. */\n    void setSeed(int argc, char\
    \ *argv[]) {\n        random_t p;\n\n        seed = 3905348978240129619LL;\n \
    \       for (int i = 1; i < argc; i++) {\n            std::size_t le = std::strlen(argv[i]);\n\
    \            for (std::size_t j = 0; j < le; j++)\n                seed = seed\
    \ * multiplier + (unsigned int) (argv[i][j]) + addend;\n            seed += multiplier\
    \ / addend;\n        }\n\n        seed = seed & mask;\n    }\n\n    /* Sets seed\
    \ by given value. */\n    void setSeed(long long _seed) {\n        _seed = (_seed\
    \ ^ multiplier) & mask;\n        seed = _seed;\n    }\n\n#ifndef __BORLANDC__\n\
    \n    /* Random string value by given pattern (see pattern documentation). */\n\
    \    std::string next(const std::string &ptrn) {\n        pattern p(ptrn);\n \
    \       return p.next(*this);\n    }\n\n#else\n    /* Random string value by given\
    \ pattern (see pattern documentation). */\n    std::string next(std::string ptrn)\n\
    \    {\n        pattern p(ptrn);\n        return p.next(*this);\n    }\n#endif\n\
    \n    /* Random value in range [0, n-1]. */\n    int next(int n) {\n        if\
    \ (n <= 0)\n            __testlib_fail(\"random_t::next(int n): n must be positive\"\
    );\n\n        if ((n & -n) == n)  // n is a power of 2\n            return (int)\
    \ ((n * (long long) nextBits(31)) >> 31);\n\n        const long long limit = INT_MAX\
    \ / n * n;\n\n        long long bits;\n        do {\n            bits = nextBits(31);\n\
    \        } while (bits >= limit);\n\n        return int(bits % n);\n    }\n\n\
    \    /* Random value in range [0, n-1]. */\n    unsigned int next(unsigned int\
    \ n) {\n        if (n >= INT_MAX)\n            __testlib_fail(\"random_t::next(unsigned\
    \ int n): n must be less INT_MAX\");\n        return (unsigned int) next(int(n));\n\
    \    }\n\n    /* Random value in range [0, n-1]. */\n    long long next(long long\
    \ n) {\n        if (n <= 0)\n            __testlib_fail(\"random_t::next(long\
    \ long n): n must be positive\");\n\n        const long long limit = __TESTLIB_LONGLONG_MAX\
    \ / n * n;\n\n        long long bits;\n        do {\n            bits = nextBits(63);\n\
    \        } while (bits >= limit);\n\n        return bits % n;\n    }\n\n    /*\
    \ Random value in range [0, n-1]. */\n    unsigned long long next(unsigned long\
    \ long n) {\n        if (n >= (unsigned long long) (__TESTLIB_LONGLONG_MAX))\n\
    \            __testlib_fail(\"random_t::next(unsigned long long n): n must be\
    \ less LONGLONG_MAX\");\n        return (unsigned long long) next((long long)\
    \ (n));\n    }\n\n    /* Random value in range [0, n-1]. */\n    long next(long\
    \ n) {\n        return (long) next((long long) (n));\n    }\n\n    /* Random value\
    \ in range [0, n-1]. */\n    unsigned long next(unsigned long n) {\n        if\
    \ (n >= (unsigned long) (LONG_MAX))\n            __testlib_fail(\"random_t::next(unsigned\
    \ long n): n must be less LONG_MAX\");\n        return (unsigned long) next((unsigned\
    \ long long) (n));\n    }\n\n    /* Returns random value in range [from,to]. */\n\
    \    int next(int from, int to) {\n        return int(next((long long) to - from\
    \ + 1) + from);\n    }\n\n    /* Returns random value in range [from,to]. */\n\
    \    unsigned int next(unsigned int from, unsigned int to) {\n        return (unsigned\
    \ int) (next((long long) to - from + 1) + from);\n    }\n\n    /* Returns random\
    \ value in range [from,to]. */\n    long long next(long long from, long long to)\
    \ {\n        return next(to - from + 1) + from;\n    }\n\n    /* Returns random\
    \ value in range [from,to]. */\n    unsigned long long next(unsigned long long\
    \ from, unsigned long long to) {\n        if (from > to)\n            __testlib_fail(\"\
    random_t::next(unsigned long long from, unsigned long long to): from can't not\
    \ exceed to\");\n        return next(to - from + 1) + from;\n    }\n\n    /* Returns\
    \ random value in range [from,to]. */\n    long next(long from, long to) {\n \
    \       return next(to - from + 1) + from;\n    }\n\n    /* Returns random value\
    \ in range [from,to]. */\n    unsigned long next(unsigned long from, unsigned\
    \ long to) {\n        if (from > to)\n            __testlib_fail(\"random_t::next(unsigned\
    \ long from, unsigned long to): from can't not exceed to\");\n        return next(to\
    \ - from + 1) + from;\n    }\n\n    /* Random double value in range [0, 1). */\n\
    \    double next() {\n        long long left = ((long long) (nextBits(26)) <<\
    \ 27);\n        long long right = nextBits(27);\n        return (double) (left\
    \ + right) / (double) (1LL << 53);\n    }\n\n    /* Random double value in range\
    \ [0, n). */\n    double next(double n) {\n        return n * next();\n    }\n\
    \n    /* Random double value in range [from, to). */\n    double next(double from,\
    \ double to) {\n        if (from > to)\n            __testlib_fail(\"random_t::next(double\
    \ from, double to): from can't not exceed to\");\n        return next(to - from)\
    \ + from;\n    }\n\n    /* Returns random element from container. */\n    template<typename\
    \ Container>\n    typename Container::value_type any(const Container &c) {\n \
    \       size_t size = c.size();\n        if (size <= 0)\n            __testlib_fail(\"\
    random_t::any(const Container& c): c.size() must be positive\");\n        return\
    \ *(c.begin() + next(size));\n    }\n\n    /* Returns random element from iterator\
    \ range. */\n    template<typename Iter>\n    typename Iter::value_type any(const\
    \ Iter &begin, const Iter &end) {\n        int size = int(end - begin);\n    \
    \    if (size <= 0)\n            __testlib_fail(\"random_t::any(const Iter& begin,\
    \ const Iter& end): range must have positive length\");\n        return *(begin\
    \ + next(size));\n    }\n\n    /* Random string value by given pattern (see pattern\
    \ documentation). */\n#ifdef __GNUC__\n    __attribute__ ((format (printf, 2,\
    \ 3)))\n#endif\n    std::string next(const char *format, ...) {\n        FMT_TO_RESULT(format,\
    \ format, ptrn);\n        return next(ptrn);\n    }\n\n    /* \n     * Weighted\
    \ next. If type == 0 than it is usual \"next()\".\n     *\n     * If type = 1,\
    \ than it returns \"max(next(), next())\"\n     * (the number of \"max\" functions\
    \ equals to \"type\").\n     *\n     * If type < 0, than \"max\" function replaces\
    \ with \"min\".\n     */\n    int wnext(int n, int type) {\n        if (n <= 0)\n\
    \            __testlib_fail(\"random_t::wnext(int n, int type): n must be positive\"\
    );\n\n        if (abs(type) < random_t::lim) {\n            int result = next(n);\n\
    \n            for (int i = 0; i < +type; i++)\n                result = __testlib_max(result,\
    \ next(n));\n\n            for (int i = 0; i < -type; i++)\n                result\
    \ = __testlib_min(result, next(n));\n\n            return result;\n        } else\
    \ {\n            double p;\n\n            if (type > 0)\n                p = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n            else\n                p = 1 - std::pow(next()\
    \ + 0.0, 1.0 / (-type + 1));\n\n            return int(n * p);\n        }\n  \
    \  }\n\n    /* See wnext(int, int). It uses the same algorithms. */\n    long\
    \ long wnext(long long n, int type) {\n        if (n <= 0)\n            __testlib_fail(\"\
    random_t::wnext(long long n, int type): n must be positive\");\n\n        if (abs(type)\
    \ < random_t::lim) {\n            long long result = next(n);\n\n            for\
    \ (int i = 0; i < +type; i++)\n                result = __testlib_max(result,\
    \ next(n));\n\n            for (int i = 0; i < -type; i++)\n                result\
    \ = __testlib_min(result, next(n));\n\n            return result;\n        } else\
    \ {\n            double p;\n\n            if (type > 0)\n                p = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n            else\n                p = std::pow(next()\
    \ + 0.0, -type + 1);\n\n            return __testlib_min(__testlib_max((long long)\
    \ (double(n) * p), 0LL), n - 1LL);\n        }\n    }\n\n    /* See wnext(int,\
    \ int). It uses the same algorithms. */\n    double wnext(int type) {\n      \
    \  if (abs(type) < random_t::lim) {\n            double result = next();\n\n \
    \           for (int i = 0; i < +type; i++)\n                result = __testlib_max(result,\
    \ next());\n\n            for (int i = 0; i < -type; i++)\n                result\
    \ = __testlib_min(result, next());\n\n            return result;\n        } else\
    \ {\n            double p;\n\n            if (type > 0)\n                p = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n            else\n                p = std::pow(next()\
    \ + 0.0, -type + 1);\n\n            return p;\n        }\n    }\n\n    /* See\
    \ wnext(int, int). It uses the same algorithms. */\n    double wnext(double n,\
    \ int type) {\n        if (n <= 0)\n            __testlib_fail(\"random_t::wnext(double\
    \ n, int type): n must be positive\");\n\n        if (abs(type) < random_t::lim)\
    \ {\n            double result = next();\n\n            for (int i = 0; i < +type;\
    \ i++)\n                result = __testlib_max(result, next());\n\n          \
    \  for (int i = 0; i < -type; i++)\n                result = __testlib_min(result,\
    \ next());\n\n            return n * result;\n        } else {\n            double\
    \ p;\n\n            if (type > 0)\n                p = std::pow(next() + 0.0,\
    \ 1.0 / (type + 1));\n            else\n                p = std::pow(next() +\
    \ 0.0, -type + 1);\n\n            return n * p;\n        }\n    }\n\n    /* See\
    \ wnext(int, int). It uses the same algorithms. */\n    unsigned int wnext(unsigned\
    \ int n, int type) {\n        if (n >= INT_MAX)\n            __testlib_fail(\"\
    random_t::wnext(unsigned int n, int type): n must be less INT_MAX\");\n      \
    \  return (unsigned int) wnext(int(n), type);\n    }\n\n    /* See wnext(int,\
    \ int). It uses the same algorithms. */\n    unsigned long long wnext(unsigned\
    \ long long n, int type) {\n        if (n >= (unsigned long long) (__TESTLIB_LONGLONG_MAX))\n\
    \            __testlib_fail(\"random_t::wnext(unsigned long long n, int type):\
    \ n must be less LONGLONG_MAX\");\n\n        return (unsigned long long) wnext((long\
    \ long) (n), type);\n    }\n\n    /* See wnext(int, int). It uses the same algorithms.\
    \ */\n    long wnext(long n, int type) {\n        return (long) wnext((long long)\
    \ (n), type);\n    }\n\n    /* See wnext(int, int). It uses the same algorithms.\
    \ */\n    unsigned long wnext(unsigned long n, int type) {\n        if (n >= (unsigned\
    \ long) (LONG_MAX))\n            __testlib_fail(\"random_t::wnext(unsigned long\
    \ n, int type): n must be less LONG_MAX\");\n\n        return (unsigned long)\
    \ wnext((unsigned long long) (n), type);\n    }\n\n    /* Returns weighted random\
    \ value in range [from, to]. */\n    int wnext(int from, int to, int type) {\n\
    \        if (from > to)\n            __testlib_fail(\"random_t::wnext(int from,\
    \ int to, int type): from can't not exceed to\");\n        return wnext(to - from\
    \ + 1, type) + from;\n    }\n\n    /* Returns weighted random value in range [from,\
    \ to]. */\n    int wnext(unsigned int from, unsigned int to, int type) {\n   \
    \     if (from > to)\n            __testlib_fail(\"random_t::wnext(unsigned int\
    \ from, unsigned int to, int type): from can't not exceed to\");\n        return\
    \ int(wnext(to - from + 1, type) + from);\n    }\n\n    /* Returns weighted random\
    \ value in range [from, to]. */\n    long long wnext(long long from, long long\
    \ to, int type) {\n        if (from > to)\n            __testlib_fail(\"random_t::wnext(long\
    \ long from, long long to, int type): from can't not exceed to\");\n        return\
    \ wnext(to - from + 1, type) + from;\n    }\n\n    /* Returns weighted random\
    \ value in range [from, to]. */\n    unsigned long long wnext(unsigned long long\
    \ from, unsigned long long to, int type) {\n        if (from > to)\n         \
    \   __testlib_fail(\n                    \"random_t::wnext(unsigned long long\
    \ from, unsigned long long to, int type): from can't not exceed to\");\n     \
    \   return wnext(to - from + 1, type) + from;\n    }\n\n    /* Returns weighted\
    \ random value in range [from, to]. */\n    long wnext(long from, long to, int\
    \ type) {\n        if (from > to)\n            __testlib_fail(\"random_t::wnext(long\
    \ from, long to, int type): from can't not exceed to\");\n        return wnext(to\
    \ - from + 1, type) + from;\n    }\n\n    /* Returns weighted random value in\
    \ range [from, to]. */\n    unsigned long wnext(unsigned long from, unsigned long\
    \ to, int type) {\n        if (from > to)\n            __testlib_fail(\"random_t::wnext(unsigned\
    \ long from, unsigned long to, int type): from can't not exceed to\");\n     \
    \   return wnext(to - from + 1, type) + from;\n    }\n\n    /* Returns weighted\
    \ random double value in range [from, to). */\n    double wnext(double from, double\
    \ to, int type) {\n        if (from > to)\n            __testlib_fail(\"random_t::wnext(double\
    \ from, double to, int type): from can't not exceed to\");\n        return wnext(to\
    \ - from, type) + from;\n    }\n\n    /* Returns weighted random element from\
    \ container. */\n    template<typename Container>\n    typename Container::value_type\
    \ wany(const Container &c, int type) {\n        size_t size = c.size();\n    \
    \    if (size <= 0)\n            __testlib_fail(\"random_t::wany(const Container&\
    \ c, int type): c.size() must be positive\");\n        return *(c.begin() + wnext(size,\
    \ type));\n    }\n\n    /* Returns weighted random element from iterator range.\
    \ */\n    template<typename Iter>\n    typename Iter::value_type wany(const Iter\
    \ &begin, const Iter &end, int type) {\n        int size = int(end - begin);\n\
    \        if (size <= 0)\n            __testlib_fail(\n                    \"random_t::any(const\
    \ Iter& begin, const Iter& end, int type): range must have positive length\");\n\
    \        return *(begin + wnext(size, type));\n    }\n\n    /* Returns random\
    \ permutation of the given size (values are between `first` and `first`+size-1)*/\n\
    \    template<typename T, typename E>\n    std::vector<E> perm(T size, E first)\
    \ {\n        if (size <= 0)\n            __testlib_fail(\"random_t::perm(T size,\
    \ E first = 0): size must be positive\");\n        std::vector<E> p(size);\n \
    \       E current = first;\n        for (T i = 0; i < size; i++)\n           \
    \ p[i] = current++;\n        if (size > 1)\n            for (T i = 1; i < size;\
    \ i++)\n                std::swap(p[i], p[next(i + 1)]);\n        return p;\n\
    \    }\n\n    /* Returns random permutation of the given size (values are between\
    \ 0 and size-1)*/\n    template<typename T>\n    std::vector<T> perm(T size) {\n\
    \        return perm(size, T(0));\n    }\n    \n    /* Returns `size` unordered\
    \ (unsorted) distinct numbers between `from` and `to`. */\n    template<typename\
    \ T>\n    std::vector<T> distinct(int size, T from, T to) {\n        if (from\
    \ > to)\n            __testlib_fail(\"random_t::distinct expected from <= to\"\
    );\n\n        if (size < 0)\n            __testlib_fail(\"random_t::distinct expected\
    \ size >= 0\");\n\n        uint64_t n = to - from + 1;\n        if (uint64_t(size)\
    \ > n)\n            __testlib_fail(\"random_t::distinct expected size <= to -\
    \ from + 1\");\n\n        std::vector<T> result;\n        if (size == 0)\n   \
    \         return result;\n\n        double expected = 0.0;\n        for (int i\
    \ = 1; i <= size; i++)\n            expected += double(n) / double(n - i + 1);\n\
    \        \n        if (expected < double(n)) {\n            std::set<T> vals;\n\
    \            while (int(vals.size()) < size)\n                vals.insert(T(next(from,\
    \ to)));\n            result.insert(result.end(), vals.begin(), vals.end());\n\
    \        } else {\n            if (n > 1000000000)\n                __testlib_fail(\"\
    random_t::distinct here expected to - from + 1 <= 1000000000\");\n           \
    \ std::vector<T> p(perm(int(n), from));\n            result.insert(result.end(),\
    \ p.begin(), p.begin() + size);\n        }\n\n        return result;\n    }\n\n\
    \    /* Returns `size` unordered (unsorted) distinct numbers between `0` and `upper`-1.\
    \ */\n    template<typename T>\n    std::vector<T> distinct(int size, T upper)\
    \ {\n        if (size < 0)\n            __testlib_fail(\"random_t::distinct expected\
    \ size >= 0\");\n        if (size == 0)\n            return std::vector<T>();\n\
    \        \n        if (upper <= 0)\n            __testlib_fail(\"random_t::distinct\
    \ expected upper > 0\");\n        if (size > upper)\n            __testlib_fail(\"\
    random_t::distinct expected size <= upper\");\n            \n        return distinct(size,\
    \ T(0), upper - 1);\n    }\n\n    /* Returns random (unsorted) partition which\
    \ is a representation of sum as a sum of integers not less than min_part. */\n\
    \    template<typename T>\n    std::vector<T> partition(int size, T sum, T min_part)\
    \ {\n        if (size < 0)\n            __testlib_fail(\"random_t::partition:\
    \ size < 0\");\n        if (size == 0 && sum != 0)\n            __testlib_fail(\"\
    random_t::partition: size == 0 && sum != 0\");\n        if (min_part * size >\
    \ sum)\n            __testlib_fail(\"random_t::partition: min_part * size > sum\"\
    );\n\n        T sum_ = sum;\n        sum -= min_part * size;\n\n        std::vector<T>\
    \ septums(size);\n        std::vector<T> d = distinct(size - 1, T(1), T(sum +\
    \ size - 1));\n        for (int i = 0; i + 1 < size; i++)\n            septums[i\
    \ + 1] = d[i];\n        sort(septums.begin(), septums.end());\n\n        std::vector<T>\
    \ result(size);\n        for (int i = 0; i + 1 < size; i++)\n            result[i]\
    \ = septums[i + 1] - septums[i] - 1;\n        result[size - 1] = sum + size -\
    \ 1 - septums.back();\n\n        for (std::size_t i = 0; i < result.size(); i++)\n\
    \            result[i] += min_part;\n        \n        T result_sum = 0;\n   \
    \     for (std::size_t i = 0; i < result.size(); i++)\n            result_sum\
    \ += result[i];\n        if (result_sum != sum_)\n            __testlib_fail(\"\
    random_t::partition: partition sum is expeced to be the given sum\");\n      \
    \  \n        if (*std::min_element(result.begin(), result.end()) < min_part)\n\
    \            __testlib_fail(\"random_t::partition: partition min is expeced to\
    \ be to less than the given min_part\");\n        \n        if (int(result.size())\
    \ != size || result.size() != (size_t) size)\n            __testlib_fail(\"random_t::partition:\
    \ partition size is expected to be equal to the given size\");\n        \n   \
    \     return result;\n    }\n\n    /* Returns random (unsorted) partition which\
    \ is a representation of sum as a sum of positive integers. */\n    template<typename\
    \ T>\n    std::vector<T> partition(int size, T sum) {\n        return partition(size,\
    \ sum, T(1));\n    }\n};\n\nconst int random_t::lim = 25;\nconst unsigned long\
    \ long random_t::multiplier = 0x5DEECE66DLL;\nconst unsigned long long random_t::addend\
    \ = 0xBLL;\nconst unsigned long long random_t::mask = (1LL << 48) - 1;\nint random_t::version\
    \ = -1;\n\n/* Pattern implementation */\nbool pattern::matches(const std::string\
    \ &s) const {\n    return matches(s, 0);\n}\n\nstatic bool __pattern_isSlash(const\
    \ std::string &s, size_t pos) {\n    return s[pos] == '\\\\';\n}\n\n#ifdef __GNUC__\n\
    __attribute__((pure))\n#endif\nstatic bool __pattern_isCommandChar(const std::string\
    \ &s, size_t pos, char value) {\n    if (pos >= s.length())\n        return false;\n\
    \n    int slashes = 0;\n\n    int before = int(pos) - 1;\n    while (before >=\
    \ 0 && s[before] == '\\\\')\n        before--, slashes++;\n\n    return slashes\
    \ % 2 == 0 && s[pos] == value;\n}\n\nstatic char __pattern_getChar(const std::string\
    \ &s, size_t &pos) {\n    if (__pattern_isSlash(s, pos))\n        pos += 2;\n\
    \    else\n        pos++;\n\n    return s[pos - 1];\n}\n\n#ifdef __GNUC__\n__attribute__((pure))\n\
    #endif\nstatic int __pattern_greedyMatch(const std::string &s, size_t pos, const\
    \ std::vector<char> chars) {\n    int result = 0;\n\n    while (pos < s.length())\
    \ {\n        char c = s[pos++];\n        if (!std::binary_search(chars.begin(),\
    \ chars.end(), c))\n            break;\n        else\n            result++;\n\
    \    }\n\n    return result;\n}\n\nstd::string pattern::src() const {\n    return\
    \ s;\n}\n\nbool pattern::matches(const std::string &s, size_t pos) const {\n \
    \   std::string result;\n\n    if (to > 0) {\n        int size = __pattern_greedyMatch(s,\
    \ pos, chars);\n        if (size < from)\n            return false;\n        if\
    \ (size > to)\n            size = to;\n        pos += size;\n    }\n\n    if (children.size()\
    \ > 0) {\n        for (size_t child = 0; child < children.size(); child++)\n \
    \           if (children[child].matches(s, pos))\n                return true;\n\
    \        return false;\n    } else\n        return pos == s.length();\n}\n\nstd::string\
    \ pattern::next(random_t &rnd) const {\n    std::string result;\n    result.reserve(20);\n\
    \n    if (to == INT_MAX)\n        __testlib_fail(\"pattern::next(random_t& rnd):\
    \ can't process character '*' for generation\");\n\n    if (to > 0) {\n      \
    \  int count = rnd.next(to - from + 1) + from;\n        for (int i = 0; i < count;\
    \ i++)\n            result += chars[rnd.next(int(chars.size()))];\n    }\n\n \
    \   if (children.size() > 0) {\n        int child = rnd.next(int(children.size()));\n\
    \        result += children[child].next(rnd);\n    }\n\n    return result;\n}\n\
    \nstatic void __pattern_scanCounts(const std::string &s, size_t &pos, int &from,\
    \ int &to) {\n    if (pos >= s.length()) {\n        from = to = 1;\n        return;\n\
    \    }\n\n    if (__pattern_isCommandChar(s, pos, '{')) {\n        std::vector<std::string>\
    \ parts;\n        std::string part;\n\n        pos++;\n\n        while (pos <\
    \ s.length() && !__pattern_isCommandChar(s, pos, '}')) {\n            if (__pattern_isCommandChar(s,\
    \ pos, ','))\n                parts.push_back(part), part = \"\", pos++;\n   \
    \         else\n                part += __pattern_getChar(s, pos);\n        }\n\
    \n        if (part != \"\")\n            parts.push_back(part);\n\n        if\
    \ (!__pattern_isCommandChar(s, pos, '}'))\n            __testlib_fail(\"pattern:\
    \ Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n        pos++;\n\n    \
    \    if (parts.size() < 1 || parts.size() > 2)\n            __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n        std::vector<int>\
    \ numbers;\n\n        for (size_t i = 0; i < parts.size(); i++) {\n          \
    \  if (parts[i].length() == 0)\n                __testlib_fail(\"pattern: Illegal\
    \ pattern (or part) \\\"\" + s + \"\\\"\");\n            int number;\n       \
    \     if (std::sscanf(parts[i].c_str(), \"%d\", &number) != 1)\n             \
    \   __testlib_fail(\"pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\"\
    );\n            numbers.push_back(number);\n        }\n\n        if (numbers.size()\
    \ == 1)\n            from = to = numbers[0];\n        else\n            from =\
    \ numbers[0], to = numbers[1];\n\n        if (from > to)\n            __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n    } else {\n   \
    \     if (__pattern_isCommandChar(s, pos, '?')) {\n            from = 0, to =\
    \ 1, pos++;\n            return;\n        }\n\n        if (__pattern_isCommandChar(s,\
    \ pos, '*')) {\n            from = 0, to = INT_MAX, pos++;\n            return;\n\
    \        }\n\n        if (__pattern_isCommandChar(s, pos, '+')) {\n          \
    \  from = 1, to = INT_MAX, pos++;\n            return;\n        }\n\n        from\
    \ = to = 1;\n    }\n}\n\nstatic std::vector<char> __pattern_scanCharSet(const\
    \ std::string &s, size_t &pos) {\n    if (pos >= s.length())\n        __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n    std::vector<char>\
    \ result;\n\n    if (__pattern_isCommandChar(s, pos, '[')) {\n        pos++;\n\
    \        bool negative = __pattern_isCommandChar(s, pos, '^');\n        if (negative)\n\
    \            pos++;\n\n        char prev = 0;\n\n        while (pos < s.length()\
    \ && !__pattern_isCommandChar(s, pos, ']')) {\n            if (__pattern_isCommandChar(s,\
    \ pos, '-') && prev != 0) {\n                pos++;\n\n                if (pos\
    \ + 1 == s.length() || __pattern_isCommandChar(s, pos, ']')) {\n             \
    \       result.push_back(prev);\n                    prev = '-';\n           \
    \         continue;\n                }\n\n                char next = __pattern_getChar(s,\
    \ pos);\n                if (prev > next)\n                    __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n               \
    \ for (char c = prev; c != next; c++)\n                    result.push_back(c);\n\
    \                result.push_back(next);\n\n                prev = 0;\n      \
    \      } else {\n                if (prev != 0)\n                    result.push_back(prev);\n\
    \                prev = __pattern_getChar(s, pos);\n            }\n        }\n\
    \n        if (prev != 0)\n            result.push_back(prev);\n\n        if (!__pattern_isCommandChar(s,\
    \ pos, ']'))\n            __testlib_fail(\"pattern: Illegal pattern (or part)\
    \ \\\"\" + s + \"\\\"\");\n\n        pos++;\n\n        if (negative) {\n     \
    \       std::sort(result.begin(), result.end());\n            std::vector<char>\
    \ actuals;\n            for (int code = 0; code < 255; code++) {\n           \
    \     char c = char(code);\n                if (!std::binary_search(result.begin(),\
    \ result.end(), c))\n                    actuals.push_back(c);\n            }\n\
    \            result = actuals;\n        }\n\n        std::sort(result.begin(),\
    \ result.end());\n    } else\n        result.push_back(__pattern_getChar(s, pos));\n\
    \n    return result;\n}\n\npattern::pattern(std::string s) : s(s), from(0), to(0)\
    \ {\n    std::string t;\n    for (size_t i = 0; i < s.length(); i++)\n       \
    \ if (!__pattern_isCommandChar(s, i, ' '))\n            t += s[i];\n    s = t;\n\
    \n    int opened = 0;\n    int firstClose = -1;\n    std::vector<int> seps;\n\n\
    \    for (size_t i = 0; i < s.length(); i++) {\n        if (__pattern_isCommandChar(s,\
    \ i, '(')) {\n            opened++;\n            continue;\n        }\n\n    \
    \    if (__pattern_isCommandChar(s, i, ')')) {\n            opened--;\n      \
    \      if (opened == 0 && firstClose == -1)\n                firstClose = int(i);\n\
    \            continue;\n        }\n\n        if (opened < 0)\n            __testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n        if (__pattern_isCommandChar(s,\
    \ i, '|') && opened == 0)\n            seps.push_back(int(i));\n    }\n\n    if\
    \ (opened != 0)\n        __testlib_fail(\"pattern: Illegal pattern (or part) \\\
    \"\" + s + \"\\\"\");\n\n    if (seps.size() == 0 && firstClose + 1 == (int) s.length()\n\
    \        && __pattern_isCommandChar(s, 0, '(') && __pattern_isCommandChar(s, s.length()\
    \ - 1, ')')) {\n        children.push_back(pattern(s.substr(1, s.length() - 2)));\n\
    \    } else {\n        if (seps.size() > 0) {\n            seps.push_back(int(s.length()));\n\
    \            int last = 0;\n\n            for (size_t i = 0; i < seps.size();\
    \ i++) {\n                children.push_back(pattern(s.substr(last, seps[i] -\
    \ last)));\n                last = seps[i] + 1;\n            }\n        } else\
    \ {\n            size_t pos = 0;\n            chars = __pattern_scanCharSet(s,\
    \ pos);\n            __pattern_scanCounts(s, pos, from, to);\n            if (pos\
    \ < s.length())\n                children.push_back(pattern(s.substr(pos)));\n\
    \        }\n    }\n}\n\n/* End of pattern implementation */\n\ntemplate<typename\
    \ C>\ninline bool isEof(C c) {\n    return c == EOFC;\n}\n\ntemplate<typename\
    \ C>\ninline bool isEoln(C c) {\n    return (c == LF || c == CR);\n}\n\ntemplate<typename\
    \ C>\ninline bool isBlanks(C c) {\n    return (c == LF || c == CR || c == SPACE\
    \ || c == TAB);\n}\n\ninline std::string trim(const std::string &s) {\n    if\
    \ (s.empty())\n        return s;\n\n    int left = 0;\n    while (left < int(s.length())\
    \ && isBlanks(s[left]))\n        left++;\n    if (left >= int(s.length()))\n \
    \       return \"\";\n\n    int right = int(s.length()) - 1;\n    while (right\
    \ >= 0 && isBlanks(s[right]))\n        right--;\n    if (right < 0)\n        return\
    \ \"\";\n\n    return s.substr(left, right - left + 1);\n}\n\nenum TMode {\n \
    \   _input, _output, _answer\n};\n\n/* Outcomes 6-15 are reserved for future use.\
    \ */\nenum TResult {\n    _ok = 0,\n    _wa = 1,\n    _pe = 2,\n    _fail = 3,\n\
    \    _dirt = 4,\n    _points = 5,\n    _unexpected_eof = 8,\n    _partially =\
    \ 16\n};\n\nenum TTestlibMode {\n    _unknown, _checker, _validator, _generator,\
    \ _interactor\n};\n\n#define _pc(exitCode) (TResult(_partially + (exitCode)))\n\
    \n/* Outcomes 6-15 are reserved for future use. */\nconst std::string outcomes[]\
    \ = {\n        \"accepted\",\n        \"wrong-answer\",\n        \"presentation-error\"\
    ,\n        \"fail\",\n        \"fail\",\n#ifndef PCMS2\n        \"points\",\n\
    #else\n        \"relative-scoring\",\n#endif\n        \"reserved\",\n        \"\
    reserved\",\n        \"unexpected-eof\",\n        \"reserved\",\n        \"reserved\"\
    ,\n        \"reserved\",\n        \"reserved\",\n        \"reserved\",\n     \
    \   \"reserved\",\n        \"reserved\",\n        \"partially-correct\"\n};\n\n\
    class InputStreamReader {\npublic:\n    virtual int curChar() = 0;\n\n    virtual\
    \ int nextChar() = 0;\n\n    virtual void skipChar() = 0;\n\n    virtual void\
    \ unreadChar(int c) = 0;\n\n    virtual std::string getName() = 0;\n\n    virtual\
    \ bool eof() = 0;\n\n    virtual void close() = 0;\n\n    virtual int getLine()\
    \ = 0;\n\n    virtual ~InputStreamReader() = 0;\n};\n\nInputStreamReader::~InputStreamReader()\
    \ {\n    // No operations.\n}\n\nclass StringInputStreamReader : public InputStreamReader\
    \ {\nprivate:\n    std::string s;\n    size_t pos;\n\npublic:\n    StringInputStreamReader(const\
    \ std::string &content) : s(content), pos(0) {\n        // No operations.\n  \
    \  }\n\n    int curChar() {\n        if (pos >= s.length())\n            return\
    \ EOFC;\n        else\n            return s[pos];\n    }\n\n    int nextChar()\
    \ {\n        if (pos >= s.length()) {\n            pos++;\n            return\
    \ EOFC;\n        } else\n            return s[pos++];\n    }\n\n    void skipChar()\
    \ {\n        pos++;\n    }\n\n    void unreadChar(int c) {\n        if (pos ==\
    \ 0)\n            __testlib_fail(\"FileFileInputStreamReader::unreadChar(int):\
    \ pos == 0.\");\n        pos--;\n        if (pos < s.length())\n            s[pos]\
    \ = char(c);\n    }\n\n    std::string getName() {\n        return __testlib_part(s);\n\
    \    }\n\n    int getLine() {\n        return -1;\n    }\n\n    bool eof() {\n\
    \        return pos >= s.length();\n    }\n\n    void close() {\n        // No\
    \ operations.\n    }\n};\n\nclass FileInputStreamReader : public InputStreamReader\
    \ {\nprivate:\n    std::FILE *file;\n    std::string name;\n    int line;\n  \
    \  std::vector<int> undoChars;\n\n    inline int postprocessGetc(int getcResult)\
    \ {\n        if (getcResult != EOF)\n            return getcResult;\n        else\n\
    \            return EOFC;\n    }\n\n    int getc(FILE *file) {\n        int c;\n\
    \        if (undoChars.empty())\n            c = ::getc(file);\n        else {\n\
    \            c = undoChars.back();\n            undoChars.pop_back();\n      \
    \  }\n\n        if (c == LF)\n            line++;\n        return c;\n    }\n\n\
    \    int ungetc(int c/*, FILE* file*/) {\n        if (c == LF)\n            line--;\n\
    \        undoChars.push_back(c);\n        return c;\n    }\n\npublic:\n    FileInputStreamReader(std::FILE\
    \ *file, const std::string &name) : file(file), name(name), line(1) {\n      \
    \  // No operations.\n    }\n\n    int curChar() {\n        if (feof(file))\n\
    \            return EOFC;\n        else {\n            int c = getc(file);\n \
    \           ungetc(c/*, file*/);\n            return postprocessGetc(c);\n   \
    \     }\n    }\n\n    int nextChar() {\n        if (feof(file))\n            return\
    \ EOFC;\n        else\n            return postprocessGetc(getc(file));\n    }\n\
    \n    void skipChar() {\n        getc(file);\n    }\n\n    void unreadChar(int\
    \ c) {\n        ungetc(c/*, file*/);\n    }\n\n    std::string getName() {\n \
    \       return name;\n    }\n\n    int getLine() {\n        return line;\n   \
    \ }\n\n    bool eof() {\n        if (NULL == file || feof(file))\n           \
    \ return true;\n        else {\n            int c = nextChar();\n            if\
    \ (c == EOFC || (c == EOF && feof(file)))\n                return true;\n    \
    \        unreadChar(c);\n            return false;\n        }\n    }\n\n    void\
    \ close() {\n        if (NULL != file) {\n            fclose(file);\n        \
    \    file = NULL;\n        }\n    }\n};\n\nclass BufferedFileInputStreamReader\
    \ : public InputStreamReader {\nprivate:\n    static const size_t BUFFER_SIZE;\n\
    \    static const size_t MAX_UNREAD_COUNT;\n\n    std::FILE *file;\n    char *buffer;\n\
    \    bool *isEof;\n    int bufferPos;\n    size_t bufferSize;\n\n    std::string\
    \ name;\n    int line;\n\n    bool refill() {\n        if (NULL == file)\n   \
    \         __testlib_fail(\"BufferedFileInputStreamReader: file == NULL (\" + getName()\
    \ + \")\");\n\n        if (bufferPos >= int(bufferSize)) {\n            size_t\
    \ readSize = fread(\n                    buffer + MAX_UNREAD_COUNT,\n        \
    \            1,\n                    BUFFER_SIZE - MAX_UNREAD_COUNT,\n       \
    \             file\n            );\n\n            if (readSize < BUFFER_SIZE -\
    \ MAX_UNREAD_COUNT\n                && ferror(file))\n                __testlib_fail(\"\
    BufferedFileInputStreamReader: unable to read (\" + getName() + \")\");\n\n  \
    \          bufferSize = MAX_UNREAD_COUNT + readSize;\n            bufferPos =\
    \ int(MAX_UNREAD_COUNT);\n            std::memset(isEof + MAX_UNREAD_COUNT, 0,\
    \ sizeof(isEof[0]) * readSize);\n\n            return readSize > 0;\n        }\
    \ else\n            return true;\n    }\n\n    char increment() {\n        char\
    \ c;\n        if ((c = buffer[bufferPos++]) == LF)\n            line++;\n    \
    \    return c;\n    }\n\npublic:\n    BufferedFileInputStreamReader(std::FILE\
    \ *file, const std::string &name) : file(file), name(name), line(1) {\n      \
    \  buffer = new char[BUFFER_SIZE];\n        isEof = new bool[BUFFER_SIZE];\n \
    \       bufferSize = MAX_UNREAD_COUNT;\n        bufferPos = int(MAX_UNREAD_COUNT);\n\
    \    }\n\n    ~BufferedFileInputStreamReader() {\n        if (NULL != buffer)\
    \ {\n            delete[] buffer;\n            buffer = NULL;\n        }\n   \
    \     if (NULL != isEof) {\n            delete[] isEof;\n            isEof = NULL;\n\
    \        }\n    }\n\n    int curChar() {\n        if (!refill())\n           \
    \ return EOFC;\n\n        return isEof[bufferPos] ? EOFC : buffer[bufferPos];\n\
    \    }\n\n    int nextChar() {\n        if (!refill())\n            return EOFC;\n\
    \n        return isEof[bufferPos] ? EOFC : increment();\n    }\n\n    void skipChar()\
    \ {\n        increment();\n    }\n\n    void unreadChar(int c) {\n        bufferPos--;\n\
    \        if (bufferPos < 0)\n            __testlib_fail(\"BufferedFileInputStreamReader::unreadChar(int):\
    \ bufferPos < 0\");\n        isEof[bufferPos] = (c == EOFC);\n        buffer[bufferPos]\
    \ = char(c);\n        if (c == LF)\n            line--;\n    }\n\n    std::string\
    \ getName() {\n        return name;\n    }\n\n    int getLine() {\n        return\
    \ line;\n    }\n\n    bool eof() {\n        return !refill() || EOFC == curChar();\n\
    \    }\n\n    void close() {\n        if (NULL != file) {\n            fclose(file);\n\
    \            file = NULL;\n        }\n    }\n};\n\nconst size_t BufferedFileInputStreamReader::BUFFER_SIZE\
    \ = 2000000;\nconst size_t BufferedFileInputStreamReader::MAX_UNREAD_COUNT = BufferedFileInputStreamReader::BUFFER_SIZE\
    \ / 2;\n\n/*\n * Streams to be used for reading data in checkers or validators.\n\
    \ * Each read*() method moves pointer to the next character after the\n * read\
    \ value.\n */\nstruct InStream {\n    /* Do not use them. */\n    InStream();\n\
    \n    ~InStream();\n\n    /* Wrap std::string with InStream. */\n    InStream(const\
    \ InStream &baseStream, std::string content);\n\n    InputStreamReader *reader;\n\
    \    int lastLine;\n\n    std::string name;\n    TMode mode;\n    bool opened;\n\
    \    bool stdfile;\n    bool strict;\n\n    std::string _tmpReadToken;\n\n   \
    \ int readManyIteration;\n    size_t maxFileSize;\n    size_t maxTokenLength;\n\
    \    size_t maxMessageLength;\n\n    void init(std::string fileName, TMode mode);\n\
    \n    void init(std::FILE *f, TMode mode);\n\n    /* Moves stream pointer to the\
    \ first non-white-space character or EOF. */\n    void skipBlanks();\n\n    /*\
    \ Returns current character in the stream. Doesn't remove it from stream. */\n\
    \    char curChar();\n\n    /* Moves stream pointer one character forward. */\n\
    \    void skipChar();\n\n    /* Returns current character and moves pointer one\
    \ character forward. */\n    char nextChar();\n\n    /* Returns current character\
    \ and moves pointer one character forward. */\n    char readChar();\n\n    /*\
    \ As \"readChar()\" but ensures that the result is equal to given parameter. */\n\
    \    char readChar(char c);\n\n    /* As \"readChar()\" but ensures that the result\
    \ is equal to the space (code=32). */\n    char readSpace();\n\n    /* Puts back\
    \ the character into the stream. */\n    void unreadChar(char c);\n\n    /* Reopens\
    \ stream, you should not use it. */\n    void reset(std::FILE *file = NULL);\n\
    \n    /* Checks that current position is EOF. If not it doesn't move stream pointer.\
    \ */\n    bool eof();\n\n    /* Moves pointer to the first non-white-space character\
    \ and calls \"eof()\". */\n    bool seekEof();\n\n    /* \n     * Checks that\
    \ current position contains EOLN. \n     * If not it doesn't move stream pointer.\
    \ \n     * In strict mode expects \"#13#10\" for windows or \"#10\" for other\
    \ platforms.\n     */\n    bool eoln();\n\n    /* Moves pointer to the first non-space\
    \ and non-tab character and calls \"eoln()\". */\n    bool seekEoln();\n\n   \
    \ /* Moves stream pointer to the first character of the next line (if exists).\
    \ */\n    void nextLine();\n\n    /* \n     * Reads new token. Ignores white-spaces\
    \ into the non-strict mode \n     * (strict mode is used in validators usually).\
    \ \n     */\n    std::string readWord();\n\n    /* The same as \"readWord()\"\
    , it is preffered to use \"readToken()\". */\n    std::string readToken();\n\n\
    \    /* The same as \"readWord()\", but ensures that token matches to given pattern.\
    \ */\n    std::string readWord(const std::string &ptrn, const std::string &variableName\
    \ = \"\");\n\n    std::string readWord(const pattern &p, const std::string &variableName\
    \ = \"\");\n\n    std::vector<std::string>\n    readWords(int size, const std::string\
    \ &ptrn, const std::string &variablesName = \"\", int indexBase = 1);\n\n    std::vector<std::string>\n\
    \    readWords(int size, const pattern &p, const std::string &variablesName =\
    \ \"\", int indexBase = 1);\n\n    std::vector<std::string> readWords(int size,\
    \ int indexBase = 1);\n\n    /* The same as \"readToken()\", but ensures that\
    \ token matches to given pattern. */\n    std::string readToken(const std::string\
    \ &ptrn, const std::string &variableName = \"\");\n\n    std::string readToken(const\
    \ pattern &p, const std::string &variableName = \"\");\n\n    std::vector<std::string>\n\
    \    readTokens(int size, const std::string &ptrn, const std::string &variablesName\
    \ = \"\", int indexBase = 1);\n\n    std::vector<std::string>\n    readTokens(int\
    \ size, const pattern &p, const std::string &variablesName = \"\", int indexBase\
    \ = 1);\n\n    std::vector<std::string> readTokens(int size, int indexBase = 1);\n\
    \n    void readWordTo(std::string &result);\n\n    void readWordTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n    void\
    \ readWordTo(std::string &result, const std::string &ptrn, const std::string &variableName\
    \ = \"\");\n\n    void readTokenTo(std::string &result);\n\n    void readTokenTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n    void\
    \ readTokenTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName = \"\");\n\n    /* \n     * Reads new long long value. Ignores\
    \ white-spaces into the non-strict mode \n     * (strict mode is used in validators\
    \ usually). \n     */\n    long long readLong();\n\n    unsigned long long readUnsignedLong();\n\
    \n    /*\n     * Reads new int. Ignores white-spaces into the non-strict mode\
    \ \n     * (strict mode is used in validators usually). \n     */\n    int readInteger();\n\
    \n    /*\n     * Reads new int. Ignores white-spaces into the non-strict mode\
    \ \n     * (strict mode is used in validators usually). \n     */\n    int readInt();\n\
    \n    /* As \"readLong()\" but ensures that value in the range [minv,maxv]. */\n\
    \    long long readLong(long long minv, long long maxv, const std::string &variableName\
    \ = \"\");\n\n    /* Reads space-separated sequence of long longs. */\n    std::vector<long\
    \ long>\n    readLongs(int size, long long minv, long long maxv, const std::string\
    \ &variablesName = \"\", int indexBase = 1);\n\n    /* Reads space-separated sequence\
    \ of long longs. */\n    std::vector<long long> readLongs(int size, int indexBase\
    \ = 1);\n\n    unsigned long long\n    readUnsignedLong(unsigned long long minv,\
    \ unsigned long long maxv, const std::string &variableName = \"\");\n\n    std::vector<unsigned\
    \ long long>\n    readUnsignedLongs(int size, unsigned long long minv, unsigned\
    \ long long maxv, const std::string &variablesName = \"\",\n                 \
    \     int indexBase = 1);\n\n    std::vector<unsigned long long> readUnsignedLongs(int\
    \ size, int indexBase = 1);\n\n    unsigned long long readLong(unsigned long long\
    \ minv, unsigned long long maxv, const std::string &variableName = \"\");\n\n\
    \    std::vector<unsigned long long>\n    readLongs(int size, unsigned long long\
    \ minv, unsigned long long maxv, const std::string &variablesName = \"\",\n  \
    \            int indexBase = 1);\n\n    /* As \"readInteger()\" but ensures that\
    \ value in the range [minv,maxv]. */\n    int readInteger(int minv, int maxv,\
    \ const std::string &variableName = \"\");\n\n    /* As \"readInt()\" but ensures\
    \ that value in the range [minv,maxv]. */\n    int readInt(int minv, int maxv,\
    \ const std::string &variableName = \"\");\n\n    /* Reads space-separated sequence\
    \ of integers. */\n    std::vector<int>\n    readIntegers(int size, int minv,\
    \ int maxv, const std::string &variablesName = \"\", int indexBase = 1);\n\n \
    \   /* Reads space-separated sequence of integers. */\n    std::vector<int> readIntegers(int\
    \ size, int indexBase = 1);\n\n    /* Reads space-separated sequence of integers.\
    \ */\n    std::vector<int> readInts(int size, int minv, int maxv, const std::string\
    \ &variablesName = \"\", int indexBase = 1);\n\n    /* Reads space-separated sequence\
    \ of integers. */\n    std::vector<int> readInts(int size, int indexBase = 1);\n\
    \n    /* \n     * Reads new double. Ignores white-spaces into the non-strict mode\
    \ \n     * (strict mode is used in validators usually). \n     */\n    double\
    \ readReal();\n\n    /*\n     * Reads new double. Ignores white-spaces into the\
    \ non-strict mode \n     * (strict mode is used in validators usually). \n   \
    \  */\n    double readDouble();\n\n    /* As \"readReal()\" but ensures that value\
    \ in the range [minv,maxv]. */\n    double readReal(double minv, double maxv,\
    \ const std::string &variableName = \"\");\n\n    std::vector<double>\n    readReals(int\
    \ size, double minv, double maxv, const std::string &variablesName = \"\", int\
    \ indexBase = 1);\n\n    std::vector<double> readReals(int size, int indexBase\
    \ = 1);\n\n    /* As \"readDouble()\" but ensures that value in the range [minv,maxv].\
    \ */\n    double readDouble(double minv, double maxv, const std::string &variableName\
    \ = \"\");\n\n    std::vector<double>\n    readDoubles(int size, double minv,\
    \ double maxv, const std::string &variablesName = \"\", int indexBase = 1);\n\n\
    \    std::vector<double> readDoubles(int size, int indexBase = 1);\n\n    /* \n\
    \     * As \"readReal()\" but ensures that value in the range [minv,maxv] and\n\
    \     * number of digit after the decimal point is in range [minAfterPointDigitCount,maxAfterPointDigitCount]\n\
    \     * and number is in the form \"[-]digit(s)[.digit(s)]\".\n     */\n    double\
    \ readStrictReal(double minv, double maxv,\n                          int minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n                          const std::string &variableName\
    \ = \"\");\n\n    std::vector<double> readStrictReals(int size, double minv, double\
    \ maxv,\n                                        int minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n                                        const\
    \ std::string &variablesName = \"\", int indexBase = 1);\n\n    /* \n     * As\
    \ \"readDouble()\" but ensures that value in the range [minv,maxv] and\n     *\
    \ number of digit after the decimal point is in range [minAfterPointDigitCount,maxAfterPointDigitCount]\n\
    \     * and number is in the form \"[-]digit(s)[.digit(s)]\".\n     */\n    double\
    \ readStrictDouble(double minv, double maxv,\n                            int\
    \ minAfterPointDigitCount, int maxAfterPointDigitCount,\n                    \
    \        const std::string &variableName = \"\");\n\n    std::vector<double> readStrictDoubles(int\
    \ size, double minv, double maxv,\n                                          int\
    \ minAfterPointDigitCount, int maxAfterPointDigitCount,\n                    \
    \                      const std::string &variablesName = \"\", int indexBase\
    \ = 1);\n\n    /* As readLine(). */\n    std::string readString();\n\n    /* Read\
    \ many lines. */\n    std::vector<std::string> readStrings(int size, int indexBase\
    \ = 1);\n\n    /* See readLine(). */\n    void readStringTo(std::string &result);\n\
    \n    /* The same as \"readLine()/readString()\", but ensures that line matches\
    \ to the given pattern. */\n    std::string readString(const pattern &p, const\
    \ std::string &variableName = \"\");\n\n    /* The same as \"readLine()/readString()\"\
    , but ensures that line matches to the given pattern. */\n    std::string readString(const\
    \ std::string &ptrn, const std::string &variableName = \"\");\n\n    /* Read many\
    \ lines. */\n    std::vector<std::string>\n    readStrings(int size, const pattern\
    \ &p, const std::string &variableName = \"\", int indexBase = 1);\n\n    /* Read\
    \ many lines. */\n    std::vector<std::string>\n    readStrings(int size, const\
    \ std::string &ptrn, const std::string &variableName = \"\", int indexBase = 1);\n\
    \n    /* The same as \"readLine()/readString()\", but ensures that line matches\
    \ to the given pattern. */\n    void readStringTo(std::string &result, const pattern\
    \ &p, const std::string &variableName = \"\");\n\n    /* The same as \"readLine()/readString()\"\
    , but ensures that line matches to the given pattern. */\n    void readStringTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName = \"\");\n\
    \n    /* \n     * Reads line from the current position to EOLN or EOF. Moves stream\
    \ pointer to \n     * the first character of the new line (if possible). \n  \
    \   */\n    std::string readLine();\n\n    /* Read many lines. */\n    std::vector<std::string>\
    \ readLines(int size, int indexBase = 1);\n\n    /* See readLine(). */\n    void\
    \ readLineTo(std::string &result);\n\n    /* The same as \"readLine()\", but ensures\
    \ that line matches to the given pattern. */\n    std::string readLine(const pattern\
    \ &p, const std::string &variableName = \"\");\n\n    /* The same as \"readLine()\"\
    , but ensures that line matches to the given pattern. */\n    std::string readLine(const\
    \ std::string &ptrn, const std::string &variableName = \"\");\n\n    /* Read many\
    \ lines. */\n    std::vector<std::string>\n    readLines(int size, const pattern\
    \ &p, const std::string &variableName = \"\", int indexBase = 1);\n\n    /* Read\
    \ many lines. */\n    std::vector<std::string>\n    readLines(int size, const\
    \ std::string &ptrn, const std::string &variableName = \"\", int indexBase = 1);\n\
    \n    /* The same as \"readLine()\", but ensures that line matches to the given\
    \ pattern. */\n    void readLineTo(std::string &result, const pattern &p, const\
    \ std::string &variableName = \"\");\n\n    /* The same as \"readLine()\", but\
    \ ensures that line matches to the given pattern. */\n    void readLineTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName = \"\");\n\
    \n    /* Reads EOLN or fails. Use it in validators. Calls \"eoln()\" method internally.\
    \ */\n    void readEoln();\n\n    /* Reads EOF or fails. Use it in validators.\
    \ Calls \"eof()\" method internally. */\n    void readEof();\n\n    /* \n    \
    \ * Quit-functions aborts program with <result> and <message>:\n     * input/answer\
    \ streams replace any result to FAIL.\n     */\n    NORETURN void quit(TResult\
    \ result, const char *msg);\n    /* \n     * Quit-functions aborts program with\
    \ <result> and <message>:\n     * input/answer streams replace any result to FAIL.\n\
    \     */\n    NORETURN void quitf(TResult result, const char *msg, ...);\n\n \
    \   /*\n     * Quit-functions aborts program with <result> and <message>:\n  \
    \   * input/answer streams replace any result to FAIL.\n     */\n    void quitif(bool\
    \ condition, TResult result, const char *msg, ...);\n    /* \n     * Quit-functions\
    \ aborts program with <result> and <message>:\n     * input/answer streams replace\
    \ any result to FAIL.\n     */\n    NORETURN void quits(TResult result, std::string\
    \ msg);\n\n    /* \n     * Checks condition and aborts a program if codition is\
    \ false.\n     * Returns _wa for ouf and _fail on any other streams.\n     */\n\
    #ifdef __GNUC__\n    __attribute__ ((format (printf, 3, 4)))\n#endif\n    void\
    \ ensuref(bool cond, const char *format, ...);\n\n    void __testlib_ensure(bool\
    \ cond, std::string message);\n\n    void close();\n\n    const static int NO_INDEX\
    \ = INT_MAX;\n    const static char OPEN_BRACKET = char(11);\n    const static\
    \ char CLOSE_BRACKET = char(17);\n\n    const static WORD LightGray = 0x07;\n\
    \    const static WORD LightRed = 0x0c;\n    const static WORD LightCyan = 0x0b;\n\
    \    const static WORD LightGreen = 0x0a;\n    const static WORD LightYellow =\
    \ 0x0e;\n\n    static void textColor(WORD color);\n\n    static void quitscr(WORD\
    \ color, const char *msg);\n\n    static void quitscrS(WORD color, std::string\
    \ msg);\n\n    void xmlSafeWrite(std::FILE *file, const char *msg);\n\nprivate:\n\
    \    InStream(const InStream &);\n\n    InStream &operator=(const InStream &);\n\
    };\n\nInStream inf;\nInStream ouf;\nInStream ans;\nbool appesMode;\nstd::string\
    \ resultName;\nstd::string checkerName = \"untitled checker\";\nrandom_t rnd;\n\
    TTestlibMode testlibMode = _unknown;\ndouble __testlib_points = std::numeric_limits<float>::infinity();\n\
    \nstruct ValidatorBoundsHit {\n    static const double EPS;\n    bool minHit;\n\
    \    bool maxHit;\n\n    ValidatorBoundsHit(bool minHit = false, bool maxHit =\
    \ false) : minHit(minHit), maxHit(maxHit) {\n    };\n\n    ValidatorBoundsHit\
    \ merge(const ValidatorBoundsHit &validatorBoundsHit) {\n        return ValidatorBoundsHit(\n\
    \                __testlib_max(minHit, validatorBoundsHit.minHit),\n         \
    \       __testlib_max(maxHit, validatorBoundsHit.maxHit)\n        );\n    }\n\
    };\n\nconst double ValidatorBoundsHit::EPS = 1E-12;\n\nclass Validator {\nprivate:\n\
    \    bool _initialized;\n    std::string _testset;\n    std::string _group;\n\
    \    std::string _testOverviewLogFileName;\n    std::map<std::string, ValidatorBoundsHit>\
    \ _boundsHitByVariableName;\n    std::set<std::string> _features;\n    std::set<std::string>\
    \ _hitFeatures;\n\n    bool isVariableNameBoundsAnalyzable(const std::string &variableName)\
    \ {\n        for (size_t i = 0; i < variableName.length(); i++)\n            if\
    \ ((variableName[i] >= '0' && variableName[i] <= '9') || variableName[i] < ' ')\n\
    \                return false;\n        return true;\n    }\n\n    bool isFeatureNameAnalyzable(const\
    \ std::string &featureName) {\n        for (size_t i = 0; i < featureName.length();\
    \ i++)\n            if (featureName[i] < ' ')\n                return false;\n\
    \        return true;\n    }\n\npublic:\n    Validator() : _initialized(false),\
    \ _testset(\"tests\"), _group() {\n    }\n\n    void initialize() {\n        _initialized\
    \ = true;\n    }\n\n    std::string testset() const {\n        if (!_initialized)\n\
    \            __testlib_fail(\"Validator should be initialized with registerValidation(argc,\
    \ argv) instead of registerValidation() to support validator.testset()\");\n \
    \       return _testset;\n    }\n\n    std::string group() const {\n        if\
    \ (!_initialized)\n            __testlib_fail(\"Validator should be initialized\
    \ with registerValidation(argc, argv) instead of registerValidation() to support\
    \ validator.group()\");\n        return _group;\n    }\n\n    std::string testOverviewLogFileName()\
    \ const {\n        return _testOverviewLogFileName;\n    }\n\n    void setTestset(const\
    \ char *const testset) {\n        _testset = testset;\n    }\n\n    void setGroup(const\
    \ char *const group) {\n        _group = group;\n    }\n\n    void setTestOverviewLogFileName(const\
    \ char *const testOverviewLogFileName) {\n        _testOverviewLogFileName = testOverviewLogFileName;\n\
    \    }\n\n    void addBoundsHit(const std::string &variableName, ValidatorBoundsHit\
    \ boundsHit) {\n        if (isVariableNameBoundsAnalyzable(variableName)) {\n\
    \            _boundsHitByVariableName[variableName]\n                    = boundsHit.merge(_boundsHitByVariableName[variableName]);\n\
    \        }\n    }\n\n    std::string getBoundsHitLog() {\n        std::string\
    \ result;\n        for (std::map<std::string, ValidatorBoundsHit>::iterator i\
    \ = _boundsHitByVariableName.begin();\n             i != _boundsHitByVariableName.end();\n\
    \             i++) {\n            result += \"\\\"\" + i->first + \"\\\":\";\n\
    \            if (i->second.minHit)\n                result += \" min-value-hit\"\
    ;\n            if (i->second.maxHit)\n                result += \" max-value-hit\"\
    ;\n            result += \"\\n\";\n        }\n        return result;\n    }\n\n\
    \    std::string getFeaturesLog() {\n        std::string result;\n        for\
    \ (std::set<std::string>::iterator i = _features.begin();\n             i != _features.end();\n\
    \             i++) {\n            result += \"feature \\\"\" + *i + \"\\\":\"\
    ;\n            if (_hitFeatures.count(*i))\n                result += \" hit\"\
    ;\n            result += \"\\n\";\n        }\n        return result;\n    }\n\n\
    \    void writeTestOverviewLog() {\n        if (!_testOverviewLogFileName.empty())\
    \ {\n            std::string fileName(_testOverviewLogFileName);\n           \
    \ _testOverviewLogFileName = \"\";\n            FILE *testOverviewLogFile = fopen(fileName.c_str(),\
    \ \"w\");\n            if (NULL == testOverviewLogFile)\n                __testlib_fail(\"\
    Validator::writeTestOverviewLog: can't test overview log to (\" + fileName + \"\
    )\");\n            fprintf(testOverviewLogFile, \"%s%s\", getBoundsHitLog().c_str(),\
    \ getFeaturesLog().c_str());\n            if (fclose(testOverviewLogFile))\n \
    \               __testlib_fail(\n                        \"Validator::writeTestOverviewLog:\
    \ can't close test overview log file (\" + fileName + \")\");\n        }\n   \
    \ }\n\n    void addFeature(const std::string &feature) {\n        if (_features.count(feature))\n\
    \            __testlib_fail(\"Feature \" + feature + \" registered twice.\");\n\
    \        if (!isFeatureNameAnalyzable(feature))\n            __testlib_fail(\"\
    Feature name '\" + feature + \"' contains restricted characters.\");\n\n     \
    \   _features.insert(feature);\n    }\n\n    void feature(const std::string &feature)\
    \ {\n        if (!isFeatureNameAnalyzable(feature))\n            __testlib_fail(\"\
    Feature name '\" + feature + \"' contains restricted characters.\");\n\n     \
    \   if (!_features.count(feature))\n            __testlib_fail(\"Feature \" +\
    \ feature + \" didn't registered via addFeature(feature).\");\n\n        _hitFeatures.insert(feature);\n\
    \    }\n} validator;\n\nstruct TestlibFinalizeGuard {\n    static bool alive;\n\
    \    int quitCount, readEofCount;\n\n    TestlibFinalizeGuard() : quitCount(0),\
    \ readEofCount(0) {\n        // No operations.\n    }\n\n    ~TestlibFinalizeGuard()\
    \ {\n        bool _alive = alive;\n        alive = false;\n\n        if (_alive)\
    \ {\n            if (testlibMode == _checker && quitCount == 0)\n            \
    \    __testlib_fail(\"Checker must end with quit or quitf call.\");\n\n      \
    \      if (testlibMode == _validator && readEofCount == 0 && quitCount == 0)\n\
    \                __testlib_fail(\"Validator must end with readEof call.\");\n\
    \        }\n\n        validator.writeTestOverviewLog();\n    }\n};\n\nbool TestlibFinalizeGuard::alive\
    \ = true;\nTestlibFinalizeGuard testlibFinalizeGuard;\n\n/*\n * Call it to disable\
    \ checks on finalization.\n */\nvoid disableFinalizeGuard() {\n    TestlibFinalizeGuard::alive\
    \ = false;\n}\n\n/* Interactor streams.\n */\nstd::fstream tout;\n\n/* implementation\n\
    \ */\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\ntemplate<typename T>\n\
    static std::string vtos(const T &t, std::true_type) {\n    if (t == 0)\n     \
    \   return \"0\";\n    else {\n        T n(t);\n        bool negative = n < 0;\n\
    \        std::string s;\n        while (n != 0) {\n            T digit = n % 10;\n\
    \            if (digit < 0)\n                digit = -digit;\n            s +=\
    \ char('0' + digit);\n            n /= 10;\n        }\n        std::reverse(s.begin(),\
    \ s.end());\n        return negative ? \"-\" + s : s;\n    }\n}\n\ntemplate<typename\
    \ T>\nstatic std::string vtos(const T &t, std::false_type) {\n    std::string\
    \ s;\n    static std::stringstream ss;\n    ss.str(std::string());\n    ss.clear();\n\
    \    ss << t;\n    ss >> s;\n    return s;\n}\n\ntemplate<typename T>\nstatic\
    \ std::string vtos(const T &t) {\n    return vtos(t, std::is_integral<T>());\n\
    }\n\n/* signed case. */\ntemplate<typename T>\nstatic std::string toHumanReadableString(const\
    \ T &n, std::false_type) {\n    if (n == 0)\n        return vtos(n);\n    int\
    \ trailingZeroCount = 0;\n    T n_ = n;\n    while (n_ % 10 == 0)\n        n_\
    \ /= 10, trailingZeroCount++;\n    if (trailingZeroCount >= 7) {\n        if (n_\
    \ == 1)\n            return \"10^\" + vtos(trailingZeroCount);\n        else if\
    \ (n_ == -1)\n            return \"-10^\" + vtos(trailingZeroCount);\n       \
    \ else\n            return vtos(n_) + \"*10^\" + vtos(trailingZeroCount);\n  \
    \  } else\n        return vtos(n);\n}\n\n/* unsigned case. */\ntemplate<typename\
    \ T>\nstatic std::string toHumanReadableString(const T &n, std::true_type) {\n\
    \    if (n == 0)\n        return vtos(n);\n    int trailingZeroCount = 0;\n  \
    \  T n_ = n;\n    while (n_ % 10 == 0)\n        n_ /= 10, trailingZeroCount++;\n\
    \    if (trailingZeroCount >= 7) {\n        if (n_ == 1)\n            return \"\
    10^\" + vtos(trailingZeroCount);\n        else\n            return vtos(n_) +\
    \ \"*10^\" + vtos(trailingZeroCount);\n    } else\n        return vtos(n);\n}\n\
    \ntemplate<typename T>\nstatic std::string toHumanReadableString(const T &n) {\n\
    \    return toHumanReadableString(n, std::is_unsigned<T>());\n}\n#else\ntemplate<typename\
    \ T>\nstatic std::string vtos(const T& t)\n{\n    std::string s;\n    static std::stringstream\
    \ ss;\n    ss.str(std::string());\n    ss.clear();\n    ss << t;\n    ss >> s;\n\
    \    return s;\n}\n\ntemplate<typename T>\nstatic std::string toHumanReadableString(const\
    \ T &n) {\n    return vtos(n);\n}\n#endif\n\ntemplate<typename T>\nstatic std::string\
    \ toString(const T &t) {\n    return vtos(t);\n}\n\nInStream::InStream() {\n \
    \   reader = NULL;\n    lastLine = -1;\n    opened = false;\n    name = \"\";\n\
    \    mode = _input;\n    strict = false;\n    stdfile = false;\n    readManyIteration\
    \ = NO_INDEX;\n    maxFileSize = 128 * 1024 * 1024; // 128MB.\n    maxTokenLength\
    \ = 32 * 1024 * 1024; // 32MB.\n    maxMessageLength = 32000;\n}\n\nInStream::InStream(const\
    \ InStream &baseStream, std::string content) {\n    reader = new StringInputStreamReader(content);\n\
    \    lastLine = -1;\n    opened = true;\n    strict = baseStream.strict;\n   \
    \ stdfile = false;\n    mode = baseStream.mode;\n    name = \"based on \" + baseStream.name;\n\
    \    readManyIteration = NO_INDEX;\n    maxFileSize = 128 * 1024 * 1024; // 128MB.\n\
    \    maxTokenLength = 32 * 1024 * 1024; // 32MB.\n    maxMessageLength = 32000;\n\
    }\n\nInStream::~InStream() {\n    if (NULL != reader) {\n        reader->close();\n\
    \        delete reader;\n        reader = NULL;\n    }\n}\n\n#ifdef __GNUC__\n\
    __attribute__((const))\n#endif\nint resultExitCode(TResult r) {\n    if (r ==\
    \ _ok)\n        return OK_EXIT_CODE;\n    if (r == _wa)\n        return WA_EXIT_CODE;\n\
    \    if (r == _pe)\n        return PE_EXIT_CODE;\n    if (r == _fail)\n      \
    \  return FAIL_EXIT_CODE;\n    if (r == _dirt)\n        return DIRT_EXIT_CODE;\n\
    \    if (r == _points)\n        return POINTS_EXIT_CODE;\n    if (r == _unexpected_eof)\n\
    #ifdef ENABLE_UNEXPECTED_EOF\n        return UNEXPECTED_EOF_EXIT_CODE;\n#else\n\
    \        return PE_EXIT_CODE;\n#endif\n    if (r >= _partially)\n        return\
    \ PC_BASE_EXIT_CODE + (r - _partially);\n    return FAIL_EXIT_CODE;\n}\n\nvoid\
    \ InStream::textColor(\n#if !(defined(ON_WINDOWS) && (!defined(_MSC_VER) || _MSC_VER\
    \ > 1400)) && defined(__GNUC__)\n        __attribute__((unused))\n#endif\n   \
    \     WORD color\n) {\n#if defined(ON_WINDOWS) && (!defined(_MSC_VER) || _MSC_VER\
    \ > 1400)\n    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);\n    SetConsoleTextAttribute(handle,\
    \ color);\n#endif\n#if !defined(ON_WINDOWS) && defined(__GNUC__)\n    if (isatty(2))\n\
    \    {\n        switch (color)\n        {\n        case LightRed:\n          \
    \  fprintf(stderr, \"\\033[1;31m\");\n            break;\n        case LightCyan:\n\
    \            fprintf(stderr, \"\\033[1;36m\");\n            break;\n        case\
    \ LightGreen:\n            fprintf(stderr, \"\\033[1;32m\");\n            break;\n\
    \        case LightYellow:\n            fprintf(stderr, \"\\033[1;33m\");\n  \
    \          break;\n        case LightGray:\n        default:\n            fprintf(stderr,\
    \ \"\\033[0m\");\n        }\n    }\n#endif\n}\n\nNORETURN void halt(int exitCode)\
    \ {\n#ifdef FOOTER\n    InStream::textColor(InStream::LightGray);\n    std::fprintf(stderr,\
    \ \"Checker: \\\"%s\\\"\\n\", checkerName.c_str());\n    std::fprintf(stderr,\
    \ \"Exit code: %d\\n\", exitCode);\n    InStream::textColor(InStream::LightGray);\n\
    #endif\n    std::exit(exitCode);\n}\n\nstatic bool __testlib_shouldCheckDirt(TResult\
    \ result) {\n    return result == _ok || result == _points || result >= _partially;\n\
    }\n\nstatic std::string __testlib_appendMessage(const std::string &message, const\
    \ std::string &extra) {\n    int openPos = -1, closePos = -1;\n    for (size_t\
    \ i = 0; i < message.length(); i++) {\n        if (message[i] == InStream::OPEN_BRACKET)\
    \ {\n            if (openPos == -1)\n                openPos = i;\n          \
    \  else\n                openPos = INT_MAX;\n        }\n        if (message[i]\
    \ == InStream::CLOSE_BRACKET) {\n            if (closePos == -1)\n           \
    \     closePos = i;\n            else\n                closePos = INT_MAX;\n \
    \       }\n    }\n    if (openPos != -1 && openPos != INT_MAX\n        && closePos\
    \ != -1 && closePos != INT_MAX\n        && openPos < closePos) {\n        size_t\
    \ index = message.find(extra, openPos);\n        if (index == std::string::npos\
    \ || int(index) >= closePos) {\n            std::string result(message);\n   \
    \         result.insert(closePos, \", \" + extra);\n            return result;\n\
    \        }\n        return message;\n    }\n\n    return message + \" \" + InStream::OPEN_BRACKET\
    \ + extra + InStream::CLOSE_BRACKET;\n}\n\nstatic std::string __testlib_toPrintableMessage(const\
    \ std::string &message) {\n    int openPos = -1, closePos = -1;\n    for (size_t\
    \ i = 0; i < message.length(); i++) {\n        if (message[i] == InStream::OPEN_BRACKET)\
    \ {\n            if (openPos == -1)\n                openPos = i;\n          \
    \  else\n                openPos = INT_MAX;\n        }\n        if (message[i]\
    \ == InStream::CLOSE_BRACKET) {\n            if (closePos == -1)\n           \
    \     closePos = i;\n            else\n                closePos = INT_MAX;\n \
    \       }\n    }\n    if (openPos != -1 && openPos != INT_MAX\n        && closePos\
    \ != -1 && closePos != INT_MAX\n        && openPos < closePos) {\n        std::string\
    \ result(message);\n        result[openPos] = '(';\n        result[closePos] =\
    \ ')';\n        return result;\n    }\n\n    return message;\n}\n\nNORETURN void\
    \ InStream::quit(TResult result, const char *msg) {\n    if (TestlibFinalizeGuard::alive)\n\
    \        testlibFinalizeGuard.quitCount++;\n\n    std::string message(msg);\n\
    \    message = trim(message);\n\n    if (__testlib_hasTestCase) {\n        if\
    \ (result != _ok)\n            message = __testlib_appendMessage(message, \"test\
    \ case \" + vtos(__testlib_testCase));\n        else {\n            if (__testlib_testCase\
    \ == 1)\n                message = __testlib_appendMessage(message, vtos(__testlib_testCase)\
    \ + \" test case\");\n            else\n                message = __testlib_appendMessage(message,\
    \ vtos(__testlib_testCase) + \" test cases\");\n        }\n    }\n\n    // You\
    \ can change maxMessageLength.\n    // Example: 'inf.maxMessageLength = 1024 *\
    \ 1024;'.\n    if (message.length() > maxMessageLength) {\n        std::string\
    \ warn = \"message length exceeds \" + vtos(maxMessageLength)\n              \
    \             + \", the message is truncated: \";\n        message = warn + message.substr(0,\
    \ maxMessageLength - warn.length());\n    }\n\n#ifndef ENABLE_UNEXPECTED_EOF\n\
    \    if (result == _unexpected_eof)\n        result = _pe;\n#endif\n\n    if (mode\
    \ != _output && result != _fail) {\n        if (mode == _input && testlibMode\
    \ == _validator && lastLine != -1)\n            quits(_fail, __testlib_appendMessage(__testlib_appendMessage(message,\
    \ name), \"line \" + vtos(lastLine)));\n        else\n            quits(_fail,\
    \ __testlib_appendMessage(message, name));\n    }\n\n    std::FILE *resultFile;\n\
    \    std::string errorName;\n\n    if (__testlib_shouldCheckDirt(result)) {\n\
    \        if (testlibMode != _interactor && !ouf.seekEof())\n            quit(_dirt,\
    \ \"Extra information in the output file\");\n    }\n\n    int pctype = result\
    \ - _partially;\n    bool isPartial = false;\n\n    switch (result) {\n      \
    \  case _ok:\n            errorName = \"ok \";\n            quitscrS(LightGreen,\
    \ errorName);\n            break;\n        case _wa:\n            errorName =\
    \ \"wrong answer \";\n            quitscrS(LightRed, errorName);\n           \
    \ break;\n        case _pe:\n            errorName = \"wrong output format \"\
    ;\n            quitscrS(LightRed, errorName);\n            break;\n        case\
    \ _fail:\n            errorName = \"FAIL \";\n            quitscrS(LightRed, errorName);\n\
    \            break;\n        case _dirt:\n            errorName = \"wrong output\
    \ format \";\n            quitscrS(LightCyan, errorName);\n            result\
    \ = _pe;\n            break;\n        case _points:\n            errorName = \"\
    points \";\n            quitscrS(LightYellow, errorName);\n            break;\n\
    \        case _unexpected_eof:\n            errorName = \"unexpected eof \";\n\
    \            quitscrS(LightCyan, errorName);\n            break;\n        default:\n\
    \            if (result >= _partially) {\n                errorName = format(\"\
    partially correct (%d) \", pctype);\n                isPartial = true;\n     \
    \           quitscrS(LightYellow, errorName);\n            } else\n          \
    \      quit(_fail, \"What is the code ??? \");\n    }\n\n    if (resultName !=\
    \ \"\") {\n        resultFile = std::fopen(resultName.c_str(), \"w\");\n     \
    \   if (resultFile == NULL) {\n            resultName = \"\";\n            quit(_fail,\
    \ \"Can not write to the result file\");\n        }\n        if (appesMode) {\n\
    \            std::fprintf(resultFile, \"<?xml version=\\\"1.0\\\" encoding=\\\"\
    windows-1251\\\"?>\");\n            if (isPartial)\n                std::fprintf(resultFile,\
    \ \"<result outcome = \\\"%s\\\" pctype = \\\"%d\\\">\",\n                   \
    \          outcomes[(int) _partially].c_str(), pctype);\n            else {\n\
    \                if (result != _points)\n                    std::fprintf(resultFile,\
    \ \"<result outcome = \\\"%s\\\">\", outcomes[(int) result].c_str());\n      \
    \          else {\n                    if (__testlib_points == std::numeric_limits<float>::infinity())\n\
    \                        quit(_fail, \"Expected points, but infinity found\");\n\
    \                    std::string stringPoints = removeDoubleTrailingZeroes(format(\"\
    %.10f\", __testlib_points));\n                    std::fprintf(resultFile, \"\
    <result outcome = \\\"%s\\\" points = \\\"%s\\\">\",\n                       \
    \          outcomes[(int) result].c_str(), stringPoints.c_str());\n          \
    \      }\n            }\n            xmlSafeWrite(resultFile, __testlib_toPrintableMessage(message).c_str());\n\
    \            std::fprintf(resultFile, \"</result>\\n\");\n        } else\n   \
    \         std::fprintf(resultFile, \"%s\", __testlib_toPrintableMessage(message).c_str());\n\
    \        if (NULL == resultFile || fclose(resultFile) != 0) {\n            resultName\
    \ = \"\";\n            quit(_fail, \"Can not write to the result file\");\n  \
    \      }\n    }\n\n    quitscr(LightGray, __testlib_toPrintableMessage(message).c_str());\n\
    \    std::fprintf(stderr, \"\\n\");\n\n    inf.close();\n    ouf.close();\n  \
    \  ans.close();\n    if (tout.is_open())\n        tout.close();\n\n    textColor(LightGray);\n\
    \n    if (resultName != \"\")\n        std::fprintf(stderr, \"See file to check\
    \ exit message\\n\");\n\n    halt(resultExitCode(result));\n}\n\n#ifdef __GNUC__\n\
    __attribute__ ((format (printf, 3, 4)))\n#endif\nNORETURN void InStream::quitf(TResult\
    \ result, const char *msg, ...) {\n    FMT_TO_RESULT(msg, msg, message);\n   \
    \ InStream::quit(result, message.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nvoid InStream::quitif(bool condition, TResult\
    \ result, const char *msg, ...) {\n    if (condition) {\n        FMT_TO_RESULT(msg,\
    \ msg, message);\n        InStream::quit(result, message.c_str());\n    }\n}\n\
    \nNORETURN void InStream::quits(TResult result, std::string msg) {\n    InStream::quit(result,\
    \ msg.c_str());\n}\n\nvoid InStream::xmlSafeWrite(std::FILE *file, const char\
    \ *msg) {\n    size_t lmsg = strlen(msg);\n    for (size_t i = 0; i < lmsg; i++)\
    \ {\n        if (msg[i] == '&') {\n            std::fprintf(file, \"%s\", \"&amp;\"\
    );\n            continue;\n        }\n        if (msg[i] == '<') {\n         \
    \   std::fprintf(file, \"%s\", \"&lt;\");\n            continue;\n        }\n\
    \        if (msg[i] == '>') {\n            std::fprintf(file, \"%s\", \"&gt;\"\
    );\n            continue;\n        }\n        if (msg[i] == '\"') {\n        \
    \    std::fprintf(file, \"%s\", \"&quot;\");\n            continue;\n        }\n\
    \        if (0 <= msg[i] && msg[i] <= 31) {\n            std::fprintf(file, \"\
    %c\", '.');\n            continue;\n        }\n        std::fprintf(file, \"%c\"\
    , msg[i]);\n    }\n}\n\nvoid InStream::quitscrS(WORD color, std::string msg) {\n\
    \    quitscr(color, msg.c_str());\n}\n\nvoid InStream::quitscr(WORD color, const\
    \ char *msg) {\n    if (resultName == \"\") {\n        textColor(color);\n   \
    \     std::fprintf(stderr, \"%s\", msg);\n        textColor(LightGray);\n    }\n\
    }\n\nvoid InStream::reset(std::FILE *file) {\n    if (opened && stdfile)\n   \
    \     quit(_fail, \"Can't reset standard handle\");\n\n    if (opened)\n     \
    \   close();\n\n    if (!stdfile)\n        if (NULL == (file = std::fopen(name.c_str(),\
    \ \"rb\"))) {\n            if (mode == _output)\n                quits(_pe, std::string(\"\
    Output file not found: \\\"\") + name + \"\\\"\");\n\n            if (mode ==\
    \ _answer)\n                quits(_fail, std::string(\"Answer file not found:\
    \ \\\"\") + name + \"\\\"\");\n        }\n\n    if (NULL != file) {\n        opened\
    \ = true;\n\n        __testlib_set_binary(file);\n\n        if (stdfile)\n   \
    \         reader = new FileInputStreamReader(file, name);\n        else\n    \
    \        reader = new BufferedFileInputStreamReader(file, name);\n    } else {\n\
    \        opened = false;\n        reader = NULL;\n    }\n}\n\nvoid InStream::init(std::string\
    \ fileName, TMode mode) {\n    opened = false;\n    name = fileName;\n    stdfile\
    \ = false;\n    this->mode = mode;\n\n    std::ifstream stream;\n    stream.open(fileName.c_str(),\
    \ std::ios::in);\n    if (stream.is_open()) {\n        std::streampos start =\
    \ stream.tellg();\n        stream.seekg(0, std::ios::end);\n        std::streampos\
    \ end = stream.tellg();\n        size_t fileSize = size_t(end - start);\n    \
    \    stream.close();\n\n        // You can change maxFileSize.\n        // Example:\
    \ 'inf.maxFileSize = 256 * 1024 * 1024;'.\n        if (fileSize > maxFileSize)\n\
    \            quitf(_pe, \"File size exceeds %d bytes, size is %d\", int(maxFileSize),\
    \ int(fileSize));\n    }\n\n    reset();\n}\n\nvoid InStream::init(std::FILE *f,\
    \ TMode mode) {\n    opened = false;\n    name = \"untitled\";\n    this->mode\
    \ = mode;\n\n    if (f == stdin)\n        name = \"stdin\", stdfile = true;\n\
    \    if (f == stdout)\n        name = \"stdout\", stdfile = true;\n    if (f ==\
    \ stderr)\n        name = \"stderr\", stdfile = true;\n\n    reset(f);\n}\n\n\
    char InStream::curChar() {\n    return char(reader->curChar());\n}\n\nchar InStream::nextChar()\
    \ {\n    return char(reader->nextChar());\n}\n\nchar InStream::readChar() {\n\
    \    return nextChar();\n}\n\nchar InStream::readChar(char c) {\n    lastLine\
    \ = reader->getLine();\n    char found = readChar();\n    if (c != found) {\n\
    \        if (!isEoln(found))\n            quit(_pe, (\"Unexpected character '\"\
    \ + std::string(1, found) + \"', but '\" + std::string(1, c) +\n             \
    \          \"' expected\").c_str());\n        else\n            quit(_pe, (\"\
    Unexpected character \" + (\"#\" + vtos(int(found))) + \", but '\" + std::string(1,\
    \ c) +\n                       \"' expected\").c_str());\n    }\n    return found;\n\
    }\n\nchar InStream::readSpace() {\n    return readChar(' ');\n}\n\nvoid InStream::unreadChar(char\
    \ c) {\n    reader->unreadChar(c);\n}\n\nvoid InStream::skipChar() {\n    reader->skipChar();\n\
    }\n\nvoid InStream::skipBlanks() {\n    while (isBlanks(reader->curChar()))\n\
    \        reader->skipChar();\n}\n\nstd::string InStream::readWord() {\n    readWordTo(_tmpReadToken);\n\
    \    return _tmpReadToken;\n}\n\nvoid InStream::readWordTo(std::string &result)\
    \ {\n    if (!strict)\n        skipBlanks();\n\n    lastLine = reader->getLine();\n\
    \    int cur = reader->nextChar();\n\n    if (cur == EOFC)\n        quit(_unexpected_eof,\
    \ \"Unexpected end of file - token expected\");\n\n    if (isBlanks(cur))\n  \
    \      quit(_pe, \"Unexpected white-space - token expected\");\n\n    result.clear();\n\
    \n    while (!(isBlanks(cur) || cur == EOFC)) {\n        result += char(cur);\n\
    \n        // You can change maxTokenLength.\n        // Example: 'inf.maxTokenLength\
    \ = 128 * 1024 * 1024;'.\n        if (result.length() > maxTokenLength)\n    \
    \        quitf(_pe, \"Length of token exceeds %d, token is '%s...'\", int(maxTokenLength),\n\
    \                  __testlib_part(result).c_str());\n\n        cur = reader->nextChar();\n\
    \    }\n\n    reader->unreadChar(cur);\n\n    if (result.length() == 0)\n    \
    \    quit(_unexpected_eof, \"Unexpected end of file or white-space - token expected\"\
    );\n}\n\nstd::string InStream::readToken() {\n    return readWord();\n}\n\nvoid\
    \ InStream::readTokenTo(std::string &result) {\n    readWordTo(result);\n}\n\n\
    static std::string __testlib_part(const std::string &s) {\n    if (s.length()\
    \ <= 64)\n        return s;\n    else\n        return s.substr(0, 30) + \"...\"\
    \ + s.substr(s.length() - 31, 31);\n}\n\n#define __testlib_readMany(readMany,\
    \ readOne, typeName, space)                  \\\n    if (size < 0)           \
    \                                                    \\\n        quit(_fail, #readMany\
    \ \": size should be non-negative.\");                \\\n    if (size > 100000000)\
    \                                                       \\\n        quit(_fail,\
    \ #readMany \": size should be at most 100000000.\");           \\\n         \
    \                                                                       \\\n \
    \   std::vector<typeName> result(size);                                      \
    \   \\\n    readManyIteration = indexBase;                                   \
    \           \\\n                                                             \
    \                   \\\n    for (int i = 0; i < size; i++)                   \
    \                           \\\n    {                                        \
    \                                   \\\n        result[i] = readOne;         \
    \                                           \\\n        readManyIteration++; \
    \                                                   \\\n        if (strict &&\
    \ space && i + 1 < size)                                              \\\n   \
    \         readSpace();                                                       \
    \ \\\n    }                                                                  \
    \         \\\n                                                               \
    \                 \\\n    readManyIteration = NO_INDEX;                      \
    \                         \\\n    return result;                             \
    \                                 \\\n\n\nstd::string InStream::readWord(const\
    \ pattern &p, const std::string &variableName) {\n    readWordTo(_tmpReadToken);\n\
    \    if (!p.matches(_tmpReadToken)) {\n        if (readManyIteration == NO_INDEX)\
    \ {\n            if (variableName.empty())\n                quit(_wa,\n      \
    \               (\"Token \\\"\" + __testlib_part(_tmpReadToken) + \"\\\" doesn't\
    \ correspond to pattern \\\"\" + p.src() +\n                      \"\\\"\").c_str());\n\
    \            else\n                quit(_wa, (\"Token parameter [name=\" + variableName\
    \ + \"] equals to \\\"\" + __testlib_part(_tmpReadToken) +\n                 \
    \          \"\\\", doesn't correspond to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n\
    \        } else {\n            if (variableName.empty())\n                quit(_wa,\
    \ (\"Token element [index=\" + vtos(readManyIteration) + \"] equals to \\\"\"\
    \ +\n                           __testlib_part(_tmpReadToken) + \"\\\" doesn't\
    \ correspond to pattern \\\"\" + p.src() +\n                           \"\\\"\"\
    ).c_str());\n            else\n                quit(_wa, (\"Token element \" +\
    \ variableName + \"[\" + vtos(readManyIteration) + \"] equals to \\\"\" +\n  \
    \                         __testlib_part(_tmpReadToken) + \"\\\", doesn't correspond\
    \ to pattern \\\"\" + p.src() +\n                           \"\\\"\").c_str());\n\
    \        }\n    }\n    return _tmpReadToken;\n}\n\nstd::vector<std::string>\n\
    InStream::readWords(int size, const pattern &p, const std::string &variablesName,\
    \ int indexBase) {\n    __testlib_readMany(readWords, readWord(p, variablesName),\
    \ std::string, true);\n}\n\nstd::vector<std::string> InStream::readWords(int size,\
    \ int indexBase) {\n    __testlib_readMany(readWords, readWord(), std::string,\
    \ true);\n}\n\nstd::string InStream::readWord(const std::string &ptrn, const std::string\
    \ &variableName) {\n    return readWord(pattern(ptrn), variableName);\n}\n\nstd::vector<std::string>\n\
    InStream::readWords(int size, const std::string &ptrn, const std::string &variablesName,\
    \ int indexBase) {\n    pattern p(ptrn);\n    __testlib_readMany(readWords, readWord(p,\
    \ variablesName), std::string, true);\n}\n\nstd::string InStream::readToken(const\
    \ pattern &p, const std::string &variableName) {\n    return readWord(p, variableName);\n\
    }\n\nstd::vector<std::string>\nInStream::readTokens(int size, const pattern &p,\
    \ const std::string &variablesName, int indexBase) {\n    __testlib_readMany(readTokens,\
    \ readToken(p, variablesName), std::string, true);\n}\n\nstd::vector<std::string>\
    \ InStream::readTokens(int size, int indexBase) {\n    __testlib_readMany(readTokens,\
    \ readToken(), std::string, true);\n}\n\nstd::string InStream::readToken(const\
    \ std::string &ptrn, const std::string &variableName) {\n    return readWord(ptrn,\
    \ variableName);\n}\n\nstd::vector<std::string>\nInStream::readTokens(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \    pattern p(ptrn);\n    __testlib_readMany(readTokens, readWord(p, variablesName),\
    \ std::string, true);\n}\n\nvoid InStream::readWordTo(std::string &result, const\
    \ pattern &p, const std::string &variableName) {\n    readWordTo(result);\n  \
    \  if (!p.matches(result)) {\n        if (variableName.empty())\n            quit(_wa,\
    \ (\"Token \\\"\" + __testlib_part(result) + \"\\\" doesn't correspond to pattern\
    \ \\\"\" + p.src() +\n                       \"\\\"\").c_str());\n        else\n\
    \            quit(_wa, (\"Token parameter [name=\" + variableName + \"] equals\
    \ to \\\"\" + __testlib_part(result) +\n                       \"\\\", doesn't\
    \ correspond to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n    }\n}\n\nvoid\
    \ InStream::readWordTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName) {\n    return readWordTo(result, pattern(ptrn), variableName);\n\
    }\n\nvoid InStream::readTokenTo(std::string &result, const pattern &p, const std::string\
    \ &variableName) {\n    return readWordTo(result, p, variableName);\n}\n\nvoid\
    \ InStream::readTokenTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName) {\n    return readWordTo(result, ptrn, variableName);\n}\n\n\
    #ifdef __GNUC__\n__attribute__((pure))\n#endif\nstatic inline bool equals(long\
    \ long integer, const char *s) {\n    if (integer == LLONG_MIN)\n        return\
    \ strcmp(s, \"-9223372036854775808\") == 0;\n\n    if (integer == 0LL)\n     \
    \   return strcmp(s, \"0\") == 0;\n\n    size_t length = strlen(s);\n\n    if\
    \ (length == 0)\n        return false;\n\n    if (integer < 0 && s[0] != '-')\n\
    \        return false;\n\n    if (integer < 0)\n        s++, length--, integer\
    \ = -integer;\n\n    if (length == 0)\n        return false;\n\n    while (integer\
    \ > 0) {\n        int digit = int(integer % 10);\n\n        if (s[length - 1]\
    \ != '0' + digit)\n            return false;\n\n        length--;\n        integer\
    \ /= 10;\n    }\n\n    return length == 0;\n}\n\n#ifdef __GNUC__\n__attribute__((pure))\n\
    #endif\nstatic inline bool equals(unsigned long long integer, const char *s) {\n\
    \    if (integer == ULLONG_MAX)\n        return strcmp(s, \"18446744073709551615\"\
    ) == 0;\n\n    if (integer == 0ULL)\n        return strcmp(s, \"0\") == 0;\n\n\
    \    size_t length = strlen(s);\n\n    if (length == 0)\n        return false;\n\
    \n    while (integer > 0) {\n        int digit = int(integer % 10);\n\n      \
    \  if (s[length - 1] != '0' + digit)\n            return false;\n\n        length--;\n\
    \        integer /= 10;\n    }\n\n    return length == 0;\n}\n\nstatic inline\
    \ double stringToDouble(InStream &in, const char *buffer) {\n    double retval;\n\
    \n    size_t length = strlen(buffer);\n\n    int minusCount = 0;\n    int plusCount\
    \ = 0;\n    int decimalPointCount = 0;\n    int digitCount = 0;\n    int eCount\
    \ = 0;\n\n    for (size_t i = 0; i < length; i++) {\n        if (('0' <= buffer[i]\
    \ && buffer[i] <= '9') || buffer[i] == '.'\n            || buffer[i] == 'e' ||\
    \ buffer[i] == 'E'\n            || buffer[i] == '-' || buffer[i] == '+') {\n \
    \           if ('0' <= buffer[i] && buffer[i] <= '9')\n                digitCount++;\n\
    \            if (buffer[i] == 'e' || buffer[i] == 'E')\n                eCount++;\n\
    \            if (buffer[i] == '-')\n                minusCount++;\n          \
    \  if (buffer[i] == '+')\n                plusCount++;\n            if (buffer[i]\
    \ == '.')\n                decimalPointCount++;\n        } else\n            in.quit(_pe,\
    \ (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \    }\n\n    // If for sure is not a number in standard notation or in e-notation.\n\
    \    if (digitCount == 0 || minusCount > 2 || plusCount > 2 || decimalPointCount\
    \ > 1 || eCount > 1)\n        in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n    char *suffix = new char[length + 1];\n  \
    \  std::memset(suffix, 0, length + 1);\n    int scanned = std::sscanf(buffer,\
    \ \"%lf%s\", &retval, suffix);\n    bool empty = strlen(suffix) == 0;\n    delete[]\
    \ suffix;\n\n    if (scanned == 1 || (scanned == 2 && empty)) {\n        if (__testlib_isNaN(retval))\n\
    \            in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n        return retval;\n    } else\n        in.quit(_pe,\
    \ (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    }\n\nstatic inline double\nstringToStrictDouble(InStream &in, const char *buffer,\
    \ int minAfterPointDigitCount, int maxAfterPointDigitCount) {\n    if (minAfterPointDigitCount\
    \ < 0)\n        in.quit(_fail, \"stringToStrictDouble: minAfterPointDigitCount\
    \ should be non-negative.\");\n\n    if (minAfterPointDigitCount > maxAfterPointDigitCount)\n\
    \        in.quit(_fail,\n                \"stringToStrictDouble: minAfterPointDigitCount\
    \ should be less or equal to maxAfterPointDigitCount.\");\n\n    double retval;\n\
    \n    size_t length = strlen(buffer);\n\n    if (length == 0 || length > 1000)\n\
    \        in.quit(_pe, (\"Expected strict double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n    if (buffer[0] != '-' && (buffer[0] < '0'\
    \ || buffer[0] > '9'))\n        in.quit(_pe, (\"Expected strict double, but \\\
    \"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n    int pointPos\
    \ = -1;\n    for (size_t i = 1; i + 1 < length; i++) {\n        if (buffer[i]\
    \ == '.') {\n            if (pointPos > -1)\n                in.quit(_pe, (\"\
    Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \            pointPos = int(i);\n        }\n        if (buffer[i] != '.' && (buffer[i]\
    \ < '0' || buffer[i] > '9'))\n            in.quit(_pe, (\"Expected strict double,\
    \ but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n    }\n\n \
    \   if (buffer[length - 1] < '0' || buffer[length - 1] > '9')\n        in.quit(_pe,\
    \ (\"Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n    int afterDigitsCount = (pointPos == -1 ? 0 : int(length) -\
    \ pointPos - 1);\n    if (afterDigitsCount < minAfterPointDigitCount || afterDigitsCount\
    \ > maxAfterPointDigitCount)\n        in.quit(_pe, (\"Expected strict double with\
    \ number of digits after point in range [\"\n                      + vtos(minAfterPointDigitCount)\n\
    \                      + \",\"\n                      + vtos(maxAfterPointDigitCount)\n\
    \                      + \"], but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str()\n        );\n\n    int firstDigitPos = -1;\n    for (size_t i = 0; i\
    \ < length; i++)\n        if (buffer[i] >= '0' && buffer[i] <= '9') {\n      \
    \      firstDigitPos = int(i);\n            break;\n        }\n\n    if (firstDigitPos\
    \ > 1 || firstDigitPos == -1)\n        in.quit(_pe, (\"Expected strict double,\
    \ but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n    if (buffer[firstDigitPos]\
    \ == '0' && firstDigitPos + 1 < int(length)\n        && buffer[firstDigitPos +\
    \ 1] >= '0' && buffer[firstDigitPos + 1] <= '9')\n        in.quit(_pe, (\"Expected\
    \ strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \n    char *suffix = new char[length + 1];\n    std::memset(suffix, 0, length\
    \ + 1);\n    int scanned = std::sscanf(buffer, \"%lf%s\", &retval, suffix);\n\
    \    bool empty = strlen(suffix) == 0;\n    delete[] suffix;\n\n    if (scanned\
    \ == 1 || (scanned == 2 && empty)) {\n        if (__testlib_isNaN(retval) || __testlib_isInfinite(retval))\n\
    \            in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n        if (buffer[0] == '-' && retval >= 0)\n\
    \            in.quit(_pe, (\"Redundant minus in \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n        return retval;\n    } else\n        in.quit(_pe,\
    \ (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    }\n\nstatic inline long long stringToLongLong(InStream &in, const char *buffer)\
    \ {\n    if (strcmp(buffer, \"-9223372036854775808\") == 0)\n        return LLONG_MIN;\n\
    \n    bool minus = false;\n    size_t length = strlen(buffer);\n\n    if (length\
    \ > 1 && buffer[0] == '-')\n        minus = true;\n\n    if (length > 20)\n  \
    \      in.quit(_pe, (\"Expected integer, but \\\"\" + __testlib_part(buffer) +\
    \ \"\\\" found\").c_str());\n\n    long long retval = 0LL;\n\n    int zeroes =\
    \ 0;\n    bool processingZeroes = true;\n\n    for (int i = (minus ? 1 : 0); i\
    \ < int(length); i++) {\n        if (buffer[i] == '0' && processingZeroes)\n \
    \           zeroes++;\n        else\n            processingZeroes = false;\n\n\
    \        if (buffer[i] < '0' || buffer[i] > '9')\n            in.quit(_pe, (\"\
    Expected integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \        retval = retval * 10 + (buffer[i] - '0');\n    }\n\n    if (retval <\
    \ 0)\n        in.quit(_pe, (\"Expected integer, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n    if ((zeroes > 0 && (retval != 0 || minus))\
    \ || zeroes > 1)\n        in.quit(_pe, (\"Expected integer, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n    retval = (minus ? -retval : +retval);\n\n\
    \    if (length < 19)\n        return retval;\n\n    if (equals(retval, buffer))\n\
    \        return retval;\n    else\n        in.quit(_pe, (\"Expected int64, but\
    \ \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n}\n\nstatic inline\
    \ unsigned long long stringToUnsignedLongLong(InStream &in, const char *buffer)\
    \ {\n    size_t length = strlen(buffer);\n\n    if (length > 20)\n        in.quit(_pe,\
    \ (\"Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n    if (length > 1 && buffer[0] == '0')\n        in.quit(_pe, (\"\
    Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n    unsigned long long retval = 0LL;\n    for (int i = 0; i < int(length);\
    \ i++) {\n        if (buffer[i] < '0' || buffer[i] > '9')\n            in.quit(_pe,\
    \ (\"Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n        retval = retval * 10 + (buffer[i] - '0');\n    }\n\n    if\
    \ (length < 19)\n        return retval;\n\n    if (length == 20 && strcmp(buffer,\
    \ \"18446744073709551615\") > 0)\n        in.quit(_pe, (\"Expected unsigned int64,\
    \ but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n    if (equals(retval,\
    \ buffer))\n        return retval;\n    else\n        in.quit(_pe, (\"Expected\
    \ unsigned int64, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    }\n\nint InStream::readInteger() {\n    if (!strict && seekEof())\n        quit(_unexpected_eof,\
    \ \"Unexpected end of file - int32 expected\");\n\n    readWordTo(_tmpReadToken);\n\
    \n    long long value = stringToLongLong(*this, _tmpReadToken.c_str());\n    if\
    \ (value < INT_MIN || value > INT_MAX)\n        quit(_pe, (\"Expected int32, but\
    \ \\\"\" + __testlib_part(_tmpReadToken) + \"\\\" found\").c_str());\n\n    return\
    \ int(value);\n}\n\nlong long InStream::readLong() {\n    if (!strict && seekEof())\n\
    \        quit(_unexpected_eof, \"Unexpected end of file - int64 expected\");\n\
    \n    readWordTo(_tmpReadToken);\n\n    return stringToLongLong(*this, _tmpReadToken.c_str());\n\
    }\n\nunsigned long long InStream::readUnsignedLong() {\n    if (!strict && seekEof())\n\
    \        quit(_unexpected_eof, \"Unexpected end of file - int64 expected\");\n\
    \n    readWordTo(_tmpReadToken);\n\n    return stringToUnsignedLongLong(*this,\
    \ _tmpReadToken.c_str());\n}\n\nlong long InStream::readLong(long long minv, long\
    \ long maxv, const std::string &variableName) {\n    long long result = readLong();\n\
    \n    if (result < minv || result > maxv) {\n        if (readManyIteration ==\
    \ NO_INDEX) {\n            if (variableName.empty())\n                quit(_wa,\
    \ (\"Integer \" + vtos(result) + \" violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) +\n                           \"]\").c_str());\n\
    \            else\n                quit(_wa, (\"Integer parameter [name=\" + std::string(variableName)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        } else {\n            if (variableName.empty())\n\
    \                quit(_wa, (\"Integer element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n            else\n                quit(_wa,\n          \
    \           (\"Integer element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ + \"] equals to \" +\n                      vtos(result) + \", violates the\
    \ range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        }\n    }\n\n    if (strict && !variableName.empty())\n\
    \        validator.addBoundsHit(variableName, ValidatorBoundsHit(minv == result,\
    \ maxv == result));\n\n    return result;\n}\n\nstd::vector<long long>\nInStream::readLongs(int\
    \ size, long long minv, long long maxv, const std::string &variablesName, int\
    \ indexBase) {\n    __testlib_readMany(readLongs, readLong(minv, maxv, variablesName),\
    \ long long, true)\n}\n\nstd::vector<long long> InStream::readLongs(int size,\
    \ int indexBase) {\n    __testlib_readMany(readLongs, readLong(), long long, true)\n\
    }\n\nunsigned long long\nInStream::readUnsignedLong(unsigned long long minv, unsigned\
    \ long long maxv, const std::string &variableName) {\n    unsigned long long result\
    \ = readUnsignedLong();\n\n    if (result < minv || result > maxv) {\n       \
    \ if (readManyIteration == NO_INDEX) {\n            if (variableName.empty())\n\
    \                quit(_wa,\n                     (\"Unsigned integer \" + vtos(result)\
    \ + \" violates the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ +\n                      \"]\").c_str());\n            else\n              \
    \  quit(_wa,\n                     (\"Unsigned integer parameter [name=\" + std::string(variableName)\
    \ + \"] equals to \" + vtos(result) +\n                      \", violates the\
    \ range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        } else {\n            if (variableName.empty())\n\
    \                quit(_wa,\n                     (\"Unsigned integer element [index=\"\
    \ + vtos(readManyIteration) + \"] equals to \" + vtos(result) +\n            \
    \          \", violates the range [\" + toHumanReadableString(minv) + \", \" +\
    \ toHumanReadableString(maxv) + \"]\").c_str());\n            else\n         \
    \       quit(_wa, (\"Unsigned integer element \" + std::string(variableName) +\
    \ \"[\" + vtos(readManyIteration) +\n                           \"] equals to\
    \ \" + vtos(result) + \", violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) +\n                           \"]\").c_str());\n\
    \        }\n    }\n\n    if (strict && !variableName.empty())\n        validator.addBoundsHit(variableName,\
    \ ValidatorBoundsHit(minv == result, maxv == result));\n\n    return result;\n\
    }\n\nstd::vector<unsigned long long> InStream::readUnsignedLongs(int size, unsigned\
    \ long long minv, unsigned long long maxv,\n                                 \
    \                           const std::string &variablesName, int indexBase) {\n\
    \    __testlib_readMany(readUnsignedLongs, readUnsignedLong(minv, maxv, variablesName),\
    \ unsigned long long, true)\n}\n\nstd::vector<unsigned long long> InStream::readUnsignedLongs(int\
    \ size, int indexBase) {\n    __testlib_readMany(readUnsignedLongs, readUnsignedLong(),\
    \ unsigned long long, true)\n}\n\nunsigned long long\nInStream::readLong(unsigned\
    \ long long minv, unsigned long long maxv, const std::string &variableName) {\n\
    \    return readUnsignedLong(minv, maxv, variableName);\n}\n\nint InStream::readInt()\
    \ {\n    return readInteger();\n}\n\nint InStream::readInt(int minv, int maxv,\
    \ const std::string &variableName) {\n    int result = readInt();\n\n    if (result\
    \ < minv || result > maxv) {\n        if (readManyIteration == NO_INDEX) {\n \
    \           if (variableName.empty())\n                quit(_wa, (\"Integer \"\
    \ + vtos(result) + \" violates the range [\" + toHumanReadableString(minv) + \"\
    , \" + toHumanReadableString(maxv) +\n                           \"]\").c_str());\n\
    \            else\n                quit(_wa, (\"Integer parameter [name=\" + std::string(variableName)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        } else {\n            if (variableName.empty())\n\
    \                quit(_wa, (\"Integer element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n            else\n                quit(_wa,\n          \
    \           (\"Integer element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ + \"] equals to \" +\n                      vtos(result) + \", violates the\
    \ range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n        }\n    }\n\n    if (strict && !variableName.empty())\n\
    \        validator.addBoundsHit(variableName, ValidatorBoundsHit(minv == result,\
    \ maxv == result));\n\n    return result;\n}\n\nint InStream::readInteger(int\
    \ minv, int maxv, const std::string &variableName) {\n    return readInt(minv,\
    \ maxv, variableName);\n}\n\nstd::vector<int> InStream::readInts(int size, int\
    \ minv, int maxv, const std::string &variablesName, int indexBase) {\n    __testlib_readMany(readInts,\
    \ readInt(minv, maxv, variablesName), int, true)\n}\n\nstd::vector<int> InStream::readInts(int\
    \ size, int indexBase) {\n    __testlib_readMany(readInts, readInt(), int, true)\n\
    }\n\nstd::vector<int> InStream::readIntegers(int size, int minv, int maxv, const\
    \ std::string &variablesName, int indexBase) {\n    __testlib_readMany(readIntegers,\
    \ readInt(minv, maxv, variablesName), int, true)\n}\n\nstd::vector<int> InStream::readIntegers(int\
    \ size, int indexBase) {\n    __testlib_readMany(readIntegers, readInt(), int,\
    \ true)\n}\n\ndouble InStream::readReal() {\n    if (!strict && seekEof())\n \
    \       quit(_unexpected_eof, \"Unexpected end of file - double expected\");\n\
    \n    return stringToDouble(*this, readWord().c_str());\n}\n\ndouble InStream::readDouble()\
    \ {\n    return readReal();\n}\n\ndouble InStream::readReal(double minv, double\
    \ maxv, const std::string &variableName) {\n    double result = readReal();\n\n\
    \    if (result < minv || result > maxv) {\n        if (readManyIteration == NO_INDEX)\
    \ {\n            if (variableName.empty())\n                quit(_wa, (\"Double\
    \ \" + vtos(result) + \" violates the range [\" + vtos(minv) + \", \" + vtos(maxv)\
    \ +\n                           \"]\").c_str());\n            else\n         \
    \       quit(_wa, (\"Double parameter [name=\" + std::string(variableName) + \"\
    ] equals to \" + vtos(result) +\n                           \", violates the range\
    \ [\" + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n        } else {\n\
    \            if (variableName.empty())\n                quit(_wa, (\"Double element\
    \ [index=\" + vtos(readManyIteration) + \"] equals to \" + vtos(result) +\n  \
    \                         \", violates the range [\" + vtos(minv) + \", \" + vtos(maxv)\
    \ + \"]\").c_str());\n            else\n                quit(_wa,\n          \
    \           (\"Double element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ + \"] equals to \" +\n                      vtos(result) + \", violates the\
    \ range [\" + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n        }\n\
    \    }\n\n    if (strict && !variableName.empty())\n        validator.addBoundsHit(variableName,\
    \ ValidatorBoundsHit(\n                doubleDelta(minv, result) < ValidatorBoundsHit::EPS,\n\
    \                doubleDelta(maxv, result) < ValidatorBoundsHit::EPS\n       \
    \ ));\n\n    return result;\n}\n\nstd::vector<double>\nInStream::readReals(int\
    \ size, double minv, double maxv, const std::string &variablesName, int indexBase)\
    \ {\n    __testlib_readMany(readReals, readReal(minv, maxv, variablesName), double,\
    \ true)\n}\n\nstd::vector<double> InStream::readReals(int size, int indexBase)\
    \ {\n    __testlib_readMany(readReals, readReal(), double, true)\n}\n\ndouble\
    \ InStream::readDouble(double minv, double maxv, const std::string &variableName)\
    \ {\n    return readReal(minv, maxv, variableName);\n}\n\nstd::vector<double>\n\
    InStream::readDoubles(int size, double minv, double maxv, const std::string &variablesName,\
    \ int indexBase) {\n    __testlib_readMany(readDoubles, readDouble(minv, maxv,\
    \ variablesName), double, true)\n}\n\nstd::vector<double> InStream::readDoubles(int\
    \ size, int indexBase) {\n    __testlib_readMany(readDoubles, readDouble(), double,\
    \ true)\n}\n\ndouble InStream::readStrictReal(double minv, double maxv,\n    \
    \                            int minAfterPointDigitCount, int maxAfterPointDigitCount,\n\
    \                                const std::string &variableName) {\n    if (!strict\
    \ && seekEof())\n        quit(_unexpected_eof, \"Unexpected end of file - strict\
    \ double expected\");\n\n    double result = stringToStrictDouble(*this, readWord().c_str(),\n\
    \                                         minAfterPointDigitCount, maxAfterPointDigitCount);\n\
    \n    if (result < minv || result > maxv) {\n        if (readManyIteration ==\
    \ NO_INDEX) {\n            if (variableName.empty())\n                quit(_wa,\
    \ (\"Strict double \" + vtos(result) + \" violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) +\n                           \"]\").c_str());\n     \
    \       else\n                quit(_wa,\n                     (\"Strict double\
    \ parameter [name=\" + std::string(variableName) + \"] equals to \" + vtos(result)\
    \ +\n                      \", violates the range [\" + vtos(minv) + \", \" +\
    \ vtos(maxv) + \"]\").c_str());\n        } else {\n            if (variableName.empty())\n\
    \                quit(_wa, (\"Strict double element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n                           \", violates\
    \ the range [\" + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n      \
    \      else\n                quit(_wa, (\"Strict double element \" + std::string(variableName)\
    \ + \"[\" + vtos(readManyIteration) +\n                           \"] equals to\
    \ \" + vtos(result) + \", violates the range [\" + vtos(minv) + \", \" + vtos(maxv)\
    \ +\n                           \"]\").c_str());\n        }\n    }\n\n    if (strict\
    \ && !variableName.empty())\n        validator.addBoundsHit(variableName, ValidatorBoundsHit(\n\
    \                doubleDelta(minv, result) < ValidatorBoundsHit::EPS,\n      \
    \          doubleDelta(maxv, result) < ValidatorBoundsHit::EPS\n        ));\n\n\
    \    return result;\n}\n\nstd::vector<double> InStream::readStrictReals(int size,\
    \ double minv, double maxv,\n                                              int\
    \ minAfterPointDigitCount, int maxAfterPointDigitCount,\n                    \
    \                          const std::string &variablesName, int indexBase) {\n\
    \    __testlib_readMany(readStrictReals,\n                       readStrictReal(minv,\
    \ maxv, minAfterPointDigitCount, maxAfterPointDigitCount, variablesName),\n  \
    \                     double, true)\n}\n\ndouble InStream::readStrictDouble(double\
    \ minv, double maxv,\n                                  int minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n                                  const std::string\
    \ &variableName) {\n    return readStrictReal(minv, maxv,\n                  \
    \        minAfterPointDigitCount, maxAfterPointDigitCount,\n                 \
    \         variableName);\n}\n\nstd::vector<double> InStream::readStrictDoubles(int\
    \ size, double minv, double maxv,\n                                          \
    \      int minAfterPointDigitCount, int maxAfterPointDigitCount,\n           \
    \                                     const std::string &variablesName, int indexBase)\
    \ {\n    __testlib_readMany(readStrictDoubles,\n                       readStrictDouble(minv,\
    \ maxv, minAfterPointDigitCount, maxAfterPointDigitCount, variablesName),\n  \
    \                     double, true)\n}\n\nbool InStream::eof() {\n    if (!strict\
    \ && NULL == reader)\n        return true;\n\n    return reader->eof();\n}\n\n\
    bool InStream::seekEof() {\n    if (!strict && NULL == reader)\n        return\
    \ true;\n    skipBlanks();\n    return eof();\n}\n\nbool InStream::eoln() {\n\
    \    if (!strict && NULL == reader)\n        return true;\n\n    int c = reader->nextChar();\n\
    \n    if (!strict) {\n        if (c == EOFC)\n            return true;\n\n   \
    \     if (c == CR) {\n            c = reader->nextChar();\n\n            if (c\
    \ != LF) {\n                reader->unreadChar(c);\n                reader->unreadChar(CR);\n\
    \                return false;\n            } else\n                return true;\n\
    \        }\n\n        if (c == LF)\n            return true;\n\n        reader->unreadChar(c);\n\
    \        return false;\n    } else {\n        bool returnCr = false;\n\n#if (defined(ON_WINDOWS)\
    \ && !defined(FOR_LINUX)) || defined(FOR_WINDOWS)\n        if (c != CR) {\n  \
    \          reader->unreadChar(c);\n            return false;\n        } else {\n\
    \            if (!returnCr)\n                returnCr = true;\n            c =\
    \ reader->nextChar();\n        }\n#endif\n        if (c != LF) {\n           \
    \ reader->unreadChar(c);\n            if (returnCr)\n                reader->unreadChar(CR);\n\
    \            return false;\n        }\n\n        return true;\n    }\n}\n\nvoid\
    \ InStream::readEoln() {\n    lastLine = reader->getLine();\n    if (!eoln())\n\
    \        quit(_pe, \"Expected EOLN\");\n}\n\nvoid InStream::readEof() {\n    lastLine\
    \ = reader->getLine();\n    if (!eof())\n        quit(_pe, \"Expected EOF\");\n\
    \n    if (TestlibFinalizeGuard::alive && this == &inf)\n        testlibFinalizeGuard.readEofCount++;\n\
    }\n\nbool InStream::seekEoln() {\n    if (!strict && NULL == reader)\n       \
    \ return true;\n\n    int cur;\n    do {\n        cur = reader->nextChar();\n\
    \    } while (cur == SPACE || cur == TAB);\n\n    reader->unreadChar(cur);\n \
    \   return eoln();\n}\n\nvoid InStream::nextLine() {\n    readLine();\n}\n\nvoid\
    \ InStream::readStringTo(std::string &result) {\n    if (NULL == reader)\n   \
    \     quit(_pe, \"Expected line\");\n\n    result.clear();\n\n    for (;;) {\n\
    \        int cur = reader->curChar();\n\n        if (cur == LF || cur == EOFC)\n\
    \            break;\n\n        if (cur == CR) {\n            cur = reader->nextChar();\n\
    \            if (reader->curChar() == LF) {\n                reader->unreadChar(cur);\n\
    \                break;\n            }\n        }\n\n        lastLine = reader->getLine();\n\
    \        result += char(reader->nextChar());\n    }\n\n    if (strict)\n     \
    \   readEoln();\n    else\n        eoln();\n}\n\nstd::string InStream::readString()\
    \ {\n    readStringTo(_tmpReadToken);\n    return _tmpReadToken;\n}\n\nstd::vector<std::string>\
    \ InStream::readStrings(int size, int indexBase) {\n    __testlib_readMany(readStrings,\
    \ readString(), std::string, false)\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result, const pattern &p, const std::string &variableName) {\n    readStringTo(result);\n\
    \    if (!p.matches(result)) {\n        if (readManyIteration == NO_INDEX) {\n\
    \            if (variableName.empty())\n                quit(_wa, (\"Line \\\"\
    \" + __testlib_part(result) + \"\\\" doesn't correspond to pattern \\\"\" + p.src()\
    \ +\n                           \"\\\"\").c_str());\n            else\n      \
    \          quit(_wa, (\"Line [name=\" + variableName + \"] equals to \\\"\" +\
    \ __testlib_part(result) +\n                           \"\\\", doesn't correspond\
    \ to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n        } else {\n      \
    \      if (variableName.empty())\n                quit(_wa,\n                \
    \     (\"Line element [index=\" + vtos(readManyIteration) + \"] equals to \\\"\
    \" + __testlib_part(result) +\n                      \"\\\" doesn't correspond\
    \ to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n            else\n      \
    \          quit(_wa,\n                     (\"Line element \" + std::string(variableName)\
    \ + \"[\" + vtos(readManyIteration) + \"] equals to \\\"\" +\n               \
    \       __testlib_part(result) + \"\\\", doesn't correspond to pattern \\\"\"\
    \ + p.src() + \"\\\"\").c_str());\n        }\n    }\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName) {\n    readStringTo(result,\
    \ pattern(ptrn), variableName);\n}\n\nstd::string InStream::readString(const pattern\
    \ &p, const std::string &variableName) {\n    readStringTo(_tmpReadToken, p, variableName);\n\
    \    return _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readStrings(int\
    \ size, const pattern &p, const std::string &variablesName, int indexBase) {\n\
    \    __testlib_readMany(readStrings, readString(p, variablesName), std::string,\
    \ false)\n}\n\nstd::string InStream::readString(const std::string &ptrn, const\
    \ std::string &variableName) {\n    readStringTo(_tmpReadToken, ptrn, variableName);\n\
    \    return _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readStrings(int\
    \ size, const std::string &ptrn, const std::string &variablesName, int indexBase)\
    \ {\n    pattern p(ptrn);\n    __testlib_readMany(readStrings, readString(p, variablesName),\
    \ std::string, false)\n}\n\nvoid InStream::readLineTo(std::string &result) {\n\
    \    readStringTo(result);\n}\n\nstd::string InStream::readLine() {\n    return\
    \ readString();\n}\n\nstd::vector<std::string> InStream::readLines(int size, int\
    \ indexBase) {\n    __testlib_readMany(readLines, readString(), std::string, false)\n\
    }\n\nvoid InStream::readLineTo(std::string &result, const pattern &p, const std::string\
    \ &variableName) {\n    readStringTo(result, p, variableName);\n}\n\nvoid InStream::readLineTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName) {\n    readStringTo(result,\
    \ ptrn, variableName);\n}\n\nstd::string InStream::readLine(const pattern &p,\
    \ const std::string &variableName) {\n    return readString(p, variableName);\n\
    }\n\nstd::vector<std::string>\nInStream::readLines(int size, const pattern &p,\
    \ const std::string &variablesName, int indexBase) {\n    __testlib_readMany(readLines,\
    \ readString(p, variablesName), std::string, false)\n}\n\nstd::string InStream::readLine(const\
    \ std::string &ptrn, const std::string &variableName) {\n    return readString(ptrn,\
    \ variableName);\n}\n\nstd::vector<std::string>\nInStream::readLines(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \    pattern p(ptrn);\n    __testlib_readMany(readLines, readString(p, variablesName),\
    \ std::string, false)\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 3,\
    \ 4)))\n#endif\nvoid InStream::ensuref(bool cond, const char *format, ...) {\n\
    \    if (!cond) {\n        FMT_TO_RESULT(format, format, message);\n        this->__testlib_ensure(cond,\
    \ message);\n    }\n}\n\nvoid InStream::__testlib_ensure(bool cond, std::string\
    \ message) {\n    if (!cond)\n        this->quit(_wa, message.c_str());\n}\n\n\
    void InStream::close() {\n    if (NULL != reader) {\n        reader->close();\n\
    \        delete reader;\n        reader = NULL;\n    }\n\n    opened = false;\n\
    }\n\nNORETURN void quit(TResult result, const std::string &msg) {\n    ouf.quit(result,\
    \ msg.c_str());\n}\n\nNORETURN void quit(TResult result, const char *msg) {\n\
    \    ouf.quit(result, msg);\n}\n\nNORETURN void __testlib_quitp(double points,\
    \ const char *message) {\n    __testlib_points = points;\n    std::string stringPoints\
    \ = removeDoubleTrailingZeroes(format(\"%.10f\", points));\n\n    std::string\
    \ quitMessage;\n    if (NULL == message || 0 == strlen(message))\n        quitMessage\
    \ = stringPoints;\n    else\n        quitMessage = stringPoints + \" \" + message;\n\
    \n    quit(_points, quitMessage.c_str());\n}\n\nNORETURN void __testlib_quitp(int\
    \ points, const char *message) {\n    __testlib_points = points;\n    std::string\
    \ stringPoints = format(\"%d\", points);\n\n    std::string quitMessage;\n   \
    \ if (NULL == message || 0 == strlen(message))\n        quitMessage = stringPoints;\n\
    \    else\n        quitMessage = stringPoints + \" \" + message;\n\n    quit(_points,\
    \ quitMessage.c_str());\n}\n\nNORETURN void quitp(float points, const std::string\
    \ &message = \"\") {\n    __testlib_quitp(double(points), message.c_str());\n\
    }\n\nNORETURN void quitp(double points, const std::string &message = \"\") {\n\
    \    __testlib_quitp(points, message.c_str());\n}\n\nNORETURN void quitp(long\
    \ double points, const std::string &message = \"\") {\n    __testlib_quitp(double(points),\
    \ message.c_str());\n}\n\nNORETURN void quitp(int points, const std::string &message\
    \ = \"\") {\n    __testlib_quitp(points, message.c_str());\n}\n\ntemplate<typename\
    \ F>\n#ifdef __GNUC__\n__attribute__ ((format (printf, 2, 3)))\n#endif\nNORETURN\
    \ void quitp(F points, const char *format, ...) {\n    FMT_TO_RESULT(format, format,\
    \ message);\n    quitp(points, message);\n}\n\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 2, 3)))\n#endif\nNORETURN void quitf(TResult result, const\
    \ char *format, ...) {\n    FMT_TO_RESULT(format, format, message);\n    quit(result,\
    \ message);\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 3, 4)))\n#endif\n\
    void quitif(bool condition, TResult result, const char *format, ...) {\n    if\
    \ (condition) {\n        FMT_TO_RESULT(format, format, message);\n        quit(result,\
    \ message);\n    }\n}\n\nNORETURN void __testlib_help() {\n    InStream::textColor(InStream::LightCyan);\n\
    \    std::fprintf(stderr, \"TESTLIB %s, https://github.com/MikeMirzayanov/testlib/\
    \ \", VERSION);\n    std::fprintf(stderr, \"by Mike Mirzayanov, copyright(c) 2005-2020\\\
    n\");\n    std::fprintf(stderr, \"Checker name: \\\"%s\\\"\\n\", checkerName.c_str());\n\
    \    InStream::textColor(InStream::LightGray);\n\n    std::fprintf(stderr, \"\\\
    n\");\n    std::fprintf(stderr, \"Latest features: \\n\");\n    for (size_t i\
    \ = 0; i < sizeof(latestFeatures) / sizeof(char *); i++) {\n        std::fprintf(stderr,\
    \ \"*) %s\\n\", latestFeatures[i]);\n    }\n    std::fprintf(stderr, \"\\n\");\n\
    \n    std::fprintf(stderr, \"Program must be run with the following arguments:\
    \ \\n\");\n    std::fprintf(stderr, \"    <input-file> <output-file> <answer-file>\
    \ [<report-file> [<-appes>]]\\n\\n\");\n\n    std::exit(FAIL_EXIT_CODE);\n}\n\n\
    static void __testlib_ensuresPreconditions() {\n    // testlib assumes: sizeof(int)\
    \ = 4.\n    __TESTLIB_STATIC_ASSERT(sizeof(int) == 4);\n\n    // testlib assumes:\
    \ INT_MAX == 2147483647.\n    __TESTLIB_STATIC_ASSERT(INT_MAX == 2147483647);\n\
    \n    // testlib assumes: sizeof(long long) = 8.\n    __TESTLIB_STATIC_ASSERT(sizeof(long\
    \ long) == 8);\n\n    // testlib assumes: sizeof(double) = 8.\n    __TESTLIB_STATIC_ASSERT(sizeof(double)\
    \ == 8);\n\n    // testlib assumes: no -ffast-math.\n    if (!__testlib_isNaN(+__testlib_nan()))\n\
    \        quit(_fail, \"Function __testlib_isNaN is not working correctly: possible\
    \ reason is '-ffast-math'\");\n    if (!__testlib_isNaN(-__testlib_nan()))\n \
    \       quit(_fail, \"Function __testlib_isNaN is not working correctly: possible\
    \ reason is '-ffast-math'\");\n}\n\nvoid registerGen(int argc, char *argv[], int\
    \ randomGeneratorVersion) {\n    if (randomGeneratorVersion < 0 || randomGeneratorVersion\
    \ > 1)\n        quitf(_fail, \"Random generator version is expected to be 0 or\
    \ 1.\");\n    random_t::version = randomGeneratorVersion;\n\n    __testlib_ensuresPreconditions();\n\
    \n    testlibMode = _generator;\n    __testlib_set_binary(stdin);\n    rnd.setSeed(argc,\
    \ argv);\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\n    prepareOpts(argc,\
    \ argv);\n#endif\n}\n\n#ifdef USE_RND_AS_BEFORE_087\nvoid registerGen(int argc,\
    \ char* argv[])\n{\n    registerGen(argc, argv, 0);\n}\n#else\n#ifdef __GNUC__\n\
    #if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 4))\n__attribute__\
    \ ((deprecated(\"Use registerGen(argc, argv, 0) or registerGen(argc, argv, 1).\"\
    \n\" The third parameter stands for the random generator version.\"\n\" If you\
    \ are trying to compile old generator use macro -DUSE_RND_AS_BEFORE_087 or registerGen(argc,\
    \ argv, 0).\"\n\" Version 1 has been released on Spring, 2013. Use it to write\
    \ new generators.\")))\n#else\n__attribute__ ((deprecated))\n#endif\n#endif\n\
    #ifdef _MSC_VER\n__declspec(deprecated(\"Use registerGen(argc, argv, 0) or registerGen(argc,\
    \ argv, 1).\"\n        \" The third parameter stands for the random generator\
    \ version.\"\n        \" If you are trying to compile old generator use macro\
    \ -DUSE_RND_AS_BEFORE_087 or registerGen(argc, argv, 0).\"\n        \" Version\
    \ 1 has been released on Spring, 2013. Use it to write new generators.\"))\n#endif\n\
    void registerGen(int argc, char *argv[]) {\n    std::fprintf(stderr, \"Use registerGen(argc,\
    \ argv, 0) or registerGen(argc, argv, 1).\"\n                         \" The third\
    \ parameter stands for the random generator version.\"\n                     \
    \    \" If you are trying to compile old generator use macro -DUSE_RND_AS_BEFORE_087\
    \ or registerGen(argc, argv, 0).\"\n                         \" Version 1 has\
    \ been released on Spring, 2013. Use it to write new generators.\\n\\n\");\n \
    \   registerGen(argc, argv, 0);\n}\n#endif\n\nvoid registerInteraction(int argc,\
    \ char *argv[]) {\n    __testlib_ensuresPreconditions();\n\n    testlibMode =\
    \ _interactor;\n    __testlib_set_binary(stdin);\n\n    if (argc > 1 && !strcmp(\"\
    --help\", argv[1]))\n        __testlib_help();\n\n    if (argc < 3 || argc > 6)\
    \ {\n        quit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n                    std::string(\"<input-file> <output-file>\
    \ [<answer-file> [<report-file> [<-appes>]]]\") +\n                    \"\\nUse\
    \ \\\"--help\\\" to get help information\");\n    }\n\n    if (argc <= 4) {\n\
    \        resultName = \"\";\n        appesMode = false;\n    }\n\n#ifndef EJUDGE\n\
    \    if (argc == 5) {\n        resultName = argv[4];\n        appesMode = false;\n\
    \    }\n\n    if (argc == 6) {\n        if (strcmp(\"-APPES\", argv[5]) && strcmp(\"\
    -appes\", argv[5])) {\n            quit(_fail, std::string(\"Program must be run\
    \ with the following arguments: \") +\n                        \"<input-file>\
    \ <output-file> <answer-file> [<report-file> [<-appes>]]\");\n        } else {\n\
    \            resultName = argv[4];\n            appesMode = true;\n        }\n\
    \    }\n#endif\n\n    inf.init(argv[1], _input);\n\n    tout.open(argv[2], std::ios_base::out);\n\
    \    if (tout.fail() || !tout.is_open())\n        quit(_fail, std::string(\"Can\
    \ not write to the test-output-file '\") + argv[2] + std::string(\"'\"));\n\n\
    \    ouf.init(stdin, _output);\n\n    if (argc >= 4)\n        ans.init(argv[3],\
    \ _answer);\n    else\n        ans.name = \"unopened answer stream\";\n}\n\nvoid\
    \ registerValidation() {\n    __testlib_ensuresPreconditions();\n\n    testlibMode\
    \ = _validator;\n    __testlib_set_binary(stdin);\n\n    inf.init(stdin, _input);\n\
    \    inf.strict = true;\n}\n\nvoid registerValidation(int argc, char *argv[])\
    \ {\n    registerValidation();\n    validator.initialize();\n\n    for (int i\
    \ = 1; i < argc; i++) {\n        if (!strcmp(\"--testset\", argv[i])) {\n    \
    \        if (i + 1 < argc && strlen(argv[i + 1]) > 0)\n                validator.setTestset(argv[++i]);\n\
    \            else\n                quit(_fail, std::string(\"Validator must be\
    \ run with the following arguments: \") +\n                            \"[--testset\
    \ testset] [--group group] [--testOverviewLogFileName fileName]\");\n        }\n\
    \        if (!strcmp(\"--group\", argv[i])) {\n            if (i + 1 < argc)\n\
    \                validator.setGroup(argv[++i]);\n            else\n          \
    \      quit(_fail, std::string(\"Validator must be run with the following arguments:\
    \ \") +\n                            \"[--testset testset] [--group group] [--testOverviewLogFileName\
    \ fileName]\");\n        }\n        if (!strcmp(\"--testOverviewLogFileName\"\
    , argv[i])) {\n            if (i + 1 < argc)\n                validator.setTestOverviewLogFileName(argv[++i]);\n\
    \            else\n                quit(_fail, std::string(\"Validator must be\
    \ run with the following arguments: \") +\n                            \"[--testset\
    \ testset] [--group group] [--testOverviewLogFileName fileName]\");\n        }\n\
    \    }\n}\n\nvoid addFeature(const std::string &feature) {\n    if (testlibMode\
    \ != _validator)\n        quit(_fail, \"Features are supported in validators only.\"\
    );\n    validator.addFeature(feature);\n}\n\nvoid feature(const std::string &feature)\
    \ {\n    if (testlibMode != _validator)\n        quit(_fail, \"Features are supported\
    \ in validators only.\");\n    validator.feature(feature);\n}\n\nvoid registerTestlibCmd(int\
    \ argc, char *argv[]) {\n    __testlib_ensuresPreconditions();\n\n    testlibMode\
    \ = _checker;\n    __testlib_set_binary(stdin);\n\n    if (argc > 1 && !strcmp(\"\
    --help\", argv[1]))\n        __testlib_help();\n\n    if (argc < 4 || argc > 6)\
    \ {\n        quit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n                    std::string(\"<input-file> <output-file>\
    \ <answer-file> [<report-file> [<-appes>]]\") +\n                    \"\\nUse\
    \ \\\"--help\\\" to get help information\");\n    }\n\n    if (argc == 4) {\n\
    \        resultName = \"\";\n        appesMode = false;\n    }\n\n    if (argc\
    \ == 5) {\n        resultName = argv[4];\n        appesMode = false;\n    }\n\n\
    \    if (argc == 6) {\n        if (strcmp(\"-APPES\", argv[5]) && strcmp(\"-appes\"\
    , argv[5])) {\n            quit(_fail, std::string(\"Program must be run with\
    \ the following arguments: \") +\n                        \"<input-file> <output-file>\
    \ <answer-file> [<report-file> [<-appes>]]\");\n        } else {\n           \
    \ resultName = argv[4];\n            appesMode = true;\n        }\n    }\n\n \
    \   inf.init(argv[1], _input);\n    ouf.init(argv[2], _output);\n    ans.init(argv[3],\
    \ _answer);\n}\n\nvoid registerTestlib(int argc, ...) {\n    if (argc < 3 || argc\
    \ > 5)\n        quit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n                    \"<input-file> <output-file> <answer-file>\
    \ [<report-file> [<-appes>]]\");\n\n    char **argv = new char *[argc + 1];\n\n\
    \    va_list ap;\n    va_start(ap, argc);\n    argv[0] = NULL;\n    for (int i\
    \ = 0; i < argc; i++) {\n        argv[i + 1] = va_arg(ap, char*);\n    }\n   \
    \ va_end(ap);\n\n    registerTestlibCmd(argc + 1, argv);\n    delete[] argv;\n\
    }\n\nstatic inline void __testlib_ensure(bool cond, const std::string &msg) {\n\
    \    if (!cond)\n        quit(_fail, msg.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__((unused))\n\
    #endif\nstatic inline void __testlib_ensure(bool cond, const char *msg) {\n  \
    \  if (!cond)\n        quit(_fail, msg);\n}\n\n#define ensure(cond) __testlib_ensure(cond,\
    \ \"Condition failed: \\\"\" #cond \"\\\"\")\n#define STRINGIZE_DETAIL(x) #x\n\
    #define STRINGIZE(x) STRINGIZE_DETAIL(x)\n#define ensure_ext(cond) __testlib_ensure(cond,\
    \ \"Line \" STRINGIZE(__LINE__) \": Condition failed: \\\"\" #cond \"\\\"\")\n\
    \n#ifdef __GNUC__\n__attribute__ ((format (printf, 2, 3)))\n#endif\ninline void\
    \ ensuref(bool cond, const char *format, ...) {\n    if (!cond) {\n        FMT_TO_RESULT(format,\
    \ format, message);\n        __testlib_ensure(cond, message);\n    }\n}\n\nNORETURN\
    \ static void __testlib_fail(const std::string &message) {\n    quitf(_fail, \"\
    %s\", message.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf,\
    \ 1, 2)))\n#endif\nvoid setName(const char *format, ...) {\n    FMT_TO_RESULT(format,\
    \ format, name);\n    checkerName = name;\n}\n\n/* \n * Do not use random_shuffle,\
    \ because it will produce different result\n * for different C++ compilers.\n\
    \ *\n * This implementation uses testlib random_t to produce random numbers, so\n\
    \ * it is stable.\n */\ntemplate<typename _RandomAccessIter>\nvoid shuffle(_RandomAccessIter\
    \ __first, _RandomAccessIter __last) {\n    if (__first == __last) return;\n \
    \   for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)\n        std::iter_swap(__i,\
    \ __first + rnd.next(int(__i - __first) + 1));\n}\n\n\ntemplate<typename _RandomAccessIter>\n\
    #if defined(__GNUC__) && !defined(__clang__)\n__attribute__ ((error(\"Don't use\
    \ random_shuffle(), use shuffle() instead\")))\n#endif\nvoid random_shuffle(_RandomAccessIter,\
    \ _RandomAccessIter) {\n    quitf(_fail, \"Don't use random_shuffle(), use shuffle()\
    \ instead\");\n}\n\n#ifdef __GLIBC__\n#  define RAND_THROW_STATEMENT throw()\n\
    #else\n#  define RAND_THROW_STATEMENT\n#endif\n\n#if defined(__GNUC__) && !defined(__clang__)\n\
    \n__attribute__ ((error(\"Don't use rand(), use rnd.next() instead\")))\n#endif\n\
    #ifdef _MSC_VER\n#   pragma warning( disable : 4273 )\n#endif\nint rand() RAND_THROW_STATEMENT\n\
    {\n    quitf(_fail, \"Don't use rand(), use rnd.next() instead\");\n\n    /* This\
    \ line never runs. */\n    //throw \"Don't use rand(), use rnd.next() instead\"\
    ;\n}\n\n#if defined(__GNUC__) && !defined(__clang__)\n\n__attribute__ ((error(\"\
    Don't use srand(), you should use \"\n\"'registerGen(argc, argv, 1);' to initialize\
    \ generator seed \"\n\"by hash code of the command line params. The third parameter\
    \ \"\n\"is randomGeneratorVersion (currently the latest is 1).\")))\n#endif\n\
    #ifdef _MSC_VER\n#   pragma warning( disable : 4273 )\n#endif\nvoid srand(unsigned\
    \ int seed) RAND_THROW_STATEMENT\n{\n    quitf(_fail, \"Don't use srand(), you\
    \ should use \"\n                 \"'registerGen(argc, argv, 1);' to initialize\
    \ generator seed \"\n                 \"by hash code of the command line params.\
    \ The third parameter \"\n                 \"is randomGeneratorVersion (currently\
    \ the latest is 1) [ignored seed=%u].\", seed);\n}\n\nvoid startTest(int test)\
    \ {\n    const std::string testFileName = vtos(test);\n    if (NULL == freopen(testFileName.c_str(),\
    \ \"wt\", stdout))\n        __testlib_fail(\"Unable to write file '\" + testFileName\
    \ + \"'\");\n}\n\ninline std::string upperCase(std::string s) {\n    for (size_t\
    \ i = 0; i < s.length(); i++)\n        if ('a' <= s[i] && s[i] <= 'z')\n     \
    \       s[i] = char(s[i] - 'a' + 'A');\n    return s;\n}\n\ninline std::string\
    \ lowerCase(std::string s) {\n    for (size_t i = 0; i < s.length(); i++)\n  \
    \      if ('A' <= s[i] && s[i] <= 'Z')\n            s[i] = char(s[i] - 'A' + 'a');\n\
    \    return s;\n}\n\ninline std::string compress(const std::string &s) {\n   \
    \ return __testlib_part(s);\n}\n\ninline std::string englishEnding(int x) {\n\
    \    x %= 100;\n    if (x / 10 == 1)\n        return \"th\";\n    if (x % 10 ==\
    \ 1)\n        return \"st\";\n    if (x % 10 == 2)\n        return \"nd\";\n \
    \   if (x % 10 == 3)\n        return \"rd\";\n    return \"th\";\n}\n\ntemplate<typename\
    \ _ForwardIterator, typename _Separator>\nstd::string join(_ForwardIterator first,\
    \ _ForwardIterator last, _Separator separator) {\n    std::stringstream ss;\n\
    \    bool repeated = false;\n    for (_ForwardIterator i = first; i != last; i++)\
    \ {\n        if (repeated)\n            ss << separator;\n        else\n     \
    \       repeated = true;\n        ss << *i;\n    }\n    return ss.str();\n}\n\n\
    template<typename _ForwardIterator>\nstd::string join(_ForwardIterator first,\
    \ _ForwardIterator last) {\n    return join(first, last, ' ');\n}\n\ntemplate<typename\
    \ _Collection, typename _Separator>\nstd::string join(const _Collection &collection,\
    \ _Separator separator) {\n    return join(collection.begin(), collection.end(),\
    \ separator);\n}\n\ntemplate<typename _Collection>\nstd::string join(const _Collection\
    \ &collection) {\n    return join(collection, ' ');\n}\n\n/**\n * Splits string\
    \ s by character separator returning exactly k+1 items,\n * where k is the number\
    \ of separator occurences.\n */\nstd::vector<std::string> split(const std::string\
    \ &s, char separator) {\n    std::vector<std::string> result;\n    std::string\
    \ item;\n    for (size_t i = 0; i < s.length(); i++)\n        if (s[i] == separator)\
    \ {\n            result.push_back(item);\n            item = \"\";\n        }\
    \ else\n            item += s[i];\n    result.push_back(item);\n    return result;\n\
    }\n\n/**\n * Splits string s by character separators returning exactly k+1 items,\n\
    \ * where k is the number of separator occurences.\n */\nstd::vector<std::string>\
    \ split(const std::string &s, const std::string &separators) {\n    if (separators.empty())\n\
    \        return std::vector<std::string>(1, s);\n\n    std::vector<bool> isSeparator(256);\n\
    \    for (size_t i = 0; i < separators.size(); i++)\n        isSeparator[(unsigned\
    \ char) (separators[i])] = true;\n\n    std::vector<std::string> result;\n   \
    \ std::string item;\n    for (size_t i = 0; i < s.length(); i++)\n        if (isSeparator[(unsigned\
    \ char) (s[i])]) {\n            result.push_back(item);\n            item = \"\
    \";\n        } else\n            item += s[i];\n    result.push_back(item);\n\
    \    return result;\n}\n\n/**\n * Splits string s by character separator returning\
    \ non-empty items.\n */\nstd::vector<std::string> tokenize(const std::string &s,\
    \ char separator) {\n    std::vector<std::string> result;\n    std::string item;\n\
    \    for (size_t i = 0; i < s.length(); i++)\n        if (s[i] == separator) {\n\
    \            if (!item.empty())\n                result.push_back(item);\n   \
    \         item = \"\";\n        } else\n            item += s[i];\n    if (!item.empty())\n\
    \        result.push_back(item);\n    return result;\n}\n\n/**\n * Splits string\
    \ s by character separators returning non-empty items.\n */\nstd::vector<std::string>\
    \ tokenize(const std::string &s, const std::string &separators) {\n    if (separators.empty())\n\
    \        return std::vector<std::string>(1, s);\n\n    std::vector<bool> isSeparator(256);\n\
    \    for (size_t i = 0; i < separators.size(); i++)\n        isSeparator[(unsigned\
    \ char) (separators[i])] = true;\n\n    std::vector<std::string> result;\n   \
    \ std::string item;\n    for (size_t i = 0; i < s.length(); i++)\n        if (isSeparator[(unsigned\
    \ char) (s[i])]) {\n            if (!item.empty())\n                result.push_back(item);\n\
    \            item = \"\";\n        } else\n            item += s[i];\n\n    if\
    \ (!item.empty())\n        result.push_back(item);\n\n    return result;\n}\n\n\
    NORETURN void __testlib_expectedButFound(TResult result, std::string expected,\
    \ std::string found, const char *prepend) {\n    std::string message;\n    if\
    \ (strlen(prepend) != 0)\n        message = format(\"%s: expected '%s', but found\
    \ '%s'\",\n                         compress(prepend).c_str(), compress(expected).c_str(),\
    \ compress(found).c_str());\n    else\n        message = format(\"expected '%s',\
    \ but found '%s'\",\n                         compress(expected).c_str(), compress(found).c_str());\n\
    \    quit(result, message);\n}\n\nNORETURN void __testlib_expectedButFound(TResult\
    \ result, double expected, double found, const char *prepend) {\n    std::string\
    \ expectedString = removeDoubleTrailingZeroes(format(\"%.12f\", expected));\n\
    \    std::string foundString = removeDoubleTrailingZeroes(format(\"%.12f\", found));\n\
    \    __testlib_expectedButFound(result, expectedString, foundString, prepend);\n\
    }\n\ntemplate<typename T>\n#ifdef __GNUC__\n__attribute__ ((format (printf, 4,\
    \ 5)))\n#endif\nNORETURN void expectedButFound(TResult result, T expected, T found,\
    \ const char *prependFormat = \"\", ...) {\n    FMT_TO_RESULT(prependFormat, prependFormat,\
    \ prepend);\n    std::string expectedString = vtos(expected);\n    std::string\
    \ foundString = vtos(found);\n    __testlib_expectedButFound(result, expectedString,\
    \ foundString, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<std::string>(TResult\
    \ result, std::string expected, std::string found, const char *prependFormat,\
    \ ...) {\n    FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n    __testlib_expectedButFound(result,\
    \ expected, found, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound<double>(TResult\
    \ result, double expected, double found, const char *prependFormat, ...) {\n \
    \   FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n    std::string expectedString\
    \ = removeDoubleTrailingZeroes(format(\"%.12f\", expected));\n    std::string\
    \ foundString = removeDoubleTrailingZeroes(format(\"%.12f\", found));\n    __testlib_expectedButFound(result,\
    \ expectedString, foundString, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n\
    __attribute__ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<const\
    \ char *>(TResult result, const char *expected, const char *found, const char\
    \ *prependFormat,\n                               ...) {\n    FMT_TO_RESULT(prependFormat,\
    \ prependFormat, prepend);\n    __testlib_expectedButFound(result, std::string(expected),\
    \ std::string(found), prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound<float>(TResult\
    \ result, float expected, float found, const char *prependFormat, ...) {\n   \
    \ FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n    __testlib_expectedButFound(result,\
    \ double(expected), double(found), prepend.c_str());\n}\n\ntemplate<>\n#ifdef\
    \ __GNUC__\n__attribute__ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<long\
    \ double>(TResult result, long double expected, long double found, const char\
    \ *prependFormat, ...) {\n    FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n\
    \    __testlib_expectedButFound(result, double(expected), double(found), prepend.c_str());\n\
    }\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\ntemplate<typename T>\nstruct\
    \ is_iterable {\n    template<typename U>\n    static char test(typename U::iterator\
    \ *x);\n\n    template<typename U>\n    static long test(U *x);\n\n    static\
    \ const bool value = sizeof(test<T>(0)) == 1;\n};\n\ntemplate<bool B, class T\
    \ = void>\nstruct __testlib_enable_if {\n};\n\ntemplate<class T>\nstruct __testlib_enable_if<true,\
    \ T> {\n    typedef T type;\n};\n\ntemplate<typename T>\ntypename __testlib_enable_if<!is_iterable<T>::value,\
    \ void>::type __testlib_print_one(const T &t) {\n    std::cout << t;\n}\n\ntemplate<typename\
    \ T>\ntypename __testlib_enable_if<is_iterable<T>::value, void>::type __testlib_print_one(const\
    \ T &t) {\n    bool first = true;\n    for (typename T::const_iterator i = t.begin();\
    \ i != t.end(); i++) {\n        if (first)\n            first = false;\n     \
    \   else\n            std::cout << \" \";\n        std::cout << *i;\n    }\n}\n\
    \ntemplate<>\ntypename __testlib_enable_if<is_iterable<std::string>::value, void>::type\n\
    __testlib_print_one<std::string>(const std::string &t) {\n    std::cout << t;\n\
    }\n\ntemplate<typename A, typename B>\nvoid __println_range(A begin, B end) {\n\
    \    bool first = true;\n    for (B i = B(begin); i != end; i++) {\n        if\
    \ (first)\n            first = false;\n        else\n            std::cout <<\
    \ \" \";\n        __testlib_print_one(*i);\n    }\n    std::cout << std::endl;\n\
    }\n\ntemplate<class T, class Enable = void>\nstruct is_iterator {\n    static\
    \ T makeT();\n\n    typedef void *twoptrs[2];\n\n    static twoptrs &test(...);\n\
    \n    template<class R>\n    static typename R::iterator_category *test(R);\n\n\
    \    template<class R>\n    static void *test(R *);\n\n    static const bool value\
    \ = sizeof(test(makeT())) == sizeof(void *);\n};\n\ntemplate<class T>\nstruct\
    \ is_iterator<T, typename __testlib_enable_if<std::is_array<T>::value>::type>\
    \ {\n    static const bool value = false;\n};\n\ntemplate<typename A, typename\
    \ B>\ntypename __testlib_enable_if<!is_iterator<B>::value, void>::type println(const\
    \ A &a, const B &b) {\n    __testlib_print_one(a);\n    std::cout << \" \";\n\
    \    __testlib_print_one(b);\n    std::cout << std::endl;\n}\n\ntemplate<typename\
    \ A, typename B>\ntypename __testlib_enable_if<is_iterator<B>::value, void>::type\
    \ println(const A &a, const B &b) {\n    __println_range(a, b);\n}\n\ntemplate<typename\
    \ A>\nvoid println(const A *a, const A *b) {\n    __println_range(a, b);\n}\n\n\
    template<>\nvoid println<char>(const char *a, const char *b) {\n    __testlib_print_one(a);\n\
    \    std::cout << \" \";\n    __testlib_print_one(b);\n    std::cout << std::endl;\n\
    }\n\ntemplate<typename T>\nvoid println(const T &x) {\n    __testlib_print_one(x);\n\
    \    std::cout << std::endl;\n}\n\ntemplate<typename A, typename B, typename C>\n\
    void println(const A &a, const B &b, const C &c) {\n    __testlib_print_one(a);\n\
    \    std::cout << \" \";\n    __testlib_print_one(b);\n    std::cout << \" \"\
    ;\n    __testlib_print_one(c);\n    std::cout << std::endl;\n}\n\ntemplate<typename\
    \ A, typename B, typename C, typename D>\nvoid println(const A &a, const B &b,\
    \ const C &c, const D &d) {\n    __testlib_print_one(a);\n    std::cout << \"\
    \ \";\n    __testlib_print_one(b);\n    std::cout << \" \";\n    __testlib_print_one(c);\n\
    \    std::cout << \" \";\n    __testlib_print_one(d);\n    std::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E>\nvoid\
    \ println(const A &a, const B &b, const C &c, const D &d, const E &e) {\n    __testlib_print_one(a);\n\
    \    std::cout << \" \";\n    __testlib_print_one(b);\n    std::cout << \" \"\
    ;\n    __testlib_print_one(c);\n    std::cout << \" \";\n    __testlib_print_one(d);\n\
    \    std::cout << \" \";\n    __testlib_print_one(e);\n    std::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E, typename\
    \ F>\nvoid println(const A &a, const B &b, const C &c, const D &d, const E &e,\
    \ const F &f) {\n    __testlib_print_one(a);\n    std::cout << \" \";\n    __testlib_print_one(b);\n\
    \    std::cout << \" \";\n    __testlib_print_one(c);\n    std::cout << \" \"\
    ;\n    __testlib_print_one(d);\n    std::cout << \" \";\n    __testlib_print_one(e);\n\
    \    std::cout << \" \";\n    __testlib_print_one(f);\n    std::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E, typename\
    \ F, typename G>\nvoid println(const A &a, const B &b, const C &c, const D &d,\
    \ const E &e, const F &f, const G &g) {\n    __testlib_print_one(a);\n    std::cout\
    \ << \" \";\n    __testlib_print_one(b);\n    std::cout << \" \";\n    __testlib_print_one(c);\n\
    \    std::cout << \" \";\n    __testlib_print_one(d);\n    std::cout << \" \"\
    ;\n    __testlib_print_one(e);\n    std::cout << \" \";\n    __testlib_print_one(f);\n\
    \    std::cout << \" \";\n    __testlib_print_one(g);\n    std::cout << std::endl;\n\
    }\n\n/* opts */\nsize_t getOptType(char* s) {\n    if (!s || strlen(s) <= 1)\n\
    \        return 0;\n\n    if (s[0] == '-') {\n        if (isalpha(s[1]))\n   \
    \         return 1;\n        else if (s[1] == '-')\n            return isalpha(s[2])\
    \ ? 2 : 0;\n    }\n\n    return 0;\n}\n\nsize_t parseOpt(size_t argc, char* argv[],\
    \ size_t index, std::map<std::string, std::string>& opts) {\n    if (index >=\
    \ argc)\n        return 0;\n\n    size_t type = getOptType(argv[index]), inc =\
    \ 1;\n    if (type > 0) {\n        std::string key(argv[index] + type), val;\n\
    \        size_t sep = key.find('=');\n        if (sep != std::string::npos) {\n\
    \            val = key.substr(sep + 1);\n            key = key.substr(0, sep);\n\
    \        } else {\n            if (index + 1 < argc && getOptType(argv[index +\
    \ 1]) == 0) {\n                val = argv[index + 1];\n                inc = 2;\n\
    \            } else {\n                if (key.length() > 1 && isdigit(key[1]))\
    \ {\n                    val = key.substr(1);\n                    key = key.substr(0,\
    \ 1);\n                } else {\n                    val = \"true\";\n       \
    \         }\n            }\n        }\n        opts[key] = val;\n    } else {\n\
    \        return inc;\n    }\n\n    return inc;\n}\n\nstd::vector<std::string>\
    \ __testlib_argv;\nstd::map<std::string, std::string> __testlib_opts;\n\nvoid\
    \ prepareOpts(int argc, char* argv[]) {\n    if (argc <= 0)\n        __testlib_fail(\"\
    Opts: expected argc>=0 but found \" + toString(argc));\n    size_t n = static_cast<size_t>(argc);\
    \ // NOLINT(hicpp-use-auto,modernize-use-auto)\n    __testlib_opts = std::map<std::string,\
    \ std::string>();\n    for (size_t index = 1; index < n; index += parseOpt(n,\
    \ argv, index, __testlib_opts));\n    __testlib_argv = std::vector<std::string>(n);\n\
    \    for (size_t index = 0; index < n; index++)\n        __testlib_argv[index]\
    \ = argv[index];\n}\n\nstd::string __testlib_indexToArgv(int index) {\n    if\
    \ (index < 0 || index >= int(__testlib_argv.size()))\n        __testlib_fail(\"\
    Opts: index '\" + toString(index) + \"' is out of range [0,\" + toString(__testlib_argv.size())\
    \ + \")\");\n    return __testlib_argv[size_t(index)];\n}\n\nstd::string __testlib_keyToOpts(const\
    \ std::string& key) {\n    if (__testlib_opts.count(key) == 0)\n        __testlib_fail(\"\
    Opts: unknown key '\" + compress(key) + \"'\");\n    return __testlib_opts[key];\n\
    }\n\ntemplate<typename T>\nT optValueToIntegral(const std::string& s, bool nonnegative);\n\
    \nlong double optValueToLongDouble(const std::string& s);\n\nstd::string parseExponentialOptValue(const\
    \ std::string& s) {\n    size_t pos = std::string::npos;\n    for (size_t i =\
    \ 0; i < s.length(); i++)\n        if (s[i] == 'e' || s[i] == 'E') {\n       \
    \     if (pos != std::string::npos)\n                __testlib_fail(\"Opts: expected\
    \ typical exponential notation but '\" + compress(s) + \"' found\");\n       \
    \     pos = i;\n        }\n    if (pos == std::string::npos)\n        return s;\n\
    \    std::string e = s.substr(pos + 1);\n    if (!e.empty() && e[0] == '+')\n\
    \        e = e.substr(1);\n    if (e.empty())\n        __testlib_fail(\"Opts:\
    \ expected typical exponential notation but '\" + compress(s) + \"' found\");\n\
    \    if (e.length() > 20)\n        __testlib_fail(\"Opts: expected typical exponential\
    \ notation but '\" + compress(s) + \"' found\");\n    int ne = optValueToIntegral<int>(e,\
    \ false);\n    std::string num = s.substr(0, pos);\n    if (num.length() > 20)\n\
    \        __testlib_fail(\"Opts: expected typical exponential notation but '\"\
    \ + compress(s) + \"' found\");\n    if (!num.empty() && num[0] == '+')\n    \
    \    num = num.substr(1);\n    optValueToLongDouble(num);\n    bool minus = false;\n\
    \    if (num[0] == '-') {\n        minus = true;\n        num = num.substr(1);\n\
    \    }\n    for (int i = 0; i < +ne; i++) {\n        size_t sep = num.find('.');\n\
    \        if (sep == std::string::npos)\n            num += '0';\n        else\
    \ {\n            if (sep + 1 == num.length())\n                num[sep] = '0';\n\
    \            else\n                std::swap(num[sep], num[sep + 1]);\n      \
    \  }\n    }\n    for (int i = 0; i < -ne; i++) {\n        size_t sep = num.find('.');\n\
    \        if (sep == std::string::npos)\n            num.insert(num.begin() + int(num.length())\
    \ - 1, '.');\n        else {\n            if (sep == 0)\n                num.insert(num.begin()\
    \ + 1, '0');\n            else\n                std::swap(num[sep - 1], num[sep]);\n\
    \        }\n    }\n    while (!num.empty() && num[0] == '0')\n        num = num.substr(1);\n\
    \    while (num.find('.') != std::string::npos && num.back() == '0')\n       \
    \ num = num.substr(0, num.length() - 1);\n    if (!num.empty() && num.back() ==\
    \ '.')\n        num = num.substr(0, num.length() - 1);\n    if ((!num.empty()\
    \ && num[0] == '.') || num.empty())\n        num.insert(num.begin(), '0');\n \
    \   return (minus ? \"-\" : \"\") + num;\n}\n\ntemplate<typename T>\nT optValueToIntegral(const\
    \ std::string& s_, bool nonnegative) {\n    std::string s(parseExponentialOptValue(s_));\n\
    \    if (s.empty())\n        __testlib_fail(\"Opts: expected integer but '\" +\
    \ compress(s_) + \"' found\");\n    T value = 0;\n    long double about = 0.0;\n\
    \    signed char sign = +1;\n    size_t pos = 0;\n    if (s[pos] == '-') {\n \
    \       if (nonnegative)\n            __testlib_fail(\"Opts: expected non-negative\
    \ integer but '\" + compress(s_) + \"' found\");\n        sign = -1;\n       \
    \ pos++;\n    }\n    for (size_t i = pos; i < s.length(); i++) {\n        if (s[i]\
    \ < '0' || s[i] > '9')\n            __testlib_fail(\"Opts: expected integer but\
    \ '\" + compress(s_) + \"' found\");\n        value = value * 10 + s[i] - '0';\n\
    \        about = about * 10 + s[i] - '0';\n    }\n    value *= sign;\n    about\
    \ *= sign;\n    if (fabsl(value - about) > 0.1)\n        __testlib_fail(\"Opts:\
    \ integer overflow: expected integer but '\" + compress(s_) + \"' found\");\n\
    \    return value;\n}\n\nlong double optValueToLongDouble(const std::string& s_)\
    \ {\n    std::string s(parseExponentialOptValue(s_));\n    if (s.empty())\n  \
    \      __testlib_fail(\"Opts: expected float number but '\" + compress(s_) + \"\
    ' found\");\n    long double value = 0.0;\n    signed char sign = +1;\n    size_t\
    \ pos = 0;\n    if (s[pos] == '-') {\n        sign = -1;\n        pos++;\n   \
    \ }\n    bool period = false;\n    long double mul = 1.0;\n    for (size_t i =\
    \ pos; i < s.length(); i++) {\n        if (s[i] == '.') {\n            if (period)\n\
    \                __testlib_fail(\"Opts: expected float number but '\" + compress(s_)\
    \ + \"' found\");\n            else {\n                period = true;\n      \
    \          continue;\n            }\n        }\n        if (period)\n        \
    \    mul *= 10.0;\n        if (s[i] < '0' || s[i] > '9')\n            __testlib_fail(\"\
    Opts: expected float number but '\" + compress(s_) + \"' found\");\n        if\
    \ (period)\n            value += (s[i] - '0') / mul;\n        else\n         \
    \   value = value * 10 + s[i] - '0';\n    }\n    value *= sign;\n    return value;\n\
    }\n\nbool has_opt(const std::string key) {\n    return __testlib_opts.count(key)\
    \ != 0;\n}\n\ntemplate<typename T>\nT opt(std::false_type, int index);\n\ntemplate<>\n\
    std::string opt(std::false_type, int index) {\n    return __testlib_indexToArgv(index);\n\
    }\n\ntemplate<typename T>\nT opt(std::true_type, int index) {\n    return T(optValueToLongDouble(__testlib_indexToArgv(index)));\n\
    }\n\ntemplate<typename T, typename U>\nT opt(std::false_type, U, int index) {\n\
    \    return opt<T>(std::is_floating_point<T>(), index);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::false_type, int index) {\n    return optValueToIntegral<T>(__testlib_indexToArgv(index),\
    \ false);\n}\n\ntemplate<typename T>\nT opt(std::true_type, std::true_type, int\
    \ index) {\n    return optValueToIntegral<T>(__testlib_indexToArgv(index), true);\n\
    }\n\ntemplate<>\nbool opt(std::true_type, std::true_type, int index) {\n    std::string\
    \ value = __testlib_indexToArgv(index);\n    if (value == \"true\" || value ==\
    \ \"1\")\n        return true;\n    if (value == \"false\" || value == \"0\")\n\
    \        return false;\n    __testlib_fail(\"Opts: opt by index '\" + toString(index)\
    \ + \"': expected bool true/false or 0/1 but '\" + compress(value) + \"' found\"\
    );\n}\n\ntemplate<typename T>\nT opt(int index) {\n    return opt<T>(std::is_integral<T>(),\
    \ std::is_unsigned<T>(), index);\n}\n\nstd::string opt(int index) {\n    return\
    \ opt<std::string>(index);\n}\n\ntemplate<typename T>\nT opt(std::false_type,\
    \ const std::string& key);\n\ntemplate<>\nstd::string opt(std::false_type, const\
    \ std::string& key) {\n    return __testlib_keyToOpts(key);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, const std::string& key) {\n    return T(optValueToLongDouble(__testlib_keyToOpts(key)));\n\
    }\n\ntemplate<typename T, typename U>\nT opt(std::false_type, U, const std::string&\
    \ key) {\n    return opt<T>(std::is_floating_point<T>(), key);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::false_type, const std::string& key) {\n    return\
    \ optValueToIntegral<T>(__testlib_keyToOpts(key), false);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::true_type, const std::string& key) {\n    return\
    \ optValueToIntegral<T>(__testlib_keyToOpts(key), true);\n}\n\ntemplate<>\nbool\
    \ opt(std::true_type, std::true_type, const std::string& key) {\n    if (!has_opt(key))\n\
    \        return false;\n    std::string value = __testlib_keyToOpts(key);\n  \
    \  if (value == \"true\" || value == \"1\")\n        return true;\n    if (value\
    \ == \"false\" || value == \"0\")\n        return false;\n    __testlib_fail(\"\
    Opts: key '\" + compress(key) + \"': expected bool true/false or 0/1 but '\" +\
    \ compress(value) + \"' found\");\n}\n\ntemplate<typename T>\nT opt(const std::string\
    \ key) {\n    return opt<T>(std::is_integral<T>(), std::is_unsigned<T>(), key);\n\
    }\n\nstd::string opt(const std::string key) {\n    return opt<std::string>(key);\n\
    }\n#endif\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: other/testlib.h
  requiredBy: []
  timestamp: '2021-01-06 23:31:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/testlib.h
layout: document
redirect_from:
- /library/other/testlib.h
- /library/other/testlib.h.html
title: other/testlib.h
---
