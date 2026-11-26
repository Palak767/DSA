class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int x = entrance[0], y = entrance[1];
        queue<array<int,3>> q;
        vector<vector<int>> vis(m,vector<int>(n,-1));
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        q.push({x,y,0});
        vis[x][y] = 1;
        while(!q.empty()){
            auto [r,c,s] = q.front();
            q.pop();
            if(s > 0 && (r == 0 || r == m-1 || c == 0 || c == n-1)) return s; 
            for(auto [dr,dc] : dir){
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == -1 && maze[nr][nc] == '.'){
                    q.push({nr,nc,s+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};