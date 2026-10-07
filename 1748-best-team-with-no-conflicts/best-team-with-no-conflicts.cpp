class Solution {
public:
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
        vector<int> dp(n+1,0);
        int maxScore = 0;
        for(int i=0;i<n;i++){
            dp[i] = players[i].first;
            for(int j=0;j<i;j++){
                if(players[i].first >= players[j].first){
                    dp[i] = max(dp[i],dp[j] + players[i].first);
                }
            }
            maxScore = max(maxScore,dp[i]);
        }
        return maxScore;
    }
};