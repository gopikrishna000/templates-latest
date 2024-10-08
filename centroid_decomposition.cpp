<snippet>
	<content><![CDATA[

struct centroid {
  vector<vector<int> > edges;
  vector<bool> vis;
  vector<int> par;
  vector<int> sz;
  int n;
 
  void init(int s) {
    n = s;
    edges = vector<vector<int> >(n, vector<int>());
    vis = vector<bool>(n, 0);
    par = vector<int>(n);
    sz = vector<int>(n);
  }
 
  void edge(int a, int b) {
    edges[a].pb(b);
    edges[b].pb(a);
  }
 
  int find_size(int v, int p = -1) {
    if (vis[v]) return 0;
    sz[v] = 1;
 
    for (int x: edges[v]) {
      if (x != p) {
        sz[v] += find_size(x, v);
      }
    }
 
    return sz[v];
  }
 
  int find_centroid(int v, int p, int n) {
    for (int x: edges[v]) {
      if (x != p) {
        if (!vis[x] && sz[x] > n / 2) {
          return find_centroid(x, v, n);
        }
      }
    }
 
    return v;
  }
 
  void init_centroid(int v = 0, int p = -1) {
    find_size(v);
 
    int c = find_centroid(v, -1, sz[v]);
    vis[c] = true;
    par[c] = p;
 
    for (int x: edges[c]) {
      if (!vis[x]) {
        init_centroid(x, c);
      }
    }
  }
};



/*
readme
1)Read in n, and call init(n).
2)Read in all edges, and call edge(u, v) for an edge between u and v.
3)Call init_centroid (the root v can be arbitrary, make sure p is -1).
That’s it - now the tree is represented by the parents for each vertex.
note: par for root will be -1.

create like 
centroid cd;
cd.init(n);,so on

ref:https://discuss.codechef.com/t/hybrid-tutorial-2-centroid-decomposition/75297
*/

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>centroid decomposition</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
