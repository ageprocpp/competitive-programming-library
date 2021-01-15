#pragma once
#include "../other/template.hpp"
class PrimalDual {
	class edge {
	  public:
		int to, cap;
		lint cost;
		int rev, id;
	};
	int n, idx = 0, s, t;
	lint curres = 0;
	std::vector<std::vector<edge>> vec;
	std::vector<int> prevv, preve;
	std::vector<lint> h, dist;
	bool negative = false;
	lint BellmanFord() {
		dist.assign(n, LINF);
		dist[s] = 0;
		rep(i, n - 1) {
			rep(j, n) {
				rep(k, vec[j].size()) {
					const edge& e = vec[j][k];
					if (e.cap > 0 &&
						chmin(dist[e.to], dist[j] + e.cost + h[j] - h[e.to])) {
						prevv[e.to] = j;
						preve[e.to] = k;
					}
				}
			}
		}
		if (dist[t] == LINF) {
			std::cerr << "The demand is over maximum flow." << std::endl;
			return -1;
		}
		rep(i, n) h[i] += dist[i];
		for (int i = t; i != s; i = prevv[i]) {
			vec[prevv[i]][preve[i]].cap--;
			vec[i][vec[prevv[i]][preve[i]].rev].cap++;
		}
		return h[t];
	}

  public:
	PrimalDual(int n, int s, int t) : n(n), s(s), t(t) {
		vec.resize(n);
		h.resize(n);
		dist.resize(n);
		prevv.resize(n);
		preve.resize(n);
	}
	void add_edge(int from, int to, int cap, lint cost) {
		if (cost < 0) negative = true;
		vec[from].push_back({to, cap, cost, (int)vec[to].size(), -1});
		vec[to].push_back({from, 0, -cost, (int)vec[from].size() - 1, idx++});
	}
	lint add_flow(int f) {
		if (negative) {
			curres += BellmanFord();
			f--;
			negative = false;
		}
		while (f > 0) {
			dist.assign(n, LINF);
			dist[s] = 0;
			prique<std::pair<lint, int>> que;
			que.push({0, s});
			while (!que.empty()) {
				auto p = que.top();
				que.pop();
				if (dist[p.second] < p.first) continue;
				rep(i, vec[p.second].size()) {
					edge& e = vec[p.second][i];
					if (e.cap > 0 &&
						chmin(dist[e.to], dist[p.second] + e.cost +
											  h[p.second] - h[e.to])) {
						prevv[e.to] = p.second;
						preve[e.to] = i;
						que.push({dist[e.to], e.to});
					}
				}
			}
			if (dist[t] == LINF) {
				std::cerr << "The demand is over the maximum flow."
						  << std::endl;
				return -1;
			}
			rep(i, n) h[i] += dist[i];
			int d = f;
			for (int i = t; i != s; i = prevv[i]) {
				chmin(d, vec[prevv[i]][preve[i]].cap);
			}
			f -= d;
			curres += (lint)d * h[t];
			for (int i = t; i != s; i = prevv[i]) {
				vec[prevv[i]][preve[i]].cap -= d;
				vec[i][vec[prevv[i]][preve[i]].rev].cap += d;
			}
		}
		return curres;
	}
	std::vector<lint> restore() {
		std::vector<lint> res(idx);
		rep(i, n) {
			for (const auto& j : vec[i]) {
				if (j.id != -1) res[j.id] = j.cap;
			}
		}
		return res;
	}
	void reset() {
		rep(i, n) {
			for (auto& j : vec[i]) {
				if (j.id != -1) {
					vec[j.to][j.rev].cap += j.cap;
					j.cap = 0;
				}
			}
		}
	}
};

/**
 * @title Primal-dual algorithm
 */