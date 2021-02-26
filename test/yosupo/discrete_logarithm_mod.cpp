#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "../../other/template.hpp"
#include "../../algebraic/DiscreteLogarithm.hpp"
int main() {
	int T, X, Y, M;
	std::cin >> T;
	rep(i, T) {
		std::cin >> X >> Y >> M;
		std::cout << DiscreteLogarithm(X, Y, M) << std::endl;
	}
}