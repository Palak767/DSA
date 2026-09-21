class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<vector<int>> dp(numRows,vector<int>(numRows,0));
        dp[0][0] = 1;
        for(int i=0;i<numRows;i++){
            vector<int> row;
            for(int j=0;j<=i;j++){
                if(j == 0 || j == i){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                row.push_back(dp[i][j]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};