// Author: YOGI
// Created on: 2024-09-16_22-28-11
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
vector<int> par(N);
// LCA : Lowest common Ancestor -> from bottom to top first common parent node

void dfs(int vertex, int parent = -1){
	par[vertex] = parent;
	for(auto child : g[vertex]){
		if(child == parent) continue;
		dfs(child, vertex);
	}
}

vector<int> path(int vertex){
	vector<int> ans;
	while(vertex != -1){
		ans.push_back(vertex);
		vertex = par[vertex];
	}
	reverse(all(ans));
	return ans;
}

void solve()
{
	int n; cin >> n;
	for(int i = 0; i < n - 1; i++){
		int x, y; cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	int x, y; cin >> x >> y;
	vector<int> x_path = path(x);
	vector<int> y_path = path(y);
	int m = min(x_path.size(), y_path.size());
	int lcs = -1;
	for(int i = 0; i < m; i++){
		if(x_path[i] != y_path[i]){
			lcs = x_path[i-1];
			break;
		}
	}
	cout << lcs << endl;
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
