#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include "../../basic/template.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/Matrix.hpp"
using ModInt = StaticModInt<998244353>;
int N;
int main() {
	scanf("%d", &N);
	SquareMatrix<ModInt> mat(N);
	rep(i, N) rep(j, N) std::cin >> mat[i][j];
	auto res = mat.inverse();
	if (res.size() == decltype(res.size()){0, 0})
		puts("-1");
	else
		std::cout << res << std::endl;
	return 0;
}