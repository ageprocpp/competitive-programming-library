#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_large"
#include "../../other/template.hpp"
#include "../../other/FastIO.hpp"
#include "../../math/FormalPowerSeries.hpp"
using FPS = FormalPowerSeries<StaticModInt<998244353>>;
FastIO::Scanner cin;
FastIO::Printer cout;
int N, M;
int main() {
	cin >> N >> M;
	FPS A(N), B(M);
	rep(i, N) cin >> A[i];
	rep(i, M) cin >> B[i];
	cout << A * B << '\n';
}