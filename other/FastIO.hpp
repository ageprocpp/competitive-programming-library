#pragma once
#include "template.hpp"
namespace FastIO {
	static constexpr size_t buf_size = 1 << 18;
	static constexpr size_t integer_size = 19;

	static char inbuf[buf_size + 1] = {};
	static char outbuf[buf_size + 1] = {};

	class Scanner {
		size_t pos = 0, end = buf_size;
		void load() {
			end = fread(inbuf, 1, buf_size, stdin);
			inbuf[end] = '\0';
		}
		void ignore_space() {
			while (inbuf[pos] <= ' ') {
				if (__builtin_expect(++pos == end, 0)) reload();
			}
		}
		char next() { return inbuf[pos++]; }
		char next_nonspace() {
			ignore_space();
			return inbuf[pos++];
		}

	  public:
		Scanner() { load(); }
		void reload() {
			size_t length = end - pos;
			memmove(inbuf, inbuf + pos, length);
			end = length + fread(inbuf + length, 1, buf_size - length, stdin);
			inbuf[end] = '\0';
			pos = 0;
		}
		void scan() {}
		void scan(char& c) { c = next_nonspace(); }
		void scan(std::string& s) {
			ignore_space();
			s = "";
			do {
				size_t start = pos;
				while (inbuf[pos] > ' ') pos++;
				s += std::string(inbuf + start, inbuf + pos);
				if (inbuf[pos] != '\0') break;
				reload();
			} while (true);
		}
		template <typename T,
				  std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
		void scan(T& x) {
			char c = next_nonspace();
			if (__builtin_expect(pos + integer_size >= end, 0)) reload();
			bool minus = false;
			if (c == '-')
				minus = true, x = 0;
			else
				x = c & 15;
			while ((c = next()) >= '0') x = x * 10 + (c & 15);
			if (minus) x = -x;
		}
		template <typename T, class... Args>
		void scan(T& x, Args&... args) {
			scan(x);
			scan(args...);
		}
		template <typename T>
		Scanner& operator>>(T& x) {
			scan(x);
			return *this;
		}
	};

	class Printer {
		static constexpr size_t block_size = 10000;
		static const std::unique_ptr<char[]> block_str;
		size_t pos = 0;

		static constexpr lint powers[] = {1,
										  10,
										  100,
										  1000,
										  10000,
										  100000,
										  1000000,
										  10000000,
										  100000000,
										  1000000000,
										  10000000000,
										  100000000000,
										  1000000000000,
										  10000000000000,
										  100000000000000,
										  1000000000000000,
										  10000000000000000,
										  100000000000000000,
										  1000000000000000000};

		static std::unique_ptr<char[]> precompute() {
			std::unique_ptr<char[]> res(new char[block_size * 4]);
			rep(i, block_size) {
				size_t j = 4, k = i;
				while (j--) {
					res[i * 4 + j] = k % 10 + '0';
					k /= 10;
				}
			}
			return res;
		}
		template <typename T>
		size_t integer_digits(T n) {
			if (n >= powers[9]) {
				if (n >= powers[13]) {
					if (n >= powers[16]) {
						if (n >= powers[17]) {
							if (n >= powers[18]) return 19;
							return 18;
						}
						return 17;
					}
					if (n >= powers[14]) {
						if (n >= powers[15]) return 16;
						return 15;
					}
					return 14;
				}
				if (n >= powers[11]) {
					if (n >= powers[12]) return 13;
					return 12;
				}
				if (n >= powers[10]) return 11;
				return 10;
			}
			if (n >= powers[4]) {
				if (n >= powers[7]) {
					if (n >= powers[8]) return 9;
					return 8;
				}
				if (n >= powers[5]) {
					if (n >= powers[6]) return 7;
					return 6;
				}
				return 5;
			}
			if (n >= powers[2]) {
				if (n >= powers[3]) return 4;
				return 3;
			}
			if (n >= powers[1]) return 2;
			return 1;
		}

	  public:
		Printer() = default;
		~Printer() { flush(); }
		void flush() {
			fwrite(outbuf, 1, pos, stdout);
			pos = 0;
		}
		void print() {}
		void print(char c) {
			outbuf[pos++] = c;
			if (__builtin_expect(pos == buf_size, 0)) flush();
		}
		void print(char* s) {
			while (*s != 0) {
				outbuf[pos++] = *s++;
				if (pos == buf_size) flush();
			}
		}
		template <typename T,
				  std::enable_if_t<std::is_integral<T>::value, std::nullptr_t> = nullptr>
		void print(T x) {
			if (__builtin_expect(pos + integer_size >= buf_size, 0)) flush();
			if (x < 0) print('-'), x = -x;
			size_t digit = integer_digits(x);
			size_t len = digit;
			while (len >= 4) {
				len -= 4;
				memcpy(outbuf + pos + len, block_str.get() + (x % block_size) * 4, 4);
				x /= 10000;
			}
			memcpy(outbuf + pos, block_str.get() + x * 4 + 4 - len, len);
			pos += digit;
		}
		void print(const std::string& x) {
			for (char c : x) {
				outbuf[pos++] = c;
				if (pos == buf_size) flush();
			}
		}
		template <typename T, class... Args>
		void print(const T& x, const Args&... args) {
			print(x);
			print(' ');
			print(args...);
		}
		template <class... Args>
		void println(const Args&... args) {
			print(args...);
			print('\n');
		}
		template <typename T>
		Printer& operator<<(const T& x) {
			print(x);
			return *this;
		}
	};
	const std::unique_ptr<char[]> Printer::block_str = Printer::precompute();
};	// namespace FastIO

/**
 * @title Fast IO library
 */