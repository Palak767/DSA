class Solution {
public:
    void solve(int i , vector<int>& candidates, int target, vector<int>& currPath, vector<vector<int>>& res){
        int n = candidates.size();
        if(target == 0){
            res.push_back(currPath);
            return;
        }
        if(target < 0 || i == n) return;
        currPath.push_back(candidates[i]);
        solve(i,candidates,target-candidates[i],currPath,res);
        currPath.pop_back();
        solve(i+1,candidates,target,currPath,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> currPath;
        solve(0,candidates,target,currPath,res);
        return res;
    }
};