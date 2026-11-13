class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, currZero = 0, maxZero = 0;
        for(int right=0; right<n; right++){
            if(nums[right] == 0) currZero++;
            while(currZero > k){
                if(nums[left] == 0) currZero--;
                left++;
            }
            maxZero = max(maxZero, right-left+1);
        }
        return maxZero;
    }
};