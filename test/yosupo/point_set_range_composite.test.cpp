#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../../algebraic/StaticModInt.hpp"
#include "../../data-structure/SegTree.hpp"
#include "../../other/template.hpp"
using ModInt = StaticModInt<998244353>;
using MP = std::pair<ModInt, ModInt>;
MP nodef(const MP& lhs, const MP& rhs) {
	return {lhs.first * rhs.first, lhs.second * rhs.first + rhs.second};
}
class MySeg : public SegTree<MP, nodef> {
	using Base = SegTree<MP, nodef>;

  public:
	MySeg(int n) : Base(n, {0, 0}, {1, 0}) {}
};
int n, q;
int main() {
	scanf("%d%d", &n, &q);
	MySeg st(n);
	rep(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		st.update(i, {a, b});
	}
	rep(i, q) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int p, c, d;
			scanf("%d%d%d", &p, &c, &d);
			st.update(p, {c, d});
		} else {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			auto p = st.query(l, r);
			printf("%d\n", p.first * x + p.second);
		}
	}
	return 0;
}