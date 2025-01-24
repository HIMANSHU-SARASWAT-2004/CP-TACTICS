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
// Lowest Common Ancestor

class Solution {
    public:
        bool getPath(TreeNode *root, vector<TreeNode*> &arr, int node){
            if(root == NULL) return false;
            arr.push_back(root);
            if(root->val == node) return true;
            if(getPath(root->left, arr, node) || getPath(root->right, arr, node)) return true;
            arr.pop_back();
            return false;
        }
        vector<TreeNode*> solve(TreeNode *root, int node){
            vector<TreeNode*> arr; 
            getPath(root, arr, node);
            return arr;
        }
    public: 
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
            vector<TreeNode*> p1 = solve(root, p->val), p2 = solve(root, q->val);
            TreeNode* ans = NULL;
            for(int i = 0; i < min(p1.size(), p2.size()); i++){
                if(p1[i] == p2[i]) ans = p1[i];
                else break;
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