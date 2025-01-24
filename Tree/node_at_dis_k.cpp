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
// Printing all the nodes at distance k from the target node

void makeParents(TreeNode *root, TreeNode *target, unordered_map<TreeNode *, TreeNode *> &parents){
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        if(node->left){
            parents[node->left] = node;
            q.push(node->left);
        } 
        if(node -> right){
            parents[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parents;
    makeParents(root, target, parents);
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    while(!q.empty()){
        int sz = q.size();
        if(curr_level++ == k) break;
        while(sz--){
            auto node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parents[node] && !visited[parents[node]]){
                q.push(parents[node]);
                visited[parents[node]] = true;
            }
        }
    }
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
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