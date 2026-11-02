class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(i >= n-1) return 0;
        if(nums[i] == 0) return 1e9;
        if(dp[i] != -1) return dp[i];
        int jumps = 1e9;
        for(int step=1;step<=nums[i];step++){
            jumps = min(jumps,1+solve(i+step,nums,dp));
        }
        return dp[i] = jumps;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(0,nums,dp);
    }
};