#pragma once
#include "../basic/template.hpp"

template <class T,
		  std::enable_if_t<
#if __cplusplus >= 201703L
			  std::is_same_v<decltype(std::declval<const T&>() / std::declval<const T&>()), T>
#else
			  std::is_same<decltype(std::declval<const T&>() / std::declval<const T&>()), T>::value
#endif
			  ,
			  std::nullptr_t> = nullptr>
class Matrix {
  protected:
	uint N, M;
	std::vector<std::vector<T>> elems;

  public:
	Matrix() = default;
	Matrix(uint N_, uint M_) : N(N_), M(M_), elems(N, std::vector<T>(M)) {}
	[[nodiscard]] std::pair<uint, uint> size() const { return {N, M}; };
	std::vector<T>& operator[](uint idx) { return elems[idx]; }
	const std::vector<T>& operator[](uint idx) const { return elems[idx]; }
	decltype(elems)& data() { return elems; }
	const decltype(elems)& data() const { return elems; }

	void resize(int N_, int M_) {
		elems.resize(N_);
		rep(i, N_) elems[i].resize(M_);
	}

	Matrix<T> transposed() const {
		Matrix<T> res(M, N);
		rep(i, N) rep(j, M) res[j][i] = (*this)[i][j];
		return res;
	}

	uint rank() const {
		if (!N || !M) return 0;
		Matrix<T> tmp;
		if (N <= M)
			tmp = *this;
		else
			tmp = this->transposed();
		int row = 0;
		rep(i, tmp.M) {
			if (!tmp[row][i]) {
				for (int j = row + 1; j < tmp.N; j++) {
					if (tmp[j][i]) {
						std::swap(tmp[row], tmp[j]);
						break;
					}
				}
				if (!tmp[row][i]) continue;
			}
			assert(tmp[row][i]);
			T inv = T(1) / tmp[row][i];
			for (int j = i; j < tmp.M; j++) tmp[row][j] *= inv;
			rep(j, tmp.N) {
				if (j == row) continue;
				if (tmp[j][i]) {
					for (int k = i + 1; k < tmp.M; k++) tmp[j][k] -= tmp[j][i] * tmp[row][k];
					tmp[j][i] = 0;
				}
			}
			if (++row == tmp.N) break;
		}
		return row;
	}

	Matrix operator*(Matrix rhs) const {
		Matrix<T> res(N, rhs.M);
		rep(i, N) rep(j, M) rep(k, rhs.M) res[i][k] += elems[i][j] * rhs.elems[j][k];
		return res;
	}
};

template <class T>
class SquareMatrix : public Matrix<T> {
	using Matrix<T>::N;
	using Matrix<T>::Matrix;
	using Matrix<T>::elems;

  public:
	SquareMatrix(uint N_) : Matrix<T>(N_, N_) {}
	SquareMatrix<T>& operator=(const Matrix<T>& rhs) {
		elems = rhs.data();
		return *this;
	}
	SquareMatrix<T>& operator=(Matrix<T>&& rhs) {
		elems = std::move(rhs.data());
		return *this;
	}
	SquareMatrix<T> operator*=(const SquareMatrix<T>& rhs) {
		*this = *this * rhs;
		return *this;
	}

	SquareMatrix<T> pow(lint p) const {
		SquareMatrix<T> res{N}, memo = *this;
		rep(i, N) res[i][i] = 1;
		while (p) {
			if (p & 1) res *= memo;
			p >>= 1;
			memo *= memo;
		}
		return res;
	}

	SquareMatrix<T> inverse() const {
		Matrix<T> tmp(N, 2 * N);
		rep(i, N) {
			rep(j, N) tmp[i][j] = (*this)[i][j];
			tmp[i][N + i] = 1;
		}
		rep(i, N) {
			if (!tmp[i][i]) {
				for (int j = i + 1; j < N; j++) {
					if (tmp[j][i]) {
						std::swap(tmp[i], tmp[j]);
						break;
					}
				}
			}
			if (!tmp[i][i]) return {};
			T inv = T(1) / tmp[i][i];
			for (int j = i; j < 2 * N; j++) tmp[i][j] *= inv;
			rep(j, N) {
				if (i == j) continue;
				for (int k = i + 1; k < 2 * N; k++) {
					tmp[j][k] -= tmp[j][i] * tmp[i][k];
				}
				tmp[j][i] = 0;
			}
		}
		SquareMatrix<T> res(N);
		rep(i, N) rep(j, N) res[i][j] = tmp[i][N + j];
		return res;
	}

	constexpr T determinant() const {
		SquareMatrix<T> tmp = *this;
		T res(1);
		rep(i, N) {
			if (!tmp[i][i]) {
				for (int j = i + 1; j < N; j++) {
					if (tmp[j][i]) {
						std::swap(tmp[i], tmp[j]);
						res = -res;
						break;
					}
				}
			}
			res *= tmp[i][i];
			for (int j = i + 1; j < N; j++) {
				T inv = T(1) / tmp[i][i];
				for (int k = i + 1; k < N; k++) {
					tmp[j][k] -= tmp[j][i] * inv * tmp[i][k];
				}
			}
		}
		return res;
	}
};

template <class T, uint N, uint M>
class FixedMatrix {
  protected:
	std::array<std::array<T, M>, N> elems;

  public:
	constexpr FixedMatrix() { rep(i, N) elems[i].fill(0); }
	constexpr FixedMatrix(std::initializer_list<T> init) {
		auto ite = init.begin();
		rep(i, N) rep(j, M) elems[i][j] = *ite++;
	}
	constexpr FixedMatrix(const FixedMatrix<T, N, M>& rhs) { elems = rhs.elems; }
	constexpr FixedMatrix(FixedMatrix<T, N, M>&& rhs) { elems = std::move(rhs.elems); }
	constexpr std::array<T, N>& operator[](uint idx) { return elems[idx]; }
	constexpr const std::array<T, N>& operator[](uint idx) const { return elems[idx]; }
	constexpr decltype(elems)& data() { return elems; }
	constexpr const decltype(elems)& data() const { return elems; }

	constexpr FixedMatrix<T, N, M> operator=(const FixedMatrix<T, N, M>& rhs) {
		elems = rhs.elems;
		return *this;
	}
	constexpr FixedMatrix<T, N, M> operator=(FixedMatrix<T, N, M>&& rhs) {
		elems = std::move(rhs.elems);
		return *this;
	}

	constexpr FixedMatrix<T, N, M> operator+=(const FixedMatrix<T, N, M>& rhs) {
		rep(i, N) rep(j, M) elems[i][j] += rhs.elems[i][j];
		return *this;
	}

	constexpr FixedMatrix<T, N, M> operator+(const FixedMatrix<T, N, M>& rhs) const {
		FixedMatrix<T, N, M> res = *this;
		return res += rhs;
	}

	template <uint L>
	constexpr FixedMatrix<T, N, L> operator*(const FixedMatrix<T, M, L>& rhs) const {
		FixedMatrix<T, N, L> res;
		rep(i, N) rep(j, M) rep(k, L) res[i][k] += elems[i][j] * rhs.elems[j][k];
		return res;
	}

	constexpr FixedMatrix<T, M, N> transposed() const {
		FixedMatrix<T, M, N> res(M, N);
		rep(i, N) rep(j, M) res[j][i] = (*this)[i][j];
		return res;
	}

	constexpr uint rank() const {
		if (!N || !M) return 0;
		std::conditional_t<N <= M, FixedMatrix<T, N, M>, FixedMatrix<T, M, N>> tmp;
		uint N_, M_;
		if constexpr (N <= M) {
			tmp = *this;
			N_ = N, M_ = M;
		} else {
			tmp = this->transposed();
			N_ = M, M_ = N;
		}
		int row = 0;
		rep(i, M_) {
			if (!tmp[row][i]) {
				for (int j = row + 1; j < N_; j++) {
					if (tmp[j][i]) {
						std::swap(tmp[row], tmp[j]);
						break;
					}
				}
				if (!tmp[row][i]) continue;
			}
			assert(tmp[row][i]);
			T inv = T(1) / tmp[row][i];
			for (int j = i; j < M_; j++) tmp[row][j] *= inv;
			rep(j, N_) {
				if (j == row) continue;
				if (tmp[j][i]) {
					for (int k = i + 1; k < M_; k++) tmp[j][k] -= tmp[j][i] * tmp[row][k];
					tmp[j][i] = 0;
				}
			}
			if (++row == N_) break;
		}
		return row;
	}
};

template <class T, uint N>
class FixedSquareMatrix : public FixedMatrix<T, N, N> {
	using FixedMatrix<T, N, N>::FixedMatrix;
	using FixedMatrix<T, N, N>::elems;

  public:
	using FixedMatrix<T, N, N>::operator*;
	constexpr FixedSquareMatrix(const FixedMatrix<T, N, N>& obj) : FixedMatrix<T, N, N>(obj) {}
	constexpr FixedSquareMatrix(FixedMatrix<T, N, N>&& obj) : FixedMatrix<T, N, N>(obj) {}

	constexpr FixedSquareMatrix<T, N>& operator*=(const FixedSquareMatrix<T, N>& rhs) {
		*this = *this * rhs;
		return *this;
	}

	constexpr FixedSquareMatrix<T, N> pow(lint p) const {
		FixedSquareMatrix<T, N> res, memo = *this;
		rep(i, N) res[i][i] = 1;
		while (p) {
			if (p & 1) res *= memo;
			p >>= 1;
			memo *= memo;
		}
		return res;
	}

	FixedSquareMatrix<T, N> inverse() const {
		FixedMatrix<T, N, 2 * N> tmp;
		rep(i, N) {
			rep(j, N) tmp[i][j] = (*this)[i][j];
			tmp[i][N + i] = 1;
		}
		rep(i, N) {
			if (!tmp[i][i]) {
				for (int j = i + 1; j < N; j++) {
					if (tmp[j][i]) {
						std::swap(tmp[i], tmp[j]);
						break;
					}
				}
				if (!tmp[i][i]) return {};
			}
			T inv = T(1) / tmp[i][i];
			for (int j = i; j < 2 * N; j++) tmp[i][j] *= inv;
			rep(j, N) {
				if (i == j) continue;
				for (int k = i + 1; k < 2 * N; k++) {
					tmp[j][k] -= tmp[j][i] * tmp[i][k];
				}
				tmp[j][i] = 0;
			}
		}
		FixedSquareMatrix<T, N> res;
		rep(i, N) rep(j, N) res[i][j] = tmp[i][N + j];
		return res;
	}

	constexpr T determinant() const {
		FixedSquareMatrix<T, N> tmp = *this;
		T res(1);
		rep(i, N) {
			if (tmp[i][i] == 0) {
				for (int j = i + 1; j < N; j++) {
					if (tmp[j][i]) {
						std::swap(tmp[i], tmp[j]);
						res = -res;
						break;
					}
				}
			}
			res *= tmp[i][i];
			for (int j = i + 1; j < N; j++) {
				T inv = T(1) / tmp[i][i];
				for (int k = i + 1; k < N; k++) {
					tmp[j][k] -= tmp[j][i] * inv * tmp[i][k];
				}
			}
		}
		return res;
	}

	constexpr static FixedSquareMatrix<T, N> ident() {
		FixedSquareMatrix<T, N> res;
		rep(i, N) res[i][i] = 1;
		return res;
	}
};

template <class Stream, class T>
Stream& operator<<(Stream& ost, const Matrix<T>& mat) {
	const auto& data = mat.data();
	rep(i, data.size()) ost << data[i] << '\n';
	return ost;
}

template <class Stream, class T, uint N, uint M>
Stream& operator<<(Stream& ost, const FixedMatrix<T, N, M>& mat) {
	const auto& data = mat.data();
	rep(i, data.size()) ost << data[i] << '\n';
	return ost;
}

/**
 * @title Matrix
 */