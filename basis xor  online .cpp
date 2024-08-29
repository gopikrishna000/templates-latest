<snippet>
	<content><![CDATA[

const int d = 30;
int basis[d]; // basis[i] keeps the mask of the vector whose f value is i

int sz; // Current size of the basis

void insertVector(int mask) {
	for (int i = 0; i < d; i++) {
		if ((mask & 1 << i) == 0) continue; // continue if i != f(mask)

		if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
			basis[i] = mask;
			++sz;
			
			return;
		}

		mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
	}
}
/*
update:*In above code, basis[] contains unique lsbs not msbs..
ie: For unique msb, do all the above logic from left to right of binary rep, instead of
 right to left.. as both are symetrically same....
 * note: we store not the actual element, but a subset xor whose has lsb(or msb) set at that index..
 * if you want to store actual element, then it may not have unique lsb(or msb),
 eg: consider for msb: arr = bas = [1001,1000], but it can be arr = [1001,1000],bas=[1000,0001]
 * tip:You can have another time[30] array parally which stores index.
 ref:https://codeforces.com/contest/1100/submission/48345032 that stores latest index for msb..(not necasrly time[i] has msb as i)
*/


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>basis online</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
