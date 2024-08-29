<snippet>
	<content><![CDATA[

//no path compression
takes O(# of unions done after the mark) to go back to mark state/time [not logn]
[doesnt remove an general edge u-v if exist]
struct DSU {
    std::vector<int> siz, f;
    std::vector<std::pair<int *, int>> his;
    DSU(int n) : siz(n, 1), f(n) { std::iota(f.begin(), f.end(), 0); }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (siz[u] < siz[v]) std::swap(u, v);
        his.emplace_back(&siz[u], siz[u]);
        siz[u] += siz[v];
        his.emplace_back(&f[v], f[v]);
        f[v] = u;
    }
    int find(int x) {
        while (x != f[x]) x = f[x];
        return x;
    }
    int size(int x) { return siz[find(x)]; }
    void undo(int mark) {
        while (int(his.size()) > mark) {
            *his.back().first = his.back().second;
            his.pop_back();
        }
    }
};
/*
use
int time = dsu.his.size(); //to mark the time.
dsu.undo(time); //to go back to that state.
*/

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>undo dsu</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
