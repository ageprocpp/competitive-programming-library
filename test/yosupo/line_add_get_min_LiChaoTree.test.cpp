#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../data-structure/LiChaoTree.hpp"
#include "../../basic/template.hpp"
int n, q;
lint a[200010], b[200010];
std::vector<std::pair<int, lint>> vec;
std::vector<lint> cord;
int main() {
	scanf("%d%d", &n, &q);
	rep(i, n) scanf("%lld%lld", a + i, b + i);
	rep(i, q) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int a;
			lint b;
			scanf("%d%lld", &a, &b);
			vec.emplace_back(a, b);
		} else {
			int p;
			scanf("%d", &p);
			vec.emplace_back(p, LINF);
			cord.emplace_back(p);
		}
	}
	std::sort(all(cord));
	cord.erase(std::unique(all(cord)), cord.end());
	LiChaoTree<true> lct(cord);
	rep(i, n) lct.addLine(a[i], b[i]);
	for (auto i : vec) {
		if (i.second == LINF)
			printf("%lld\n", lct.query(std::lower_bound(all(cord), i.first) -
									   cord.begin())
								 .first);
		else
			lct.addLine(i.first, i.second);
	}
}
