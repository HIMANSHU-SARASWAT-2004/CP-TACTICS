// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

#include <bits/stdc++.h>

// अहं कृत्स्नस्य जगतः प्रभवः प्रलयस्तथा ।।6।।

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
void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& visited){
    int n = heights.size(), m = heights[0].size();
    visited[i][j] = 1;
    if(i-1 >= 0 && !visited[i-1][j] && heights[i-1][j] >= heights[i][j]) dfs(i-1, j, heights, visited);
    if(i+1 < n && !visited[i+1][j] && heights[i+1][j] >= heights[i][j]) dfs(i+1, j, heights, visited);
    if(j-1 >= 0 && !visited[i][j-1] && heights[i][j-1] >= heights[i][j]) dfs(i, j-1, heights, visited);
    if(j+1 < m && !visited[i][j+1] && heights[i][j+1] >= heights[i][j]) dfs(i, j+1, heights, visited);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    vector<vector<int>> ans;
    vector<vector<int>> pacific(n, vector<int> (m, 0)), atlantic(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++){
        dfs(i, 0, heights, pacific);
        dfs(i, m-1, heights, atlantic);
    }
    for(int i = 0; i < m; i++){
        dfs(0, i, heights, pacific);
        dfs(n-1, i, heights, atlantic);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(pacific[i][j] && atlantic[i][j]){
                ans.push_back({i, j});
            }
        }
    }
    return ans;
}
void solve()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> sea(n, vector<int> (m)), ans;
	repeat(i,0,n) repeat(j,0,m) cin >> sea[i][j];
	ans = pacificAtlantic(sea);
    // for(auto it : ans){
    //     print(it);
    // }
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
