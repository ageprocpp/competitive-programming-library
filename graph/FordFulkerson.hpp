#pragma once
#include "../other/template.hpp"
class FordFulkerson {
	class edge {
	  public:
		int to;
		lint cap;
		int rev, id;
	};
	int N, idx = 0;
	std::vector<std::vector<edge>> vec;
	std::vector<bool> used;
	lint dfs(int node, int t, lint f) {
		if (node == t) return f;
		used[node] = true;
		for (edge& e : vec[node]) {
			if (!used[e.to] && e.cap > 0) {
				lint d = dfs(e.to, t, std::min(f, e.cap));
				if (d) {
					e.cap -= d;
					vec[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

  public:
	FordFulkerson(int n) : N(n) {
		vec.resize(N);
		used.resize(N);
	}
	void reset() {
		rep(i, N) {
			for (auto& j : vec[i]) {
				if (j.id != -1) {
					vec[j.to][j.rev].cap += j.cap;
					j.cap = 0;
				}
			}
		}
	}
	void add_edge(int from, int to, lint cap) {
		vec[from].push_back({to, cap, (int)vec[to].size(), -1});
		vec[to].push_back({from, 0, (int)vec[from].size() - 1, idx++});
	}
	lint max_flow(int s, int t) {
		lint res = 0;
		while (true) {
			used.assign(N, false);
			lint f = dfs(s, t, LINF);
			if (!f) return res;
			res += f;
		}
	}
	std::vector<lint> restore() const {
		std::vector<lint> res(idx);
		rep(i, N) {
			for (const auto& j : vec[i]) {
				if (j.id != -1) res[j.id] = j.cap;
			}
		}
		return res;
	}
};

/**
 * @title Ford-Fulkerson algorithm
 */