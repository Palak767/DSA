class Solution {
public:
    int solve(int i, int j,vector<int>& cuts, vector<vector<int>>& dp){
        int n = cuts.size();
        if(j-i <= 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int minCuts = INT_MAX;
        for(int k=i+1;k<j;k++){
            int cost = solve(i,k,cuts,dp) + solve(k,j,cuts,dp) + cuts[j] - cuts[i];
            minCuts = min(minCuts,cost);
        }
        return dp[i][j] = minCuts;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(103,vector<int>(103,-1));
        return solve(0,cuts.size()-1,cuts,dp);
    }
};