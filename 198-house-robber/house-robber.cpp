class Solution {
public:
    int solve(vector<int>& nums, int i,vector<int>& dp){
        if(i < 0) return 0;
        int max_amt = INT_MIN;
        if(dp[i] != -1) return dp[i];
        int res = max(solve(nums,i-1,dp),solve(nums,i-2,dp)+nums[i]);
        return dp[i] = max(res,max_amt);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,n-1,dp);
    }
};