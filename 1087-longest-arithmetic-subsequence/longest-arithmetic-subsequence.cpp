class Solution {
public:
    int solve(vector<int>& nums,int curr,int diff,vector<vector<int>>& dp){
        int n = nums.size();
        if(curr == nums.size()-1) return 0;
        int best = 0;
        if(dp[curr][diff+500] != -1) return dp[curr][diff+500];
        for(int k=curr+1;k<nums.size();k++){
            if(nums[k] - nums[curr] == diff){
                best = max(best,solve(nums,k,diff,dp)+1);
            }
        }
        return dp[curr][diff+500] = best;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 2;
        vector<vector<int>> dp(n,vector<int>(1001,-1));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[j] - nums[i];
                maxLen = max(maxLen,solve(nums,j,diff,dp)+2);
            }
        }
        return maxLen;
    }
};

// can be solved using hash map too