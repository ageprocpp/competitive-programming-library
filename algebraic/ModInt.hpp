#pragma once
#include "../other/template.hpp"
class ModInt {
    lint value;
public:
    static const unsigned int modulo;
    ModInt() : value(0) {}
    template<typename T>
    ModInt(T value = 0) : value(value) {
        if (value < 0)value = -(lint)(-value % modulo) + modulo;
        this->value = value % modulo;
    }
    inline operator int()const { return value; }
    inline ModInt& operator+=(const ModInt& x) {
        value += x.value;
        if (value >= modulo)value -= modulo;
        return *this;
    }
    inline ModInt& operator++() {
        if (value == modulo - 1)value = 0;
        else value++;
        return *this;
    }
    inline ModInt operator-()const {
        return ModInt(0) -= *this;
    }
    inline ModInt& operator-=(const ModInt& x) {
        value -= x.value;
        if (value < 0)value += modulo;
        return *this;
    }
    inline ModInt& operator--() {
        if (value == 0)value = modulo - 1;
        else value--;
        return *this;
    }
    inline ModInt& operator*=(const ModInt& x) {
        value = value * x.value % modulo;
        return *this;
    }
    inline ModInt& operator/=(ModInt rhs) {
        int exp = modulo - 2;
        while (exp) {
            if (exp & 1)*this *= rhs;
            rhs *= rhs;
            exp >>= 1;
        }
        return *this;
    }
    template<typename T> ModInt operator+(const T& rhs)const { return ModInt(*this) += rhs; }
    template<typename T> ModInt& operator+=(const T& rhs) { return operator+=(ModInt(rhs)); }
    template<typename T> ModInt operator-(const T& rhs)const { return ModInt(*this) -= rhs; }
    template<typename T> ModInt& operator-=(const T& rhs) { return operator-=(ModInt(rhs)); }
    template<typename T> ModInt operator*(const T& rhs)const { return ModInt(*this) *= rhs; }
    template<typename T> ModInt& operator*=(const T& rhs) { return operator*=(ModInt(rhs)); }
    template<typename T> ModInt operator/(const T& rhs)const { return ModInt(*this) /= rhs; }
    template<typename T> ModInt& operator/=(const T& rhs) { return operator/=(ModInt(rhs)); }
};
std::istream& operator>>(std::istream& ist, ModInt& x) {
    lint a;
    ist >> a;
    x = a;
    return ist;
}