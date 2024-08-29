<snippet>
	<content><![CDATA[

vector<vector<int>> adj;
void dfs(int root, int par) {
	for (auto &x : adj[root]) {
		if (x != par) {
			dfs(x,root);
		}
	}
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>dfs</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
