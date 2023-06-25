#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
#include "../../data-structure/WaveletMatrix.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int n, q;
std::vector<int> a;
int main() {
	cin >> n >> q;
	a.resize(n);
	rep(i, n) cin >> a[i];
	WaveletMatrix wm(a);
	rep(i, q) {
		int l, r, k;
		cin >> l >> r >> k;
		cout << wm.quantile(l, r, k + 1) << '\n';
	}
}