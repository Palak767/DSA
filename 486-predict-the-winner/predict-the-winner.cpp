class Solution {
public:
    int solve(int i, int j, vector<int>& nums, bool isPlayer1, vector<vector<vector<int>>>& dp){
        if(i == j) return nums[i];
        if(dp[i][j][isPlayer1] != -1) return dp[i][j][isPlayer1];
        if(isPlayer1){
            int left = nums[i] + solve(i+1,j,nums,false,dp);
            int right = nums[j] + solve(i,j-1,nums,false,dp);
            return dp[i][j][isPlayer1] = max(left,right);
        }else{
            int left = solve(i+1,j,nums,true,dp);
            int right = solve(i,j-1,nums,true,dp);
            return dp[i][j][isPlayer1] = min(left,right);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = std::accumulate(nums.begin(),nums.end(),0);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        int player1_score = solve(0,n-1,nums,true,dp);
        int player2_score = total_score - player1_score;
        return player1_score >= player2_score;
    }
};