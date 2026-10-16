class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& output, vector<vector<int>>& res){
        if(i >= nums.size()){
            res.push_back(output);
            return;
        }
        solve(i+1,nums,output,res);
        output.push_back(nums[i]);
        solve(i+1,nums,output,res);
        output.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        solve(0,nums,output,res);
        return res;
    }
};