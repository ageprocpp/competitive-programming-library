#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A"
#define ERROR "1e-8"
#include "../../other/template.hpp"
#include "../../math/Geometry.hpp"
int main() {
	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	Line2D l(Point2D(x1, y1), Point2D(x2, y2));
	int q;
	std::cin >> q;
	rep(i, q) {
		int x, y;
		std::cin >> x >> y;
		std::cout << std::fixed << std::setprecision(12)
				  << projection(l, Point2D(x, y)) << std::endl;
	}
}