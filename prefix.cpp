<snippet>
	<content><![CDATA[

//prefix suffix precomputation ,initalise size of pre,suf
auto calc = [&](auto & main, auto & p, auto & s) {
	for (int _ = 0; _ < 2; _++) {
		int n = main.size();
		vi &pre = (_ == 0) ? p : s;
		for (int i = 0; i < n; i++) {
			pre[i] = (i == 0) ? main[i] : main[i] + pre[i - 1];
		}
		reverse(all(main));
		reverse(all(suf));//and all suffix arrays
	}
};

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>prefix</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
