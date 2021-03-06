#pragma once
#include "../other/template.hpp"
#include "../data-structure/PrioritizableBinaryHeap.hpp"
#include "../data-structure/FibonacciHeap.hpp"
template <class T>
class Dijkstra {
	int N;
	std::vector<std::vector<std::pair<int, T>>> vec, rev;
	bool exec(int s, int t, std::vector<T> &dist) {
		dist.assign(N, std::numeric_limits<T>::max());
		dist[s] = 0;
		PrioritizableBinaryHeap<T, std::greater<T>> que(N);
		// FibonacciHeap<T, std::greater<T>> que;
		que.push(s, 0);
		while (!que.empty()) {
			auto p = que.top();
			que.pop();
			// if (dist[p.first] < p.second) continue;
			for (auto i : vec[p.first]) {
				if (chmin(dist[i.first], p.second + i.second))
					que.increase_key(i.first, dist[i.first]);
				// que.push(i.first, dist[i.first]);
			}
		}
		return dist[t] != std::numeric_limits<T>::max();
	}

  public:
	Dijkstra(int N) : N(N), vec(N), rev(N) {}
	void add_edge(int from, int to, T cost) {
		vec[from].push_back({to, cost});
		rev[to].push_back({from, cost});
	}
	T get_dist(int s, int t) {
		std::vector<T> dist;
		if (!exec(s, t, dist)) return -1;
		return dist[t];
	}
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
	std::vector<T> get_dists(int s) {
		std::vector<T> dist;
		exec(s, s, dist);
		return dist;
	}
};

/**
 * @title Dijkstra's algorithm
 */