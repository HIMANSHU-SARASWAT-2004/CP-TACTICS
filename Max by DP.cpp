int maxibydp(vi nums, int n){
    vector<int> dp(n);
    dp[0] = max(0ll,nums[0]);
    int mx = max(dp[0],0ll);
    for(int i = 1;i < n;i++){
        dp[i] = 0;
        dp[i] = max({dp[i],dp[i-1]+nums[i],nums[i]});
        mx = max(mx,dp[i]);
    }
    return mx;
}
