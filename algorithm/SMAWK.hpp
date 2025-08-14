#pragma once

template <typename T, class F>
std::vector<T> smawk(int N, int M, F&& f) {
	std::vector<int> rows(N), columns(M);
	std::iota(all(rows), 0), std::iota(all(columns), 0);
	std::vector<T> res(N);
	lambda_fix([f = std::forward<F>(f), &res](auto self, const std::vector<int>& R,
											  const std::vector<int>& C) -> std::vector<int> {
		const int n = R.size();
		if (!n) return {};
		std::vector<int> C2;
		for (const int i : C) {
			while (!C2.empty() && f(R[C2.size() - 1], C2.back()) > f(R[C2.size() - 1], i))
				C2.pop_back();
			if (C2.size() < n) C2.push_back(i);
		}
		std::vector<int> R2;
		for (int i = 1; i < n; i += 2) R2.emplace_back(R[i]);
		const auto A2 = self(self, R2, C2);
		std::vector<int> A(n);
		rep(i, A2.size()) A[2 * i + 1] = A2[i];
		int j = 0;
		for (int i = 0; i < n; i += 2) {
			res[R[i]] = f(R[i], C2[j]), A[i] = C2[j];
			const int end = i + 1 == n ? C2.back() : A[i + 1];
			while (C2[j] != end) {
				j++;
				if (chmin(res[R[i]], f(R[i], C2[j]))) A[i] = C2[j];
			}
		}
		return A;
	})(rows, columns);
	return res;
}