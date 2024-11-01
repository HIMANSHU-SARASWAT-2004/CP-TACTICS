// Author: YOGI
// Created on: 2024-09-25_14-43-57
// Your code goes here
// Question : https://leetcode.com/problems/network-delay-time/description/

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
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];

// Dijkstra Algorithm {work on weighted graph};

int dijkstra(int source, int n, vector<pair<int, int>> g[])
{
	vector<int> vis(N, 0);
	vector<int> dist(N, INF);

	set<pair<int, int>> st;

	st.insert({0, source});
	dist[source] = 0;

	while (st.size() > 0)
	{
		auto node = *st.begin();
		int v = node.se, v_dist = node.fi;
		st.erase(node);
		if (vis[v])
			continue;
		vis[v] = 1;
		for (auto child : g[v])
		{
			int child_v = child.fi, wt = child.se;
			if (dist[v] + wt < dist[child_v])
			{
				dist[child_v] = dist[v] + wt;
				st.insert({dist[child_v], child_v});
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INF)
			return -1;
		ans = max(ans, dist[i]);
	}
	return ans;
}

void dijkstra(int &source, int &n, vector<int> &time, vector<pair<int,int>> g[]){
    time[source] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0, source});
    while(!pq.empty()){
        int v = pq.top().second, v_time = pq.top().first;
        pq.pop();
        if(time[v] < v_time) continue;
        for(auto child : g[v]){
            int child_v = child.first, wt = child.second;
            if(time[v] + wt < time[child_v]){
                time[child_v] = time[v] + wt;
                pq.push({time[child_v], child_v});
            }
        }
    }
}
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
	vector<pair<int, int>> g[N];
	for (auto edge : times)
	{
		int x = edge[0], y = edge[1], wt = edge[2];
		g[x].push_back({y, wt});
	}
	return dijkstra(k, n, g);
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	// for (int i = 0; i < m; i++)
	// {
	// 	int x, y, wt;
	// 	cin >> x >> y >> wt;
	// 	g[x].push_back({y, wt});
	// }
	// cout << dijkstra(k, n, g) << endl;

	vector<vector<int>> times;
	for (int i = 0; i < m; i++)
	{
		int x, y, wt;
		cin >> x >> y >> wt;
		times.push_back({x, y, wt});
	}
	cout << networkDelayTime(times, n, k) << endl;
}

signed main()
{
	IOS

#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
