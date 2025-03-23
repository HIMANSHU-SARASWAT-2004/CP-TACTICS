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

class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            int n = fruits.size(); vector<int> segTree(4 * n, 0); 
            function<void(int, int, int)> build = [&](int st, int end, int n){
                if(st == end){
                    segTree[n] = baskets[st];
                    return;
                }
                int mid = (st + end) / 2;
                build(st, mid, 2 * n);
                build(mid + 1, end, 2 * n + 1);
                segTree[n] = max(segTree[2 * n], segTree[2 * n + 1]);
            };
            build(0, n - 1, 1);
            int ans = 0;
            function<int(int, int, int, int)> search = [&](int n, int st, int end, int k){
                if(segTree[n] < k) return -1;
                if(st == end){
                    segTree[n] = -1;
                    return st;
                }
                int mid = (st + end) / 2;
                int pos = ((segTree[2 * n] >= k) ? search(2 * n, st, mid, k) : search(2 * n + 1, mid + 1, end, k));
                segTree[n] = max(segTree[2 * n], segTree[2 * n + 1]);
                return pos;
            };
            for(auto fruit : fruits){
                if(search(1, 0, n - 1, fruit) == -1) ans++;
            }
            return ans;
        }
};
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