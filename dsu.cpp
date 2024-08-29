<snippet>
	<content><![CDATA[


#define dsu(n) parent_dsu.resize(n);rank_dsu.assign(n,0);iota(parent_dsu.begin(),parent_dsu.end(),0)
vector<int> parent_dsu, rank_dsu;
void make_set_dsu(int v) {
	parent_dsu[v] = v;  //initially all elements of parent_dsu = same value // so no need of make_set_dsu !!
	rank_dsu[v] = 0;     //initially all elemnts of rank = 0
}

int find_set_dsu(int v) {
	if (v == parent_dsu[v])
		return v;
	return parent_dsu[v] = find_set_dsu(parent_dsu[v]); //path compression
	//O(logn) avg, but while building tree by doing union itself everything happens, and it becomes O(logn) after construction, for any call.
}

void union_sets_dsu(int a, int b) {
	a = find_set_dsu(a);
	b = find_set_dsu(b);
	if (a != b) {
		if (rank_dsu[a] < rank_dsu[b])
			swap(a, b);
		parent_dsu[b] = a;
		if (rank_dsu[a] == rank_dsu[b])
			rank_dsu[a]++;
	}
}


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>dsu</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
