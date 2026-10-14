class Solution {
public:
    int solve(int i, int k, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        if(k == 1){
            int sum = 0;
            for(int t=i;t<n;t++){
                sum += nums[t];
            }
            return sum;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int currSum = 0;
        int ans = INT_MAX;
        for(int j=i;j<=n-k;j++){
            currSum = currSum + nums[j];
            int remainingSum = solve(j+1,k-1,nums,dp);
            int largerSum = max(remainingSum,currSum);
            ans = min(ans,largerSum);
        }
        return dp[i][k] = ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(0,k,nums,dp);
    }
};