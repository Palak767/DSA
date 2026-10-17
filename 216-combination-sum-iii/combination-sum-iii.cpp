class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& output, vector<vector<int>>& combinations){
        if(output.size() == k && n == 0){
            combinations.push_back(output);
            return;
        }
        if(output.size() > k || n < 0) return;
        for(int i=start;i<=9;i++){
            output.push_back(i);
            backtrack(i+1,k,n-i,output,combinations);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> output;
        backtrack(1,k,n,output,combinations);
        return combinations;
    }
};