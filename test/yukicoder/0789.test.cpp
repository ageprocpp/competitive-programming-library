#define PROBLEM "https://yukicoder.me/problems/no/789"
#include "../../other/template.hpp"
#include "../../data-structure/DynamicSegTree.hpp"
int nodef(const int& a, const int& b) { return a + b; }
int main() {
	int n;
	std::cin >> n;
	DynamicSegTree<int, nodef, 0> dst(1000000001);
	lint ans = 0;
	rep(i, n) {
		int t, x, y;
		std::cin >> t >> x >> y;
		if (t == 0) {
			dst.update(x, dst[x] + y);
		} else {
			ans += dst.query(x, y + 1);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}