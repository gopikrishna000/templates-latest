<snippet>
	<content><![CDATA[

struct SCC {
	int n;
	std::vector<std::vector<int>> adj;
	std::vector<int> stk;
	std::vector<int> dfn, low, bel;
	int cur, cnt;

	SCC() {}
	SCC(int n) {
		init(n);
	}

	void init(int n) {
		this->n = n;
		adj.assign(n, {});
		dfn.assign(n, -1);
		low.resize(n);
		bel.assign(n, -1);
		stk.clear();
		cur = cnt = 0;
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

	void dfs(int x) {
		dfn[x] = low[x] = cur++;
		stk.push_back(x);

		for (auto y : adj[x]) {
			if (dfn[y] == -1) {
				dfs(y);
				low[x] = std::min(low[x], low[y]);
			} else if (bel[y] == -1) {
				low[x] = std::min(low[x], dfn[y]);
			}
		}

		if (dfn[x] == low[x]) {
			int y;
			do {
				y = stk.back();
				bel[y] = cnt;
				stk.pop_back();
			} while (y != x);
			cnt++;
		}
	}

	std::vector<int> work() {
		for (int i = 0; i < n; i++) {
			if (dfn[i] == -1) {
				dfs(i);
			}
		}
		return bel;
	}
};

// vi in;
vector<vector<int>> compressed_tree(SCC &g) {
	auto bel = g.work();
	int n = bel.size();
	std::vector<std::vector<int>> adj(g.cnt);
	// in.assign(g.cnt, 0);
	for (int i = 0; i < n; i++) {
		for (auto j : g.adj[i]) {
			if (bel[i] != bel[j]) {
				adj[bel[i]].push_back(bel[j]);
				// in[bel[j]]++;
			}
		}
	}
	return adj;
}

/*
SCC g(n);
// edge add u -> v.
g.addEdge(u, v);
vector<int> bel = g.work(); // bel[i] == like dsu group belongs.
//note: bel[i] = [0,cnt) range instead of [0,-1]
*/


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>scc-tarjan-kosaraju</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
