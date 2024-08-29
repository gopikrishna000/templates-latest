<snippet>
	<content><![CDATA[

vector<vector<int>> matrix_multiply(vector<vector<int>> &mat1, vector<vector<int>> &mat2, long long mod) {
	int i, j, k;
	int M = mat1.size(), K = mat2.size() , N = mat2[0].size();
	vector<vector<int>> res(M, vector<int>(N));
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			res[i][j] = 0;
			for (k = 0; k < K; k++)
				res[i][j] = (res[i][j] + (long long)mat1[i][k] * mat2[k][j]) % mod;
		}
	}

	//   for(int i=0;i<M;i++){
	//   for(int j=0;j<N;j++)
	//       cout<<res[i][j]<<" ";
	//       cout<<"\n";
	//   }
	//       cout<<"\n";
	return res;
}

//N = count, initial = first matrix..
vector<vector<int>> matrix_exp(long long N, vector<vector<int>> initial , long long mod) {
	int n = initial[0].size();
	vector<vector<int>> mat(n, vector<int>(n));
	/*---------- filling M matrix ---------*/ //note: row(ini) x columni(mat)

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			mat[i][j] = 0;
		for (int j = i; j < n; j++)
			mat[i][j] = 1;
	}

	/*---------- filling M matrix ---------*/

	vector<vector<int>> res(n, vector<int>(n)); //indentity matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (i != j)
				res[i][j] = 0;
			else
				res[i][j] = 1;
	}
//   for(int i=0;i<n;i++)
//       for(int j=0;j<n;j++)
//           cout<<mat[i][j]<<" ";
//           cout<<"\n";
	while (N > 0) {
		if (N & 1ll)
			res = matrix_multiply(res, mat, mod); //res , a % m;
		mat = matrix_multiply(mat, mat, mod); //a * a % m;
		N >>= 1ll;
	}
	return matrix_multiply(initial, res, mod); //Dont change the order of multiplication.
}


int main() {
	// your code goes here
	int n, k;
	scanf("%d %d", &n, &k);
	vector<vector<int>> arr(1, vector<int>(n));

	//inital values 1D
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[0][i]);
	}


	vector<vector<int>> ans = matrix_exp(k, arr, 1e9 + 7); //passing 1D initial vector as 2D

	for (int i = 0; i < n; i++)
		printf("%d ", ans[0][i]);
	printf("\n");

	return 0;
}


]]></content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>matrix exponentiation</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
