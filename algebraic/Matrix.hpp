#pragma once
#include "../other/template.hpp"

template <class T>
class Matrix {
  protected:
	uint N, M;
	std::vector<std::vector<T>> elems;

  public:
	Matrix() = default;
	Matrix(uint N_, uint M_) : N(N_), M(M_), elems(N, std::vector<T>(M)) {}
	std::vector<T>& operator[](uint idx) { return elems[idx]; }
	const std::vector<T>& operator[](uint idx) const { return elems[idx]; }
	decltype(elems)& data() { return elems; }
	const decltype(elems)& data() const { return elems; }

	void resize(int N_, int M_) {
		elems.resize(N_);
		rep(i, N_) elems[i].resize(M_);
	}

	Matrix operator*(Matrix rhs) const {
		Matrix<T> res(N, rhs.M);
		rep(i, N) rep(j, M) rep(k, rhs.M) res[i][k] +=
			elems[i][j] * rhs.elems[j][k];
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
	constexpr FixedMatrix(const FixedMatrix<T, N, M>& rhs) {
		elems = rhs.elems;
	}
	constexpr FixedMatrix(FixedMatrix<T, N, M>&& rhs) {
		elems = std::move(rhs.elems);
	}
	constexpr std::array<T, N>& operator[](uint idx) { return elems[idx]; }
	constexpr const std::array<T, N>& operator[](uint idx) const {
		return elems[idx];
	}
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

	constexpr FixedMatrix<T, N, M> operator+(
		const FixedMatrix<T, N, M>& rhs) const {
		FixedMatrix<T, N, M> res = *this;
		return res += rhs;
	}

	template <uint L>
	constexpr FixedMatrix<T, N, L> operator*(
		const FixedMatrix<T, M, L>& rhs) const {
		FixedMatrix<T, N, L> res;
		rep(i, N) rep(j, M) rep(k, L) res[i][k] +=
			elems[i][j] * rhs.elems[j][k];
		return res;
	}
};

template <class T, uint N>
class FixedSquareMatrix : public FixedMatrix<T, N, N> {
	using FixedMatrix<T, N, N>::FixedMatrix;
	using FixedMatrix<T, N, N>::elems;

  public:
	using FixedMatrix<T, N, N>::operator*;
	constexpr FixedSquareMatrix(const FixedMatrix<T, N, N>& obj)
		: FixedMatrix<T, N, N>(obj) {}
	constexpr FixedSquareMatrix(FixedMatrix<T, N, N>&& obj)
		: FixedMatrix<T, N, N>(obj) {}

	constexpr FixedSquareMatrix<T, N>& operator*=(
		const FixedSquareMatrix<T, N>& rhs) {
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

	constexpr static FixedSquareMatrix<T, N> ident() {
		FixedSquareMatrix<T, N> res;
		rep(i, N) res[i][i] = 1;
		return res;
	}
};

/**
 * @title Matrix
 */