#include "../basic/template.hpp"
#include "../basic/type_traits.hpp"
#include "NumberTheoreticTransform.hpp"

template <class T, std::enable_if_t<is_ModInt_v<T>, std::nullptr_t> = nullptr>
class FormalPowerSeries : public std::vector<T> {
  private:
	using NTT = NumberTheoreticTransform;
	using FPS = FormalPowerSeries<T>;
	using std::vector<T>::vector;

  public:
	FormalPowerSeries(const std::vector<T>& vec) : std::vector<T>(vec) {}

	FPS operator-() const {
		FPS res(*this);
		for (T& i : res) i = -i;
		return res;
	}

	template <class U>
	FPS& operator+=(const U& v) {
		if (this->empty())
			this->emplace_back(v);
		else
			(*this)[0] += v;
		return *this;
	}
	template <class U>
	FPS operator+(const U& v) const {
		FPS res(*this);
		return res += v;
	}
	FPS operator+=(const FPS& f) {
		this->resize(std::max(this->size(), f.size()));
		rep(i, this->size())(*this)[i] += f[i];
		return *this;
	}
	FPS operator+(const FPS& f) const {
		FPS res(*this);
		return res += f;
	}

	template <class U>
	FPS& operator-=(const U& v) {
		if (this->empty())
			this->emplace_back(-v);
		else
			(*this)[0] -= v;
		return *this;
	}
	template <class U>
	FPS operator-(const U& v) const {
		FPS res(*this);
		return res -= v;
	}
	FPS operator-=(const FPS& f) {
		this->resize(std::max(this->size(), f.size()));
		rep(i, std::min(this->size(), f.size()))(*this)[i] -= f[i];
		return *this;
	}
	FPS operator-(const FPS& f) const {
		FPS res(*this);
		return res -= f;
	}

	template <class U>
	FPS& operator*=(const U& v) {
		for (T& i : *this) i *= v;
		return *this;
	}
	template <class U>
	FPS operator*(const U& v) const {
		FPS res(*this);
		return res *= v;
	}
	FPS operator*=(const FPS& f) {
		*this = NTT::convolution(*this, f);
		return *this;
	}
	FPS operator*(const FPS& f) const { return NTT::convolution(*this, f); }

	template <class U>
	FPS& operator/=(const U& v) {
		return *this *= T(v).inv();
	}
	template <class U>
	FPS operator/(const U& v) const {
		return *this * T(v).inv();
	}
	FPS operator/=(const FPS& f) {
		*this = *this * f.inv();
		return *this;
	}
	FPS operator/(const FPS& f) const { return *this * f.inv(); }

	void differentiate() {
		this->erase(this->begin());
		REP(i, this->size())(*this)[i - 1] *= i;
	}
	[[nodiscard]] FPS differential() {
		FPS res = *this;
		res.differentiate();
		return res;
	}

	void integrate() {
		this->insert(this->begin(), 0);
		REP(i, this->size() - 1)(*this)[i] /= i;
	}
	[[nodiscard]] FPS integral() {
		FPS res = *this;
		res.integrate();
		return res;
	}

	void invert() { invert(this->size()); }
	void invert(size_t len) { *this = FPS(len); }
	[[nodiscard]] FPS inv() const { return inv(this->size()); }
	[[nodiscard]] FPS inv(size_t len) const {
		FPS res;
		size_t n = 1;
		res.emplace_back((*this)[0].inv());
		while (n < len) {
			n <<= 1;
			FPS f(n), g(n);
			rep(i, std::min(this->size(), n)) f[i] = (*this)[i];
			rep(i, res.size()) g[i] = res[i];
			NTT::ntt(f, false, n);
			NTT::ntt(g, false, n);
			rep(i, n) f[i] *= g[i];
			NTT::ntt(f, true, n);
			T inv = T(n).inv();
			rep(i, n >> 1) f[i] = 0, f[i + (n >> 1)] *= inv;
			NTT::ntt(f, false, n);
			rep(i, n) f[i] *= g[i];
			NTT::ntt(f, true, n);
			rep(i, n >> 1) f[i + (n >> 1)] *= -inv;
			res.insert(res.end(), f.begin() + (n >> 1), f.begin() + n);
		}
		res.resize(len);
		return std::move(res);
	}

	[[nodiscard]] FPS log() { return log(this->size()); }
	[[nodiscard]] FPS log(size_t len) {
		FPS differentiated = differential();
		FPS tmp = differentiated / *this;
		tmp.resize(len - 1);
		return tmp.integral();
	}

	[[nodiscard]] FPS exp() { return exp(this->size()); }
	[[nodiscard]] FPS exp(size_t len) {
		FPS res(1, 1);
		size_t n = 1;
		while (n < len) {
			n <<= 1;
			auto tmp = *this + 1;
			tmp -= res.log(n);
			res *= tmp;
			res.resize(std::min(len, 2 * n));
		}
		return res;
	}

	[[nodiscard]] FPS pow(lint k) { return pow(k, this->size()); }
	[[nodiscard]] FPS pow(lint k, size_t len) {
		rep(i, len) {
			if (i && (len < k || len < k * i)) break;
			if ((*this)[i]) {
				FPS res = FPS(this->begin() + i, this->end()) / (*this)[i];
				res = (res.log() * k).exp();
				res.resize(len);
				T c = (*this)[i].pow(k);
				for (int j = len - 1; j >= 0; j--) {
					if (i && (j < k || j < k * i))
						res[j] = 0;
					else
						res[j] = res[j - i * k] * c;
				}
				return res;
			}
		}
		FPS res(len);
		if (!k) res[0] = 1;
		return res;
	}
};