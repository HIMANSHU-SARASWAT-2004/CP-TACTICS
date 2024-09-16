// https://leetcode.com/problems/island-perimeter/description/

// Author: YOGI
// Created on: 2024-09-15_11-50-27
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
int dfs(int i, int j, vector<vector<int>> & grid){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return 1;
    if(grid[i][j] == -1) return 0;
    grid[i][j] = -1;
    int ans = 0;
    ans += dfs(i+1, j, grid);
    ans += dfs(i-1, j, grid);
    ans += dfs(i, j+1, grid);
    ans += dfs(i, j-1, grid);
    return ans;
}
int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;
    repeat(i,0,n){
        repeat(j,0,m){
            if(grid[i][j] == 1){
                ans += dfs(i, j, grid);
                // cout << ans << " ";
            }
        }
        // cout << endl;
    }
    return ans;
}
void solve()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> grid(n, vector<int> (m));
	repeat(i,0,n) repeat(j,0,m) cin >> grid[i][j];
	cout << islandPerimeter(grid) << endl;	
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
