#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../../basic/template.hpp"
#include "../../math/FastFactorize.hpp"
int main() {
	int Q;
	lint a;
	std::cin >> Q;
	while (Q--) {
		std::cin >> a;
		if (a == 1)
			std::cout << 0 << std::endl;
		else {
			std::vector<lint> res = FastFactorize::factorize(a);
			std::cout << res.size() << ' ' << res << std::endl;
		}
	}
}