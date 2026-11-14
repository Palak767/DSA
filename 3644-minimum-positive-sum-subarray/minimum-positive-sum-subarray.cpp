class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;
        for(int i=l; i<=r; i++){
            int left = 0, currSum = 0;
            for(int right=0; right<n; right++){
                currSum += nums[right];
                if(right-left+1 > i){
                    currSum -= nums[left];
                    left++;
                }
                if(right-left+1 == i && currSum > 0){
                    minSum = min(minSum, currSum);
                }
            }
        }
        return minSum == INT_MAX ? -1 : minSum;
    }
};