#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../other/template.hpp"
int main() {
	lint t, a, b;
	scanf("%lld", &t);
	rep(i, t) {
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", a + b);
	}
	return 0;
}