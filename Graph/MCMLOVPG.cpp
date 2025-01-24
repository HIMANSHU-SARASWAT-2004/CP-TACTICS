// Minimum Cost to Make at Least One Valid Path in a Grid
// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void print(vi &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
int minCost(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    deque<pair<int,int>> dq;
    dq.push_back({0,0});
    dist[0][0] = 0;
    while(!dq.empty()){
        auto [x, y] = dq.front();
        dq.pop_front(); int ind = 0;
        for(auto [dx, dy] : moves){
            int nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                int cost = (ind + 1 == grid[x][y]) ? 0 : 1;
                if(dist[nx][ny] > dist[x][y] + cost){
                    dist[nx][ny] = dist[x][y] + cost;
                    if(cost == 0) dq.push_front({nx, ny});
                    else dq.push_back({nx, ny});
                }
            }
            ind++;
        }
    }
    return dist[n-1][m-1];
}
void solve()
{
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