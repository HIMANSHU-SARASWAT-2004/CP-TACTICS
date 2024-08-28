https://bit.ly/3t62bqQ


vector<int> f1(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    for(int i = 1; i <= k; i++) dp[0][i] = (arr[0] == i);
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(j < arr[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
        }
    }
    vector<int> last_row = dp[n-1];
    return last_row;
}

int minSubsetSumDifference(vector<int>& arr, int n) {
    int max_sum = 0, min_diff = INT_MAX;
    for(int i = 0; i < n; i++) max_sum += arr[i];
    vector<int> last_row = f1(n, max_sum, arr);
    for(int i = 0; i < last_row.size(); i++) if(last_row[i]) min_diff = min(min_diff, abs(max_sum - 2*i));
    return min_diff;
}
