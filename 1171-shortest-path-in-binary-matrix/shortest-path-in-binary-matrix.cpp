class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; 
        queue<array<int, 3>> que;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<pair<int,int>> dir = {{-1,-1}, {0,1},{0,-1},{1,-1},{-1,0},{1,0},{1,1},{-1,1}};
        vis[0][0] = 1;
        que.push({0,0,1});
        while(!que.empty()){
            auto [r,c,d] = que.front();
            que.pop();
            if(r == n-1 && c == n-1) return d;
            for(auto[dr,dc] : dir){
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    que.push({nr,nc,d+1});
                }
            }
        }
        return -1;
    }
};