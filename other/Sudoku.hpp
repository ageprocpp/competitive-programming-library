#pragma once
#include "../basic/template.hpp"
class Sudoku {
	static void determine(int i, int j, int x,
						  std::array<std::array<std::array<bool, 9>, 9>, 9>& flag,
						  std::array<std::array<int, 9>, 9>& target) {
		target[i][j] = x;
		rep(k, 9) flag[i][k][x - 1] = flag[k][j][x - 1] = false;
		rep(k, 3) rep(l, 3) flag[i / 3 * 3 + k][j / 3 * 3 + l][x - 1] = false;
		rep(k, 9) flag[i][j][k] = false;
		flag[i][j][x - 1] = true;
	}
	static bool completed(const std::array<std::array<int, 9>, 9>& ans) {
		rep(i, 9) rep(j, 9) if (!ans[i][j]) return false;
		return true;
	}
	static bool solvable(const std::array<std::array<std::array<bool, 9>, 9>, 9>& flag,
						 const std::array<std::array<int, 9>, 9>& ans) {
		rep(i, 9) {
			rep(j, 9) {
				if (!ans[i][j]) {
					bool ok = false;
					rep(k, 9) ok |= flag[i][j][k];
					if (!ok) return false;
				}
			}
		}
		return true;
	}
	static void logic(std::array<std::array<std::array<bool, 9>, 9>, 9>& flag,
					  std::array<std::array<int, 9>, 9>& ans) {
		while (true) {
			bool updated = false;
			rep(i, 9) rep(j, 9) {
				int cand = 0, cnt = 0;
				rep(k, 9) {
					if (!ans[i][j] && flag[i][j][k]) {
						cand = k + 1, cnt++;
						if (cnt > 1) break;
					}
				}
				if (cnt == 1) determine(i, j, cand, flag, ans), updated = true;
			}
			rep(i, 9) {
				rep(j, 9) {
					int cand = -1;
					rep(k, 9) {
						if (ans[i][k] == j + 1) {
							cand = -1;
							break;
						}
						if (flag[i][k][j]) {
							if (cand != -1) {
								cand = -1;
								break;
							}
							cand = k;
						}
					}
					if (cand != -1) determine(i, cand, j + 1, flag, ans), updated = true;
					cand = -1;
					rep(k, 9) {
						if (ans[k][i] == j + 1) {
							cand = -1;
							break;
						}
						if (flag[k][i][j]) {
							if (cand != -1) {
								cand = -1;
								break;
							}
							cand = k;
						}
					}
					if (cand != -1) determine(cand, i, j + 1, flag, ans), updated = true;
				}
			}
			rep(i, 3) {
				rep(j, 3) {
					rep(k, 9) {
						IP cand = {-1, -1};
						bool ng = false;
						rep(l, 3) {
							rep(m, 3) {
								if (ans[i * 3 + l][j * 3 + m] == k + 1) {
									cand = IP{-1, -1};
									ng = true;
									break;
								}
								if (flag[i * 3 + l][j * 3 + m][k]) {
									if (cand != IP{-1, -1}) {
										cand = IP{-1, -1};
										ng = true;
										break;
									}
									cand = IP{l, m};
								}
							}
							if (ng) break;
						}
						if (!ng && cand != IP{-1, -1})
							determine(i * 3 + cand.first, j * 3 + cand.second, k + 1, flag, ans),
								updated = true;
					}
				}
			}
			if (!updated) break;
		}
	}
	static bool solve(std::array<std::array<std::array<bool, 9>, 9>, 9>& flag,
					  std::array<std::array<int, 9>, 9>& ans) {
		logic(flag, ans);
		auto nflag = flag;
		auto nans = ans;
		rep(i, 9) {
			rep(j, 9) {
				if (!nans[i][j]) {
					rep(k, 9) {
						if (nflag[i][j][k]) {
							determine(i, j, k + 1, nflag, nans);
							if (!solvable(nflag, nans) || !solve(nflag, nans)) {
								flag[i][j][k] = false;
								nflag = flag, nans = ans;
							}
						}
					}
				}
			}
		}
		if (completed(nans)) {
			flag = nflag, ans = nans;
			return true;
		}
		return false;
	}

  public:
	static std::array<std::array<int, 9>, 9> solve(const std::array<std::array<int, 9>, 9>& prob) {
		std::array<std::array<std::array<bool, 9>, 9>, 9> flag;
		auto ans = prob;
		rep(i, 9) rep(j, 9) rep(k, 9) flag[i][j][k] = true;
		rep(i, 9) rep(j, 9) if (prob[i][j]) determine(i, j, prob[i][j], flag, ans);
		solve(flag, ans);
		return ans;
	}
};