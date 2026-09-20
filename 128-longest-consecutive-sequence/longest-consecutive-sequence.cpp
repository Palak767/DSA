class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int longest = 1;
        int cnt = 0;
        int lstSmall = INT_MIN;
        if(nums.size() == 0) return 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] - 1 == lstSmall){
                cnt++;
                lstSmall = nums[i];
            }else if(nums[i] != lstSmall){
                cnt = 1;
                lstSmall = nums[i];
            }
            longest = max(longest,cnt);
        }
        return longest;
    }
};