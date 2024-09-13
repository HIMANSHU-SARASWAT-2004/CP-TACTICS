// Author: YOGI
// Created on: 2024-09-13_22-18-28
// Your code goes here

#include <bits/stdc++.h>

using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){
	// Take action on vertex after entering the vertex
	cout << vertex << endl;
	vis[vertex] = true;
	for(int chile : g[vertex]){
		cout << "Parent: " << vertex << " Child: " << chile << endl;
		if([vis[chile]]) continue;
		// Take action on child before entering the child node
		dfs(child);
		// Take action on child after exiting child node 
	}	
	// Take action on vertex before exiting the vertex
} 

void solve()
{
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int v1, v2; cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
}

signed main()
{
    IOS

#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
