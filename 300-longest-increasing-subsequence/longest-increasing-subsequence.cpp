class Solution {
public:
    int solve(vector<int>& nums,int i,vector<int>& dp){
        int ans = 1;
        if(dp[i] != -1) return dp[i];
        for(int j=i+1;j<nums.size();j++){
            if(nums[i] < nums[j]){
                ans = max(ans,1+solve(nums,j,dp));
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,solve(nums,i,dp));
        }
        return ans;
    }
};