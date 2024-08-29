<snippet>
	<content><![CDATA[

//return two number with  given sum and xor value..
void solve(int sum,
            int xorVal)
{
    int A = (sum - xorVal)/2;
    int a = 0, b = 0;
    for (int i=0; i< 8*sizeof(sum); i++)
    {
        int x = (xorVal & (1 << i));
        int ai = (A & (1 << i));
        if (x == 0 && ai == 0)
        {
            continue;
        }
        else if (x == 0 && ai > 0)
        {
            a = ((1 << i) | a);
            b = ((1 << i) | b);
        }
        else if (x > 0 && ai == 0)
        {
            a = ((1 << i) | a);
        }
        else 
        {
            cout << "-1\n";
            return;
        }
    }
    if(a+b != 2 * (a ^ b)) {
        cout << "-1" << endl;
        return;
    }
    cout << a << ' ' << b << endl;
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>xor sum addition solution</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
