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
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s,p,0,0,dp);
    }
};