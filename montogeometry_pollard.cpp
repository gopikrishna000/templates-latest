<snippet>
	<content><![CDATA[



// https://judge.yosupo.jp/submission/23126
namespace inner {

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

template <typename T> T gcd(T a, T b) {
	while (b) swap(a %= b, b);
	return a;
}

uint64_t gcd_impl(uint64_t n, uint64_t m) {
	constexpr uint64_t K = 5;
	for (int i = 0; i < 80; ++i) {
		uint64_t t = n - m;
		uint64_t s = n - m * K;
		bool q = t < m;
		bool p = t < m * K;
		n = q ? m : t;
		m = q ? t : m;
		if (m == 0) return n;
		n = p ? n : s;
	}
	return gcd_impl(m, n % m);
}

uint64_t gcd_pre(uint64_t n, uint64_t m) {
	for (int i = 0; i < 4; ++i) {
		uint64_t t = n - m;
		bool q = t < m;
		n = q ? m : t;
		m = q ? t : m;
		if (m == 0) return n;
	}
	return gcd_impl(n, m);
}

uint64_t gcd_fast(uint64_t n, uint64_t m) { return n > m ? gcd_pre(n, m) : gcd_pre(m, n); }

template <typename T = int32_t> T inv(T a, T p) {
	T b = p, x = 1, y = 0;
	while (a) {
		T q = b % a;
		swap(a, b /= a);
		swap(x, y -= q * x);
	}
	assert(b == 1);
	return y < 0 ? y + p : y;
}

template <typename T = int32_t, typename U = int64_t> T modpow(T a, U n, T p) {
	T ret = 1;
	for (; n; n >>= 1, a = U(a) * a % p)
		if (n & 1) ret = U(ret) * a % p;
	return ret;
}

} // namespace inner

using namespace std;

unsigned long long mrng() {
	static unsigned long long x_ = 88172645463325252ULL;
	x_ = x_ ^ (x_ << 7);
	return x_ = x_ ^ (x_ >> 9);
}
using namespace std;


struct ArbitraryLazyMontgomeryModInt {
	using mint = ArbitraryLazyMontgomeryModInt;
	using i32 = int32_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	static u32 mod;
	static u32 r;
	static u32 n2;

	static u32 get_r() {
		u32 ret = mod;
		for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
		return ret;
	}

	static void set_mod(u32 m) {
		assert(m < (1 << 30));
		assert((m & 1) == 1);
		mod = m;
		n2 = -u64(m) % m;
		r = get_r();
		assert(r * mod == 1);
	}

	u32 a;

	ArbitraryLazyMontgomeryModInt() : a(0) {}
	ArbitraryLazyMontgomeryModInt(const int64_t &b) : a(reduce(u64(b % mod + mod) * n2)) {};

	static u32 reduce(const u64 &b) { return (b + u64(u32(b) * u32(-r)) * mod) >> 32; }

	mint &operator+=(const mint &b) {
		if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
		return *this;
	}

	mint &operator-=(const mint &b) {
		if (i32(a -= b.a) < 0) a += 2 * mod;
		return *this;
	}

	mint &operator*=(const mint &b) {
		a = reduce(u64(a) * b.a);
		return *this;
	}

	mint &operator/=(const mint &b) {
		*this *= b.inverse();
		return *this;
	}

	mint operator+(const mint &b) const { return mint(*this) += b; }
	mint operator-(const mint &b) const { return mint(*this) -= b; }
	mint operator*(const mint &b) const { return mint(*this) *= b; }
	mint operator/(const mint &b) const { return mint(*this) /= b; }
	bool operator==(const mint &b) const { return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a); }
	bool operator!=(const mint &b) const { return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a); }
	mint operator-() const { return mint() - mint(*this); }

	mint pow(u64 n) const {
		mint ret(1), mul(*this);
		while (n > 0) {
			if (n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	friend ostream &operator<<(ostream &os, const mint &b) { return os << b.get(); }

	friend istream &operator>>(istream &is, mint &b) {
		int64_t t;
		is >> t;
		b = ArbitraryLazyMontgomeryModInt(t);
		return (is);
	}

	mint inverse() const { return pow(mod - 2); }

	u32 get() const {
		u32 ret = reduce(a);
		return ret >= mod ? ret - mod : ret;
	}

	static u32 get_mod() { return mod; }
};
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::mod;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::r;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::n2;

using namespace std;


struct montgomery64 {
	using mint = montgomery64;
	using i64 = int64_t;
	using u64 = uint64_t;
	using u128 = __uint128_t;

	static u64 mod;
	static u64 r;
	static u64 n2;

	static u64 get_r() {
		u64 ret = mod;
		for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;
		return ret;
	}

	static void set_mod(u64 m) {
		assert(m < (1LL << 62));
		assert((m & 1) == 1);
		mod = m;
		n2 = -u128(m) % m;
		r = get_r();
		assert(r * mod == 1);
	}

	u64 a;

	montgomery64() : a(0) {}
	montgomery64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)) {};

	static u64 reduce(const u128 &b) { return (b + u128(u64(b) * u64(-r)) * mod) >> 64; }

	mint &operator+=(const mint &b) {
		if (i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
		return *this;
	}

	mint &operator-=(const mint &b) {
		if (i64(a -= b.a) < 0) a += 2 * mod;
		return *this;
	}

	mint &operator*=(const mint &b) {
		a = reduce(u128(a) * b.a);
		return *this;
	}

	mint &operator/=(const mint &b) {
		*this *= b.inverse();
		return *this;
	}

	mint operator+(const mint &b) const { return mint(*this) += b; }
	mint operator-(const mint &b) const { return mint(*this) -= b; }
	mint operator*(const mint &b) const { return mint(*this) *= b; }
	mint operator/(const mint &b) const { return mint(*this) /= b; }
	bool operator==(const mint &b) const { return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a); }
	bool operator!=(const mint &b) const { return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a); }
	mint operator-() const { return mint() - mint(*this); }

	mint pow(u128 n) const {
		mint ret(1), mul(*this);
		while (n > 0) {
			if (n & 1) ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	friend ostream &operator<<(ostream &os, const mint &b) { return os << b.get(); }

	friend istream &operator>>(istream &is, mint &b) {
		int64_t t;
		is >> t;
		b = montgomery64(t);
		return (is);
	}

	mint inverse() const { return pow(mod - 2); }

	u64 get() const {
		u64 ret = reduce(a);
		return ret >= mod ? ret - mod : ret;
	}

	static u64 get_mod() { return mod; }
};
typename montgomery64::u64 montgomery64::mod, montgomery64::r, montgomery64::n2;

namespace fast_factorize {
using u64 = uint64_t;

template <typename mint> bool miller_rabin(u64 n, vector<u64> as) {
	if (mint::get_mod() != n) mint::set_mod(n);
	u64 d = n - 1;
	while (~d & 1) d >>= 1;
	mint e{1}, rev{int64_t(n - 1)};
	for (u64 a : as) {
		if (n <= a) break;
		u64 t = d;
		mint y = mint(a).pow(t);
		while (t != n - 1 && y != e && y != rev) {
			y *= y;
			t *= 2;
		}
		if (y != rev && t % 2 == 0) return false;
	}
	return true;
}

bool is_prime(u64 n) {
	if (~n & 1) return n == 2;
	if (n <= 1) return false;
	if (n < (1LL << 30))
		return miller_rabin<ArbitraryLazyMontgomeryModInt>(n, {2, 7, 61});
	else
		return miller_rabin<montgomery64>(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

template <typename mint, typename T> T pollard_rho(T n) {
	if (~n & 1) return 2;
	if (is_prime(n)) return n;
	if (mint::get_mod() != n) mint::set_mod(n);
	mint R, one = 1;
	auto f = [&](mint x) { return x * x + R; };
	auto rnd = [&]() { return mrng() % (n - 2) + 2; };
	while (1) {
		mint x, y, ys, q = one;
		R = rnd(), y = rnd();
		T g = 1;
		constexpr int m = 128;
		for (int r = 1; g == 1; r <<= 1) {
			x = y;
			for (int i = 0; i < r; ++i) y = f(y);
			for (int k = 0; g == 1 && k < r; k += m) {
				ys = y;
				for (int i = 0; i < m && i < r - k; ++i) q *= x - (y = f(y));
				g = inner::gcd_fast(q.get(), n);
			}
		}
		if (g == n) do
				g = inner::gcd_fast((x - (ys = f(ys))).get(), n);
			while (g == 1);
		if (g != n) return g;
	}
	exit(1);
}

vector<u64> inner_factorize(u64 n) {
	if (n <= 1) return {};
	u64 p;
	if (n <= (1LL << 30))
		p = pollard_rho<ArbitraryLazyMontgomeryModInt>(n);
	else
		p = pollard_rho<montgomery64>(n);
	if (p == n) return {p};
	auto l = inner_factorize(p);
	auto r = inner_factorize(n / p);
	copy(begin(r), end(r), back_inserter(l));
	return l;
}

vector<u64> factorize(u64 n) {
	auto ret = inner_factorize(n);
	sort(begin(ret), end(ret));
	return ret;
}

} // namespace fast_factorize
using fast_factorize::factorize;
using fast_factorize::is_prime;

using u64 = uint64_t;
vector<pair<long long, long long>> factorize_prime(long long n) {
	vector<u64> res = factorize(n);
	vector<pair<long long, long long>> ret;
	for (int i = 0; i < res.size(); i++) {
		if (i == 0 || res[i] != res[i - 1]) ret.push_back({res[i], 1});
		else ret[ret.size() - 1].second++;
	}
	return ret;
}
vector<long long> divisor(long long n) {
	vector<pair<long long, long long>> v = factorize_prime(n);
	vector<long long> ret;
	auto f = [&](auto rc, int i, long long x)->void{
		if (i == (int)v.size()) {
			ret.push_back(x);
			return;
		}
		for (int j = 0; j <= v[i].second; j++) {
			rc(rc, i + 1, x);
			x *= v[i].first;
		}
	};
	f(f, 0, 1);
	sort(ret.begin(), ret.end());
	return ret;
}



]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>montogeometry pollard rho</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
