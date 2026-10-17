class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int idx){
        int m = board.size();
        int n = board[0].size();
        int x = word.size();
        if(idx == x){
            return true;
        }
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(i+1,j,board,word,idx+1) || dfs(i-1,j,board,word,idx+1) || dfs(i,j+1,board,word,idx+1) ||dfs(i,j-1,board,word,idx+1);
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0] && dfs(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};