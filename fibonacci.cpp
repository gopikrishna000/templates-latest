<snippet>
	<content><![CDATA[

#define ll long long
void fibonacci(ll n, ll&x, ll&y) {
	if (n == 0) {
		x = 0;
		y = 1;
		return ;
	}

	if (n & 1) {
		fibonacci(n - 1, y, x);
		y = (y + x);
	} else {
		ll a, b;
		fibonacci(n >> 1, a, b);
		y = (a * a + b * b);
		x = (a * b + a * (b - a));
	}
}
// int x,y;
// call fib(n,x,y) with any x,y variable
//ans in x

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>fibonacci nth</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
