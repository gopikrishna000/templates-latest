<snippet>
	<content><![CDATA[


//cycled finding in floyd grapg [hanging tree like structure]
		vi brr(n), vis(n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				int j = i;
				int c = 0;
				si s;
				while (!vis[j]) {
					s.insert(j);
					vis[j] = 1;
					brr[j] = c;
					j = arr[j];
					c++;
				}
				wd(c, j, brr[j], i);
				if (s.find(j) != s.end())
					ans += c - brr[j];

			}
		}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>floyd cycles hanging</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
