// Author: YOGI
// Created on: 2024-08-26_23-43-34
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
int arr[100100];
int t[400400];

void build(int index, int l, int r){
	if(l == r){
		t[index] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	build(index * 2, l, mid);
	build(index * 2 + 1, mid + 1 , r);
	t[index] = t[index * 2] + t[index * 2 + 1];
}

void update(int index, int l, int r, int pos, int val){
	if(pos < l || pos > r) return;
	if(l == r){
		t[index] = val;
		arr[l] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(index * 2, l, mid, pos, val);
	update(index * 2 + 1, mid + 1 , r, pos, val);
	t[index] = t[index * 2] + t[index * 2 + 1];
}

int query(int index, int l , int r, int lq, int rq){
	if(l > rq || lq > r) return 0;
	if(lq <= l && r <= rq){
		return t[index];
	}
	int mid = (l + r) / 2;
	return query(index * 2, l , mid, lq, rq) + query(index * 2 + 1, mid + 1, r, lq, rq);
}

void solve()
{
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	build(1, 0, n - 1);
	int q; cin >> q;
	while(q--){
		int ch; cin >> ch;
		if(ch == 1){
			int x, v; cin >> x >> v;
			update(1, 0, n-1, x, v);
		}else{
			int l, r; cin >> l >> r;
			cout << query(1, 0, n-1, l, r) << endl;
		}
	}
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


// Standerd way to deal with Segment tree
// Author: YOGI
// Created on: 2024-08-26_23-43-34
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
int arr[100100];
struct node{
	int mini, cnt;
	node(int m = 1e9, int c = 0){
		mini = m;
		cnt = c;
	}	
};
node t[400400];
node merge(node a, node b){
	if(a.mini == b.mini) return node(a.mini, a.cnt + b.cnt);
	else if(a.mini < b.mini) return a;
	else return b;
}
void build(int index, int l, int r){
	if(l == r){
		t[index] = node(arr[l], 1);
		return;
	}
	int mid = (l + r) / 2;
	build(index * 2, l, mid);
	build(index * 2 + 1, mid + 1 , r);
	t[index] = merge(t[index * 2] , t[index * 2 + 1]);
}

void update(int index, int l, int r, int pos, int val){
	if(pos < l || pos > r) return;
	if(l == r){
		t[index] = node(val, 1);
		arr[l] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(index * 2, l, mid, pos, val);
	update(index * 2 + 1, mid + 1 , r, pos, val);
	t[index] = merge(t[index * 2] , t[index * 2 + 1]);
}
node query(int index, int l , int r, int lq, int rq){
	if(l > rq || lq > r) return node();
	if(lq <= l && r <= rq){ // complete overlap (for example lq = l and rq = r)
		return t[index];
	}
	int mid = (l + r) / 2;
	return merge(query(index * 2, l , mid, lq, rq) , query(index * 2 + 1, mid + 1, r, lq, rq));
}
void print_tree(int n){
	for(int i = 1; i < 2 * n; i++){
		cout << t[i].mini << " " << t[i].cnt << endl;
	}
}
void solve()
{
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	build(1, 0, n - 1);
	int q; cin >> q;
	while(q--){
		int ch; cin >> ch;
		if(ch == 1){
			int x, v; cin >> x >> v;
			update(1, 0, n-1, x, v);
			print_tree(n);
			cout << endl;
		}else{
			int l, r; cin >> l >> r;
			node p = query(1, 0, n-1, l, r);
			cout << p.mini << " " << p.cnt << endl;
			cout << endl;
		}
	}
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

