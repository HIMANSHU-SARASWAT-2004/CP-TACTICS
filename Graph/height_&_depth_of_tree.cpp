// Author: YOGI
// Created on: 2024-09-15_15-26-27
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
const int N = 1e3+10;
vector<int> g[N];
vector<int> Height(N), Depth(N);

void dfs(int vertex, int par = 0){

	for(auto child : g[vertex]){
		if(child == par) continue;
		Depth[child] = Depth[vertex] + 1;
		dfs(child, vertex);
		Height[vertex] = max(Height[vertex], Height[child] + 1);
	}	
	
}
void solve()
{
	int n; cin >> n;
	repeat(i,0,n-1){
		int x, y; cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1);
	for(int i = 0; i < n + 1; i++){
		cout << Height[i] << " " << Depth[i] << endl;
	}
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
