<snippet>
	<content><![CDATA[

int N = n;
int low = 0 , high = N , mid = (low + high) / 2;
while (low < high) {
	if (mid!=N && foo(mid)) {
		low = mid + 1;
	}
	else {
		high = mid;
	}
	mid = (low + high) / 2;
}

/*binary search, first zero! [note: range is 0 to n-1]
111111000000
......X..... => X = low.
All cases handled [ie: when "000" || "111"], former case is just like any other i,
and later is handled like "11110" by adding 0 at nth position.(ie:mid!=n)
*/

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>binary search</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
