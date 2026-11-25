class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        vector<pair<int,int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
        queue<vector<int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }else if(grid[i][j] == 1) fresh++;
            }
        }
        int maxTime = 0;
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            int r = curr[0];
            int c = curr[1];
            int t = curr[2];
            maxTime = max(maxTime, t);
            for(auto [dr,dc] : dir){
                int nr = r + dr;
                int nc = c + dc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr,nc,t+1});
                }
            }
        }
        return fresh == 0 ? maxTime : -1; 
    }
};