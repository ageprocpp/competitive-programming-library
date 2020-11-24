#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../data-structure/WaveletMatrix.hpp"
#include "../../other/template.hpp"
int n, q;
std::vector<int> a;
int main() {
	scanf("%d%d", &n, &q);
	a.resize(n);
	rep(i, n) scanf("%d", a.data() + i);
	WaveletMatrix wm(a);
	rep(i, q) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", wm.quantile(l, r, k + 1));
	}
}