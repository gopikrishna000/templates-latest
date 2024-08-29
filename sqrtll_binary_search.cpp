<snippet>
	<content><![CDATA[

// Function to find square root
// of given number upto given
// precision
long double sqrtll(int number, int precision = 20)
{
	int start = 0, end = number;
	int mid;

	// variable to store the answer
	long double ans = 0;

	// for computing integral part
	// of square root of number
	while (start <= end) {
		mid = (start + end) / 2;
		if (mid * mid == number) {
			ans = mid;
			break;
		}

		// incrementing start if integral
		// part lies on right side of the mid
		if (mid * mid < number) {
			start = mid + 1;
			ans = mid;
		}

		// decrementing end if integral part
		// lies on the left side of the mid
		else {
			end = mid - 1;
		}
	}

	// For computing the fractional part
	// of square root upto given precision
	long double increment = 0.5;
	for (int i = 0; i < precision; i++) {
		while (ans * ans <= number) {
			ans += increment;
		}

		// loop terminates when ans * ans > number
		ans = ans - increment;
		increment = increment / 2;
	}
	return ans;
}


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>sqrtll</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
