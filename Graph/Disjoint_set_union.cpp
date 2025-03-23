// Author: YOGI
// Created on: 2024-09-28_17-25-54
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
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
void print(vi &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
vector<int> parent(N);
vector<int> size(N);

void make(int a){
	parent[a] = a;	
	size[a] = 1;
}

int find(int a){
	if(a == parent[a]) return a;
	return find(parent[a]);
}

void Union(int a, int b){
	int a = find(a), b = find(b);
	if(a != b) {
		if(size[b] > size[a]) swap(a, b); 
		parent[b] = a;
		size[a] += size[b];
	}
}
struct DSU{
    int cnt = 0;
    vector<int> par;
    void init(int n){
        par.assign(n + 1, -1);
        cnt = n;
    }
    int getPar(int node){
        if(par[node] < 0) return node;
        return par[node] = getPar(par[node]);
    }
    int unite(int a, int b){
        a = getPar(a);
        b = getPar(b);
        if(a == b) return 0;
        if(-par[a] < -par[b]) swap(a, b);
        par[a] += par[b];
        par[b] = a;
        cnt--;
        return 1;
    }
};

void solve()
{
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++){
		make(i);
	}
	while(m--){
		int u, v; cin >> u >> v;
		Union(u, v);
	}

	int connected = 0;
	for(int i = 1; i <= n; i++){
		if(find(i) == i) connected++;
	}
	cout << connected << endl;
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
