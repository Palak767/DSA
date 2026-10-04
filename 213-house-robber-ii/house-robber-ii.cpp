class Solution {
public:
    int solve(vector<int>& nums,int start,int i,vector<int>& dp){
        if(i < start) return 0;
        if(i == start) return nums[start];
        if(dp[i] != -1) return dp[i];
        int skip = solve(nums,start,i-1,dp);
        int rob = solve(nums,start,i-2,dp) + nums[i];
        return dp[i] = max(skip,rob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int case1 = solve(nums,0,n-2,dp1);
        int case2 = solve(nums,1,n-1,dp2);
        return max(case1,case2);
    }
};