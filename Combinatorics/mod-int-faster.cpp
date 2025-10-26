struct Mint {
	int val;

	Mint(long long v = 0) {
		if (v < 0) v = v %  + mod;
		if (v >= mod) v %= mod;
		val = v;
	}

	static int mod_inv(int a, int m = mod) {
		int g = m, r = a, x = 0, y = 1;
		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}
		return x < 0 ? x + m : x;
	}
	explicit operator int() const { return val; }
	Mint& operator+=(const Mint &other) { val += other.val; if (val >= mod) val -= mod; return *this; }
	Mint& operator-=(const Mint &other) { val -= other.val; if (val < 0) val += mod; return *this; }
	static unsigned fast_mod(uint64_t x, unsigned m = mod) {
#if !defined(_WIN32) || defined(_WIN64)
		return x % m;
#endif
		unsigned x_high = x >> 32, x_low = (unsigned) x;
		unsigned quot, rem;
		asm("divl %4\n"
		    : "=a" (quot), "=d" (rem)
		    : "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}
	Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val); return *this; }
	Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
	friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
	friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
	friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
	friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
	Mint& operator++() { val = val == mod - 1 ? 0 : val + 1; return *this; }
	Mint& operator--() { val = val == 0 ? mod - 1 : val - 1; return *this; }
	// friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <= (int)b; }
	Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
	Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
	Mint operator-() const { return val == 0 ? 0 : mod - val; }
	bool operator==(const Mint &other) const { return val == other.val; }
	bool operator!=(const Mint &other) const { return val != other.val; }
	Mint inv() const { return mod_inv(val); }
	Mint power(long long p) const {
		assert(p >= 0);
		Mint a = *this, result = 1;
		while (p > 0) {
			if (p & 1) result *= a;
			a *= a, p >>= 1;
		}
		return result;
	}
	friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
	friend istream& operator >> (istream &stream, Mint &m) { return stream >> m.val;   }
};
