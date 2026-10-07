class Solution {
public:
vector<vector<bool>> isPal;
    void buildPalindromeTable(string& s, int n){
        isPal.assign(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i] == s[j] && (j-i <= 2 || isPal[i+1][j-1])){
                    isPal[i][j] = true;
                }
            }
        }
    }
    int solve(int i, int n, vector<int>& dp){
        if(i == n) return 0;
        int minCuts = INT_MAX;
        if(dp[i] != -1) return dp[i];
        for(int j=i;j<n;j++){
            if(isPal[i][j]){
                minCuts = min(minCuts,1+solve(j+1,n,dp));
            }
        }
        return dp[i] = minCuts;
    }
    int minCut(string s) {
        int n = s.size();
        buildPalindromeTable(s,n);
        vector<int> dp(n,-1);
        return solve(0,n,dp)-1;
    }
};