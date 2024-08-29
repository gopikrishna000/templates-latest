<snippet>
	<content><![CDATA[

//note: lsb_set==lsb && lsb_unset==lsbu
//just take log2(lsb_set(x)) if want just pos. //x!=0
int log2_floor(long long i) {
	return i ? __builtin_clzll(1ll) - __builtin_clzll(i) : -1;
}
#define lsb(x) (x&-x)
#define lsbu(x) (x&(x+1))
#define msb(x) __lg(x)
#define msbu(x)


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>msb lsb bit</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
