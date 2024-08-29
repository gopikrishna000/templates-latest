<snippet>
	<content><![CDATA[

    int xors = 0;
    if (n % 4 == 0) xors = n;
    else if (n % 4 == 1) xors = 1;
    else if (n % 4 == 2) xors = n + 1;
    else xors = 0;

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>natural xor sum</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
