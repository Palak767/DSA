class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<tuple<int,int,int>> q;
        vector<vector<int>> dist(m,vector<int>(n,-1));
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto [r,c,d] = q.front();
            q.pop();
            for(auto [dr,dc] : dir){
                int nr = r + dr, nc = c + dc;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] == -1){
                    q.push({nr,nc,d+1});
                    dist[nr][nc] = d + 1;
                }
            }
        }
        return dist;
    }
};