<snippet>
	<content><![CDATA[


bool isSubsetSum(int brr[], int n, int sum)
{
	// The value of dp[i][j] will be true if
	// there is a subset of brr[0..j-1] with sum
	// equal to i
	bool dp[n + 1][sum + 1];

	// If sum is 0, then answer is true
	for (int i = 0; i <= n; i++)
		dp[i][0] = true;

	// If sum is not 0 and set is empty,
	// then answer is false
	for (int i = 1; i <= sum; i++)
		dp[0][i] = false;

	// Fill the subset table in bottom up manner
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j < brr[i - 1])
				dp[i][j] = dp[i - 1][j];
			if (j >= brr[i - 1])
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - brr[i - 1]];
		}
	}

	return dp[n][sum];
}

]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>subset sum</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
