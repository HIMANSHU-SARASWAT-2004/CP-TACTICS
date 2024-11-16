#include <bits/stdc++.h>

// अहं कृत्स्नस्य जगतः प्रभवः प्रलयस्तथा ।।6।।

using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long
#define vi vector<int>
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
void preorder(TreeNode *root){
    if(root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(TreeNode *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
void levelOrder(TreeNode *root){
    if(root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        cout << node->val << " ";
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}
void itretivePreorder(TreeNode *root){
    stack<TreeNode*> s;
    while(root != NULL || !s.empty()){
        while(root != NULL){
            cout << root->val << " ";
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        root = root->right;
    }
}
void itretivePreorder2(TreeNode *root){
    vi preorder;
    if(root == NULL) return;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        auto node = s.top();
        s.pop();
        preorder.push_back(node->val);
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
    print(preorder);
}
void itretiveInorder(TreeNode *root){
    vi inorder;
    if(root == NULL) return;    
    stack<TreeNode*> s; 
    while(root != NULL || !s.empty()){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        inorder.push_back(root->val);
        root = root->right;
    }
    print(inorder);
}
void itretivePostorder(TreeNode *root){
    vi postorder;
    if(root == NULL) return;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        auto node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }
    while(!s2.empty()){
        auto node = s2.top();
        s2.pop();
        postorder.push_back(node->val);
    }
    print(postorder);
}
void preInPostOrder(TreeNode *root){
    stack<pair<TreeNode*, int>> s;
    s.push({root, 1});
    vi preorder, inorder, postorder;
    if(root == NULL) return;
    while(!s.empty()){
        auto it = s.top();
        s.pop();
        if(it.second == 1){
            preorder.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first->left) s.push({it.first->left, 1});
        }
        else if(it.second == 2){
            inorder.push_back(it.first->val);
            it.second++;
            s.push(it);
            if(it.first->right) s.push({it.first->right, 1});
        }
        else{
            postorder.push_back(it.first->val);
        }
    }
    print(preorder);
    print(inorder);
    print(postorder);
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