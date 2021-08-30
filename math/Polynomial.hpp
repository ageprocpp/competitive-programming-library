#pragma once
#include "../other/template.hpp"
#include "../other/type_traits.hpp"
#include "NumberTheoreticTransform.hpp"
template <typename T, typename mod_specify = void>
class Polynomial {
	std::vector<T> vec;

  public:
	Polynomial() : vec() {}
	Polynomial(const std::vector<T>& v) : vec(v) {}
	Polynomial operator*(const Polynomial& p) {
		auto res = *this;
		res *= p;
		return res;
	}
	Polynomial& operator*=(const Polynomial& p) {
		auto conv_func = [](const std::vector<T>& x, const std::vector<T>& y) {
			if constexpr (is_ModInt_v<T>)
				return NumberTheoreticTransform::convolution(x, y);
			else
				return NumberTheoreticTransform::convolution_plain(x, y);
		};
		auto res = conv_func(vec, p.vec);
		std::vector<T> nvec(vec.size() + p.vec.size() - 1);
		rep(i, vec.size()) {
			rep(j, p.vec.size()) nvec[i + j] = vec[i] * p.vec[j];
		}
		vec = std::move(nvec);
		return *this;
	}

	template <typename U>
	friend std::ostream& operator<<(std::ostream&, const Polynomial<U>&);
};

template <typename T, typename U,
		  std::enable_if_t<is_ModInt_v<U>, std::nullptr_t> = nullptr>
Polynomial<U> interpolate(const std::vector<T>& x, std::vector<U> y) {
	const size_t N = x.size() - 1;
	rep(i, N + 1) {
		U t = 1;
		rep(j, N + 1) if (i != j) t *= x[i] - x[j];
		y[i] /= t;
	}
	U cur = 0, nxt = 1;
	auto dp = make_vec<U>(2, N + 2);
	dp[0][0] = -x[0], dp[0][1] = 1;
	REP(i, N) {
		rep(j, N + 2) {
			dp[nxt][j] = -dp[cur][j] * x[i];
			if (j) dp[nxt][j] += dp[cur][j - 1];
		}
		std::swap(nxt, cur);
	}
	std::vector<U> xinv(N + 1), ret(N + 1);
	rep(i, N + 1) xinv[i] = x[i].inv();
	rep(i, N + 1) {
		if (!y[i]) continue;
		if (!x[i]) {
			rep(j, N + 1) ret[j] += dp[cur][j + 1] * y[i];
		} else {
			ret[0] -= dp[cur][0] * xinv[i] * y[i];
			U pre = -dp[cur][0] * xinv[i];
			REP(j, N) {
				ret[j] -= (dp[cur][j] - pre) * xinv[i] * y[i];
				pre = (pre - dp[cur][j]) * xinv[i];
			}
		}
	}
	return ret;
}

template <typename T, typename U,
		  std::enable_if_t<is_ModInt_v<U>, std::nullptr_t> = nullptr>
U interpolate(const std::vector<T>& x, const std::vector<U>& y, T S) {
	const size_t N = x.size() - 1;
	U ret = 0;
	rep(i, N + 1) {
		U t = 1;
		rep(j, N + 1) {
			if (i == j) continue;
			t *= S - x[j];
			t /= x[i] - x[j];
		}
		ret += t * y[i];
	}
	return ret;
}

template <typename T, typename U,
		  std::enable_if_t<is_ModInt_v<U>, std::nullptr_t> = nullptr>
U interpolate_arithmetic(T a, T d, const std::vector<U>& y, T S) {
	const size_t N = y.size() - 1;
	auto ft = make_vec<U>(2, N);
	ft[0][0] = S - a;
	REP(i, N - 1) ft[0][i] = ft[0][i - 1] * (S - a - U(d) * i);
	ft[1][N - 1] = 1;
	for (int i = N - 2; i >= 0; i--)
		ft[1][i] = ft[1][i + 1] * (S - a - U(d) * (i + 2));
	U f = 1;
	REP(i, N) f *= -U(d) * i;
	f = f.inv();
	U ret = y[0] * f * ft[1][0] * (S - a - d);
	rep(i, N) {
		f *= U(i - N) / (i + 1);
		ret += y[i + 1] * f * ft[0][i] * ft[1][i];
	}
	return ret;
}

template <typename T>
std::ostream& operator<<(std::ostream& ost, const Polynomial<T>& p) {
	rep(i, p.vec.size()) {
		ost << p.vec[i];
		if (i != (int)p.vec.size() - 1) ost << ' ';
	}
	return ost;
}