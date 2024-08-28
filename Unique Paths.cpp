#include <bits/stdc++.h> 
int f(int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 && n == 0) return 1;
    if(m < 0 || n < 0) return 0;
    if (dp[m][n] != 0) return dp[m][n];
    return dp[m][n] = f(m - 1, n, dp) + f(m, n - 1, dp);
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    return f(m-1, n-1, dp);
}

Unique Paths II -> Tabulation form

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == -1) dp[i][j] = 0;
            else if(i == 0 && j == 0) dp[i][j] = 1;
            else {
                int up = 0, left = 0;
                if(i > 0 && mat[i-1][j] != -1) up = dp[i-1][j];
                if(j > 0 && mat[i][j-1] != -1) left = dp[i][j-1];
                dp[i][j] = (up + left) % mod;
            }
        }
    }   
    return dp[n-1][m-1];
}

 Triangle -->

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}

https://bit.ly/3F436dK - > Maximum Path Sum in the matrix

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0) dp[i][j] = matrix[i][j];
            else{
                int up = INT_MIN, left = INT_MIN, right = INT_MIN;
                if(j > 0) left = dp[i-1][j-1];
                if(j < m-1) right = dp[i-1][j+1];
                up = dp[i-1][j];
                dp[i][j] = matrix[i][j] + max(up, max(left, right));
            }
        }
    } 
    int ans = INT_MIN;
    for(int i = 0; i < m; i++) ans = max(ans, dp[n-1][i]);
    return ans;
}

