// Author: YOGI
// Created on: 2024-09-28_15-37-03
// Your code goes here
// https://codeforces.com/problemset/problem/295/B

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


void solve()
{
	int n; cin >> n; 
	vector<vector<int>> dist(n + 1, vector<int>(n + 1));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> dist[i][j];
		}
	}

	vector<int> del_order(n), ans;
	for(int i = 0; i < n; i++) cin >> del_order[i];
	reverse(all(del_order));

	for(int k = 0; k < n; k++){
		int k_v = del_order[k];
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int new_dist = dist[i][k_v] + dist[k_v][j];
				dist[i][j] = min(dist[i][j], new_dist);
			}
		}
		int sum = 0;
		for(int i = 0; i <= k; i++){
			for(int j = 0; j <= k; j++){
				sum += dist[del_order[i]][del_order[j]];
			}
		}
		ans.push_back(sum);
	}
	reverse(all(ans));
	print(ans);
}

signed main()
{
    IOS

#ifndef ONLINE_JUDGE

        freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
