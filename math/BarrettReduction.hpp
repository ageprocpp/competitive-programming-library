#include "../basic/template.hpp"
class BarrettReduction {
	uint m;
	ulint im;

  public:
	constexpr explicit BarrettReduction(uint m_) : m(m_), im(ulint(-1) / m_ + 1) {}
	constexpr uint mul(uint a, uint b) {
		ulint z = ulint(a) * b;
		ulint x = ulint((u128(z) * im) >> 64);
		ulint y = x * m;
		return uint(z - y + (z < y ? m : 0));
	}
};