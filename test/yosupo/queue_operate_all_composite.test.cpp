#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../../algebraic/StaticModInt.hpp"
#include "../../data-structure/SWAG.hpp"
#include "../../other/template.hpp"
using ModInt = StaticModInt<998244353>;
using MP = std::pair<ModInt, ModInt>;
MP op(const MP& lhs, const MP& rhs) {
	return MP{lhs.first * rhs.first, lhs.second * rhs.first + rhs.second};
}
int Q;
int main() {
	scanf("%d", &Q);
	SWAG<MP, op> swag;
	rep(i, Q) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			swag.push(MP{a, b});
		}
		if (t == 1) swag.pop();
		if (t == 2) {
			int x;
			scanf("%d", &x);
			if (swag.empty())
				printf("%d\n", x);
			else {
				auto res = swag.fold();
				printf("%d\n", res.first * x + res.second);
			}
		}
	}
}