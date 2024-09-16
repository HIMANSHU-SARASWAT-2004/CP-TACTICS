// Author: YOGI
// Created on: 2024-09-16_09-53-39
// Your code goes here

#include <bits/stdc++.h>

using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define fi first
#define se second
#define all(arr) arr.begin(), arr.end()
#define MP make_pair
#define pb push_back
#define repeat(i, st, n) for (int i = st; i < n; i++)
const int mod = 1e9 + 7;
void print(vi &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
const int N = 1e3 + 10;
vector<int> g[N];
vector<int> subTree_sum(N), subTree_even(N);

// Given Q Queries, Q <= 10^5
// In each query given, V
// Print subtree sum of V & Number of even numbers
// int subtree of V

void dfs(int vertex, int par = 0){

	if(vertex % 2 == 0) subTree_even[vertex]++;
	subTree_sum[vertex] += vertex;
	for(int child : g[vertex]){

		if(child == par) continue;
		dfs(child, vertex);

		subTree_sum[vertex] += subTree_sum[child];
		subTree_even[vertex] += subTree_even[child];
	}
	
}
void solve()
{
	int n; cin >> n;
	for(int i = 0; i < n-1; i++){
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	for(int i = 1; i < n; i++){
		cout << subTree_sum[i] << " " << subTree_even[i] << endl;
	}
	// int q; cin >> q;
	// while(q--){
	// 	int v; cin >> v;
	// 	cout << subTree_sum[v] << " " << subTree_even[v] << endl;
	// }
}

signed main()
{
    IOS

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
