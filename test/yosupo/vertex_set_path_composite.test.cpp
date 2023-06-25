#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../../math/StaticModInt.hpp"
#include "../../data-structure/SegTree.hpp"
#include "../../graph/HeavyLightDecomposition.hpp"
#include "../../basic/template.hpp"
using ModInt = StaticModInt<998244353>;
using MP = std::pair<ModInt, ModInt>;
MP nodef(const MP& lhs, const MP& rhs) {
	return {lhs.first * rhs.first, lhs.second * rhs.first + rhs.second};
}
class MySeg : public SegTree<MP, nodef> {
	using Base = SegTree<MP, nodef>;

  public:
	MySeg(int n) : Base(n, MP{1, 0}, MP{1, 0}) {}
};
int n, q;
IP a[200010];
int main() {
	scanf("%d%d", &n, &q);
	rep(i, n) scanf("%d%d", &a[i].first, &a[i].second);
	HeavyLightDecomposition hld(n);
	MySeg st1(n), st2(n);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		hld.add_edge(u, v);
	}
	hld.build(0);
	rep(i, n) {
		st1.update(hld.label[i], a[i]);
		st2.update(n - 1 - hld.label[i], a[i]);
	}
	rep(i, q) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int p, c, d;
			scanf("%d%d%d", &p, &c, &d);
			a[p] = {c, d};
			st1.update(hld.label[p], {c, d});
			st2.update(n - 1 - hld.label[p], {c, d});
		} else {
			int u, v, x;
			scanf("%d%d%d", &u, &v, &x);
			int t = hld.lca(u, v);
			std::pair<ModInt, ModInt> f1(1, 0), f2(1, 0);
			hld.each_vertex(u, t, [&](int l, int r) {
				auto p = st2.query(n - 1 - r, n - 1 - l + 1);
				f1 = {f1.first * p.first, f1.second * p.first + p.second};
			});
			f1 = {f1.first / a[t].first,
				  (f1.second - a[t].second) / a[t].first};
			hld.each_vertex(t, v, [&](int l, int r) {
				auto p = st1.query(l, r + 1);
				f2 = {p.first * f2.first, p.second * f2.first + f2.second};
			});
			f1 = {f1.first * f2.first, f1.second * f2.first + f2.second};
			printf("%d\n", ModInt(x) * f1.first + f1.second);
		}
	}
}