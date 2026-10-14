class Solution {
public:
    int minChanges(int i, int j, string s){
        int change = 0;
        while(i < j){
            if(s[i] != s[j]){
                change++;
            }
            i++;
            j--;
        }
        return change;
    }
    int solve(int i, int k, string s, vector<vector<int>>& dp){
        int n = s.size();
        if(k == 1){
            return minChanges(i,n-1,s);
        }
        if(dp[i][k] != -1) return dp[i][k];
        int ans = INT_MAX;
        for(int j=i;j<=n-k;j++){
            int changes = minChanges(i,j,s) + solve(j+1,k-1,s,dp);
            ans = min(ans,changes);
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return solve(0,k,s,dp);
    }
};