#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"
#include "../../basic/template.hpp"
#include "../../string/SuffixArray.hpp"
std::string t, p;
int main() {
	std::cin >> t >> p;
	SuffixArray sa(t);
	std::vector<int> vec = sa.locate(p);
	for (int i : vec) printf("%d\n", i);
}