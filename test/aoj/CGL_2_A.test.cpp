#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_A"
#include "../../basic/template.hpp"
#include "../../math/Geometry.hpp"
int main() {
	int q;
	std::cin >> q;
	rep(i, q) {
		int x0, y0, x1, y1, x2, y2, x3, y3;
		std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		Line2D l0(Point2D(x0, y0), Point2D(x1, y1)),
			l1(Point2D(x2, y2), Point2D(x3, y3));
		if (is_parallel(l0, l1))
			std::cout << 2 << std::endl;
		else if (is_orthogonal(l0, l1))
			std::cout << 1 << std::endl;
		else
			std::cout << 0 << std::endl;
	}
}