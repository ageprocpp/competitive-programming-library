#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "../../basic/template.hpp"
#include "../../math/CountPrime.hpp"
int main() {
	lint N;
	std::cin >> N;
	std::cout << count_prime(N) << '\n';
}