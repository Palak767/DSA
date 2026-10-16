class Solution {
public:
vector<vector<int>> subsets;
vector<int> output;
    void solve(int idx, vector<int>& nums){
        subsets.push_back(output);
        for(int i=idx;i<nums.size();i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            output.push_back(nums[i]);
            solve(i+1,nums);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        solve(0,nums);
        return subsets;
    }
};