// Author: YOGI
// Created on: 2024-09-25_12-13-59
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
const int INF = 1e9 + 10;
vector<vector<int>> val(N, vector<int>(N));
vector<vector<int>> vis(N, vector<int>(N));
vector<vector<int>> lev(N, vector<int>(N));

int n, m;

void reset(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			vis[i][j] = 0;
			lev[i][j] = INF;
		}
	}	
}

vector<pair<int,int>> movements = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0},
	{1, 1}, {1, -1}, {-1, 1}, {-1, -1}
};

bool isValid(int i, int j){
	return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs(){
	int mx = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
		 	mx = max(mx, val[i][j]);
		}
	}
	queue<pair<int, int>> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(val[i][j] == mx){
				q.push({i,j});
				lev[i][j] = 0;
				vis[i][j] = 1;
			}
		}
	}
	int ans = 0;
	while(!q.empty()){
		auto v = q.front();
		int vx = v.fi, vy = v.se;
		q.pop();

		for(auto movement : movements){
			int child_x = movement.fi + vx, child_y = movement.se + vy;
			if(!isValid(child_x, child_y)) continue;
			if(vis[child_x][child_y]) continue;
			q.push({child_x, child_y});
			lev[child_x][child_y] = lev[vx][vy] + 1;
			vis[child_x][child_y] = 1;
			ans = max(ans, lev[child_x][child_y]);
		}
	}
	return ans;
}

void solve()
{
	cin >> n >> m;
	reset();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> val[i][j];
		}
	}	
	cout << bfs() << endl;
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
