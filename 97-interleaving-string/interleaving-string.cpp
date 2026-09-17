class Solution {
public:
    bool solve(string s1, string s2, string s3,int m,int n,vector<vector<int>>& dp){
        if(m == 0 && n == 0) return true;
        if(dp[m][n] != -1) return dp[m][n];
        int k = m + n - 1;
        bool res = false;
        if(m > 0 && s1[m-1] == s3[k]){
            res = solve(s1,s2,s3,m-1,n,dp);
        }
        if(!res && n > 0 && s2[n-1] == s3[k]){
            res = solve(s1,s2,s3,m,n-1,dp);
        }
        return dp[m][n] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int x = s3.size();
        if(m + n != x) return false;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,s3,m,n,dp);
    }
};