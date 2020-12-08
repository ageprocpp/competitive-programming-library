#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"
#include "../../other/template.hpp"
#include "../../string/RollingHash.hpp"
std::string t, p;
int main() {
	std::cin >> t >> p;
	if (t.size() < p.size()) return 0;
	RollingHash<1000000007, 1007> rt1(t), rp1(p);
	RollingHash<1000000007, 10007> rt2(t), rp2(p);
	rep(i, t.size() - p.size() + 1) {
		if (rt1.query(i, i + p.size()) == rp1 &&
			rt2.query(i, i + p.size()) == rp2)
			printf("%d\n", i);
	}
}