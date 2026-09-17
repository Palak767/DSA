class Solution {
public:
    bool solve(string s1, string s2, string s3,int i,int j,vector<vector<int>>& dp){
        int m = s1.size();
        int n = s2.size();
        int x = s3.size();
        if(i == m && j == n) return true;
        if(dp[i][j] != -1) return dp[i][j];
        int k = i + j;
        bool res = false;
        if(i < m && s1[i] == s3[k]){
            res = solve(s1,s2,s3,i+1,j,dp);
        }
        if(!res && j < n && s2[j] == s3[k]){
            res = solve(s1,s2,s3,i,j+1,dp);
        }
        return dp[i][j] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int x = s3.size();
        if(m + n != x) return false;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,s3,0,0,dp);
    }
};