#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../../math/NumberTheoreticTransform.hpp"
#include "../../other/template.hpp"
int n, m;
std::vector<int> a, b;
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n);
	b.resize(m);
	rep(i, n) scanf("%d", a.data() + i);
	rep(i, m) scanf("%d", b.data() + i);
	std::vector<StaticModInt<998244353>> c =
		NumberTheoreticTransform::convolution<998244353>(a, b);
	rep(i, n + m - 1) printf((i == n + m ? "%d\n" : "%d "), c[i]);
}