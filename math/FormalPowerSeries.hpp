#include "../other/template.hpp"
#include "../other/type_traits.hpp"
#include "NumberTheoreticTransform.hpp"

template <class T, std::enable_if_t<is_ModInt_v<T>, std::nullptr_t> = nullptr>
class FormalPowerSeries {
  private:
	std::vector<T> vec;

	using NTT = NumberTheoreticTransform;
	using FPS = FormalPowerSeries<T>;

  public:
	template <class... Args>
	FormalPowerSeries(Args&&... args) : vec(std::forward<Args>(args)...) {}

	operator std::vector<T>() { return vec; }
	operator std::vector<T>() const { return vec; }
	size_t size() const noexcept { return vec.size(); }

	FPS operator-() const {
		FPS res(*this);
		for (T& i : res.vec) i = -i;
		return res;
	}

	template <class U>
	FPS& operator+=(const U& v) {
		if (vec.empty())
			vec.emplace_back(v);
		else
			vec[0] += v;
		return *this;
	}
	template <class U>
	FPS operator+(const U& v) const {
		FPS res(*this);
		return res += v;
	}
	FPS operator+=(const FPS& f) {
		vec.resize(std::max(size(), f.size()));
		rep(i, vec.size()) vec[i] += f.vec[i];
		return *this;
	}
	FPS operator+(const FPS& f) const {
		FPS res(*this);
		return res += f;
	}

	template <class U>
	FPS& operator-=(const U& v) {
		if (vec.empty())
			vec.emplace_bcak(-v);
		else
			vec[0] -= v;
		return *this;
	}
	template <class U>
	FPS operator-(const U& v) const {
		FPS res(*this);
		return res -= v;
	}
	FPS operator-=(const FPS& f) {
		vec.resize(std::max(size(), f.size()));
		rep(i, std::min(size(), f.size())) vec[i] -= f.vec[i];
		return *this;
	}
	FPS operator-(const FPS& f) const {
		FPS res(*this);
		return res -= f;
	}

	template <class U>
	FPS& operator*=(const U& v) {
		for (const T& i : vec) i *= v;
		return *this;
	}
	template <class U>
	FPS operator*(const U& v) {
		FPS res(*this);
		return res *= v;
	}
	FPS operator*=(const FPS& f) {
		vec = NTT::convolution(vec, f.vec);
		return *this;
	}
	FPS operator*(const FPS& f) {
		FPS res(*this);
		return res *= f;
	}

	template <class U>
	FPS& operator/=(const U& v) {
		for (const T& i : vec) i /= v;
		return *this;
	}
	template <class U>
	FPS operator/(const U& v) {
		FPS res(*this);
		return res /= v;
	}
	FPS operator/=(const FPS& f) {
		vec = NTT::convolution(vec, f.inverse().vec);
		return *this;
	}
	FPS operator/(const FPS& f) {
		FPS res(*this);
		return res /= f;
	}

	template <class U>

	[[nodiscard]] size_t size() const {
		return vec.size();
	}
	void resize(size_t n) { vec.resize(n); }

	void differentiate() {
		vec.erase(vec.begin());
		REP(i, vec.size()) vec[i - 1] *= i;
	}
	[[nodiscard]] FPS differential() {
		FPS res = *this;
		res.differentiate();
		return res;
	}

	void integrate() {
		vec.insert(vec.begin(), 0);
		REP(i, vec.size() - 1) vec[i] /= i;
	}
	[[nodiscard]] FPS integral() {
		FPS res = *this;
		res.integrate();
		return res;
	}

	void invert() { invert(vec.size()); }
	void invert(size_t len) { *this = FPS(len); }
	[[nodiscard]] FPS inverse() const { return inverse(vec.size()); }
	[[nodiscard]] FPS inverse(size_t len) const {
		std::vector<T> res;
		size_t n = 1;
		res.emplace_back(T(1) / vec[0]);
		std::vector<T> vec_shortened = {vec[0]};
		vec_shortened.reserve(len);
		while (n < len) {
			n <<= 1;
			vec_shortened.insert(vec_shortened.end(),
								 vec.begin() + vec_shortened.size(),
								 vec.begin() + std::min(vec.size(), n));
			auto tmp = NTT::convolution(res, vec_shortened);
			tmp.resize(std::min(n, len));
			for (T& i : tmp) i = -i;
			tmp[0] += 2;
			res = NTT::convolution(res, tmp);
			res.resize(std::min(n, len));
		}
		return FPS(std::move(res));
	}

	[[nodiscard]] FPS log() { return log(size()); }
	[[nodiscard]] FPS log(size_t len) {
		FPS differentiated = differential();
		FPS tmp = differentiated / *this;
		tmp.resize(len - 1);
		return tmp.integral();
	}

	[[nodiscard]] FPS exp() { return exp(size()); }
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

	template <class U>
	friend std::ostream& operator<<(std::ostream&, const FormalPowerSeries<U>&);
};

template <class T>
std::ostream& operator<<(std::ostream& ost, const FormalPowerSeries<T>& fps) {
	ost << fps.vec;
	return ost;
}