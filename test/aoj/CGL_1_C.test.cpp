#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_C"
#include "../../other/template.hpp"
#include "../../math/Geometry.hpp"
int main() {
	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	Point2D p1(x1, y1), p2(x2, y2);
	int q;
	std::cin >> q;
	rep(i, q) {
		int x, y;
		std::cin >> x >> y;
		switch (counter_clockwise(p1, p2, Point2D(x, y))) {
			case 1:
				puts("COUNTER_CLOCKWISE");
				break;
			case -1:
				puts("CLOCKWISE");
				break;
			case 2:
				puts("ONLINE_BACK");
				break;
			case -2:
				puts("ONLINE_FRONT");
				break;
			default:
				puts("ON_SEGMENT");
		}
	}
}