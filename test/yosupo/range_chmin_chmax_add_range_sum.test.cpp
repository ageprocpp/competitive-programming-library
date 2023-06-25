#define PROBLEM \
	"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../../data-structure/SegTreeBeats.hpp"
#include "../../basic/template.hpp"
int n, q;
int main() {
	scanf("%d%d", &n, &q);
	std::vector<lint> vec(n);
	rep(i, n) scanf("%lld", vec.data() + i);
	SegTreeBeats beats(vec);
	rep(i, q) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			lint l, r, b;
			scanf("%lld%lld%lld", &l, &r, &b);
			beats.update_chmin(l, r, b);
		} else if (t == 1) {
			lint l, r, b;
			scanf("%lld%lld%lld", &l, &r, &b);
			beats.update_chmax(l, r, b);
		} else if (t == 2) {
			lint l, r, b;
			scanf("%lld%lld%lld", &l, &r, &b);
			beats.update_add(l, r, b);
		} else {
			lint l, r;
			scanf("%lld%lld", &l, &r);
			printf("%lld\n", beats.query_sum(l, r));
		}
	}
	return 0;
}