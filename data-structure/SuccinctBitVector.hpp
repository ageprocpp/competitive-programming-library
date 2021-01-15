#pragma once
#include "../other/template.hpp"
class SuccinctBitVector {
	std::vector<bool> v;
	using u8 = uint_least8_t;
	using u16 = uint_least16_t;
	using u32 = uint_least32_t;

	constexpr static u8 chunk_bit = 10;
	constexpr static u8 blocks_bit = 4;
	constexpr static u16 chunk_size = 1 << chunk_bit;  // log ^ 2 N bit
	constexpr static u8 block_size = 1 << blocks_bit;  // log N / 2 bit
	constexpr static u8 blocks_in_chunk = 1 << (chunk_bit - blocks_bit);

	size_t N;							 // MAX 2 ^ 32
	std::vector<u32> chunks;			 // log N: 32
	std::vector<u16> blocks, block_num;	 // 2 log log N: 10

  public:
	SuccinctBitVector() = default;
	SuccinctBitVector(const std::vector<bool>& vec) { init(vec); }
	void init(const std::vector<bool>& vec) {
		N = vec.size();
		chunks.resize((N + chunk_size - 1) >> chunk_bit, 0);
		blocks.resize((N + block_size - 1) >> blocks_bit, 0);
		block_num.resize((N + block_size - 1) >> blocks_bit, 0);
		rep(i, N) {
			if (vec[i]) {
				chunks[i >> chunk_bit]++;
				blocks[i >> blocks_bit]++;
				block_num[i >> blocks_bit] |= 1 << (i & (block_size - 1));
			}
		}
		rep(i, chunks.size() - 1) chunks[i + 1] += chunks[i];
		rep(i, blocks.size() - 1) {
			if ((i & (blocks_in_chunk - 1)) != blocks_in_chunk - 1)
				blocks[i + 1] += blocks[i];
		}
		v = vec;
	}
	int rank(bool b, int x) const {
		int res = 0;
		res += x >= chunk_size ? chunks[(x >> chunk_bit) - 1] : 0;
		res += (x & (chunk_size - 1)) >= block_size
				   ? blocks[(x >> blocks_bit) - 1]
				   : 0;
		res += __builtin_popcount(block_num[x >> blocks_bit] &
						((1 << ((x & (block_size - 1)) + 1)) - 1));
		return b ? res : x + 1 - res;
	}
	size_t size() const { return N; }
};

/**
 * @title Succinct Bit Vector
 */