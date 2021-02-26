#pragma once
#include "../other/template.hpp"
int DiscreteLogarithm(int X, int Y, int M) {
	if (Y == 0 && M == 1) return 0;
	if (X == 0) {
		if (Y == 0) return 1;
		if (Y == 1) return 0;
		return -1;
	}
	if (Y == 1) return 0;
	if (Y == 0) {
		int inf_p = 1, tmp = M, cur = 1;
		while (tmp) inf_p = lint(inf_p) * X % M, tmp >>= 1, cur <<= 1;
		if (inf_p) return -1;
		int ans = 0, now = 1;
		while (cur >>= 1) {
			if (lint(now) * modpow(X, cur, M) % M) {
				now = lint(now) * modpow(X, cur, M) % M;
				ans += cur;
			}
		}
		return ans + 1;
	}
	int m = std::sqrt(M) + 1, c = modpow(X, m, M);
	std::unordered_map<int, int> mp;
	int cur = 1, p = 0;
	REP(i, m) {
		cur = lint(cur) * c % M;
		p += m;
		if (mp.find(cur) != mp.end()) break;
		mp.insert({cur, p});
	}
	cur = Y;
	int res = INF;
	rep(i, m) {
		if (mp.find(cur) != mp.end()) {
			if (modpow(X, mp[cur] - i, M) == Y) chmin(res, mp[cur] - i);
		}
		cur = lint(cur) * X % M;
	}
	return res == INF ? -1 : res;
}