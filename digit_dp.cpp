<snippet>
	<content><![CDATA[


#define ll long long
// int mem[20][2] // last dim not need, as [0] will be called O(20) times only
//also its value will be diff and recalculated for different input
int mem[20];
vector<int> v;
// lo = 0 => [<=given number]
// lo = 1 => [all possible digit]
int dp(int pos, bool lo) {

	if (pos == -1) return 1;

	int &res = mem[pos];
	if (lo && res != -1) return res;

	int ans = 0;
	int mx = lo ? 9 : v[pos];
	// wd(pos, lo, mx, islead, b[3]);

	for (int d = 0; d <= mx; d++) {		
		ans += dp(pos - 1, lo || (d < mx));
	}
	return lo ? res = ans : ans; //no need to memoize for lo = 0;
}



int solve(int x, int k) {

	v.clear();
	while (x) {
		v.push_back(x % 10);
		x /= 10;
	}

	return dp(v.size() - 1, 0);
}


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>digit dp</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
