#pragma once
#include "../basic/template.hpp"
#include "Graph.hpp"
#include "../data-structure/PrioritizableBinaryHeap.hpp"
template <typename W>
class Dijkstra {
	Graph<true, W> G;

  public:
	Dijkstra() {}
	Dijkstra(const Graph<true, W>& G_) : G(G_) {}
	Dijkstra(Graph<true, W>&& G_) : G(G_) {}

	void set(const Graph<true, W>& G_) { G = G_; }

	std::vector<W> operator()(int s) {
		std::vector<W> dist(G.N, std::numeric_limits<W>::max());
		dist[s] = 0;
		PrioritizableBinaryHeap<W, std::greater<W>> que(G.N);
		que.push(s, 0);
		while (!que.empty()) {
			auto p = que.pop();
			for (const auto& i : G.vec[p.first]) {
				if (chmin(dist[i.first], p.second + i.second))
					que.increase_key(i.first, dist[i.first]);
			}
		}
		return dist;
	}

	W operator()(int s, int t) {
		std::vector<W> dist(G.N, std::numeric_limits<W>::max());
		dist[s] = 0;
		PrioritizableBinaryHeap<W, std::greater<W>> que(G.N);
		que.push(s, 0);
		while (!que.empty()) {
			auto p = que.pop();
			if (p.first == t) break;
			for (const auto& i : G.vec[p.first]) {
				if (chmin(dist[i.first], p.second + i.second))
					que.increase_key(i.first, dist[i.first]);
			}
		}
		return dist[t];
	}

	std::pair<W, std::vector<int>> dist_and_path(int s, int t) {
		std::vector<W> from(G.N), dist(G.N, std::numeric_limits<W>::max());
		dist[s] = 0;
		PrioritizableBinaryHeap<W, std::greater<W>> que(G.N);
		que.push(s, 0);
		while (!que.empty()) {
			auto p = que.top();
			que.pop();
			if (p.first == t) break;
			for (auto i : G.vec[p.first]) {
				if (chmin(dist[i.first], p.second + i.second)) {
					from[i.first] = p.first;
					que.increase_key(i.first, dist[i.first]);
				}
			}
		}
		if (dist[t] == std::numeric_limits<W>::max()) return {dist[t], {}};
		W res_dist = dist[t];
		std::vector<int> res_vec = {t};
		while (t != s) res_vec.emplace_back(t = from[t]);
		std::reverse(all(res_vec));
		return {res_dist, res_vec};
	}
};

/**
 * @title Dijkstra's algorithm
 */