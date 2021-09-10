#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_B"
#include "../../other/template.hpp"
#include "../../math/Geometry.hpp"
int main() {
	int n;
	std::cin >> n;
	std::vector<Point2D> v(n);
	rep(i, n) std::cin >> v[i];
	std::cout << std::fixed << std::setprecision(12)
			  << convex_polygon_diameter(v) << std::endl;
}