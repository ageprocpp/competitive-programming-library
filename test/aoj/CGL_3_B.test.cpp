#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_B"
#include "../../basic/template.hpp"
#include "../../math/Geometry.hpp"
int main() {
	int n;
	std::cin >> n;
	std::vector<Point2D> v(n);
	rep(i, n) std::cin >> v[i];
	std::cout << is_convex(v) << std::endl;
}