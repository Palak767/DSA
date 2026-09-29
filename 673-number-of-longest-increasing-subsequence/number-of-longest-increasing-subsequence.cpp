class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxLen = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i] < nums[j]){
                    if(1 + dp[j] > dp[i]){
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    }else if(1 + dp[j] == dp[i]){
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen,dp[i]);
        }
        int totalNumber = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxLen){
                totalNumber += count[i];
            }
        }
        return totalNumber;
    }
};