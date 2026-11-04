class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n = nums.size();
        int left = 0, oddCnt = 0, cnt = 0;
        for(int right=0;right<n;right++){
            if(nums[right] % 2 != 0) oddCnt++;
            while(oddCnt > k){
                if(nums[left] % 2 != 0) oddCnt--;
                left++;
            }
            cnt += right-left+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return solve(nums,k) - solve(nums,k-1);
    }
};