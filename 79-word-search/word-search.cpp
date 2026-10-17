class Solution {
public:
    void solve(int i, int j, vector<vector<char>>& board, string word, int idx, string& ans,string output){
        int m = board.size();
        int n = board[0].size();
        int x = word.size();
        if(idx == x){
            ans = output;
            return;
        }
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx] || board[i][j] == '#') return;
        char temp = board[i][j];
        board[i][j] = '#';
        output.push_back(temp);
        solve(i+1,j,board,word,idx+1,ans,output);
        solve(i-1,j,board,word,idx+1,ans,output);
        solve(i,j+1,board,word,idx+1,ans,output);
        solve(i,j-1,board,word,idx+1,ans,output);
        board[i][j] = temp;
        output.pop_back();
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        string ans = "";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    string output = "";
                    solve(i,j,board,word,0,ans,output);
                    if(ans == word){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};