<snippet>
	<content><![CDATA[

const int inf = 2e9;
int n, l;
vector<vector<int>> adj; //upd adj
int _q = 0; //update it to _q if wt ed tree is used
vector<vector<pair<int, int>>> wadj;
vector<int> wt;

int timer;
vector<int> tin, tout, depth;
vector<vector<int>> up, mx, mn;
vector<int> arr;

void dfs(int v, int p, int dep) //depth is extra,in case needed...
{
	tin[v] = ++timer;
	up[v][0] = p;
	mx[v][0] = arr[v];
	mn[v][0] = arr[v];

	depth[v] = dep;
	for (int i = 1; i <= l; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		mx[v][i] = max(mx[v][i - 1], mx[up[v][i - 1]][i - 1]);
		mn[v][i] = min(mn[v][i - 1], mn[up[v][i - 1]][i - 1]);
	}

	for (int u : adj[v]) {
		if (u != p)
			dfs(u, v, dep + 1);
	}

	tout[v] = ++timer;
}

void wdfs(int v, int p, int sofar)
{
	wt[v] = sofar;
	for (auto &[u, w] : wadj[v]) {
		if (u != p)
			wdfs(u, v, sofar + w);
	}
}

// is u ancestor of v?
bool is_ancestor(int u, int v)
{
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = l; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

int distance(int u, int v) {
	int anc = lca(u, v);
	return abs(depth[u] - depth[anc]) + abs(depth[anc] - depth[v]);
}

int weight(int u, int v) {
	int anc = lca(u, v);
	return abs(wt[u] - wt[anc]) + abs(wt[anc] - wt[v]);
}

void preprocess(int root) {
	n = adj.size();
	tin.resize(n);
	tout.resize(n);
	depth.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	mx.assign(n, vector<int>(l + 1, -inf));
	mn.assign(n, vector<int>(l + 1, inf));
	dfs(root, root, 0);
	if (_q) {
		wt.resize(n);
		wdfs(root, root, 0);
	}
}

/*
* if edge has weight and edge path query need, then just do edgevsnode mapping
* and assign find node max query excluding lca.
*/
int maxQuery(int u, int v) {
	int U, V;
	int res = -inf;
	int lca = u;
	auto doo = [&](auto u, auto v) {
		if (is_ancestor(v, u))return;
		U = u, V = v;
		for (int i = l; i >= 0 ; i--) {
			if (!is_ancestor(up[V][i], u)) {
				chmax(res, mx[V][i]);
				V = up[V][i];
			}
		}
		chmax(res, arr[V]);
		lca = up[V][0];
	};
	doo(u, v);
	doo(v, u);
	// doing for ancestor which wasnt covered in both case [exclude this if edge path query).
	chmax(res, arr[lca]);
	return res;
}

int minQuery(int u, int v) {
	int U, V;
	int res = inf;
	int lca;
	auto doo = [&](auto u, auto v) {
		if (is_ancestor(v, u))return;
		U = u, V = v;
		for (int i = l; i >= 0 ; i--) {
			if (!is_ancestor(up[V][i], u)) {
				chmin(res, mx[V][i]);
				V = up[V][i];
			}
		}
		chmin(res, arr[V]);
		lca = up[V][0];
	};
	doo(u, v);
	doo(v, u);
	// doing for ancestor which wasnt covered in both case [exclude this if edge path query).
	chmin(res, arr[lca]);
	return res;
}


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>min max binary lifting lca</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
