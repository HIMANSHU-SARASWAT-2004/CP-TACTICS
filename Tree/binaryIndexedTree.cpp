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

// Fenwick Tree
// number has right most set bit = x & -x
void solve()
{
    int n; cin >> n;
    vector<int> nums(n), bit(n + 1, 0); repeat(i, 0, n) cin >> nums[i];
    function<void(int, int)> update = [&](int val, int id){
        while(id <= n){
            bit[id] += val;
            id += (id & -id);
        }
    };
    function<int(int)> query = [&](int id){
        int sum = 0;
        while(id > 0){
            sum += bit[id];
            id -= (id & -id);
        }
        return sum;
    };
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());
    vector<int> ans(n, 0);
    for(auto & [val, id] : v){
        update(1, id + 1);
        ans[id] = query(n) - query(id + 1);
    }
    print(ans);
}
const int N = 1e5 + 5;
void inversion_count(){
    int n; cin >> n;
    vector<int> nums(n), bit(N, 0); repeat(i, 0, n) cin >> nums[i];
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[nums[i]];
    }
    int ctn = 1; 
    for(auto & [key, val] : mp){
        mp[key] = ctn++;
    }
    for(int i = 1; i <= n; i++){
        nums[i] = mp[nums[i]];
    }
    function<void(int, int)> update = [&](int val, int id){
        while(id <= N){
            bit[id] += val;
            id += (id & -id);
        }
    };
    function<int(int)> query = [&](int id){
        int sum = 0;
        while(id > 0){
            sum += bit[id];
            id -= (id & -id);
        }
        return sum;
    };
    int inversion = 0;
    for(int i = n - 1; i >= 0; i--){
        inversion += query(N - 5) - query(nums[i]);
        update(1, nums[i]);
    }
    cout << inversion << endl;
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
