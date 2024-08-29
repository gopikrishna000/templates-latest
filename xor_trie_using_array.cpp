<snippet>
	<content><![CDATA[


const int K = 30;
const int N = 200200;
const int M = N * (K + 1) + 7;
int id = 0;
int to[M][2];

int getNewNode() {
	to[id][0] = to[id][1] = -1;
	return id++;
}
int createTrie(int x=0) {
	int v = getNewNode();
	int r = v;
	for (int k = K - 1; k >= 0; k--) {
		int u = getNewNode();
		to[v][(x >> k) & 1] = u;
		v = u;
	}
	return r;
}
int findBiggestXor(int v, int x) {
	assert(v != -1);
	int res = 0;
	for (int k = K - 1; k >= 0; k--) {
		int c = (x >> k) & 1;
		if (to[v][c ^ 1] != -1) {
			res ^= 1 << k;
			v = to[v][c ^ 1];
		} else {
			v = to[v][c];
			assert(v != -1);
		}
	}
	return res;
}
int mergeTries(int v, int u) {
	if (v == -1) return u;
	if (u == -1) return v;
	for (int c = 0; c < 2; c++)
		to[v][c] = mergeTries(to[v][c], to[u][c]);
	return v;
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>xor trie array</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
