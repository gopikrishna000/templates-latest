<snippet>
	<content><![CDATA[


typedef unsigned long long ull;

int gen_base(int before, int after) {
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 gen(seed ^ ull(new ull));
	std::uniform_int_distribution<int> dist(before + 2, after - 1);
	int base = dist(gen);
	return base % 2 == 0 ? base - 1 : base;
}

struct PolyHash {
	// -------- Static variables --------
	static const ull mod = (ull(1) << 61) - 1; // prime mod of hashing
	//mod = 6735249118018991;
	static int base;                           // odd base of hashing
	static std::vector<ull> pow;               // powers of base modulo mod;

	// -------- Static functions --------
	static inline ull add(ull a, ull b) {
		// Calculate (a + b) % mod, 0 <= a < mod, 0 <= b < mod
		return (a += b) < mod ? a : a - mod;
	}

	static inline ull sub(ull a, ull b) {
		// Calculate (a - b) % mod, 0 <= a < mod, 0 <= b < mod
		return (a -= b) < mod ? a : a + mod;
	}

	static inline ull mul(ull a, ull b) {
		// Calculate (a * b) % mod, 0 <= a < mod, 0 <= b < mod
		ull l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
		ull l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
		ull ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
		ret = (ret & mod) + (ret >> 61);
		ret = (ret & mod) + (ret >> 61);
		return ret - 1;
		// __int128_t res = a; // for other primes(or composite?)
		// res *= b;
		// res %= mod;
		// return (ull)res;
	}

	// -------- Variables of class --------
	std::vector<ull> pref; // polynomial hash on prefix

	// Constructor from string:
	PolyHash(const auto& s)
		: pref(s.size() + 1u, 0)
	{
		// Pre-calculate powers of base:
		while (pow.size() <= s.size()) {
			pow.push_back(mul(pow.back(), base));
		}
		// Calculate polinomial hash on prefix:
		for (int i = 0; i < (int)s.size(); ++i) {
			pref[i + 1] = add(mul(pref[i], base), s[i]);
		}
	}

	// Get hash from [pos, pos+len-1] segment of string
	inline ull operator()(const int pos, const int len) const {
		return sub(pref[pos + len], mul(pref[pos], pow[len]));
	}

};

// Init static variables of class PolyHash:
int PolyHash::base((int)1e9 + 7);
std::vector<ull> PolyHash::pow{1};

// note: pref[1..i] = s[0]*b^i....+s[i-2]b^2+s[i-1]*b+s[i]
// {cause, no need of division, so mod can be composite, but mod should 1<<61-1 for mul to work}
// pref[1..i+1] = pref[i]*b+s[i+1]
// PolyHash::base = gen_base(256, 2e9);
// PolyHash hash_s(s), hash_t(t);

/*
* donot forget to use ull for storing hash value
* always use PolyHash::add(a,b),PolyHash::mul(a,b), so on... especially for mul, cause
any hash value <= 2^61, so if you just multiply by 1e5, still overflow..
[[ But becareful, for any of those function, it must hold for paramter that is passed that,
0 <= a < mod, 0 <= b < mod .... Eg: so, dont pass sub(mod,a) for a = -a, rather call a=sub(0,a)]]
* becareful about hash of negative values or coefficients, since we use here only ull.
*/

//large primes https://t5k.org/curios/index.php?start=11&stop=16
// 6735249118018991

//ref: https://ideone.com/ACmWDq
//ref: https://codeforces.com/blog/entry/60445

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>polynomial rolling string hash one mod</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>

