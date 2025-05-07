#include <bits/stdc++.h>

// https://atcoder.jp/contests/dp/tasks/dp_s
// अहं कृत्स्नस्य जगतः प्रभवः प्रलयस्तथा ।।6।।

using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"

const long long mod = 1e9 + 7;

long long dp[10002][2][101]; 
void solve()
{
  string k; int d; cin >> k >> d;
  int len = k.size();
  memset(dp, -1, sizeof(dp));
  
  function<long long(long long, int, int)> digitDP = [&](long long idx, int hi, int rem){
    if(idx == len){
      return ((rem == 0) ? 1ll : 0ll);
    }
    
    if(dp[idx][hi][rem] == -1){
      long long ans = 0; int loLim = 0, hiLim = 9;
      if(hi == 1) hiLim = k[idx] - '0';
      
      for(int i = loLim; i <= hiLim; i++){
        int newHi = hi;
        if(i != k[idx] - '0') newHi = 0;
        int newRem = (rem + i) % d;
        ans = (ans + digitDP(idx + 1, newHi, newRem)) % mod;
      }
      dp[idx][hi][rem] = ans;
    }
    return dp[idx][hi][rem];
  };
  
  cout << (digitDP(0ll, 1, 0) - 1 + mod) % mod << endl;
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