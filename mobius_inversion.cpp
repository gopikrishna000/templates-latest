<snippet>
	<content><![CDATA[

	std::vector<int> mu(N + 1);
	mu[1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 2 * i; j <= N; j += i) {
			mu[j] -= mu[i];
		}
	}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>mobius inversion function</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
