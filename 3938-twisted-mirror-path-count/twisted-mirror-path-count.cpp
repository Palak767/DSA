class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int i, int j, int dir, vector<vector<int>>& grid, vector<vector<vector<long long>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
            return 1;
        if (dp[i][j][dir] != -1)
            return dp[i][j][dir];
        long long ans = 0;
        if (grid[i][j] == 0) {
            ans = solve(i, j + 1, 0, grid, dp) +
                  solve(i + 1, j, 1, grid, dp);
        }
        else {
            if (dir == 0)
                ans = solve(i + 1, j, 1, grid, dp);
            else
                ans = solve(i, j + 1, 0, grid, dp);
        }
        return dp[i][j][dir] = ans % MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(2,-1)));
        return solve(0,0,0,grid,dp);
    }
};