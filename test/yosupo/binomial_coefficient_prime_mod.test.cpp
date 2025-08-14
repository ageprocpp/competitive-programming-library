#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
#include "../../math/DynamicModInt.hpp"
#include "../../math/Combinatorics.hpp"
using ModInt = DynamicModInt;
using MC = ModCombinatorics<ModInt>;
FastIO::Scanner cin;
FastIO::Printer cout;
int T, m;
int main() {
	cin >> T >> m;
	ModInt::setMod(m);
	rep(_, T) {
		int n, k;
		cin >> n >> k;
		if (n < k)
			cout << 0 << '\n';
		else
			cout << MC::get_comb(n, k) << '\n';
	}
	return 0;
}