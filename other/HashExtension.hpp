template <class P1, class P2>
class std::hash<std::pair<P1, P2>> {
  public:
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const {
		auto hash1 = std::hash<T1>{}(p.first);

		auto hash2 = std::hash<T2>{}(p.second);

		size_t seed = 0;
		seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
		return seed;
	}
};