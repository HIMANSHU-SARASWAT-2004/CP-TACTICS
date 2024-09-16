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
const int N = 1e3  + 7;
vector<int> G[N];
vector<bool> vis(N, 0);


bool dfs(int vertex, int parent){
    bool isCycle = false;
    vis[vertex] = true;
    for(auto it : G[vertex]){
        if(vis[it] && it != parent) continue;
        if(vis[it]) return true;
        isCycle |= dfs(it, vertex);
    }
    return isCycle;
}
void solve()
{
    int n, e; cin >> n >> e;
    repeat(i, 0, e){
        int u, v; cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }   
    bool isCycle = false;
    repeat(i,1, n+1){
        if(vis[i]) continue;    
        if(dfs(i, 0)){
            isCycle = true;
            break;
        }
    }
    cout << (isCycle ? "YES" : "NO") << endl;
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
