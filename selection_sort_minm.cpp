<snippet>
	<content><![CDATA[

vi ord(n), where(n), what;
		iota(all(ord), 0);
		where = what = ord;
		sort(all(ord), [&](auto a, auto b) {
			return arr[a] < arr[b];
		});
		auto SWAP = [&](auto i, auto j) {
			swap(what[i], what[j]);//unique index even though arr may be repeated
			swap(arr[i], arr[j]);//in case need
			swap(where[what[i]], where[what[j]]);
		};
		for (int i = 0; i < n; i++) {
			if (where[ord[i]] != i) {
				SWAP(i, where[ord[i]]);
			}
		}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>selection sort</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
