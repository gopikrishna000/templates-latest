<snippet>
	<content><![CDATA[


int narm(int x, int P) {
	if (-P <= x && x < (P << 1ll)) {
		if (x < 0) {
			x += P;
		}
		if (x >= P) {
			x -= P;
		}
		return x;
	}

	if (x < 0) {
		x += ((-x + P - 1) / P) * P;
	}
	return x % P;
}


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>narm</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
