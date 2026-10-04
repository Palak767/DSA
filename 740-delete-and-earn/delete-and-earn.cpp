class Solution {
public:
    int solve(vector<int>& total,int x,vector<int>& dp){
        if(x>=total.size()) return 0;
        if(dp[x] != -1) return dp[x];
        return dp[x] = max(total[x] + solve(total,x+2,dp),solve(total,x+1,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = std::ranges::max(nums);
        vector<int> total(maxVal+1,0);
        for(int x:nums){
            total[x] += x;
        }
        vector<int> dp(maxVal+1,-1);
        return solve(total,0,dp);
    }
};