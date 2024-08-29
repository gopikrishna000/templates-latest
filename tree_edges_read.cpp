<snippet>
	<content><![CDATA[

	adj.assign(n,vi());
	for (int i = 0; i < n-1; i++) {
		int u,v;
		cin>>u>>v;
		u--;v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>tree edges read</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
