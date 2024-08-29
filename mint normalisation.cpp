<snippet>
	<content><![CDATA[


long long &P = mod;
using i64 = long long;
// assume -P <= x < 2P
i64 narm(i64 x) {
	if (-P <= x && x < (P << 1ll)) {
		if (x < 0) {
			x += P;
		}
		if (x >= P) {
			x -= P;
		}
		return x;
	}

	if (x < 0) {
		x += ((-x + P - 1) / P) * P;
	}
	return x % P;
}
template<class T>
T power(T a, i64 b) {
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b % 2) {
			res *= a;
		}
	}
	return res;
}
struct mint {
	i64 x;
	mint(int32_t x = 0) : x(narm(x)) {}
	mint(i64 x) : x(narm(x)) {}
	// template<typename T>
	// operator T() const {
	// 	return x;
	// }
	i64 val() const {
		return x;
	}
	mint operator-() const {
		return mint(narm(P - x));
	}
	mint pow(i64 m) {
		return power(*this, m);
	}
	mint inv() const {
		assert(x != 0);
		return power(*this, P - 2);
	}
	mint &operator*=(const mint &rhs) {
		x = i64(x) * rhs.x % P;
		return *this;
	}
	mint &operator+=(const mint &rhs) {
		x = narm(x + rhs.x);
		return *this;
	}
	mint &operator-=(const mint &rhs) {
		x = narm(x - rhs.x);
		return *this;
	}
	mint &operator/=(const mint &rhs) {
		return *this *= rhs.inv();
	}
	friend mint operator*(const mint &lhs, const mint &rhs) {
		mint res = lhs;
		res *= rhs;
		return res;
	}
	friend mint operator+(const mint &lhs, const mint &rhs) {
		mint res = lhs;
		res += rhs;
		return res;
	}
	friend mint operator-(const mint &lhs, const mint &rhs) {
		mint res = lhs;
		res -= rhs;
		return res;
	}
	friend mint operator/(const mint &lhs, const mint &rhs) {
		mint res = lhs;
		res /= rhs;
		return res;
	}
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	mint operator++(int32_t) { mint temp; temp.x = x++; return temp; }
	mint operator--(int32_t) { mint temp; temp.x = x--; return temp; }

	friend std::istream &operator>>(std::istream &is, mint &a) {
		i64 v;
		is >> v;
		a = mint(v);
		return is;
	}
	friend std::ostream &operator<<(std::ostream &os, const mint &a) {
		return os << a.val();
	}
};
#define mi mint
#define i32 int32_t
#define i64 long long

void __print(mint y) {cerr << (y).x;}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>mint modular</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
