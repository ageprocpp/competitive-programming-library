#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "../../other/template.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/FormalPowerSeries.hpp"

using ModInt = StaticModInt<998244353>;
using FPS = FormalPowerSeries<ModInt>;
int main() {
	int N;
	std::vector<ModInt> vec;
	std::cin >> N >> vec;
	std::cout << FPS(std::move(vec)).exp() << std::endl;
}