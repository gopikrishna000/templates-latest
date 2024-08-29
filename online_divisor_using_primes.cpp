<snippet>
	<content><![CDATA[


#define N 1e6 + 1
vector<int> prime;
vector<vi> divisors(N+1); //memoization

void prime_sieve() {
	int sq = sqrt(N);
	vector<bool> B(sq + 1, 0);
	for (int i = 2; i <= sq; i++) {
		if (!B[i]) {
			prime.pb(i);
			for (int j = i * 2; j <= sq; j += i) {
				B[j] = 1;
			}
		}
	}
}

//generate prime divisors O(#p<sqrt(n) + logn)
vector<pair<int, int>> prime_divisors(int n) {
	vector<pair<int, int>> f; //factorization
	if (n == 1) {
		f.pb({1, 1});
		return f;
	}
	for (auto &p : prime) {
		int c = 0;
		bool ok = 0;
		while (n % p == 0) {
			c++;
			ok = 1;
			n /= p;
		}
		if (ok)
			f.pb({p, c});
	}
	if (n != 1)
		f.pb({n, 1});
	return f;
}

void gendiv(vector<pair<int, int>> &f, int ppos, vector<int> &div, int sofar) {
	if (ppos == f.size()) {
		div.pb(sofar);
		return;
	}
	int pexp = 1;
	for (int i = 0; i <= f[ppos].second; i++) {
		gendiv(f, ppos + 1, div, sofar * pexp);
		pexp *= f[ppos].first;
	}
}


//generate divisors //not in sorted order
vector<int> generate_divisors(int n) {
	vector<int> div;
	vector<pair<int, int>> f = prime_divisors(n);
	gendiv(f, 0, div, 1);
	return div;
}



]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>online divisors generator using prime factorisation</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
