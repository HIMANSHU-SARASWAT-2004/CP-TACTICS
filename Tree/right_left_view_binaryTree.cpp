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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void recursionRight(TreeNode *root, int level, vector<int> &res){
    if(!root) return;
    if(res.size() == level) res.push_back(root->val);
    recursionRight(root->right, level+1, res);
    recursionRight(root->left, level+1, res);
}

vector<int> rightSideView(TreeNode *root){
    vector<int> res;
    recursionRight(root, 0, res);
    return res;
}

void recursionLeft(TreeNode *root, int level, vector<int> &res){
    if(!root) return;
    if(res.size() == level) res.push_back(root->val);
    recursionLeft(root->left, level + 1, res);
    recursionLeft(root->right, level + 1, res);
}

vector<int> leftSideView(TreeNode *root){
    vector<int> res;
    recursionLeft(root, 0, res);
    return res;
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