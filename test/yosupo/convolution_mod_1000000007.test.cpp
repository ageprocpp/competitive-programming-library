#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
#include "../../math/FormalPowerSeries.hpp"
using FPS = FormalPowerSeries<StaticModInt<1000000007>>;
FastIO::Scanner cin;
FastIO::Printer cout;
int N, M;
FPS a, b;
int main() {
	cin >> N >> M;
	FPS a(N), b(M);
	rep(i, N) cin >> a[i];
	rep(i, M) cin >> b[i];
	cout << a * b << '\n';
}