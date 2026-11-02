class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e9);
        dp[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            int maxReach = min(n-1, i+nums[i]);
            for(int step=i+1; step <= maxReach; step++){
                dp[i] = min(dp[i],1+dp[step]);
            }
        }
        return dp[0];
    }
};