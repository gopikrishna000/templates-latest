<snippet>
	<content><![CDATA[

//cycle finding in even degree directed graph
int cnt = 0;
for (int i = 0; i < n; i++) {
	if (adj[i].size() == 0)continue;
	int j = i;
	j = adj[i].back();
	adj[i].pop_back();
	int c = 1; // length of cycle
	while (j != i) {
		int pj = j;
		j = adj[j].back();
		adj[pj].pop_back();
		c++;
	}
	cnt += c;
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>permutation group cycle</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
