class Solution {
public:
    void row(vector<vector<int>>& matrix,int i,int n){
        for(int j=0;j<n;j++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -999999;
            }
        }
    }
    void col(vector<vector<int>>& matrix,int j,int m){
        for(int i=0;i<m;i++){
            if(matrix[i][j] != 0){
                matrix[i][j] = -999999;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    row(matrix,i,n);
                    col(matrix,j,m);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -999999){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};