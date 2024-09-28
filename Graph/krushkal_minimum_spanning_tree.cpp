// Author: YOGI
// Created on: 2024-09-28_17-25-54
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
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
void print(vi &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
vector<int> parent(N);
vector<int> sz(N);

void make(int a){
	parent[a] = a;	
	sz[a] = 1;
}

int find(int a){
	if(a == parent[a]) return a;
	return find(parent[a]);
}

void Union(int a, int b){
	a = find(a), b = find(b);
	if(a != b) {
		if(sz[b] > sz[a]) swap(a, b); 
		parent[b] = a;
		sz[a] += sz[b];
	}
}

// Krushkal's Algorithm to find minimum spanning tree

void solve()
{
	int n, m; cin >> n >> m;
	vector<pair<int, pair<int, int>>> edges;
	for(int i = 0; i < m; i++){
		int u, v, wt; cin >> u >> v >> wt;
		edges.push_back({wt, {u, v}});
	}
	sort(all(edges));
	for(int i = 1; i <= n; i++) make(i);

	int total_cost = 0;
	for(auto &edge : edges){
		int wt = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if(find(u) == find(v)) continue;
		Union(u, v);
		total_cost += wt;
		cout << u << " " << v << endl;
	}
	cout << total_cost << endl;
}

signed main()
{
    IOS

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
