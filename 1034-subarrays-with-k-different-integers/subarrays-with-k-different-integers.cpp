class Solution {
public:
    int solve(vector<int>& nums, int x){
        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0, cnt = 0;
        for(int right=0; right<n; right++){
            mp[nums[right]]++;
            while(mp.size() > x){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            cnt += right-left+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
    }
};