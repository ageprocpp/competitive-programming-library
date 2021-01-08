#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"
#include "../../other/template.hpp"
#include "../../string/HashedString.hpp"
std::string t, p;
int main() {
	std::cin >> t >> p;
	if (t.size() < p.size()) return 0;
	HashedString ht(t), hp(p);
	rep(i, t.size() - p.size() + 1) {
		if (ht.substr(i, p.size()) == decltype(ht.substr(i, p.size()))(hp))
			printf("%d\n", i);
	}
}