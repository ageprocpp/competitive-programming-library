#pragma once
#include "../other/template.hpp"
#include "StronglyConnectedComponents.hpp"
class TwoSat {
	int N;
	StronglyConnectedComponents scc;
	std::vector<int> ans;

  public:
	TwoSat(int N_) : N(N_), scc(2 * N_), ans(N_) {}
	void add_clause(int i, bool f, int j, bool g) {
		scc.add_edge(2 * i + int(!f), 2 * j + int(g));
		scc.add_edge(2 * j + int(!g), 2 * i + int(f));
	}
	void build() { scc.build(); }
	bool satisfiable() {
		auto ids = scc.get_ids();
		rep(i, N) {
			if (ids[2 * i] == ids[2 * i + 1]) return false;
			ans[i] = ids[2 * i] < ids[2 * i + 1];
		}
		return true;
	}
	std::vector<int> answer() { return ans; }
};

/**
 * @title Two-sat solver
 */