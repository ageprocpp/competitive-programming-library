#pragma once
#include "../other/template.hpp"
class StronglyConnectedComponents {
	int N;
	std::vector<std::vector<int>> vec, rvec;

  public:
	StronglyConnectedComponents(int N_) : N(N_) {
		vec.resize(N);
		rvec.resize(N);
	}
	void add_edge(int from, int to) {
		vec[from].emplace_back(to);
		rvec[to].emplace_back(from);
	}
	std::vector<std::vector<int>> get_scc() {
		std::vector<bool> used(N);
		std::vector<int> vs;
		std::vector<std::vector<int>> res;
		auto dfs = lambda_fix([&](auto self, int node) -> void {
			used[node] = true;
			for (const int& i : vec[node]) {
				if (!used[i]) self(self, i);
			}
			vs.emplace_back(node);
		});
		auto rdfs = lambda_fix([&](auto self, int node) -> void {
			used[node] = true;
			res.back().emplace_back(node);
			for (const int& i : rvec[node]) {
				if (!used[i]) self(self, i);
			}
		});
		rep(i, N) {
			if (!used[i]) dfs(i);
		}
		used.assign(N, false);
		for (int i = N - 1; i >= 0; i--) {
			if (!used[vs[i]]) {
				res.emplace_back();
				rdfs(vs[i]);
			}
		}
		return res;
	}
	std::vector<int> get_ids() {
		auto vec = get_scc();
		std::vector<int> res(N);
		rep(i, vec.size()) {
			for (const auto& j : vec[i]) res[j] = i;
		}
		return res;
	}
};

/**
 * @title Strongly connected components
 */