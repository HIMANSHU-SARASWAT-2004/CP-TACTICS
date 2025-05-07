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
class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> ans;
        multiset<int> minHeap, maxHeap;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (maxHeap.empty() || nums[i] <= *maxHeap.rbegin())
            {
                maxHeap.insert(nums[i]);
            }
            else
            {
                minHeap.insert(nums[i]);
            }

            while (maxHeap.size() > minHeap.size() + 1)
            {
                minHeap.insert(*maxHeap.rbegin());
                maxHeap.erase(prev(maxHeap.end()));
            }
            while (minHeap.size() > maxHeap.size())
            {
                maxHeap.insert(*minHeap.begin());
                minHeap.erase(minHeap.begin());
            }

            if (i >= k - 1)
            {
                if (maxHeap.size() == minHeap.size())
                {
                    ans.push_back((1.0 * (*maxHeap.rbegin()) + *minHeap.begin()) / 2.0);
                }
                else
                {
                    ans.push_back(*maxHeap.rbegin());
                }

                int toRemove = nums[i - k + 1];
                if (maxHeap.find(toRemove) != maxHeap.end())
                {
                    maxHeap.erase(maxHeap.find(toRemove));
                }
                else
                {
                    minHeap.erase(minHeap.find(toRemove));
                }

                while (maxHeap.size() > minHeap.size() + 1)
                {
                    minHeap.insert(*maxHeap.rbegin());
                    maxHeap.erase(prev(maxHeap.end()));
                }
                while (minHeap.size() > maxHeap.size())
                {
                    maxHeap.insert(*minHeap.begin());
                    minHeap.erase(minHeap.begin());
                }
            }
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