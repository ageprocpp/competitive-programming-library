#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_B"
#include "../../basic/template.hpp"
#include "../../math/Geometry.hpp"
int main() {
	int q;
	std::cin >> q;
	rep(i, q) {
		int x0, y0, x1, y1, x2, y2, x3, y3;
		std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		Segment2D s0(Point2D(x0, y0), Point2D(x1, y1)),
			s1(Point2D(x2, y2), Point2D(x3, y3));
		std::cout << is_intersect(s0, s1) << std::endl;
	}
}