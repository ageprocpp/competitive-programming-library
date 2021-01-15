#pragma once
#include "../other/template.hpp"
class Tree {
	using ET = std::pair<int, lint>;

  private:
	int N;
	std::vector<std::vector<ET>> vec;

  public:
	template <class T, class U>
	Tree(int M, const std::vector<std::pair<T, U>> es) : N(M) {
		vec.resize(N + 1);
		for (const auto& e : es) {
			vec[e.first].emplace_back(e.second, 1);
			vec[e.second].emplace_back(e.first, 1);
		}
	}
	template <class T, class U, class V>
	Tree(int M, const std::vector<std::pair<std::pair<T, U>, V>> es) : N(M) {
		vec.resize(N + 1);
		for (const auto& e : es) {
			vec[e.first.first].emplace_back(e.first.second, e.second);
			vec[e.first.second].emplace_back(e.first.first, e.second);
		}
	}
	std::vector<lint> GetDist(int s) {
		std::vector<lint> dist(N + 1, LINF);
		dist[0] = -LINF;
		dist[s] = 0;
		lambda_fix([&](auto self, int node) -> void {
			for (const auto& e : vec[node]) {
				if (dist[e.first] == LINF) {
					dist[e.first] = dist[node] + e.second;
					self(self, e.first);
				}
			}
		})(s);
		return dist;
	}
	std::pair<P, lint> Diameter() {
		auto d = GetDist(1);
		int x = std::max_element(all(d)) - d.begin();
		d = GetDist(x);
		auto mit = std::max_element(all(d));
		return {{x, mit - d.begin()}, *mit};
	}
	std::pair<std::vector<int>, lint> DiameterPath() {
		auto tmp = Diameter();
		auto [x, y] = tmp.first;
		lint dist = tmp.second;
		std::vector<bool> used(N + 1);
		std::vector<int> res;
		bool f = false;
		lambda_fix([&, y = y](auto self, int node) -> void {
			used[node] = true;
			if (node == y) f = true;
			for (const auto& e : vec[node]) {
				if (!used[e.first]) {
					self(self, e.first);
					if (f) break;
				}
			}
			if (f) res.push_back(node);
		})(x);
		std::reverse(all(res));
		return {res, dist};
	}
};

/**
 * @title Basic algorithms for tree
 */