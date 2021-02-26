#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../other/template.hpp"
#include "../../string/ZAlgorithm.hpp"
int main() {
	std::string S;
	std::cin >> S;
	printArray(ZAlgorithm(S));
}