class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        grid[i][j] = 0;
                    }
                }
            }
        }
        vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(auto& [dr,dc] : dir){
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    q.push({nr,nc});
                    grid[nr][nc] = 0;
                }
            }
        }
        int enclaves = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) enclaves++;
            }
        }
        return enclaves;
    }
};