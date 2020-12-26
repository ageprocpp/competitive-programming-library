#pragma once
#include "../other/template.hpp"
class MyComplex {
	double realvalue, imagvalue;

  public:
	MyComplex() : realvalue(0), imagvalue(0) {}
	template <class T, class U>
	MyComplex(const T& realvalue, const U& imagvalue)
		: realvalue(realvalue), imagvalue(imagvalue) {}
	template <class T>
	MyComplex(const T& realvalue) : realvalue(realvalue), imagvalue(0) {}
	template <class T>
	MyComplex(const std::complex<T>& c)
		: realvalue(c.real()), imagvalue(c.imag()) {}
	double& real() { return this->realvalue; }
	double& imag() { return this->imagvalue; }
	double abs() const { return hypot(realvalue, imagvalue); }
	MyComplex& operator+=(const MyComplex& rhs) {
		this->realvalue += rhs.realvalue;
		this->imagvalue += rhs.imagvalue;
		return *this;
	}
	MyComplex& operator-=(const MyComplex& rhs) {
		this->realvalue -= rhs.realvalue;
		this->imagvalue -= rhs.imagvalue;
		return *this;
	}
	MyComplex& operator*=(const MyComplex& rhs) {
		double pastreal = this->realvalue;
		this->realvalue =
			this->realvalue * rhs.realvalue - this->imagvalue * rhs.imagvalue;
		this->imagvalue =
			pastreal * rhs.imagvalue + rhs.realvalue * this->imagvalue;
		return *this;
	}
	MyComplex& operator/=(const MyComplex& rhs) {
		*this *= MyComplex(rhs.realvalue, -rhs.imagvalue);
		double dnm =
			rhs.realvalue * rhs.realvalue - rhs.imagvalue * rhs.imagvalue;
		this->realvalue /= dnm;
		this->imagvalue /= dnm;
		return *this;
	}

	template <class T>
	MyComplex operator+(const T& rhs) const {
		return MyComplex(*this) += rhs;
	}
	template <class T>
	MyComplex& operator+=(const T& rhs) const {
		return operator+=(MyComplex(rhs));
	}
	template <class T>
	MyComplex operator-(const T& rhs) const {
		return MyComplex(*this) -= rhs;
	}
	template <class T>
	MyComplex& operator-=(const T& rhs) const {
		return operator-=(MyComplex(rhs));
	}
	template <class T>
	MyComplex operator*(const T& rhs) const {
		return MyComplex(*this) *= rhs;
	}
	template <class T>
	MyComplex& operator*=(const T& rhs) const {
		return operator*=(MyComplex(rhs));
	}
	template <class T>
	MyComplex operator/(const T& rhs) const {
		return MyComplex(*this) /= rhs;
	}
	template <class T>
	MyComplex& operator/=(const T& rhs) const {
		return operator/=(MyComplex(rhs));
	}
};