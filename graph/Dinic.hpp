#pragma once
#include "../other/template.hpp"
class Dinic {
	class edge {
	  public:
		int to;
		lint cap;
		int rev, id;
	};
	int N, idx = 0;
	std::vector<std::vector<edge>> vec;
	std::vector<int> iter, level;
	bool bfs(int s, int t) {
		level.assign(N, -1);
		level[s] = 0;
		std::queue<int> que;
		que.push(s);
		while (!que.empty()) {
			int node = que.front();
			que.pop();
			for (const auto& i : vec[node]) {
				if (i.cap > 0 && level[i.to] == -1) {
					level[i.to] = level[node] + 1;
					que.push(i.to);
				}
			}
		}
		return level[t] != -1;
	}
	lint dfs(int node, int t, lint f) {
		if (node == t) return f;
		for (int& i = iter[node]; i < vec[node].size(); i++) {
			edge& e = vec[node][i];
			if (e.cap > 0 && level[node] < level[e.to]) {
				lint d = dfs(e.to, t, std::min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					vec[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

  public:
	Dinic(int n) : N(n) {
		vec.resize(N);
		level.resize(N);
		iter.resize(N);
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
			bfs(s, t);
			if (level[t] < 0) return res;
			iter.assign(N, 0);
			lint f;
			while ((f = dfs(s, t, LINF)) > 0) res += f;
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