class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, cnt = 0, prod = 1;
        for(int right=0;right<n;right++){
            prod *= nums[right];
            while(prod >= k && left <= right){
                prod /= nums[left];
                left++;
            }
            cnt += right-left+1;
        }
        return cnt;
    }
};