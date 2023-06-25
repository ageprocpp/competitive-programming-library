#pragma once
#include "../basic/template.hpp"
class StronglyConnectedComponents {
	int N;
	std::vector<std::vector<int>> vec, rvec;
	std::vector<std::vector<int>> scc;

  public:
	StronglyConnectedComponents() {}
	StronglyConnectedComponents(int N_) : N(N_) { vec.resize(N), rvec.resize(N); }
	void add_edge(int from, int to) { vec[from].emplace_back(to), rvec[to].emplace_back(from); }
	void build() {
		scc.clear();
		std::vector<bool> used(N);
		std::vector<int> vs;
		auto dfs = lambda_fix([&](auto self, int node) -> void {
			used[node] = true;
			for (const int& i : vec[node]) {
				if (!used[i]) self(self, i);
			}
			vs.emplace_back(node);
		});
		auto rdfs = lambda_fix([&](auto self, int node) -> void {
			used[node] = true;
			scc.back().emplace_back(node);
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
				scc.emplace_back();
				rdfs(vs[i]);
			}
		}
	}
	std::vector<std::vector<int>> get_scc() const { return scc; }
	std::vector<std::vector<int>> get_newgraph() const {
		std::vector<int> ids = get_ids();
		std::vector<std::vector<int>> res(scc.size());
		rep(i, N) {
			for (int j : vec[i]) res[ids[i]].emplace_back(ids[j]);
		}
		rep(i, scc.size()) std::sort(all(res[i])),
			res[i].erase(std::unique(all(res[i])), res[i].end());
		return res;
	}
	std::vector<int> get_ids() const {
		std::vector<int> res(N);
		rep(i, scc.size()) for (const auto& j : scc[i]) res[j] = i;
		return res;
	}
	size_t size() const { return N; }
};

/**
 * @title Strongly connected components
 */