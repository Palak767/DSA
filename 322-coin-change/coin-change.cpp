class Solution {
public:
    int solve(vector<int>& coins, int amount,int i,vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(i < 0) return 1e9;
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = 1e9;
        int skip = solve(coins,amount,i-1,dp);
        if(coins[i] <= amount){
            take = 1 + solve(coins,amount-coins[i],i,dp);
        }
        return dp[i][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans = solve(coins,amount,n-1,dp);
        return (ans>=1e9)?-1:ans;
    }
};