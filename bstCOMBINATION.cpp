#include<bits/stdc++.h>

using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void calculateFact(int *fact, int n)
{
	fact[0] = 1;
	for (ll i = 1; i < n; i++)
	{
		fact[i] = fact[i - 1] * i;
	}


}
int nCr(int *fact, int n, int r)
{
	//nCr = n!/r!*(n-r)!

	if (n < r)
		return 0;
	int res = fact[n] / fact[n - r];

	res /= fact[r];

	return res;
}

int build(vector<int> arr, int *fact)
{
	int N = arr.size();

	if (N <= 2)
		return 1;

	int root = arr[0];
	vector<int> leftsubtree;

	vector<int> rightsubtree;


	//leftsubtree mai small than root && rightsubtree mai greater than root element
	for (int i = 1; i < N; i++)
	{
		if (arr[0] < arr[i])
			rightsubtree.pb(arr[i]);
		else
			leftsubtree.pb(arr[i]);
	}

	int n1 = leftsubtree.size();
	// countLeft is for the left subtree and than its left subtree

	//countRight is for the right subtree and than its right so on.

	int countLeft = build(leftsubtree, fact);
	int countRight = build(rightsubtree, fact);

	// ans for calculating the nCr of the current node and than going left and right and than
	// finding its nCr

	int ans = nCr(fact, N - 1, n1) * countRight * countLeft;
	return ans;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int k ; cin >> k;
		arr.pb(k);
	}

	int fact[n];

	calculateFact(fact, n);

	int ans = build(arr, fact);
	cout << "No of ways are: " << ans << nline;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	fastio();
	int t;	cin >> t;
	while (t--)
	{
		solve();

	}
}
