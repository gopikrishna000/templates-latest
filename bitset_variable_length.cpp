<snippet>
	<content><![CDATA[

const int MAXLEN = 1e9+7;
template <int len = 1>
void solve(int n) {
	if (n > len) {
		solve<std::min(len * 2, MAXLEN)>(n);
		return;
	}
	// solution using bitset<len>
	bitset<len> s;
	cout << s.size();
}

variable n;
solve(n);

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>variable size bitset</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
