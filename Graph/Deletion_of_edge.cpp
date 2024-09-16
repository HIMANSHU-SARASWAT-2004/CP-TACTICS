// Author: YOGI
// Created on: 2024-09-16_23-05-18
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
vector<int> subtree_sum(N);
vector<int> val(N);

void dfs(int vertex, int parent = -1){
	subtree_sum[vertex] += val[vertex];
	for(auto child : g[vertex]){
		if(child == parent) continue;
		dfs(child, vertex);
		subtree_sum[vertex] += subtree_sum[child];
	}
}
// Edge Deletion type question ke liye
// This code is to find that edge by deletion of which we can find maximum multiplication of sum of both subtrees
void solve()
{
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++){
		int x, y, value; cin >> x >> y >> value;
		g[x].push_back(y);
		g[y].push_back(x);
		val[i] = value;
	}
	dfs(1);
	int ans = 0;
	for(int i = 2; i <= n; i++){
		int part1 = subtree_sum[i];
		int part2 = subtree_sum[1] - subtree_sum[i];
		ans = max(ans, part1 * part2);
	}
	cout << ans << endl;
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
