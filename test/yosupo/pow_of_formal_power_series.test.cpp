#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include "../../other/template.hpp"
#include "../../other/FastIO.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/FormalPowerSeries.hpp"

using ModInt = StaticModInt<998244353>;
using FPS = FormalPowerSeries<ModInt>;
FastIO::Scanner cin;
FastIO::Printer cout;
int main() {
	int N;
	lint M;
	cin >> N >> M;
	FPS vec(N);
	rep(i, N) cin >> vec[i];
	cout << vec.pow(M) << '\n';
}