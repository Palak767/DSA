class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int maxLen = 0;
        for(int x : arr){
            int prev = x - difference;
            dp[x] = dp[prev] + 1;
            maxLen = max(maxLen,dp[x]);
        }
        return maxLen;
    }
};