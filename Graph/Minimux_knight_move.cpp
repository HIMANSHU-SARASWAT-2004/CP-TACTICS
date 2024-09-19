// https://www.spoj.com/problems/NAKANJ/

// Author: YOGI
// Created on: 2024-09-18_21-16-29
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

vector<vector<int>> vis(8, vector<int>(8, 0)), level(8, vector<int>(8, 0));
const int INF = 1e9;
int getX(string s)
{
    return s[0] - 'a';
}
int getY(string s)
{
    return s[1] - '1';
}

void reset()
{
    repeat(i, 0, 8)
    {
        repeat(j, 0, 8)
        {
            vis[i][j] = 0;
            level[i][j] = INF;
        }
    }
}
bool isValid(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
vector<pair<int, int>> moves = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
int dfs(string s1, string s2)
{
    int x1 = getX(s1), y1 = getY(s1);
    int x2 = getX(s2), y2 = getY(s2);
    queue<pair<int, int>> q;
    q.push({x1, y1});
    vis[x1][y1] = 1;
    level[x1][y1] = 0;

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for(auto m: moves){
            int nx = x + m.first, ny = y + m.second;
            if(!isValid(nx, ny)) continue;
            if(!vis[nx][ny]){
                q.push({nx, ny});
                level[nx][ny] = level[x][y] + 1;
                vis[nx][ny] = 1;
            }
        }
        if(level[x2][y2] != INF) break;
    }
    return level[x2][y2];
}

void solve()
{
    reset();
    string s1, s2;
    cin >> s1 >> s2;
    cout << dfs(s1, s2) << endl;
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
