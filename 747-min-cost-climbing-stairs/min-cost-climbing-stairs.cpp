class Solution {
public:
    int solve(int n,vector<int>& cost,vector<int>& dp){
        if(n <= 1) return cost[n];
        if(dp[n] != -1) return dp[n];
        int oneStep = cost[n] + solve(n-1,cost,dp);
        int twoStep = cost[n] + solve(n-2,cost,dp);
        return dp[n] = min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        return min(solve(n-1,cost,dp),solve(n-2,cost,dp));
    }
};