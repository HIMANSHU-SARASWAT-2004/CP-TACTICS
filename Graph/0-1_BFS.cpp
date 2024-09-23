// Author: YOGI
// Created on: 2024-09-23_10-57-09
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
// Sortest path using 0-1 BFS --> if(value(node) == 0) push_front or push_back
const int N = 1e4 + 10;
const int INF = 1e9;

vector<pair<int,int>> g[N];
vector<int> level(N, INF);

int bfs(int n){
	deque<int> q;
	q.push_front(1);
	level[1] = 0;
	while(!q.empty()){
		int cur_v = q.front();
		q.pop_front();

		for(auto child : g[cur_v]){
			int child_v = child.first;
			int wt = child.second;
			if(level[cur_v] + wt < level[child_v]){
				level[child_v] = level[cur_v] + wt;
				if(wt == 1) q.push_back(child_v);
				else q.push_front(child_v);
			}
		}
	}
	return level[n] == INF ? -1 : level[n];
}

void solve()
{
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		if(x == y) continue;
		g[x].push_back({y, 0});
		g[y].push_back({x, 1});
	}
	cout << bfs(n) << endl;
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
