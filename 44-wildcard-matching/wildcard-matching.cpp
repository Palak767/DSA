class Solution {
public:
    bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp){
        int m = s.size();
        int n = p.size();
        if(j == n) return i == m;
        if(i == m){
            for(int k=j;k<n;k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool match = false;
        if(p[j] == s[i] || p[j] == '?'){
            match = solve(s,p,i+1,j+1,dp);
        }else if(p[j] == '*'){
            match = solve(s,p,i+1,j,dp) || solve(s,p,i,j+1,dp);
        }
        return dp[i][j] = match;
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        for(int j=1;j<=n;j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1] == s[i-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};