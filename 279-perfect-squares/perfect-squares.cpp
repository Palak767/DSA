class Solution {
public:
    int solve(int n,int i,vector<vector<int>>& dp){
        if(n == 0) return 0;
        if(i <= 0) return 1e9;
        if(dp[i][n] != -1) return dp[i][n];
        int take = 1e9;
        int skip = solve(n,i-1,dp);
        if(i*i <= n){
            take = 1 + solve(n-i*i,i,dp);
        }
        return dp[i][n] = min(take,skip);
    }
    int numSquares(int n) {
        int x = sqrt(n);
        vector<vector<int>> dp(x+1,vector<int>(n+1,-1));
        return solve(n,x,dp);
    }
};