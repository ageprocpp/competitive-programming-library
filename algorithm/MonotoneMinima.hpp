#pragma once

template <typename T, class F>
std::vector<T> monotone_minima(int N, int M, F&& f) {
	std::vector<T> ans(N);
	lambda_fix([&](auto self, int u, int d, int l, int r) {
		if (u == d || l == r) return;
		int m = (u + d) / 2;
		int res = l;
		T min = f(m, l);
		for (int i = l + 1; i < r; i++)
			if (chmin(min, f(m, i))) res = i;
		ans[m] = min;
		self(self, u, m, l, res + 1);
		self(self, m + 1, d, res, r);
	})(0, N, 0, M);
	return ans;
}
template <typename T, class F>
std::vector<T> monotone_maxima(int N, int M, F&& f) {
	std::vector<T> ans(N);
	lambda_fix([&](auto self, int u, int d, int l, int r) {
		if (u == d || l == r) return;
		int m = (u + d) / 2;
		int res = l;
		T max = f(m, l);
		for (int i = l + 1; i < r; i++)
			if (chmax(max, f(m, i))) res = i;
		ans[m] = max;
		self(self, u, m, l, res + 1);
		self(self, m + 1, d, res, r);
	})(0, N, 0, M);
	return ans;
}