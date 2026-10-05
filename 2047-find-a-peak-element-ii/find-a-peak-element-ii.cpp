class Solution {
public:
    int findMaxRow(const std::vector<std::vector<int>>& mat, int m, int col){
        int maxRow = 0;
        for (int i=1;i<m;i++) {
            if (mat[i][col] > mat[maxRow][col]) {
                maxRow = i;
            }
        }
        return maxRow;
    }
    int getVal(vector<vector<int>>& mat, int r, int c, int m, int n){
        if(r < 0 || r >= m || c < 0 || c >= n) return -1;
        return mat[r][c];
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int maxRow = findMaxRow(mat,m,mid);
            int leftNeighbor = getVal(mat,maxRow,mid-1,m,n);
            int rightNeighbor = getVal(mat,maxRow,mid+1,m,n);
            if(mat[maxRow][mid] > leftNeighbor && mat[maxRow][mid] > rightNeighbor){
                return {maxRow,mid};
            }else if(mat[maxRow][mid] < rightNeighbor){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return {-1,-1};
    }
};