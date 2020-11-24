#pragma once
#include "../other/template.hpp"
template <typename T>
class Dijkstra {
	int N;
	std::vector<std::vector<std::pair<int, T>>> vec, rev;
	bool exec(int s, int t, std::vector<T> &dist) {
		dist.assign(N, std::numeric_limits<T>::max());
		dist[s] = 0;
		prique<std::pair<T, int>> que;
		que.push({0, s});
		while (!que.empty()) {
			auto p = que.top();
			que.pop();
			if (dist[p.second] < p.first) continue;
			for (auto i : vec[p.second]) {
				if (chmin(dist[i.first], p.first + i.second)) {
					que.push({dist[i.first], i.first});
				}
			}
		}
		return dist[t] != std::numeric_limits<T>::max();
	}

  public:
	Dijkstra(int N) : N(N), vec(N), rev(N) {}
	void add_edge(int from, int to, T cost) {
		vec[from].emplace_back(std::pair<int, T>{to, cost});
		rev[to].emplace_back(std::pair<int, T>{from, cost});
	}
	T get_dist(int s, int t) { return get_dist_and_path(s, t).first; }
	std::vector<int> get_path(int s, int t) {
		return get_dist_and_path(s, t).second;
	}
	std::pair<T, std::vector<int>> get_dist_and_path(int s, int t) {
		std::vector<T> dist;
		std::vector<int> res = {t};
		std::vector<bool> used(N);
		if (!exec(s, t, dist)) return {-1, {}};
		used[t] = true;
		int head = t;
		while (head != s) {
			for (auto i : rev[head]) {
				if (!used[i.first] && dist[i.first] + i.second == dist[head]) {
					used[i.first] = true;
					head = i.first;
					res.emplace_back(head);
					break;
				}
			}
		}
		std::reverse(all(res));
		return {dist[t], res};
	}
};