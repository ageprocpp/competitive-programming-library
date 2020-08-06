#pragma once
#include "../other/template.hpp"
class MyComplex{
	double realvalue, imagvalue;
public:
	MyComplex() :realvalue(0), imagvalue(0) {}
	MyComplex(const double& realvalue, const double& imagvalue) : realvalue(realvalue), imagvalue(imagvalue) {}
	MyComplex(const double& realvalue) : realvalue(realvalue), imagvalue(0) {}
	MyComplex(const std::complex<double>& c) :realvalue(c.real()), imagvalue(c.imag()) {}
	MyComplex(const MyComplex& rhs) :realvalue(rhs.realvalue), imagvalue(rhs.imagvalue) {}
	double& real(){ return this->realvalue; }
	double& imag(){ return this->imagvalue; }
	double abs()const{ return hypot(realvalue, imagvalue); }
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
		this->realvalue = this->realvalue * rhs.realvalue - this->imagvalue * rhs.imagvalue;
		this->imagvalue = pastreal * rhs.imagvalue + rhs.realvalue * this->imagvalue;
		return *this;
	}
	MyComplex& operator/=(const MyComplex& rhs) {
		*this *= MyComplex(rhs.realvalue, -rhs.imagvalue);
		double dnm = rhs.realvalue * rhs.realvalue - rhs.imagvalue * rhs.imagvalue;
		this->realvalue /= dnm;
		this->imagvalue /= dnm;
		return *this;
	}

	template<typename T>MyComplex operator+(const T& rhs)const {return MyComplex(*this)+=rhs;}
	template<typename T>MyComplex& operator+=(const T& rhs)const {return operator+=(MyComplex(rhs));}
	template<typename T>MyComplex operator-(const T& rhs)const {return MyComplex(*this)-=rhs;}
	template<typename T>MyComplex& operator-=(const T& rhs)const {return operator-=(MyComplex(rhs));}
	template<typename T>MyComplex operator*(const T& rhs)const {return MyComplex(*this)*=rhs;}
	template<typename T>MyComplex& operator*=(const T& rhs)const {return operator*=(MyComplex(rhs));}
	template<typename T>MyComplex operator/(const T& rhs)const {return MyComplex(*this)/=rhs;}
	template<typename T>MyComplex& operator/=(const T& rhs)const {return operator/=(MyComplex(rhs));}
};