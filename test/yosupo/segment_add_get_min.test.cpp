#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../../data-structure/LiChaoTree.hpp"
#include "../../other/template.hpp"
int n, q, l[200010], r[200010], a[200010];
lint b[200010];
std::vector<std::pair<IP, std::pair<int, lint>>> vec;
std::vector<lint> cord;
int main() {
	scanf("%d%d", &n, &q);
	rep(i, n) {
		scanf("%d%d%d%lld", l + i, r + i, a + i, b + i);
		cord.emplace_back(l[i]);
		cord.emplace_back(r[i]);
	}
	rep(i, q) {
		int type;
		scanf("%d", &type);
		if (type == 0) {
			int l, r, a;
			lint b;
			scanf("%d%d%d%lld", &l, &r, &a, &b);
			vec.push_back({{l, r}, {a, b}});
			cord.emplace_back(l);
			cord.emplace_back(r);
		} else {
			int p;
			scanf("%d", &p);
			vec.push_back({{p, INF}, {0, 0}});
			cord.emplace_back(p);
		}
	}
	std::sort(all(cord));
	cord.erase(std::unique(all(cord)), cord.end());
	rep(i, n) {
		l[i] = std::lower_bound(all(cord), l[i]) - cord.begin();
		r[i] = std::lower_bound(all(cord), r[i]) - cord.begin();
	}
	for (auto& i : vec) {
		i.first.first =
			std::lower_bound(all(cord), i.first.first) - cord.begin();
		if (i.first.second != INF)
			i.first.second =
				std::lower_bound(all(cord), i.first.second) - cord.begin();
	}
	LiChaoTree<true> lct(cord);
	rep(i, n) lct.addSegment(l[i], r[i], a[i], b[i]);
	for (auto i : vec) {
		if (i.first.second == INF) {
			lint ans = lct.query(i.first.first).first;
			if (ans == LINF)
				puts("INFINITY");
			else
				printf("%lld\n", ans);
		} else
			lct.addSegment(i.first.first, i.first.second, i.second.first,
						   i.second.second);
	}
}
