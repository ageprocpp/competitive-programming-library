---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \ in\n * generators. Probably, these sample calls will be usefull for you:\n *\t\
    \t\t  rnd.next(); rnd.next(100); rnd.next(1, 2); \n *\t\t\t  rnd.next(3.14); rnd.next(\"\
    [a-z]{1,100}\").\n *\n * Also read about wnext() to generate off-center random\
    \ distribution.\n *\n * See https://github.com/MikeMirzayanov/testlib/ to get\
    \ latest version or bug tracker.\n */\n\n#ifndef _TESTLIB_H_\n#define _TESTLIB_H_\n\
    \n/*\n * Copyright (c) 2005-2020\n */\n\n#define VERSION \"0.9.33-SNAPSHOT\"\n\
    \n/* \n * Mike Mirzayanov\n *\n * This material is provided \"as is\", with absolutely\
    \ no warranty expressed\n * or implied. Any use is at your own risk.\n *\n * Permission\
    \ to use or copy this software for any purpose is hereby granted \n * without\
    \ fee, provided the above notices are retained on all copies.\n * Permission to\
    \ modify the code and to distribute modified code is granted,\n * provided the\
    \ above notices are retained, and a notice that the code was\n * modified is included\
    \ with the above copyright notice.\n *\n */\n\n/* NOTE: This file contains testlib\
    \ library for C++.\n *\n *   Check, using testlib running format:\n *\t check.exe\
    \ <Input_File> <Output_File> <Answer_File> [<Result_File> [-appes]],\n *   If\
    \ result file is specified it will contain results.\n *\n *   Validator, using\
    \ testlib running format:\t\t\t\t\t\t\t\t\t\t  \n *\t validator.exe < input.txt,\n\
    \ *   It will return non-zero exit code and writes message to standard output.\n\
    \ *\n *   Generator, using testlib running format:\t\t\t\t\t\t\t\t\t\t  \n *\t\
    \ gen.exe [parameter-1] [parameter-2] [... paramerter-n]\n *   You can write generated\
    \ test(s) into standard output or into the file(s).\n *\n *   Interactor, using\
    \ testlib running format:\t\t\t\t\t\t\t\t\t\t  \n *\t interactor.exe <Input_File>\
    \ <Output_File> [<Answer_File> [<Result_File> [-appes]]],\n *   Reads test from\
    \ inf (mapped to args[1]), writes result to tout (mapped to argv[2],\n *   can\
    \ be judged by checker later), reads program output from ouf (mapped to stdin),\n\
    \ *   writes output to program via stdout (use cout, printf, etc).\n */\n\nconst\
    \ char *latestFeatures[] = {\n\t\t\"rnd.partition(size, sum[, min_part=0]) returns\
    \ random (unsorted) partition which is a representation of the given `sum` as\
    \ a sum of `size` positive integers (or >=min_part if specified)\",\n\t\t\"rnd.distinct(size,\
    \ n) and rnd.distinct(size, from, to)\",\n\t\t\"opt<bool>(\\\"some_missing_key\\\
    \") returns false now\",\n\t\t\"has_opt(key)\",\n\t\t\"Abort validator on validator.testset()/validator.group()\
    \ if registered without using command line\",\n\t\t\"Print integer range violations\
    \ in a human readable way like `violates the range [1, 10^9]`\",\n\t\t\"Opts supported:\
    \ use them like n = opt<int>(\\\"n\\\"), in a command line you can use an exponential\
    \ notation\",\n\t\t\"Reformatted\",\n\t\t\"Use setTestCase(i) or unsetTestCase()\
    \ to support test cases (you can use it in any type of program: generator, interactor,\
    \ validator or checker)\",\n\t\t\"Fixed issue #87: readStrictDouble accepts \\\
    \"-0.00\\\"\",\n\t\t\"Fixed issue #83: added InStream::quitif(condition, ...)\"\
    ,\n\t\t\"Fixed issue #79: fixed missed guard against repeated header include\"\
    ,\n\t\t\"Fixed issue #80: fixed UB in case of huge quitf message\",\n\t\t\"Fixed\
    \ issue #84: added readXs(size, indexBase = 1)\",\n\t\t\"Fixed stringstream repeated\
    \ usage issue\",\n\t\t\"Fixed compilation in g++ (for std=c++03)\",\n\t\t\"Batch\
    \ of println functions (support collections, iterator ranges)\",\n\t\t\"Introduced\
    \ rnd.perm(size, first = 0) to generate a `first`-indexed permutation\",\n\t\t\
    \"Allow any whitespace in readInts-like functions for non-validators\",\n\t\t\"\
    Ignore 4+ command line arguments ifdef EJUDGE\",\n\t\t\"Speed up of vtos\",\n\t\
    \t\"Show line number in validators in case of incorrect format\",\n\t\t\"Truncate\
    \ huge checker/validator/interactor message\",\n\t\t\"Fixed issue with readTokenTo\
    \ of very long tokens, now aborts with _pe/_fail depending of a stream type\"\
    ,\n\t\t\"Introduced InStream::ensure/ensuref checking a condition, returns wa/fail\
    \ depending of a stream type\",\n\t\t\"Fixed compilation in VS 2015+\",\n\t\t\"\
    Introduced space-separated read functions: readWords/readTokens, multilines read\
    \ functions: readStrings/readLines\",\n\t\t\"Introduced space-separated read functions:\
    \ readInts/readIntegers/readLongs/readUnsignedLongs/readDoubles/readReals/readStrictDoubles/readStrictReals\"\
    ,\n\t\t\"Introduced split/tokenize functions to separate string by given char\"\
    ,\n\t\t\"Introduced InStream::readUnsignedLong and InStream::readLong with unsigned\
    \ long long paramerters\",\n\t\t\"Supported --testOverviewLogFileName for validator:\
    \ bounds hits + features\",\n\t\t\"Fixed UB (sequence points) in random_t\",\n\
    \t\t\"POINTS_EXIT_CODE returned back to 7 (instead of 0)\",\n\t\t\"Removed disable\
    \ buffers for interactive problems, because it works unexpectedly in wine\",\n\
    \t\t\"InStream over string: constructor of InStream from base InStream to inherit\
    \ policies and std::string\",\n\t\t\"Added expectedButFound quit function, examples:\
    \ expectedButFound(_wa, 10, 20), expectedButFound(_fail, ja, pa, \\\"[n=%d,m=%d]\\\
    \", n, m)\",\n\t\t\"Fixed incorrect interval parsing in patterns\",\n\t\t\"Use\
    \ registerGen(argc, argv, 1) to develop new generator, use registerGen(argc, argv,\
    \ 0) to compile old generators (originally created for testlib under 0.8.7)\"\
    ,\n\t\t\"Introduced disableFinalizeGuard() to switch off finalization checkings\"\
    ,\n\t\t\"Use join() functions to format a range of items as a single string (separated\
    \ by spaces or other separators)\",\n\t\t\"Use -DENABLE_UNEXPECTED_EOF to enable\
    \ special exit code (by default, 8) in case of unexpected eof. It is good idea\
    \ to use it in interactors\",\n\t\t\"Use -DUSE_RND_AS_BEFORE_087 to compile in\
    \ compatibility mode with random behavior of versions before 0.8.7\",\n\t\t\"\
    Fixed bug with nan in stringToDouble\",\n\t\t\"Fixed issue around overloads for\
    \ size_t on x64\",\n\t\t\"Added attribute 'points' to the XML output in case of\
    \ result=_points\",\n\t\t\"Exit codes can be customized via macros, e.g. -DPE_EXIT_CODE=14\"\
    ,\n\t\t\"Introduced InStream function readWordTo/readTokenTo/readStringTo/readLineTo\
    \ for faster reading\",\n\t\t\"Introduced global functions: format(), englishEnding(),\
    \ upperCase(), lowerCase(), compress()\",\n\t\t\"Manual buffer in InStreams, some\
    \ IO speed improvements\",\n\t\t\"Introduced quitif(bool, const char* pattern,\
    \ ...) which delegates to quitf() in case of first argument is true\",\n\t\t\"\
    Introduced guard against missed quitf() in checker or readEof() in validators\"\
    ,\n\t\t\"Supported readStrictReal/readStrictDouble - to use in validators to check\
    \ strictly float numbers\",\n\t\t\"Supported registerInteraction(argc, argv)\"\
    ,\n\t\t\"Print checker message to the stderr instead of stdout\",\n\t\t\"Supported\
    \ TResult _points to output calculated score, use quitp(...) functions\",\n\t\t\
    \"Fixed to be compilable on Mac\",\n\t\t\"PC_BASE_EXIT_CODE=50 in case of defined\
    \ TESTSYS\",\n\t\t\"Fixed issues 19-21, added __attribute__ format printf\",\n\
    \t\t\"Some bug fixes\",\n\t\t\"ouf.readInt(1, 100) and similar calls return WA\"\
    ,\n\t\t\"Modified random_t to avoid integer overflow\",\n\t\t\"Truncated checker\
    \ output [patch by Stepan Gatilov]\",\n\t\t\"Renamed class random -> class random_t\"\
    ,\n\t\t\"Supported name parameter for read-and-validation methods, like readInt(1,\
    \ 2, \\\"n\\\")\",\n\t\t\"Fixed bug in readDouble()\",\n\t\t\"Improved ensuref(),\
    \ fixed nextLine to work in case of EOF, added startTest()\",\n\t\t\"Supported\
    \ \\\"partially correct\\\", example: quitf(_pc(13), \\\"result=%d\\\", result)\"\
    ,\n\t\t\"Added shuffle(begin, end), use it instead of random_shuffle(begin, end)\"\
    ,\n\t\t\"Added readLine(const string& ptrn), fixed the logic of readLine() in\
    \ the validation mode\",\n\t\t\"Package extended with samples of generators and\
    \ validators\",\n\t\t\"Written the documentation for classes and public methods\
    \ in testlib.h\",\n\t\t\"Implemented random routine to support generators, use\
    \ registerGen() to switch it on\",\n\t\t\"Implemented strict mode to validate\
    \ tests, use registerValidation() to switch it on\",\n\t\t\"Now ncmp.cpp and wcmp.cpp\
    \ are return WA if answer is suffix or prefix of the output\",\n\t\t\"Added InStream::readLong()\
    \ and removed InStream::readLongint()\",\n\t\t\"Now no footer added to each report\
    \ by default (use directive FOOTER to switch on)\",\n\t\t\"Now every checker has\
    \ a name, use setName(const char* format, ...) to set it\",\n\t\t\"Now it is compatible\
    \ with TTS (by Kittens Computing)\",\n\t\t\"Added \\'ensure(condition, message\
    \ = \\\"\\\")\\' feature, it works like assert()\",\n\t\t\"Fixed compatibility\
    \ with MS C++ 7.1\",\n\t\t\"Added footer with exit code information\",\n\t\t\"\
    Added compatibility with EJUDGE (compile with EJUDGE directive)\",\n\t\t\"Added\
    \ compatibility with Contester (compile with CONTESTER directive)\"\n};\n\n#ifdef\
    \ _MSC_VER\n#define _CRT_SECURE_NO_DEPRECATE\n#define _CRT_SECURE_NO_WARNINGS\n\
    #define _CRT_NO_VA_START_VALIDATION\n#endif\n\n/* Overrides random() for Borland\
    \ C++. */\n#define random __random_deprecated\n#include <stdlib.h>\n#include <cstdlib>\n\
    #include <climits>\n#include <algorithm>\n#undef random\n\n#include <cstdio>\n\
    #include <cctype>\n#include <string>\n#include <vector>\n#include <map>\n#include\
    \ <set>\n#include <cmath>\n#include <iostream>\n#include <sstream>\n#include <fstream>\n\
    #include <cstring>\n#include <limits>\n#include <stdarg.h>\n#include <fcntl.h>\n\
    \n#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__ || __CYGWIN__)\n#   if !defined(_MSC_VER)\
    \ || _MSC_VER > 1400\n#\t   define NOMINMAX 1\n#\t   include <windows.h>\n#  \
    \ else\n#\t   define WORD unsigned short\n#\t   include <unistd.h>\n#   endif\n\
    #   include <io.h>\n#   define ON_WINDOWS\n#   if defined(_MSC_VER) && _MSC_VER\
    \ > 1400\n#\t   pragma warning( disable : 4127 )\n#\t   pragma warning( disable\
    \ : 4146 )\n#\t   pragma warning( disable : 4458 )\n#   endif\n#else\n#   define\
    \ WORD unsigned short\n#   include <unistd.h>\n#endif\n\n#if defined(FOR_WINDOWS)\
    \ && defined(FOR_LINUX)\n#error Only one target system is allowed\n#endif\n\n\
    #ifndef LLONG_MIN\n#define LLONG_MIN   (-9223372036854775807LL - 1)\n#endif\n\n\
    #ifndef ULLONG_MAX\n#define ULLONG_MAX   (18446744073709551615)\n#endif\n\n#define\
    \ LF ((char)10)\n#define CR ((char)13)\n#define TAB ((char)9)\n#define SPACE ((char)'\
    \ ')\n#define EOFC (255)\n\n#ifndef OK_EXIT_CODE\n#   ifdef CONTESTER\n#\t   define\
    \ OK_EXIT_CODE 0xAC\n#   else\n#\t   define OK_EXIT_CODE 0\n#   endif\n#endif\n\
    \n#ifndef WA_EXIT_CODE\n#   ifdef EJUDGE\n#\t   define WA_EXIT_CODE 5\n#   elif\
    \ defined(CONTESTER)\n#\t   define WA_EXIT_CODE 0xAB\n#   else\n#\t   define WA_EXIT_CODE\
    \ 1\n#   endif\n#endif\n\n#ifndef PE_EXIT_CODE\n#   ifdef EJUDGE\n#\t   define\
    \ PE_EXIT_CODE 4\n#   elif defined(CONTESTER)\n#\t   define PE_EXIT_CODE 0xAA\n\
    #   else\n#\t   define PE_EXIT_CODE 2\n#   endif\n#endif\n\n#ifndef FAIL_EXIT_CODE\n\
    #   ifdef EJUDGE\n#\t   define FAIL_EXIT_CODE 6\n#   elif defined(CONTESTER)\n\
    #\t   define FAIL_EXIT_CODE 0xA3\n#   else\n#\t   define FAIL_EXIT_CODE 3\n# \
    \  endif\n#endif\n\n#ifndef DIRT_EXIT_CODE\n#   ifdef EJUDGE\n#\t   define DIRT_EXIT_CODE\
    \ 6\n#   else\n#\t   define DIRT_EXIT_CODE 4\n#   endif\n#endif\n\n#ifndef POINTS_EXIT_CODE\n\
    #   define POINTS_EXIT_CODE 7\n#endif\n\n#ifndef UNEXPECTED_EOF_EXIT_CODE\n# \
    \  define UNEXPECTED_EOF_EXIT_CODE 8\n#endif\n\n#ifndef PC_BASE_EXIT_CODE\n# \
    \  ifdef TESTSYS\n#\t   define PC_BASE_EXIT_CODE 50\n#   else\n#\t   define PC_BASE_EXIT_CODE\
    \ 0\n#   endif\n#endif\n\n#ifdef __GNUC__\n#\tdefine __TESTLIB_STATIC_ASSERT(condition)\
    \ typedef void* __testlib_static_assert_type[(condition) ? 1 : -1] __attribute__((unused))\n\
    #else\n#\tdefine __TESTLIB_STATIC_ASSERT(condition) typedef void* __testlib_static_assert_type[(condition)\
    \ ? 1 : -1]\n#endif\n\n#ifdef ON_WINDOWS\n#define I64 \"%I64d\"\n#define U64 \"\
    %I64u\"\n#else\n#define I64 \"%lld\"\n#define U64 \"%llu\"\n#endif\n\n#ifdef _MSC_VER\n\
    #   define NORETURN __declspec(noreturn)\n#elif defined __GNUC__\n#   define NORETURN\
    \ __attribute__ ((noreturn))\n#else\n#   define NORETURN\n#endif\n\nstatic char\
    \ __testlib_format_buffer[16777216];\nstatic int __testlib_format_buffer_usage_count\
    \ = 0;\n\n#define FMT_TO_RESULT(fmt, cstr, result)  std::string result;\t\t\t\t\
    \t\t\t  \\\n\t\t\tif (__testlib_format_buffer_usage_count != 0)\t\t\t\t\t\t\t\t\
    \  \\\n\t\t\t\t__testlib_fail(\"FMT_TO_RESULT::__testlib_format_buffer_usage_count\
    \ != 0\"); \\\n\t\t\t__testlib_format_buffer_usage_count++;\t\t\t\t\t\t\t\t\t\t\
    \ \\\n\t\t\tva_list ap;\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\tva_start(ap,\
    \ fmt);\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t \\\n\t\t\tvsnprintf(__testlib_format_buffer,\
    \ sizeof(__testlib_format_buffer), cstr, ap); \\\n\t\t\tva_end(ap);\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\t__testlib_format_buffer[sizeof(__testlib_format_buffer)\
    \ - 1] = 0;\t\t\t  \\\n\t\t\tresult = std::string(__testlib_format_buffer);\t\t\
    \t\t\t\t\t\t \\\n\t\t\t__testlib_format_buffer_usage_count--;\t\t\t\t\t\t\t\t\t\
    \t \\\n\nconst long long __TESTLIB_LONGLONG_MAX = 9223372036854775807LL;\n\nbool\
    \ __testlib_hasTestCase;\nint __testlib_testCase = -1;\n\nvoid setTestCase(int\
    \ testCase) {\n\t__testlib_hasTestCase = true;\n\t__testlib_testCase = testCase;\n\
    }\n\nvoid unsetTestCase() {\n\t__testlib_hasTestCase = false;\n\t__testlib_testCase\
    \ = -1;\n}\n\nNORETURN static void __testlib_fail(const std::string &message);\n\
    \ntemplate<typename T>\nstatic inline T __testlib_abs(const T &x) {\n\treturn\
    \ x > 0 ? x : -x;\n}\n\ntemplate<typename T>\nstatic inline T __testlib_min(const\
    \ T &a, const T &b) {\n\treturn a < b ? a : b;\n}\n\ntemplate<typename T>\nstatic\
    \ inline T __testlib_max(const T &a, const T &b) {\n\treturn a > b ? a : b;\n\
    }\n\nstatic bool __testlib_prelimIsNaN(double r) {\n\tvolatile double ra = r;\n\
    #ifndef __BORLANDC__\n\treturn ((ra != ra) == true) && ((ra == ra) == false) &&\
    \ ((1.0 > ra) == false) && ((1.0 < ra) == false);\n#else\n\treturn std::_isnan(ra);\n\
    #endif\n}\n\nstatic std::string removeDoubleTrailingZeroes(std::string value)\
    \ {\n\twhile (!value.empty() && value[value.length() - 1] == '0' && value.find('.')\
    \ != std::string::npos)\n\t\tvalue = value.substr(0, value.length() - 1);\n\t\
    return value + '0';\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 1,\
    \ 2)))\n#endif\nstd::string format(const char *fmt, ...) {\n\tFMT_TO_RESULT(fmt,\
    \ fmt, result);\n\treturn result;\n}\n\nstd::string format(const std::string fmt,\
    \ ...) {\n\tFMT_TO_RESULT(fmt, fmt.c_str(), result);\n\treturn result;\n}\n\n\
    static std::string __testlib_part(const std::string &s);\n\nstatic bool __testlib_isNaN(double\
    \ r) {\n\t__TESTLIB_STATIC_ASSERT(sizeof(double) == sizeof(long long));\n\tvolatile\
    \ double ra = r;\n\tlong long llr1, llr2;\n\tstd::memcpy((void *) &llr1, (void\
    \ *) &ra, sizeof(double));\n\tra = -ra;\n\tstd::memcpy((void *) &llr2, (void *)\
    \ &ra, sizeof(double));\n\tlong long llnan = 0xFFF8000000000000LL;\n\treturn __testlib_prelimIsNaN(r)\
    \ || llnan == llr1 || llnan == llr2;\n}\n\nstatic double __testlib_nan() {\n\t\
    __TESTLIB_STATIC_ASSERT(sizeof(double) == sizeof(long long));\n#ifndef NAN\n\t\
    long long llnan = 0xFFF8000000000000LL;\n\tdouble nan;\n\tstd::memcpy(&nan, &llnan,\
    \ sizeof(double));\n\treturn nan;\n#else\n\treturn NAN;\n#endif\n}\n\nstatic bool\
    \ __testlib_isInfinite(double r) {\n\tvolatile double ra = r;\n\treturn (ra >\
    \ 1E300 || ra < -1E300);\n}\n\n#ifdef __GNUC__\n__attribute__((const))\n#endif\n\
    inline bool doubleCompare(double expected, double result, double MAX_DOUBLE_ERROR)\
    \ {\n\tif (__testlib_isNaN(expected)) {\n\t\treturn __testlib_isNaN(result);\n\
    \t} else if (__testlib_isInfinite(expected)) {\n\t\tif (expected > 0) {\n\t\t\t\
    return result > 0 && __testlib_isInfinite(result);\n\t\t} else {\n\t\t\treturn\
    \ result < 0 && __testlib_isInfinite(result);\n\t\t}\n\t} else if (__testlib_isNaN(result)\
    \ || __testlib_isInfinite(result)) {\n\t\treturn false;\n\t} else if (__testlib_abs(result\
    \ - expected) <= MAX_DOUBLE_ERROR + 1E-15) {\n\t\treturn true;\n\t} else {\n\t\
    \tdouble minv = __testlib_min(expected * (1.0 - MAX_DOUBLE_ERROR),\n\t\t\t\t\t\
    \t\t\t\texpected * (1.0 + MAX_DOUBLE_ERROR));\n\t\tdouble maxv = __testlib_max(expected\
    \ * (1.0 - MAX_DOUBLE_ERROR),\n\t\t\t\t\t\t\t\t\texpected * (1.0 + MAX_DOUBLE_ERROR));\n\
    \t\treturn result + 1E-15 >= minv && result <= maxv + 1E-15;\n\t}\n}\n\n#ifdef\
    \ __GNUC__\n__attribute__((const))\n#endif\ninline double doubleDelta(double expected,\
    \ double result) {\n\tdouble absolute = __testlib_abs(result - expected);\n\n\t\
    if (__testlib_abs(expected) > 1E-9) {\n\t\tdouble relative = __testlib_abs(absolute\
    \ / expected);\n\t\treturn __testlib_min(absolute, relative);\n\t} else\n\t\t\
    return absolute;\n}\n\n#if !defined(_MSC_VER) || _MSC_VER < 1900\n#ifndef _fileno\n\
    #define _fileno(_stream)  ((_stream)->_file)\n#endif\n#endif\n\n#ifndef O_BINARY\n\
    static void __testlib_set_binary(\n#ifdef __GNUC__\n\t__attribute__((unused))\
    \ \n#endif\n\tstd::FILE* file\n)\n#else\nstatic void __testlib_set_binary(std::FILE\
    \ *file)\n#endif\n{\n#ifdef O_BINARY\n\tif (NULL != file) {\n#ifndef __BORLANDC__\n\
    \t\t_setmode(_fileno(file), O_BINARY);\n#else\n\t\tsetmode(fileno(file), O_BINARY);\n\
    #endif\n\t}\n#endif\n}\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\n/* opts\
    \ */\nvoid prepareOpts(int argc, char* argv[]);\n#endif\n\n/*\n * Very simple\
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
    )\".\n */\nclass random_t;\n\nclass pattern {\npublic:\n\t/* Create pattern instance\
    \ by string. */\n\tpattern(std::string s);\n\n\t/* Generate new string by pattern\
    \ and given random_t. */\n\tstd::string next(random_t &rnd) const;\n\n\t/* Checks\
    \ if given string match the pattern. */\n\tbool matches(const std::string &s)\
    \ const;\n\n\t/* Returns source string of the pattern. */\n\tstd::string src()\
    \ const;\n\nprivate:\n\tbool matches(const std::string &s, size_t pos) const;\n\
    \n\tstd::string s;\n\tstd::vector<pattern> children;\n\tstd::vector<char> chars;\n\
    \tint from;\n\tint to;\n};\n\n/* \n * Use random_t instances to generate random\
    \ values. It is preffered\n * way to use randoms instead of rand() function or\
    \ self-written \n * randoms.\n *\n * Testlib defines global variable \"rnd\" of\
    \ random_t class.\n * Use registerGen(argc, argv, 1) to setup random_t seed be\
    \ command\n * line (to use latest random generator version).\n *\n * Random generates\
    \ uniformly distributed values if another strategy is\n * not specified explicitly.\n\
    \ */\nclass random_t {\nprivate:\n\tunsigned long long seed;\n\tstatic const unsigned\
    \ long long multiplier;\n\tstatic const unsigned long long addend;\n\tstatic const\
    \ unsigned long long mask;\n\tstatic const int lim;\n\n\tlong long nextBits(int\
    \ bits) {\n\t\tif (bits <= 48) {\n\t\t\tseed = (seed * multiplier + addend) &\
    \ mask;\n\t\t\treturn (long long) (seed >> (48 - bits));\n\t\t} else {\n\t\t\t\
    if (bits > 63)\n\t\t\t\t__testlib_fail(\"random_t::nextBits(int bits): n must\
    \ be less than 64\");\n\n\t\t\tint lowerBitCount = (random_t::version == 0 ? 31\
    \ : 32);\n\n\t\t\tlong long left = (nextBits(31) << 32);\n\t\t\tlong long right\
    \ = nextBits(lowerBitCount);\n\n\t\t\treturn left ^ right;\n\t\t}\n\t}\n\npublic:\n\
    \tstatic int version;\n\n\t/* New random_t with fixed seed. */\n\trandom_t()\n\
    \t\t\t: seed(3905348978240129619LL) {\n\t}\n\n\t/* Sets seed by command line.\
    \ */\n\tvoid setSeed(int argc, char *argv[]) {\n\t\trandom_t p;\n\n\t\tseed =\
    \ 3905348978240129619LL;\n\t\tfor (int i = 1; i < argc; i++) {\n\t\t\tstd::size_t\
    \ le = std::strlen(argv[i]);\n\t\t\tfor (std::size_t j = 0; j < le; j++)\n\t\t\
    \t\tseed = seed * multiplier + (unsigned int) (argv[i][j]) + addend;\n\t\t\tseed\
    \ += multiplier / addend;\n\t\t}\n\n\t\tseed = seed & mask;\n\t}\n\n\t/* Sets\
    \ seed by given value. */\n\tvoid setSeed(long long _seed) {\n\t\t_seed = (_seed\
    \ ^ multiplier) & mask;\n\t\tseed = _seed;\n\t}\n\n#ifndef __BORLANDC__\n\n\t\
    /* Random string value by given pattern (see pattern documentation). */\n\tstd::string\
    \ next(const std::string &ptrn) {\n\t\tpattern p(ptrn);\n\t\treturn p.next(*this);\n\
    \t}\n\n#else\n\t/* Random string value by given pattern (see pattern documentation).\
    \ */\n\tstd::string next(std::string ptrn)\n\t{\n\t\tpattern p(ptrn);\n\t\treturn\
    \ p.next(*this);\n\t}\n#endif\n\n\t/* Random value in range [0, n-1]. */\n\tint\
    \ next(int n) {\n\t\tif (n <= 0)\n\t\t\t__testlib_fail(\"random_t::next(int n):\
    \ n must be positive\");\n\n\t\tif ((n & -n) == n)  // n is a power of 2\n\t\t\
    \treturn (int) ((n * (long long) nextBits(31)) >> 31);\n\n\t\tconst long long\
    \ limit = INT_MAX / n * n;\n\n\t\tlong long bits;\n\t\tdo {\n\t\t\tbits = nextBits(31);\n\
    \t\t} while (bits >= limit);\n\n\t\treturn int(bits % n);\n\t}\n\n\t/* Random\
    \ value in range [0, n-1]. */\n\tunsigned int next(unsigned int n) {\n\t\tif (n\
    \ >= INT_MAX)\n\t\t\t__testlib_fail(\"random_t::next(unsigned int n): n must be\
    \ less INT_MAX\");\n\t\treturn (unsigned int) next(int(n));\n\t}\n\n\t/* Random\
    \ value in range [0, n-1]. */\n\tlong long next(long long n) {\n\t\tif (n <= 0)\n\
    \t\t\t__testlib_fail(\"random_t::next(long long n): n must be positive\");\n\n\
    \t\tconst long long limit = __TESTLIB_LONGLONG_MAX / n * n;\n\n\t\tlong long bits;\n\
    \t\tdo {\n\t\t\tbits = nextBits(63);\n\t\t} while (bits >= limit);\n\n\t\treturn\
    \ bits % n;\n\t}\n\n\t/* Random value in range [0, n-1]. */\n\tunsigned long long\
    \ next(unsigned long long n) {\n\t\tif (n >= (unsigned long long) (__TESTLIB_LONGLONG_MAX))\n\
    \t\t\t__testlib_fail(\"random_t::next(unsigned long long n): n must be less LONGLONG_MAX\"\
    );\n\t\treturn (unsigned long long) next((long long) (n));\n\t}\n\n\t/* Random\
    \ value in range [0, n-1]. */\n\tlong next(long n) {\n\t\treturn (long) next((long\
    \ long) (n));\n\t}\n\n\t/* Random value in range [0, n-1]. */\n\tunsigned long\
    \ next(unsigned long n) {\n\t\tif (n >= (unsigned long) (LONG_MAX))\n\t\t\t__testlib_fail(\"\
    random_t::next(unsigned long n): n must be less LONG_MAX\");\n\t\treturn (unsigned\
    \ long) next((unsigned long long) (n));\n\t}\n\n\t/* Returns random value in range\
    \ [from,to]. */\n\tint next(int from, int to) {\n\t\treturn int(next((long long)\
    \ to - from + 1) + from);\n\t}\n\n\t/* Returns random value in range [from,to].\
    \ */\n\tunsigned int next(unsigned int from, unsigned int to) {\n\t\treturn (unsigned\
    \ int) (next((long long) to - from + 1) + from);\n\t}\n\n\t/* Returns random value\
    \ in range [from,to]. */\n\tlong long next(long long from, long long to) {\n\t\
    \treturn next(to - from + 1) + from;\n\t}\n\n\t/* Returns random value in range\
    \ [from,to]. */\n\tunsigned long long next(unsigned long long from, unsigned long\
    \ long to) {\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"random_t::next(unsigned\
    \ long long from, unsigned long long to): from can't not exceed to\");\n\t\treturn\
    \ next(to - from + 1) + from;\n\t}\n\n\t/* Returns random value in range [from,to].\
    \ */\n\tlong next(long from, long to) {\n\t\treturn next(to - from + 1) + from;\n\
    \t}\n\n\t/* Returns random value in range [from,to]. */\n\tunsigned long next(unsigned\
    \ long from, unsigned long to) {\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"\
    random_t::next(unsigned long from, unsigned long to): from can't not exceed to\"\
    );\n\t\treturn next(to - from + 1) + from;\n\t}\n\n\t/* Random double value in\
    \ range [0, 1). */\n\tdouble next() {\n\t\tlong long left = ((long long) (nextBits(26))\
    \ << 27);\n\t\tlong long right = nextBits(27);\n\t\treturn (double) (left + right)\
    \ / (double) (1LL << 53);\n\t}\n\n\t/* Random double value in range [0, n). */\n\
    \tdouble next(double n) {\n\t\treturn n * next();\n\t}\n\n\t/* Random double value\
    \ in range [from, to). */\n\tdouble next(double from, double to) {\n\t\tif (from\
    \ > to)\n\t\t\t__testlib_fail(\"random_t::next(double from, double to): from can't\
    \ not exceed to\");\n\t\treturn next(to - from) + from;\n\t}\n\n\t/* Returns random\
    \ element from container. */\n\ttemplate<typename Container>\n\ttypename Container::value_type\
    \ any(const Container &c) {\n\t\tsize_t size = c.size();\n\t\tif (size <= 0)\n\
    \t\t\t__testlib_fail(\"random_t::any(const Container& c): c.size() must be positive\"\
    );\n\t\treturn *(c.begin() + next(size));\n\t}\n\n\t/* Returns random element\
    \ from iterator range. */\n\ttemplate<typename Iter>\n\ttypename Iter::value_type\
    \ any(const Iter &begin, const Iter &end) {\n\t\tint size = int(end - begin);\n\
    \t\tif (size <= 0)\n\t\t\t__testlib_fail(\"random_t::any(const Iter& begin, const\
    \ Iter& end): range must have positive length\");\n\t\treturn *(begin + next(size));\n\
    \t}\n\n\t/* Random string value by given pattern (see pattern documentation).\
    \ */\n#ifdef __GNUC__\n\t__attribute__ ((format (printf, 2, 3)))\n#endif\n\tstd::string\
    \ next(const char *format, ...) {\n\t\tFMT_TO_RESULT(format, format, ptrn);\n\t\
    \treturn next(ptrn);\n\t}\n\n\t/* \n\t * Weighted next. If type == 0 than it is\
    \ usual \"next()\".\n\t *\n\t * If type = 1, than it returns \"max(next(), next())\"\
    \n\t * (the number of \"max\" functions equals to \"type\").\n\t *\n\t * If type\
    \ < 0, than \"max\" function replaces with \"min\".\n\t */\n\tint wnext(int n,\
    \ int type) {\n\t\tif (n <= 0)\n\t\t\t__testlib_fail(\"random_t::wnext(int n,\
    \ int type): n must be positive\");\n\n\t\tif (abs(type) < random_t::lim) {\n\t\
    \t\tint result = next(n);\n\n\t\t\tfor (int i = 0; i < +type; i++)\n\t\t\t\tresult\
    \ = __testlib_max(result, next(n));\n\n\t\t\tfor (int i = 0; i < -type; i++)\n\
    \t\t\t\tresult = __testlib_min(result, next(n));\n\n\t\t\treturn result;\n\t\t\
    } else {\n\t\t\tdouble p;\n\n\t\t\tif (type > 0)\n\t\t\t\tp = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n\t\t\telse\n\t\t\t\tp = 1 - std::pow(next() + 0.0,\
    \ 1.0 / (-type + 1));\n\n\t\t\treturn int(n * p);\n\t\t}\n\t}\n\n\t/* See wnext(int,\
    \ int). It uses the same algorithms. */\n\tlong long wnext(long long n, int type)\
    \ {\n\t\tif (n <= 0)\n\t\t\t__testlib_fail(\"random_t::wnext(long long n, int\
    \ type): n must be positive\");\n\n\t\tif (abs(type) < random_t::lim) {\n\t\t\t\
    long long result = next(n);\n\n\t\t\tfor (int i = 0; i < +type; i++)\n\t\t\t\t\
    result = __testlib_max(result, next(n));\n\n\t\t\tfor (int i = 0; i < -type; i++)\n\
    \t\t\t\tresult = __testlib_min(result, next(n));\n\n\t\t\treturn result;\n\t\t\
    } else {\n\t\t\tdouble p;\n\n\t\t\tif (type > 0)\n\t\t\t\tp = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n\t\t\telse\n\t\t\t\tp = std::pow(next() + 0.0, -type\
    \ + 1);\n\n\t\t\treturn __testlib_min(__testlib_max((long long) (double(n) * p),\
    \ 0LL), n - 1LL);\n\t\t}\n\t}\n\n\t/* See wnext(int, int). It uses the same algorithms.\
    \ */\n\tdouble wnext(int type) {\n\t\tif (abs(type) < random_t::lim) {\n\t\t\t\
    double result = next();\n\n\t\t\tfor (int i = 0; i < +type; i++)\n\t\t\t\tresult\
    \ = __testlib_max(result, next());\n\n\t\t\tfor (int i = 0; i < -type; i++)\n\t\
    \t\t\tresult = __testlib_min(result, next());\n\n\t\t\treturn result;\n\t\t} else\
    \ {\n\t\t\tdouble p;\n\n\t\t\tif (type > 0)\n\t\t\t\tp = std::pow(next() + 0.0,\
    \ 1.0 / (type + 1));\n\t\t\telse\n\t\t\t\tp = std::pow(next() + 0.0, -type + 1);\n\
    \n\t\t\treturn p;\n\t\t}\n\t}\n\n\t/* See wnext(int, int). It uses the same algorithms.\
    \ */\n\tdouble wnext(double n, int type) {\n\t\tif (n <= 0)\n\t\t\t__testlib_fail(\"\
    random_t::wnext(double n, int type): n must be positive\");\n\n\t\tif (abs(type)\
    \ < random_t::lim) {\n\t\t\tdouble result = next();\n\n\t\t\tfor (int i = 0; i\
    \ < +type; i++)\n\t\t\t\tresult = __testlib_max(result, next());\n\n\t\t\tfor\
    \ (int i = 0; i < -type; i++)\n\t\t\t\tresult = __testlib_min(result, next());\n\
    \n\t\t\treturn n * result;\n\t\t} else {\n\t\t\tdouble p;\n\n\t\t\tif (type >\
    \ 0)\n\t\t\t\tp = std::pow(next() + 0.0, 1.0 / (type + 1));\n\t\t\telse\n\t\t\t\
    \tp = std::pow(next() + 0.0, -type + 1);\n\n\t\t\treturn n * p;\n\t\t}\n\t}\n\n\
    \t/* See wnext(int, int). It uses the same algorithms. */\n\tunsigned int wnext(unsigned\
    \ int n, int type) {\n\t\tif (n >= INT_MAX)\n\t\t\t__testlib_fail(\"random_t::wnext(unsigned\
    \ int n, int type): n must be less INT_MAX\");\n\t\treturn (unsigned int) wnext(int(n),\
    \ type);\n\t}\n\n\t/* See wnext(int, int). It uses the same algorithms. */\n\t\
    unsigned long long wnext(unsigned long long n, int type) {\n\t\tif (n >= (unsigned\
    \ long long) (__TESTLIB_LONGLONG_MAX))\n\t\t\t__testlib_fail(\"random_t::wnext(unsigned\
    \ long long n, int type): n must be less LONGLONG_MAX\");\n\n\t\treturn (unsigned\
    \ long long) wnext((long long) (n), type);\n\t}\n\n\t/* See wnext(int, int). It\
    \ uses the same algorithms. */\n\tlong wnext(long n, int type) {\n\t\treturn (long)\
    \ wnext((long long) (n), type);\n\t}\n\n\t/* See wnext(int, int). It uses the\
    \ same algorithms. */\n\tunsigned long wnext(unsigned long n, int type) {\n\t\t\
    if (n >= (unsigned long) (LONG_MAX))\n\t\t\t__testlib_fail(\"random_t::wnext(unsigned\
    \ long n, int type): n must be less LONG_MAX\");\n\n\t\treturn (unsigned long)\
    \ wnext((unsigned long long) (n), type);\n\t}\n\n\t/* Returns weighted random\
    \ value in range [from, to]. */\n\tint wnext(int from, int to, int type) {\n\t\
    \tif (from > to)\n\t\t\t__testlib_fail(\"random_t::wnext(int from, int to, int\
    \ type): from can't not exceed to\");\n\t\treturn wnext(to - from + 1, type) +\
    \ from;\n\t}\n\n\t/* Returns weighted random value in range [from, to]. */\n\t\
    int wnext(unsigned int from, unsigned int to, int type) {\n\t\tif (from > to)\n\
    \t\t\t__testlib_fail(\"random_t::wnext(unsigned int from, unsigned int to, int\
    \ type): from can't not exceed to\");\n\t\treturn int(wnext(to - from + 1, type)\
    \ + from);\n\t}\n\n\t/* Returns weighted random value in range [from, to]. */\n\
    \tlong long wnext(long long from, long long to, int type) {\n\t\tif (from > to)\n\
    \t\t\t__testlib_fail(\"random_t::wnext(long long from, long long to, int type):\
    \ from can't not exceed to\");\n\t\treturn wnext(to - from + 1, type) + from;\n\
    \t}\n\n\t/* Returns weighted random value in range [from, to]. */\n\tunsigned\
    \ long long wnext(unsigned long long from, unsigned long long to, int type) {\n\
    \t\tif (from > to)\n\t\t\t__testlib_fail(\n\t\t\t\t\t\"random_t::wnext(unsigned\
    \ long long from, unsigned long long to, int type): from can't not exceed to\"\
    );\n\t\treturn wnext(to - from + 1, type) + from;\n\t}\n\n\t/* Returns weighted\
    \ random value in range [from, to]. */\n\tlong wnext(long from, long to, int type)\
    \ {\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"random_t::wnext(long from, long\
    \ to, int type): from can't not exceed to\");\n\t\treturn wnext(to - from + 1,\
    \ type) + from;\n\t}\n\n\t/* Returns weighted random value in range [from, to].\
    \ */\n\tunsigned long wnext(unsigned long from, unsigned long to, int type) {\n\
    \t\tif (from > to)\n\t\t\t__testlib_fail(\"random_t::wnext(unsigned long from,\
    \ unsigned long to, int type): from can't not exceed to\");\n\t\treturn wnext(to\
    \ - from + 1, type) + from;\n\t}\n\n\t/* Returns weighted random double value\
    \ in range [from, to). */\n\tdouble wnext(double from, double to, int type) {\n\
    \t\tif (from > to)\n\t\t\t__testlib_fail(\"random_t::wnext(double from, double\
    \ to, int type): from can't not exceed to\");\n\t\treturn wnext(to - from, type)\
    \ + from;\n\t}\n\n\t/* Returns weighted random element from container. */\n\t\
    template<typename Container>\n\ttypename Container::value_type wany(const Container\
    \ &c, int type) {\n\t\tsize_t size = c.size();\n\t\tif (size <= 0)\n\t\t\t__testlib_fail(\"\
    random_t::wany(const Container& c, int type): c.size() must be positive\");\n\t\
    \treturn *(c.begin() + wnext(size, type));\n\t}\n\n\t/* Returns weighted random\
    \ element from iterator range. */\n\ttemplate<typename Iter>\n\ttypename Iter::value_type\
    \ wany(const Iter &begin, const Iter &end, int type) {\n\t\tint size = int(end\
    \ - begin);\n\t\tif (size <= 0)\n\t\t\t__testlib_fail(\n\t\t\t\t\t\"random_t::any(const\
    \ Iter& begin, const Iter& end, int type): range must have positive length\");\n\
    \t\treturn *(begin + wnext(size, type));\n\t}\n\n\t/* Returns random permutation\
    \ of the given size (values are between `first` and `first`+size-1)*/\n\ttemplate<typename\
    \ T, typename E>\n\tstd::vector<E> perm(T size, E first) {\n\t\tif (size <= 0)\n\
    \t\t\t__testlib_fail(\"random_t::perm(T size, E first = 0): size must be positive\"\
    );\n\t\tstd::vector<E> p(size);\n\t\tE current = first;\n\t\tfor (T i = 0; i <\
    \ size; i++)\n\t\t\tp[i] = current++;\n\t\tif (size > 1)\n\t\t\tfor (T i = 1;\
    \ i < size; i++)\n\t\t\t\tstd::swap(p[i], p[next(i + 1)]);\n\t\treturn p;\n\t\
    }\n\n\t/* Returns random permutation of the given size (values are between 0 and\
    \ size-1)*/\n\ttemplate<typename T>\n\tstd::vector<T> perm(T size) {\n\t\treturn\
    \ perm(size, T(0));\n\t}\n\t\n\t/* Returns `size` unordered (unsorted) distinct\
    \ numbers between `from` and `to`. */\n\ttemplate<typename T>\n\tstd::vector<T>\
    \ distinct(int size, T from, T to) {\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"\
    random_t::distinct expected from <= to\");\n\n\t\tif (size < 0)\n\t\t\t__testlib_fail(\"\
    random_t::distinct expected size >= 0\");\n\n\t\tuint64_t n = to - from + 1;\n\
    \t\tif (uint64_t(size) > n)\n\t\t\t__testlib_fail(\"random_t::distinct expected\
    \ size <= to - from + 1\");\n\n\t\tstd::vector<T> result;\n\t\tif (size == 0)\n\
    \t\t\treturn result;\n\n\t\tdouble expected = 0.0;\n\t\tfor (int i = 1; i <= size;\
    \ i++)\n\t\t\texpected += double(n) / double(n - i + 1);\n\t\t\n\t\tif (expected\
    \ < double(n)) {\n\t\t\tstd::set<T> vals;\n\t\t\twhile (int(vals.size()) < size)\n\
    \t\t\t\tvals.insert(T(next(from, to)));\n\t\t\tresult.insert(result.end(), vals.begin(),\
    \ vals.end());\n\t\t} else {\n\t\t\tif (n > 1000000000)\n\t\t\t\t__testlib_fail(\"\
    random_t::distinct here expected to - from + 1 <= 1000000000\");\n\t\t\tstd::vector<T>\
    \ p(perm(int(n), from));\n\t\t\tresult.insert(result.end(), p.begin(), p.begin()\
    \ + size);\n\t\t}\n\n\t\treturn result;\n\t}\n\n\t/* Returns `size` unordered\
    \ (unsorted) distinct numbers between `0` and `upper`-1. */\n\ttemplate<typename\
    \ T>\n\tstd::vector<T> distinct(int size, T upper) {\n\t\tif (size < 0)\n\t\t\t\
    __testlib_fail(\"random_t::distinct expected size >= 0\");\n\t\tif (size == 0)\n\
    \t\t\treturn std::vector<T>();\n\t\t\n\t\tif (upper <= 0)\n\t\t\t__testlib_fail(\"\
    random_t::distinct expected upper > 0\");\n\t\tif (size > upper)\n\t\t\t__testlib_fail(\"\
    random_t::distinct expected size <= upper\");\n\t\t\t\n\t\treturn distinct(size,\
    \ T(0), upper - 1);\n\t}\n\n\t/* Returns random (unsorted) partition which is\
    \ a representation of sum as a sum of integers not less than min_part. */\n\t\
    template<typename T>\n\tstd::vector<T> partition(int size, T sum, T min_part)\
    \ {\n\t\tif (size < 0)\n\t\t\t__testlib_fail(\"random_t::partition: size < 0\"\
    );\n\t\tif (size == 0 && sum != 0)\n\t\t\t__testlib_fail(\"random_t::partition:\
    \ size == 0 && sum != 0\");\n\t\tif (min_part * size > sum)\n\t\t\t__testlib_fail(\"\
    random_t::partition: min_part * size > sum\");\n\n\t\tT sum_ = sum;\n\t\tsum -=\
    \ min_part * size;\n\n\t\tstd::vector<T> septums(size);\n\t\tstd::vector<T> d\
    \ = distinct(size - 1, T(1), T(sum + size - 1));\n\t\tfor (int i = 0; i + 1 <\
    \ size; i++)\n\t\t\tseptums[i + 1] = d[i];\n\t\tsort(septums.begin(), septums.end());\n\
    \n\t\tstd::vector<T> result(size);\n\t\tfor (int i = 0; i + 1 < size; i++)\n\t\
    \t\tresult[i] = septums[i + 1] - septums[i] - 1;\n\t\tresult[size - 1] = sum +\
    \ size - 1 - septums.back();\n\n\t\tfor (std::size_t i = 0; i < result.size();\
    \ i++)\n\t\t\tresult[i] += min_part;\n\t\t\n\t\tT result_sum = 0;\n\t\tfor (std::size_t\
    \ i = 0; i < result.size(); i++)\n\t\t\tresult_sum += result[i];\n\t\tif (result_sum\
    \ != sum_)\n\t\t\t__testlib_fail(\"random_t::partition: partition sum is expeced\
    \ to be the given sum\");\n\t\t\n\t\tif (*std::min_element(result.begin(), result.end())\
    \ < min_part)\n\t\t\t__testlib_fail(\"random_t::partition: partition min is expeced\
    \ to be to less than the given min_part\");\n\t\t\n\t\tif (int(result.size())\
    \ != size || result.size() != (size_t) size)\n\t\t\t__testlib_fail(\"random_t::partition:\
    \ partition size is expected to be equal to the given size\");\n\t\t\n\t\treturn\
    \ result;\n\t}\n\n\t/* Returns random (unsorted) partition which is a representation\
    \ of sum as a sum of positive integers. */\n\ttemplate<typename T>\n\tstd::vector<T>\
    \ partition(int size, T sum) {\n\t\treturn partition(size, sum, T(1));\n\t}\n\
    };\n\nconst int random_t::lim = 25;\nconst unsigned long long random_t::multiplier\
    \ = 0x5DEECE66DLL;\nconst unsigned long long random_t::addend = 0xBLL;\nconst\
    \ unsigned long long random_t::mask = (1LL << 48) - 1;\nint random_t::version\
    \ = -1;\n\n/* Pattern implementation */\nbool pattern::matches(const std::string\
    \ &s) const {\n\treturn matches(s, 0);\n}\n\nstatic bool __pattern_isSlash(const\
    \ std::string &s, size_t pos) {\n\treturn s[pos] == '\\\\';\n}\n\n#ifdef __GNUC__\n\
    __attribute__((pure))\n#endif\nstatic bool __pattern_isCommandChar(const std::string\
    \ &s, size_t pos, char value) {\n\tif (pos >= s.length())\n\t\treturn false;\n\
    \n\tint slashes = 0;\n\n\tint before = int(pos) - 1;\n\twhile (before >= 0 &&\
    \ s[before] == '\\\\')\n\t\tbefore--, slashes++;\n\n\treturn slashes % 2 == 0\
    \ && s[pos] == value;\n}\n\nstatic char __pattern_getChar(const std::string &s,\
    \ size_t &pos) {\n\tif (__pattern_isSlash(s, pos))\n\t\tpos += 2;\n\telse\n\t\t\
    pos++;\n\n\treturn s[pos - 1];\n}\n\n#ifdef __GNUC__\n__attribute__((pure))\n\
    #endif\nstatic int __pattern_greedyMatch(const std::string &s, size_t pos, const\
    \ std::vector<char> chars) {\n\tint result = 0;\n\n\twhile (pos < s.length())\
    \ {\n\t\tchar c = s[pos++];\n\t\tif (!std::binary_search(chars.begin(), chars.end(),\
    \ c))\n\t\t\tbreak;\n\t\telse\n\t\t\tresult++;\n\t}\n\n\treturn result;\n}\n\n\
    std::string pattern::src() const {\n\treturn s;\n}\n\nbool pattern::matches(const\
    \ std::string &s, size_t pos) const {\n\tstd::string result;\n\n\tif (to > 0)\
    \ {\n\t\tint size = __pattern_greedyMatch(s, pos, chars);\n\t\tif (size < from)\n\
    \t\t\treturn false;\n\t\tif (size > to)\n\t\t\tsize = to;\n\t\tpos += size;\n\t\
    }\n\n\tif (children.size() > 0) {\n\t\tfor (size_t child = 0; child < children.size();\
    \ child++)\n\t\t\tif (children[child].matches(s, pos))\n\t\t\t\treturn true;\n\
    \t\treturn false;\n\t} else\n\t\treturn pos == s.length();\n}\n\nstd::string pattern::next(random_t\
    \ &rnd) const {\n\tstd::string result;\n\tresult.reserve(20);\n\n\tif (to == INT_MAX)\n\
    \t\t__testlib_fail(\"pattern::next(random_t& rnd): can't process character '*'\
    \ for generation\");\n\n\tif (to > 0) {\n\t\tint count = rnd.next(to - from +\
    \ 1) + from;\n\t\tfor (int i = 0; i < count; i++)\n\t\t\tresult += chars[rnd.next(int(chars.size()))];\n\
    \t}\n\n\tif (children.size() > 0) {\n\t\tint child = rnd.next(int(children.size()));\n\
    \t\tresult += children[child].next(rnd);\n\t}\n\n\treturn result;\n}\n\nstatic\
    \ void __pattern_scanCounts(const std::string &s, size_t &pos, int &from, int\
    \ &to) {\n\tif (pos >= s.length()) {\n\t\tfrom = to = 1;\n\t\treturn;\n\t}\n\n\
    \tif (__pattern_isCommandChar(s, pos, '{')) {\n\t\tstd::vector<std::string> parts;\n\
    \t\tstd::string part;\n\n\t\tpos++;\n\n\t\twhile (pos < s.length() && !__pattern_isCommandChar(s,\
    \ pos, '}')) {\n\t\t\tif (__pattern_isCommandChar(s, pos, ','))\n\t\t\t\tparts.push_back(part),\
    \ part = \"\", pos++;\n\t\t\telse\n\t\t\t\tpart += __pattern_getChar(s, pos);\n\
    \t\t}\n\n\t\tif (part != \"\")\n\t\t\tparts.push_back(part);\n\n\t\tif (!__pattern_isCommandChar(s,\
    \ pos, '}'))\n\t\t\t__testlib_fail(\"pattern: Illegal pattern (or part) \\\"\"\
    \ + s + \"\\\"\");\n\n\t\tpos++;\n\n\t\tif (parts.size() < 1 || parts.size() >\
    \ 2)\n\t\t\t__testlib_fail(\"pattern: Illegal pattern (or part) \\\"\" + s + \"\
    \\\"\");\n\n\t\tstd::vector<int> numbers;\n\n\t\tfor (size_t i = 0; i < parts.size();\
    \ i++) {\n\t\t\tif (parts[i].length() == 0)\n\t\t\t\t__testlib_fail(\"pattern:\
    \ Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\t\t\tint number;\n\t\t\t\
    if (std::sscanf(parts[i].c_str(), \"%d\", &number) != 1)\n\t\t\t\t__testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\t\t\tnumbers.push_back(number);\n\
    \t\t}\n\n\t\tif (numbers.size() == 1)\n\t\t\tfrom = to = numbers[0];\n\t\telse\n\
    \t\t\tfrom = numbers[0], to = numbers[1];\n\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\t} else {\n\t\tif\
    \ (__pattern_isCommandChar(s, pos, '?')) {\n\t\t\tfrom = 0, to = 1, pos++;\n\t\
    \t\treturn;\n\t\t}\n\n\t\tif (__pattern_isCommandChar(s, pos, '*')) {\n\t\t\t\
    from = 0, to = INT_MAX, pos++;\n\t\t\treturn;\n\t\t}\n\n\t\tif (__pattern_isCommandChar(s,\
    \ pos, '+')) {\n\t\t\tfrom = 1, to = INT_MAX, pos++;\n\t\t\treturn;\n\t\t}\n\n\
    \t\tfrom = to = 1;\n\t}\n}\n\nstatic std::vector<char> __pattern_scanCharSet(const\
    \ std::string &s, size_t &pos) {\n\tif (pos >= s.length())\n\t\t__testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n\tstd::vector<char>\
    \ result;\n\n\tif (__pattern_isCommandChar(s, pos, '[')) {\n\t\tpos++;\n\t\tbool\
    \ negative = __pattern_isCommandChar(s, pos, '^');\n\n\t\tchar prev = 0;\n\n\t\
    \twhile (pos < s.length() && !__pattern_isCommandChar(s, pos, ']')) {\n\t\t\t\
    if (__pattern_isCommandChar(s, pos, '-') && prev != 0) {\n\t\t\t\tpos++;\n\n\t\
    \t\t\tif (pos + 1 == s.length() || __pattern_isCommandChar(s, pos, ']')) {\n\t\
    \t\t\t\tresult.push_back(prev);\n\t\t\t\t\tprev = '-';\n\t\t\t\t\tcontinue;\n\t\
    \t\t\t}\n\n\t\t\t\tchar next = __pattern_getChar(s, pos);\n\t\t\t\tif (prev >\
    \ next)\n\t\t\t\t\t__testlib_fail(\"pattern: Illegal pattern (or part) \\\"\"\
    \ + s + \"\\\"\");\n\n\t\t\t\tfor (char c = prev; c != next; c++)\n\t\t\t\t\t\
    result.push_back(c);\n\t\t\t\tresult.push_back(next);\n\n\t\t\t\tprev = 0;\n\t\
    \t\t} else {\n\t\t\t\tif (prev != 0)\n\t\t\t\t\tresult.push_back(prev);\n\t\t\t\
    \tprev = __pattern_getChar(s, pos);\n\t\t\t}\n\t\t}\n\n\t\tif (prev != 0)\n\t\t\
    \tresult.push_back(prev);\n\n\t\tif (!__pattern_isCommandChar(s, pos, ']'))\n\t\
    \t\t__testlib_fail(\"pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\"\
    );\n\n\t\tpos++;\n\n\t\tif (negative) {\n\t\t\tstd::sort(result.begin(), result.end());\n\
    \t\t\tstd::vector<char> actuals;\n\t\t\tfor (int code = 0; code < 255; code++)\
    \ {\n\t\t\t\tchar c = char(code);\n\t\t\t\tif (!std::binary_search(result.begin(),\
    \ result.end(), c))\n\t\t\t\t\tactuals.push_back(c);\n\t\t\t}\n\t\t\tresult =\
    \ actuals;\n\t\t}\n\n\t\tstd::sort(result.begin(), result.end());\n\t} else\n\t\
    \tresult.push_back(__pattern_getChar(s, pos));\n\n\treturn result;\n}\n\npattern::pattern(std::string\
    \ s) : s(s), from(0), to(0) {\n\tstd::string t;\n\tfor (size_t i = 0; i < s.length();\
    \ i++)\n\t\tif (!__pattern_isCommandChar(s, i, ' '))\n\t\t\tt += s[i];\n\ts =\
    \ t;\n\n\tint opened = 0;\n\tint firstClose = -1;\n\tstd::vector<int> seps;\n\n\
    \tfor (size_t i = 0; i < s.length(); i++) {\n\t\tif (__pattern_isCommandChar(s,\
    \ i, '(')) {\n\t\t\topened++;\n\t\t\tcontinue;\n\t\t}\n\n\t\tif (__pattern_isCommandChar(s,\
    \ i, ')')) {\n\t\t\topened--;\n\t\t\tif (opened == 0 && firstClose == -1)\n\t\t\
    \t\tfirstClose = int(i);\n\t\t\tcontinue;\n\t\t}\n\n\t\tif (opened < 0)\n\t\t\t\
    __testlib_fail(\"pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n\
    \t\tif (__pattern_isCommandChar(s, i, '|') && opened == 0)\n\t\t\tseps.push_back(int(i));\n\
    \t}\n\n\tif (opened != 0)\n\t\t__testlib_fail(\"pattern: Illegal pattern (or part)\
    \ \\\"\" + s + \"\\\"\");\n\n\tif (seps.size() == 0 && firstClose + 1 == (int)\
    \ s.length()\n\t\t&& __pattern_isCommandChar(s, 0, '(') && __pattern_isCommandChar(s,\
    \ s.length() - 1, ')')) {\n\t\tchildren.push_back(pattern(s.substr(1, s.length()\
    \ - 2)));\n\t} else {\n\t\tif (seps.size() > 0) {\n\t\t\tseps.push_back(int(s.length()));\n\
    \t\t\tint last = 0;\n\n\t\t\tfor (size_t i = 0; i < seps.size(); i++) {\n\t\t\t\
    \tchildren.push_back(pattern(s.substr(last, seps[i] - last)));\n\t\t\t\tlast =\
    \ seps[i] + 1;\n\t\t\t}\n\t\t} else {\n\t\t\tsize_t pos = 0;\n\t\t\tchars = __pattern_scanCharSet(s,\
    \ pos);\n\t\t\t__pattern_scanCounts(s, pos, from, to);\n\t\t\tif (pos < s.length())\n\
    \t\t\t\tchildren.push_back(pattern(s.substr(pos)));\n\t\t}\n\t}\n}\n\n/* End of\
    \ pattern implementation */\n\ntemplate<typename C>\ninline bool isEof(C c) {\n\
    \treturn c == EOFC;\n}\n\ntemplate<typename C>\ninline bool isEoln(C c) {\n\t\
    return (c == LF || c == CR);\n}\n\ntemplate<typename C>\ninline bool isBlanks(C\
    \ c) {\n\treturn (c == LF || c == CR || c == SPACE || c == TAB);\n}\n\ninline\
    \ std::string trim(const std::string &s) {\n\tif (s.empty())\n\t\treturn s;\n\n\
    \tint left = 0;\n\twhile (left < int(s.length()) && isBlanks(s[left]))\n\t\tleft++;\n\
    \tif (left >= int(s.length()))\n\t\treturn \"\";\n\n\tint right = int(s.length())\
    \ - 1;\n\twhile (right >= 0 && isBlanks(s[right]))\n\t\tright--;\n\tif (right\
    \ < 0)\n\t\treturn \"\";\n\n\treturn s.substr(left, right - left + 1);\n}\n\n\
    enum TMode {\n\t_input, _output, _answer\n};\n\n/* Outcomes 6-15 are reserved\
    \ for future use. */\nenum TResult {\n\t_ok = 0,\n\t_wa = 1,\n\t_pe = 2,\n\t_fail\
    \ = 3,\n\t_dirt = 4,\n\t_points = 5,\n\t_unexpected_eof = 8,\n\t_partially = 16\n\
    };\n\nenum TTestlibMode {\n\t_unknown, _checker, _validator, _generator, _interactor\n\
    };\n\n#define _pc(exitCode) (TResult(_partially + (exitCode)))\n\n/* Outcomes\
    \ 6-15 are reserved for future use. */\nconst std::string outcomes[] = {\n\t\t\
    \"accepted\",\n\t\t\"wrong-answer\",\n\t\t\"presentation-error\",\n\t\t\"fail\"\
    ,\n\t\t\"fail\",\n#ifndef PCMS2\n\t\t\"points\",\n#else\n\t\t\"relative-scoring\"\
    ,\n#endif\n\t\t\"reserved\",\n\t\t\"reserved\",\n\t\t\"unexpected-eof\",\n\t\t\
    \"reserved\",\n\t\t\"reserved\",\n\t\t\"reserved\",\n\t\t\"reserved\",\n\t\t\"\
    reserved\",\n\t\t\"reserved\",\n\t\t\"reserved\",\n\t\t\"partially-correct\"\n\
    };\n\nclass InputStreamReader {\npublic:\n\tvirtual int curChar() = 0;\n\n\tvirtual\
    \ int nextChar() = 0;\n\n\tvirtual void skipChar() = 0;\n\n\tvirtual void unreadChar(int\
    \ c) = 0;\n\n\tvirtual std::string getName() = 0;\n\n\tvirtual bool eof() = 0;\n\
    \n\tvirtual void close() = 0;\n\n\tvirtual int getLine() = 0;\n\n\tvirtual ~InputStreamReader()\
    \ = 0;\n};\n\nInputStreamReader::~InputStreamReader() {\n\t// No operations.\n\
    }\n\nclass StringInputStreamReader : public InputStreamReader {\nprivate:\n\t\
    std::string s;\n\tsize_t pos;\n\npublic:\n\tStringInputStreamReader(const std::string\
    \ &content) : s(content), pos(0) {\n\t\t// No operations.\n\t}\n\n\tint curChar()\
    \ {\n\t\tif (pos >= s.length())\n\t\t\treturn EOFC;\n\t\telse\n\t\t\treturn s[pos];\n\
    \t}\n\n\tint nextChar() {\n\t\tif (pos >= s.length()) {\n\t\t\tpos++;\n\t\t\t\
    return EOFC;\n\t\t} else\n\t\t\treturn s[pos++];\n\t}\n\n\tvoid skipChar() {\n\
    \t\tpos++;\n\t}\n\n\tvoid unreadChar(int c) {\n\t\tif (pos == 0)\n\t\t\t__testlib_fail(\"\
    FileFileInputStreamReader::unreadChar(int): pos == 0.\");\n\t\tpos--;\n\t\tif\
    \ (pos < s.length())\n\t\t\ts[pos] = char(c);\n\t}\n\n\tstd::string getName()\
    \ {\n\t\treturn __testlib_part(s);\n\t}\n\n\tint getLine() {\n\t\treturn -1;\n\
    \t}\n\n\tbool eof() {\n\t\treturn pos >= s.length();\n\t}\n\n\tvoid close() {\n\
    \t\t// No operations.\n\t}\n};\n\nclass FileInputStreamReader : public InputStreamReader\
    \ {\nprivate:\n\tstd::FILE *file;\n\tstd::string name;\n\tint line;\n\tstd::vector<int>\
    \ undoChars;\n\n\tinline int postprocessGetc(int getcResult) {\n\t\tif (getcResult\
    \ != EOF)\n\t\t\treturn getcResult;\n\t\telse\n\t\t\treturn EOFC;\n\t}\n\n\tint\
    \ getc(FILE *file) {\n\t\tint c;\n\t\tif (undoChars.empty())\n\t\t\tc = ::getc(file);\n\
    \t\telse {\n\t\t\tc = undoChars.back();\n\t\t\tundoChars.pop_back();\n\t\t}\n\n\
    \t\tif (c == LF)\n\t\t\tline++;\n\t\treturn c;\n\t}\n\n\tint ungetc(int c/*, FILE*\
    \ file*/) {\n\t\tif (c == LF)\n\t\t\tline--;\n\t\tundoChars.push_back(c);\n\t\t\
    return c;\n\t}\n\npublic:\n\tFileInputStreamReader(std::FILE *file, const std::string\
    \ &name) : file(file), name(name), line(1) {\n\t\t// No operations.\n\t}\n\n\t\
    int curChar() {\n\t\tif (feof(file))\n\t\t\treturn EOFC;\n\t\telse {\n\t\t\tint\
    \ c = getc(file);\n\t\t\tungetc(c/*, file*/);\n\t\t\treturn postprocessGetc(c);\n\
    \t\t}\n\t}\n\n\tint nextChar() {\n\t\tif (feof(file))\n\t\t\treturn EOFC;\n\t\t\
    else\n\t\t\treturn postprocessGetc(getc(file));\n\t}\n\n\tvoid skipChar() {\n\t\
    \tgetc(file);\n\t}\n\n\tvoid unreadChar(int c) {\n\t\tungetc(c/*, file*/);\n\t\
    }\n\n\tstd::string getName() {\n\t\treturn name;\n\t}\n\n\tint getLine() {\n\t\
    \treturn line;\n\t}\n\n\tbool eof() {\n\t\tif (NULL == file || feof(file))\n\t\
    \t\treturn true;\n\t\telse {\n\t\t\tint c = nextChar();\n\t\t\tif (c == EOFC ||\
    \ (c == EOF && feof(file)))\n\t\t\t\treturn true;\n\t\t\tunreadChar(c);\n\t\t\t\
    return false;\n\t\t}\n\t}\n\n\tvoid close() {\n\t\tif (NULL != file) {\n\t\t\t\
    fclose(file);\n\t\t\tfile = NULL;\n\t\t}\n\t}\n};\n\nclass BufferedFileInputStreamReader\
    \ : public InputStreamReader {\nprivate:\n\tstatic const size_t BUFFER_SIZE;\n\
    \tstatic const size_t MAX_UNREAD_COUNT;\n\n\tstd::FILE *file;\n\tchar *buffer;\n\
    \tbool *isEof;\n\tint bufferPos;\n\tsize_t bufferSize;\n\n\tstd::string name;\n\
    \tint line;\n\n\tbool refill() {\n\t\tif (NULL == file)\n\t\t\t__testlib_fail(\"\
    BufferedFileInputStreamReader: file == NULL (\" + getName() + \")\");\n\n\t\t\
    if (bufferPos >= int(bufferSize)) {\n\t\t\tsize_t readSize = fread(\n\t\t\t\t\t\
    buffer + MAX_UNREAD_COUNT,\n\t\t\t\t\t1,\n\t\t\t\t\tBUFFER_SIZE - MAX_UNREAD_COUNT,\n\
    \t\t\t\t\tfile\n\t\t\t);\n\n\t\t\tif (readSize < BUFFER_SIZE - MAX_UNREAD_COUNT\n\
    \t\t\t\t&& ferror(file))\n\t\t\t\t__testlib_fail(\"BufferedFileInputStreamReader:\
    \ unable to read (\" + getName() + \")\");\n\n\t\t\tbufferSize = MAX_UNREAD_COUNT\
    \ + readSize;\n\t\t\tbufferPos = int(MAX_UNREAD_COUNT);\n\t\t\tstd::memset(isEof\
    \ + MAX_UNREAD_COUNT, 0, sizeof(isEof[0]) * readSize);\n\n\t\t\treturn readSize\
    \ > 0;\n\t\t} else\n\t\t\treturn true;\n\t}\n\n\tchar increment() {\n\t\tchar\
    \ c;\n\t\tif ((c = buffer[bufferPos++]) == LF)\n\t\t\tline++;\n\t\treturn c;\n\
    \t}\n\npublic:\n\tBufferedFileInputStreamReader(std::FILE *file, const std::string\
    \ &name) : file(file), name(name), line(1) {\n\t\tbuffer = new char[BUFFER_SIZE];\n\
    \t\tisEof = new bool[BUFFER_SIZE];\n\t\tbufferSize = MAX_UNREAD_COUNT;\n\t\tbufferPos\
    \ = int(MAX_UNREAD_COUNT);\n\t}\n\n\t~BufferedFileInputStreamReader() {\n\t\t\
    if (NULL != buffer) {\n\t\t\tdelete[] buffer;\n\t\t\tbuffer = NULL;\n\t\t}\n\t\
    \tif (NULL != isEof) {\n\t\t\tdelete[] isEof;\n\t\t\tisEof = NULL;\n\t\t}\n\t\
    }\n\n\tint curChar() {\n\t\tif (!refill())\n\t\t\treturn EOFC;\n\n\t\treturn isEof[bufferPos]\
    \ ? EOFC : buffer[bufferPos];\n\t}\n\n\tint nextChar() {\n\t\tif (!refill())\n\
    \t\t\treturn EOFC;\n\n\t\treturn isEof[bufferPos] ? EOFC : increment();\n\t}\n\
    \n\tvoid skipChar() {\n\t\tincrement();\n\t}\n\n\tvoid unreadChar(int c) {\n\t\
    \tbufferPos--;\n\t\tif (bufferPos < 0)\n\t\t\t__testlib_fail(\"BufferedFileInputStreamReader::unreadChar(int):\
    \ bufferPos < 0\");\n\t\tisEof[bufferPos] = (c == EOFC);\n\t\tbuffer[bufferPos]\
    \ = char(c);\n\t\tif (c == LF)\n\t\t\tline--;\n\t}\n\n\tstd::string getName()\
    \ {\n\t\treturn name;\n\t}\n\n\tint getLine() {\n\t\treturn line;\n\t}\n\n\tbool\
    \ eof() {\n\t\treturn !refill() || EOFC == curChar();\n\t}\n\n\tvoid close() {\n\
    \t\tif (NULL != file) {\n\t\t\tfclose(file);\n\t\t\tfile = NULL;\n\t\t}\n\t}\n\
    };\n\nconst size_t BufferedFileInputStreamReader::BUFFER_SIZE = 2000000;\nconst\
    \ size_t BufferedFileInputStreamReader::MAX_UNREAD_COUNT = BufferedFileInputStreamReader::BUFFER_SIZE\
    \ / 2;\n\n/*\n * Streams to be used for reading data in checkers or validators.\n\
    \ * Each read*() method moves pointer to the next character after the\n * read\
    \ value.\n */\nstruct InStream {\n\t/* Do not use them. */\n\tInStream();\n\n\t\
    ~InStream();\n\n\t/* Wrap std::string with InStream. */\n\tInStream(const InStream\
    \ &baseStream, std::string content);\n\n\tInputStreamReader *reader;\n\tint lastLine;\n\
    \n\tstd::string name;\n\tTMode mode;\n\tbool opened;\n\tbool stdfile;\n\tbool\
    \ strict;\n\n\tint wordReserveSize;\n\tstd::string _tmpReadToken;\n\n\tint readManyIteration;\n\
    \tsize_t maxFileSize;\n\tsize_t maxTokenLength;\n\tsize_t maxMessageLength;\n\n\
    \tvoid init(std::string fileName, TMode mode);\n\n\tvoid init(std::FILE *f, TMode\
    \ mode);\n\n\t/* Moves stream pointer to the first non-white-space character or\
    \ EOF. */\n\tvoid skipBlanks();\n\n\t/* Returns current character in the stream.\
    \ Doesn't remove it from stream. */\n\tchar curChar();\n\n\t/* Moves stream pointer\
    \ one character forward. */\n\tvoid skipChar();\n\n\t/* Returns current character\
    \ and moves pointer one character forward. */\n\tchar nextChar();\n\n\t/* Returns\
    \ current character and moves pointer one character forward. */\n\tchar readChar();\n\
    \n\t/* As \"readChar()\" but ensures that the result is equal to given parameter.\
    \ */\n\tchar readChar(char c);\n\n\t/* As \"readChar()\" but ensures that the\
    \ result is equal to the space (code=32). */\n\tchar readSpace();\n\n\t/* Puts\
    \ back the character into the stream. */\n\tvoid unreadChar(char c);\n\n\t/* Reopens\
    \ stream, you should not use it. */\n\tvoid reset(std::FILE *file = NULL);\n\n\
    \t/* Checks that current position is EOF. If not it doesn't move stream pointer.\
    \ */\n\tbool eof();\n\n\t/* Moves pointer to the first non-white-space character\
    \ and calls \"eof()\". */\n\tbool seekEof();\n\n\t/* \n\t * Checks that current\
    \ position contains EOLN. \n\t * If not it doesn't move stream pointer. \n\t *\
    \ In strict mode expects \"#13#10\" for windows or \"#10\" for other platforms.\n\
    \t */\n\tbool eoln();\n\n\t/* Moves pointer to the first non-space and non-tab\
    \ character and calls \"eoln()\". */\n\tbool seekEoln();\n\n\t/* Moves stream\
    \ pointer to the first character of the next line (if exists). */\n\tvoid nextLine();\n\
    \n\t/* \n\t * Reads new token. Ignores white-spaces into the non-strict mode \n\
    \t * (strict mode is used in validators usually). \n\t */\n\tstd::string readWord();\n\
    \n\t/* The same as \"readWord()\", it is preffered to use \"readToken()\". */\n\
    \tstd::string readToken();\n\n\t/* The same as \"readWord()\", but ensures that\
    \ token matches to given pattern. */\n\tstd::string readWord(const std::string\
    \ &ptrn, const std::string &variableName = \"\");\n\n\tstd::string readWord(const\
    \ pattern &p, const std::string &variableName = \"\");\n\n\tstd::vector<std::string>\n\
    \treadWords(int size, const std::string &ptrn, const std::string &variablesName\
    \ = \"\", int indexBase = 1);\n\n\tstd::vector<std::string>\n\treadWords(int size,\
    \ const pattern &p, const std::string &variablesName = \"\", int indexBase = 1);\n\
    \n\tstd::vector<std::string> readWords(int size, int indexBase = 1);\n\n\t/* The\
    \ same as \"readToken()\", but ensures that token matches to given pattern. */\n\
    \tstd::string readToken(const std::string &ptrn, const std::string &variableName\
    \ = \"\");\n\n\tstd::string readToken(const pattern &p, const std::string &variableName\
    \ = \"\");\n\n\tstd::vector<std::string>\n\treadTokens(int size, const std::string\
    \ &ptrn, const std::string &variablesName = \"\", int indexBase = 1);\n\n\tstd::vector<std::string>\n\
    \treadTokens(int size, const pattern &p, const std::string &variablesName = \"\
    \", int indexBase = 1);\n\n\tstd::vector<std::string> readTokens(int size, int\
    \ indexBase = 1);\n\n\tvoid readWordTo(std::string &result);\n\n\tvoid readWordTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n\tvoid\
    \ readWordTo(std::string &result, const std::string &ptrn, const std::string &variableName\
    \ = \"\");\n\n\tvoid readTokenTo(std::string &result);\n\n\tvoid readTokenTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n\tvoid\
    \ readTokenTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName = \"\");\n\n\t/* \n\t * Reads new long long value. Ignores white-spaces\
    \ into the non-strict mode \n\t * (strict mode is used in validators usually).\
    \ \n\t */\n\tlong long readLong();\n\n\tunsigned long long readUnsignedLong();\n\
    \n\t/*\n\t * Reads new int. Ignores white-spaces into the non-strict mode \n\t\
    \ * (strict mode is used in validators usually). \n\t */\n\tint readInteger();\n\
    \n\t/*\n\t * Reads new int. Ignores white-spaces into the non-strict mode \n\t\
    \ * (strict mode is used in validators usually). \n\t */\n\tint readInt();\n\n\
    \t/* As \"readLong()\" but ensures that value in the range [minv,maxv]. */\n\t\
    long long readLong(long long minv, long long maxv, const std::string &variableName\
    \ = \"\");\n\n\t/* Reads space-separated sequence of long longs. */\n\tstd::vector<long\
    \ long>\n\treadLongs(int size, long long minv, long long maxv, const std::string\
    \ &variablesName = \"\", int indexBase = 1);\n\n\t/* Reads space-separated sequence\
    \ of long longs. */\n\tstd::vector<long long> readLongs(int size, int indexBase\
    \ = 1);\n\n\tunsigned long long\n\treadUnsignedLong(unsigned long long minv, unsigned\
    \ long long maxv, const std::string &variableName = \"\");\n\n\tstd::vector<unsigned\
    \ long long>\n\treadUnsignedLongs(int size, unsigned long long minv, unsigned\
    \ long long maxv, const std::string &variablesName = \"\",\n\t\t\t\t\t  int indexBase\
    \ = 1);\n\n\tstd::vector<unsigned long long> readUnsignedLongs(int size, int indexBase\
    \ = 1);\n\n\tunsigned long long readLong(unsigned long long minv, unsigned long\
    \ long maxv, const std::string &variableName = \"\");\n\n\tstd::vector<unsigned\
    \ long long>\n\treadLongs(int size, unsigned long long minv, unsigned long long\
    \ maxv, const std::string &variablesName = \"\",\n\t\t\t  int indexBase = 1);\n\
    \n\t/* As \"readInteger()\" but ensures that value in the range [minv,maxv]. */\n\
    \tint readInteger(int minv, int maxv, const std::string &variableName = \"\");\n\
    \n\t/* As \"readInt()\" but ensures that value in the range [minv,maxv]. */\n\t\
    int readInt(int minv, int maxv, const std::string &variableName = \"\");\n\n\t\
    /* Reads space-separated sequence of integers. */\n\tstd::vector<int>\n\treadIntegers(int\
    \ size, int minv, int maxv, const std::string &variablesName = \"\", int indexBase\
    \ = 1);\n\n\t/* Reads space-separated sequence of integers. */\n\tstd::vector<int>\
    \ readIntegers(int size, int indexBase = 1);\n\n\t/* Reads space-separated sequence\
    \ of integers. */\n\tstd::vector<int> readInts(int size, int minv, int maxv, const\
    \ std::string &variablesName = \"\", int indexBase = 1);\n\n\t/* Reads space-separated\
    \ sequence of integers. */\n\tstd::vector<int> readInts(int size, int indexBase\
    \ = 1);\n\n\t/* \n\t * Reads new double. Ignores white-spaces into the non-strict\
    \ mode \n\t * (strict mode is used in validators usually). \n\t */\n\tdouble readReal();\n\
    \n\t/*\n\t * Reads new double. Ignores white-spaces into the non-strict mode \n\
    \t * (strict mode is used in validators usually). \n\t */\n\tdouble readDouble();\n\
    \n\t/* As \"readReal()\" but ensures that value in the range [minv,maxv]. */\n\
    \tdouble readReal(double minv, double maxv, const std::string &variableName =\
    \ \"\");\n\n\tstd::vector<double>\n\treadReals(int size, double minv, double maxv,\
    \ const std::string &variablesName = \"\", int indexBase = 1);\n\n\tstd::vector<double>\
    \ readReals(int size, int indexBase = 1);\n\n\t/* As \"readDouble()\" but ensures\
    \ that value in the range [minv,maxv]. */\n\tdouble readDouble(double minv, double\
    \ maxv, const std::string &variableName = \"\");\n\n\tstd::vector<double>\n\t\
    readDoubles(int size, double minv, double maxv, const std::string &variablesName\
    \ = \"\", int indexBase = 1);\n\n\tstd::vector<double> readDoubles(int size, int\
    \ indexBase = 1);\n\n\t/* \n\t * As \"readReal()\" but ensures that value in the\
    \ range [minv,maxv] and\n\t * number of digit after the decimal point is in range\
    \ [minAfterPointDigitCount,maxAfterPointDigitCount]\n\t * and number is in the\
    \ form \"[-]digit(s)[.digit(s)]\".\n\t */\n\tdouble readStrictReal(double minv,\
    \ double maxv,\n\t\t\t\t\t\t  int minAfterPointDigitCount, int maxAfterPointDigitCount,\n\
    \t\t\t\t\t\t  const std::string &variableName = \"\");\n\n\tstd::vector<double>\
    \ readStrictReals(int size, double minv, double maxv,\n\t\t\t\t\t\t\t\t\t\tint\
    \ minAfterPointDigitCount, int maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\t\t\t\
    const std::string &variablesName = \"\", int indexBase = 1);\n\n\t/* \n\t * As\
    \ \"readDouble()\" but ensures that value in the range [minv,maxv] and\n\t * number\
    \ of digit after the decimal point is in range [minAfterPointDigitCount,maxAfterPointDigitCount]\n\
    \t * and number is in the form \"[-]digit(s)[.digit(s)]\".\n\t */\n\tdouble readStrictDouble(double\
    \ minv, double maxv,\n\t\t\t\t\t\t\tint minAfterPointDigitCount, int maxAfterPointDigitCount,\n\
    \t\t\t\t\t\t\tconst std::string &variableName = \"\");\n\n\tstd::vector<double>\
    \ readStrictDoubles(int size, double minv, double maxv,\n\t\t\t\t\t\t\t\t\t\t\
    \  int minAfterPointDigitCount, int maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\t\
    \t\t  const std::string &variablesName = \"\", int indexBase = 1);\n\n\t/* As\
    \ readLine(). */\n\tstd::string readString();\n\n\t/* Read many lines. */\n\t\
    std::vector<std::string> readStrings(int size, int indexBase = 1);\n\n\t/* See\
    \ readLine(). */\n\tvoid readStringTo(std::string &result);\n\n\t/* The same as\
    \ \"readLine()/readString()\", but ensures that line matches to the given pattern.\
    \ */\n\tstd::string readString(const pattern &p, const std::string &variableName\
    \ = \"\");\n\n\t/* The same as \"readLine()/readString()\", but ensures that line\
    \ matches to the given pattern. */\n\tstd::string readString(const std::string\
    \ &ptrn, const std::string &variableName = \"\");\n\n\t/* Read many lines. */\n\
    \tstd::vector<std::string>\n\treadStrings(int size, const pattern &p, const std::string\
    \ &variableName = \"\", int indexBase = 1);\n\n\t/* Read many lines. */\n\tstd::vector<std::string>\n\
    \treadStrings(int size, const std::string &ptrn, const std::string &variableName\
    \ = \"\", int indexBase = 1);\n\n\t/* The same as \"readLine()/readString()\"\
    , but ensures that line matches to the given pattern. */\n\tvoid readStringTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n\t/*\
    \ The same as \"readLine()/readString()\", but ensures that line matches to the\
    \ given pattern. */\n\tvoid readStringTo(std::string &result, const std::string\
    \ &ptrn, const std::string &variableName = \"\");\n\n\t/* \n\t * Reads line from\
    \ the current position to EOLN or EOF. Moves stream pointer to \n\t * the first\
    \ character of the new line (if possible). \n\t */\n\tstd::string readLine();\n\
    \n\t/* Read many lines. */\n\tstd::vector<std::string> readLines(int size, int\
    \ indexBase = 1);\n\n\t/* See readLine(). */\n\tvoid readLineTo(std::string &result);\n\
    \n\t/* The same as \"readLine()\", but ensures that line matches to the given\
    \ pattern. */\n\tstd::string readLine(const pattern &p, const std::string &variableName\
    \ = \"\");\n\n\t/* The same as \"readLine()\", but ensures that line matches to\
    \ the given pattern. */\n\tstd::string readLine(const std::string &ptrn, const\
    \ std::string &variableName = \"\");\n\n\t/* Read many lines. */\n\tstd::vector<std::string>\n\
    \treadLines(int size, const pattern &p, const std::string &variableName = \"\"\
    , int indexBase = 1);\n\n\t/* Read many lines. */\n\tstd::vector<std::string>\n\
    \treadLines(int size, const std::string &ptrn, const std::string &variableName\
    \ = \"\", int indexBase = 1);\n\n\t/* The same as \"readLine()\", but ensures\
    \ that line matches to the given pattern. */\n\tvoid readLineTo(std::string &result,\
    \ const pattern &p, const std::string &variableName = \"\");\n\n\t/* The same\
    \ as \"readLine()\", but ensures that line matches to the given pattern. */\n\t\
    void readLineTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName = \"\");\n\n\t/* Reads EOLN or fails. Use it in validators. Calls\
    \ \"eoln()\" method internally. */\n\tvoid readEoln();\n\n\t/* Reads EOF or fails.\
    \ Use it in validators. Calls \"eof()\" method internally. */\n\tvoid readEof();\n\
    \n\t/* \n\t * Quit-functions aborts program with <result> and <message>:\n\t *\
    \ input/answer streams replace any result to FAIL.\n\t */\n\tNORETURN void quit(TResult\
    \ result, const char *msg);\n\t/* \n\t * Quit-functions aborts program with <result>\
    \ and <message>:\n\t * input/answer streams replace any result to FAIL.\n\t */\n\
    \tNORETURN void quitf(TResult result, const char *msg, ...);\n\n\t/*\n\t * Quit-functions\
    \ aborts program with <result> and <message>:\n\t * input/answer streams replace\
    \ any result to FAIL.\n\t */\n\tvoid quitif(bool condition, TResult result, const\
    \ char *msg, ...);\n\t/* \n\t * Quit-functions aborts program with <result> and\
    \ <message>:\n\t * input/answer streams replace any result to FAIL.\n\t */\n\t\
    NORETURN void quits(TResult result, std::string msg);\n\n\t/* \n\t * Checks condition\
    \ and aborts a program if codition is false.\n\t * Returns _wa for ouf and _fail\
    \ on any other streams.\n\t */\n#ifdef __GNUC__\n\t__attribute__ ((format (printf,\
    \ 3, 4)))\n#endif\n\tvoid ensuref(bool cond, const char *format, ...);\n\n\tvoid\
    \ __testlib_ensure(bool cond, std::string message);\n\n\tvoid close();\n\n\tconst\
    \ static int NO_INDEX = INT_MAX;\n\tconst static char OPEN_BRACKET = char(11);\n\
    \tconst static char CLOSE_BRACKET = char(17);\n\n\tconst static WORD LightGray\
    \ = 0x07;\n\tconst static WORD LightRed = 0x0c;\n\tconst static WORD LightCyan\
    \ = 0x0b;\n\tconst static WORD LightGreen = 0x0a;\n\tconst static WORD LightYellow\
    \ = 0x0e;\n\n\tstatic void textColor(WORD color);\n\n\tstatic void quitscr(WORD\
    \ color, const char *msg);\n\n\tstatic void quitscrS(WORD color, std::string msg);\n\
    \n\tvoid xmlSafeWrite(std::FILE *file, const char *msg);\n\nprivate:\n\tInStream(const\
    \ InStream &);\n\n\tInStream &operator=(const InStream &);\n};\n\nInStream inf;\n\
    InStream ouf;\nInStream ans;\nbool appesMode;\nstd::string resultName;\nstd::string\
    \ checkerName = \"untitled checker\";\nrandom_t rnd;\nTTestlibMode testlibMode\
    \ = _unknown;\ndouble __testlib_points = std::numeric_limits<float>::infinity();\n\
    \nstruct ValidatorBoundsHit {\n\tstatic const double EPS;\n\tbool minHit;\n\t\
    bool maxHit;\n\n\tValidatorBoundsHit(bool minHit = false, bool maxHit = false)\
    \ : minHit(minHit), maxHit(maxHit) {\n\t};\n\n\tValidatorBoundsHit merge(const\
    \ ValidatorBoundsHit &validatorBoundsHit) {\n\t\treturn ValidatorBoundsHit(\n\t\
    \t\t\t__testlib_max(minHit, validatorBoundsHit.minHit),\n\t\t\t\t__testlib_max(maxHit,\
    \ validatorBoundsHit.maxHit)\n\t\t);\n\t}\n};\n\nconst double ValidatorBoundsHit::EPS\
    \ = 1E-12;\n\nclass Validator {\nprivate:\n\tbool _initialized;\n\tstd::string\
    \ _testset;\n\tstd::string _group;\n\tstd::string _testOverviewLogFileName;\n\t\
    std::map<std::string, ValidatorBoundsHit> _boundsHitByVariableName;\n\tstd::set<std::string>\
    \ _features;\n\tstd::set<std::string> _hitFeatures;\n\n\tbool isVariableNameBoundsAnalyzable(const\
    \ std::string &variableName) {\n\t\tfor (size_t i = 0; i < variableName.length();\
    \ i++)\n\t\t\tif ((variableName[i] >= '0' && variableName[i] <= '9') || variableName[i]\
    \ < ' ')\n\t\t\t\treturn false;\n\t\treturn true;\n\t}\n\n\tbool isFeatureNameAnalyzable(const\
    \ std::string &featureName) {\n\t\tfor (size_t i = 0; i < featureName.length();\
    \ i++)\n\t\t\tif (featureName[i] < ' ')\n\t\t\t\treturn false;\n\t\treturn true;\n\
    \t}\n\npublic:\n\tValidator() : _initialized(false), _testset(\"tests\"), _group()\
    \ {\n\t}\n\n\tvoid initialize() {\n\t\t_initialized = true;\n\t}\n\n\tstd::string\
    \ testset() const {\n\t\tif (!_initialized)\n\t\t\t__testlib_fail(\"Validator\
    \ should be initialized with registerValidation(argc, argv) instead of registerValidation()\
    \ to support validator.testset()\");\n\t\treturn _testset;\n\t}\n\n\tstd::string\
    \ group() const {\n\t\tif (!_initialized)\n\t\t\t__testlib_fail(\"Validator should\
    \ be initialized with registerValidation(argc, argv) instead of registerValidation()\
    \ to support validator.group()\");\n\t\treturn _group;\n\t}\n\n\tstd::string testOverviewLogFileName()\
    \ const {\n\t\treturn _testOverviewLogFileName;\n\t}\n\n\tvoid setTestset(const\
    \ char *const testset) {\n\t\t_testset = testset;\n\t}\n\n\tvoid setGroup(const\
    \ char *const group) {\n\t\t_group = group;\n\t}\n\n\tvoid setTestOverviewLogFileName(const\
    \ char *const testOverviewLogFileName) {\n\t\t_testOverviewLogFileName = testOverviewLogFileName;\n\
    \t}\n\n\tvoid addBoundsHit(const std::string &variableName, ValidatorBoundsHit\
    \ boundsHit) {\n\t\tif (isVariableNameBoundsAnalyzable(variableName)) {\n\t\t\t\
    _boundsHitByVariableName[variableName]\n\t\t\t\t\t= boundsHit.merge(_boundsHitByVariableName[variableName]);\n\
    \t\t}\n\t}\n\n\tstd::string getBoundsHitLog() {\n\t\tstd::string result;\n\t\t\
    for (std::map<std::string, ValidatorBoundsHit>::iterator i = _boundsHitByVariableName.begin();\n\
    \t\t\t i != _boundsHitByVariableName.end();\n\t\t\t i++) {\n\t\t\tresult += \"\
    \\\"\" + i->first + \"\\\":\";\n\t\t\tif (i->second.minHit)\n\t\t\t\tresult +=\
    \ \" min-value-hit\";\n\t\t\tif (i->second.maxHit)\n\t\t\t\tresult += \" max-value-hit\"\
    ;\n\t\t\tresult += \"\\n\";\n\t\t}\n\t\treturn result;\n\t}\n\n\tstd::string getFeaturesLog()\
    \ {\n\t\tstd::string result;\n\t\tfor (std::set<std::string>::iterator i = _features.begin();\n\
    \t\t\t i != _features.end();\n\t\t\t i++) {\n\t\t\tresult += \"feature \\\"\"\
    \ + *i + \"\\\":\";\n\t\t\tif (_hitFeatures.count(*i))\n\t\t\t\tresult += \" hit\"\
    ;\n\t\t\tresult += \"\\n\";\n\t\t}\n\t\treturn result;\n\t}\n\n\tvoid writeTestOverviewLog()\
    \ {\n\t\tif (!_testOverviewLogFileName.empty()) {\n\t\t\tstd::string fileName(_testOverviewLogFileName);\n\
    \t\t\t_testOverviewLogFileName = \"\";\n\t\t\tFILE *testOverviewLogFile = fopen(fileName.c_str(),\
    \ \"w\");\n\t\t\tif (NULL == testOverviewLogFile)\n\t\t\t\t__testlib_fail(\"Validator::writeTestOverviewLog:\
    \ can't test overview log to (\" + fileName + \")\");\n\t\t\tfprintf(testOverviewLogFile,\
    \ \"%s%s\", getBoundsHitLog().c_str(), getFeaturesLog().c_str());\n\t\t\tif (fclose(testOverviewLogFile))\n\
    \t\t\t\t__testlib_fail(\n\t\t\t\t\t\t\"Validator::writeTestOverviewLog: can't\
    \ close test overview log file (\" + fileName + \")\");\n\t\t}\n\t}\n\n\tvoid\
    \ addFeature(const std::string &feature) {\n\t\tif (_features.count(feature))\n\
    \t\t\t__testlib_fail(\"Feature \" + feature + \" registered twice.\");\n\t\tif\
    \ (!isFeatureNameAnalyzable(feature))\n\t\t\t__testlib_fail(\"Feature name '\"\
    \ + feature + \"' contains restricted characters.\");\n\n\t\t_features.insert(feature);\n\
    \t}\n\n\tvoid feature(const std::string &feature) {\n\t\tif (!isFeatureNameAnalyzable(feature))\n\
    \t\t\t__testlib_fail(\"Feature name '\" + feature + \"' contains restricted characters.\"\
    );\n\n\t\tif (!_features.count(feature))\n\t\t\t__testlib_fail(\"Feature \" +\
    \ feature + \" didn't registered via addFeature(feature).\");\n\n\t\t_hitFeatures.insert(feature);\n\
    \t}\n} validator;\n\nstruct TestlibFinalizeGuard {\n\tstatic bool alive;\n\tint\
    \ quitCount, readEofCount;\n\n\tTestlibFinalizeGuard() : quitCount(0), readEofCount(0)\
    \ {\n\t\t// No operations.\n\t}\n\n\t~TestlibFinalizeGuard() {\n\t\tbool _alive\
    \ = alive;\n\t\talive = false;\n\n\t\tif (_alive) {\n\t\t\tif (testlibMode ==\
    \ _checker && quitCount == 0)\n\t\t\t\t__testlib_fail(\"Checker must end with\
    \ quit or quitf call.\");\n\n\t\t\tif (testlibMode == _validator && readEofCount\
    \ == 0 && quitCount == 0)\n\t\t\t\t__testlib_fail(\"Validator must end with readEof\
    \ call.\");\n\t\t}\n\n\t\tvalidator.writeTestOverviewLog();\n\t}\n};\n\nbool TestlibFinalizeGuard::alive\
    \ = true;\nTestlibFinalizeGuard testlibFinalizeGuard;\n\n/*\n * Call it to disable\
    \ checks on finalization.\n */\nvoid disableFinalizeGuard() {\n\tTestlibFinalizeGuard::alive\
    \ = false;\n}\n\n/* Interactor streams.\n */\nstd::fstream tout;\n\n/* implementation\n\
    \ */\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\ntemplate<typename T>\n\
    static std::string vtos(const T &t, std::true_type) {\n\tif (t == 0)\n\t\treturn\
    \ \"0\";\n\telse {\n\t\tT n(t);\n\t\tbool negative = n < 0;\n\t\tstd::string s;\n\
    \t\twhile (n != 0) {\n\t\t\tT digit = n % 10;\n\t\t\tif (digit < 0)\n\t\t\t\t\
    digit = -digit;\n\t\t\ts += char('0' + digit);\n\t\t\tn /= 10;\n\t\t}\n\t\tstd::reverse(s.begin(),\
    \ s.end());\n\t\treturn negative ? \"-\" + s : s;\n\t}\n}\n\ntemplate<typename\
    \ T>\nstatic std::string vtos(const T &t, std::false_type) {\n\tstd::string s;\n\
    \tstatic std::stringstream ss;\n\tss.str(std::string());\n\tss.clear();\n\tss\
    \ << t;\n\tss >> s;\n\treturn s;\n}\n\ntemplate<typename T>\nstatic std::string\
    \ vtos(const T &t) {\n\treturn vtos(t, std::is_integral<T>());\n}\n\n/* signed\
    \ case. */\ntemplate<typename T>\nstatic std::string toHumanReadableString(const\
    \ T &n, std::false_type) {\n\tif (n == 0)\n\t\treturn vtos(n);\n\tint trailingZeroCount\
    \ = 0;\n\tT n_ = n;\n\twhile (n_ % 10 == 0)\n\t\tn_ /= 10, trailingZeroCount++;\n\
    \tif (trailingZeroCount >= 7) {\n\t\tif (n_ == 1)\n\t\t\treturn \"10^\" + vtos(trailingZeroCount);\n\
    \t\telse if (n_ == -1)\n\t\t\treturn \"-10^\" + vtos(trailingZeroCount);\n\t\t\
    else\n\t\t\treturn vtos(n_) + \"*10^\" + vtos(trailingZeroCount);\n\t} else\n\t\
    \treturn vtos(n);\n}\n\n/* unsigned case. */\ntemplate<typename T>\nstatic std::string\
    \ toHumanReadableString(const T &n, std::true_type) {\n\tif (n == 0)\n\t\treturn\
    \ vtos(n);\n\tint trailingZeroCount = 0;\n\tT n_ = n;\n\twhile (n_ % 10 == 0)\n\
    \t\tn_ /= 10, trailingZeroCount++;\n\tif (trailingZeroCount >= 7) {\n\t\tif (n_\
    \ == 1)\n\t\t\treturn \"10^\" + vtos(trailingZeroCount);\n\t\telse\n\t\t\treturn\
    \ vtos(n_) + \"*10^\" + vtos(trailingZeroCount);\n\t} else\n\t\treturn vtos(n);\n\
    }\n\ntemplate<typename T>\nstatic std::string toHumanReadableString(const T &n)\
    \ {\n\treturn toHumanReadableString(n, std::is_unsigned<T>());\n}\n#else\ntemplate<typename\
    \ T>\nstatic std::string vtos(const T& t)\n{\n\tstd::string s;\n\tstatic std::stringstream\
    \ ss;\n\tss.str(std::string());\n\tss.clear();\n\tss << t;\n\tss >> s;\n\treturn\
    \ s;\n}\n\ntemplate<typename T>\nstatic std::string toHumanReadableString(const\
    \ T &n) {\n\treturn vtos(n);\n}\n#endif\n\ntemplate<typename T>\nstatic std::string\
    \ toString(const T &t) {\n\treturn vtos(t);\n}\n\nInStream::InStream() {\n\treader\
    \ = NULL;\n\tlastLine = -1;\n\tname = \"\";\n\tmode = _input;\n\tstrict = false;\n\
    \tstdfile = false;\n\twordReserveSize = 4;\n\treadManyIteration = NO_INDEX;\n\t\
    maxFileSize = 128 * 1024 * 1024; // 128MB.\n\tmaxTokenLength = 32 * 1024 * 1024;\
    \ // 32MB.\n\tmaxMessageLength = 32000;\n}\n\nInStream::InStream(const InStream\
    \ &baseStream, std::string content) {\n\treader = new StringInputStreamReader(content);\n\
    \tlastLine = -1;\n\topened = true;\n\tstrict = baseStream.strict;\n\tmode = baseStream.mode;\n\
    \tname = \"based on \" + baseStream.name;\n\treadManyIteration = NO_INDEX;\n\t\
    maxFileSize = 128 * 1024 * 1024; // 128MB.\n\tmaxTokenLength = 32 * 1024 * 1024;\
    \ // 32MB.\n\tmaxMessageLength = 32000;\n}\n\nInStream::~InStream() {\n\tif (NULL\
    \ != reader) {\n\t\treader->close();\n\t\tdelete reader;\n\t\treader = NULL;\n\
    \t}\n}\n\n#ifdef __GNUC__\n__attribute__((const))\n#endif\nint resultExitCode(TResult\
    \ r) {\n\tif (r == _ok)\n\t\treturn OK_EXIT_CODE;\n\tif (r == _wa)\n\t\treturn\
    \ WA_EXIT_CODE;\n\tif (r == _pe)\n\t\treturn PE_EXIT_CODE;\n\tif (r == _fail)\n\
    \t\treturn FAIL_EXIT_CODE;\n\tif (r == _dirt)\n\t\treturn DIRT_EXIT_CODE;\n\t\
    if (r == _points)\n\t\treturn POINTS_EXIT_CODE;\n\tif (r == _unexpected_eof)\n\
    #ifdef ENABLE_UNEXPECTED_EOF\n\t\treturn UNEXPECTED_EOF_EXIT_CODE;\n#else\n\t\t\
    return PE_EXIT_CODE;\n#endif\n\tif (r >= _partially)\n\t\treturn PC_BASE_EXIT_CODE\
    \ + (r - _partially);\n\treturn FAIL_EXIT_CODE;\n}\n\nvoid InStream::textColor(\n\
    #if !(defined(ON_WINDOWS) && (!defined(_MSC_VER) || _MSC_VER > 1400)) && defined(__GNUC__)\n\
    \t\t__attribute__((unused))\n#endif\n\t\tWORD color\n) {\n#if defined(ON_WINDOWS)\
    \ && (!defined(_MSC_VER) || _MSC_VER > 1400)\n\tHANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);\n\
    \tSetConsoleTextAttribute(handle, color);\n#endif\n#if !defined(ON_WINDOWS) &&\
    \ defined(__GNUC__)\n\tif (isatty(2))\n\t{\n\t\tswitch (color)\n\t\t{\n\t\tcase\
    \ LightRed:\n\t\t\tfprintf(stderr, \"\\033[1;31m\");\n\t\t\tbreak;\n\t\tcase LightCyan:\n\
    \t\t\tfprintf(stderr, \"\\033[1;36m\");\n\t\t\tbreak;\n\t\tcase LightGreen:\n\t\
    \t\tfprintf(stderr, \"\\033[1;32m\");\n\t\t\tbreak;\n\t\tcase LightYellow:\n\t\
    \t\tfprintf(stderr, \"\\033[1;33m\");\n\t\t\tbreak;\n\t\tcase LightGray:\n\t\t\
    default:\n\t\t\tfprintf(stderr, \"\\033[0m\");\n\t\t}\n\t}\n#endif\n}\n\nNORETURN\
    \ void halt(int exitCode) {\n#ifdef FOOTER\n\tInStream::textColor(InStream::LightGray);\n\
    \tstd::fprintf(stderr, \"Checker: \\\"%s\\\"\\n\", checkerName.c_str());\n\tstd::fprintf(stderr,\
    \ \"Exit code: %d\\n\", exitCode);\n\tInStream::textColor(InStream::LightGray);\n\
    #endif\n\tstd::exit(exitCode);\n}\n\nstatic bool __testlib_shouldCheckDirt(TResult\
    \ result) {\n\treturn result == _ok || result == _points || result >= _partially;\n\
    }\n\nstatic std::string __testlib_appendMessage(const std::string &message, const\
    \ std::string &extra) {\n\tint openPos = -1, closePos = -1;\n\tfor (size_t i =\
    \ 0; i < message.length(); i++) {\n\t\tif (message[i] == InStream::OPEN_BRACKET)\
    \ {\n\t\t\tif (openPos == -1)\n\t\t\t\topenPos = i;\n\t\t\telse\n\t\t\t\topenPos\
    \ = INT_MAX;\n\t\t}\n\t\tif (message[i] == InStream::CLOSE_BRACKET) {\n\t\t\t\
    if (closePos == -1)\n\t\t\t\tclosePos = i;\n\t\t\telse\n\t\t\t\tclosePos = INT_MAX;\n\
    \t\t}\n\t}\n\tif (openPos != -1 && openPos != INT_MAX\n\t\t&& closePos != -1 &&\
    \ closePos != INT_MAX\n\t\t&& openPos < closePos) {\n\t\tsize_t index = message.find(extra,\
    \ openPos);\n\t\tif (index == std::string::npos || int(index) >= closePos) {\n\
    \t\t\tstd::string result(message);\n\t\t\tresult.insert(closePos, \", \" + extra);\n\
    \t\t\treturn result;\n\t\t}\n\t\treturn message;\n\t}\n\n\treturn message + \"\
    \ \" + InStream::OPEN_BRACKET + extra + InStream::CLOSE_BRACKET;\n}\n\nstatic\
    \ std::string __testlib_toPrintableMessage(const std::string &message) {\n\tint\
    \ openPos = -1, closePos = -1;\n\tfor (size_t i = 0; i < message.length(); i++)\
    \ {\n\t\tif (message[i] == InStream::OPEN_BRACKET) {\n\t\t\tif (openPos == -1)\n\
    \t\t\t\topenPos = i;\n\t\t\telse\n\t\t\t\topenPos = INT_MAX;\n\t\t}\n\t\tif (message[i]\
    \ == InStream::CLOSE_BRACKET) {\n\t\t\tif (closePos == -1)\n\t\t\t\tclosePos =\
    \ i;\n\t\t\telse\n\t\t\t\tclosePos = INT_MAX;\n\t\t}\n\t}\n\tif (openPos != -1\
    \ && openPos != INT_MAX\n\t\t&& closePos != -1 && closePos != INT_MAX\n\t\t&&\
    \ openPos < closePos) {\n\t\tstd::string result(message);\n\t\tresult[openPos]\
    \ = '(';\n\t\tresult[closePos] = ')';\n\t\treturn result;\n\t}\n\n\treturn message;\n\
    }\n\nNORETURN void InStream::quit(TResult result, const char *msg) {\n\tif (TestlibFinalizeGuard::alive)\n\
    \t\ttestlibFinalizeGuard.quitCount++;\n\n\tstd::string message(msg);\n\tmessage\
    \ = trim(message);\n\n\tif (__testlib_hasTestCase) {\n\t\tif (result != _ok)\n\
    \t\t\tmessage = __testlib_appendMessage(message, \"test case \" + vtos(__testlib_testCase));\n\
    \t\telse {\n\t\t\tif (__testlib_testCase == 1)\n\t\t\t\tmessage = __testlib_appendMessage(message,\
    \ vtos(__testlib_testCase) + \" test case\");\n\t\t\telse\n\t\t\t\tmessage = __testlib_appendMessage(message,\
    \ vtos(__testlib_testCase) + \" test cases\");\n\t\t}\n\t}\n\n\t// You can change\
    \ maxMessageLength.\n\t// Example: 'inf.maxMessageLength = 1024 * 1024;'.\n\t\
    if (message.length() > maxMessageLength) {\n\t\tstd::string warn = \"message length\
    \ exceeds \" + vtos(maxMessageLength)\n\t\t\t\t\t\t   + \", the message is truncated:\
    \ \";\n\t\tmessage = warn + message.substr(0, maxMessageLength - warn.length());\n\
    \t}\n\n#ifndef ENABLE_UNEXPECTED_EOF\n\tif (result == _unexpected_eof)\n\t\tresult\
    \ = _pe;\n#endif\n\n\tif (mode != _output && result != _fail) {\n\t\tif (mode\
    \ == _input && testlibMode == _validator && lastLine != -1)\n\t\t\tquits(_fail,\
    \ __testlib_appendMessage(__testlib_appendMessage(message, name), \"line \" +\
    \ vtos(lastLine)));\n\t\telse\n\t\t\tquits(_fail, __testlib_appendMessage(message,\
    \ name));\n\t}\n\n\tstd::FILE *resultFile;\n\tstd::string errorName;\n\n\tif (__testlib_shouldCheckDirt(result))\
    \ {\n\t\tif (testlibMode != _interactor && !ouf.seekEof())\n\t\t\tquit(_dirt,\
    \ \"Extra information in the output file\");\n\t}\n\n\tint pctype = result - _partially;\n\
    \tbool isPartial = false;\n\n\tswitch (result) {\n\t\tcase _ok:\n\t\t\terrorName\
    \ = \"ok \";\n\t\t\tquitscrS(LightGreen, errorName);\n\t\t\tbreak;\n\t\tcase _wa:\n\
    \t\t\terrorName = \"wrong answer \";\n\t\t\tquitscrS(LightRed, errorName);\n\t\
    \t\tbreak;\n\t\tcase _pe:\n\t\t\terrorName = \"wrong output format \";\n\t\t\t\
    quitscrS(LightRed, errorName);\n\t\t\tbreak;\n\t\tcase _fail:\n\t\t\terrorName\
    \ = \"FAIL \";\n\t\t\tquitscrS(LightRed, errorName);\n\t\t\tbreak;\n\t\tcase _dirt:\n\
    \t\t\terrorName = \"wrong output format \";\n\t\t\tquitscrS(LightCyan, errorName);\n\
    \t\t\tresult = _pe;\n\t\t\tbreak;\n\t\tcase _points:\n\t\t\terrorName = \"points\
    \ \";\n\t\t\tquitscrS(LightYellow, errorName);\n\t\t\tbreak;\n\t\tcase _unexpected_eof:\n\
    \t\t\terrorName = \"unexpected eof \";\n\t\t\tquitscrS(LightCyan, errorName);\n\
    \t\t\tbreak;\n\t\tdefault:\n\t\t\tif (result >= _partially) {\n\t\t\t\terrorName\
    \ = format(\"partially correct (%d) \", pctype);\n\t\t\t\tisPartial = true;\n\t\
    \t\t\tquitscrS(LightYellow, errorName);\n\t\t\t} else\n\t\t\t\tquit(_fail, \"\
    What is the code ??? \");\n\t}\n\n\tif (resultName != \"\") {\n\t\tresultFile\
    \ = std::fopen(resultName.c_str(), \"w\");\n\t\tif (resultFile == NULL) {\n\t\t\
    \tresultName = \"\";\n\t\t\tquit(_fail, \"Can not write to the result file\");\n\
    \t\t}\n\t\tif (appesMode) {\n\t\t\tstd::fprintf(resultFile, \"<?xml version=\\\
    \"1.0\\\" encoding=\\\"windows-1251\\\"?>\");\n\t\t\tif (isPartial)\n\t\t\t\t\
    std::fprintf(resultFile, \"<result outcome = \\\"%s\\\" pctype = \\\"%d\\\">\"\
    ,\n\t\t\t\t\t\t\t outcomes[(int) _partially].c_str(), pctype);\n\t\t\telse {\n\
    \t\t\t\tif (result != _points)\n\t\t\t\t\tstd::fprintf(resultFile, \"<result outcome\
    \ = \\\"%s\\\">\", outcomes[(int) result].c_str());\n\t\t\t\telse {\n\t\t\t\t\t\
    if (__testlib_points == std::numeric_limits<float>::infinity())\n\t\t\t\t\t\t\
    quit(_fail, \"Expected points, but infinity found\");\n\t\t\t\t\tstd::string stringPoints\
    \ = removeDoubleTrailingZeroes(format(\"%.10f\", __testlib_points));\n\t\t\t\t\
    \tstd::fprintf(resultFile, \"<result outcome = \\\"%s\\\" points = \\\"%s\\\"\
    >\",\n\t\t\t\t\t\t\t\t outcomes[(int) result].c_str(), stringPoints.c_str());\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\txmlSafeWrite(resultFile, __testlib_toPrintableMessage(message).c_str());\n\
    \t\t\tstd::fprintf(resultFile, \"</result>\\n\");\n\t\t} else\n\t\t\tstd::fprintf(resultFile,\
    \ \"%s\", __testlib_toPrintableMessage(message).c_str());\n\t\tif (NULL == resultFile\
    \ || fclose(resultFile) != 0) {\n\t\t\tresultName = \"\";\n\t\t\tquit(_fail, \"\
    Can not write to the result file\");\n\t\t}\n\t}\n\n\tquitscr(LightGray, __testlib_toPrintableMessage(message).c_str());\n\
    \tstd::fprintf(stderr, \"\\n\");\n\n\tinf.close();\n\touf.close();\n\tans.close();\n\
    \tif (tout.is_open())\n\t\ttout.close();\n\n\ttextColor(LightGray);\n\n\tif (resultName\
    \ != \"\")\n\t\tstd::fprintf(stderr, \"See file to check exit message\\n\");\n\
    \n\thalt(resultExitCode(result));\n}\n\n#ifdef __GNUC__\n__attribute__ ((format\
    \ (printf, 3, 4)))\n#endif\nNORETURN void InStream::quitf(TResult result, const\
    \ char *msg, ...) {\n\tFMT_TO_RESULT(msg, msg, message);\n\tInStream::quit(result,\
    \ message.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 4,\
    \ 5)))\n#endif\nvoid InStream::quitif(bool condition, TResult result, const char\
    \ *msg, ...) {\n\tif (condition) {\n\t\tFMT_TO_RESULT(msg, msg, message);\n\t\t\
    InStream::quit(result, message.c_str());\n\t}\n}\n\nNORETURN void InStream::quits(TResult\
    \ result, std::string msg) {\n\tInStream::quit(result, msg.c_str());\n}\n\nvoid\
    \ InStream::xmlSafeWrite(std::FILE *file, const char *msg) {\n\tsize_t lmsg =\
    \ strlen(msg);\n\tfor (size_t i = 0; i < lmsg; i++) {\n\t\tif (msg[i] == '&')\
    \ {\n\t\t\tstd::fprintf(file, \"%s\", \"&amp;\");\n\t\t\tcontinue;\n\t\t}\n\t\t\
    if (msg[i] == '<') {\n\t\t\tstd::fprintf(file, \"%s\", \"&lt;\");\n\t\t\tcontinue;\n\
    \t\t}\n\t\tif (msg[i] == '>') {\n\t\t\tstd::fprintf(file, \"%s\", \"&gt;\");\n\
    \t\t\tcontinue;\n\t\t}\n\t\tif (msg[i] == '\"') {\n\t\t\tstd::fprintf(file, \"\
    %s\", \"&quot;\");\n\t\t\tcontinue;\n\t\t}\n\t\tif (0 <= msg[i] && msg[i] <= 31)\
    \ {\n\t\t\tstd::fprintf(file, \"%c\", '.');\n\t\t\tcontinue;\n\t\t}\n\t\tstd::fprintf(file,\
    \ \"%c\", msg[i]);\n\t}\n}\n\nvoid InStream::quitscrS(WORD color, std::string\
    \ msg) {\n\tquitscr(color, msg.c_str());\n}\n\nvoid InStream::quitscr(WORD color,\
    \ const char *msg) {\n\tif (resultName == \"\") {\n\t\ttextColor(color);\n\t\t\
    std::fprintf(stderr, \"%s\", msg);\n\t\ttextColor(LightGray);\n\t}\n}\n\nvoid\
    \ InStream::reset(std::FILE *file) {\n\tif (opened && stdfile)\n\t\tquit(_fail,\
    \ \"Can't reset standard handle\");\n\n\tif (opened)\n\t\tclose();\n\n\tif (!stdfile)\n\
    \t\tif (NULL == (file = std::fopen(name.c_str(), \"rb\"))) {\n\t\t\tif (mode ==\
    \ _output)\n\t\t\t\tquits(_pe, std::string(\"Output file not found: \\\"\") +\
    \ name + \"\\\"\");\n\n\t\t\tif (mode == _answer)\n\t\t\t\tquits(_fail, std::string(\"\
    Answer file not found: \\\"\") + name + \"\\\"\");\n\t\t}\n\n\tif (NULL != file)\
    \ {\n\t\topened = true;\n\n\t\t__testlib_set_binary(file);\n\n\t\tif (stdfile)\n\
    \t\t\treader = new FileInputStreamReader(file, name);\n\t\telse\n\t\t\treader\
    \ = new BufferedFileInputStreamReader(file, name);\n\t} else {\n\t\topened = false;\n\
    \t\treader = NULL;\n\t}\n}\n\nvoid InStream::init(std::string fileName, TMode\
    \ mode) {\n\topened = false;\n\tname = fileName;\n\tstdfile = false;\n\tthis->mode\
    \ = mode;\n\n\tstd::ifstream stream;\n\tstream.open(fileName.c_str(), std::ios::in);\n\
    \tif (stream.is_open()) {\n\t\tstd::streampos start = stream.tellg();\n\t\tstream.seekg(0,\
    \ std::ios::end);\n\t\tstd::streampos end = stream.tellg();\n\t\tsize_t fileSize\
    \ = size_t(end - start);\n\t\tstream.close();\n\n\t\t// You can change maxFileSize.\n\
    \t\t// Example: 'inf.maxFileSize = 256 * 1024 * 1024;'.\n\t\tif (fileSize > maxFileSize)\n\
    \t\t\tquitf(_pe, \"File size exceeds %d bytes, size is %d\", int(maxFileSize),\
    \ int(fileSize));\n\t}\n\n\treset();\n}\n\nvoid InStream::init(std::FILE *f, TMode\
    \ mode) {\n\topened = false;\n\tname = \"untitled\";\n\tthis->mode = mode;\n\n\
    \tif (f == stdin)\n\t\tname = \"stdin\", stdfile = true;\n\tif (f == stdout)\n\
    \t\tname = \"stdout\", stdfile = true;\n\tif (f == stderr)\n\t\tname = \"stderr\"\
    , stdfile = true;\n\n\treset(f);\n}\n\nchar InStream::curChar() {\n\treturn char(reader->curChar());\n\
    }\n\nchar InStream::nextChar() {\n\treturn char(reader->nextChar());\n}\n\nchar\
    \ InStream::readChar() {\n\treturn nextChar();\n}\n\nchar InStream::readChar(char\
    \ c) {\n\tlastLine = reader->getLine();\n\tchar found = readChar();\n\tif (c !=\
    \ found) {\n\t\tif (!isEoln(found))\n\t\t\tquit(_pe, (\"Unexpected character '\"\
    \ + std::string(1, found) + \"', but '\" + std::string(1, c) +\n\t\t\t\t\t   \"\
    ' expected\").c_str());\n\t\telse\n\t\t\tquit(_pe, (\"Unexpected character \"\
    \ + (\"#\" + vtos(int(found))) + \", but '\" + std::string(1, c) +\n\t\t\t\t\t\
    \   \"' expected\").c_str());\n\t}\n\treturn found;\n}\n\nchar InStream::readSpace()\
    \ {\n\treturn readChar(' ');\n}\n\nvoid InStream::unreadChar(char c) {\n\treader->unreadChar(c);\n\
    }\n\nvoid InStream::skipChar() {\n\treader->skipChar();\n}\n\nvoid InStream::skipBlanks()\
    \ {\n\twhile (isBlanks(reader->curChar()))\n\t\treader->skipChar();\n}\n\nstd::string\
    \ InStream::readWord() {\n\treadWordTo(_tmpReadToken);\n\treturn _tmpReadToken;\n\
    }\n\nvoid InStream::readWordTo(std::string &result) {\n\tif (!strict)\n\t\tskipBlanks();\n\
    \n\tlastLine = reader->getLine();\n\tint cur = reader->nextChar();\n\n\tif (cur\
    \ == EOFC)\n\t\tquit(_unexpected_eof, \"Unexpected end of file - token expected\"\
    );\n\n\tif (isBlanks(cur))\n\t\tquit(_pe, \"Unexpected white-space - token expected\"\
    );\n\n\tresult.clear();\n\n\twhile (!(isBlanks(cur) || cur == EOFC)) {\n\t\tresult\
    \ += char(cur);\n\n\t\t// You can change maxTokenLength.\n\t\t// Example: 'inf.maxTokenLength\
    \ = 128 * 1024 * 1024;'.\n\t\tif (result.length() > maxTokenLength)\n\t\t\tquitf(_pe,\
    \ \"Length of token exceeds %d, token is '%s...'\", int(maxTokenLength),\n\t\t\
    \t\t  __testlib_part(result).c_str());\n\n\t\tcur = reader->nextChar();\n\t}\n\
    \n\treader->unreadChar(cur);\n\n\tif (result.length() == 0)\n\t\tquit(_unexpected_eof,\
    \ \"Unexpected end of file or white-space - token expected\");\n}\n\nstd::string\
    \ InStream::readToken() {\n\treturn readWord();\n}\n\nvoid InStream::readTokenTo(std::string\
    \ &result) {\n\treadWordTo(result);\n}\n\nstatic std::string __testlib_part(const\
    \ std::string &s) {\n\tif (s.length() <= 64)\n\t\treturn s;\n\telse\n\t\treturn\
    \ s.substr(0, 30) + \"...\" + s.substr(s.length() - 31, 31);\n}\n\n#define __testlib_readMany(readMany,\
    \ readOne, typeName, space)\t\t\t\t  \\\n\tif (size < 0)\t\t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t   \\\n\t\tquit(_fail, #readMany \": size should be non-negative.\");\t\
    \t\t\t\\\n\tif (size > 100000000)\t\t\t\t\t\t\t\t\t\t\t\t\t   \\\n\t\tquit(_fail,\
    \ #readMany \": size should be at most 100000000.\");\t\t   \\\n\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\tstd::vector<typeName> result(size);\t\t\t\t\t\t\
    \t\t\t\t \\\n\treadManyIteration = indexBase;\t\t\t\t\t\t\t\t\t\t\t  \\\n\t\t\t\
    \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\tfor (int i = 0; i < size; i++)\t\t\t\t\
    \t\t\t\t\t\t\t  \\\n\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   \\\n\t\tresult[i]\
    \ = readOne;\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\t\treadManyIteration++;\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\\\n\t\tif (strict && space && i + 1 < size)\t\t\t\t\t\t\t\t\t\t\
    \t  \\\n\t\t\treadSpace();\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\t}\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t   \\\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\treadManyIteration\
    \ = NO_INDEX;\t\t\t\t\t\t\t\t\t\t\t   \\\n\treturn result;\t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t  \\\n\n\nstd::string InStream::readWord(const pattern &p, const std::string\
    \ &variableName) {\n\treadWordTo(_tmpReadToken);\n\tif (!p.matches(_tmpReadToken))\
    \ {\n\t\tif (readManyIteration == NO_INDEX) {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Token \\\"\" + __testlib_part(_tmpReadToken)\
    \ + \"\\\" doesn't correspond to pattern \\\"\" + p.src() +\n\t\t\t\t\t  \"\\\"\
    \").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa, (\"Token parameter [name=\" + variableName\
    \ + \"] equals to \\\"\" + __testlib_part(_tmpReadToken) +\n\t\t\t\t\t\t   \"\\\
    \", doesn't correspond to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n\t\t\
    } else {\n\t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa, (\"Token element\
    \ [index=\" + vtos(readManyIteration) + \"] equals to \\\"\" +\n\t\t\t\t\t\t \
    \  __testlib_part(_tmpReadToken) + \"\\\" doesn't correspond to pattern \\\"\"\
    \ + p.src() +\n\t\t\t\t\t\t   \"\\\"\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\
    \ (\"Token element \" + variableName + \"[\" + vtos(readManyIteration) + \"] equals\
    \ to \\\"\" +\n\t\t\t\t\t\t   __testlib_part(_tmpReadToken) + \"\\\", doesn't\
    \ correspond to pattern \\\"\" + p.src() +\n\t\t\t\t\t\t   \"\\\"\").c_str());\n\
    \t\t}\n\t}\n\treturn _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readWords(int\
    \ size, const pattern &p, const std::string &variablesName, int indexBase) {\n\
    \t__testlib_readMany(readWords, readWord(p, variablesName), std::string, true);\n\
    }\n\nstd::vector<std::string> InStream::readWords(int size, int indexBase) {\n\
    \t__testlib_readMany(readWords, readWord(), std::string, true);\n}\n\nstd::string\
    \ InStream::readWord(const std::string &ptrn, const std::string &variableName)\
    \ {\n\treturn readWord(pattern(ptrn), variableName);\n}\n\nstd::vector<std::string>\n\
    InStream::readWords(int size, const std::string &ptrn, const std::string &variablesName,\
    \ int indexBase) {\n\tpattern p(ptrn);\n\t__testlib_readMany(readWords, readWord(p,\
    \ variablesName), std::string, true);\n}\n\nstd::string InStream::readToken(const\
    \ pattern &p, const std::string &variableName) {\n\treturn readWord(p, variableName);\n\
    }\n\nstd::vector<std::string>\nInStream::readTokens(int size, const pattern &p,\
    \ const std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readTokens,\
    \ readToken(p, variablesName), std::string, true);\n}\n\nstd::vector<std::string>\
    \ InStream::readTokens(int size, int indexBase) {\n\t__testlib_readMany(readTokens,\
    \ readToken(), std::string, true);\n}\n\nstd::string InStream::readToken(const\
    \ std::string &ptrn, const std::string &variableName) {\n\treturn readWord(ptrn,\
    \ variableName);\n}\n\nstd::vector<std::string>\nInStream::readTokens(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \tpattern p(ptrn);\n\t__testlib_readMany(readTokens, readWord(p, variablesName),\
    \ std::string, true);\n}\n\nvoid InStream::readWordTo(std::string &result, const\
    \ pattern &p, const std::string &variableName) {\n\treadWordTo(result);\n\tif\
    \ (!p.matches(result)) {\n\t\tif (variableName.empty())\n\t\t\tquit(_wa, (\"Token\
    \ \\\"\" + __testlib_part(result) + \"\\\" doesn't correspond to pattern \\\"\"\
    \ + p.src() +\n\t\t\t\t\t   \"\\\"\").c_str());\n\t\telse\n\t\t\tquit(_wa, (\"\
    Token parameter [name=\" + variableName + \"] equals to \\\"\" + __testlib_part(result)\
    \ +\n\t\t\t\t\t   \"\\\", doesn't correspond to pattern \\\"\" + p.src() + \"\\\
    \"\").c_str());\n\t}\n}\n\nvoid InStream::readWordTo(std::string &result, const\
    \ std::string &ptrn, const std::string &variableName) {\n\treturn readWordTo(result,\
    \ pattern(ptrn), variableName);\n}\n\nvoid InStream::readTokenTo(std::string &result,\
    \ const pattern &p, const std::string &variableName) {\n\treturn readWordTo(result,\
    \ p, variableName);\n}\n\nvoid InStream::readTokenTo(std::string &result, const\
    \ std::string &ptrn, const std::string &variableName) {\n\treturn readWordTo(result,\
    \ ptrn, variableName);\n}\n\n#ifdef __GNUC__\n__attribute__((pure))\n#endif\n\
    static inline bool equals(long long integer, const char *s) {\n\tif (integer ==\
    \ LLONG_MIN)\n\t\treturn strcmp(s, \"-9223372036854775808\") == 0;\n\n\tif (integer\
    \ == 0LL)\n\t\treturn strcmp(s, \"0\") == 0;\n\n\tsize_t length = strlen(s);\n\
    \n\tif (length == 0)\n\t\treturn false;\n\n\tif (integer < 0 && s[0] != '-')\n\
    \t\treturn false;\n\n\tif (integer < 0)\n\t\ts++, length--, integer = -integer;\n\
    \n\tif (length == 0)\n\t\treturn false;\n\n\twhile (integer > 0) {\n\t\tint digit\
    \ = int(integer % 10);\n\n\t\tif (s[length - 1] != '0' + digit)\n\t\t\treturn\
    \ false;\n\n\t\tlength--;\n\t\tinteger /= 10;\n\t}\n\n\treturn length == 0;\n\
    }\n\n#ifdef __GNUC__\n__attribute__((pure))\n#endif\nstatic inline bool equals(unsigned\
    \ long long integer, const char *s) {\n\tif (integer == ULLONG_MAX)\n\t\treturn\
    \ strcmp(s, \"18446744073709551615\") == 0;\n\n\tif (integer == 0ULL)\n\t\treturn\
    \ strcmp(s, \"0\") == 0;\n\n\tsize_t length = strlen(s);\n\n\tif (length == 0)\n\
    \t\treturn false;\n\n\twhile (integer > 0) {\n\t\tint digit = int(integer % 10);\n\
    \n\t\tif (s[length - 1] != '0' + digit)\n\t\t\treturn false;\n\n\t\tlength--;\n\
    \t\tinteger /= 10;\n\t}\n\n\treturn length == 0;\n}\n\nstatic inline double stringToDouble(InStream\
    \ &in, const char *buffer) {\n\tdouble retval;\n\n\tsize_t length = strlen(buffer);\n\
    \n\tint minusCount = 0;\n\tint plusCount = 0;\n\tint decimalPointCount = 0;\n\t\
    int digitCount = 0;\n\tint eCount = 0;\n\n\tfor (size_t i = 0; i < length; i++)\
    \ {\n\t\tif (('0' <= buffer[i] && buffer[i] <= '9') || buffer[i] == '.'\n\t\t\t\
    || buffer[i] == 'e' || buffer[i] == 'E'\n\t\t\t|| buffer[i] == '-' || buffer[i]\
    \ == '+') {\n\t\t\tif ('0' <= buffer[i] && buffer[i] <= '9')\n\t\t\t\tdigitCount++;\n\
    \t\t\tif (buffer[i] == 'e' || buffer[i] == 'E')\n\t\t\t\teCount++;\n\t\t\tif (buffer[i]\
    \ == '-')\n\t\t\t\tminusCount++;\n\t\t\tif (buffer[i] == '+')\n\t\t\t\tplusCount++;\n\
    \t\t\tif (buffer[i] == '.')\n\t\t\t\tdecimalPointCount++;\n\t\t} else\n\t\t\t\
    in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\"\
    \ found\").c_str());\n\t}\n\n\t// If for sure is not a number in standard notation\
    \ or in e-notation.\n\tif (digitCount == 0 || minusCount > 2 || plusCount > 2\
    \ || decimalPointCount > 1 || eCount > 1)\n\t\tin.quit(_pe, (\"Expected double,\
    \ but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n\tchar *suffix\
    \ = new char[length + 1];\n\tint scanned = std::sscanf(buffer, \"%lf%s\", &retval,\
    \ suffix);\n\tbool empty = strlen(suffix) == 0;\n\tdelete[] suffix;\n\n\tif (scanned\
    \ == 1 || (scanned == 2 && empty)) {\n\t\tif (__testlib_isNaN(retval))\n\t\t\t\
    in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\"\
    \ found\").c_str());\n\t\treturn retval;\n\t} else\n\t\tin.quit(_pe, (\"Expected\
    \ double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n}\n\
    \nstatic inline double\nstringToStrictDouble(InStream &in, const char *buffer,\
    \ int minAfterPointDigitCount, int maxAfterPointDigitCount) {\n\tif (minAfterPointDigitCount\
    \ < 0)\n\t\tin.quit(_fail, \"stringToStrictDouble: minAfterPointDigitCount should\
    \ be non-negative.\");\n\n\tif (minAfterPointDigitCount > maxAfterPointDigitCount)\n\
    \t\tin.quit(_fail,\n\t\t\t\t\"stringToStrictDouble: minAfterPointDigitCount should\
    \ be less or equal to maxAfterPointDigitCount.\");\n\n\tdouble retval;\n\n\tsize_t\
    \ length = strlen(buffer);\n\n\tif (length == 0 || length > 1000)\n\t\tin.quit(_pe,\
    \ (\"Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n\tif (buffer[0] != '-' && (buffer[0] < '0' || buffer[0] > '9'))\n\
    \t\tin.quit(_pe, (\"Expected strict double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n\tint pointPos = -1;\n\tfor (size_t i = 1; i\
    \ + 1 < length; i++) {\n\t\tif (buffer[i] == '.') {\n\t\t\tif (pointPos > -1)\n\
    \t\t\t\tin.quit(_pe, (\"Expected strict double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\t\t\tpointPos = int(i);\n\t\t}\n\t\tif (buffer[i]\
    \ != '.' && (buffer[i] < '0' || buffer[i] > '9'))\n\t\t\tin.quit(_pe, (\"Expected\
    \ strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \t}\n\n\tif (buffer[length - 1] < '0' || buffer[length - 1] > '9')\n\t\tin.quit(_pe,\
    \ (\"Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n\tint afterDigitsCount = (pointPos == -1 ? 0 : int(length) - pointPos\
    \ - 1);\n\tif (afterDigitsCount < minAfterPointDigitCount || afterDigitsCount\
    \ > maxAfterPointDigitCount)\n\t\tin.quit(_pe, (\"Expected strict double with\
    \ number of digits after point in range [\"\n\t\t\t\t\t  + vtos(minAfterPointDigitCount)\n\
    \t\t\t\t\t  + \",\"\n\t\t\t\t\t  + vtos(maxAfterPointDigitCount)\n\t\t\t\t\t \
    \ + \"], but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str()\n\t\t);\n\
    \n\tint firstDigitPos = -1;\n\tfor (size_t i = 0; i < length; i++)\n\t\tif (buffer[i]\
    \ >= '0' && buffer[i] <= '9') {\n\t\t\tfirstDigitPos = int(i);\n\t\t\tbreak;\n\
    \t\t}\n\n\tif (firstDigitPos > 1 || firstDigitPos == -1)\n\t\tin.quit(_pe, (\"\
    Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \n\tif (buffer[firstDigitPos] == '0' && firstDigitPos + 1 < int(length)\n\t\t\
    && buffer[firstDigitPos + 1] >= '0' && buffer[firstDigitPos + 1] <= '9')\n\t\t\
    in.quit(_pe, (\"Expected strict double, but \\\"\" + __testlib_part(buffer) +\
    \ \"\\\" found\").c_str());\n\n\tchar *suffix = new char[length + 1];\n\tint scanned\
    \ = std::sscanf(buffer, \"%lf%s\", &retval, suffix);\n\tbool empty = strlen(suffix)\
    \ == 0;\n\tdelete[] suffix;\n\n\tif (scanned == 1 || (scanned == 2 && empty))\
    \ {\n\t\tif (__testlib_isNaN(retval) || __testlib_isInfinite(retval))\n\t\t\t\
    in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\"\
    \ found\").c_str());\n\t\tif (buffer[0] == '-' && retval >= 0)\n\t\t\tin.quit(_pe,\
    \ (\"Redundant minus in \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \t\treturn retval;\n\t} else\n\t\tin.quit(_pe, (\"Expected double, but \\\"\"\
    \ + __testlib_part(buffer) + \"\\\" found\").c_str());\n}\n\nstatic inline long\
    \ long stringToLongLong(InStream &in, const char *buffer) {\n\tif (strcmp(buffer,\
    \ \"-9223372036854775808\") == 0)\n\t\treturn LLONG_MIN;\n\n\tbool minus = false;\n\
    \tsize_t length = strlen(buffer);\n\n\tif (length > 1 && buffer[0] == '-')\n\t\
    \tminus = true;\n\n\tif (length > 20)\n\t\tin.quit(_pe, (\"Expected integer, but\
    \ \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n\tlong long retval\
    \ = 0LL;\n\n\tint zeroes = 0;\n\tint processingZeroes = true;\n\n\tfor (int i\
    \ = (minus ? 1 : 0); i < int(length); i++) {\n\t\tif (buffer[i] == '0' && processingZeroes)\n\
    \t\t\tzeroes++;\n\t\telse\n\t\t\tprocessingZeroes = false;\n\n\t\tif (buffer[i]\
    \ < '0' || buffer[i] > '9')\n\t\t\tin.quit(_pe, (\"Expected integer, but \\\"\"\
    \ + __testlib_part(buffer) + \"\\\" found\").c_str());\n\t\tretval = retval *\
    \ 10 + (buffer[i] - '0');\n\t}\n\n\tif (retval < 0)\n\t\tin.quit(_pe, (\"Expected\
    \ integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n\
    \tif ((zeroes > 0 && (retval != 0 || minus)) || zeroes > 1)\n\t\tin.quit(_pe,\
    \ (\"Expected integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \n\tretval = (minus ? -retval : +retval);\n\n\tif (length < 19)\n\t\treturn retval;\n\
    \n\tif (equals(retval, buffer))\n\t\treturn retval;\n\telse\n\t\tin.quit(_pe,\
    \ (\"Expected int64, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    }\n\nstatic inline unsigned long long stringToUnsignedLongLong(InStream &in, const\
    \ char *buffer) {\n\tsize_t length = strlen(buffer);\n\n\tif (length > 20)\n\t\
    \tin.quit(_pe, (\"Expected unsigned integer, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\tif (length > 1 && buffer[0] == '0')\n\t\tin.quit(_pe,\
    \ (\"Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n\tunsigned long long retval = 0LL;\n\tfor (int i = 0; i < int(length);\
    \ i++) {\n\t\tif (buffer[i] < '0' || buffer[i] > '9')\n\t\t\tin.quit(_pe, (\"\
    Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\t\tretval = retval * 10 + (buffer[i] - '0');\n\t}\n\n\tif (length\
    \ < 19)\n\t\treturn retval;\n\n\tif (length == 20 && strcmp(buffer, \"18446744073709551615\"\
    ) == 1)\n\t\tin.quit(_pe, (\"Expected unsigned int64, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n\tif (equals(retval, buffer))\n\t\treturn retval;\n\
    \telse\n\t\tin.quit(_pe, (\"Expected unsigned int64, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n}\n\nint InStream::readInteger() {\n\tif (!strict\
    \ && seekEof())\n\t\tquit(_unexpected_eof, \"Unexpected end of file - int32 expected\"\
    );\n\n\treadWordTo(_tmpReadToken);\n\n\tlong long value = stringToLongLong(*this,\
    \ _tmpReadToken.c_str());\n\tif (value < INT_MIN || value > INT_MAX)\n\t\tquit(_pe,\
    \ (\"Expected int32, but \\\"\" + __testlib_part(_tmpReadToken) + \"\\\" found\"\
    ).c_str());\n\n\treturn int(value);\n}\n\nlong long InStream::readLong() {\n\t\
    if (!strict && seekEof())\n\t\tquit(_unexpected_eof, \"Unexpected end of file\
    \ - int64 expected\");\n\n\treadWordTo(_tmpReadToken);\n\n\treturn stringToLongLong(*this,\
    \ _tmpReadToken.c_str());\n}\n\nunsigned long long InStream::readUnsignedLong()\
    \ {\n\tif (!strict && seekEof())\n\t\tquit(_unexpected_eof, \"Unexpected end of\
    \ file - int64 expected\");\n\n\treadWordTo(_tmpReadToken);\n\n\treturn stringToUnsignedLongLong(*this,\
    \ _tmpReadToken.c_str());\n}\n\nlong long InStream::readLong(long long minv, long\
    \ long maxv, const std::string &variableName) {\n\tlong long result = readLong();\n\
    \n\tif (result < minv || result > maxv) {\n\t\tif (readManyIteration == NO_INDEX)\
    \ {\n\t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa, (\"Integer \" + vtos(result)\
    \ + \" violates the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa, (\"Integer\
    \ parameter [name=\" + std::string(variableName) + \"] equals to \" + vtos(result)\
    \ +\n\t\t\t\t\t\t   \", violates the range [\" + toHumanReadableString(minv) +\
    \ \", \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t} else {\n\t\t\t\
    if (variableName.empty())\n\t\t\t\tquit(_wa, (\"Integer element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\"\
    \ + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv) + \"]\"\
    ).c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Integer element \" +\
    \ std::string(variableName) + \"[\" + vtos(readManyIteration) + \"] equals to\
    \ \" +\n\t\t\t\t\t  vtos(result) + \", violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t}\n\t}\n\n\t\
    if (strict && !variableName.empty())\n\t\tvalidator.addBoundsHit(variableName,\
    \ ValidatorBoundsHit(minv == result, maxv == result));\n\n\treturn result;\n}\n\
    \nstd::vector<long long>\nInStream::readLongs(int size, long long minv, long long\
    \ maxv, const std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readLongs,\
    \ readLong(minv, maxv, variablesName), long long, true)\n}\n\nstd::vector<long\
    \ long> InStream::readLongs(int size, int indexBase) {\n\t__testlib_readMany(readLongs,\
    \ readLong(), long long, true)\n}\n\nunsigned long long\nInStream::readUnsignedLong(unsigned\
    \ long long minv, unsigned long long maxv, const std::string &variableName) {\n\
    \tunsigned long long result = readUnsignedLong();\n\n\tif (result < minv || result\
    \ > maxv) {\n\t\tif (readManyIteration == NO_INDEX) {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Unsigned integer \" + vtos(result) + \" violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ +\n\t\t\t\t\t  \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"\
    Unsigned integer parameter [name=\" + std::string(variableName) + \"] equals to\
    \ \" + vtos(result) +\n\t\t\t\t\t  \", violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t} else {\n\t\t\
    \tif (variableName.empty())\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Unsigned integer\
    \ element [index=\" + vtos(readManyIteration) + \"] equals to \" + vtos(result)\
    \ +\n\t\t\t\t\t  \", violates the range [\" + toHumanReadableString(minv) + \"\
    , \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\
    \ (\"Unsigned integer element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ +\n\t\t\t\t\t\t   \"] equals to \" + vtos(result) + \", violates the range [\"\
    \ + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv) +\n\t\t\
    \t\t\t\t   \"]\").c_str());\n\t\t}\n\t}\n\n\tif (strict && !variableName.empty())\n\
    \t\tvalidator.addBoundsHit(variableName, ValidatorBoundsHit(minv == result, maxv\
    \ == result));\n\n\treturn result;\n}\n\nstd::vector<unsigned long long> InStream::readUnsignedLongs(int\
    \ size, unsigned long long minv, unsigned long long maxv,\n\t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\tconst std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readUnsignedLongs,\
    \ readUnsignedLong(minv, maxv, variablesName), unsigned long long, true)\n}\n\n\
    std::vector<unsigned long long> InStream::readUnsignedLongs(int size, int indexBase)\
    \ {\n\t__testlib_readMany(readUnsignedLongs, readUnsignedLong(), unsigned long\
    \ long, true)\n}\n\nunsigned long long\nInStream::readLong(unsigned long long\
    \ minv, unsigned long long maxv, const std::string &variableName) {\n\treturn\
    \ readUnsignedLong(minv, maxv, variableName);\n}\n\nint InStream::readInt() {\n\
    \treturn readInteger();\n}\n\nint InStream::readInt(int minv, int maxv, const\
    \ std::string &variableName) {\n\tint result = readInt();\n\n\tif (result < minv\
    \ || result > maxv) {\n\t\tif (readManyIteration == NO_INDEX) {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa, (\"Integer \" + vtos(result) + \" violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\
    \t\telse\n\t\t\t\tquit(_wa, (\"Integer parameter [name=\" + std::string(variableName)\
    \ + \"] equals to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\"\
    \ + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv) + \"]\"\
    ).c_str());\n\t\t} else {\n\t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa,\
    \ (\"Integer element [index=\" + vtos(readManyIteration) + \"] equals to \" +\
    \ vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t\telse\n\t\t\t\
    \tquit(_wa,\n\t\t\t\t\t (\"Integer element \" + std::string(variableName) + \"\
    [\" + vtos(readManyIteration) + \"] equals to \" +\n\t\t\t\t\t  vtos(result) +\
    \ \", violates the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n\t\t}\n\t}\n\n\tif (strict && !variableName.empty())\n\t\
    \tvalidator.addBoundsHit(variableName, ValidatorBoundsHit(minv == result, maxv\
    \ == result));\n\n\treturn result;\n}\n\nint InStream::readInteger(int minv, int\
    \ maxv, const std::string &variableName) {\n\treturn readInt(minv, maxv, variableName);\n\
    }\n\nstd::vector<int> InStream::readInts(int size, int minv, int maxv, const std::string\
    \ &variablesName, int indexBase) {\n\t__testlib_readMany(readInts, readInt(minv,\
    \ maxv, variablesName), int, true)\n}\n\nstd::vector<int> InStream::readInts(int\
    \ size, int indexBase) {\n\t__testlib_readMany(readInts, readInt(), int, true)\n\
    }\n\nstd::vector<int> InStream::readIntegers(int size, int minv, int maxv, const\
    \ std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readIntegers,\
    \ readInt(minv, maxv, variablesName), int, true)\n}\n\nstd::vector<int> InStream::readIntegers(int\
    \ size, int indexBase) {\n\t__testlib_readMany(readIntegers, readInt(), int, true)\n\
    }\n\ndouble InStream::readReal() {\n\tif (!strict && seekEof())\n\t\tquit(_unexpected_eof,\
    \ \"Unexpected end of file - double expected\");\n\n\treturn stringToDouble(*this,\
    \ readWord().c_str());\n}\n\ndouble InStream::readDouble() {\n\treturn readReal();\n\
    }\n\ndouble InStream::readReal(double minv, double maxv, const std::string &variableName)\
    \ {\n\tdouble result = readReal();\n\n\tif (result < minv || result > maxv) {\n\
    \t\tif (readManyIteration == NO_INDEX) {\n\t\t\tif (variableName.empty())\n\t\t\
    \t\tquit(_wa, (\"Double \" + vtos(result) + \" violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\t\telse\n\t\t\t\
    \tquit(_wa, (\"Double parameter [name=\" + std::string(variableName) + \"] equals\
    \ to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t} else {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa, (\"Double element [index=\" + vtos(readManyIteration) + \"]\
    \ equals to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\
    \t\t\t (\"Double element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ + \"] equals to \" +\n\t\t\t\t\t  vtos(result) + \", violates the range [\"\
    \ + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t}\n\t}\n\n\tif (strict\
    \ && !variableName.empty())\n\t\tvalidator.addBoundsHit(variableName, ValidatorBoundsHit(\n\
    \t\t\t\tdoubleDelta(minv, result) < ValidatorBoundsHit::EPS,\n\t\t\t\tdoubleDelta(maxv,\
    \ result) < ValidatorBoundsHit::EPS\n\t\t));\n\n\treturn result;\n}\n\nstd::vector<double>\n\
    InStream::readReals(int size, double minv, double maxv, const std::string &variablesName,\
    \ int indexBase) {\n\t__testlib_readMany(readReals, readReal(minv, maxv, variablesName),\
    \ double, true)\n}\n\nstd::vector<double> InStream::readReals(int size, int indexBase)\
    \ {\n\t__testlib_readMany(readReals, readReal(), double, true)\n}\n\ndouble InStream::readDouble(double\
    \ minv, double maxv, const std::string &variableName) {\n\treturn readReal(minv,\
    \ maxv, variableName);\n}\n\nstd::vector<double>\nInStream::readDoubles(int size,\
    \ double minv, double maxv, const std::string &variablesName, int indexBase) {\n\
    \t__testlib_readMany(readDoubles, readDouble(minv, maxv, variablesName), double,\
    \ true)\n}\n\nstd::vector<double> InStream::readDoubles(int size, int indexBase)\
    \ {\n\t__testlib_readMany(readDoubles, readDouble(), double, true)\n}\n\ndouble\
    \ InStream::readStrictReal(double minv, double maxv,\n\t\t\t\t\t\t\t\tint minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\tconst std::string &variableName)\
    \ {\n\tif (!strict && seekEof())\n\t\tquit(_unexpected_eof, \"Unexpected end of\
    \ file - strict double expected\");\n\n\tdouble result = stringToStrictDouble(*this,\
    \ readWord().c_str(),\n\t\t\t\t\t\t\t\t\t\t minAfterPointDigitCount, maxAfterPointDigitCount);\n\
    \n\tif (result < minv || result > maxv) {\n\t\tif (readManyIteration == NO_INDEX)\
    \ {\n\t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa, (\"Strict double \" +\
    \ vtos(result) + \" violates the range [\" + vtos(minv) + \", \" + vtos(maxv)\
    \ +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\t\t\t\
    \ (\"Strict double parameter [name=\" + std::string(variableName) + \"] equals\
    \ to \" + vtos(result) +\n\t\t\t\t\t  \", violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t} else {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa, (\"Strict double element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\"\
    \ + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t\telse\n\t\t\t\t\
    quit(_wa, (\"Strict double element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ +\n\t\t\t\t\t\t   \"] equals to \" + vtos(result) + \", violates the range [\"\
    \ + vtos(minv) + \", \" + vtos(maxv) +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\t\
    }\n\t}\n\n\tif (strict && !variableName.empty())\n\t\tvalidator.addBoundsHit(variableName,\
    \ ValidatorBoundsHit(\n\t\t\t\tdoubleDelta(minv, result) < ValidatorBoundsHit::EPS,\n\
    \t\t\t\tdoubleDelta(maxv, result) < ValidatorBoundsHit::EPS\n\t\t));\n\n\treturn\
    \ result;\n}\n\nstd::vector<double> InStream::readStrictReals(int size, double\
    \ minv, double maxv,\n\t\t\t\t\t\t\t\t\t\t\t  int minAfterPointDigitCount, int\
    \ maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\t\t\t\t  const std::string &variablesName,\
    \ int indexBase) {\n\t__testlib_readMany(readStrictReals,\n\t\t\t\t\t   readStrictReal(minv,\
    \ maxv, minAfterPointDigitCount, maxAfterPointDigitCount, variablesName),\n\t\t\
    \t\t\t   double, true)\n}\n\ndouble InStream::readStrictDouble(double minv, double\
    \ maxv,\n\t\t\t\t\t\t\t\t  int minAfterPointDigitCount, int maxAfterPointDigitCount,\n\
    \t\t\t\t\t\t\t\t  const std::string &variableName) {\n\treturn readStrictReal(minv,\
    \ maxv,\n\t\t\t\t\t\t  minAfterPointDigitCount, maxAfterPointDigitCount,\n\t\t\
    \t\t\t\t  variableName);\n}\n\nstd::vector<double> InStream::readStrictDoubles(int\
    \ size, double minv, double maxv,\n\t\t\t\t\t\t\t\t\t\t\t\tint minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\t\t\t\t\tconst std::string &variablesName,\
    \ int indexBase) {\n\t__testlib_readMany(readStrictDoubles,\n\t\t\t\t\t   readStrictDouble(minv,\
    \ maxv, minAfterPointDigitCount, maxAfterPointDigitCount, variablesName),\n\t\t\
    \t\t\t   double, true)\n}\n\nbool InStream::eof() {\n\tif (!strict && NULL ==\
    \ reader)\n\t\treturn true;\n\n\treturn reader->eof();\n}\n\nbool InStream::seekEof()\
    \ {\n\tif (!strict && NULL == reader)\n\t\treturn true;\n\tskipBlanks();\n\treturn\
    \ eof();\n}\n\nbool InStream::eoln() {\n\tif (!strict && NULL == reader)\n\t\t\
    return true;\n\n\tint c = reader->nextChar();\n\n\tif (!strict) {\n\t\tif (c ==\
    \ EOFC)\n\t\t\treturn true;\n\n\t\tif (c == CR) {\n\t\t\tc = reader->nextChar();\n\
    \n\t\t\tif (c != LF) {\n\t\t\t\treader->unreadChar(c);\n\t\t\t\treader->unreadChar(CR);\n\
    \t\t\t\treturn false;\n\t\t\t} else\n\t\t\t\treturn true;\n\t\t}\n\n\t\tif (c\
    \ == LF)\n\t\t\treturn true;\n\n\t\treader->unreadChar(c);\n\t\treturn false;\n\
    \t} else {\n\t\tbool returnCr = false;\n\n#if (defined(ON_WINDOWS) && !defined(FOR_LINUX))\
    \ || defined(FOR_WINDOWS)\n\t\tif (c != CR) {\n\t\t\treader->unreadChar(c);\n\t\
    \t\treturn false;\n\t\t} else {\n\t\t\tif (!returnCr)\n\t\t\t\treturnCr = true;\n\
    \t\t\tc = reader->nextChar();\n\t\t}\n#endif\n\t\tif (c != LF) {\n\t\t\treader->unreadChar(c);\n\
    \t\t\tif (returnCr)\n\t\t\t\treader->unreadChar(CR);\n\t\t\treturn false;\n\t\t\
    }\n\n\t\treturn true;\n\t}\n}\n\nvoid InStream::readEoln() {\n\tlastLine = reader->getLine();\n\
    \tif (!eoln())\n\t\tquit(_pe, \"Expected EOLN\");\n}\n\nvoid InStream::readEof()\
    \ {\n\tlastLine = reader->getLine();\n\tif (!eof())\n\t\tquit(_pe, \"Expected\
    \ EOF\");\n\n\tif (TestlibFinalizeGuard::alive && this == &inf)\n\t\ttestlibFinalizeGuard.readEofCount++;\n\
    }\n\nbool InStream::seekEoln() {\n\tif (!strict && NULL == reader)\n\t\treturn\
    \ true;\n\n\tint cur;\n\tdo {\n\t\tcur = reader->nextChar();\n\t} while (cur ==\
    \ SPACE || cur == TAB);\n\n\treader->unreadChar(cur);\n\treturn eoln();\n}\n\n\
    void InStream::nextLine() {\n\treadLine();\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result) {\n\tif (NULL == reader)\n\t\tquit(_pe, \"Expected line\");\n\n\tresult.clear();\n\
    \n\tfor (;;) {\n\t\tint cur = reader->curChar();\n\n\t\tif (cur == LF || cur ==\
    \ EOFC)\n\t\t\tbreak;\n\n\t\tif (cur == CR) {\n\t\t\tcur = reader->nextChar();\n\
    \t\t\tif (reader->curChar() == LF) {\n\t\t\t\treader->unreadChar(cur);\n\t\t\t\
    \tbreak;\n\t\t\t}\n\t\t}\n\n\t\tlastLine = reader->getLine();\n\t\tresult += char(reader->nextChar());\n\
    \t}\n\n\tif (strict)\n\t\treadEoln();\n\telse\n\t\teoln();\n}\n\nstd::string InStream::readString()\
    \ {\n\treadStringTo(_tmpReadToken);\n\treturn _tmpReadToken;\n}\n\nstd::vector<std::string>\
    \ InStream::readStrings(int size, int indexBase) {\n\t__testlib_readMany(readStrings,\
    \ readString(), std::string, false)\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result, const pattern &p, const std::string &variableName) {\n\treadStringTo(result);\n\
    \tif (!p.matches(result)) {\n\t\tif (readManyIteration == NO_INDEX) {\n\t\t\t\
    if (variableName.empty())\n\t\t\t\tquit(_wa, (\"Line \\\"\" + __testlib_part(result)\
    \ + \"\\\" doesn't correspond to pattern \\\"\" + p.src() +\n\t\t\t\t\t\t   \"\
    \\\"\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa, (\"Line [name=\" + variableName\
    \ + \"] equals to \\\"\" + __testlib_part(result) +\n\t\t\t\t\t\t   \"\\\", doesn't\
    \ correspond to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n\t\t} else {\n\
    \t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Line element\
    \ [index=\" + vtos(readManyIteration) + \"] equals to \\\"\" + __testlib_part(result)\
    \ +\n\t\t\t\t\t  \"\\\" doesn't correspond to pattern \\\"\" + p.src() + \"\\\"\
    \").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Line element \" +\
    \ std::string(variableName) + \"[\" + vtos(readManyIteration) + \"] equals to\
    \ \\\"\" +\n\t\t\t\t\t  __testlib_part(result) + \"\\\", doesn't correspond to\
    \ pattern \\\"\" + p.src() + \"\\\"\").c_str());\n\t\t}\n\t}\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName) {\n\treadStringTo(result,\
    \ pattern(ptrn), variableName);\n}\n\nstd::string InStream::readString(const pattern\
    \ &p, const std::string &variableName) {\n\treadStringTo(_tmpReadToken, p, variableName);\n\
    \treturn _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readStrings(int\
    \ size, const pattern &p, const std::string &variablesName, int indexBase) {\n\
    \t__testlib_readMany(readStrings, readString(p, variablesName), std::string, false)\n\
    }\n\nstd::string InStream::readString(const std::string &ptrn, const std::string\
    \ &variableName) {\n\treadStringTo(_tmpReadToken, ptrn, variableName);\n\treturn\
    \ _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readStrings(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \tpattern p(ptrn);\n\t__testlib_readMany(readStrings, readString(p, variablesName),\
    \ std::string, false)\n}\n\nvoid InStream::readLineTo(std::string &result) {\n\
    \treadStringTo(result);\n}\n\nstd::string InStream::readLine() {\n\treturn readString();\n\
    }\n\nstd::vector<std::string> InStream::readLines(int size, int indexBase) {\n\
    \t__testlib_readMany(readLines, readString(), std::string, false)\n}\n\nvoid InStream::readLineTo(std::string\
    \ &result, const pattern &p, const std::string &variableName) {\n\treadStringTo(result,\
    \ p, variableName);\n}\n\nvoid InStream::readLineTo(std::string &result, const\
    \ std::string &ptrn, const std::string &variableName) {\n\treadStringTo(result,\
    \ ptrn, variableName);\n}\n\nstd::string InStream::readLine(const pattern &p,\
    \ const std::string &variableName) {\n\treturn readString(p, variableName);\n\
    }\n\nstd::vector<std::string>\nInStream::readLines(int size, const pattern &p,\
    \ const std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readLines,\
    \ readString(p, variablesName), std::string, false)\n}\n\nstd::string InStream::readLine(const\
    \ std::string &ptrn, const std::string &variableName) {\n\treturn readString(ptrn,\
    \ variableName);\n}\n\nstd::vector<std::string>\nInStream::readLines(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \tpattern p(ptrn);\n\t__testlib_readMany(readLines, readString(p, variablesName),\
    \ std::string, false)\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 3,\
    \ 4)))\n#endif\nvoid InStream::ensuref(bool cond, const char *format, ...) {\n\
    \tif (!cond) {\n\t\tFMT_TO_RESULT(format, format, message);\n\t\tthis->__testlib_ensure(cond,\
    \ message);\n\t}\n}\n\nvoid InStream::__testlib_ensure(bool cond, std::string\
    \ message) {\n\tif (!cond)\n\t\tthis->quit(_wa, message.c_str());\n}\n\nvoid InStream::close()\
    \ {\n\tif (NULL != reader) {\n\t\treader->close();\n\t\tdelete reader;\n\t\treader\
    \ = NULL;\n\t}\n\n\topened = false;\n}\n\nNORETURN void quit(TResult result, const\
    \ std::string &msg) {\n\touf.quit(result, msg.c_str());\n}\n\nNORETURN void quit(TResult\
    \ result, const char *msg) {\n\touf.quit(result, msg);\n}\n\nNORETURN void __testlib_quitp(double\
    \ points, const char *message) {\n\t__testlib_points = points;\n\tstd::string\
    \ stringPoints = removeDoubleTrailingZeroes(format(\"%.10f\", points));\n\n\t\
    std::string quitMessage;\n\tif (NULL == message || 0 == strlen(message))\n\t\t\
    quitMessage = stringPoints;\n\telse\n\t\tquitMessage = stringPoints + \" \" +\
    \ message;\n\n\tquit(_points, quitMessage.c_str());\n}\n\nNORETURN void __testlib_quitp(int\
    \ points, const char *message) {\n\t__testlib_points = points;\n\tstd::string\
    \ stringPoints = format(\"%d\", points);\n\n\tstd::string quitMessage;\n\tif (NULL\
    \ == message || 0 == strlen(message))\n\t\tquitMessage = stringPoints;\n\telse\n\
    \t\tquitMessage = stringPoints + \" \" + message;\n\n\tquit(_points, quitMessage.c_str());\n\
    }\n\nNORETURN void quitp(float points, const std::string &message = \"\") {\n\t\
    __testlib_quitp(double(points), message.c_str());\n}\n\nNORETURN void quitp(double\
    \ points, const std::string &message = \"\") {\n\t__testlib_quitp(points, message.c_str());\n\
    }\n\nNORETURN void quitp(long double points, const std::string &message = \"\"\
    ) {\n\t__testlib_quitp(double(points), message.c_str());\n}\n\nNORETURN void quitp(int\
    \ points, const std::string &message = \"\") {\n\t__testlib_quitp(points, message.c_str());\n\
    }\n\ntemplate<typename F>\n#ifdef __GNUC__\n__attribute__ ((format (printf, 2,\
    \ 3)))\n#endif\nNORETURN void quitp(F points, const char *format, ...) {\n\tFMT_TO_RESULT(format,\
    \ format, message);\n\tquitp(points, message);\n}\n\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 2, 3)))\n#endif\nNORETURN void quitf(TResult result, const\
    \ char *format, ...) {\n\tFMT_TO_RESULT(format, format, message);\n\tquit(result,\
    \ message);\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 3, 4)))\n#endif\n\
    void quitif(bool condition, TResult result, const char *format, ...) {\n\tif (condition)\
    \ {\n\t\tFMT_TO_RESULT(format, format, message);\n\t\tquit(result, message);\n\
    \t}\n}\n\nNORETURN void __testlib_help() {\n\tInStream::textColor(InStream::LightCyan);\n\
    \tstd::fprintf(stderr, \"TESTLIB %s, https://github.com/MikeMirzayanov/testlib/\
    \ \", VERSION);\n\tstd::fprintf(stderr, \"by Mike Mirzayanov, copyright(c) 2005-2020\\\
    n\");\n\tstd::fprintf(stderr, \"Checker name: \\\"%s\\\"\\n\", checkerName.c_str());\n\
    \tInStream::textColor(InStream::LightGray);\n\n\tstd::fprintf(stderr, \"\\n\"\
    );\n\tstd::fprintf(stderr, \"Latest features: \\n\");\n\tfor (size_t i = 0; i\
    \ < sizeof(latestFeatures) / sizeof(char *); i++) {\n\t\tstd::fprintf(stderr,\
    \ \"*) %s\\n\", latestFeatures[i]);\n\t}\n\tstd::fprintf(stderr, \"\\n\");\n\n\
    \tstd::fprintf(stderr, \"Program must be run with the following arguments: \\\
    n\");\n\tstd::fprintf(stderr, \"\t<input-file> <output-file> <answer-file> [<report-file>\
    \ [<-appes>]]\\n\\n\");\n\n\tstd::exit(FAIL_EXIT_CODE);\n}\n\nstatic void __testlib_ensuresPreconditions()\
    \ {\n\t// testlib assumes: sizeof(int) = 4.\n\t__TESTLIB_STATIC_ASSERT(sizeof(int)\
    \ == 4);\n\n\t// testlib assumes: INT_MAX == 2147483647.\n\t__TESTLIB_STATIC_ASSERT(INT_MAX\
    \ == 2147483647);\n\n\t// testlib assumes: sizeof(long long) = 8.\n\t__TESTLIB_STATIC_ASSERT(sizeof(long\
    \ long) == 8);\n\n\t// testlib assumes: sizeof(double) = 8.\n\t__TESTLIB_STATIC_ASSERT(sizeof(double)\
    \ == 8);\n\n\t// testlib assumes: no -ffast-math.\n\tif (!__testlib_isNaN(+__testlib_nan()))\n\
    \t\tquit(_fail, \"Function __testlib_isNaN is not working correctly: possible\
    \ reason is '-ffast-math'\");\n\tif (!__testlib_isNaN(-__testlib_nan()))\n\t\t\
    quit(_fail, \"Function __testlib_isNaN is not working correctly: possible reason\
    \ is '-ffast-math'\");\n}\n\nvoid registerGen(int argc, char *argv[], int randomGeneratorVersion)\
    \ {\n\tif (randomGeneratorVersion < 0 || randomGeneratorVersion > 1)\n\t\tquitf(_fail,\
    \ \"Random generator version is expected to be 0 or 1.\");\n\trandom_t::version\
    \ = randomGeneratorVersion;\n\n\t__testlib_ensuresPreconditions();\n\n\ttestlibMode\
    \ = _generator;\n\t__testlib_set_binary(stdin);\n\trnd.setSeed(argc, argv);\n\n\
    #if __cplusplus > 199711L || defined(_MSC_VER)\n\tprepareOpts(argc, argv);\n#endif\n\
    }\n\n#ifdef USE_RND_AS_BEFORE_087\nvoid registerGen(int argc, char* argv[])\n\
    {\n\tregisterGen(argc, argv, 0);\n}\n#else\n#ifdef __GNUC__\n#if (__GNUC__ > 4)\
    \ || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 4))\n__attribute__ ((deprecated(\"\
    Use registerGen(argc, argv, 0) or registerGen(argc, argv, 1).\"\n\" The third\
    \ parameter stands for the random generator version.\"\n\" If you are trying to\
    \ compile old generator use macro -DUSE_RND_AS_BEFORE_087 or registerGen(argc,\
    \ argv, 0).\"\n\" Version 1 has been released on Spring, 2013. Use it to write\
    \ new generators.\")))\n#else\n__attribute__ ((deprecated))\n#endif\n#endif\n\
    #ifdef _MSC_VER\n__declspec(deprecated(\"Use registerGen(argc, argv, 0) or registerGen(argc,\
    \ argv, 1).\"\n\t\t\" The third parameter stands for the random generator version.\"\
    \n\t\t\" If you are trying to compile old generator use macro -DUSE_RND_AS_BEFORE_087\
    \ or registerGen(argc, argv, 0).\"\n\t\t\" Version 1 has been released on Spring,\
    \ 2013. Use it to write new generators.\"))\n#endif\nvoid registerGen(int argc,\
    \ char *argv[]) {\n\tstd::fprintf(stderr, \"Use registerGen(argc, argv, 0) or\
    \ registerGen(argc, argv, 1).\"\n\t\t\t\t\t\t \" The third parameter stands for\
    \ the random generator version.\"\n\t\t\t\t\t\t \" If you are trying to compile\
    \ old generator use macro -DUSE_RND_AS_BEFORE_087 or registerGen(argc, argv, 0).\"\
    \n\t\t\t\t\t\t \" Version 1 has been released on Spring, 2013. Use it to write\
    \ new generators.\\n\\n\");\n\tregisterGen(argc, argv, 0);\n}\n#endif\n\nvoid\
    \ registerInteraction(int argc, char *argv[]) {\n\t__testlib_ensuresPreconditions();\n\
    \n\ttestlibMode = _interactor;\n\t__testlib_set_binary(stdin);\n\n\tif (argc >\
    \ 1 && !strcmp(\"--help\", argv[1]))\n\t\t__testlib_help();\n\n\tif (argc < 3\
    \ || argc > 6) {\n\t\tquit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n\t\t\t\t\tstd::string(\"<input-file> <output-file> [<answer-file>\
    \ [<report-file> [<-appes>]]]\") +\n\t\t\t\t\t\"\\nUse \\\"--help\\\" to get help\
    \ information\");\n\t}\n\n\tif (argc <= 4) {\n\t\tresultName = \"\";\n\t\tappesMode\
    \ = false;\n\t}\n\n#ifndef EJUDGE\n\tif (argc == 5) {\n\t\tresultName = argv[4];\n\
    \t\tappesMode = false;\n\t}\n\n\tif (argc == 6) {\n\t\tif (strcmp(\"-APPES\",\
    \ argv[5]) && strcmp(\"-appes\", argv[5])) {\n\t\t\tquit(_fail, std::string(\"\
    Program must be run with the following arguments: \") +\n\t\t\t\t\t\t\"<input-file>\
    \ <output-file> <answer-file> [<report-file> [<-appes>]]\");\n\t\t} else {\n\t\
    \t\tresultName = argv[4];\n\t\t\tappesMode = true;\n\t\t}\n\t}\n#endif\n\n\tinf.init(argv[1],\
    \ _input);\n\n\ttout.open(argv[2], std::ios_base::out);\n\tif (tout.fail() ||\
    \ !tout.is_open())\n\t\tquit(_fail, std::string(\"Can not write to the test-output-file\
    \ '\") + argv[2] + std::string(\"'\"));\n\n\touf.init(stdin, _output);\n\n\tif\
    \ (argc >= 4)\n\t\tans.init(argv[3], _answer);\n\telse\n\t\tans.name = \"unopened\
    \ answer stream\";\n}\n\nvoid registerValidation() {\n\t__testlib_ensuresPreconditions();\n\
    \n\ttestlibMode = _validator;\n\t__testlib_set_binary(stdin);\n\n\tinf.init(stdin,\
    \ _input);\n\tinf.strict = true;\n}\n\nvoid registerValidation(int argc, char\
    \ *argv[]) {\n\tregisterValidation();\n\tvalidator.initialize();\n\n\tfor (int\
    \ i = 1; i < argc; i++) {\n\t\tif (!strcmp(\"--testset\", argv[i])) {\n\t\t\t\
    if (i + 1 < argc && strlen(argv[i + 1]) > 0)\n\t\t\t\tvalidator.setTestset(argv[++i]);\n\
    \t\t\telse\n\t\t\t\tquit(_fail, std::string(\"Validator must be run with the following\
    \ arguments: \") +\n\t\t\t\t\t\t\t\"[--testset testset] [--group group] [--testOverviewLogFileName\
    \ fileName]\");\n\t\t}\n\t\tif (!strcmp(\"--group\", argv[i])) {\n\t\t\tif (i\
    \ + 1 < argc)\n\t\t\t\tvalidator.setGroup(argv[++i]);\n\t\t\telse\n\t\t\t\tquit(_fail,\
    \ std::string(\"Validator must be run with the following arguments: \") +\n\t\t\
    \t\t\t\t\t\"[--testset testset] [--group group] [--testOverviewLogFileName fileName]\"\
    );\n\t\t}\n\t\tif (!strcmp(\"--testOverviewLogFileName\", argv[i])) {\n\t\t\t\
    if (i + 1 < argc)\n\t\t\t\tvalidator.setTestOverviewLogFileName(argv[++i]);\n\t\
    \t\telse\n\t\t\t\tquit(_fail, std::string(\"Validator must be run with the following\
    \ arguments: \") +\n\t\t\t\t\t\t\t\"[--testset testset] [--group group] [--testOverviewLogFileName\
    \ fileName]\");\n\t\t}\n\t}\n}\n\nvoid addFeature(const std::string &feature)\
    \ {\n\tif (testlibMode != _validator)\n\t\tquit(_fail, \"Features are supported\
    \ in validators only.\");\n\tvalidator.addFeature(feature);\n}\n\nvoid feature(const\
    \ std::string &feature) {\n\tif (testlibMode != _validator)\n\t\tquit(_fail, \"\
    Features are supported in validators only.\");\n\tvalidator.feature(feature);\n\
    }\n\nvoid registerTestlibCmd(int argc, char *argv[]) {\n\t__testlib_ensuresPreconditions();\n\
    \n\ttestlibMode = _checker;\n\t__testlib_set_binary(stdin);\n\n\tif (argc > 1\
    \ && !strcmp(\"--help\", argv[1]))\n\t\t__testlib_help();\n\n\tif (argc < 4 ||\
    \ argc > 6) {\n\t\tquit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n\t\t\t\t\tstd::string(\"<input-file> <output-file> <answer-file>\
    \ [<report-file> [<-appes>]]\") +\n\t\t\t\t\t\"\\nUse \\\"--help\\\" to get help\
    \ information\");\n\t}\n\n\tif (argc == 4) {\n\t\tresultName = \"\";\n\t\tappesMode\
    \ = false;\n\t}\n\n\tif (argc == 5) {\n\t\tresultName = argv[4];\n\t\tappesMode\
    \ = false;\n\t}\n\n\tif (argc == 6) {\n\t\tif (strcmp(\"-APPES\", argv[5]) &&\
    \ strcmp(\"-appes\", argv[5])) {\n\t\t\tquit(_fail, std::string(\"Program must\
    \ be run with the following arguments: \") +\n\t\t\t\t\t\t\"<input-file> <output-file>\
    \ <answer-file> [<report-file> [<-appes>]]\");\n\t\t} else {\n\t\t\tresultName\
    \ = argv[4];\n\t\t\tappesMode = true;\n\t\t}\n\t}\n\n\tinf.init(argv[1], _input);\n\
    \touf.init(argv[2], _output);\n\tans.init(argv[3], _answer);\n}\n\nvoid registerTestlib(int\
    \ argc, ...) {\n\tif (argc < 3 || argc > 5)\n\t\tquit(_fail, std::string(\"Program\
    \ must be run with the following arguments: \") +\n\t\t\t\t\t\"<input-file> <output-file>\
    \ <answer-file> [<report-file> [<-appes>]]\");\n\n\tchar **argv = new char *[argc\
    \ + 1];\n\n\tva_list ap;\n\tva_start(ap, argc);\n\targv[0] = NULL;\n\tfor (int\
    \ i = 0; i < argc; i++) {\n\t\targv[i + 1] = va_arg(ap, char*);\n\t}\n\tva_end(ap);\n\
    \n\tregisterTestlibCmd(argc + 1, argv);\n\tdelete[] argv;\n}\n\nstatic inline\
    \ void __testlib_ensure(bool cond, const std::string &msg) {\n\tif (!cond)\n\t\
    \tquit(_fail, msg.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__((unused))\n#endif\n\
    static inline void __testlib_ensure(bool cond, const char *msg) {\n\tif (!cond)\n\
    \t\tquit(_fail, msg);\n}\n\n#define ensure(cond) __testlib_ensure(cond, \"Condition\
    \ failed: \\\"\" #cond \"\\\"\")\n#define STRINGIZE_DETAIL(x) #x\n#define STRINGIZE(x)\
    \ STRINGIZE_DETAIL(x)\n#define ensure_ext(cond) __testlib_ensure(cond, \"Line\
    \ \" STRINGIZE(__LINE__) \": Condition failed: \\\"\" #cond \"\\\"\")\n\n#ifdef\
    \ __GNUC__\n__attribute__ ((format (printf, 2, 3)))\n#endif\ninline void ensuref(bool\
    \ cond, const char *format, ...) {\n\tif (!cond) {\n\t\tFMT_TO_RESULT(format,\
    \ format, message);\n\t\t__testlib_ensure(cond, message);\n\t}\n}\n\nNORETURN\
    \ static void __testlib_fail(const std::string &message) {\n\tquitf(_fail, \"\
    %s\", message.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf,\
    \ 1, 2)))\n#endif\nvoid setName(const char *format, ...) {\n\tFMT_TO_RESULT(format,\
    \ format, name);\n\tcheckerName = name;\n}\n\n/* \n * Do not use random_shuffle,\
    \ because it will produce different result\n * for different C++ compilers.\n\
    \ *\n * This implementation uses testlib random_t to produce random numbers, so\n\
    \ * it is stable.\n */\ntemplate<typename _RandomAccessIter>\nvoid shuffle(_RandomAccessIter\
    \ __first, _RandomAccessIter __last) {\n\tif (__first == __last) return;\n\tfor\
    \ (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)\n\t\tstd::iter_swap(__i,\
    \ __first + rnd.next(int(__i - __first) + 1));\n}\n\n\ntemplate<typename _RandomAccessIter>\n\
    #if defined(__GNUC__) && !defined(__clang__)\n__attribute__ ((error(\"Don't use\
    \ random_shuffle(), use shuffle() instead\")))\n#endif\nvoid random_shuffle(_RandomAccessIter,\
    \ _RandomAccessIter) {\n\tquitf(_fail, \"Don't use random_shuffle(), use shuffle()\
    \ instead\");\n}\n\n#ifdef __GLIBC__\n#  define RAND_THROW_STATEMENT throw()\n\
    #else\n#  define RAND_THROW_STATEMENT\n#endif\n\n#if defined(__GNUC__) && !defined(__clang__)\n\
    \n__attribute__ ((error(\"Don't use rand(), use rnd.next() instead\")))\n#endif\n\
    #ifdef _MSC_VER\n#   pragma warning( disable : 4273 )\n#endif\nint rand() RAND_THROW_STATEMENT\n\
    {\n\tquitf(_fail, \"Don't use rand(), use rnd.next() instead\");\n\n\t/* This\
    \ line never runs. */\n\t//throw \"Don't use rand(), use rnd.next() instead\"\
    ;\n}\n\n#if defined(__GNUC__) && !defined(__clang__)\n\n__attribute__ ((error(\"\
    Don't use srand(), you should use \"\n\"'registerGen(argc, argv, 1);' to initialize\
    \ generator seed \"\n\"by hash code of the command line params. The third parameter\
    \ \"\n\"is randomGeneratorVersion (currently the latest is 1).\")))\n#endif\n\
    #ifdef _MSC_VER\n#   pragma warning( disable : 4273 )\n#endif\nvoid srand(unsigned\
    \ int seed) RAND_THROW_STATEMENT\n{\n\tquitf(_fail, \"Don't use srand(), you should\
    \ use \"\n\t\t\t\t \"'registerGen(argc, argv, 1);' to initialize generator seed\
    \ \"\n\t\t\t\t \"by hash code of the command line params. The third parameter\
    \ \"\n\t\t\t\t \"is randomGeneratorVersion (currently the latest is 1) [ignored\
    \ seed=%d].\", seed);\n}\n\nvoid startTest(int test) {\n\tconst std::string testFileName\
    \ = vtos(test);\n\tif (NULL == freopen(testFileName.c_str(), \"wt\", stdout))\n\
    \t\t__testlib_fail(\"Unable to write file '\" + testFileName + \"'\");\n}\n\n\
    inline std::string upperCase(std::string s) {\n\tfor (size_t i = 0; i < s.length();\
    \ i++)\n\t\tif ('a' <= s[i] && s[i] <= 'z')\n\t\t\ts[i] = char(s[i] - 'a' + 'A');\n\
    \treturn s;\n}\n\ninline std::string lowerCase(std::string s) {\n\tfor (size_t\
    \ i = 0; i < s.length(); i++)\n\t\tif ('A' <= s[i] && s[i] <= 'Z')\n\t\t\ts[i]\
    \ = char(s[i] - 'A' + 'a');\n\treturn s;\n}\n\ninline std::string compress(const\
    \ std::string &s) {\n\treturn __testlib_part(s);\n}\n\ninline std::string englishEnding(int\
    \ x) {\n\tx %= 100;\n\tif (x / 10 == 1)\n\t\treturn \"th\";\n\tif (x % 10 == 1)\n\
    \t\treturn \"st\";\n\tif (x % 10 == 2)\n\t\treturn \"nd\";\n\tif (x % 10 == 3)\n\
    \t\treturn \"rd\";\n\treturn \"th\";\n}\n\ntemplate<typename _ForwardIterator,\
    \ typename _Separator>\nstd::string join(_ForwardIterator first, _ForwardIterator\
    \ last, _Separator separator) {\n\tstd::stringstream ss;\n\tbool repeated = false;\n\
    \tfor (_ForwardIterator i = first; i != last; i++) {\n\t\tif (repeated)\n\t\t\t\
    ss << separator;\n\t\telse\n\t\t\trepeated = true;\n\t\tss << *i;\n\t}\n\treturn\
    \ ss.str();\n}\n\ntemplate<typename _ForwardIterator>\nstd::string join(_ForwardIterator\
    \ first, _ForwardIterator last) {\n\treturn join(first, last, ' ');\n}\n\ntemplate<typename\
    \ _Collection, typename _Separator>\nstd::string join(const _Collection &collection,\
    \ _Separator separator) {\n\treturn join(collection.begin(), collection.end(),\
    \ separator);\n}\n\ntemplate<typename _Collection>\nstd::string join(const _Collection\
    \ &collection) {\n\treturn join(collection, ' ');\n}\n\n/**\n * Splits string\
    \ s by character separator returning exactly k+1 items,\n * where k is the number\
    \ of separator occurences.\n */\nstd::vector<std::string> split(const std::string\
    \ &s, char separator) {\n\tstd::vector<std::string> result;\n\tstd::string item;\n\
    \tfor (size_t i = 0; i < s.length(); i++)\n\t\tif (s[i] == separator) {\n\t\t\t\
    result.push_back(item);\n\t\t\titem = \"\";\n\t\t} else\n\t\t\titem += s[i];\n\
    \tresult.push_back(item);\n\treturn result;\n}\n\n/**\n * Splits string s by character\
    \ separators returning exactly k+1 items,\n * where k is the number of separator\
    \ occurences.\n */\nstd::vector<std::string> split(const std::string &s, const\
    \ std::string &separators) {\n\tif (separators.empty())\n\t\treturn std::vector<std::string>(1,\
    \ s);\n\n\tstd::vector<bool> isSeparator(256);\n\tfor (size_t i = 0; i < separators.size();\
    \ i++)\n\t\tisSeparator[(unsigned char) (separators[i])] = true;\n\n\tstd::vector<std::string>\
    \ result;\n\tstd::string item;\n\tfor (size_t i = 0; i < s.length(); i++)\n\t\t\
    if (isSeparator[(unsigned char) (s[i])]) {\n\t\t\tresult.push_back(item);\n\t\t\
    \titem = \"\";\n\t\t} else\n\t\t\titem += s[i];\n\tresult.push_back(item);\n\t\
    return result;\n}\n\n/**\n * Splits string s by character separator returning\
    \ non-empty items.\n */\nstd::vector<std::string> tokenize(const std::string &s,\
    \ char separator) {\n\tstd::vector<std::string> result;\n\tstd::string item;\n\
    \tfor (size_t i = 0; i < s.length(); i++)\n\t\tif (s[i] == separator) {\n\t\t\t\
    if (!item.empty())\n\t\t\t\tresult.push_back(item);\n\t\t\titem = \"\";\n\t\t\
    } else\n\t\t\titem += s[i];\n\tif (!item.empty())\n\t\tresult.push_back(item);\n\
    \treturn result;\n}\n\n/**\n * Splits string s by character separators returning\
    \ non-empty items.\n */\nstd::vector<std::string> tokenize(const std::string &s,\
    \ const std::string &separators) {\n\tif (separators.empty())\n\t\treturn std::vector<std::string>(1,\
    \ s);\n\n\tstd::vector<bool> isSeparator(256);\n\tfor (size_t i = 0; i < separators.size();\
    \ i++)\n\t\tisSeparator[(unsigned char) (separators[i])] = true;\n\n\tstd::vector<std::string>\
    \ result;\n\tstd::string item;\n\tfor (size_t i = 0; i < s.length(); i++)\n\t\t\
    if (isSeparator[(unsigned char) (s[i])]) {\n\t\t\tif (!item.empty())\n\t\t\t\t\
    result.push_back(item);\n\t\t\titem = \"\";\n\t\t} else\n\t\t\titem += s[i];\n\
    \n\tif (!item.empty())\n\t\tresult.push_back(item);\n\n\treturn result;\n}\n\n\
    NORETURN void __testlib_expectedButFound(TResult result, std::string expected,\
    \ std::string found, const char *prepend) {\n\tstd::string message;\n\tif (strlen(prepend)\
    \ != 0)\n\t\tmessage = format(\"%s: expected '%s', but found '%s'\",\n\t\t\t\t\
    \t\t compress(prepend).c_str(), compress(expected).c_str(), compress(found).c_str());\n\
    \telse\n\t\tmessage = format(\"expected '%s', but found '%s'\",\n\t\t\t\t\t\t\
    \ compress(expected).c_str(), compress(found).c_str());\n\tquit(result, message);\n\
    }\n\nNORETURN void __testlib_expectedButFound(TResult result, double expected,\
    \ double found, const char *prepend) {\n\tstd::string expectedString = removeDoubleTrailingZeroes(format(\"\
    %.12f\", expected));\n\tstd::string foundString = removeDoubleTrailingZeroes(format(\"\
    %.12f\", found));\n\t__testlib_expectedButFound(result, expectedString, foundString,\
    \ prepend);\n}\n\ntemplate<typename T>\n#ifdef __GNUC__\n__attribute__ ((format\
    \ (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound(TResult result, T expected,\
    \ T found, const char *prependFormat = \"\", ...) {\n\tFMT_TO_RESULT(prependFormat,\
    \ prependFormat, prepend);\n\tstd::string expectedString = vtos(expected);\n\t\
    std::string foundString = vtos(found);\n\t__testlib_expectedButFound(result, expectedString,\
    \ foundString, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<std::string>(TResult\
    \ result, std::string expected, std::string found, const char *prependFormat,\
    \ ...) {\n\tFMT_TO_RESULT(prependFormat, prependFormat, prepend);\n\t__testlib_expectedButFound(result,\
    \ expected, found, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound<double>(TResult\
    \ result, double expected, double found, const char *prependFormat, ...) {\n\t\
    FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n\tstd::string expectedString\
    \ = removeDoubleTrailingZeroes(format(\"%.12f\", expected));\n\tstd::string foundString\
    \ = removeDoubleTrailingZeroes(format(\"%.12f\", found));\n\t__testlib_expectedButFound(result,\
    \ expectedString, foundString, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n\
    __attribute__ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<const\
    \ char *>(TResult result, const char *expected, const char *found, const char\
    \ *prependFormat,\n\t\t\t\t\t\t\t   ...) {\n\tFMT_TO_RESULT(prependFormat, prependFormat,\
    \ prepend);\n\t__testlib_expectedButFound(result, std::string(expected), std::string(found),\
    \ prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__ ((format\
    \ (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound<float>(TResult result,\
    \ float expected, float found, const char *prependFormat, ...) {\n\tFMT_TO_RESULT(prependFormat,\
    \ prependFormat, prepend);\n\t__testlib_expectedButFound(result, double(expected),\
    \ double(found), prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<long double>(TResult\
    \ result, long double expected, long double found, const char *prependFormat,\
    \ ...) {\n\tFMT_TO_RESULT(prependFormat, prependFormat, prepend);\n\t__testlib_expectedButFound(result,\
    \ double(expected), double(found), prepend.c_str());\n}\n\n#if __cplusplus > 199711L\
    \ || defined(_MSC_VER)\ntemplate<typename T>\nstruct is_iterable {\n\ttemplate<typename\
    \ U>\n\tstatic char test(typename U::iterator *x);\n\n\ttemplate<typename U>\n\
    \tstatic long test(U *x);\n\n\tstatic const bool value = sizeof(test<T>(0)) ==\
    \ 1;\n};\n\ntemplate<bool B, class T = void>\nstruct __testlib_enable_if {\n};\n\
    \ntemplate<class T>\nstruct __testlib_enable_if<true, T> {\n\ttypedef T type;\n\
    };\n\ntemplate<typename T>\ntypename __testlib_enable_if<!is_iterable<T>::value,\
    \ void>::type __testlib_print_one(const T &t) {\n\tstd::cout << t;\n}\n\ntemplate<typename\
    \ T>\ntypename __testlib_enable_if<is_iterable<T>::value, void>::type __testlib_print_one(const\
    \ T &t) {\n\tbool first = true;\n\tfor (typename T::const_iterator i = t.begin();\
    \ i != t.end(); i++) {\n\t\tif (first)\n\t\t\tfirst = false;\n\t\telse\n\t\t\t\
    std::cout << \" \";\n\t\tstd::cout << *i;\n\t}\n}\n\ntemplate<>\ntypename __testlib_enable_if<is_iterable<std::string>::value,\
    \ void>::type\n__testlib_print_one<std::string>(const std::string &t) {\n\tstd::cout\
    \ << t;\n}\n\ntemplate<typename A, typename B>\nvoid __println_range(A begin,\
    \ B end) {\n\tbool first = true;\n\tfor (B i = B(begin); i != end; i++) {\n\t\t\
    if (first)\n\t\t\tfirst = false;\n\t\telse\n\t\t\tstd::cout << \" \";\n\t\t__testlib_print_one(*i);\n\
    \t}\n\tstd::cout << std::endl;\n}\n\ntemplate<class T, class Enable = void>\n\
    struct is_iterator {\n\tstatic T makeT();\n\n\ttypedef void *twoptrs[2];\n\n\t\
    static twoptrs &test(...);\n\n\ttemplate<class R>\n\tstatic typename R::iterator_category\
    \ *test(R);\n\n\ttemplate<class R>\n\tstatic void *test(R *);\n\n\tstatic const\
    \ bool value = sizeof(test(makeT())) == sizeof(void *);\n};\n\ntemplate<class\
    \ T>\nstruct is_iterator<T, typename __testlib_enable_if<std::is_array<T>::value>::type>\
    \ {\n\tstatic const bool value = false;\n};\n\ntemplate<typename A, typename B>\n\
    typename __testlib_enable_if<!is_iterator<B>::value, void>::type println(const\
    \ A &a, const B &b) {\n\t__testlib_print_one(a);\n\tstd::cout << \" \";\n\t__testlib_print_one(b);\n\
    \tstd::cout << std::endl;\n}\n\ntemplate<typename A, typename B>\ntypename __testlib_enable_if<is_iterator<B>::value,\
    \ void>::type println(const A &a, const B &b) {\n\t__println_range(a, b);\n}\n\
    \ntemplate<typename A>\nvoid println(const A *a, const A *b) {\n\t__println_range(a,\
    \ b);\n}\n\ntemplate<>\nvoid println<char>(const char *a, const char *b) {\n\t\
    __testlib_print_one(a);\n\tstd::cout << \" \";\n\t__testlib_print_one(b);\n\t\
    std::cout << std::endl;\n}\n\ntemplate<typename T>\nvoid println(const T &x) {\n\
    \t__testlib_print_one(x);\n\tstd::cout << std::endl;\n}\n\ntemplate<typename A,\
    \ typename B, typename C>\nvoid println(const A &a, const B &b, const C &c) {\n\
    \t__testlib_print_one(a);\n\tstd::cout << \" \";\n\t__testlib_print_one(b);\n\t\
    std::cout << \" \";\n\t__testlib_print_one(c);\n\tstd::cout << std::endl;\n}\n\
    \ntemplate<typename A, typename B, typename C, typename D>\nvoid println(const\
    \ A &a, const B &b, const C &c, const D &d) {\n\t__testlib_print_one(a);\n\tstd::cout\
    \ << \" \";\n\t__testlib_print_one(b);\n\tstd::cout << \" \";\n\t__testlib_print_one(c);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(d);\n\tstd::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E>\nvoid\
    \ println(const A &a, const B &b, const C &c, const D &d, const E &e) {\n\t__testlib_print_one(a);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(b);\n\tstd::cout << \" \";\n\t__testlib_print_one(c);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(d);\n\tstd::cout << \" \";\n\t__testlib_print_one(e);\n\
    \tstd::cout << std::endl;\n}\n\ntemplate<typename A, typename B, typename C, typename\
    \ D, typename E, typename F>\nvoid println(const A &a, const B &b, const C &c,\
    \ const D &d, const E &e, const F &f) {\n\t__testlib_print_one(a);\n\tstd::cout\
    \ << \" \";\n\t__testlib_print_one(b);\n\tstd::cout << \" \";\n\t__testlib_print_one(c);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(d);\n\tstd::cout << \" \";\n\t__testlib_print_one(e);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(f);\n\tstd::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E, typename\
    \ F, typename G>\nvoid println(const A &a, const B &b, const C &c, const D &d,\
    \ const E &e, const F &f, const G &g) {\n\t__testlib_print_one(a);\n\tstd::cout\
    \ << \" \";\n\t__testlib_print_one(b);\n\tstd::cout << \" \";\n\t__testlib_print_one(c);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(d);\n\tstd::cout << \" \";\n\t__testlib_print_one(e);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(f);\n\tstd::cout << \" \";\n\t__testlib_print_one(g);\n\
    \tstd::cout << std::endl;\n}\n\n/* opts */\nsize_t getOptType(char* s) {\n\tif\
    \ (!s || strlen(s) <= 1)\n\t\treturn false;\n\n\tif (s[0] == '-') {\n\t\tif (isalpha(s[1]))\n\
    \t\t\treturn 1;\n\t\telse if (s[1] == '-')\n\t\t\treturn isalpha(s[2]) ? 2 : 0;\n\
    \t}\n\n\treturn 0;\n}\n\nsize_t parseOpt(size_t argc, char* argv[], size_t index,\
    \ std::map<std::string, std::string>& opts) {\n\tif (index >= argc)\n\t\treturn\
    \ 0;\n\n\tsize_t type = getOptType(argv[index]), inc = 1;\n\tif (type > 0) {\n\
    \t\tstd::string key(argv[index] + type), val;\n\t\tsize_t sep = key.find('=');\n\
    \t\tif (sep != std::string::npos) {\n\t\t\tval = key.substr(sep + 1);\n\t\t\t\
    key = key.substr(0, sep);\n\t\t} else {\n\t\t\tif (index + 1 < argc && getOptType(argv[index\
    \ + 1]) == 0) {\n\t\t\t\tval = argv[index + 1];\n\t\t\t\tinc = 2;\n\t\t\t} else\
    \ {\n\t\t\t\tif (key.length() > 1 && isdigit(key[1])) {\n\t\t\t\t\tval = key.substr(1);\n\
    \t\t\t\t\tkey = key.substr(0, 1);\n\t\t\t\t} else {\n\t\t\t\t\tval = \"true\"\
    ;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\topts[key] = val;\n\t} else {\n\t\treturn inc;\n\
    \t}\n\n\treturn inc;\n}\n\nstd::vector<std::string> __testlib_argv;\nstd::map<std::string,\
    \ std::string> __testlib_opts;\n\nvoid prepareOpts(int argc, char* argv[]) {\n\
    \tif (argc <= 0)\n\t\t__testlib_fail(\"Opts: expected argc>=0 but found \" + toString(argc));\n\
    \tsize_t n = static_cast<size_t>(argc); // NOLINT(hicpp-use-auto,modernize-use-auto)\n\
    \t__testlib_opts = std::map<std::string, std::string>();\n\tfor (size_t index\
    \ = 1; index < n; index += parseOpt(n, argv, index, __testlib_opts));\n\t__testlib_argv\
    \ = std::vector<std::string>(n);\n\tfor (size_t index = 0; index < n; index++)\n\
    \t\t__testlib_argv[index] = argv[index];\n}\n\nstd::string __testlib_indexToArgv(int\
    \ index) {\n\tif (index < 0 || index >= int(__testlib_argv.size()))\n\t\t__testlib_fail(\"\
    Opts: index '\" + toString(index) + \"' is out of range [0,\" + toString(__testlib_argv.size())\
    \ + \")\");\n\treturn __testlib_argv[size_t(index)];\n}\n\nstd::string __testlib_keyToOpts(const\
    \ std::string& key) {\n\tif (__testlib_opts.count(key) == 0)\n\t\t__testlib_fail(\"\
    Opts: unknown key '\" + compress(key) + \"'\");\n\treturn __testlib_opts[key];\n\
    }\n\ntemplate<typename T>\nT optValueToIntegral(const std::string& s, bool nonnegative);\n\
    \nlong double optValueToLongDouble(const std::string& s);\n\nstd::string parseExponentialOptValue(const\
    \ std::string& s) {\n\tsize_t pos = std::string::npos;\n\tfor (size_t i = 0; i\
    \ < s.length(); i++)\n\t\tif (s[i] == 'e' || s[i] == 'E') {\n\t\t\tif (pos !=\
    \ std::string::npos)\n\t\t\t\t__testlib_fail(\"Opts: expected typical exponential\
    \ notation but '\" + compress(s) + \"' found\");\n\t\t\tpos = i;\n\t\t}\n\tif\
    \ (pos == std::string::npos)\n\t\treturn s;\n\tstd::string e = s.substr(pos +\
    \ 1);\n\tif (!e.empty() && e[0] == '+')\n\t\te = e.substr(1);\n\tif (e.empty())\n\
    \t\t__testlib_fail(\"Opts: expected typical exponential notation but '\" + compress(s)\
    \ + \"' found\");\n\tif (e.length() > 20)\n\t\t__testlib_fail(\"Opts: expected\
    \ typical exponential notation but '\" + compress(s) + \"' found\");\n\tint ne\
    \ = optValueToIntegral<int>(e, false);\n\tstd::string num = s.substr(0, pos);\n\
    \tif (num.length() > 20)\n\t\t__testlib_fail(\"Opts: expected typical exponential\
    \ notation but '\" + compress(s) + \"' found\");\n\tif (!num.empty() && num[0]\
    \ == '+')\n\t\tnum = num.substr(1);\n\toptValueToLongDouble(num);\n\tbool minus\
    \ = false;\n\tif (num[0] == '-') {\n\t\tminus = true;\n\t\tnum = num.substr(1);\n\
    \t}\n\tfor (int i = 0; i < +ne; i++) {\n\t\tsize_t sep = num.find('.');\n\t\t\
    if (sep == std::string::npos)\n\t\t\tnum += '0';\n\t\telse {\n\t\t\tif (sep +\
    \ 1 == num.length())\n\t\t\t\tnum[sep] = '0';\n\t\t\telse\n\t\t\t\tstd::swap(num[sep],\
    \ num[sep + 1]);\n\t\t}\n\t}\n\tfor (int i = 0; i < -ne; i++) {\n\t\tsize_t sep\
    \ = num.find('.');\n\t\tif (sep == std::string::npos)\n\t\t\tnum.insert(num.begin()\
    \ + int(num.length()) - 1, '.');\n\t\telse {\n\t\t\tif (sep == 0)\n\t\t\t\tnum.insert(num.begin()\
    \ + 1, '0');\n\t\t\telse\n\t\t\t\tstd::swap(num[sep - 1], num[sep]);\n\t\t}\n\t\
    }\n\twhile (!num.empty() && num[0] == '0')\n\t\tnum = num.substr(1);\n\twhile\
    \ (num.find('.') != std::string::npos && num.back() == '0')\n\t\tnum = num.substr(0,\
    \ num.length() - 1);\n\tif (!num.empty() && num.back() == '.')\n\t\tnum = num.substr(0,\
    \ num.length() - 1);\n\tif ((!num.empty() && num[0] == '.') || num.empty())\n\t\
    \tnum.insert(num.begin(), '0');\n\treturn (minus ? \"-\" : \"\") + num;\n}\n\n\
    template<typename T>\nT optValueToIntegral(const std::string& s_, bool nonnegative)\
    \ {\n\tstd::string s(parseExponentialOptValue(s_));\n\tif (s.empty())\n\t\t__testlib_fail(\"\
    Opts: expected integer but '\" + compress(s_) + \"' found\");\n\tT value = 0;\n\
    \tlong double about = 0.0;\n\tsigned char sign = +1;\n\tsize_t pos = 0;\n\tif\
    \ (s[pos] == '-') {\n\t\tif (nonnegative)\n\t\t\t__testlib_fail(\"Opts: expected\
    \ non-negative integer but '\" + compress(s_) + \"' found\");\n\t\tsign = -1;\n\
    \t\tpos++;\n\t}\n\tfor (size_t i = pos; i < s.length(); i++) {\n\t\tif (s[i] <\
    \ '0' || s[i] > '9')\n\t\t\t__testlib_fail(\"Opts: expected integer but '\" +\
    \ compress(s_) + \"' found\");\n\t\tvalue = value * 10 + s[i] - '0';\n\t\tabout\
    \ = about * 10 + s[i] - '0';\n\t}\n\tvalue *= sign;\n\tabout *= sign;\n\tif (fabsl(value\
    \ - about) > 0.1)\n\t\t__testlib_fail(\"Opts: integer overflow: expected integer\
    \ but '\" + compress(s_) + \"' found\");\n\treturn value;\n}\n\nlong double optValueToLongDouble(const\
    \ std::string& s_) {\n\tstd::string s(parseExponentialOptValue(s_));\n\tif (s.empty())\n\
    \t\t__testlib_fail(\"Opts: expected float number but '\" + compress(s_) + \"'\
    \ found\");\n\tlong double value = 0.0;\n\tsigned char sign = +1;\n\tsize_t pos\
    \ = 0;\n\tif (s[pos] == '-') {\n\t\tsign = -1;\n\t\tpos++;\n\t}\n\tbool period\
    \ = false;\n\tlong double mul = 1.0;\n\tfor (size_t i = pos; i < s.length(); i++)\
    \ {\n\t\tif (s[i] == '.') {\n\t\t\tif (period)\n\t\t\t\t__testlib_fail(\"Opts:\
    \ expected float number but '\" + compress(s_) + \"' found\");\n\t\t\telse {\n\
    \t\t\t\tperiod = true;\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t}\n\t\tif (period)\n\t\
    \t\tmul *= 10.0;\n\t\tif (s[i] < '0' || s[i] > '9')\n\t\t\t__testlib_fail(\"Opts:\
    \ expected float number but '\" + compress(s_) + \"' found\");\n\t\tif (period)\n\
    \t\t\tvalue += (s[i] - '0') / mul;\n\t\telse\n\t\t\tvalue = value * 10 + s[i]\
    \ - '0';\n\t}\n\tvalue *= sign;\n\treturn value;\n}\n\nbool has_opt(const std::string\
    \ key) {\n\treturn __testlib_opts.count(key) != 0;\n}\n\ntemplate<typename T>\n\
    T opt(std::false_type, int index);\n\ntemplate<>\nstd::string opt(std::false_type,\
    \ int index) {\n\treturn __testlib_indexToArgv(index);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, int index) {\n\treturn T(optValueToLongDouble(__testlib_indexToArgv(index)));\n\
    }\n\ntemplate<typename T, typename U>\nT opt(std::false_type, U, int index) {\n\
    \treturn opt<T>(std::is_floating_point<T>(), index);\n}\n\ntemplate<typename T>\n\
    T opt(std::true_type, std::false_type, int index) {\n\treturn optValueToIntegral<T>(__testlib_indexToArgv(index),\
    \ false);\n}\n\ntemplate<typename T>\nT opt(std::true_type, std::true_type, int\
    \ index) {\n\treturn optValueToIntegral<T>(__testlib_indexToArgv(index), true);\n\
    }\n\ntemplate<>\nbool opt(std::true_type, std::true_type, int index) {\n\tstd::string\
    \ value = __testlib_indexToArgv(index);\n\tif (value == \"true\" || value == \"\
    1\")\n\t\treturn true;\n\tif (value == \"false\" || value == \"0\")\n\t\treturn\
    \ false;\n\t__testlib_fail(\"Opts: opt by index '\" + toString(index) + \"': expected\
    \ bool true/false or 0/1 but '\" + compress(value) + \"' found\");\n}\n\ntemplate<typename\
    \ T>\nT opt(int index) {\n\treturn opt<T>(std::is_integral<T>(), std::is_unsigned<T>(),\
    \ index);\n}\n\nstd::string opt(int index) {\n\treturn opt<std::string>(index);\n\
    }\n\ntemplate<typename T>\nT opt(std::false_type, const std::string& key);\n\n\
    template<>\nstd::string opt(std::false_type, const std::string& key) {\n\treturn\
    \ __testlib_keyToOpts(key);\n}\n\ntemplate<typename T>\nT opt(std::true_type,\
    \ const std::string& key) {\n\treturn T(optValueToLongDouble(__testlib_keyToOpts(key)));\n\
    }\n\ntemplate<typename T, typename U>\nT opt(std::false_type, U, const std::string&\
    \ key) {\n\treturn opt<T>(std::is_floating_point<T>(), key);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::false_type, const std::string& key) {\n\treturn\
    \ optValueToIntegral<T>(__testlib_keyToOpts(key), false);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::true_type, const std::string& key) {\n\treturn\
    \ optValueToIntegral<T>(__testlib_keyToOpts(key), true);\n}\n\ntemplate<>\nbool\
    \ opt(std::true_type, std::true_type, const std::string& key) {\n\tif (!has_opt(key))\n\
    \t\treturn false;\n\tstd::string value = __testlib_keyToOpts(key);\n\tif (value\
    \ == \"true\" || value == \"1\")\n\t\treturn true;\n\tif (value == \"false\" ||\
    \ value == \"0\")\n\t\treturn false;\n\t__testlib_fail(\"Opts: key '\" + compress(key)\
    \ + \"': expected bool true/false or 0/1 but '\" + compress(value) + \"' found\"\
    );\n}\n\ntemplate<typename T>\nT opt(const std::string key) {\n\treturn opt<T>(std::is_integral<T>(),\
    \ std::is_unsigned<T>(), key);\n}\n\nstd::string opt(const std::string key) {\n\
    \treturn opt<std::string>(key);\n}\n#endif\n#endif\n"
  code: "/* \n * It is strictly recommended to include \"testlib.h\" before any other\
    \ include \n * in your code. In this case testlib overrides compiler specific\
    \ \"random()\".\n *\n * If you can't compile your code and compiler outputs something\
    \ about \n * ambiguous call of \"random_shuffle\", \"rand\" or \"srand\" it means\
    \ that \n * you shouldn't use them. Use \"shuffle\", and \"rnd.next()\" instead\
    \ of them\n * because these calls produce stable result for any C++ compiler.\
    \ Read \n * sample generator sources for clarification.\n *\n * Please read the\
    \ documentation for class \"random_t\" and use \"rnd\" instance in\n * generators.\
    \ Probably, these sample calls will be usefull for you:\n *\t\t\t  rnd.next();\
    \ rnd.next(100); rnd.next(1, 2); \n *\t\t\t  rnd.next(3.14); rnd.next(\"[a-z]{1,100}\"\
    ).\n *\n * Also read about wnext() to generate off-center random distribution.\n\
    \ *\n * See https://github.com/MikeMirzayanov/testlib/ to get latest version or\
    \ bug tracker.\n */\n\n#ifndef _TESTLIB_H_\n#define _TESTLIB_H_\n\n/*\n * Copyright\
    \ (c) 2005-2020\n */\n\n#define VERSION \"0.9.33-SNAPSHOT\"\n\n/* \n * Mike Mirzayanov\n\
    \ *\n * This material is provided \"as is\", with absolutely no warranty expressed\n\
    \ * or implied. Any use is at your own risk.\n *\n * Permission to use or copy\
    \ this software for any purpose is hereby granted \n * without fee, provided the\
    \ above notices are retained on all copies.\n * Permission to modify the code\
    \ and to distribute modified code is granted,\n * provided the above notices are\
    \ retained, and a notice that the code was\n * modified is included with the above\
    \ copyright notice.\n *\n */\n\n/* NOTE: This file contains testlib library for\
    \ C++.\n *\n *   Check, using testlib running format:\n *\t check.exe <Input_File>\
    \ <Output_File> <Answer_File> [<Result_File> [-appes]],\n *   If result file is\
    \ specified it will contain results.\n *\n *   Validator, using testlib running\
    \ format:\t\t\t\t\t\t\t\t\t\t  \n *\t validator.exe < input.txt,\n *   It will\
    \ return non-zero exit code and writes message to standard output.\n *\n *   Generator,\
    \ using testlib running format:\t\t\t\t\t\t\t\t\t\t  \n *\t gen.exe [parameter-1]\
    \ [parameter-2] [... paramerter-n]\n *   You can write generated test(s) into\
    \ standard output or into the file(s).\n *\n *   Interactor, using testlib running\
    \ format:\t\t\t\t\t\t\t\t\t\t  \n *\t interactor.exe <Input_File> <Output_File>\
    \ [<Answer_File> [<Result_File> [-appes]]],\n *   Reads test from inf (mapped\
    \ to args[1]), writes result to tout (mapped to argv[2],\n *   can be judged by\
    \ checker later), reads program output from ouf (mapped to stdin),\n *   writes\
    \ output to program via stdout (use cout, printf, etc).\n */\n\nconst char *latestFeatures[]\
    \ = {\n\t\t\"rnd.partition(size, sum[, min_part=0]) returns random (unsorted)\
    \ partition which is a representation of the given `sum` as a sum of `size` positive\
    \ integers (or >=min_part if specified)\",\n\t\t\"rnd.distinct(size, n) and rnd.distinct(size,\
    \ from, to)\",\n\t\t\"opt<bool>(\\\"some_missing_key\\\") returns false now\"\
    ,\n\t\t\"has_opt(key)\",\n\t\t\"Abort validator on validator.testset()/validator.group()\
    \ if registered without using command line\",\n\t\t\"Print integer range violations\
    \ in a human readable way like `violates the range [1, 10^9]`\",\n\t\t\"Opts supported:\
    \ use them like n = opt<int>(\\\"n\\\"), in a command line you can use an exponential\
    \ notation\",\n\t\t\"Reformatted\",\n\t\t\"Use setTestCase(i) or unsetTestCase()\
    \ to support test cases (you can use it in any type of program: generator, interactor,\
    \ validator or checker)\",\n\t\t\"Fixed issue #87: readStrictDouble accepts \\\
    \"-0.00\\\"\",\n\t\t\"Fixed issue #83: added InStream::quitif(condition, ...)\"\
    ,\n\t\t\"Fixed issue #79: fixed missed guard against repeated header include\"\
    ,\n\t\t\"Fixed issue #80: fixed UB in case of huge quitf message\",\n\t\t\"Fixed\
    \ issue #84: added readXs(size, indexBase = 1)\",\n\t\t\"Fixed stringstream repeated\
    \ usage issue\",\n\t\t\"Fixed compilation in g++ (for std=c++03)\",\n\t\t\"Batch\
    \ of println functions (support collections, iterator ranges)\",\n\t\t\"Introduced\
    \ rnd.perm(size, first = 0) to generate a `first`-indexed permutation\",\n\t\t\
    \"Allow any whitespace in readInts-like functions for non-validators\",\n\t\t\"\
    Ignore 4+ command line arguments ifdef EJUDGE\",\n\t\t\"Speed up of vtos\",\n\t\
    \t\"Show line number in validators in case of incorrect format\",\n\t\t\"Truncate\
    \ huge checker/validator/interactor message\",\n\t\t\"Fixed issue with readTokenTo\
    \ of very long tokens, now aborts with _pe/_fail depending of a stream type\"\
    ,\n\t\t\"Introduced InStream::ensure/ensuref checking a condition, returns wa/fail\
    \ depending of a stream type\",\n\t\t\"Fixed compilation in VS 2015+\",\n\t\t\"\
    Introduced space-separated read functions: readWords/readTokens, multilines read\
    \ functions: readStrings/readLines\",\n\t\t\"Introduced space-separated read functions:\
    \ readInts/readIntegers/readLongs/readUnsignedLongs/readDoubles/readReals/readStrictDoubles/readStrictReals\"\
    ,\n\t\t\"Introduced split/tokenize functions to separate string by given char\"\
    ,\n\t\t\"Introduced InStream::readUnsignedLong and InStream::readLong with unsigned\
    \ long long paramerters\",\n\t\t\"Supported --testOverviewLogFileName for validator:\
    \ bounds hits + features\",\n\t\t\"Fixed UB (sequence points) in random_t\",\n\
    \t\t\"POINTS_EXIT_CODE returned back to 7 (instead of 0)\",\n\t\t\"Removed disable\
    \ buffers for interactive problems, because it works unexpectedly in wine\",\n\
    \t\t\"InStream over string: constructor of InStream from base InStream to inherit\
    \ policies and std::string\",\n\t\t\"Added expectedButFound quit function, examples:\
    \ expectedButFound(_wa, 10, 20), expectedButFound(_fail, ja, pa, \\\"[n=%d,m=%d]\\\
    \", n, m)\",\n\t\t\"Fixed incorrect interval parsing in patterns\",\n\t\t\"Use\
    \ registerGen(argc, argv, 1) to develop new generator, use registerGen(argc, argv,\
    \ 0) to compile old generators (originally created for testlib under 0.8.7)\"\
    ,\n\t\t\"Introduced disableFinalizeGuard() to switch off finalization checkings\"\
    ,\n\t\t\"Use join() functions to format a range of items as a single string (separated\
    \ by spaces or other separators)\",\n\t\t\"Use -DENABLE_UNEXPECTED_EOF to enable\
    \ special exit code (by default, 8) in case of unexpected eof. It is good idea\
    \ to use it in interactors\",\n\t\t\"Use -DUSE_RND_AS_BEFORE_087 to compile in\
    \ compatibility mode with random behavior of versions before 0.8.7\",\n\t\t\"\
    Fixed bug with nan in stringToDouble\",\n\t\t\"Fixed issue around overloads for\
    \ size_t on x64\",\n\t\t\"Added attribute 'points' to the XML output in case of\
    \ result=_points\",\n\t\t\"Exit codes can be customized via macros, e.g. -DPE_EXIT_CODE=14\"\
    ,\n\t\t\"Introduced InStream function readWordTo/readTokenTo/readStringTo/readLineTo\
    \ for faster reading\",\n\t\t\"Introduced global functions: format(), englishEnding(),\
    \ upperCase(), lowerCase(), compress()\",\n\t\t\"Manual buffer in InStreams, some\
    \ IO speed improvements\",\n\t\t\"Introduced quitif(bool, const char* pattern,\
    \ ...) which delegates to quitf() in case of first argument is true\",\n\t\t\"\
    Introduced guard against missed quitf() in checker or readEof() in validators\"\
    ,\n\t\t\"Supported readStrictReal/readStrictDouble - to use in validators to check\
    \ strictly float numbers\",\n\t\t\"Supported registerInteraction(argc, argv)\"\
    ,\n\t\t\"Print checker message to the stderr instead of stdout\",\n\t\t\"Supported\
    \ TResult _points to output calculated score, use quitp(...) functions\",\n\t\t\
    \"Fixed to be compilable on Mac\",\n\t\t\"PC_BASE_EXIT_CODE=50 in case of defined\
    \ TESTSYS\",\n\t\t\"Fixed issues 19-21, added __attribute__ format printf\",\n\
    \t\t\"Some bug fixes\",\n\t\t\"ouf.readInt(1, 100) and similar calls return WA\"\
    ,\n\t\t\"Modified random_t to avoid integer overflow\",\n\t\t\"Truncated checker\
    \ output [patch by Stepan Gatilov]\",\n\t\t\"Renamed class random -> class random_t\"\
    ,\n\t\t\"Supported name parameter for read-and-validation methods, like readInt(1,\
    \ 2, \\\"n\\\")\",\n\t\t\"Fixed bug in readDouble()\",\n\t\t\"Improved ensuref(),\
    \ fixed nextLine to work in case of EOF, added startTest()\",\n\t\t\"Supported\
    \ \\\"partially correct\\\", example: quitf(_pc(13), \\\"result=%d\\\", result)\"\
    ,\n\t\t\"Added shuffle(begin, end), use it instead of random_shuffle(begin, end)\"\
    ,\n\t\t\"Added readLine(const string& ptrn), fixed the logic of readLine() in\
    \ the validation mode\",\n\t\t\"Package extended with samples of generators and\
    \ validators\",\n\t\t\"Written the documentation for classes and public methods\
    \ in testlib.h\",\n\t\t\"Implemented random routine to support generators, use\
    \ registerGen() to switch it on\",\n\t\t\"Implemented strict mode to validate\
    \ tests, use registerValidation() to switch it on\",\n\t\t\"Now ncmp.cpp and wcmp.cpp\
    \ are return WA if answer is suffix or prefix of the output\",\n\t\t\"Added InStream::readLong()\
    \ and removed InStream::readLongint()\",\n\t\t\"Now no footer added to each report\
    \ by default (use directive FOOTER to switch on)\",\n\t\t\"Now every checker has\
    \ a name, use setName(const char* format, ...) to set it\",\n\t\t\"Now it is compatible\
    \ with TTS (by Kittens Computing)\",\n\t\t\"Added \\'ensure(condition, message\
    \ = \\\"\\\")\\' feature, it works like assert()\",\n\t\t\"Fixed compatibility\
    \ with MS C++ 7.1\",\n\t\t\"Added footer with exit code information\",\n\t\t\"\
    Added compatibility with EJUDGE (compile with EJUDGE directive)\",\n\t\t\"Added\
    \ compatibility with Contester (compile with CONTESTER directive)\"\n};\n\n#ifdef\
    \ _MSC_VER\n#define _CRT_SECURE_NO_DEPRECATE\n#define _CRT_SECURE_NO_WARNINGS\n\
    #define _CRT_NO_VA_START_VALIDATION\n#endif\n\n/* Overrides random() for Borland\
    \ C++. */\n#define random __random_deprecated\n#include <stdlib.h>\n#include <cstdlib>\n\
    #include <climits>\n#include <algorithm>\n#undef random\n\n#include <cstdio>\n\
    #include <cctype>\n#include <string>\n#include <vector>\n#include <map>\n#include\
    \ <set>\n#include <cmath>\n#include <iostream>\n#include <sstream>\n#include <fstream>\n\
    #include <cstring>\n#include <limits>\n#include <stdarg.h>\n#include <fcntl.h>\n\
    \n#if (_WIN32 || __WIN32__ || _WIN64 || __WIN64__ || __CYGWIN__)\n#   if !defined(_MSC_VER)\
    \ || _MSC_VER > 1400\n#\t   define NOMINMAX 1\n#\t   include <windows.h>\n#  \
    \ else\n#\t   define WORD unsigned short\n#\t   include <unistd.h>\n#   endif\n\
    #   include <io.h>\n#   define ON_WINDOWS\n#   if defined(_MSC_VER) && _MSC_VER\
    \ > 1400\n#\t   pragma warning( disable : 4127 )\n#\t   pragma warning( disable\
    \ : 4146 )\n#\t   pragma warning( disable : 4458 )\n#   endif\n#else\n#   define\
    \ WORD unsigned short\n#   include <unistd.h>\n#endif\n\n#if defined(FOR_WINDOWS)\
    \ && defined(FOR_LINUX)\n#error Only one target system is allowed\n#endif\n\n\
    #ifndef LLONG_MIN\n#define LLONG_MIN   (-9223372036854775807LL - 1)\n#endif\n\n\
    #ifndef ULLONG_MAX\n#define ULLONG_MAX   (18446744073709551615)\n#endif\n\n#define\
    \ LF ((char)10)\n#define CR ((char)13)\n#define TAB ((char)9)\n#define SPACE ((char)'\
    \ ')\n#define EOFC (255)\n\n#ifndef OK_EXIT_CODE\n#   ifdef CONTESTER\n#\t   define\
    \ OK_EXIT_CODE 0xAC\n#   else\n#\t   define OK_EXIT_CODE 0\n#   endif\n#endif\n\
    \n#ifndef WA_EXIT_CODE\n#   ifdef EJUDGE\n#\t   define WA_EXIT_CODE 5\n#   elif\
    \ defined(CONTESTER)\n#\t   define WA_EXIT_CODE 0xAB\n#   else\n#\t   define WA_EXIT_CODE\
    \ 1\n#   endif\n#endif\n\n#ifndef PE_EXIT_CODE\n#   ifdef EJUDGE\n#\t   define\
    \ PE_EXIT_CODE 4\n#   elif defined(CONTESTER)\n#\t   define PE_EXIT_CODE 0xAA\n\
    #   else\n#\t   define PE_EXIT_CODE 2\n#   endif\n#endif\n\n#ifndef FAIL_EXIT_CODE\n\
    #   ifdef EJUDGE\n#\t   define FAIL_EXIT_CODE 6\n#   elif defined(CONTESTER)\n\
    #\t   define FAIL_EXIT_CODE 0xA3\n#   else\n#\t   define FAIL_EXIT_CODE 3\n# \
    \  endif\n#endif\n\n#ifndef DIRT_EXIT_CODE\n#   ifdef EJUDGE\n#\t   define DIRT_EXIT_CODE\
    \ 6\n#   else\n#\t   define DIRT_EXIT_CODE 4\n#   endif\n#endif\n\n#ifndef POINTS_EXIT_CODE\n\
    #   define POINTS_EXIT_CODE 7\n#endif\n\n#ifndef UNEXPECTED_EOF_EXIT_CODE\n# \
    \  define UNEXPECTED_EOF_EXIT_CODE 8\n#endif\n\n#ifndef PC_BASE_EXIT_CODE\n# \
    \  ifdef TESTSYS\n#\t   define PC_BASE_EXIT_CODE 50\n#   else\n#\t   define PC_BASE_EXIT_CODE\
    \ 0\n#   endif\n#endif\n\n#ifdef __GNUC__\n#\tdefine __TESTLIB_STATIC_ASSERT(condition)\
    \ typedef void* __testlib_static_assert_type[(condition) ? 1 : -1] __attribute__((unused))\n\
    #else\n#\tdefine __TESTLIB_STATIC_ASSERT(condition) typedef void* __testlib_static_assert_type[(condition)\
    \ ? 1 : -1]\n#endif\n\n#ifdef ON_WINDOWS\n#define I64 \"%I64d\"\n#define U64 \"\
    %I64u\"\n#else\n#define I64 \"%lld\"\n#define U64 \"%llu\"\n#endif\n\n#ifdef _MSC_VER\n\
    #   define NORETURN __declspec(noreturn)\n#elif defined __GNUC__\n#   define NORETURN\
    \ __attribute__ ((noreturn))\n#else\n#   define NORETURN\n#endif\n\nstatic char\
    \ __testlib_format_buffer[16777216];\nstatic int __testlib_format_buffer_usage_count\
    \ = 0;\n\n#define FMT_TO_RESULT(fmt, cstr, result)  std::string result;\t\t\t\t\
    \t\t\t  \\\n\t\t\tif (__testlib_format_buffer_usage_count != 0)\t\t\t\t\t\t\t\t\
    \  \\\n\t\t\t\t__testlib_fail(\"FMT_TO_RESULT::__testlib_format_buffer_usage_count\
    \ != 0\"); \\\n\t\t\t__testlib_format_buffer_usage_count++;\t\t\t\t\t\t\t\t\t\t\
    \ \\\n\t\t\tva_list ap;\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\tva_start(ap,\
    \ fmt);\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t \\\n\t\t\tvsnprintf(__testlib_format_buffer,\
    \ sizeof(__testlib_format_buffer), cstr, ap); \\\n\t\t\tva_end(ap);\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t\t\t\\\n\t\t\t__testlib_format_buffer[sizeof(__testlib_format_buffer)\
    \ - 1] = 0;\t\t\t  \\\n\t\t\tresult = std::string(__testlib_format_buffer);\t\t\
    \t\t\t\t\t\t \\\n\t\t\t__testlib_format_buffer_usage_count--;\t\t\t\t\t\t\t\t\t\
    \t \\\n\nconst long long __TESTLIB_LONGLONG_MAX = 9223372036854775807LL;\n\nbool\
    \ __testlib_hasTestCase;\nint __testlib_testCase = -1;\n\nvoid setTestCase(int\
    \ testCase) {\n\t__testlib_hasTestCase = true;\n\t__testlib_testCase = testCase;\n\
    }\n\nvoid unsetTestCase() {\n\t__testlib_hasTestCase = false;\n\t__testlib_testCase\
    \ = -1;\n}\n\nNORETURN static void __testlib_fail(const std::string &message);\n\
    \ntemplate<typename T>\nstatic inline T __testlib_abs(const T &x) {\n\treturn\
    \ x > 0 ? x : -x;\n}\n\ntemplate<typename T>\nstatic inline T __testlib_min(const\
    \ T &a, const T &b) {\n\treturn a < b ? a : b;\n}\n\ntemplate<typename T>\nstatic\
    \ inline T __testlib_max(const T &a, const T &b) {\n\treturn a > b ? a : b;\n\
    }\n\nstatic bool __testlib_prelimIsNaN(double r) {\n\tvolatile double ra = r;\n\
    #ifndef __BORLANDC__\n\treturn ((ra != ra) == true) && ((ra == ra) == false) &&\
    \ ((1.0 > ra) == false) && ((1.0 < ra) == false);\n#else\n\treturn std::_isnan(ra);\n\
    #endif\n}\n\nstatic std::string removeDoubleTrailingZeroes(std::string value)\
    \ {\n\twhile (!value.empty() && value[value.length() - 1] == '0' && value.find('.')\
    \ != std::string::npos)\n\t\tvalue = value.substr(0, value.length() - 1);\n\t\
    return value + '0';\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 1,\
    \ 2)))\n#endif\nstd::string format(const char *fmt, ...) {\n\tFMT_TO_RESULT(fmt,\
    \ fmt, result);\n\treturn result;\n}\n\nstd::string format(const std::string fmt,\
    \ ...) {\n\tFMT_TO_RESULT(fmt, fmt.c_str(), result);\n\treturn result;\n}\n\n\
    static std::string __testlib_part(const std::string &s);\n\nstatic bool __testlib_isNaN(double\
    \ r) {\n\t__TESTLIB_STATIC_ASSERT(sizeof(double) == sizeof(long long));\n\tvolatile\
    \ double ra = r;\n\tlong long llr1, llr2;\n\tstd::memcpy((void *) &llr1, (void\
    \ *) &ra, sizeof(double));\n\tra = -ra;\n\tstd::memcpy((void *) &llr2, (void *)\
    \ &ra, sizeof(double));\n\tlong long llnan = 0xFFF8000000000000LL;\n\treturn __testlib_prelimIsNaN(r)\
    \ || llnan == llr1 || llnan == llr2;\n}\n\nstatic double __testlib_nan() {\n\t\
    __TESTLIB_STATIC_ASSERT(sizeof(double) == sizeof(long long));\n#ifndef NAN\n\t\
    long long llnan = 0xFFF8000000000000LL;\n\tdouble nan;\n\tstd::memcpy(&nan, &llnan,\
    \ sizeof(double));\n\treturn nan;\n#else\n\treturn NAN;\n#endif\n}\n\nstatic bool\
    \ __testlib_isInfinite(double r) {\n\tvolatile double ra = r;\n\treturn (ra >\
    \ 1E300 || ra < -1E300);\n}\n\n#ifdef __GNUC__\n__attribute__((const))\n#endif\n\
    inline bool doubleCompare(double expected, double result, double MAX_DOUBLE_ERROR)\
    \ {\n\tif (__testlib_isNaN(expected)) {\n\t\treturn __testlib_isNaN(result);\n\
    \t} else if (__testlib_isInfinite(expected)) {\n\t\tif (expected > 0) {\n\t\t\t\
    return result > 0 && __testlib_isInfinite(result);\n\t\t} else {\n\t\t\treturn\
    \ result < 0 && __testlib_isInfinite(result);\n\t\t}\n\t} else if (__testlib_isNaN(result)\
    \ || __testlib_isInfinite(result)) {\n\t\treturn false;\n\t} else if (__testlib_abs(result\
    \ - expected) <= MAX_DOUBLE_ERROR + 1E-15) {\n\t\treturn true;\n\t} else {\n\t\
    \tdouble minv = __testlib_min(expected * (1.0 - MAX_DOUBLE_ERROR),\n\t\t\t\t\t\
    \t\t\t\texpected * (1.0 + MAX_DOUBLE_ERROR));\n\t\tdouble maxv = __testlib_max(expected\
    \ * (1.0 - MAX_DOUBLE_ERROR),\n\t\t\t\t\t\t\t\t\texpected * (1.0 + MAX_DOUBLE_ERROR));\n\
    \t\treturn result + 1E-15 >= minv && result <= maxv + 1E-15;\n\t}\n}\n\n#ifdef\
    \ __GNUC__\n__attribute__((const))\n#endif\ninline double doubleDelta(double expected,\
    \ double result) {\n\tdouble absolute = __testlib_abs(result - expected);\n\n\t\
    if (__testlib_abs(expected) > 1E-9) {\n\t\tdouble relative = __testlib_abs(absolute\
    \ / expected);\n\t\treturn __testlib_min(absolute, relative);\n\t} else\n\t\t\
    return absolute;\n}\n\n#if !defined(_MSC_VER) || _MSC_VER < 1900\n#ifndef _fileno\n\
    #define _fileno(_stream)  ((_stream)->_file)\n#endif\n#endif\n\n#ifndef O_BINARY\n\
    static void __testlib_set_binary(\n#ifdef __GNUC__\n\t__attribute__((unused))\
    \ \n#endif\n\tstd::FILE* file\n)\n#else\nstatic void __testlib_set_binary(std::FILE\
    \ *file)\n#endif\n{\n#ifdef O_BINARY\n\tif (NULL != file) {\n#ifndef __BORLANDC__\n\
    \t\t_setmode(_fileno(file), O_BINARY);\n#else\n\t\tsetmode(fileno(file), O_BINARY);\n\
    #endif\n\t}\n#endif\n}\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\n/* opts\
    \ */\nvoid prepareOpts(int argc, char* argv[]);\n#endif\n\n/*\n * Very simple\
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
    )\".\n */\nclass random_t;\n\nclass pattern {\npublic:\n\t/* Create pattern instance\
    \ by string. */\n\tpattern(std::string s);\n\n\t/* Generate new string by pattern\
    \ and given random_t. */\n\tstd::string next(random_t &rnd) const;\n\n\t/* Checks\
    \ if given string match the pattern. */\n\tbool matches(const std::string &s)\
    \ const;\n\n\t/* Returns source string of the pattern. */\n\tstd::string src()\
    \ const;\n\nprivate:\n\tbool matches(const std::string &s, size_t pos) const;\n\
    \n\tstd::string s;\n\tstd::vector<pattern> children;\n\tstd::vector<char> chars;\n\
    \tint from;\n\tint to;\n};\n\n/* \n * Use random_t instances to generate random\
    \ values. It is preffered\n * way to use randoms instead of rand() function or\
    \ self-written \n * randoms.\n *\n * Testlib defines global variable \"rnd\" of\
    \ random_t class.\n * Use registerGen(argc, argv, 1) to setup random_t seed be\
    \ command\n * line (to use latest random generator version).\n *\n * Random generates\
    \ uniformly distributed values if another strategy is\n * not specified explicitly.\n\
    \ */\nclass random_t {\nprivate:\n\tunsigned long long seed;\n\tstatic const unsigned\
    \ long long multiplier;\n\tstatic const unsigned long long addend;\n\tstatic const\
    \ unsigned long long mask;\n\tstatic const int lim;\n\n\tlong long nextBits(int\
    \ bits) {\n\t\tif (bits <= 48) {\n\t\t\tseed = (seed * multiplier + addend) &\
    \ mask;\n\t\t\treturn (long long) (seed >> (48 - bits));\n\t\t} else {\n\t\t\t\
    if (bits > 63)\n\t\t\t\t__testlib_fail(\"random_t::nextBits(int bits): n must\
    \ be less than 64\");\n\n\t\t\tint lowerBitCount = (random_t::version == 0 ? 31\
    \ : 32);\n\n\t\t\tlong long left = (nextBits(31) << 32);\n\t\t\tlong long right\
    \ = nextBits(lowerBitCount);\n\n\t\t\treturn left ^ right;\n\t\t}\n\t}\n\npublic:\n\
    \tstatic int version;\n\n\t/* New random_t with fixed seed. */\n\trandom_t()\n\
    \t\t\t: seed(3905348978240129619LL) {\n\t}\n\n\t/* Sets seed by command line.\
    \ */\n\tvoid setSeed(int argc, char *argv[]) {\n\t\trandom_t p;\n\n\t\tseed =\
    \ 3905348978240129619LL;\n\t\tfor (int i = 1; i < argc; i++) {\n\t\t\tstd::size_t\
    \ le = std::strlen(argv[i]);\n\t\t\tfor (std::size_t j = 0; j < le; j++)\n\t\t\
    \t\tseed = seed * multiplier + (unsigned int) (argv[i][j]) + addend;\n\t\t\tseed\
    \ += multiplier / addend;\n\t\t}\n\n\t\tseed = seed & mask;\n\t}\n\n\t/* Sets\
    \ seed by given value. */\n\tvoid setSeed(long long _seed) {\n\t\t_seed = (_seed\
    \ ^ multiplier) & mask;\n\t\tseed = _seed;\n\t}\n\n#ifndef __BORLANDC__\n\n\t\
    /* Random string value by given pattern (see pattern documentation). */\n\tstd::string\
    \ next(const std::string &ptrn) {\n\t\tpattern p(ptrn);\n\t\treturn p.next(*this);\n\
    \t}\n\n#else\n\t/* Random string value by given pattern (see pattern documentation).\
    \ */\n\tstd::string next(std::string ptrn)\n\t{\n\t\tpattern p(ptrn);\n\t\treturn\
    \ p.next(*this);\n\t}\n#endif\n\n\t/* Random value in range [0, n-1]. */\n\tint\
    \ next(int n) {\n\t\tif (n <= 0)\n\t\t\t__testlib_fail(\"random_t::next(int n):\
    \ n must be positive\");\n\n\t\tif ((n & -n) == n)  // n is a power of 2\n\t\t\
    \treturn (int) ((n * (long long) nextBits(31)) >> 31);\n\n\t\tconst long long\
    \ limit = INT_MAX / n * n;\n\n\t\tlong long bits;\n\t\tdo {\n\t\t\tbits = nextBits(31);\n\
    \t\t} while (bits >= limit);\n\n\t\treturn int(bits % n);\n\t}\n\n\t/* Random\
    \ value in range [0, n-1]. */\n\tunsigned int next(unsigned int n) {\n\t\tif (n\
    \ >= INT_MAX)\n\t\t\t__testlib_fail(\"random_t::next(unsigned int n): n must be\
    \ less INT_MAX\");\n\t\treturn (unsigned int) next(int(n));\n\t}\n\n\t/* Random\
    \ value in range [0, n-1]. */\n\tlong long next(long long n) {\n\t\tif (n <= 0)\n\
    \t\t\t__testlib_fail(\"random_t::next(long long n): n must be positive\");\n\n\
    \t\tconst long long limit = __TESTLIB_LONGLONG_MAX / n * n;\n\n\t\tlong long bits;\n\
    \t\tdo {\n\t\t\tbits = nextBits(63);\n\t\t} while (bits >= limit);\n\n\t\treturn\
    \ bits % n;\n\t}\n\n\t/* Random value in range [0, n-1]. */\n\tunsigned long long\
    \ next(unsigned long long n) {\n\t\tif (n >= (unsigned long long) (__TESTLIB_LONGLONG_MAX))\n\
    \t\t\t__testlib_fail(\"random_t::next(unsigned long long n): n must be less LONGLONG_MAX\"\
    );\n\t\treturn (unsigned long long) next((long long) (n));\n\t}\n\n\t/* Random\
    \ value in range [0, n-1]. */\n\tlong next(long n) {\n\t\treturn (long) next((long\
    \ long) (n));\n\t}\n\n\t/* Random value in range [0, n-1]. */\n\tunsigned long\
    \ next(unsigned long n) {\n\t\tif (n >= (unsigned long) (LONG_MAX))\n\t\t\t__testlib_fail(\"\
    random_t::next(unsigned long n): n must be less LONG_MAX\");\n\t\treturn (unsigned\
    \ long) next((unsigned long long) (n));\n\t}\n\n\t/* Returns random value in range\
    \ [from,to]. */\n\tint next(int from, int to) {\n\t\treturn int(next((long long)\
    \ to - from + 1) + from);\n\t}\n\n\t/* Returns random value in range [from,to].\
    \ */\n\tunsigned int next(unsigned int from, unsigned int to) {\n\t\treturn (unsigned\
    \ int) (next((long long) to - from + 1) + from);\n\t}\n\n\t/* Returns random value\
    \ in range [from,to]. */\n\tlong long next(long long from, long long to) {\n\t\
    \treturn next(to - from + 1) + from;\n\t}\n\n\t/* Returns random value in range\
    \ [from,to]. */\n\tunsigned long long next(unsigned long long from, unsigned long\
    \ long to) {\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"random_t::next(unsigned\
    \ long long from, unsigned long long to): from can't not exceed to\");\n\t\treturn\
    \ next(to - from + 1) + from;\n\t}\n\n\t/* Returns random value in range [from,to].\
    \ */\n\tlong next(long from, long to) {\n\t\treturn next(to - from + 1) + from;\n\
    \t}\n\n\t/* Returns random value in range [from,to]. */\n\tunsigned long next(unsigned\
    \ long from, unsigned long to) {\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"\
    random_t::next(unsigned long from, unsigned long to): from can't not exceed to\"\
    );\n\t\treturn next(to - from + 1) + from;\n\t}\n\n\t/* Random double value in\
    \ range [0, 1). */\n\tdouble next() {\n\t\tlong long left = ((long long) (nextBits(26))\
    \ << 27);\n\t\tlong long right = nextBits(27);\n\t\treturn (double) (left + right)\
    \ / (double) (1LL << 53);\n\t}\n\n\t/* Random double value in range [0, n). */\n\
    \tdouble next(double n) {\n\t\treturn n * next();\n\t}\n\n\t/* Random double value\
    \ in range [from, to). */\n\tdouble next(double from, double to) {\n\t\tif (from\
    \ > to)\n\t\t\t__testlib_fail(\"random_t::next(double from, double to): from can't\
    \ not exceed to\");\n\t\treturn next(to - from) + from;\n\t}\n\n\t/* Returns random\
    \ element from container. */\n\ttemplate<typename Container>\n\ttypename Container::value_type\
    \ any(const Container &c) {\n\t\tsize_t size = c.size();\n\t\tif (size <= 0)\n\
    \t\t\t__testlib_fail(\"random_t::any(const Container& c): c.size() must be positive\"\
    );\n\t\treturn *(c.begin() + next(size));\n\t}\n\n\t/* Returns random element\
    \ from iterator range. */\n\ttemplate<typename Iter>\n\ttypename Iter::value_type\
    \ any(const Iter &begin, const Iter &end) {\n\t\tint size = int(end - begin);\n\
    \t\tif (size <= 0)\n\t\t\t__testlib_fail(\"random_t::any(const Iter& begin, const\
    \ Iter& end): range must have positive length\");\n\t\treturn *(begin + next(size));\n\
    \t}\n\n\t/* Random string value by given pattern (see pattern documentation).\
    \ */\n#ifdef __GNUC__\n\t__attribute__ ((format (printf, 2, 3)))\n#endif\n\tstd::string\
    \ next(const char *format, ...) {\n\t\tFMT_TO_RESULT(format, format, ptrn);\n\t\
    \treturn next(ptrn);\n\t}\n\n\t/* \n\t * Weighted next. If type == 0 than it is\
    \ usual \"next()\".\n\t *\n\t * If type = 1, than it returns \"max(next(), next())\"\
    \n\t * (the number of \"max\" functions equals to \"type\").\n\t *\n\t * If type\
    \ < 0, than \"max\" function replaces with \"min\".\n\t */\n\tint wnext(int n,\
    \ int type) {\n\t\tif (n <= 0)\n\t\t\t__testlib_fail(\"random_t::wnext(int n,\
    \ int type): n must be positive\");\n\n\t\tif (abs(type) < random_t::lim) {\n\t\
    \t\tint result = next(n);\n\n\t\t\tfor (int i = 0; i < +type; i++)\n\t\t\t\tresult\
    \ = __testlib_max(result, next(n));\n\n\t\t\tfor (int i = 0; i < -type; i++)\n\
    \t\t\t\tresult = __testlib_min(result, next(n));\n\n\t\t\treturn result;\n\t\t\
    } else {\n\t\t\tdouble p;\n\n\t\t\tif (type > 0)\n\t\t\t\tp = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n\t\t\telse\n\t\t\t\tp = 1 - std::pow(next() + 0.0,\
    \ 1.0 / (-type + 1));\n\n\t\t\treturn int(n * p);\n\t\t}\n\t}\n\n\t/* See wnext(int,\
    \ int). It uses the same algorithms. */\n\tlong long wnext(long long n, int type)\
    \ {\n\t\tif (n <= 0)\n\t\t\t__testlib_fail(\"random_t::wnext(long long n, int\
    \ type): n must be positive\");\n\n\t\tif (abs(type) < random_t::lim) {\n\t\t\t\
    long long result = next(n);\n\n\t\t\tfor (int i = 0; i < +type; i++)\n\t\t\t\t\
    result = __testlib_max(result, next(n));\n\n\t\t\tfor (int i = 0; i < -type; i++)\n\
    \t\t\t\tresult = __testlib_min(result, next(n));\n\n\t\t\treturn result;\n\t\t\
    } else {\n\t\t\tdouble p;\n\n\t\t\tif (type > 0)\n\t\t\t\tp = std::pow(next()\
    \ + 0.0, 1.0 / (type + 1));\n\t\t\telse\n\t\t\t\tp = std::pow(next() + 0.0, -type\
    \ + 1);\n\n\t\t\treturn __testlib_min(__testlib_max((long long) (double(n) * p),\
    \ 0LL), n - 1LL);\n\t\t}\n\t}\n\n\t/* See wnext(int, int). It uses the same algorithms.\
    \ */\n\tdouble wnext(int type) {\n\t\tif (abs(type) < random_t::lim) {\n\t\t\t\
    double result = next();\n\n\t\t\tfor (int i = 0; i < +type; i++)\n\t\t\t\tresult\
    \ = __testlib_max(result, next());\n\n\t\t\tfor (int i = 0; i < -type; i++)\n\t\
    \t\t\tresult = __testlib_min(result, next());\n\n\t\t\treturn result;\n\t\t} else\
    \ {\n\t\t\tdouble p;\n\n\t\t\tif (type > 0)\n\t\t\t\tp = std::pow(next() + 0.0,\
    \ 1.0 / (type + 1));\n\t\t\telse\n\t\t\t\tp = std::pow(next() + 0.0, -type + 1);\n\
    \n\t\t\treturn p;\n\t\t}\n\t}\n\n\t/* See wnext(int, int). It uses the same algorithms.\
    \ */\n\tdouble wnext(double n, int type) {\n\t\tif (n <= 0)\n\t\t\t__testlib_fail(\"\
    random_t::wnext(double n, int type): n must be positive\");\n\n\t\tif (abs(type)\
    \ < random_t::lim) {\n\t\t\tdouble result = next();\n\n\t\t\tfor (int i = 0; i\
    \ < +type; i++)\n\t\t\t\tresult = __testlib_max(result, next());\n\n\t\t\tfor\
    \ (int i = 0; i < -type; i++)\n\t\t\t\tresult = __testlib_min(result, next());\n\
    \n\t\t\treturn n * result;\n\t\t} else {\n\t\t\tdouble p;\n\n\t\t\tif (type >\
    \ 0)\n\t\t\t\tp = std::pow(next() + 0.0, 1.0 / (type + 1));\n\t\t\telse\n\t\t\t\
    \tp = std::pow(next() + 0.0, -type + 1);\n\n\t\t\treturn n * p;\n\t\t}\n\t}\n\n\
    \t/* See wnext(int, int). It uses the same algorithms. */\n\tunsigned int wnext(unsigned\
    \ int n, int type) {\n\t\tif (n >= INT_MAX)\n\t\t\t__testlib_fail(\"random_t::wnext(unsigned\
    \ int n, int type): n must be less INT_MAX\");\n\t\treturn (unsigned int) wnext(int(n),\
    \ type);\n\t}\n\n\t/* See wnext(int, int). It uses the same algorithms. */\n\t\
    unsigned long long wnext(unsigned long long n, int type) {\n\t\tif (n >= (unsigned\
    \ long long) (__TESTLIB_LONGLONG_MAX))\n\t\t\t__testlib_fail(\"random_t::wnext(unsigned\
    \ long long n, int type): n must be less LONGLONG_MAX\");\n\n\t\treturn (unsigned\
    \ long long) wnext((long long) (n), type);\n\t}\n\n\t/* See wnext(int, int). It\
    \ uses the same algorithms. */\n\tlong wnext(long n, int type) {\n\t\treturn (long)\
    \ wnext((long long) (n), type);\n\t}\n\n\t/* See wnext(int, int). It uses the\
    \ same algorithms. */\n\tunsigned long wnext(unsigned long n, int type) {\n\t\t\
    if (n >= (unsigned long) (LONG_MAX))\n\t\t\t__testlib_fail(\"random_t::wnext(unsigned\
    \ long n, int type): n must be less LONG_MAX\");\n\n\t\treturn (unsigned long)\
    \ wnext((unsigned long long) (n), type);\n\t}\n\n\t/* Returns weighted random\
    \ value in range [from, to]. */\n\tint wnext(int from, int to, int type) {\n\t\
    \tif (from > to)\n\t\t\t__testlib_fail(\"random_t::wnext(int from, int to, int\
    \ type): from can't not exceed to\");\n\t\treturn wnext(to - from + 1, type) +\
    \ from;\n\t}\n\n\t/* Returns weighted random value in range [from, to]. */\n\t\
    int wnext(unsigned int from, unsigned int to, int type) {\n\t\tif (from > to)\n\
    \t\t\t__testlib_fail(\"random_t::wnext(unsigned int from, unsigned int to, int\
    \ type): from can't not exceed to\");\n\t\treturn int(wnext(to - from + 1, type)\
    \ + from);\n\t}\n\n\t/* Returns weighted random value in range [from, to]. */\n\
    \tlong long wnext(long long from, long long to, int type) {\n\t\tif (from > to)\n\
    \t\t\t__testlib_fail(\"random_t::wnext(long long from, long long to, int type):\
    \ from can't not exceed to\");\n\t\treturn wnext(to - from + 1, type) + from;\n\
    \t}\n\n\t/* Returns weighted random value in range [from, to]. */\n\tunsigned\
    \ long long wnext(unsigned long long from, unsigned long long to, int type) {\n\
    \t\tif (from > to)\n\t\t\t__testlib_fail(\n\t\t\t\t\t\"random_t::wnext(unsigned\
    \ long long from, unsigned long long to, int type): from can't not exceed to\"\
    );\n\t\treturn wnext(to - from + 1, type) + from;\n\t}\n\n\t/* Returns weighted\
    \ random value in range [from, to]. */\n\tlong wnext(long from, long to, int type)\
    \ {\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"random_t::wnext(long from, long\
    \ to, int type): from can't not exceed to\");\n\t\treturn wnext(to - from + 1,\
    \ type) + from;\n\t}\n\n\t/* Returns weighted random value in range [from, to].\
    \ */\n\tunsigned long wnext(unsigned long from, unsigned long to, int type) {\n\
    \t\tif (from > to)\n\t\t\t__testlib_fail(\"random_t::wnext(unsigned long from,\
    \ unsigned long to, int type): from can't not exceed to\");\n\t\treturn wnext(to\
    \ - from + 1, type) + from;\n\t}\n\n\t/* Returns weighted random double value\
    \ in range [from, to). */\n\tdouble wnext(double from, double to, int type) {\n\
    \t\tif (from > to)\n\t\t\t__testlib_fail(\"random_t::wnext(double from, double\
    \ to, int type): from can't not exceed to\");\n\t\treturn wnext(to - from, type)\
    \ + from;\n\t}\n\n\t/* Returns weighted random element from container. */\n\t\
    template<typename Container>\n\ttypename Container::value_type wany(const Container\
    \ &c, int type) {\n\t\tsize_t size = c.size();\n\t\tif (size <= 0)\n\t\t\t__testlib_fail(\"\
    random_t::wany(const Container& c, int type): c.size() must be positive\");\n\t\
    \treturn *(c.begin() + wnext(size, type));\n\t}\n\n\t/* Returns weighted random\
    \ element from iterator range. */\n\ttemplate<typename Iter>\n\ttypename Iter::value_type\
    \ wany(const Iter &begin, const Iter &end, int type) {\n\t\tint size = int(end\
    \ - begin);\n\t\tif (size <= 0)\n\t\t\t__testlib_fail(\n\t\t\t\t\t\"random_t::any(const\
    \ Iter& begin, const Iter& end, int type): range must have positive length\");\n\
    \t\treturn *(begin + wnext(size, type));\n\t}\n\n\t/* Returns random permutation\
    \ of the given size (values are between `first` and `first`+size-1)*/\n\ttemplate<typename\
    \ T, typename E>\n\tstd::vector<E> perm(T size, E first) {\n\t\tif (size <= 0)\n\
    \t\t\t__testlib_fail(\"random_t::perm(T size, E first = 0): size must be positive\"\
    );\n\t\tstd::vector<E> p(size);\n\t\tE current = first;\n\t\tfor (T i = 0; i <\
    \ size; i++)\n\t\t\tp[i] = current++;\n\t\tif (size > 1)\n\t\t\tfor (T i = 1;\
    \ i < size; i++)\n\t\t\t\tstd::swap(p[i], p[next(i + 1)]);\n\t\treturn p;\n\t\
    }\n\n\t/* Returns random permutation of the given size (values are between 0 and\
    \ size-1)*/\n\ttemplate<typename T>\n\tstd::vector<T> perm(T size) {\n\t\treturn\
    \ perm(size, T(0));\n\t}\n\t\n\t/* Returns `size` unordered (unsorted) distinct\
    \ numbers between `from` and `to`. */\n\ttemplate<typename T>\n\tstd::vector<T>\
    \ distinct(int size, T from, T to) {\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"\
    random_t::distinct expected from <= to\");\n\n\t\tif (size < 0)\n\t\t\t__testlib_fail(\"\
    random_t::distinct expected size >= 0\");\n\n\t\tuint64_t n = to - from + 1;\n\
    \t\tif (uint64_t(size) > n)\n\t\t\t__testlib_fail(\"random_t::distinct expected\
    \ size <= to - from + 1\");\n\n\t\tstd::vector<T> result;\n\t\tif (size == 0)\n\
    \t\t\treturn result;\n\n\t\tdouble expected = 0.0;\n\t\tfor (int i = 1; i <= size;\
    \ i++)\n\t\t\texpected += double(n) / double(n - i + 1);\n\t\t\n\t\tif (expected\
    \ < double(n)) {\n\t\t\tstd::set<T> vals;\n\t\t\twhile (int(vals.size()) < size)\n\
    \t\t\t\tvals.insert(T(next(from, to)));\n\t\t\tresult.insert(result.end(), vals.begin(),\
    \ vals.end());\n\t\t} else {\n\t\t\tif (n > 1000000000)\n\t\t\t\t__testlib_fail(\"\
    random_t::distinct here expected to - from + 1 <= 1000000000\");\n\t\t\tstd::vector<T>\
    \ p(perm(int(n), from));\n\t\t\tresult.insert(result.end(), p.begin(), p.begin()\
    \ + size);\n\t\t}\n\n\t\treturn result;\n\t}\n\n\t/* Returns `size` unordered\
    \ (unsorted) distinct numbers between `0` and `upper`-1. */\n\ttemplate<typename\
    \ T>\n\tstd::vector<T> distinct(int size, T upper) {\n\t\tif (size < 0)\n\t\t\t\
    __testlib_fail(\"random_t::distinct expected size >= 0\");\n\t\tif (size == 0)\n\
    \t\t\treturn std::vector<T>();\n\t\t\n\t\tif (upper <= 0)\n\t\t\t__testlib_fail(\"\
    random_t::distinct expected upper > 0\");\n\t\tif (size > upper)\n\t\t\t__testlib_fail(\"\
    random_t::distinct expected size <= upper\");\n\t\t\t\n\t\treturn distinct(size,\
    \ T(0), upper - 1);\n\t}\n\n\t/* Returns random (unsorted) partition which is\
    \ a representation of sum as a sum of integers not less than min_part. */\n\t\
    template<typename T>\n\tstd::vector<T> partition(int size, T sum, T min_part)\
    \ {\n\t\tif (size < 0)\n\t\t\t__testlib_fail(\"random_t::partition: size < 0\"\
    );\n\t\tif (size == 0 && sum != 0)\n\t\t\t__testlib_fail(\"random_t::partition:\
    \ size == 0 && sum != 0\");\n\t\tif (min_part * size > sum)\n\t\t\t__testlib_fail(\"\
    random_t::partition: min_part * size > sum\");\n\n\t\tT sum_ = sum;\n\t\tsum -=\
    \ min_part * size;\n\n\t\tstd::vector<T> septums(size);\n\t\tstd::vector<T> d\
    \ = distinct(size - 1, T(1), T(sum + size - 1));\n\t\tfor (int i = 0; i + 1 <\
    \ size; i++)\n\t\t\tseptums[i + 1] = d[i];\n\t\tsort(septums.begin(), septums.end());\n\
    \n\t\tstd::vector<T> result(size);\n\t\tfor (int i = 0; i + 1 < size; i++)\n\t\
    \t\tresult[i] = septums[i + 1] - septums[i] - 1;\n\t\tresult[size - 1] = sum +\
    \ size - 1 - septums.back();\n\n\t\tfor (std::size_t i = 0; i < result.size();\
    \ i++)\n\t\t\tresult[i] += min_part;\n\t\t\n\t\tT result_sum = 0;\n\t\tfor (std::size_t\
    \ i = 0; i < result.size(); i++)\n\t\t\tresult_sum += result[i];\n\t\tif (result_sum\
    \ != sum_)\n\t\t\t__testlib_fail(\"random_t::partition: partition sum is expeced\
    \ to be the given sum\");\n\t\t\n\t\tif (*std::min_element(result.begin(), result.end())\
    \ < min_part)\n\t\t\t__testlib_fail(\"random_t::partition: partition min is expeced\
    \ to be to less than the given min_part\");\n\t\t\n\t\tif (int(result.size())\
    \ != size || result.size() != (size_t) size)\n\t\t\t__testlib_fail(\"random_t::partition:\
    \ partition size is expected to be equal to the given size\");\n\t\t\n\t\treturn\
    \ result;\n\t}\n\n\t/* Returns random (unsorted) partition which is a representation\
    \ of sum as a sum of positive integers. */\n\ttemplate<typename T>\n\tstd::vector<T>\
    \ partition(int size, T sum) {\n\t\treturn partition(size, sum, T(1));\n\t}\n\
    };\n\nconst int random_t::lim = 25;\nconst unsigned long long random_t::multiplier\
    \ = 0x5DEECE66DLL;\nconst unsigned long long random_t::addend = 0xBLL;\nconst\
    \ unsigned long long random_t::mask = (1LL << 48) - 1;\nint random_t::version\
    \ = -1;\n\n/* Pattern implementation */\nbool pattern::matches(const std::string\
    \ &s) const {\n\treturn matches(s, 0);\n}\n\nstatic bool __pattern_isSlash(const\
    \ std::string &s, size_t pos) {\n\treturn s[pos] == '\\\\';\n}\n\n#ifdef __GNUC__\n\
    __attribute__((pure))\n#endif\nstatic bool __pattern_isCommandChar(const std::string\
    \ &s, size_t pos, char value) {\n\tif (pos >= s.length())\n\t\treturn false;\n\
    \n\tint slashes = 0;\n\n\tint before = int(pos) - 1;\n\twhile (before >= 0 &&\
    \ s[before] == '\\\\')\n\t\tbefore--, slashes++;\n\n\treturn slashes % 2 == 0\
    \ && s[pos] == value;\n}\n\nstatic char __pattern_getChar(const std::string &s,\
    \ size_t &pos) {\n\tif (__pattern_isSlash(s, pos))\n\t\tpos += 2;\n\telse\n\t\t\
    pos++;\n\n\treturn s[pos - 1];\n}\n\n#ifdef __GNUC__\n__attribute__((pure))\n\
    #endif\nstatic int __pattern_greedyMatch(const std::string &s, size_t pos, const\
    \ std::vector<char> chars) {\n\tint result = 0;\n\n\twhile (pos < s.length())\
    \ {\n\t\tchar c = s[pos++];\n\t\tif (!std::binary_search(chars.begin(), chars.end(),\
    \ c))\n\t\t\tbreak;\n\t\telse\n\t\t\tresult++;\n\t}\n\n\treturn result;\n}\n\n\
    std::string pattern::src() const {\n\treturn s;\n}\n\nbool pattern::matches(const\
    \ std::string &s, size_t pos) const {\n\tstd::string result;\n\n\tif (to > 0)\
    \ {\n\t\tint size = __pattern_greedyMatch(s, pos, chars);\n\t\tif (size < from)\n\
    \t\t\treturn false;\n\t\tif (size > to)\n\t\t\tsize = to;\n\t\tpos += size;\n\t\
    }\n\n\tif (children.size() > 0) {\n\t\tfor (size_t child = 0; child < children.size();\
    \ child++)\n\t\t\tif (children[child].matches(s, pos))\n\t\t\t\treturn true;\n\
    \t\treturn false;\n\t} else\n\t\treturn pos == s.length();\n}\n\nstd::string pattern::next(random_t\
    \ &rnd) const {\n\tstd::string result;\n\tresult.reserve(20);\n\n\tif (to == INT_MAX)\n\
    \t\t__testlib_fail(\"pattern::next(random_t& rnd): can't process character '*'\
    \ for generation\");\n\n\tif (to > 0) {\n\t\tint count = rnd.next(to - from +\
    \ 1) + from;\n\t\tfor (int i = 0; i < count; i++)\n\t\t\tresult += chars[rnd.next(int(chars.size()))];\n\
    \t}\n\n\tif (children.size() > 0) {\n\t\tint child = rnd.next(int(children.size()));\n\
    \t\tresult += children[child].next(rnd);\n\t}\n\n\treturn result;\n}\n\nstatic\
    \ void __pattern_scanCounts(const std::string &s, size_t &pos, int &from, int\
    \ &to) {\n\tif (pos >= s.length()) {\n\t\tfrom = to = 1;\n\t\treturn;\n\t}\n\n\
    \tif (__pattern_isCommandChar(s, pos, '{')) {\n\t\tstd::vector<std::string> parts;\n\
    \t\tstd::string part;\n\n\t\tpos++;\n\n\t\twhile (pos < s.length() && !__pattern_isCommandChar(s,\
    \ pos, '}')) {\n\t\t\tif (__pattern_isCommandChar(s, pos, ','))\n\t\t\t\tparts.push_back(part),\
    \ part = \"\", pos++;\n\t\t\telse\n\t\t\t\tpart += __pattern_getChar(s, pos);\n\
    \t\t}\n\n\t\tif (part != \"\")\n\t\t\tparts.push_back(part);\n\n\t\tif (!__pattern_isCommandChar(s,\
    \ pos, '}'))\n\t\t\t__testlib_fail(\"pattern: Illegal pattern (or part) \\\"\"\
    \ + s + \"\\\"\");\n\n\t\tpos++;\n\n\t\tif (parts.size() < 1 || parts.size() >\
    \ 2)\n\t\t\t__testlib_fail(\"pattern: Illegal pattern (or part) \\\"\" + s + \"\
    \\\"\");\n\n\t\tstd::vector<int> numbers;\n\n\t\tfor (size_t i = 0; i < parts.size();\
    \ i++) {\n\t\t\tif (parts[i].length() == 0)\n\t\t\t\t__testlib_fail(\"pattern:\
    \ Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\t\t\tint number;\n\t\t\t\
    if (std::sscanf(parts[i].c_str(), \"%d\", &number) != 1)\n\t\t\t\t__testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\t\t\tnumbers.push_back(number);\n\
    \t\t}\n\n\t\tif (numbers.size() == 1)\n\t\t\tfrom = to = numbers[0];\n\t\telse\n\
    \t\t\tfrom = numbers[0], to = numbers[1];\n\n\t\tif (from > to)\n\t\t\t__testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\t} else {\n\t\tif\
    \ (__pattern_isCommandChar(s, pos, '?')) {\n\t\t\tfrom = 0, to = 1, pos++;\n\t\
    \t\treturn;\n\t\t}\n\n\t\tif (__pattern_isCommandChar(s, pos, '*')) {\n\t\t\t\
    from = 0, to = INT_MAX, pos++;\n\t\t\treturn;\n\t\t}\n\n\t\tif (__pattern_isCommandChar(s,\
    \ pos, '+')) {\n\t\t\tfrom = 1, to = INT_MAX, pos++;\n\t\t\treturn;\n\t\t}\n\n\
    \t\tfrom = to = 1;\n\t}\n}\n\nstatic std::vector<char> __pattern_scanCharSet(const\
    \ std::string &s, size_t &pos) {\n\tif (pos >= s.length())\n\t\t__testlib_fail(\"\
    pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n\tstd::vector<char>\
    \ result;\n\n\tif (__pattern_isCommandChar(s, pos, '[')) {\n\t\tpos++;\n\t\tbool\
    \ negative = __pattern_isCommandChar(s, pos, '^');\n\n\t\tchar prev = 0;\n\n\t\
    \twhile (pos < s.length() && !__pattern_isCommandChar(s, pos, ']')) {\n\t\t\t\
    if (__pattern_isCommandChar(s, pos, '-') && prev != 0) {\n\t\t\t\tpos++;\n\n\t\
    \t\t\tif (pos + 1 == s.length() || __pattern_isCommandChar(s, pos, ']')) {\n\t\
    \t\t\t\tresult.push_back(prev);\n\t\t\t\t\tprev = '-';\n\t\t\t\t\tcontinue;\n\t\
    \t\t\t}\n\n\t\t\t\tchar next = __pattern_getChar(s, pos);\n\t\t\t\tif (prev >\
    \ next)\n\t\t\t\t\t__testlib_fail(\"pattern: Illegal pattern (or part) \\\"\"\
    \ + s + \"\\\"\");\n\n\t\t\t\tfor (char c = prev; c != next; c++)\n\t\t\t\t\t\
    result.push_back(c);\n\t\t\t\tresult.push_back(next);\n\n\t\t\t\tprev = 0;\n\t\
    \t\t} else {\n\t\t\t\tif (prev != 0)\n\t\t\t\t\tresult.push_back(prev);\n\t\t\t\
    \tprev = __pattern_getChar(s, pos);\n\t\t\t}\n\t\t}\n\n\t\tif (prev != 0)\n\t\t\
    \tresult.push_back(prev);\n\n\t\tif (!__pattern_isCommandChar(s, pos, ']'))\n\t\
    \t\t__testlib_fail(\"pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\"\
    );\n\n\t\tpos++;\n\n\t\tif (negative) {\n\t\t\tstd::sort(result.begin(), result.end());\n\
    \t\t\tstd::vector<char> actuals;\n\t\t\tfor (int code = 0; code < 255; code++)\
    \ {\n\t\t\t\tchar c = char(code);\n\t\t\t\tif (!std::binary_search(result.begin(),\
    \ result.end(), c))\n\t\t\t\t\tactuals.push_back(c);\n\t\t\t}\n\t\t\tresult =\
    \ actuals;\n\t\t}\n\n\t\tstd::sort(result.begin(), result.end());\n\t} else\n\t\
    \tresult.push_back(__pattern_getChar(s, pos));\n\n\treturn result;\n}\n\npattern::pattern(std::string\
    \ s) : s(s), from(0), to(0) {\n\tstd::string t;\n\tfor (size_t i = 0; i < s.length();\
    \ i++)\n\t\tif (!__pattern_isCommandChar(s, i, ' '))\n\t\t\tt += s[i];\n\ts =\
    \ t;\n\n\tint opened = 0;\n\tint firstClose = -1;\n\tstd::vector<int> seps;\n\n\
    \tfor (size_t i = 0; i < s.length(); i++) {\n\t\tif (__pattern_isCommandChar(s,\
    \ i, '(')) {\n\t\t\topened++;\n\t\t\tcontinue;\n\t\t}\n\n\t\tif (__pattern_isCommandChar(s,\
    \ i, ')')) {\n\t\t\topened--;\n\t\t\tif (opened == 0 && firstClose == -1)\n\t\t\
    \t\tfirstClose = int(i);\n\t\t\tcontinue;\n\t\t}\n\n\t\tif (opened < 0)\n\t\t\t\
    __testlib_fail(\"pattern: Illegal pattern (or part) \\\"\" + s + \"\\\"\");\n\n\
    \t\tif (__pattern_isCommandChar(s, i, '|') && opened == 0)\n\t\t\tseps.push_back(int(i));\n\
    \t}\n\n\tif (opened != 0)\n\t\t__testlib_fail(\"pattern: Illegal pattern (or part)\
    \ \\\"\" + s + \"\\\"\");\n\n\tif (seps.size() == 0 && firstClose + 1 == (int)\
    \ s.length()\n\t\t&& __pattern_isCommandChar(s, 0, '(') && __pattern_isCommandChar(s,\
    \ s.length() - 1, ')')) {\n\t\tchildren.push_back(pattern(s.substr(1, s.length()\
    \ - 2)));\n\t} else {\n\t\tif (seps.size() > 0) {\n\t\t\tseps.push_back(int(s.length()));\n\
    \t\t\tint last = 0;\n\n\t\t\tfor (size_t i = 0; i < seps.size(); i++) {\n\t\t\t\
    \tchildren.push_back(pattern(s.substr(last, seps[i] - last)));\n\t\t\t\tlast =\
    \ seps[i] + 1;\n\t\t\t}\n\t\t} else {\n\t\t\tsize_t pos = 0;\n\t\t\tchars = __pattern_scanCharSet(s,\
    \ pos);\n\t\t\t__pattern_scanCounts(s, pos, from, to);\n\t\t\tif (pos < s.length())\n\
    \t\t\t\tchildren.push_back(pattern(s.substr(pos)));\n\t\t}\n\t}\n}\n\n/* End of\
    \ pattern implementation */\n\ntemplate<typename C>\ninline bool isEof(C c) {\n\
    \treturn c == EOFC;\n}\n\ntemplate<typename C>\ninline bool isEoln(C c) {\n\t\
    return (c == LF || c == CR);\n}\n\ntemplate<typename C>\ninline bool isBlanks(C\
    \ c) {\n\treturn (c == LF || c == CR || c == SPACE || c == TAB);\n}\n\ninline\
    \ std::string trim(const std::string &s) {\n\tif (s.empty())\n\t\treturn s;\n\n\
    \tint left = 0;\n\twhile (left < int(s.length()) && isBlanks(s[left]))\n\t\tleft++;\n\
    \tif (left >= int(s.length()))\n\t\treturn \"\";\n\n\tint right = int(s.length())\
    \ - 1;\n\twhile (right >= 0 && isBlanks(s[right]))\n\t\tright--;\n\tif (right\
    \ < 0)\n\t\treturn \"\";\n\n\treturn s.substr(left, right - left + 1);\n}\n\n\
    enum TMode {\n\t_input, _output, _answer\n};\n\n/* Outcomes 6-15 are reserved\
    \ for future use. */\nenum TResult {\n\t_ok = 0,\n\t_wa = 1,\n\t_pe = 2,\n\t_fail\
    \ = 3,\n\t_dirt = 4,\n\t_points = 5,\n\t_unexpected_eof = 8,\n\t_partially = 16\n\
    };\n\nenum TTestlibMode {\n\t_unknown, _checker, _validator, _generator, _interactor\n\
    };\n\n#define _pc(exitCode) (TResult(_partially + (exitCode)))\n\n/* Outcomes\
    \ 6-15 are reserved for future use. */\nconst std::string outcomes[] = {\n\t\t\
    \"accepted\",\n\t\t\"wrong-answer\",\n\t\t\"presentation-error\",\n\t\t\"fail\"\
    ,\n\t\t\"fail\",\n#ifndef PCMS2\n\t\t\"points\",\n#else\n\t\t\"relative-scoring\"\
    ,\n#endif\n\t\t\"reserved\",\n\t\t\"reserved\",\n\t\t\"unexpected-eof\",\n\t\t\
    \"reserved\",\n\t\t\"reserved\",\n\t\t\"reserved\",\n\t\t\"reserved\",\n\t\t\"\
    reserved\",\n\t\t\"reserved\",\n\t\t\"reserved\",\n\t\t\"partially-correct\"\n\
    };\n\nclass InputStreamReader {\npublic:\n\tvirtual int curChar() = 0;\n\n\tvirtual\
    \ int nextChar() = 0;\n\n\tvirtual void skipChar() = 0;\n\n\tvirtual void unreadChar(int\
    \ c) = 0;\n\n\tvirtual std::string getName() = 0;\n\n\tvirtual bool eof() = 0;\n\
    \n\tvirtual void close() = 0;\n\n\tvirtual int getLine() = 0;\n\n\tvirtual ~InputStreamReader()\
    \ = 0;\n};\n\nInputStreamReader::~InputStreamReader() {\n\t// No operations.\n\
    }\n\nclass StringInputStreamReader : public InputStreamReader {\nprivate:\n\t\
    std::string s;\n\tsize_t pos;\n\npublic:\n\tStringInputStreamReader(const std::string\
    \ &content) : s(content), pos(0) {\n\t\t// No operations.\n\t}\n\n\tint curChar()\
    \ {\n\t\tif (pos >= s.length())\n\t\t\treturn EOFC;\n\t\telse\n\t\t\treturn s[pos];\n\
    \t}\n\n\tint nextChar() {\n\t\tif (pos >= s.length()) {\n\t\t\tpos++;\n\t\t\t\
    return EOFC;\n\t\t} else\n\t\t\treturn s[pos++];\n\t}\n\n\tvoid skipChar() {\n\
    \t\tpos++;\n\t}\n\n\tvoid unreadChar(int c) {\n\t\tif (pos == 0)\n\t\t\t__testlib_fail(\"\
    FileFileInputStreamReader::unreadChar(int): pos == 0.\");\n\t\tpos--;\n\t\tif\
    \ (pos < s.length())\n\t\t\ts[pos] = char(c);\n\t}\n\n\tstd::string getName()\
    \ {\n\t\treturn __testlib_part(s);\n\t}\n\n\tint getLine() {\n\t\treturn -1;\n\
    \t}\n\n\tbool eof() {\n\t\treturn pos >= s.length();\n\t}\n\n\tvoid close() {\n\
    \t\t// No operations.\n\t}\n};\n\nclass FileInputStreamReader : public InputStreamReader\
    \ {\nprivate:\n\tstd::FILE *file;\n\tstd::string name;\n\tint line;\n\tstd::vector<int>\
    \ undoChars;\n\n\tinline int postprocessGetc(int getcResult) {\n\t\tif (getcResult\
    \ != EOF)\n\t\t\treturn getcResult;\n\t\telse\n\t\t\treturn EOFC;\n\t}\n\n\tint\
    \ getc(FILE *file) {\n\t\tint c;\n\t\tif (undoChars.empty())\n\t\t\tc = ::getc(file);\n\
    \t\telse {\n\t\t\tc = undoChars.back();\n\t\t\tundoChars.pop_back();\n\t\t}\n\n\
    \t\tif (c == LF)\n\t\t\tline++;\n\t\treturn c;\n\t}\n\n\tint ungetc(int c/*, FILE*\
    \ file*/) {\n\t\tif (c == LF)\n\t\t\tline--;\n\t\tundoChars.push_back(c);\n\t\t\
    return c;\n\t}\n\npublic:\n\tFileInputStreamReader(std::FILE *file, const std::string\
    \ &name) : file(file), name(name), line(1) {\n\t\t// No operations.\n\t}\n\n\t\
    int curChar() {\n\t\tif (feof(file))\n\t\t\treturn EOFC;\n\t\telse {\n\t\t\tint\
    \ c = getc(file);\n\t\t\tungetc(c/*, file*/);\n\t\t\treturn postprocessGetc(c);\n\
    \t\t}\n\t}\n\n\tint nextChar() {\n\t\tif (feof(file))\n\t\t\treturn EOFC;\n\t\t\
    else\n\t\t\treturn postprocessGetc(getc(file));\n\t}\n\n\tvoid skipChar() {\n\t\
    \tgetc(file);\n\t}\n\n\tvoid unreadChar(int c) {\n\t\tungetc(c/*, file*/);\n\t\
    }\n\n\tstd::string getName() {\n\t\treturn name;\n\t}\n\n\tint getLine() {\n\t\
    \treturn line;\n\t}\n\n\tbool eof() {\n\t\tif (NULL == file || feof(file))\n\t\
    \t\treturn true;\n\t\telse {\n\t\t\tint c = nextChar();\n\t\t\tif (c == EOFC ||\
    \ (c == EOF && feof(file)))\n\t\t\t\treturn true;\n\t\t\tunreadChar(c);\n\t\t\t\
    return false;\n\t\t}\n\t}\n\n\tvoid close() {\n\t\tif (NULL != file) {\n\t\t\t\
    fclose(file);\n\t\t\tfile = NULL;\n\t\t}\n\t}\n};\n\nclass BufferedFileInputStreamReader\
    \ : public InputStreamReader {\nprivate:\n\tstatic const size_t BUFFER_SIZE;\n\
    \tstatic const size_t MAX_UNREAD_COUNT;\n\n\tstd::FILE *file;\n\tchar *buffer;\n\
    \tbool *isEof;\n\tint bufferPos;\n\tsize_t bufferSize;\n\n\tstd::string name;\n\
    \tint line;\n\n\tbool refill() {\n\t\tif (NULL == file)\n\t\t\t__testlib_fail(\"\
    BufferedFileInputStreamReader: file == NULL (\" + getName() + \")\");\n\n\t\t\
    if (bufferPos >= int(bufferSize)) {\n\t\t\tsize_t readSize = fread(\n\t\t\t\t\t\
    buffer + MAX_UNREAD_COUNT,\n\t\t\t\t\t1,\n\t\t\t\t\tBUFFER_SIZE - MAX_UNREAD_COUNT,\n\
    \t\t\t\t\tfile\n\t\t\t);\n\n\t\t\tif (readSize < BUFFER_SIZE - MAX_UNREAD_COUNT\n\
    \t\t\t\t&& ferror(file))\n\t\t\t\t__testlib_fail(\"BufferedFileInputStreamReader:\
    \ unable to read (\" + getName() + \")\");\n\n\t\t\tbufferSize = MAX_UNREAD_COUNT\
    \ + readSize;\n\t\t\tbufferPos = int(MAX_UNREAD_COUNT);\n\t\t\tstd::memset(isEof\
    \ + MAX_UNREAD_COUNT, 0, sizeof(isEof[0]) * readSize);\n\n\t\t\treturn readSize\
    \ > 0;\n\t\t} else\n\t\t\treturn true;\n\t}\n\n\tchar increment() {\n\t\tchar\
    \ c;\n\t\tif ((c = buffer[bufferPos++]) == LF)\n\t\t\tline++;\n\t\treturn c;\n\
    \t}\n\npublic:\n\tBufferedFileInputStreamReader(std::FILE *file, const std::string\
    \ &name) : file(file), name(name), line(1) {\n\t\tbuffer = new char[BUFFER_SIZE];\n\
    \t\tisEof = new bool[BUFFER_SIZE];\n\t\tbufferSize = MAX_UNREAD_COUNT;\n\t\tbufferPos\
    \ = int(MAX_UNREAD_COUNT);\n\t}\n\n\t~BufferedFileInputStreamReader() {\n\t\t\
    if (NULL != buffer) {\n\t\t\tdelete[] buffer;\n\t\t\tbuffer = NULL;\n\t\t}\n\t\
    \tif (NULL != isEof) {\n\t\t\tdelete[] isEof;\n\t\t\tisEof = NULL;\n\t\t}\n\t\
    }\n\n\tint curChar() {\n\t\tif (!refill())\n\t\t\treturn EOFC;\n\n\t\treturn isEof[bufferPos]\
    \ ? EOFC : buffer[bufferPos];\n\t}\n\n\tint nextChar() {\n\t\tif (!refill())\n\
    \t\t\treturn EOFC;\n\n\t\treturn isEof[bufferPos] ? EOFC : increment();\n\t}\n\
    \n\tvoid skipChar() {\n\t\tincrement();\n\t}\n\n\tvoid unreadChar(int c) {\n\t\
    \tbufferPos--;\n\t\tif (bufferPos < 0)\n\t\t\t__testlib_fail(\"BufferedFileInputStreamReader::unreadChar(int):\
    \ bufferPos < 0\");\n\t\tisEof[bufferPos] = (c == EOFC);\n\t\tbuffer[bufferPos]\
    \ = char(c);\n\t\tif (c == LF)\n\t\t\tline--;\n\t}\n\n\tstd::string getName()\
    \ {\n\t\treturn name;\n\t}\n\n\tint getLine() {\n\t\treturn line;\n\t}\n\n\tbool\
    \ eof() {\n\t\treturn !refill() || EOFC == curChar();\n\t}\n\n\tvoid close() {\n\
    \t\tif (NULL != file) {\n\t\t\tfclose(file);\n\t\t\tfile = NULL;\n\t\t}\n\t}\n\
    };\n\nconst size_t BufferedFileInputStreamReader::BUFFER_SIZE = 2000000;\nconst\
    \ size_t BufferedFileInputStreamReader::MAX_UNREAD_COUNT = BufferedFileInputStreamReader::BUFFER_SIZE\
    \ / 2;\n\n/*\n * Streams to be used for reading data in checkers or validators.\n\
    \ * Each read*() method moves pointer to the next character after the\n * read\
    \ value.\n */\nstruct InStream {\n\t/* Do not use them. */\n\tInStream();\n\n\t\
    ~InStream();\n\n\t/* Wrap std::string with InStream. */\n\tInStream(const InStream\
    \ &baseStream, std::string content);\n\n\tInputStreamReader *reader;\n\tint lastLine;\n\
    \n\tstd::string name;\n\tTMode mode;\n\tbool opened;\n\tbool stdfile;\n\tbool\
    \ strict;\n\n\tint wordReserveSize;\n\tstd::string _tmpReadToken;\n\n\tint readManyIteration;\n\
    \tsize_t maxFileSize;\n\tsize_t maxTokenLength;\n\tsize_t maxMessageLength;\n\n\
    \tvoid init(std::string fileName, TMode mode);\n\n\tvoid init(std::FILE *f, TMode\
    \ mode);\n\n\t/* Moves stream pointer to the first non-white-space character or\
    \ EOF. */\n\tvoid skipBlanks();\n\n\t/* Returns current character in the stream.\
    \ Doesn't remove it from stream. */\n\tchar curChar();\n\n\t/* Moves stream pointer\
    \ one character forward. */\n\tvoid skipChar();\n\n\t/* Returns current character\
    \ and moves pointer one character forward. */\n\tchar nextChar();\n\n\t/* Returns\
    \ current character and moves pointer one character forward. */\n\tchar readChar();\n\
    \n\t/* As \"readChar()\" but ensures that the result is equal to given parameter.\
    \ */\n\tchar readChar(char c);\n\n\t/* As \"readChar()\" but ensures that the\
    \ result is equal to the space (code=32). */\n\tchar readSpace();\n\n\t/* Puts\
    \ back the character into the stream. */\n\tvoid unreadChar(char c);\n\n\t/* Reopens\
    \ stream, you should not use it. */\n\tvoid reset(std::FILE *file = NULL);\n\n\
    \t/* Checks that current position is EOF. If not it doesn't move stream pointer.\
    \ */\n\tbool eof();\n\n\t/* Moves pointer to the first non-white-space character\
    \ and calls \"eof()\". */\n\tbool seekEof();\n\n\t/* \n\t * Checks that current\
    \ position contains EOLN. \n\t * If not it doesn't move stream pointer. \n\t *\
    \ In strict mode expects \"#13#10\" for windows or \"#10\" for other platforms.\n\
    \t */\n\tbool eoln();\n\n\t/* Moves pointer to the first non-space and non-tab\
    \ character and calls \"eoln()\". */\n\tbool seekEoln();\n\n\t/* Moves stream\
    \ pointer to the first character of the next line (if exists). */\n\tvoid nextLine();\n\
    \n\t/* \n\t * Reads new token. Ignores white-spaces into the non-strict mode \n\
    \t * (strict mode is used in validators usually). \n\t */\n\tstd::string readWord();\n\
    \n\t/* The same as \"readWord()\", it is preffered to use \"readToken()\". */\n\
    \tstd::string readToken();\n\n\t/* The same as \"readWord()\", but ensures that\
    \ token matches to given pattern. */\n\tstd::string readWord(const std::string\
    \ &ptrn, const std::string &variableName = \"\");\n\n\tstd::string readWord(const\
    \ pattern &p, const std::string &variableName = \"\");\n\n\tstd::vector<std::string>\n\
    \treadWords(int size, const std::string &ptrn, const std::string &variablesName\
    \ = \"\", int indexBase = 1);\n\n\tstd::vector<std::string>\n\treadWords(int size,\
    \ const pattern &p, const std::string &variablesName = \"\", int indexBase = 1);\n\
    \n\tstd::vector<std::string> readWords(int size, int indexBase = 1);\n\n\t/* The\
    \ same as \"readToken()\", but ensures that token matches to given pattern. */\n\
    \tstd::string readToken(const std::string &ptrn, const std::string &variableName\
    \ = \"\");\n\n\tstd::string readToken(const pattern &p, const std::string &variableName\
    \ = \"\");\n\n\tstd::vector<std::string>\n\treadTokens(int size, const std::string\
    \ &ptrn, const std::string &variablesName = \"\", int indexBase = 1);\n\n\tstd::vector<std::string>\n\
    \treadTokens(int size, const pattern &p, const std::string &variablesName = \"\
    \", int indexBase = 1);\n\n\tstd::vector<std::string> readTokens(int size, int\
    \ indexBase = 1);\n\n\tvoid readWordTo(std::string &result);\n\n\tvoid readWordTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n\tvoid\
    \ readWordTo(std::string &result, const std::string &ptrn, const std::string &variableName\
    \ = \"\");\n\n\tvoid readTokenTo(std::string &result);\n\n\tvoid readTokenTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n\tvoid\
    \ readTokenTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName = \"\");\n\n\t/* \n\t * Reads new long long value. Ignores white-spaces\
    \ into the non-strict mode \n\t * (strict mode is used in validators usually).\
    \ \n\t */\n\tlong long readLong();\n\n\tunsigned long long readUnsignedLong();\n\
    \n\t/*\n\t * Reads new int. Ignores white-spaces into the non-strict mode \n\t\
    \ * (strict mode is used in validators usually). \n\t */\n\tint readInteger();\n\
    \n\t/*\n\t * Reads new int. Ignores white-spaces into the non-strict mode \n\t\
    \ * (strict mode is used in validators usually). \n\t */\n\tint readInt();\n\n\
    \t/* As \"readLong()\" but ensures that value in the range [minv,maxv]. */\n\t\
    long long readLong(long long minv, long long maxv, const std::string &variableName\
    \ = \"\");\n\n\t/* Reads space-separated sequence of long longs. */\n\tstd::vector<long\
    \ long>\n\treadLongs(int size, long long minv, long long maxv, const std::string\
    \ &variablesName = \"\", int indexBase = 1);\n\n\t/* Reads space-separated sequence\
    \ of long longs. */\n\tstd::vector<long long> readLongs(int size, int indexBase\
    \ = 1);\n\n\tunsigned long long\n\treadUnsignedLong(unsigned long long minv, unsigned\
    \ long long maxv, const std::string &variableName = \"\");\n\n\tstd::vector<unsigned\
    \ long long>\n\treadUnsignedLongs(int size, unsigned long long minv, unsigned\
    \ long long maxv, const std::string &variablesName = \"\",\n\t\t\t\t\t  int indexBase\
    \ = 1);\n\n\tstd::vector<unsigned long long> readUnsignedLongs(int size, int indexBase\
    \ = 1);\n\n\tunsigned long long readLong(unsigned long long minv, unsigned long\
    \ long maxv, const std::string &variableName = \"\");\n\n\tstd::vector<unsigned\
    \ long long>\n\treadLongs(int size, unsigned long long minv, unsigned long long\
    \ maxv, const std::string &variablesName = \"\",\n\t\t\t  int indexBase = 1);\n\
    \n\t/* As \"readInteger()\" but ensures that value in the range [minv,maxv]. */\n\
    \tint readInteger(int minv, int maxv, const std::string &variableName = \"\");\n\
    \n\t/* As \"readInt()\" but ensures that value in the range [minv,maxv]. */\n\t\
    int readInt(int minv, int maxv, const std::string &variableName = \"\");\n\n\t\
    /* Reads space-separated sequence of integers. */\n\tstd::vector<int>\n\treadIntegers(int\
    \ size, int minv, int maxv, const std::string &variablesName = \"\", int indexBase\
    \ = 1);\n\n\t/* Reads space-separated sequence of integers. */\n\tstd::vector<int>\
    \ readIntegers(int size, int indexBase = 1);\n\n\t/* Reads space-separated sequence\
    \ of integers. */\n\tstd::vector<int> readInts(int size, int minv, int maxv, const\
    \ std::string &variablesName = \"\", int indexBase = 1);\n\n\t/* Reads space-separated\
    \ sequence of integers. */\n\tstd::vector<int> readInts(int size, int indexBase\
    \ = 1);\n\n\t/* \n\t * Reads new double. Ignores white-spaces into the non-strict\
    \ mode \n\t * (strict mode is used in validators usually). \n\t */\n\tdouble readReal();\n\
    \n\t/*\n\t * Reads new double. Ignores white-spaces into the non-strict mode \n\
    \t * (strict mode is used in validators usually). \n\t */\n\tdouble readDouble();\n\
    \n\t/* As \"readReal()\" but ensures that value in the range [minv,maxv]. */\n\
    \tdouble readReal(double minv, double maxv, const std::string &variableName =\
    \ \"\");\n\n\tstd::vector<double>\n\treadReals(int size, double minv, double maxv,\
    \ const std::string &variablesName = \"\", int indexBase = 1);\n\n\tstd::vector<double>\
    \ readReals(int size, int indexBase = 1);\n\n\t/* As \"readDouble()\" but ensures\
    \ that value in the range [minv,maxv]. */\n\tdouble readDouble(double minv, double\
    \ maxv, const std::string &variableName = \"\");\n\n\tstd::vector<double>\n\t\
    readDoubles(int size, double minv, double maxv, const std::string &variablesName\
    \ = \"\", int indexBase = 1);\n\n\tstd::vector<double> readDoubles(int size, int\
    \ indexBase = 1);\n\n\t/* \n\t * As \"readReal()\" but ensures that value in the\
    \ range [minv,maxv] and\n\t * number of digit after the decimal point is in range\
    \ [minAfterPointDigitCount,maxAfterPointDigitCount]\n\t * and number is in the\
    \ form \"[-]digit(s)[.digit(s)]\".\n\t */\n\tdouble readStrictReal(double minv,\
    \ double maxv,\n\t\t\t\t\t\t  int minAfterPointDigitCount, int maxAfterPointDigitCount,\n\
    \t\t\t\t\t\t  const std::string &variableName = \"\");\n\n\tstd::vector<double>\
    \ readStrictReals(int size, double minv, double maxv,\n\t\t\t\t\t\t\t\t\t\tint\
    \ minAfterPointDigitCount, int maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\t\t\t\
    const std::string &variablesName = \"\", int indexBase = 1);\n\n\t/* \n\t * As\
    \ \"readDouble()\" but ensures that value in the range [minv,maxv] and\n\t * number\
    \ of digit after the decimal point is in range [minAfterPointDigitCount,maxAfterPointDigitCount]\n\
    \t * and number is in the form \"[-]digit(s)[.digit(s)]\".\n\t */\n\tdouble readStrictDouble(double\
    \ minv, double maxv,\n\t\t\t\t\t\t\tint minAfterPointDigitCount, int maxAfterPointDigitCount,\n\
    \t\t\t\t\t\t\tconst std::string &variableName = \"\");\n\n\tstd::vector<double>\
    \ readStrictDoubles(int size, double minv, double maxv,\n\t\t\t\t\t\t\t\t\t\t\
    \  int minAfterPointDigitCount, int maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\t\
    \t\t  const std::string &variablesName = \"\", int indexBase = 1);\n\n\t/* As\
    \ readLine(). */\n\tstd::string readString();\n\n\t/* Read many lines. */\n\t\
    std::vector<std::string> readStrings(int size, int indexBase = 1);\n\n\t/* See\
    \ readLine(). */\n\tvoid readStringTo(std::string &result);\n\n\t/* The same as\
    \ \"readLine()/readString()\", but ensures that line matches to the given pattern.\
    \ */\n\tstd::string readString(const pattern &p, const std::string &variableName\
    \ = \"\");\n\n\t/* The same as \"readLine()/readString()\", but ensures that line\
    \ matches to the given pattern. */\n\tstd::string readString(const std::string\
    \ &ptrn, const std::string &variableName = \"\");\n\n\t/* Read many lines. */\n\
    \tstd::vector<std::string>\n\treadStrings(int size, const pattern &p, const std::string\
    \ &variableName = \"\", int indexBase = 1);\n\n\t/* Read many lines. */\n\tstd::vector<std::string>\n\
    \treadStrings(int size, const std::string &ptrn, const std::string &variableName\
    \ = \"\", int indexBase = 1);\n\n\t/* The same as \"readLine()/readString()\"\
    , but ensures that line matches to the given pattern. */\n\tvoid readStringTo(std::string\
    \ &result, const pattern &p, const std::string &variableName = \"\");\n\n\t/*\
    \ The same as \"readLine()/readString()\", but ensures that line matches to the\
    \ given pattern. */\n\tvoid readStringTo(std::string &result, const std::string\
    \ &ptrn, const std::string &variableName = \"\");\n\n\t/* \n\t * Reads line from\
    \ the current position to EOLN or EOF. Moves stream pointer to \n\t * the first\
    \ character of the new line (if possible). \n\t */\n\tstd::string readLine();\n\
    \n\t/* Read many lines. */\n\tstd::vector<std::string> readLines(int size, int\
    \ indexBase = 1);\n\n\t/* See readLine(). */\n\tvoid readLineTo(std::string &result);\n\
    \n\t/* The same as \"readLine()\", but ensures that line matches to the given\
    \ pattern. */\n\tstd::string readLine(const pattern &p, const std::string &variableName\
    \ = \"\");\n\n\t/* The same as \"readLine()\", but ensures that line matches to\
    \ the given pattern. */\n\tstd::string readLine(const std::string &ptrn, const\
    \ std::string &variableName = \"\");\n\n\t/* Read many lines. */\n\tstd::vector<std::string>\n\
    \treadLines(int size, const pattern &p, const std::string &variableName = \"\"\
    , int indexBase = 1);\n\n\t/* Read many lines. */\n\tstd::vector<std::string>\n\
    \treadLines(int size, const std::string &ptrn, const std::string &variableName\
    \ = \"\", int indexBase = 1);\n\n\t/* The same as \"readLine()\", but ensures\
    \ that line matches to the given pattern. */\n\tvoid readLineTo(std::string &result,\
    \ const pattern &p, const std::string &variableName = \"\");\n\n\t/* The same\
    \ as \"readLine()\", but ensures that line matches to the given pattern. */\n\t\
    void readLineTo(std::string &result, const std::string &ptrn, const std::string\
    \ &variableName = \"\");\n\n\t/* Reads EOLN or fails. Use it in validators. Calls\
    \ \"eoln()\" method internally. */\n\tvoid readEoln();\n\n\t/* Reads EOF or fails.\
    \ Use it in validators. Calls \"eof()\" method internally. */\n\tvoid readEof();\n\
    \n\t/* \n\t * Quit-functions aborts program with <result> and <message>:\n\t *\
    \ input/answer streams replace any result to FAIL.\n\t */\n\tNORETURN void quit(TResult\
    \ result, const char *msg);\n\t/* \n\t * Quit-functions aborts program with <result>\
    \ and <message>:\n\t * input/answer streams replace any result to FAIL.\n\t */\n\
    \tNORETURN void quitf(TResult result, const char *msg, ...);\n\n\t/*\n\t * Quit-functions\
    \ aborts program with <result> and <message>:\n\t * input/answer streams replace\
    \ any result to FAIL.\n\t */\n\tvoid quitif(bool condition, TResult result, const\
    \ char *msg, ...);\n\t/* \n\t * Quit-functions aborts program with <result> and\
    \ <message>:\n\t * input/answer streams replace any result to FAIL.\n\t */\n\t\
    NORETURN void quits(TResult result, std::string msg);\n\n\t/* \n\t * Checks condition\
    \ and aborts a program if codition is false.\n\t * Returns _wa for ouf and _fail\
    \ on any other streams.\n\t */\n#ifdef __GNUC__\n\t__attribute__ ((format (printf,\
    \ 3, 4)))\n#endif\n\tvoid ensuref(bool cond, const char *format, ...);\n\n\tvoid\
    \ __testlib_ensure(bool cond, std::string message);\n\n\tvoid close();\n\n\tconst\
    \ static int NO_INDEX = INT_MAX;\n\tconst static char OPEN_BRACKET = char(11);\n\
    \tconst static char CLOSE_BRACKET = char(17);\n\n\tconst static WORD LightGray\
    \ = 0x07;\n\tconst static WORD LightRed = 0x0c;\n\tconst static WORD LightCyan\
    \ = 0x0b;\n\tconst static WORD LightGreen = 0x0a;\n\tconst static WORD LightYellow\
    \ = 0x0e;\n\n\tstatic void textColor(WORD color);\n\n\tstatic void quitscr(WORD\
    \ color, const char *msg);\n\n\tstatic void quitscrS(WORD color, std::string msg);\n\
    \n\tvoid xmlSafeWrite(std::FILE *file, const char *msg);\n\nprivate:\n\tInStream(const\
    \ InStream &);\n\n\tInStream &operator=(const InStream &);\n};\n\nInStream inf;\n\
    InStream ouf;\nInStream ans;\nbool appesMode;\nstd::string resultName;\nstd::string\
    \ checkerName = \"untitled checker\";\nrandom_t rnd;\nTTestlibMode testlibMode\
    \ = _unknown;\ndouble __testlib_points = std::numeric_limits<float>::infinity();\n\
    \nstruct ValidatorBoundsHit {\n\tstatic const double EPS;\n\tbool minHit;\n\t\
    bool maxHit;\n\n\tValidatorBoundsHit(bool minHit = false, bool maxHit = false)\
    \ : minHit(minHit), maxHit(maxHit) {\n\t};\n\n\tValidatorBoundsHit merge(const\
    \ ValidatorBoundsHit &validatorBoundsHit) {\n\t\treturn ValidatorBoundsHit(\n\t\
    \t\t\t__testlib_max(minHit, validatorBoundsHit.minHit),\n\t\t\t\t__testlib_max(maxHit,\
    \ validatorBoundsHit.maxHit)\n\t\t);\n\t}\n};\n\nconst double ValidatorBoundsHit::EPS\
    \ = 1E-12;\n\nclass Validator {\nprivate:\n\tbool _initialized;\n\tstd::string\
    \ _testset;\n\tstd::string _group;\n\tstd::string _testOverviewLogFileName;\n\t\
    std::map<std::string, ValidatorBoundsHit> _boundsHitByVariableName;\n\tstd::set<std::string>\
    \ _features;\n\tstd::set<std::string> _hitFeatures;\n\n\tbool isVariableNameBoundsAnalyzable(const\
    \ std::string &variableName) {\n\t\tfor (size_t i = 0; i < variableName.length();\
    \ i++)\n\t\t\tif ((variableName[i] >= '0' && variableName[i] <= '9') || variableName[i]\
    \ < ' ')\n\t\t\t\treturn false;\n\t\treturn true;\n\t}\n\n\tbool isFeatureNameAnalyzable(const\
    \ std::string &featureName) {\n\t\tfor (size_t i = 0; i < featureName.length();\
    \ i++)\n\t\t\tif (featureName[i] < ' ')\n\t\t\t\treturn false;\n\t\treturn true;\n\
    \t}\n\npublic:\n\tValidator() : _initialized(false), _testset(\"tests\"), _group()\
    \ {\n\t}\n\n\tvoid initialize() {\n\t\t_initialized = true;\n\t}\n\n\tstd::string\
    \ testset() const {\n\t\tif (!_initialized)\n\t\t\t__testlib_fail(\"Validator\
    \ should be initialized with registerValidation(argc, argv) instead of registerValidation()\
    \ to support validator.testset()\");\n\t\treturn _testset;\n\t}\n\n\tstd::string\
    \ group() const {\n\t\tif (!_initialized)\n\t\t\t__testlib_fail(\"Validator should\
    \ be initialized with registerValidation(argc, argv) instead of registerValidation()\
    \ to support validator.group()\");\n\t\treturn _group;\n\t}\n\n\tstd::string testOverviewLogFileName()\
    \ const {\n\t\treturn _testOverviewLogFileName;\n\t}\n\n\tvoid setTestset(const\
    \ char *const testset) {\n\t\t_testset = testset;\n\t}\n\n\tvoid setGroup(const\
    \ char *const group) {\n\t\t_group = group;\n\t}\n\n\tvoid setTestOverviewLogFileName(const\
    \ char *const testOverviewLogFileName) {\n\t\t_testOverviewLogFileName = testOverviewLogFileName;\n\
    \t}\n\n\tvoid addBoundsHit(const std::string &variableName, ValidatorBoundsHit\
    \ boundsHit) {\n\t\tif (isVariableNameBoundsAnalyzable(variableName)) {\n\t\t\t\
    _boundsHitByVariableName[variableName]\n\t\t\t\t\t= boundsHit.merge(_boundsHitByVariableName[variableName]);\n\
    \t\t}\n\t}\n\n\tstd::string getBoundsHitLog() {\n\t\tstd::string result;\n\t\t\
    for (std::map<std::string, ValidatorBoundsHit>::iterator i = _boundsHitByVariableName.begin();\n\
    \t\t\t i != _boundsHitByVariableName.end();\n\t\t\t i++) {\n\t\t\tresult += \"\
    \\\"\" + i->first + \"\\\":\";\n\t\t\tif (i->second.minHit)\n\t\t\t\tresult +=\
    \ \" min-value-hit\";\n\t\t\tif (i->second.maxHit)\n\t\t\t\tresult += \" max-value-hit\"\
    ;\n\t\t\tresult += \"\\n\";\n\t\t}\n\t\treturn result;\n\t}\n\n\tstd::string getFeaturesLog()\
    \ {\n\t\tstd::string result;\n\t\tfor (std::set<std::string>::iterator i = _features.begin();\n\
    \t\t\t i != _features.end();\n\t\t\t i++) {\n\t\t\tresult += \"feature \\\"\"\
    \ + *i + \"\\\":\";\n\t\t\tif (_hitFeatures.count(*i))\n\t\t\t\tresult += \" hit\"\
    ;\n\t\t\tresult += \"\\n\";\n\t\t}\n\t\treturn result;\n\t}\n\n\tvoid writeTestOverviewLog()\
    \ {\n\t\tif (!_testOverviewLogFileName.empty()) {\n\t\t\tstd::string fileName(_testOverviewLogFileName);\n\
    \t\t\t_testOverviewLogFileName = \"\";\n\t\t\tFILE *testOverviewLogFile = fopen(fileName.c_str(),\
    \ \"w\");\n\t\t\tif (NULL == testOverviewLogFile)\n\t\t\t\t__testlib_fail(\"Validator::writeTestOverviewLog:\
    \ can't test overview log to (\" + fileName + \")\");\n\t\t\tfprintf(testOverviewLogFile,\
    \ \"%s%s\", getBoundsHitLog().c_str(), getFeaturesLog().c_str());\n\t\t\tif (fclose(testOverviewLogFile))\n\
    \t\t\t\t__testlib_fail(\n\t\t\t\t\t\t\"Validator::writeTestOverviewLog: can't\
    \ close test overview log file (\" + fileName + \")\");\n\t\t}\n\t}\n\n\tvoid\
    \ addFeature(const std::string &feature) {\n\t\tif (_features.count(feature))\n\
    \t\t\t__testlib_fail(\"Feature \" + feature + \" registered twice.\");\n\t\tif\
    \ (!isFeatureNameAnalyzable(feature))\n\t\t\t__testlib_fail(\"Feature name '\"\
    \ + feature + \"' contains restricted characters.\");\n\n\t\t_features.insert(feature);\n\
    \t}\n\n\tvoid feature(const std::string &feature) {\n\t\tif (!isFeatureNameAnalyzable(feature))\n\
    \t\t\t__testlib_fail(\"Feature name '\" + feature + \"' contains restricted characters.\"\
    );\n\n\t\tif (!_features.count(feature))\n\t\t\t__testlib_fail(\"Feature \" +\
    \ feature + \" didn't registered via addFeature(feature).\");\n\n\t\t_hitFeatures.insert(feature);\n\
    \t}\n} validator;\n\nstruct TestlibFinalizeGuard {\n\tstatic bool alive;\n\tint\
    \ quitCount, readEofCount;\n\n\tTestlibFinalizeGuard() : quitCount(0), readEofCount(0)\
    \ {\n\t\t// No operations.\n\t}\n\n\t~TestlibFinalizeGuard() {\n\t\tbool _alive\
    \ = alive;\n\t\talive = false;\n\n\t\tif (_alive) {\n\t\t\tif (testlibMode ==\
    \ _checker && quitCount == 0)\n\t\t\t\t__testlib_fail(\"Checker must end with\
    \ quit or quitf call.\");\n\n\t\t\tif (testlibMode == _validator && readEofCount\
    \ == 0 && quitCount == 0)\n\t\t\t\t__testlib_fail(\"Validator must end with readEof\
    \ call.\");\n\t\t}\n\n\t\tvalidator.writeTestOverviewLog();\n\t}\n};\n\nbool TestlibFinalizeGuard::alive\
    \ = true;\nTestlibFinalizeGuard testlibFinalizeGuard;\n\n/*\n * Call it to disable\
    \ checks on finalization.\n */\nvoid disableFinalizeGuard() {\n\tTestlibFinalizeGuard::alive\
    \ = false;\n}\n\n/* Interactor streams.\n */\nstd::fstream tout;\n\n/* implementation\n\
    \ */\n\n#if __cplusplus > 199711L || defined(_MSC_VER)\ntemplate<typename T>\n\
    static std::string vtos(const T &t, std::true_type) {\n\tif (t == 0)\n\t\treturn\
    \ \"0\";\n\telse {\n\t\tT n(t);\n\t\tbool negative = n < 0;\n\t\tstd::string s;\n\
    \t\twhile (n != 0) {\n\t\t\tT digit = n % 10;\n\t\t\tif (digit < 0)\n\t\t\t\t\
    digit = -digit;\n\t\t\ts += char('0' + digit);\n\t\t\tn /= 10;\n\t\t}\n\t\tstd::reverse(s.begin(),\
    \ s.end());\n\t\treturn negative ? \"-\" + s : s;\n\t}\n}\n\ntemplate<typename\
    \ T>\nstatic std::string vtos(const T &t, std::false_type) {\n\tstd::string s;\n\
    \tstatic std::stringstream ss;\n\tss.str(std::string());\n\tss.clear();\n\tss\
    \ << t;\n\tss >> s;\n\treturn s;\n}\n\ntemplate<typename T>\nstatic std::string\
    \ vtos(const T &t) {\n\treturn vtos(t, std::is_integral<T>());\n}\n\n/* signed\
    \ case. */\ntemplate<typename T>\nstatic std::string toHumanReadableString(const\
    \ T &n, std::false_type) {\n\tif (n == 0)\n\t\treturn vtos(n);\n\tint trailingZeroCount\
    \ = 0;\n\tT n_ = n;\n\twhile (n_ % 10 == 0)\n\t\tn_ /= 10, trailingZeroCount++;\n\
    \tif (trailingZeroCount >= 7) {\n\t\tif (n_ == 1)\n\t\t\treturn \"10^\" + vtos(trailingZeroCount);\n\
    \t\telse if (n_ == -1)\n\t\t\treturn \"-10^\" + vtos(trailingZeroCount);\n\t\t\
    else\n\t\t\treturn vtos(n_) + \"*10^\" + vtos(trailingZeroCount);\n\t} else\n\t\
    \treturn vtos(n);\n}\n\n/* unsigned case. */\ntemplate<typename T>\nstatic std::string\
    \ toHumanReadableString(const T &n, std::true_type) {\n\tif (n == 0)\n\t\treturn\
    \ vtos(n);\n\tint trailingZeroCount = 0;\n\tT n_ = n;\n\twhile (n_ % 10 == 0)\n\
    \t\tn_ /= 10, trailingZeroCount++;\n\tif (trailingZeroCount >= 7) {\n\t\tif (n_\
    \ == 1)\n\t\t\treturn \"10^\" + vtos(trailingZeroCount);\n\t\telse\n\t\t\treturn\
    \ vtos(n_) + \"*10^\" + vtos(trailingZeroCount);\n\t} else\n\t\treturn vtos(n);\n\
    }\n\ntemplate<typename T>\nstatic std::string toHumanReadableString(const T &n)\
    \ {\n\treturn toHumanReadableString(n, std::is_unsigned<T>());\n}\n#else\ntemplate<typename\
    \ T>\nstatic std::string vtos(const T& t)\n{\n\tstd::string s;\n\tstatic std::stringstream\
    \ ss;\n\tss.str(std::string());\n\tss.clear();\n\tss << t;\n\tss >> s;\n\treturn\
    \ s;\n}\n\ntemplate<typename T>\nstatic std::string toHumanReadableString(const\
    \ T &n) {\n\treturn vtos(n);\n}\n#endif\n\ntemplate<typename T>\nstatic std::string\
    \ toString(const T &t) {\n\treturn vtos(t);\n}\n\nInStream::InStream() {\n\treader\
    \ = NULL;\n\tlastLine = -1;\n\tname = \"\";\n\tmode = _input;\n\tstrict = false;\n\
    \tstdfile = false;\n\twordReserveSize = 4;\n\treadManyIteration = NO_INDEX;\n\t\
    maxFileSize = 128 * 1024 * 1024; // 128MB.\n\tmaxTokenLength = 32 * 1024 * 1024;\
    \ // 32MB.\n\tmaxMessageLength = 32000;\n}\n\nInStream::InStream(const InStream\
    \ &baseStream, std::string content) {\n\treader = new StringInputStreamReader(content);\n\
    \tlastLine = -1;\n\topened = true;\n\tstrict = baseStream.strict;\n\tmode = baseStream.mode;\n\
    \tname = \"based on \" + baseStream.name;\n\treadManyIteration = NO_INDEX;\n\t\
    maxFileSize = 128 * 1024 * 1024; // 128MB.\n\tmaxTokenLength = 32 * 1024 * 1024;\
    \ // 32MB.\n\tmaxMessageLength = 32000;\n}\n\nInStream::~InStream() {\n\tif (NULL\
    \ != reader) {\n\t\treader->close();\n\t\tdelete reader;\n\t\treader = NULL;\n\
    \t}\n}\n\n#ifdef __GNUC__\n__attribute__((const))\n#endif\nint resultExitCode(TResult\
    \ r) {\n\tif (r == _ok)\n\t\treturn OK_EXIT_CODE;\n\tif (r == _wa)\n\t\treturn\
    \ WA_EXIT_CODE;\n\tif (r == _pe)\n\t\treturn PE_EXIT_CODE;\n\tif (r == _fail)\n\
    \t\treturn FAIL_EXIT_CODE;\n\tif (r == _dirt)\n\t\treturn DIRT_EXIT_CODE;\n\t\
    if (r == _points)\n\t\treturn POINTS_EXIT_CODE;\n\tif (r == _unexpected_eof)\n\
    #ifdef ENABLE_UNEXPECTED_EOF\n\t\treturn UNEXPECTED_EOF_EXIT_CODE;\n#else\n\t\t\
    return PE_EXIT_CODE;\n#endif\n\tif (r >= _partially)\n\t\treturn PC_BASE_EXIT_CODE\
    \ + (r - _partially);\n\treturn FAIL_EXIT_CODE;\n}\n\nvoid InStream::textColor(\n\
    #if !(defined(ON_WINDOWS) && (!defined(_MSC_VER) || _MSC_VER > 1400)) && defined(__GNUC__)\n\
    \t\t__attribute__((unused))\n#endif\n\t\tWORD color\n) {\n#if defined(ON_WINDOWS)\
    \ && (!defined(_MSC_VER) || _MSC_VER > 1400)\n\tHANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);\n\
    \tSetConsoleTextAttribute(handle, color);\n#endif\n#if !defined(ON_WINDOWS) &&\
    \ defined(__GNUC__)\n\tif (isatty(2))\n\t{\n\t\tswitch (color)\n\t\t{\n\t\tcase\
    \ LightRed:\n\t\t\tfprintf(stderr, \"\\033[1;31m\");\n\t\t\tbreak;\n\t\tcase LightCyan:\n\
    \t\t\tfprintf(stderr, \"\\033[1;36m\");\n\t\t\tbreak;\n\t\tcase LightGreen:\n\t\
    \t\tfprintf(stderr, \"\\033[1;32m\");\n\t\t\tbreak;\n\t\tcase LightYellow:\n\t\
    \t\tfprintf(stderr, \"\\033[1;33m\");\n\t\t\tbreak;\n\t\tcase LightGray:\n\t\t\
    default:\n\t\t\tfprintf(stderr, \"\\033[0m\");\n\t\t}\n\t}\n#endif\n}\n\nNORETURN\
    \ void halt(int exitCode) {\n#ifdef FOOTER\n\tInStream::textColor(InStream::LightGray);\n\
    \tstd::fprintf(stderr, \"Checker: \\\"%s\\\"\\n\", checkerName.c_str());\n\tstd::fprintf(stderr,\
    \ \"Exit code: %d\\n\", exitCode);\n\tInStream::textColor(InStream::LightGray);\n\
    #endif\n\tstd::exit(exitCode);\n}\n\nstatic bool __testlib_shouldCheckDirt(TResult\
    \ result) {\n\treturn result == _ok || result == _points || result >= _partially;\n\
    }\n\nstatic std::string __testlib_appendMessage(const std::string &message, const\
    \ std::string &extra) {\n\tint openPos = -1, closePos = -1;\n\tfor (size_t i =\
    \ 0; i < message.length(); i++) {\n\t\tif (message[i] == InStream::OPEN_BRACKET)\
    \ {\n\t\t\tif (openPos == -1)\n\t\t\t\topenPos = i;\n\t\t\telse\n\t\t\t\topenPos\
    \ = INT_MAX;\n\t\t}\n\t\tif (message[i] == InStream::CLOSE_BRACKET) {\n\t\t\t\
    if (closePos == -1)\n\t\t\t\tclosePos = i;\n\t\t\telse\n\t\t\t\tclosePos = INT_MAX;\n\
    \t\t}\n\t}\n\tif (openPos != -1 && openPos != INT_MAX\n\t\t&& closePos != -1 &&\
    \ closePos != INT_MAX\n\t\t&& openPos < closePos) {\n\t\tsize_t index = message.find(extra,\
    \ openPos);\n\t\tif (index == std::string::npos || int(index) >= closePos) {\n\
    \t\t\tstd::string result(message);\n\t\t\tresult.insert(closePos, \", \" + extra);\n\
    \t\t\treturn result;\n\t\t}\n\t\treturn message;\n\t}\n\n\treturn message + \"\
    \ \" + InStream::OPEN_BRACKET + extra + InStream::CLOSE_BRACKET;\n}\n\nstatic\
    \ std::string __testlib_toPrintableMessage(const std::string &message) {\n\tint\
    \ openPos = -1, closePos = -1;\n\tfor (size_t i = 0; i < message.length(); i++)\
    \ {\n\t\tif (message[i] == InStream::OPEN_BRACKET) {\n\t\t\tif (openPos == -1)\n\
    \t\t\t\topenPos = i;\n\t\t\telse\n\t\t\t\topenPos = INT_MAX;\n\t\t}\n\t\tif (message[i]\
    \ == InStream::CLOSE_BRACKET) {\n\t\t\tif (closePos == -1)\n\t\t\t\tclosePos =\
    \ i;\n\t\t\telse\n\t\t\t\tclosePos = INT_MAX;\n\t\t}\n\t}\n\tif (openPos != -1\
    \ && openPos != INT_MAX\n\t\t&& closePos != -1 && closePos != INT_MAX\n\t\t&&\
    \ openPos < closePos) {\n\t\tstd::string result(message);\n\t\tresult[openPos]\
    \ = '(';\n\t\tresult[closePos] = ')';\n\t\treturn result;\n\t}\n\n\treturn message;\n\
    }\n\nNORETURN void InStream::quit(TResult result, const char *msg) {\n\tif (TestlibFinalizeGuard::alive)\n\
    \t\ttestlibFinalizeGuard.quitCount++;\n\n\tstd::string message(msg);\n\tmessage\
    \ = trim(message);\n\n\tif (__testlib_hasTestCase) {\n\t\tif (result != _ok)\n\
    \t\t\tmessage = __testlib_appendMessage(message, \"test case \" + vtos(__testlib_testCase));\n\
    \t\telse {\n\t\t\tif (__testlib_testCase == 1)\n\t\t\t\tmessage = __testlib_appendMessage(message,\
    \ vtos(__testlib_testCase) + \" test case\");\n\t\t\telse\n\t\t\t\tmessage = __testlib_appendMessage(message,\
    \ vtos(__testlib_testCase) + \" test cases\");\n\t\t}\n\t}\n\n\t// You can change\
    \ maxMessageLength.\n\t// Example: 'inf.maxMessageLength = 1024 * 1024;'.\n\t\
    if (message.length() > maxMessageLength) {\n\t\tstd::string warn = \"message length\
    \ exceeds \" + vtos(maxMessageLength)\n\t\t\t\t\t\t   + \", the message is truncated:\
    \ \";\n\t\tmessage = warn + message.substr(0, maxMessageLength - warn.length());\n\
    \t}\n\n#ifndef ENABLE_UNEXPECTED_EOF\n\tif (result == _unexpected_eof)\n\t\tresult\
    \ = _pe;\n#endif\n\n\tif (mode != _output && result != _fail) {\n\t\tif (mode\
    \ == _input && testlibMode == _validator && lastLine != -1)\n\t\t\tquits(_fail,\
    \ __testlib_appendMessage(__testlib_appendMessage(message, name), \"line \" +\
    \ vtos(lastLine)));\n\t\telse\n\t\t\tquits(_fail, __testlib_appendMessage(message,\
    \ name));\n\t}\n\n\tstd::FILE *resultFile;\n\tstd::string errorName;\n\n\tif (__testlib_shouldCheckDirt(result))\
    \ {\n\t\tif (testlibMode != _interactor && !ouf.seekEof())\n\t\t\tquit(_dirt,\
    \ \"Extra information in the output file\");\n\t}\n\n\tint pctype = result - _partially;\n\
    \tbool isPartial = false;\n\n\tswitch (result) {\n\t\tcase _ok:\n\t\t\terrorName\
    \ = \"ok \";\n\t\t\tquitscrS(LightGreen, errorName);\n\t\t\tbreak;\n\t\tcase _wa:\n\
    \t\t\terrorName = \"wrong answer \";\n\t\t\tquitscrS(LightRed, errorName);\n\t\
    \t\tbreak;\n\t\tcase _pe:\n\t\t\terrorName = \"wrong output format \";\n\t\t\t\
    quitscrS(LightRed, errorName);\n\t\t\tbreak;\n\t\tcase _fail:\n\t\t\terrorName\
    \ = \"FAIL \";\n\t\t\tquitscrS(LightRed, errorName);\n\t\t\tbreak;\n\t\tcase _dirt:\n\
    \t\t\terrorName = \"wrong output format \";\n\t\t\tquitscrS(LightCyan, errorName);\n\
    \t\t\tresult = _pe;\n\t\t\tbreak;\n\t\tcase _points:\n\t\t\terrorName = \"points\
    \ \";\n\t\t\tquitscrS(LightYellow, errorName);\n\t\t\tbreak;\n\t\tcase _unexpected_eof:\n\
    \t\t\terrorName = \"unexpected eof \";\n\t\t\tquitscrS(LightCyan, errorName);\n\
    \t\t\tbreak;\n\t\tdefault:\n\t\t\tif (result >= _partially) {\n\t\t\t\terrorName\
    \ = format(\"partially correct (%d) \", pctype);\n\t\t\t\tisPartial = true;\n\t\
    \t\t\tquitscrS(LightYellow, errorName);\n\t\t\t} else\n\t\t\t\tquit(_fail, \"\
    What is the code ??? \");\n\t}\n\n\tif (resultName != \"\") {\n\t\tresultFile\
    \ = std::fopen(resultName.c_str(), \"w\");\n\t\tif (resultFile == NULL) {\n\t\t\
    \tresultName = \"\";\n\t\t\tquit(_fail, \"Can not write to the result file\");\n\
    \t\t}\n\t\tif (appesMode) {\n\t\t\tstd::fprintf(resultFile, \"<?xml version=\\\
    \"1.0\\\" encoding=\\\"windows-1251\\\"?>\");\n\t\t\tif (isPartial)\n\t\t\t\t\
    std::fprintf(resultFile, \"<result outcome = \\\"%s\\\" pctype = \\\"%d\\\">\"\
    ,\n\t\t\t\t\t\t\t outcomes[(int) _partially].c_str(), pctype);\n\t\t\telse {\n\
    \t\t\t\tif (result != _points)\n\t\t\t\t\tstd::fprintf(resultFile, \"<result outcome\
    \ = \\\"%s\\\">\", outcomes[(int) result].c_str());\n\t\t\t\telse {\n\t\t\t\t\t\
    if (__testlib_points == std::numeric_limits<float>::infinity())\n\t\t\t\t\t\t\
    quit(_fail, \"Expected points, but infinity found\");\n\t\t\t\t\tstd::string stringPoints\
    \ = removeDoubleTrailingZeroes(format(\"%.10f\", __testlib_points));\n\t\t\t\t\
    \tstd::fprintf(resultFile, \"<result outcome = \\\"%s\\\" points = \\\"%s\\\"\
    >\",\n\t\t\t\t\t\t\t\t outcomes[(int) result].c_str(), stringPoints.c_str());\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\txmlSafeWrite(resultFile, __testlib_toPrintableMessage(message).c_str());\n\
    \t\t\tstd::fprintf(resultFile, \"</result>\\n\");\n\t\t} else\n\t\t\tstd::fprintf(resultFile,\
    \ \"%s\", __testlib_toPrintableMessage(message).c_str());\n\t\tif (NULL == resultFile\
    \ || fclose(resultFile) != 0) {\n\t\t\tresultName = \"\";\n\t\t\tquit(_fail, \"\
    Can not write to the result file\");\n\t\t}\n\t}\n\n\tquitscr(LightGray, __testlib_toPrintableMessage(message).c_str());\n\
    \tstd::fprintf(stderr, \"\\n\");\n\n\tinf.close();\n\touf.close();\n\tans.close();\n\
    \tif (tout.is_open())\n\t\ttout.close();\n\n\ttextColor(LightGray);\n\n\tif (resultName\
    \ != \"\")\n\t\tstd::fprintf(stderr, \"See file to check exit message\\n\");\n\
    \n\thalt(resultExitCode(result));\n}\n\n#ifdef __GNUC__\n__attribute__ ((format\
    \ (printf, 3, 4)))\n#endif\nNORETURN void InStream::quitf(TResult result, const\
    \ char *msg, ...) {\n\tFMT_TO_RESULT(msg, msg, message);\n\tInStream::quit(result,\
    \ message.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 4,\
    \ 5)))\n#endif\nvoid InStream::quitif(bool condition, TResult result, const char\
    \ *msg, ...) {\n\tif (condition) {\n\t\tFMT_TO_RESULT(msg, msg, message);\n\t\t\
    InStream::quit(result, message.c_str());\n\t}\n}\n\nNORETURN void InStream::quits(TResult\
    \ result, std::string msg) {\n\tInStream::quit(result, msg.c_str());\n}\n\nvoid\
    \ InStream::xmlSafeWrite(std::FILE *file, const char *msg) {\n\tsize_t lmsg =\
    \ strlen(msg);\n\tfor (size_t i = 0; i < lmsg; i++) {\n\t\tif (msg[i] == '&')\
    \ {\n\t\t\tstd::fprintf(file, \"%s\", \"&amp;\");\n\t\t\tcontinue;\n\t\t}\n\t\t\
    if (msg[i] == '<') {\n\t\t\tstd::fprintf(file, \"%s\", \"&lt;\");\n\t\t\tcontinue;\n\
    \t\t}\n\t\tif (msg[i] == '>') {\n\t\t\tstd::fprintf(file, \"%s\", \"&gt;\");\n\
    \t\t\tcontinue;\n\t\t}\n\t\tif (msg[i] == '\"') {\n\t\t\tstd::fprintf(file, \"\
    %s\", \"&quot;\");\n\t\t\tcontinue;\n\t\t}\n\t\tif (0 <= msg[i] && msg[i] <= 31)\
    \ {\n\t\t\tstd::fprintf(file, \"%c\", '.');\n\t\t\tcontinue;\n\t\t}\n\t\tstd::fprintf(file,\
    \ \"%c\", msg[i]);\n\t}\n}\n\nvoid InStream::quitscrS(WORD color, std::string\
    \ msg) {\n\tquitscr(color, msg.c_str());\n}\n\nvoid InStream::quitscr(WORD color,\
    \ const char *msg) {\n\tif (resultName == \"\") {\n\t\ttextColor(color);\n\t\t\
    std::fprintf(stderr, \"%s\", msg);\n\t\ttextColor(LightGray);\n\t}\n}\n\nvoid\
    \ InStream::reset(std::FILE *file) {\n\tif (opened && stdfile)\n\t\tquit(_fail,\
    \ \"Can't reset standard handle\");\n\n\tif (opened)\n\t\tclose();\n\n\tif (!stdfile)\n\
    \t\tif (NULL == (file = std::fopen(name.c_str(), \"rb\"))) {\n\t\t\tif (mode ==\
    \ _output)\n\t\t\t\tquits(_pe, std::string(\"Output file not found: \\\"\") +\
    \ name + \"\\\"\");\n\n\t\t\tif (mode == _answer)\n\t\t\t\tquits(_fail, std::string(\"\
    Answer file not found: \\\"\") + name + \"\\\"\");\n\t\t}\n\n\tif (NULL != file)\
    \ {\n\t\topened = true;\n\n\t\t__testlib_set_binary(file);\n\n\t\tif (stdfile)\n\
    \t\t\treader = new FileInputStreamReader(file, name);\n\t\telse\n\t\t\treader\
    \ = new BufferedFileInputStreamReader(file, name);\n\t} else {\n\t\topened = false;\n\
    \t\treader = NULL;\n\t}\n}\n\nvoid InStream::init(std::string fileName, TMode\
    \ mode) {\n\topened = false;\n\tname = fileName;\n\tstdfile = false;\n\tthis->mode\
    \ = mode;\n\n\tstd::ifstream stream;\n\tstream.open(fileName.c_str(), std::ios::in);\n\
    \tif (stream.is_open()) {\n\t\tstd::streampos start = stream.tellg();\n\t\tstream.seekg(0,\
    \ std::ios::end);\n\t\tstd::streampos end = stream.tellg();\n\t\tsize_t fileSize\
    \ = size_t(end - start);\n\t\tstream.close();\n\n\t\t// You can change maxFileSize.\n\
    \t\t// Example: 'inf.maxFileSize = 256 * 1024 * 1024;'.\n\t\tif (fileSize > maxFileSize)\n\
    \t\t\tquitf(_pe, \"File size exceeds %d bytes, size is %d\", int(maxFileSize),\
    \ int(fileSize));\n\t}\n\n\treset();\n}\n\nvoid InStream::init(std::FILE *f, TMode\
    \ mode) {\n\topened = false;\n\tname = \"untitled\";\n\tthis->mode = mode;\n\n\
    \tif (f == stdin)\n\t\tname = \"stdin\", stdfile = true;\n\tif (f == stdout)\n\
    \t\tname = \"stdout\", stdfile = true;\n\tif (f == stderr)\n\t\tname = \"stderr\"\
    , stdfile = true;\n\n\treset(f);\n}\n\nchar InStream::curChar() {\n\treturn char(reader->curChar());\n\
    }\n\nchar InStream::nextChar() {\n\treturn char(reader->nextChar());\n}\n\nchar\
    \ InStream::readChar() {\n\treturn nextChar();\n}\n\nchar InStream::readChar(char\
    \ c) {\n\tlastLine = reader->getLine();\n\tchar found = readChar();\n\tif (c !=\
    \ found) {\n\t\tif (!isEoln(found))\n\t\t\tquit(_pe, (\"Unexpected character '\"\
    \ + std::string(1, found) + \"', but '\" + std::string(1, c) +\n\t\t\t\t\t   \"\
    ' expected\").c_str());\n\t\telse\n\t\t\tquit(_pe, (\"Unexpected character \"\
    \ + (\"#\" + vtos(int(found))) + \", but '\" + std::string(1, c) +\n\t\t\t\t\t\
    \   \"' expected\").c_str());\n\t}\n\treturn found;\n}\n\nchar InStream::readSpace()\
    \ {\n\treturn readChar(' ');\n}\n\nvoid InStream::unreadChar(char c) {\n\treader->unreadChar(c);\n\
    }\n\nvoid InStream::skipChar() {\n\treader->skipChar();\n}\n\nvoid InStream::skipBlanks()\
    \ {\n\twhile (isBlanks(reader->curChar()))\n\t\treader->skipChar();\n}\n\nstd::string\
    \ InStream::readWord() {\n\treadWordTo(_tmpReadToken);\n\treturn _tmpReadToken;\n\
    }\n\nvoid InStream::readWordTo(std::string &result) {\n\tif (!strict)\n\t\tskipBlanks();\n\
    \n\tlastLine = reader->getLine();\n\tint cur = reader->nextChar();\n\n\tif (cur\
    \ == EOFC)\n\t\tquit(_unexpected_eof, \"Unexpected end of file - token expected\"\
    );\n\n\tif (isBlanks(cur))\n\t\tquit(_pe, \"Unexpected white-space - token expected\"\
    );\n\n\tresult.clear();\n\n\twhile (!(isBlanks(cur) || cur == EOFC)) {\n\t\tresult\
    \ += char(cur);\n\n\t\t// You can change maxTokenLength.\n\t\t// Example: 'inf.maxTokenLength\
    \ = 128 * 1024 * 1024;'.\n\t\tif (result.length() > maxTokenLength)\n\t\t\tquitf(_pe,\
    \ \"Length of token exceeds %d, token is '%s...'\", int(maxTokenLength),\n\t\t\
    \t\t  __testlib_part(result).c_str());\n\n\t\tcur = reader->nextChar();\n\t}\n\
    \n\treader->unreadChar(cur);\n\n\tif (result.length() == 0)\n\t\tquit(_unexpected_eof,\
    \ \"Unexpected end of file or white-space - token expected\");\n}\n\nstd::string\
    \ InStream::readToken() {\n\treturn readWord();\n}\n\nvoid InStream::readTokenTo(std::string\
    \ &result) {\n\treadWordTo(result);\n}\n\nstatic std::string __testlib_part(const\
    \ std::string &s) {\n\tif (s.length() <= 64)\n\t\treturn s;\n\telse\n\t\treturn\
    \ s.substr(0, 30) + \"...\" + s.substr(s.length() - 31, 31);\n}\n\n#define __testlib_readMany(readMany,\
    \ readOne, typeName, space)\t\t\t\t  \\\n\tif (size < 0)\t\t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t   \\\n\t\tquit(_fail, #readMany \": size should be non-negative.\");\t\
    \t\t\t\\\n\tif (size > 100000000)\t\t\t\t\t\t\t\t\t\t\t\t\t   \\\n\t\tquit(_fail,\
    \ #readMany \": size should be at most 100000000.\");\t\t   \\\n\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\tstd::vector<typeName> result(size);\t\t\t\t\t\t\
    \t\t\t\t \\\n\treadManyIteration = indexBase;\t\t\t\t\t\t\t\t\t\t\t  \\\n\t\t\t\
    \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\tfor (int i = 0; i < size; i++)\t\t\t\t\
    \t\t\t\t\t\t\t  \\\n\t{\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   \\\n\t\tresult[i]\
    \ = readOne;\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\t\treadManyIteration++;\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\\\n\t\tif (strict && space && i + 1 < size)\t\t\t\t\t\t\t\t\t\t\
    \t  \\\n\t\t\treadSpace();\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\t}\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t\t\t\t\t   \\\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\\\n\treadManyIteration\
    \ = NO_INDEX;\t\t\t\t\t\t\t\t\t\t\t   \\\n\treturn result;\t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\t  \\\n\n\nstd::string InStream::readWord(const pattern &p, const std::string\
    \ &variableName) {\n\treadWordTo(_tmpReadToken);\n\tif (!p.matches(_tmpReadToken))\
    \ {\n\t\tif (readManyIteration == NO_INDEX) {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Token \\\"\" + __testlib_part(_tmpReadToken)\
    \ + \"\\\" doesn't correspond to pattern \\\"\" + p.src() +\n\t\t\t\t\t  \"\\\"\
    \").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa, (\"Token parameter [name=\" + variableName\
    \ + \"] equals to \\\"\" + __testlib_part(_tmpReadToken) +\n\t\t\t\t\t\t   \"\\\
    \", doesn't correspond to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n\t\t\
    } else {\n\t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa, (\"Token element\
    \ [index=\" + vtos(readManyIteration) + \"] equals to \\\"\" +\n\t\t\t\t\t\t \
    \  __testlib_part(_tmpReadToken) + \"\\\" doesn't correspond to pattern \\\"\"\
    \ + p.src() +\n\t\t\t\t\t\t   \"\\\"\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\
    \ (\"Token element \" + variableName + \"[\" + vtos(readManyIteration) + \"] equals\
    \ to \\\"\" +\n\t\t\t\t\t\t   __testlib_part(_tmpReadToken) + \"\\\", doesn't\
    \ correspond to pattern \\\"\" + p.src() +\n\t\t\t\t\t\t   \"\\\"\").c_str());\n\
    \t\t}\n\t}\n\treturn _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readWords(int\
    \ size, const pattern &p, const std::string &variablesName, int indexBase) {\n\
    \t__testlib_readMany(readWords, readWord(p, variablesName), std::string, true);\n\
    }\n\nstd::vector<std::string> InStream::readWords(int size, int indexBase) {\n\
    \t__testlib_readMany(readWords, readWord(), std::string, true);\n}\n\nstd::string\
    \ InStream::readWord(const std::string &ptrn, const std::string &variableName)\
    \ {\n\treturn readWord(pattern(ptrn), variableName);\n}\n\nstd::vector<std::string>\n\
    InStream::readWords(int size, const std::string &ptrn, const std::string &variablesName,\
    \ int indexBase) {\n\tpattern p(ptrn);\n\t__testlib_readMany(readWords, readWord(p,\
    \ variablesName), std::string, true);\n}\n\nstd::string InStream::readToken(const\
    \ pattern &p, const std::string &variableName) {\n\treturn readWord(p, variableName);\n\
    }\n\nstd::vector<std::string>\nInStream::readTokens(int size, const pattern &p,\
    \ const std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readTokens,\
    \ readToken(p, variablesName), std::string, true);\n}\n\nstd::vector<std::string>\
    \ InStream::readTokens(int size, int indexBase) {\n\t__testlib_readMany(readTokens,\
    \ readToken(), std::string, true);\n}\n\nstd::string InStream::readToken(const\
    \ std::string &ptrn, const std::string &variableName) {\n\treturn readWord(ptrn,\
    \ variableName);\n}\n\nstd::vector<std::string>\nInStream::readTokens(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \tpattern p(ptrn);\n\t__testlib_readMany(readTokens, readWord(p, variablesName),\
    \ std::string, true);\n}\n\nvoid InStream::readWordTo(std::string &result, const\
    \ pattern &p, const std::string &variableName) {\n\treadWordTo(result);\n\tif\
    \ (!p.matches(result)) {\n\t\tif (variableName.empty())\n\t\t\tquit(_wa, (\"Token\
    \ \\\"\" + __testlib_part(result) + \"\\\" doesn't correspond to pattern \\\"\"\
    \ + p.src() +\n\t\t\t\t\t   \"\\\"\").c_str());\n\t\telse\n\t\t\tquit(_wa, (\"\
    Token parameter [name=\" + variableName + \"] equals to \\\"\" + __testlib_part(result)\
    \ +\n\t\t\t\t\t   \"\\\", doesn't correspond to pattern \\\"\" + p.src() + \"\\\
    \"\").c_str());\n\t}\n}\n\nvoid InStream::readWordTo(std::string &result, const\
    \ std::string &ptrn, const std::string &variableName) {\n\treturn readWordTo(result,\
    \ pattern(ptrn), variableName);\n}\n\nvoid InStream::readTokenTo(std::string &result,\
    \ const pattern &p, const std::string &variableName) {\n\treturn readWordTo(result,\
    \ p, variableName);\n}\n\nvoid InStream::readTokenTo(std::string &result, const\
    \ std::string &ptrn, const std::string &variableName) {\n\treturn readWordTo(result,\
    \ ptrn, variableName);\n}\n\n#ifdef __GNUC__\n__attribute__((pure))\n#endif\n\
    static inline bool equals(long long integer, const char *s) {\n\tif (integer ==\
    \ LLONG_MIN)\n\t\treturn strcmp(s, \"-9223372036854775808\") == 0;\n\n\tif (integer\
    \ == 0LL)\n\t\treturn strcmp(s, \"0\") == 0;\n\n\tsize_t length = strlen(s);\n\
    \n\tif (length == 0)\n\t\treturn false;\n\n\tif (integer < 0 && s[0] != '-')\n\
    \t\treturn false;\n\n\tif (integer < 0)\n\t\ts++, length--, integer = -integer;\n\
    \n\tif (length == 0)\n\t\treturn false;\n\n\twhile (integer > 0) {\n\t\tint digit\
    \ = int(integer % 10);\n\n\t\tif (s[length - 1] != '0' + digit)\n\t\t\treturn\
    \ false;\n\n\t\tlength--;\n\t\tinteger /= 10;\n\t}\n\n\treturn length == 0;\n\
    }\n\n#ifdef __GNUC__\n__attribute__((pure))\n#endif\nstatic inline bool equals(unsigned\
    \ long long integer, const char *s) {\n\tif (integer == ULLONG_MAX)\n\t\treturn\
    \ strcmp(s, \"18446744073709551615\") == 0;\n\n\tif (integer == 0ULL)\n\t\treturn\
    \ strcmp(s, \"0\") == 0;\n\n\tsize_t length = strlen(s);\n\n\tif (length == 0)\n\
    \t\treturn false;\n\n\twhile (integer > 0) {\n\t\tint digit = int(integer % 10);\n\
    \n\t\tif (s[length - 1] != '0' + digit)\n\t\t\treturn false;\n\n\t\tlength--;\n\
    \t\tinteger /= 10;\n\t}\n\n\treturn length == 0;\n}\n\nstatic inline double stringToDouble(InStream\
    \ &in, const char *buffer) {\n\tdouble retval;\n\n\tsize_t length = strlen(buffer);\n\
    \n\tint minusCount = 0;\n\tint plusCount = 0;\n\tint decimalPointCount = 0;\n\t\
    int digitCount = 0;\n\tint eCount = 0;\n\n\tfor (size_t i = 0; i < length; i++)\
    \ {\n\t\tif (('0' <= buffer[i] && buffer[i] <= '9') || buffer[i] == '.'\n\t\t\t\
    || buffer[i] == 'e' || buffer[i] == 'E'\n\t\t\t|| buffer[i] == '-' || buffer[i]\
    \ == '+') {\n\t\t\tif ('0' <= buffer[i] && buffer[i] <= '9')\n\t\t\t\tdigitCount++;\n\
    \t\t\tif (buffer[i] == 'e' || buffer[i] == 'E')\n\t\t\t\teCount++;\n\t\t\tif (buffer[i]\
    \ == '-')\n\t\t\t\tminusCount++;\n\t\t\tif (buffer[i] == '+')\n\t\t\t\tplusCount++;\n\
    \t\t\tif (buffer[i] == '.')\n\t\t\t\tdecimalPointCount++;\n\t\t} else\n\t\t\t\
    in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\"\
    \ found\").c_str());\n\t}\n\n\t// If for sure is not a number in standard notation\
    \ or in e-notation.\n\tif (digitCount == 0 || minusCount > 2 || plusCount > 2\
    \ || decimalPointCount > 1 || eCount > 1)\n\t\tin.quit(_pe, (\"Expected double,\
    \ but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n\tchar *suffix\
    \ = new char[length + 1];\n\tint scanned = std::sscanf(buffer, \"%lf%s\", &retval,\
    \ suffix);\n\tbool empty = strlen(suffix) == 0;\n\tdelete[] suffix;\n\n\tif (scanned\
    \ == 1 || (scanned == 2 && empty)) {\n\t\tif (__testlib_isNaN(retval))\n\t\t\t\
    in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\"\
    \ found\").c_str());\n\t\treturn retval;\n\t} else\n\t\tin.quit(_pe, (\"Expected\
    \ double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n}\n\
    \nstatic inline double\nstringToStrictDouble(InStream &in, const char *buffer,\
    \ int minAfterPointDigitCount, int maxAfterPointDigitCount) {\n\tif (minAfterPointDigitCount\
    \ < 0)\n\t\tin.quit(_fail, \"stringToStrictDouble: minAfterPointDigitCount should\
    \ be non-negative.\");\n\n\tif (minAfterPointDigitCount > maxAfterPointDigitCount)\n\
    \t\tin.quit(_fail,\n\t\t\t\t\"stringToStrictDouble: minAfterPointDigitCount should\
    \ be less or equal to maxAfterPointDigitCount.\");\n\n\tdouble retval;\n\n\tsize_t\
    \ length = strlen(buffer);\n\n\tif (length == 0 || length > 1000)\n\t\tin.quit(_pe,\
    \ (\"Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n\tif (buffer[0] != '-' && (buffer[0] < '0' || buffer[0] > '9'))\n\
    \t\tin.quit(_pe, (\"Expected strict double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n\tint pointPos = -1;\n\tfor (size_t i = 1; i\
    \ + 1 < length; i++) {\n\t\tif (buffer[i] == '.') {\n\t\t\tif (pointPos > -1)\n\
    \t\t\t\tin.quit(_pe, (\"Expected strict double, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\t\t\tpointPos = int(i);\n\t\t}\n\t\tif (buffer[i]\
    \ != '.' && (buffer[i] < '0' || buffer[i] > '9'))\n\t\t\tin.quit(_pe, (\"Expected\
    \ strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \t}\n\n\tif (buffer[length - 1] < '0' || buffer[length - 1] > '9')\n\t\tin.quit(_pe,\
    \ (\"Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n\tint afterDigitsCount = (pointPos == -1 ? 0 : int(length) - pointPos\
    \ - 1);\n\tif (afterDigitsCount < minAfterPointDigitCount || afterDigitsCount\
    \ > maxAfterPointDigitCount)\n\t\tin.quit(_pe, (\"Expected strict double with\
    \ number of digits after point in range [\"\n\t\t\t\t\t  + vtos(minAfterPointDigitCount)\n\
    \t\t\t\t\t  + \",\"\n\t\t\t\t\t  + vtos(maxAfterPointDigitCount)\n\t\t\t\t\t \
    \ + \"], but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str()\n\t\t);\n\
    \n\tint firstDigitPos = -1;\n\tfor (size_t i = 0; i < length; i++)\n\t\tif (buffer[i]\
    \ >= '0' && buffer[i] <= '9') {\n\t\t\tfirstDigitPos = int(i);\n\t\t\tbreak;\n\
    \t\t}\n\n\tif (firstDigitPos > 1 || firstDigitPos == -1)\n\t\tin.quit(_pe, (\"\
    Expected strict double, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \n\tif (buffer[firstDigitPos] == '0' && firstDigitPos + 1 < int(length)\n\t\t\
    && buffer[firstDigitPos + 1] >= '0' && buffer[firstDigitPos + 1] <= '9')\n\t\t\
    in.quit(_pe, (\"Expected strict double, but \\\"\" + __testlib_part(buffer) +\
    \ \"\\\" found\").c_str());\n\n\tchar *suffix = new char[length + 1];\n\tint scanned\
    \ = std::sscanf(buffer, \"%lf%s\", &retval, suffix);\n\tbool empty = strlen(suffix)\
    \ == 0;\n\tdelete[] suffix;\n\n\tif (scanned == 1 || (scanned == 2 && empty))\
    \ {\n\t\tif (__testlib_isNaN(retval) || __testlib_isInfinite(retval))\n\t\t\t\
    in.quit(_pe, (\"Expected double, but \\\"\" + __testlib_part(buffer) + \"\\\"\
    \ found\").c_str());\n\t\tif (buffer[0] == '-' && retval >= 0)\n\t\t\tin.quit(_pe,\
    \ (\"Redundant minus in \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \t\treturn retval;\n\t} else\n\t\tin.quit(_pe, (\"Expected double, but \\\"\"\
    \ + __testlib_part(buffer) + \"\\\" found\").c_str());\n}\n\nstatic inline long\
    \ long stringToLongLong(InStream &in, const char *buffer) {\n\tif (strcmp(buffer,\
    \ \"-9223372036854775808\") == 0)\n\t\treturn LLONG_MIN;\n\n\tbool minus = false;\n\
    \tsize_t length = strlen(buffer);\n\n\tif (length > 1 && buffer[0] == '-')\n\t\
    \tminus = true;\n\n\tif (length > 20)\n\t\tin.quit(_pe, (\"Expected integer, but\
    \ \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n\tlong long retval\
    \ = 0LL;\n\n\tint zeroes = 0;\n\tint processingZeroes = true;\n\n\tfor (int i\
    \ = (minus ? 1 : 0); i < int(length); i++) {\n\t\tif (buffer[i] == '0' && processingZeroes)\n\
    \t\t\tzeroes++;\n\t\telse\n\t\t\tprocessingZeroes = false;\n\n\t\tif (buffer[i]\
    \ < '0' || buffer[i] > '9')\n\t\t\tin.quit(_pe, (\"Expected integer, but \\\"\"\
    \ + __testlib_part(buffer) + \"\\\" found\").c_str());\n\t\tretval = retval *\
    \ 10 + (buffer[i] - '0');\n\t}\n\n\tif (retval < 0)\n\t\tin.quit(_pe, (\"Expected\
    \ integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\n\
    \tif ((zeroes > 0 && (retval != 0 || minus)) || zeroes > 1)\n\t\tin.quit(_pe,\
    \ (\"Expected integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    \n\tretval = (minus ? -retval : +retval);\n\n\tif (length < 19)\n\t\treturn retval;\n\
    \n\tif (equals(retval, buffer))\n\t\treturn retval;\n\telse\n\t\tin.quit(_pe,\
    \ (\"Expected int64, but \\\"\" + __testlib_part(buffer) + \"\\\" found\").c_str());\n\
    }\n\nstatic inline unsigned long long stringToUnsignedLongLong(InStream &in, const\
    \ char *buffer) {\n\tsize_t length = strlen(buffer);\n\n\tif (length > 20)\n\t\
    \tin.quit(_pe, (\"Expected unsigned integer, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\tif (length > 1 && buffer[0] == '0')\n\t\tin.quit(_pe,\
    \ (\"Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\n\tunsigned long long retval = 0LL;\n\tfor (int i = 0; i < int(length);\
    \ i++) {\n\t\tif (buffer[i] < '0' || buffer[i] > '9')\n\t\t\tin.quit(_pe, (\"\
    Expected unsigned integer, but \\\"\" + __testlib_part(buffer) + \"\\\" found\"\
    ).c_str());\n\t\tretval = retval * 10 + (buffer[i] - '0');\n\t}\n\n\tif (length\
    \ < 19)\n\t\treturn retval;\n\n\tif (length == 20 && strcmp(buffer, \"18446744073709551615\"\
    ) == 1)\n\t\tin.quit(_pe, (\"Expected unsigned int64, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n\n\tif (equals(retval, buffer))\n\t\treturn retval;\n\
    \telse\n\t\tin.quit(_pe, (\"Expected unsigned int64, but \\\"\" + __testlib_part(buffer)\
    \ + \"\\\" found\").c_str());\n}\n\nint InStream::readInteger() {\n\tif (!strict\
    \ && seekEof())\n\t\tquit(_unexpected_eof, \"Unexpected end of file - int32 expected\"\
    );\n\n\treadWordTo(_tmpReadToken);\n\n\tlong long value = stringToLongLong(*this,\
    \ _tmpReadToken.c_str());\n\tif (value < INT_MIN || value > INT_MAX)\n\t\tquit(_pe,\
    \ (\"Expected int32, but \\\"\" + __testlib_part(_tmpReadToken) + \"\\\" found\"\
    ).c_str());\n\n\treturn int(value);\n}\n\nlong long InStream::readLong() {\n\t\
    if (!strict && seekEof())\n\t\tquit(_unexpected_eof, \"Unexpected end of file\
    \ - int64 expected\");\n\n\treadWordTo(_tmpReadToken);\n\n\treturn stringToLongLong(*this,\
    \ _tmpReadToken.c_str());\n}\n\nunsigned long long InStream::readUnsignedLong()\
    \ {\n\tif (!strict && seekEof())\n\t\tquit(_unexpected_eof, \"Unexpected end of\
    \ file - int64 expected\");\n\n\treadWordTo(_tmpReadToken);\n\n\treturn stringToUnsignedLongLong(*this,\
    \ _tmpReadToken.c_str());\n}\n\nlong long InStream::readLong(long long minv, long\
    \ long maxv, const std::string &variableName) {\n\tlong long result = readLong();\n\
    \n\tif (result < minv || result > maxv) {\n\t\tif (readManyIteration == NO_INDEX)\
    \ {\n\t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa, (\"Integer \" + vtos(result)\
    \ + \" violates the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa, (\"Integer\
    \ parameter [name=\" + std::string(variableName) + \"] equals to \" + vtos(result)\
    \ +\n\t\t\t\t\t\t   \", violates the range [\" + toHumanReadableString(minv) +\
    \ \", \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t} else {\n\t\t\t\
    if (variableName.empty())\n\t\t\t\tquit(_wa, (\"Integer element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\"\
    \ + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv) + \"]\"\
    ).c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Integer element \" +\
    \ std::string(variableName) + \"[\" + vtos(readManyIteration) + \"] equals to\
    \ \" +\n\t\t\t\t\t  vtos(result) + \", violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t}\n\t}\n\n\t\
    if (strict && !variableName.empty())\n\t\tvalidator.addBoundsHit(variableName,\
    \ ValidatorBoundsHit(minv == result, maxv == result));\n\n\treturn result;\n}\n\
    \nstd::vector<long long>\nInStream::readLongs(int size, long long minv, long long\
    \ maxv, const std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readLongs,\
    \ readLong(minv, maxv, variablesName), long long, true)\n}\n\nstd::vector<long\
    \ long> InStream::readLongs(int size, int indexBase) {\n\t__testlib_readMany(readLongs,\
    \ readLong(), long long, true)\n}\n\nunsigned long long\nInStream::readUnsignedLong(unsigned\
    \ long long minv, unsigned long long maxv, const std::string &variableName) {\n\
    \tunsigned long long result = readUnsignedLong();\n\n\tif (result < minv || result\
    \ > maxv) {\n\t\tif (readManyIteration == NO_INDEX) {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Unsigned integer \" + vtos(result) + \" violates\
    \ the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ +\n\t\t\t\t\t  \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"\
    Unsigned integer parameter [name=\" + std::string(variableName) + \"] equals to\
    \ \" + vtos(result) +\n\t\t\t\t\t  \", violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t} else {\n\t\t\
    \tif (variableName.empty())\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Unsigned integer\
    \ element [index=\" + vtos(readManyIteration) + \"] equals to \" + vtos(result)\
    \ +\n\t\t\t\t\t  \", violates the range [\" + toHumanReadableString(minv) + \"\
    , \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\
    \ (\"Unsigned integer element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ +\n\t\t\t\t\t\t   \"] equals to \" + vtos(result) + \", violates the range [\"\
    \ + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv) +\n\t\t\
    \t\t\t\t   \"]\").c_str());\n\t\t}\n\t}\n\n\tif (strict && !variableName.empty())\n\
    \t\tvalidator.addBoundsHit(variableName, ValidatorBoundsHit(minv == result, maxv\
    \ == result));\n\n\treturn result;\n}\n\nstd::vector<unsigned long long> InStream::readUnsignedLongs(int\
    \ size, unsigned long long minv, unsigned long long maxv,\n\t\t\t\t\t\t\t\t\t\t\
    \t\t\t\t\tconst std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readUnsignedLongs,\
    \ readUnsignedLong(minv, maxv, variablesName), unsigned long long, true)\n}\n\n\
    std::vector<unsigned long long> InStream::readUnsignedLongs(int size, int indexBase)\
    \ {\n\t__testlib_readMany(readUnsignedLongs, readUnsignedLong(), unsigned long\
    \ long, true)\n}\n\nunsigned long long\nInStream::readLong(unsigned long long\
    \ minv, unsigned long long maxv, const std::string &variableName) {\n\treturn\
    \ readUnsignedLong(minv, maxv, variableName);\n}\n\nint InStream::readInt() {\n\
    \treturn readInteger();\n}\n\nint InStream::readInt(int minv, int maxv, const\
    \ std::string &variableName) {\n\tint result = readInt();\n\n\tif (result < minv\
    \ || result > maxv) {\n\t\tif (readManyIteration == NO_INDEX) {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa, (\"Integer \" + vtos(result) + \" violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\
    \t\telse\n\t\t\t\tquit(_wa, (\"Integer parameter [name=\" + std::string(variableName)\
    \ + \"] equals to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\"\
    \ + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv) + \"]\"\
    ).c_str());\n\t\t} else {\n\t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa,\
    \ (\"Integer element [index=\" + vtos(readManyIteration) + \"] equals to \" +\
    \ vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\" + toHumanReadableString(minv)\
    \ + \", \" + toHumanReadableString(maxv) + \"]\").c_str());\n\t\t\telse\n\t\t\t\
    \tquit(_wa,\n\t\t\t\t\t (\"Integer element \" + std::string(variableName) + \"\
    [\" + vtos(readManyIteration) + \"] equals to \" +\n\t\t\t\t\t  vtos(result) +\
    \ \", violates the range [\" + toHumanReadableString(minv) + \", \" + toHumanReadableString(maxv)\
    \ + \"]\").c_str());\n\t\t}\n\t}\n\n\tif (strict && !variableName.empty())\n\t\
    \tvalidator.addBoundsHit(variableName, ValidatorBoundsHit(minv == result, maxv\
    \ == result));\n\n\treturn result;\n}\n\nint InStream::readInteger(int minv, int\
    \ maxv, const std::string &variableName) {\n\treturn readInt(minv, maxv, variableName);\n\
    }\n\nstd::vector<int> InStream::readInts(int size, int minv, int maxv, const std::string\
    \ &variablesName, int indexBase) {\n\t__testlib_readMany(readInts, readInt(minv,\
    \ maxv, variablesName), int, true)\n}\n\nstd::vector<int> InStream::readInts(int\
    \ size, int indexBase) {\n\t__testlib_readMany(readInts, readInt(), int, true)\n\
    }\n\nstd::vector<int> InStream::readIntegers(int size, int minv, int maxv, const\
    \ std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readIntegers,\
    \ readInt(minv, maxv, variablesName), int, true)\n}\n\nstd::vector<int> InStream::readIntegers(int\
    \ size, int indexBase) {\n\t__testlib_readMany(readIntegers, readInt(), int, true)\n\
    }\n\ndouble InStream::readReal() {\n\tif (!strict && seekEof())\n\t\tquit(_unexpected_eof,\
    \ \"Unexpected end of file - double expected\");\n\n\treturn stringToDouble(*this,\
    \ readWord().c_str());\n}\n\ndouble InStream::readDouble() {\n\treturn readReal();\n\
    }\n\ndouble InStream::readReal(double minv, double maxv, const std::string &variableName)\
    \ {\n\tdouble result = readReal();\n\n\tif (result < minv || result > maxv) {\n\
    \t\tif (readManyIteration == NO_INDEX) {\n\t\t\tif (variableName.empty())\n\t\t\
    \t\tquit(_wa, (\"Double \" + vtos(result) + \" violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\t\telse\n\t\t\t\
    \tquit(_wa, (\"Double parameter [name=\" + std::string(variableName) + \"] equals\
    \ to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t} else {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa, (\"Double element [index=\" + vtos(readManyIteration) + \"]\
    \ equals to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\
    \t\t\t (\"Double element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ + \"] equals to \" +\n\t\t\t\t\t  vtos(result) + \", violates the range [\"\
    \ + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t}\n\t}\n\n\tif (strict\
    \ && !variableName.empty())\n\t\tvalidator.addBoundsHit(variableName, ValidatorBoundsHit(\n\
    \t\t\t\tdoubleDelta(minv, result) < ValidatorBoundsHit::EPS,\n\t\t\t\tdoubleDelta(maxv,\
    \ result) < ValidatorBoundsHit::EPS\n\t\t));\n\n\treturn result;\n}\n\nstd::vector<double>\n\
    InStream::readReals(int size, double minv, double maxv, const std::string &variablesName,\
    \ int indexBase) {\n\t__testlib_readMany(readReals, readReal(minv, maxv, variablesName),\
    \ double, true)\n}\n\nstd::vector<double> InStream::readReals(int size, int indexBase)\
    \ {\n\t__testlib_readMany(readReals, readReal(), double, true)\n}\n\ndouble InStream::readDouble(double\
    \ minv, double maxv, const std::string &variableName) {\n\treturn readReal(minv,\
    \ maxv, variableName);\n}\n\nstd::vector<double>\nInStream::readDoubles(int size,\
    \ double minv, double maxv, const std::string &variablesName, int indexBase) {\n\
    \t__testlib_readMany(readDoubles, readDouble(minv, maxv, variablesName), double,\
    \ true)\n}\n\nstd::vector<double> InStream::readDoubles(int size, int indexBase)\
    \ {\n\t__testlib_readMany(readDoubles, readDouble(), double, true)\n}\n\ndouble\
    \ InStream::readStrictReal(double minv, double maxv,\n\t\t\t\t\t\t\t\tint minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\tconst std::string &variableName)\
    \ {\n\tif (!strict && seekEof())\n\t\tquit(_unexpected_eof, \"Unexpected end of\
    \ file - strict double expected\");\n\n\tdouble result = stringToStrictDouble(*this,\
    \ readWord().c_str(),\n\t\t\t\t\t\t\t\t\t\t minAfterPointDigitCount, maxAfterPointDigitCount);\n\
    \n\tif (result < minv || result > maxv) {\n\t\tif (readManyIteration == NO_INDEX)\
    \ {\n\t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa, (\"Strict double \" +\
    \ vtos(result) + \" violates the range [\" + vtos(minv) + \", \" + vtos(maxv)\
    \ +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\t\t\t\
    \ (\"Strict double parameter [name=\" + std::string(variableName) + \"] equals\
    \ to \" + vtos(result) +\n\t\t\t\t\t  \", violates the range [\" + vtos(minv)\
    \ + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t} else {\n\t\t\tif (variableName.empty())\n\
    \t\t\t\tquit(_wa, (\"Strict double element [index=\" + vtos(readManyIteration)\
    \ + \"] equals to \" + vtos(result) +\n\t\t\t\t\t\t   \", violates the range [\"\
    \ + vtos(minv) + \", \" + vtos(maxv) + \"]\").c_str());\n\t\t\telse\n\t\t\t\t\
    quit(_wa, (\"Strict double element \" + std::string(variableName) + \"[\" + vtos(readManyIteration)\
    \ +\n\t\t\t\t\t\t   \"] equals to \" + vtos(result) + \", violates the range [\"\
    \ + vtos(minv) + \", \" + vtos(maxv) +\n\t\t\t\t\t\t   \"]\").c_str());\n\t\t\
    }\n\t}\n\n\tif (strict && !variableName.empty())\n\t\tvalidator.addBoundsHit(variableName,\
    \ ValidatorBoundsHit(\n\t\t\t\tdoubleDelta(minv, result) < ValidatorBoundsHit::EPS,\n\
    \t\t\t\tdoubleDelta(maxv, result) < ValidatorBoundsHit::EPS\n\t\t));\n\n\treturn\
    \ result;\n}\n\nstd::vector<double> InStream::readStrictReals(int size, double\
    \ minv, double maxv,\n\t\t\t\t\t\t\t\t\t\t\t  int minAfterPointDigitCount, int\
    \ maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\t\t\t\t  const std::string &variablesName,\
    \ int indexBase) {\n\t__testlib_readMany(readStrictReals,\n\t\t\t\t\t   readStrictReal(minv,\
    \ maxv, minAfterPointDigitCount, maxAfterPointDigitCount, variablesName),\n\t\t\
    \t\t\t   double, true)\n}\n\ndouble InStream::readStrictDouble(double minv, double\
    \ maxv,\n\t\t\t\t\t\t\t\t  int minAfterPointDigitCount, int maxAfterPointDigitCount,\n\
    \t\t\t\t\t\t\t\t  const std::string &variableName) {\n\treturn readStrictReal(minv,\
    \ maxv,\n\t\t\t\t\t\t  minAfterPointDigitCount, maxAfterPointDigitCount,\n\t\t\
    \t\t\t\t  variableName);\n}\n\nstd::vector<double> InStream::readStrictDoubles(int\
    \ size, double minv, double maxv,\n\t\t\t\t\t\t\t\t\t\t\t\tint minAfterPointDigitCount,\
    \ int maxAfterPointDigitCount,\n\t\t\t\t\t\t\t\t\t\t\t\tconst std::string &variablesName,\
    \ int indexBase) {\n\t__testlib_readMany(readStrictDoubles,\n\t\t\t\t\t   readStrictDouble(minv,\
    \ maxv, minAfterPointDigitCount, maxAfterPointDigitCount, variablesName),\n\t\t\
    \t\t\t   double, true)\n}\n\nbool InStream::eof() {\n\tif (!strict && NULL ==\
    \ reader)\n\t\treturn true;\n\n\treturn reader->eof();\n}\n\nbool InStream::seekEof()\
    \ {\n\tif (!strict && NULL == reader)\n\t\treturn true;\n\tskipBlanks();\n\treturn\
    \ eof();\n}\n\nbool InStream::eoln() {\n\tif (!strict && NULL == reader)\n\t\t\
    return true;\n\n\tint c = reader->nextChar();\n\n\tif (!strict) {\n\t\tif (c ==\
    \ EOFC)\n\t\t\treturn true;\n\n\t\tif (c == CR) {\n\t\t\tc = reader->nextChar();\n\
    \n\t\t\tif (c != LF) {\n\t\t\t\treader->unreadChar(c);\n\t\t\t\treader->unreadChar(CR);\n\
    \t\t\t\treturn false;\n\t\t\t} else\n\t\t\t\treturn true;\n\t\t}\n\n\t\tif (c\
    \ == LF)\n\t\t\treturn true;\n\n\t\treader->unreadChar(c);\n\t\treturn false;\n\
    \t} else {\n\t\tbool returnCr = false;\n\n#if (defined(ON_WINDOWS) && !defined(FOR_LINUX))\
    \ || defined(FOR_WINDOWS)\n\t\tif (c != CR) {\n\t\t\treader->unreadChar(c);\n\t\
    \t\treturn false;\n\t\t} else {\n\t\t\tif (!returnCr)\n\t\t\t\treturnCr = true;\n\
    \t\t\tc = reader->nextChar();\n\t\t}\n#endif\n\t\tif (c != LF) {\n\t\t\treader->unreadChar(c);\n\
    \t\t\tif (returnCr)\n\t\t\t\treader->unreadChar(CR);\n\t\t\treturn false;\n\t\t\
    }\n\n\t\treturn true;\n\t}\n}\n\nvoid InStream::readEoln() {\n\tlastLine = reader->getLine();\n\
    \tif (!eoln())\n\t\tquit(_pe, \"Expected EOLN\");\n}\n\nvoid InStream::readEof()\
    \ {\n\tlastLine = reader->getLine();\n\tif (!eof())\n\t\tquit(_pe, \"Expected\
    \ EOF\");\n\n\tif (TestlibFinalizeGuard::alive && this == &inf)\n\t\ttestlibFinalizeGuard.readEofCount++;\n\
    }\n\nbool InStream::seekEoln() {\n\tif (!strict && NULL == reader)\n\t\treturn\
    \ true;\n\n\tint cur;\n\tdo {\n\t\tcur = reader->nextChar();\n\t} while (cur ==\
    \ SPACE || cur == TAB);\n\n\treader->unreadChar(cur);\n\treturn eoln();\n}\n\n\
    void InStream::nextLine() {\n\treadLine();\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result) {\n\tif (NULL == reader)\n\t\tquit(_pe, \"Expected line\");\n\n\tresult.clear();\n\
    \n\tfor (;;) {\n\t\tint cur = reader->curChar();\n\n\t\tif (cur == LF || cur ==\
    \ EOFC)\n\t\t\tbreak;\n\n\t\tif (cur == CR) {\n\t\t\tcur = reader->nextChar();\n\
    \t\t\tif (reader->curChar() == LF) {\n\t\t\t\treader->unreadChar(cur);\n\t\t\t\
    \tbreak;\n\t\t\t}\n\t\t}\n\n\t\tlastLine = reader->getLine();\n\t\tresult += char(reader->nextChar());\n\
    \t}\n\n\tif (strict)\n\t\treadEoln();\n\telse\n\t\teoln();\n}\n\nstd::string InStream::readString()\
    \ {\n\treadStringTo(_tmpReadToken);\n\treturn _tmpReadToken;\n}\n\nstd::vector<std::string>\
    \ InStream::readStrings(int size, int indexBase) {\n\t__testlib_readMany(readStrings,\
    \ readString(), std::string, false)\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result, const pattern &p, const std::string &variableName) {\n\treadStringTo(result);\n\
    \tif (!p.matches(result)) {\n\t\tif (readManyIteration == NO_INDEX) {\n\t\t\t\
    if (variableName.empty())\n\t\t\t\tquit(_wa, (\"Line \\\"\" + __testlib_part(result)\
    \ + \"\\\" doesn't correspond to pattern \\\"\" + p.src() +\n\t\t\t\t\t\t   \"\
    \\\"\").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa, (\"Line [name=\" + variableName\
    \ + \"] equals to \\\"\" + __testlib_part(result) +\n\t\t\t\t\t\t   \"\\\", doesn't\
    \ correspond to pattern \\\"\" + p.src() + \"\\\"\").c_str());\n\t\t} else {\n\
    \t\t\tif (variableName.empty())\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Line element\
    \ [index=\" + vtos(readManyIteration) + \"] equals to \\\"\" + __testlib_part(result)\
    \ +\n\t\t\t\t\t  \"\\\" doesn't correspond to pattern \\\"\" + p.src() + \"\\\"\
    \").c_str());\n\t\t\telse\n\t\t\t\tquit(_wa,\n\t\t\t\t\t (\"Line element \" +\
    \ std::string(variableName) + \"[\" + vtos(readManyIteration) + \"] equals to\
    \ \\\"\" +\n\t\t\t\t\t  __testlib_part(result) + \"\\\", doesn't correspond to\
    \ pattern \\\"\" + p.src() + \"\\\"\").c_str());\n\t\t}\n\t}\n}\n\nvoid InStream::readStringTo(std::string\
    \ &result, const std::string &ptrn, const std::string &variableName) {\n\treadStringTo(result,\
    \ pattern(ptrn), variableName);\n}\n\nstd::string InStream::readString(const pattern\
    \ &p, const std::string &variableName) {\n\treadStringTo(_tmpReadToken, p, variableName);\n\
    \treturn _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readStrings(int\
    \ size, const pattern &p, const std::string &variablesName, int indexBase) {\n\
    \t__testlib_readMany(readStrings, readString(p, variablesName), std::string, false)\n\
    }\n\nstd::string InStream::readString(const std::string &ptrn, const std::string\
    \ &variableName) {\n\treadStringTo(_tmpReadToken, ptrn, variableName);\n\treturn\
    \ _tmpReadToken;\n}\n\nstd::vector<std::string>\nInStream::readStrings(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \tpattern p(ptrn);\n\t__testlib_readMany(readStrings, readString(p, variablesName),\
    \ std::string, false)\n}\n\nvoid InStream::readLineTo(std::string &result) {\n\
    \treadStringTo(result);\n}\n\nstd::string InStream::readLine() {\n\treturn readString();\n\
    }\n\nstd::vector<std::string> InStream::readLines(int size, int indexBase) {\n\
    \t__testlib_readMany(readLines, readString(), std::string, false)\n}\n\nvoid InStream::readLineTo(std::string\
    \ &result, const pattern &p, const std::string &variableName) {\n\treadStringTo(result,\
    \ p, variableName);\n}\n\nvoid InStream::readLineTo(std::string &result, const\
    \ std::string &ptrn, const std::string &variableName) {\n\treadStringTo(result,\
    \ ptrn, variableName);\n}\n\nstd::string InStream::readLine(const pattern &p,\
    \ const std::string &variableName) {\n\treturn readString(p, variableName);\n\
    }\n\nstd::vector<std::string>\nInStream::readLines(int size, const pattern &p,\
    \ const std::string &variablesName, int indexBase) {\n\t__testlib_readMany(readLines,\
    \ readString(p, variablesName), std::string, false)\n}\n\nstd::string InStream::readLine(const\
    \ std::string &ptrn, const std::string &variableName) {\n\treturn readString(ptrn,\
    \ variableName);\n}\n\nstd::vector<std::string>\nInStream::readLines(int size,\
    \ const std::string &ptrn, const std::string &variablesName, int indexBase) {\n\
    \tpattern p(ptrn);\n\t__testlib_readMany(readLines, readString(p, variablesName),\
    \ std::string, false)\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 3,\
    \ 4)))\n#endif\nvoid InStream::ensuref(bool cond, const char *format, ...) {\n\
    \tif (!cond) {\n\t\tFMT_TO_RESULT(format, format, message);\n\t\tthis->__testlib_ensure(cond,\
    \ message);\n\t}\n}\n\nvoid InStream::__testlib_ensure(bool cond, std::string\
    \ message) {\n\tif (!cond)\n\t\tthis->quit(_wa, message.c_str());\n}\n\nvoid InStream::close()\
    \ {\n\tif (NULL != reader) {\n\t\treader->close();\n\t\tdelete reader;\n\t\treader\
    \ = NULL;\n\t}\n\n\topened = false;\n}\n\nNORETURN void quit(TResult result, const\
    \ std::string &msg) {\n\touf.quit(result, msg.c_str());\n}\n\nNORETURN void quit(TResult\
    \ result, const char *msg) {\n\touf.quit(result, msg);\n}\n\nNORETURN void __testlib_quitp(double\
    \ points, const char *message) {\n\t__testlib_points = points;\n\tstd::string\
    \ stringPoints = removeDoubleTrailingZeroes(format(\"%.10f\", points));\n\n\t\
    std::string quitMessage;\n\tif (NULL == message || 0 == strlen(message))\n\t\t\
    quitMessage = stringPoints;\n\telse\n\t\tquitMessage = stringPoints + \" \" +\
    \ message;\n\n\tquit(_points, quitMessage.c_str());\n}\n\nNORETURN void __testlib_quitp(int\
    \ points, const char *message) {\n\t__testlib_points = points;\n\tstd::string\
    \ stringPoints = format(\"%d\", points);\n\n\tstd::string quitMessage;\n\tif (NULL\
    \ == message || 0 == strlen(message))\n\t\tquitMessage = stringPoints;\n\telse\n\
    \t\tquitMessage = stringPoints + \" \" + message;\n\n\tquit(_points, quitMessage.c_str());\n\
    }\n\nNORETURN void quitp(float points, const std::string &message = \"\") {\n\t\
    __testlib_quitp(double(points), message.c_str());\n}\n\nNORETURN void quitp(double\
    \ points, const std::string &message = \"\") {\n\t__testlib_quitp(points, message.c_str());\n\
    }\n\nNORETURN void quitp(long double points, const std::string &message = \"\"\
    ) {\n\t__testlib_quitp(double(points), message.c_str());\n}\n\nNORETURN void quitp(int\
    \ points, const std::string &message = \"\") {\n\t__testlib_quitp(points, message.c_str());\n\
    }\n\ntemplate<typename F>\n#ifdef __GNUC__\n__attribute__ ((format (printf, 2,\
    \ 3)))\n#endif\nNORETURN void quitp(F points, const char *format, ...) {\n\tFMT_TO_RESULT(format,\
    \ format, message);\n\tquitp(points, message);\n}\n\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 2, 3)))\n#endif\nNORETURN void quitf(TResult result, const\
    \ char *format, ...) {\n\tFMT_TO_RESULT(format, format, message);\n\tquit(result,\
    \ message);\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf, 3, 4)))\n#endif\n\
    void quitif(bool condition, TResult result, const char *format, ...) {\n\tif (condition)\
    \ {\n\t\tFMT_TO_RESULT(format, format, message);\n\t\tquit(result, message);\n\
    \t}\n}\n\nNORETURN void __testlib_help() {\n\tInStream::textColor(InStream::LightCyan);\n\
    \tstd::fprintf(stderr, \"TESTLIB %s, https://github.com/MikeMirzayanov/testlib/\
    \ \", VERSION);\n\tstd::fprintf(stderr, \"by Mike Mirzayanov, copyright(c) 2005-2020\\\
    n\");\n\tstd::fprintf(stderr, \"Checker name: \\\"%s\\\"\\n\", checkerName.c_str());\n\
    \tInStream::textColor(InStream::LightGray);\n\n\tstd::fprintf(stderr, \"\\n\"\
    );\n\tstd::fprintf(stderr, \"Latest features: \\n\");\n\tfor (size_t i = 0; i\
    \ < sizeof(latestFeatures) / sizeof(char *); i++) {\n\t\tstd::fprintf(stderr,\
    \ \"*) %s\\n\", latestFeatures[i]);\n\t}\n\tstd::fprintf(stderr, \"\\n\");\n\n\
    \tstd::fprintf(stderr, \"Program must be run with the following arguments: \\\
    n\");\n\tstd::fprintf(stderr, \"\t<input-file> <output-file> <answer-file> [<report-file>\
    \ [<-appes>]]\\n\\n\");\n\n\tstd::exit(FAIL_EXIT_CODE);\n}\n\nstatic void __testlib_ensuresPreconditions()\
    \ {\n\t// testlib assumes: sizeof(int) = 4.\n\t__TESTLIB_STATIC_ASSERT(sizeof(int)\
    \ == 4);\n\n\t// testlib assumes: INT_MAX == 2147483647.\n\t__TESTLIB_STATIC_ASSERT(INT_MAX\
    \ == 2147483647);\n\n\t// testlib assumes: sizeof(long long) = 8.\n\t__TESTLIB_STATIC_ASSERT(sizeof(long\
    \ long) == 8);\n\n\t// testlib assumes: sizeof(double) = 8.\n\t__TESTLIB_STATIC_ASSERT(sizeof(double)\
    \ == 8);\n\n\t// testlib assumes: no -ffast-math.\n\tif (!__testlib_isNaN(+__testlib_nan()))\n\
    \t\tquit(_fail, \"Function __testlib_isNaN is not working correctly: possible\
    \ reason is '-ffast-math'\");\n\tif (!__testlib_isNaN(-__testlib_nan()))\n\t\t\
    quit(_fail, \"Function __testlib_isNaN is not working correctly: possible reason\
    \ is '-ffast-math'\");\n}\n\nvoid registerGen(int argc, char *argv[], int randomGeneratorVersion)\
    \ {\n\tif (randomGeneratorVersion < 0 || randomGeneratorVersion > 1)\n\t\tquitf(_fail,\
    \ \"Random generator version is expected to be 0 or 1.\");\n\trandom_t::version\
    \ = randomGeneratorVersion;\n\n\t__testlib_ensuresPreconditions();\n\n\ttestlibMode\
    \ = _generator;\n\t__testlib_set_binary(stdin);\n\trnd.setSeed(argc, argv);\n\n\
    #if __cplusplus > 199711L || defined(_MSC_VER)\n\tprepareOpts(argc, argv);\n#endif\n\
    }\n\n#ifdef USE_RND_AS_BEFORE_087\nvoid registerGen(int argc, char* argv[])\n\
    {\n\tregisterGen(argc, argv, 0);\n}\n#else\n#ifdef __GNUC__\n#if (__GNUC__ > 4)\
    \ || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 4))\n__attribute__ ((deprecated(\"\
    Use registerGen(argc, argv, 0) or registerGen(argc, argv, 1).\"\n\" The third\
    \ parameter stands for the random generator version.\"\n\" If you are trying to\
    \ compile old generator use macro -DUSE_RND_AS_BEFORE_087 or registerGen(argc,\
    \ argv, 0).\"\n\" Version 1 has been released on Spring, 2013. Use it to write\
    \ new generators.\")))\n#else\n__attribute__ ((deprecated))\n#endif\n#endif\n\
    #ifdef _MSC_VER\n__declspec(deprecated(\"Use registerGen(argc, argv, 0) or registerGen(argc,\
    \ argv, 1).\"\n\t\t\" The third parameter stands for the random generator version.\"\
    \n\t\t\" If you are trying to compile old generator use macro -DUSE_RND_AS_BEFORE_087\
    \ or registerGen(argc, argv, 0).\"\n\t\t\" Version 1 has been released on Spring,\
    \ 2013. Use it to write new generators.\"))\n#endif\nvoid registerGen(int argc,\
    \ char *argv[]) {\n\tstd::fprintf(stderr, \"Use registerGen(argc, argv, 0) or\
    \ registerGen(argc, argv, 1).\"\n\t\t\t\t\t\t \" The third parameter stands for\
    \ the random generator version.\"\n\t\t\t\t\t\t \" If you are trying to compile\
    \ old generator use macro -DUSE_RND_AS_BEFORE_087 or registerGen(argc, argv, 0).\"\
    \n\t\t\t\t\t\t \" Version 1 has been released on Spring, 2013. Use it to write\
    \ new generators.\\n\\n\");\n\tregisterGen(argc, argv, 0);\n}\n#endif\n\nvoid\
    \ registerInteraction(int argc, char *argv[]) {\n\t__testlib_ensuresPreconditions();\n\
    \n\ttestlibMode = _interactor;\n\t__testlib_set_binary(stdin);\n\n\tif (argc >\
    \ 1 && !strcmp(\"--help\", argv[1]))\n\t\t__testlib_help();\n\n\tif (argc < 3\
    \ || argc > 6) {\n\t\tquit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n\t\t\t\t\tstd::string(\"<input-file> <output-file> [<answer-file>\
    \ [<report-file> [<-appes>]]]\") +\n\t\t\t\t\t\"\\nUse \\\"--help\\\" to get help\
    \ information\");\n\t}\n\n\tif (argc <= 4) {\n\t\tresultName = \"\";\n\t\tappesMode\
    \ = false;\n\t}\n\n#ifndef EJUDGE\n\tif (argc == 5) {\n\t\tresultName = argv[4];\n\
    \t\tappesMode = false;\n\t}\n\n\tif (argc == 6) {\n\t\tif (strcmp(\"-APPES\",\
    \ argv[5]) && strcmp(\"-appes\", argv[5])) {\n\t\t\tquit(_fail, std::string(\"\
    Program must be run with the following arguments: \") +\n\t\t\t\t\t\t\"<input-file>\
    \ <output-file> <answer-file> [<report-file> [<-appes>]]\");\n\t\t} else {\n\t\
    \t\tresultName = argv[4];\n\t\t\tappesMode = true;\n\t\t}\n\t}\n#endif\n\n\tinf.init(argv[1],\
    \ _input);\n\n\ttout.open(argv[2], std::ios_base::out);\n\tif (tout.fail() ||\
    \ !tout.is_open())\n\t\tquit(_fail, std::string(\"Can not write to the test-output-file\
    \ '\") + argv[2] + std::string(\"'\"));\n\n\touf.init(stdin, _output);\n\n\tif\
    \ (argc >= 4)\n\t\tans.init(argv[3], _answer);\n\telse\n\t\tans.name = \"unopened\
    \ answer stream\";\n}\n\nvoid registerValidation() {\n\t__testlib_ensuresPreconditions();\n\
    \n\ttestlibMode = _validator;\n\t__testlib_set_binary(stdin);\n\n\tinf.init(stdin,\
    \ _input);\n\tinf.strict = true;\n}\n\nvoid registerValidation(int argc, char\
    \ *argv[]) {\n\tregisterValidation();\n\tvalidator.initialize();\n\n\tfor (int\
    \ i = 1; i < argc; i++) {\n\t\tif (!strcmp(\"--testset\", argv[i])) {\n\t\t\t\
    if (i + 1 < argc && strlen(argv[i + 1]) > 0)\n\t\t\t\tvalidator.setTestset(argv[++i]);\n\
    \t\t\telse\n\t\t\t\tquit(_fail, std::string(\"Validator must be run with the following\
    \ arguments: \") +\n\t\t\t\t\t\t\t\"[--testset testset] [--group group] [--testOverviewLogFileName\
    \ fileName]\");\n\t\t}\n\t\tif (!strcmp(\"--group\", argv[i])) {\n\t\t\tif (i\
    \ + 1 < argc)\n\t\t\t\tvalidator.setGroup(argv[++i]);\n\t\t\telse\n\t\t\t\tquit(_fail,\
    \ std::string(\"Validator must be run with the following arguments: \") +\n\t\t\
    \t\t\t\t\t\"[--testset testset] [--group group] [--testOverviewLogFileName fileName]\"\
    );\n\t\t}\n\t\tif (!strcmp(\"--testOverviewLogFileName\", argv[i])) {\n\t\t\t\
    if (i + 1 < argc)\n\t\t\t\tvalidator.setTestOverviewLogFileName(argv[++i]);\n\t\
    \t\telse\n\t\t\t\tquit(_fail, std::string(\"Validator must be run with the following\
    \ arguments: \") +\n\t\t\t\t\t\t\t\"[--testset testset] [--group group] [--testOverviewLogFileName\
    \ fileName]\");\n\t\t}\n\t}\n}\n\nvoid addFeature(const std::string &feature)\
    \ {\n\tif (testlibMode != _validator)\n\t\tquit(_fail, \"Features are supported\
    \ in validators only.\");\n\tvalidator.addFeature(feature);\n}\n\nvoid feature(const\
    \ std::string &feature) {\n\tif (testlibMode != _validator)\n\t\tquit(_fail, \"\
    Features are supported in validators only.\");\n\tvalidator.feature(feature);\n\
    }\n\nvoid registerTestlibCmd(int argc, char *argv[]) {\n\t__testlib_ensuresPreconditions();\n\
    \n\ttestlibMode = _checker;\n\t__testlib_set_binary(stdin);\n\n\tif (argc > 1\
    \ && !strcmp(\"--help\", argv[1]))\n\t\t__testlib_help();\n\n\tif (argc < 4 ||\
    \ argc > 6) {\n\t\tquit(_fail, std::string(\"Program must be run with the following\
    \ arguments: \") +\n\t\t\t\t\tstd::string(\"<input-file> <output-file> <answer-file>\
    \ [<report-file> [<-appes>]]\") +\n\t\t\t\t\t\"\\nUse \\\"--help\\\" to get help\
    \ information\");\n\t}\n\n\tif (argc == 4) {\n\t\tresultName = \"\";\n\t\tappesMode\
    \ = false;\n\t}\n\n\tif (argc == 5) {\n\t\tresultName = argv[4];\n\t\tappesMode\
    \ = false;\n\t}\n\n\tif (argc == 6) {\n\t\tif (strcmp(\"-APPES\", argv[5]) &&\
    \ strcmp(\"-appes\", argv[5])) {\n\t\t\tquit(_fail, std::string(\"Program must\
    \ be run with the following arguments: \") +\n\t\t\t\t\t\t\"<input-file> <output-file>\
    \ <answer-file> [<report-file> [<-appes>]]\");\n\t\t} else {\n\t\t\tresultName\
    \ = argv[4];\n\t\t\tappesMode = true;\n\t\t}\n\t}\n\n\tinf.init(argv[1], _input);\n\
    \touf.init(argv[2], _output);\n\tans.init(argv[3], _answer);\n}\n\nvoid registerTestlib(int\
    \ argc, ...) {\n\tif (argc < 3 || argc > 5)\n\t\tquit(_fail, std::string(\"Program\
    \ must be run with the following arguments: \") +\n\t\t\t\t\t\"<input-file> <output-file>\
    \ <answer-file> [<report-file> [<-appes>]]\");\n\n\tchar **argv = new char *[argc\
    \ + 1];\n\n\tva_list ap;\n\tva_start(ap, argc);\n\targv[0] = NULL;\n\tfor (int\
    \ i = 0; i < argc; i++) {\n\t\targv[i + 1] = va_arg(ap, char*);\n\t}\n\tva_end(ap);\n\
    \n\tregisterTestlibCmd(argc + 1, argv);\n\tdelete[] argv;\n}\n\nstatic inline\
    \ void __testlib_ensure(bool cond, const std::string &msg) {\n\tif (!cond)\n\t\
    \tquit(_fail, msg.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__((unused))\n#endif\n\
    static inline void __testlib_ensure(bool cond, const char *msg) {\n\tif (!cond)\n\
    \t\tquit(_fail, msg);\n}\n\n#define ensure(cond) __testlib_ensure(cond, \"Condition\
    \ failed: \\\"\" #cond \"\\\"\")\n#define STRINGIZE_DETAIL(x) #x\n#define STRINGIZE(x)\
    \ STRINGIZE_DETAIL(x)\n#define ensure_ext(cond) __testlib_ensure(cond, \"Line\
    \ \" STRINGIZE(__LINE__) \": Condition failed: \\\"\" #cond \"\\\"\")\n\n#ifdef\
    \ __GNUC__\n__attribute__ ((format (printf, 2, 3)))\n#endif\ninline void ensuref(bool\
    \ cond, const char *format, ...) {\n\tif (!cond) {\n\t\tFMT_TO_RESULT(format,\
    \ format, message);\n\t\t__testlib_ensure(cond, message);\n\t}\n}\n\nNORETURN\
    \ static void __testlib_fail(const std::string &message) {\n\tquitf(_fail, \"\
    %s\", message.c_str());\n}\n\n#ifdef __GNUC__\n__attribute__ ((format (printf,\
    \ 1, 2)))\n#endif\nvoid setName(const char *format, ...) {\n\tFMT_TO_RESULT(format,\
    \ format, name);\n\tcheckerName = name;\n}\n\n/* \n * Do not use random_shuffle,\
    \ because it will produce different result\n * for different C++ compilers.\n\
    \ *\n * This implementation uses testlib random_t to produce random numbers, so\n\
    \ * it is stable.\n */\ntemplate<typename _RandomAccessIter>\nvoid shuffle(_RandomAccessIter\
    \ __first, _RandomAccessIter __last) {\n\tif (__first == __last) return;\n\tfor\
    \ (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)\n\t\tstd::iter_swap(__i,\
    \ __first + rnd.next(int(__i - __first) + 1));\n}\n\n\ntemplate<typename _RandomAccessIter>\n\
    #if defined(__GNUC__) && !defined(__clang__)\n__attribute__ ((error(\"Don't use\
    \ random_shuffle(), use shuffle() instead\")))\n#endif\nvoid random_shuffle(_RandomAccessIter,\
    \ _RandomAccessIter) {\n\tquitf(_fail, \"Don't use random_shuffle(), use shuffle()\
    \ instead\");\n}\n\n#ifdef __GLIBC__\n#  define RAND_THROW_STATEMENT throw()\n\
    #else\n#  define RAND_THROW_STATEMENT\n#endif\n\n#if defined(__GNUC__) && !defined(__clang__)\n\
    \n__attribute__ ((error(\"Don't use rand(), use rnd.next() instead\")))\n#endif\n\
    #ifdef _MSC_VER\n#   pragma warning( disable : 4273 )\n#endif\nint rand() RAND_THROW_STATEMENT\n\
    {\n\tquitf(_fail, \"Don't use rand(), use rnd.next() instead\");\n\n\t/* This\
    \ line never runs. */\n\t//throw \"Don't use rand(), use rnd.next() instead\"\
    ;\n}\n\n#if defined(__GNUC__) && !defined(__clang__)\n\n__attribute__ ((error(\"\
    Don't use srand(), you should use \"\n\"'registerGen(argc, argv, 1);' to initialize\
    \ generator seed \"\n\"by hash code of the command line params. The third parameter\
    \ \"\n\"is randomGeneratorVersion (currently the latest is 1).\")))\n#endif\n\
    #ifdef _MSC_VER\n#   pragma warning( disable : 4273 )\n#endif\nvoid srand(unsigned\
    \ int seed) RAND_THROW_STATEMENT\n{\n\tquitf(_fail, \"Don't use srand(), you should\
    \ use \"\n\t\t\t\t \"'registerGen(argc, argv, 1);' to initialize generator seed\
    \ \"\n\t\t\t\t \"by hash code of the command line params. The third parameter\
    \ \"\n\t\t\t\t \"is randomGeneratorVersion (currently the latest is 1) [ignored\
    \ seed=%d].\", seed);\n}\n\nvoid startTest(int test) {\n\tconst std::string testFileName\
    \ = vtos(test);\n\tif (NULL == freopen(testFileName.c_str(), \"wt\", stdout))\n\
    \t\t__testlib_fail(\"Unable to write file '\" + testFileName + \"'\");\n}\n\n\
    inline std::string upperCase(std::string s) {\n\tfor (size_t i = 0; i < s.length();\
    \ i++)\n\t\tif ('a' <= s[i] && s[i] <= 'z')\n\t\t\ts[i] = char(s[i] - 'a' + 'A');\n\
    \treturn s;\n}\n\ninline std::string lowerCase(std::string s) {\n\tfor (size_t\
    \ i = 0; i < s.length(); i++)\n\t\tif ('A' <= s[i] && s[i] <= 'Z')\n\t\t\ts[i]\
    \ = char(s[i] - 'A' + 'a');\n\treturn s;\n}\n\ninline std::string compress(const\
    \ std::string &s) {\n\treturn __testlib_part(s);\n}\n\ninline std::string englishEnding(int\
    \ x) {\n\tx %= 100;\n\tif (x / 10 == 1)\n\t\treturn \"th\";\n\tif (x % 10 == 1)\n\
    \t\treturn \"st\";\n\tif (x % 10 == 2)\n\t\treturn \"nd\";\n\tif (x % 10 == 3)\n\
    \t\treturn \"rd\";\n\treturn \"th\";\n}\n\ntemplate<typename _ForwardIterator,\
    \ typename _Separator>\nstd::string join(_ForwardIterator first, _ForwardIterator\
    \ last, _Separator separator) {\n\tstd::stringstream ss;\n\tbool repeated = false;\n\
    \tfor (_ForwardIterator i = first; i != last; i++) {\n\t\tif (repeated)\n\t\t\t\
    ss << separator;\n\t\telse\n\t\t\trepeated = true;\n\t\tss << *i;\n\t}\n\treturn\
    \ ss.str();\n}\n\ntemplate<typename _ForwardIterator>\nstd::string join(_ForwardIterator\
    \ first, _ForwardIterator last) {\n\treturn join(first, last, ' ');\n}\n\ntemplate<typename\
    \ _Collection, typename _Separator>\nstd::string join(const _Collection &collection,\
    \ _Separator separator) {\n\treturn join(collection.begin(), collection.end(),\
    \ separator);\n}\n\ntemplate<typename _Collection>\nstd::string join(const _Collection\
    \ &collection) {\n\treturn join(collection, ' ');\n}\n\n/**\n * Splits string\
    \ s by character separator returning exactly k+1 items,\n * where k is the number\
    \ of separator occurences.\n */\nstd::vector<std::string> split(const std::string\
    \ &s, char separator) {\n\tstd::vector<std::string> result;\n\tstd::string item;\n\
    \tfor (size_t i = 0; i < s.length(); i++)\n\t\tif (s[i] == separator) {\n\t\t\t\
    result.push_back(item);\n\t\t\titem = \"\";\n\t\t} else\n\t\t\titem += s[i];\n\
    \tresult.push_back(item);\n\treturn result;\n}\n\n/**\n * Splits string s by character\
    \ separators returning exactly k+1 items,\n * where k is the number of separator\
    \ occurences.\n */\nstd::vector<std::string> split(const std::string &s, const\
    \ std::string &separators) {\n\tif (separators.empty())\n\t\treturn std::vector<std::string>(1,\
    \ s);\n\n\tstd::vector<bool> isSeparator(256);\n\tfor (size_t i = 0; i < separators.size();\
    \ i++)\n\t\tisSeparator[(unsigned char) (separators[i])] = true;\n\n\tstd::vector<std::string>\
    \ result;\n\tstd::string item;\n\tfor (size_t i = 0; i < s.length(); i++)\n\t\t\
    if (isSeparator[(unsigned char) (s[i])]) {\n\t\t\tresult.push_back(item);\n\t\t\
    \titem = \"\";\n\t\t} else\n\t\t\titem += s[i];\n\tresult.push_back(item);\n\t\
    return result;\n}\n\n/**\n * Splits string s by character separator returning\
    \ non-empty items.\n */\nstd::vector<std::string> tokenize(const std::string &s,\
    \ char separator) {\n\tstd::vector<std::string> result;\n\tstd::string item;\n\
    \tfor (size_t i = 0; i < s.length(); i++)\n\t\tif (s[i] == separator) {\n\t\t\t\
    if (!item.empty())\n\t\t\t\tresult.push_back(item);\n\t\t\titem = \"\";\n\t\t\
    } else\n\t\t\titem += s[i];\n\tif (!item.empty())\n\t\tresult.push_back(item);\n\
    \treturn result;\n}\n\n/**\n * Splits string s by character separators returning\
    \ non-empty items.\n */\nstd::vector<std::string> tokenize(const std::string &s,\
    \ const std::string &separators) {\n\tif (separators.empty())\n\t\treturn std::vector<std::string>(1,\
    \ s);\n\n\tstd::vector<bool> isSeparator(256);\n\tfor (size_t i = 0; i < separators.size();\
    \ i++)\n\t\tisSeparator[(unsigned char) (separators[i])] = true;\n\n\tstd::vector<std::string>\
    \ result;\n\tstd::string item;\n\tfor (size_t i = 0; i < s.length(); i++)\n\t\t\
    if (isSeparator[(unsigned char) (s[i])]) {\n\t\t\tif (!item.empty())\n\t\t\t\t\
    result.push_back(item);\n\t\t\titem = \"\";\n\t\t} else\n\t\t\titem += s[i];\n\
    \n\tif (!item.empty())\n\t\tresult.push_back(item);\n\n\treturn result;\n}\n\n\
    NORETURN void __testlib_expectedButFound(TResult result, std::string expected,\
    \ std::string found, const char *prepend) {\n\tstd::string message;\n\tif (strlen(prepend)\
    \ != 0)\n\t\tmessage = format(\"%s: expected '%s', but found '%s'\",\n\t\t\t\t\
    \t\t compress(prepend).c_str(), compress(expected).c_str(), compress(found).c_str());\n\
    \telse\n\t\tmessage = format(\"expected '%s', but found '%s'\",\n\t\t\t\t\t\t\
    \ compress(expected).c_str(), compress(found).c_str());\n\tquit(result, message);\n\
    }\n\nNORETURN void __testlib_expectedButFound(TResult result, double expected,\
    \ double found, const char *prepend) {\n\tstd::string expectedString = removeDoubleTrailingZeroes(format(\"\
    %.12f\", expected));\n\tstd::string foundString = removeDoubleTrailingZeroes(format(\"\
    %.12f\", found));\n\t__testlib_expectedButFound(result, expectedString, foundString,\
    \ prepend);\n}\n\ntemplate<typename T>\n#ifdef __GNUC__\n__attribute__ ((format\
    \ (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound(TResult result, T expected,\
    \ T found, const char *prependFormat = \"\", ...) {\n\tFMT_TO_RESULT(prependFormat,\
    \ prependFormat, prepend);\n\tstd::string expectedString = vtos(expected);\n\t\
    std::string foundString = vtos(found);\n\t__testlib_expectedButFound(result, expectedString,\
    \ foundString, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<std::string>(TResult\
    \ result, std::string expected, std::string found, const char *prependFormat,\
    \ ...) {\n\tFMT_TO_RESULT(prependFormat, prependFormat, prepend);\n\t__testlib_expectedButFound(result,\
    \ expected, found, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound<double>(TResult\
    \ result, double expected, double found, const char *prependFormat, ...) {\n\t\
    FMT_TO_RESULT(prependFormat, prependFormat, prepend);\n\tstd::string expectedString\
    \ = removeDoubleTrailingZeroes(format(\"%.12f\", expected));\n\tstd::string foundString\
    \ = removeDoubleTrailingZeroes(format(\"%.12f\", found));\n\t__testlib_expectedButFound(result,\
    \ expectedString, foundString, prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n\
    __attribute__ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<const\
    \ char *>(TResult result, const char *expected, const char *found, const char\
    \ *prependFormat,\n\t\t\t\t\t\t\t   ...) {\n\tFMT_TO_RESULT(prependFormat, prependFormat,\
    \ prepend);\n\t__testlib_expectedButFound(result, std::string(expected), std::string(found),\
    \ prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__ ((format\
    \ (printf, 4, 5)))\n#endif\nNORETURN void expectedButFound<float>(TResult result,\
    \ float expected, float found, const char *prependFormat, ...) {\n\tFMT_TO_RESULT(prependFormat,\
    \ prependFormat, prepend);\n\t__testlib_expectedButFound(result, double(expected),\
    \ double(found), prepend.c_str());\n}\n\ntemplate<>\n#ifdef __GNUC__\n__attribute__\
    \ ((format (printf, 4, 5)))\n#endif\nNORETURN void\nexpectedButFound<long double>(TResult\
    \ result, long double expected, long double found, const char *prependFormat,\
    \ ...) {\n\tFMT_TO_RESULT(prependFormat, prependFormat, prepend);\n\t__testlib_expectedButFound(result,\
    \ double(expected), double(found), prepend.c_str());\n}\n\n#if __cplusplus > 199711L\
    \ || defined(_MSC_VER)\ntemplate<typename T>\nstruct is_iterable {\n\ttemplate<typename\
    \ U>\n\tstatic char test(typename U::iterator *x);\n\n\ttemplate<typename U>\n\
    \tstatic long test(U *x);\n\n\tstatic const bool value = sizeof(test<T>(0)) ==\
    \ 1;\n};\n\ntemplate<bool B, class T = void>\nstruct __testlib_enable_if {\n};\n\
    \ntemplate<class T>\nstruct __testlib_enable_if<true, T> {\n\ttypedef T type;\n\
    };\n\ntemplate<typename T>\ntypename __testlib_enable_if<!is_iterable<T>::value,\
    \ void>::type __testlib_print_one(const T &t) {\n\tstd::cout << t;\n}\n\ntemplate<typename\
    \ T>\ntypename __testlib_enable_if<is_iterable<T>::value, void>::type __testlib_print_one(const\
    \ T &t) {\n\tbool first = true;\n\tfor (typename T::const_iterator i = t.begin();\
    \ i != t.end(); i++) {\n\t\tif (first)\n\t\t\tfirst = false;\n\t\telse\n\t\t\t\
    std::cout << \" \";\n\t\tstd::cout << *i;\n\t}\n}\n\ntemplate<>\ntypename __testlib_enable_if<is_iterable<std::string>::value,\
    \ void>::type\n__testlib_print_one<std::string>(const std::string &t) {\n\tstd::cout\
    \ << t;\n}\n\ntemplate<typename A, typename B>\nvoid __println_range(A begin,\
    \ B end) {\n\tbool first = true;\n\tfor (B i = B(begin); i != end; i++) {\n\t\t\
    if (first)\n\t\t\tfirst = false;\n\t\telse\n\t\t\tstd::cout << \" \";\n\t\t__testlib_print_one(*i);\n\
    \t}\n\tstd::cout << std::endl;\n}\n\ntemplate<class T, class Enable = void>\n\
    struct is_iterator {\n\tstatic T makeT();\n\n\ttypedef void *twoptrs[2];\n\n\t\
    static twoptrs &test(...);\n\n\ttemplate<class R>\n\tstatic typename R::iterator_category\
    \ *test(R);\n\n\ttemplate<class R>\n\tstatic void *test(R *);\n\n\tstatic const\
    \ bool value = sizeof(test(makeT())) == sizeof(void *);\n};\n\ntemplate<class\
    \ T>\nstruct is_iterator<T, typename __testlib_enable_if<std::is_array<T>::value>::type>\
    \ {\n\tstatic const bool value = false;\n};\n\ntemplate<typename A, typename B>\n\
    typename __testlib_enable_if<!is_iterator<B>::value, void>::type println(const\
    \ A &a, const B &b) {\n\t__testlib_print_one(a);\n\tstd::cout << \" \";\n\t__testlib_print_one(b);\n\
    \tstd::cout << std::endl;\n}\n\ntemplate<typename A, typename B>\ntypename __testlib_enable_if<is_iterator<B>::value,\
    \ void>::type println(const A &a, const B &b) {\n\t__println_range(a, b);\n}\n\
    \ntemplate<typename A>\nvoid println(const A *a, const A *b) {\n\t__println_range(a,\
    \ b);\n}\n\ntemplate<>\nvoid println<char>(const char *a, const char *b) {\n\t\
    __testlib_print_one(a);\n\tstd::cout << \" \";\n\t__testlib_print_one(b);\n\t\
    std::cout << std::endl;\n}\n\ntemplate<typename T>\nvoid println(const T &x) {\n\
    \t__testlib_print_one(x);\n\tstd::cout << std::endl;\n}\n\ntemplate<typename A,\
    \ typename B, typename C>\nvoid println(const A &a, const B &b, const C &c) {\n\
    \t__testlib_print_one(a);\n\tstd::cout << \" \";\n\t__testlib_print_one(b);\n\t\
    std::cout << \" \";\n\t__testlib_print_one(c);\n\tstd::cout << std::endl;\n}\n\
    \ntemplate<typename A, typename B, typename C, typename D>\nvoid println(const\
    \ A &a, const B &b, const C &c, const D &d) {\n\t__testlib_print_one(a);\n\tstd::cout\
    \ << \" \";\n\t__testlib_print_one(b);\n\tstd::cout << \" \";\n\t__testlib_print_one(c);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(d);\n\tstd::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E>\nvoid\
    \ println(const A &a, const B &b, const C &c, const D &d, const E &e) {\n\t__testlib_print_one(a);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(b);\n\tstd::cout << \" \";\n\t__testlib_print_one(c);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(d);\n\tstd::cout << \" \";\n\t__testlib_print_one(e);\n\
    \tstd::cout << std::endl;\n}\n\ntemplate<typename A, typename B, typename C, typename\
    \ D, typename E, typename F>\nvoid println(const A &a, const B &b, const C &c,\
    \ const D &d, const E &e, const F &f) {\n\t__testlib_print_one(a);\n\tstd::cout\
    \ << \" \";\n\t__testlib_print_one(b);\n\tstd::cout << \" \";\n\t__testlib_print_one(c);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(d);\n\tstd::cout << \" \";\n\t__testlib_print_one(e);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(f);\n\tstd::cout << std::endl;\n\
    }\n\ntemplate<typename A, typename B, typename C, typename D, typename E, typename\
    \ F, typename G>\nvoid println(const A &a, const B &b, const C &c, const D &d,\
    \ const E &e, const F &f, const G &g) {\n\t__testlib_print_one(a);\n\tstd::cout\
    \ << \" \";\n\t__testlib_print_one(b);\n\tstd::cout << \" \";\n\t__testlib_print_one(c);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(d);\n\tstd::cout << \" \";\n\t__testlib_print_one(e);\n\
    \tstd::cout << \" \";\n\t__testlib_print_one(f);\n\tstd::cout << \" \";\n\t__testlib_print_one(g);\n\
    \tstd::cout << std::endl;\n}\n\n/* opts */\nsize_t getOptType(char* s) {\n\tif\
    \ (!s || strlen(s) <= 1)\n\t\treturn false;\n\n\tif (s[0] == '-') {\n\t\tif (isalpha(s[1]))\n\
    \t\t\treturn 1;\n\t\telse if (s[1] == '-')\n\t\t\treturn isalpha(s[2]) ? 2 : 0;\n\
    \t}\n\n\treturn 0;\n}\n\nsize_t parseOpt(size_t argc, char* argv[], size_t index,\
    \ std::map<std::string, std::string>& opts) {\n\tif (index >= argc)\n\t\treturn\
    \ 0;\n\n\tsize_t type = getOptType(argv[index]), inc = 1;\n\tif (type > 0) {\n\
    \t\tstd::string key(argv[index] + type), val;\n\t\tsize_t sep = key.find('=');\n\
    \t\tif (sep != std::string::npos) {\n\t\t\tval = key.substr(sep + 1);\n\t\t\t\
    key = key.substr(0, sep);\n\t\t} else {\n\t\t\tif (index + 1 < argc && getOptType(argv[index\
    \ + 1]) == 0) {\n\t\t\t\tval = argv[index + 1];\n\t\t\t\tinc = 2;\n\t\t\t} else\
    \ {\n\t\t\t\tif (key.length() > 1 && isdigit(key[1])) {\n\t\t\t\t\tval = key.substr(1);\n\
    \t\t\t\t\tkey = key.substr(0, 1);\n\t\t\t\t} else {\n\t\t\t\t\tval = \"true\"\
    ;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\topts[key] = val;\n\t} else {\n\t\treturn inc;\n\
    \t}\n\n\treturn inc;\n}\n\nstd::vector<std::string> __testlib_argv;\nstd::map<std::string,\
    \ std::string> __testlib_opts;\n\nvoid prepareOpts(int argc, char* argv[]) {\n\
    \tif (argc <= 0)\n\t\t__testlib_fail(\"Opts: expected argc>=0 but found \" + toString(argc));\n\
    \tsize_t n = static_cast<size_t>(argc); // NOLINT(hicpp-use-auto,modernize-use-auto)\n\
    \t__testlib_opts = std::map<std::string, std::string>();\n\tfor (size_t index\
    \ = 1; index < n; index += parseOpt(n, argv, index, __testlib_opts));\n\t__testlib_argv\
    \ = std::vector<std::string>(n);\n\tfor (size_t index = 0; index < n; index++)\n\
    \t\t__testlib_argv[index] = argv[index];\n}\n\nstd::string __testlib_indexToArgv(int\
    \ index) {\n\tif (index < 0 || index >= int(__testlib_argv.size()))\n\t\t__testlib_fail(\"\
    Opts: index '\" + toString(index) + \"' is out of range [0,\" + toString(__testlib_argv.size())\
    \ + \")\");\n\treturn __testlib_argv[size_t(index)];\n}\n\nstd::string __testlib_keyToOpts(const\
    \ std::string& key) {\n\tif (__testlib_opts.count(key) == 0)\n\t\t__testlib_fail(\"\
    Opts: unknown key '\" + compress(key) + \"'\");\n\treturn __testlib_opts[key];\n\
    }\n\ntemplate<typename T>\nT optValueToIntegral(const std::string& s, bool nonnegative);\n\
    \nlong double optValueToLongDouble(const std::string& s);\n\nstd::string parseExponentialOptValue(const\
    \ std::string& s) {\n\tsize_t pos = std::string::npos;\n\tfor (size_t i = 0; i\
    \ < s.length(); i++)\n\t\tif (s[i] == 'e' || s[i] == 'E') {\n\t\t\tif (pos !=\
    \ std::string::npos)\n\t\t\t\t__testlib_fail(\"Opts: expected typical exponential\
    \ notation but '\" + compress(s) + \"' found\");\n\t\t\tpos = i;\n\t\t}\n\tif\
    \ (pos == std::string::npos)\n\t\treturn s;\n\tstd::string e = s.substr(pos +\
    \ 1);\n\tif (!e.empty() && e[0] == '+')\n\t\te = e.substr(1);\n\tif (e.empty())\n\
    \t\t__testlib_fail(\"Opts: expected typical exponential notation but '\" + compress(s)\
    \ + \"' found\");\n\tif (e.length() > 20)\n\t\t__testlib_fail(\"Opts: expected\
    \ typical exponential notation but '\" + compress(s) + \"' found\");\n\tint ne\
    \ = optValueToIntegral<int>(e, false);\n\tstd::string num = s.substr(0, pos);\n\
    \tif (num.length() > 20)\n\t\t__testlib_fail(\"Opts: expected typical exponential\
    \ notation but '\" + compress(s) + \"' found\");\n\tif (!num.empty() && num[0]\
    \ == '+')\n\t\tnum = num.substr(1);\n\toptValueToLongDouble(num);\n\tbool minus\
    \ = false;\n\tif (num[0] == '-') {\n\t\tminus = true;\n\t\tnum = num.substr(1);\n\
    \t}\n\tfor (int i = 0; i < +ne; i++) {\n\t\tsize_t sep = num.find('.');\n\t\t\
    if (sep == std::string::npos)\n\t\t\tnum += '0';\n\t\telse {\n\t\t\tif (sep +\
    \ 1 == num.length())\n\t\t\t\tnum[sep] = '0';\n\t\t\telse\n\t\t\t\tstd::swap(num[sep],\
    \ num[sep + 1]);\n\t\t}\n\t}\n\tfor (int i = 0; i < -ne; i++) {\n\t\tsize_t sep\
    \ = num.find('.');\n\t\tif (sep == std::string::npos)\n\t\t\tnum.insert(num.begin()\
    \ + int(num.length()) - 1, '.');\n\t\telse {\n\t\t\tif (sep == 0)\n\t\t\t\tnum.insert(num.begin()\
    \ + 1, '0');\n\t\t\telse\n\t\t\t\tstd::swap(num[sep - 1], num[sep]);\n\t\t}\n\t\
    }\n\twhile (!num.empty() && num[0] == '0')\n\t\tnum = num.substr(1);\n\twhile\
    \ (num.find('.') != std::string::npos && num.back() == '0')\n\t\tnum = num.substr(0,\
    \ num.length() - 1);\n\tif (!num.empty() && num.back() == '.')\n\t\tnum = num.substr(0,\
    \ num.length() - 1);\n\tif ((!num.empty() && num[0] == '.') || num.empty())\n\t\
    \tnum.insert(num.begin(), '0');\n\treturn (minus ? \"-\" : \"\") + num;\n}\n\n\
    template<typename T>\nT optValueToIntegral(const std::string& s_, bool nonnegative)\
    \ {\n\tstd::string s(parseExponentialOptValue(s_));\n\tif (s.empty())\n\t\t__testlib_fail(\"\
    Opts: expected integer but '\" + compress(s_) + \"' found\");\n\tT value = 0;\n\
    \tlong double about = 0.0;\n\tsigned char sign = +1;\n\tsize_t pos = 0;\n\tif\
    \ (s[pos] == '-') {\n\t\tif (nonnegative)\n\t\t\t__testlib_fail(\"Opts: expected\
    \ non-negative integer but '\" + compress(s_) + \"' found\");\n\t\tsign = -1;\n\
    \t\tpos++;\n\t}\n\tfor (size_t i = pos; i < s.length(); i++) {\n\t\tif (s[i] <\
    \ '0' || s[i] > '9')\n\t\t\t__testlib_fail(\"Opts: expected integer but '\" +\
    \ compress(s_) + \"' found\");\n\t\tvalue = value * 10 + s[i] - '0';\n\t\tabout\
    \ = about * 10 + s[i] - '0';\n\t}\n\tvalue *= sign;\n\tabout *= sign;\n\tif (fabsl(value\
    \ - about) > 0.1)\n\t\t__testlib_fail(\"Opts: integer overflow: expected integer\
    \ but '\" + compress(s_) + \"' found\");\n\treturn value;\n}\n\nlong double optValueToLongDouble(const\
    \ std::string& s_) {\n\tstd::string s(parseExponentialOptValue(s_));\n\tif (s.empty())\n\
    \t\t__testlib_fail(\"Opts: expected float number but '\" + compress(s_) + \"'\
    \ found\");\n\tlong double value = 0.0;\n\tsigned char sign = +1;\n\tsize_t pos\
    \ = 0;\n\tif (s[pos] == '-') {\n\t\tsign = -1;\n\t\tpos++;\n\t}\n\tbool period\
    \ = false;\n\tlong double mul = 1.0;\n\tfor (size_t i = pos; i < s.length(); i++)\
    \ {\n\t\tif (s[i] == '.') {\n\t\t\tif (period)\n\t\t\t\t__testlib_fail(\"Opts:\
    \ expected float number but '\" + compress(s_) + \"' found\");\n\t\t\telse {\n\
    \t\t\t\tperiod = true;\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t}\n\t\tif (period)\n\t\
    \t\tmul *= 10.0;\n\t\tif (s[i] < '0' || s[i] > '9')\n\t\t\t__testlib_fail(\"Opts:\
    \ expected float number but '\" + compress(s_) + \"' found\");\n\t\tif (period)\n\
    \t\t\tvalue += (s[i] - '0') / mul;\n\t\telse\n\t\t\tvalue = value * 10 + s[i]\
    \ - '0';\n\t}\n\tvalue *= sign;\n\treturn value;\n}\n\nbool has_opt(const std::string\
    \ key) {\n\treturn __testlib_opts.count(key) != 0;\n}\n\ntemplate<typename T>\n\
    T opt(std::false_type, int index);\n\ntemplate<>\nstd::string opt(std::false_type,\
    \ int index) {\n\treturn __testlib_indexToArgv(index);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, int index) {\n\treturn T(optValueToLongDouble(__testlib_indexToArgv(index)));\n\
    }\n\ntemplate<typename T, typename U>\nT opt(std::false_type, U, int index) {\n\
    \treturn opt<T>(std::is_floating_point<T>(), index);\n}\n\ntemplate<typename T>\n\
    T opt(std::true_type, std::false_type, int index) {\n\treturn optValueToIntegral<T>(__testlib_indexToArgv(index),\
    \ false);\n}\n\ntemplate<typename T>\nT opt(std::true_type, std::true_type, int\
    \ index) {\n\treturn optValueToIntegral<T>(__testlib_indexToArgv(index), true);\n\
    }\n\ntemplate<>\nbool opt(std::true_type, std::true_type, int index) {\n\tstd::string\
    \ value = __testlib_indexToArgv(index);\n\tif (value == \"true\" || value == \"\
    1\")\n\t\treturn true;\n\tif (value == \"false\" || value == \"0\")\n\t\treturn\
    \ false;\n\t__testlib_fail(\"Opts: opt by index '\" + toString(index) + \"': expected\
    \ bool true/false or 0/1 but '\" + compress(value) + \"' found\");\n}\n\ntemplate<typename\
    \ T>\nT opt(int index) {\n\treturn opt<T>(std::is_integral<T>(), std::is_unsigned<T>(),\
    \ index);\n}\n\nstd::string opt(int index) {\n\treturn opt<std::string>(index);\n\
    }\n\ntemplate<typename T>\nT opt(std::false_type, const std::string& key);\n\n\
    template<>\nstd::string opt(std::false_type, const std::string& key) {\n\treturn\
    \ __testlib_keyToOpts(key);\n}\n\ntemplate<typename T>\nT opt(std::true_type,\
    \ const std::string& key) {\n\treturn T(optValueToLongDouble(__testlib_keyToOpts(key)));\n\
    }\n\ntemplate<typename T, typename U>\nT opt(std::false_type, U, const std::string&\
    \ key) {\n\treturn opt<T>(std::is_floating_point<T>(), key);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::false_type, const std::string& key) {\n\treturn\
    \ optValueToIntegral<T>(__testlib_keyToOpts(key), false);\n}\n\ntemplate<typename\
    \ T>\nT opt(std::true_type, std::true_type, const std::string& key) {\n\treturn\
    \ optValueToIntegral<T>(__testlib_keyToOpts(key), true);\n}\n\ntemplate<>\nbool\
    \ opt(std::true_type, std::true_type, const std::string& key) {\n\tif (!has_opt(key))\n\
    \t\treturn false;\n\tstd::string value = __testlib_keyToOpts(key);\n\tif (value\
    \ == \"true\" || value == \"1\")\n\t\treturn true;\n\tif (value == \"false\" ||\
    \ value == \"0\")\n\t\treturn false;\n\t__testlib_fail(\"Opts: key '\" + compress(key)\
    \ + \"': expected bool true/false or 0/1 but '\" + compress(value) + \"' found\"\
    );\n}\n\ntemplate<typename T>\nT opt(const std::string key) {\n\treturn opt<T>(std::is_integral<T>(),\
    \ std::is_unsigned<T>(), key);\n}\n\nstd::string opt(const std::string key) {\n\
    \treturn opt<std::string>(key);\n}\n#endif\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: other/testlib.h
  requiredBy: []
  timestamp: '2020-07-31 11:16:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/testlib.h
layout: document
redirect_from:
- /library/other/testlib.h
- /library/other/testlib.h.html
title: other/testlib.h
---