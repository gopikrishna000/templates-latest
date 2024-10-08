<snippet>
	<content><![CDATA[

#include <bits/stdc++.h>
 
using i64 = long long;
struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};


/*
HLD tree(n);
for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        t.addEdge(u, v);
}
t.work(A); // making root as A
pi = t.parent[i] // parent of node i for current t
t.rootedLca(T, A, B) //T as root, lca(A,B)
S = t.rootedParent(T, S);//T as root, parent of S
*/
 

//only in case any problem ----refer below
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> A(n - 1), B(n - 1);
    HLD t(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        A[i - 1] = u;
        B[i - 1] = v;
        t.addEdge(u, v);
    }
    
    std::vector<int> a(n);
    std::map<int, std::vector<int>, std::greater<>> f;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        f[a[i]].push_back(i);
    }
    
    std::vector<int> ans(n);
    
    int S = -1, T = -1;
    
    int min = 0;
    
    for (auto [v, e] : f) {
        if (e.size() < 2) {
            continue;
        }
        if (e.size() >= 3) {
            min = v;
            break;
        }
        int A = e[0], B = e[1];
        if (S == -1) {
            t.work(A); // making root as A
            ans.assign(n, v);
            S = A, T = B;
            for (int i = T; i != S; i = t.parent[i]) { // parent of node i for current t
                ans[i] = 0;
            }
        } else {
            while (S != T && t.rootedLca(T, A, B) != T) { //T as root, lca(A,B)
                ans[T] = v;
                T = t.parent[T];
            }
            while (S != T && t.rootedLca(S, A, B) != S) { // S as root, lca(A,B)
                S = t.rootedParent(T, S);//T as root, parent of S
                ans[S] = v;
            }
        }
    }
    
    if (S == -1) {
        t.work(0);
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (t.parent[A[i]] == B[i]) {
            std::swap(A[i], B[i]);
        }
        std::cout << std::max(ans[B[i]], min) << "\n";
    }
    
    return 0;
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>HLD</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
