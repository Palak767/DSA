class Solution {
public:
    int solve(int i, int j, int currXOR, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m || j >= n) return 1e9;
        currXOR ^= grid[i][j];
        if(i == m-1 && j == n-1) return currXOR;
        if(dp[i][j][currXOR] != -1) return dp[i][j][currXOR];
        int right = solve(i,j+1,currXOR,grid,dp);
        int down = solve(i+1,j,currXOR,grid,dp);
        int ans = min(right,down);
        return dp[i][j][currXOR] = ans; 
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(1024,-1)));
        return solve(0,0,0,grid,dp);
    }
};