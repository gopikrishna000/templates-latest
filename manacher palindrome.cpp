<snippet>
	<content><![CDATA[


vector<int> manacher_odd(string s) {
	int n = s.size();
	s = "$" + s + "^";
	vector<int> p(n + 2);
	int l = 1, r = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = max(0, min(r - i, p[l + (r - i)]));
		while (s[i - p[i]] == s[i + p[i]]) {
			p[i]++;
		}
		if (i + p[i] > r) {
			l = i - p[i], r = i + p[i];
		}
	}
	return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
	string t;
	for (auto c : s) {
		t += string("#") + c;
	}
	auto res = manacher_odd(t + "#");
	return vector<int>(begin(res) + 1, end(res) - 1);
}

/*
aabababa => #a#a#b#a#b#a#b#a# (ignoring 1st & lst # for res)
[res] = [{2,3,2,1,4,1,6,1,8,1,6,1,4,1,2}]
res[i] = longest pal length centered i (only ceil half len).

Actual conversion: (0-based access of res)
Odd: (res[i*2]/2 - 1)*2+1 : "len of longest pal centered i";
Even: (res[i*2+1]/2)*2 : "len of longest pal centered i,i+1"
*/

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>manacher palindrome</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
