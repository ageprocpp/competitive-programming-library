#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"
#include "../../other/template.hpp"
#include "../../other/FastIO.hpp"
#include "../../algebraic/NumberTheoreticTransform.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int N, M;
std::vector<int> a, b;
int main() {
	cin >> N >> M;
	a.resize(N);
	b.resize(M);
	rep(i, N) cin >> a[i];
	rep(i, M) cin >> b[i];
	auto res = NumberTheoreticTransform::convolution<1000000007>(a, b);
	rep(i, N + M - 2) cout << (int)res[i] << ' ';
	cout << (int)res[N + M - 2] << '\n';
}