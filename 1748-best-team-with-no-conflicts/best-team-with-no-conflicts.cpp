class Solution {
public:
    int solve(int i, int prev, vector<pair<int,int>>& players,vector<vector<int>>& dp){
        int n = players.size();
        if(i >= n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int skip = solve(i+1,prev,players,dp);
        int take = 0;
        if(prev == -1 || players[i].first >= players[prev].first){
            take = solve(i+1,i,players,dp) + players[i].first;
        }
        return dp[i][prev+1] = max(take,skip);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> players(n);
        for(int i=0;i<n;i++){
            players[i] = {scores[i],ages[i]};
        }
        sort(players.begin(),players.end(),[](pair<int,int>& a, pair<int,int>& b){
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,players,dp);
    }
};