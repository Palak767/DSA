class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int slow = 0, high = 1, ans = 0;
        while(high < n){
            if(nums[slow] == nums[high]) ans = nums[slow];
            slow++;
            high++;
        }
        return ans;
    }
};