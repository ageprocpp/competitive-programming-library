#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_A"
#include "../../basic/template.hpp"
#include "../../math/Geometry.hpp"
int main() {
	int n;
	std::cin >> n;
	std::vector<Point2D> v(n);
	rep(i, n) std::cin >> v[i];
	auto ans = convex_hull(v);
	std::cout << ans.size() << std::endl;
	int s = 0;
	REP(i, ans.size() - 1) {
		if (ans[s].get_y() > ans[i].get_y() ||
			(ans[s].get_y() == ans[i].get_y() &&
			 ans[s].get_x() > ans[i].get_x()))
			s = i;
	}
	rep(i, ans.size()) std::cout
		<< ans[i + s >= ans.size() ? i + s - ans.size() : i + s] << std::endl;
}