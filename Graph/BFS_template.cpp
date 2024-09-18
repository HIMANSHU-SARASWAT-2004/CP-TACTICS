// Author: YOGI
// Created on: 2024-09-18_12-15-42
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
vector<int> vis(N), level(N);

void bfs(int source){
	queue<int> q;
	q.push(source);
	vis[source] = 1;

	while(!q.empty()){
		int cur_v = q.front();
		q.pop();
		cout << cur_v << " ";
		for(int child : g[cur_v]){
			if(!vis[child]){
				q.push(child);
				vis[child] = 1;
				level[child] = level[cur_v] + 1;
			}
		}
	}
	cout << endl;
}

void solve()
{
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int x, y; cin >> x >> y;
		g[x].pb(y); g[y].pb(x);
	}
	bfs(1);
	
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
