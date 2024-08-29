#include <bits/stdc++.h>
using namespace std;

//https://codeforces.com/blog/entry/96344
// #pragma GCC optimize("O3","unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

long long ccccc = 0;
#ifdef LOCAL
#include "../debug.h"
#define tle ccccc++;assert(ccccc<1e7)
#else
#define wd(x...)
#define tle
#define __stime()
#define __etime()
#endif

using i64 = long long;
using i32 = int32_t;

// #define int long long

/*------------shortcuts----------*/
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define preci(x) cout<<fixed<<setprecision((x));cerr<<fixed<<setprecision((x))
#define unique(a) (a).erase(std::unique((a).begin(),(a).end()),(a).end())
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define aii array<int,2>
#define ai(i) array<int,(i)>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vil vector<long long>
#define vii vector<pair<int,int>>
#define viil vector<pair<long long,long long>>
#define si set<int>
#define up(x) ceil(1.0*x)
#define down(x) floor(1.0*x)
#define mii map<int,int>
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return 1;} else return 0;}
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} else return 0;}

//#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) )
#define ub(a, x) ( upper_bound((a).begin(), (a).end(), (x)) )
template <typename T, typename S> T ceil(T x, S y) {
	assert(y);
	return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
}

template <typename T, typename S> T floor(T x, S y) {
	assert(y);
	return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
}
/*------------shortcuts----------*/

void print(auto &arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}
void yesno(int x) {if (x) cout << "YES\n"; else cout << "NO\n";}


#define all(x) (x).begin(), (x).end()
long long mod = 1e9 + 7 ;

const double EPS = 1e-9;
bool isEqual(double x, double y) {
	return abs(x - y) <= EPS;
	// return abs(x-y)/max(1.0,y) <= EPS;
}


int32_t main() {
	// your code goes here
	fio;
//preci(12);
//dsu(n);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

//__stime();

	int t = 1;
	cin >> t;

	auto solve = [&](int T) -> void{
		// printf("Case #%d: \n",testcase);
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		


		// yesno(ans);
		// cout << ans << "\n";
	};


	for (int i = 1; i <= t; i++) {
		solve(i);
	}

//__etime();

	return 0;
}


