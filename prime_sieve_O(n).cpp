<snippet>
	<content><![CDATA[


//O(n) prime sieve jiangly
vector<int> minp, primes; //minp=>min prime
void primesieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
    minp[1]=1;
}

/*
-----------------logic------------------
For any number n, if pj is its min prime, and if i.pj=n then i will be largest/last number 
such that we update minp[i*pj]=pj for i.pj=n
* Also from each i, we update "minp[i * p] = p;" only for p<=minprime[i], cause for numbers
n=i*p with p>minprime[i], obviously minprime[n]=minprime[i](which we will update at future i'>i)
but certaintly not p.
-------------rough work-------------
* Time complexity: 	O(Σ(π(minp[i]))
where π[p] is number of prime less than p
and minp[i] is minm prime divisor of i
Also to be more exact,since we use "if(i*p>n)break;" for each i, we dont always visit O(π(minp[i]))
rather O(π(min(minp[i],n/minp[i])))
----------------TL:DR-----------
* Actual Time complexity: O(N)
cause for any number n, minp[n] will be updated by exactly from i=n/minp[n] alone..but no other i.
proof: first it will updated from any i such that i*prime = n, so all the i cut down to
n/primediv[n], but say we update from i = n/pj with pj>minp[n], but it wont be possible as
minp[i]=minp[n] and pj>minp[n]=minp[i].
* So this method just takes for any/each i, exactly one iteration to find its minp *
*/

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>prime sieve linear jiangly</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
