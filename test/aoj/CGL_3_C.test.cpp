#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_C"
#include "../../other/template.hpp"
#include "../../math/Geometry.hpp"
int main() {
	int n, q;
	std::cin >> n;
	std::vector<Point2D> v(n);
	rep(i, n) std::cin >> v[i];
	std::cin >> q;
	rep(i, q) {
		Point2D p;
		std::cin >> p;
		std::cout << is_contained(v, p) << std::endl;
	}
}