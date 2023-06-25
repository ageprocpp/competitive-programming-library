#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../basic/template.hpp"
#include "../../data-structure/ConvexHullTrick.hpp"
int N, Q;
int main() {
	scanf("%d%d", &N, &Q);
	ConvexHullTrick<lint, true> cht;
	rep(i, N) {
		int a;
		lint b;
		scanf("%d%lld", &a, &b);
		cht.addLine(a, b);
	}
	rep(i, Q) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int a;
			lint b;
			scanf("%d%lld", &a, &b);
			cht.addLine(a, b);
		} else {
			int p;
			scanf("%d", &p);
			printf("%lld\n", cht.query(p).first);
		}
	}
}
