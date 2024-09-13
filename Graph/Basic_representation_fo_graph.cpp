// Author: YOGI
// Created on: 2024-09-13_20-37-58
// Your code goes here

#include <bits/stdc++.h>

using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long
#define repeat(i, st, n) for (int i = st; i < n; i++)

void solve1() // Matrix
{
	int n, m; cin >> n >> m;
	vector<vector<int>> Graph(n, vector<int> (n, 0));
	repeat(i,0,m){
		int x, y; cin >> x >> y;
		Graph[x-1][y-1] = 1;
		Graph[y-1][x-1] = 1;
	}
}
const int N = 1e5+ 10;
vector<int> g[N];
void solve2() // List
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
 //   freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        // solve1();
        // solve2();
    }
    return 0;
}
