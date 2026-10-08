class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<int>& dp){
        if(i >= arr.size()) return 0;
        int largestSum = -1;
        int len = 0;
        int res = INT_MIN;
        if(dp[i] != -1) return dp[i];
        for(int j=i;j<arr.size() && j<i+k;j++){
            largestSum = max(largestSum,arr[j]);
            len = j-i+1;
            int cost = largestSum*len + solve(j+1,arr,k,dp);
            res = max(res,cost);
        }
        return dp[i] = res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,k,dp);
    }
};