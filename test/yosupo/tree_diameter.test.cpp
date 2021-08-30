#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../graph/Tree.hpp"
#include "../../other/template.hpp"
int N;
int main() {
	scanf("%d", &N);
	std::vector<std::pair<IP, int>> vec;
	rep(i, N - 1) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a++;
		b++;
		vec.push_back({{a, b}, c});
	}
	Tree tree(N, vec);
	auto res = tree.DiameterPath();
	printf("%lld %d\n", res.second, res.first.size());
	std::for_each(all(res.first), [](int &n) { n--; });
	std::cout << res.first << std::endl;
}