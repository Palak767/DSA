class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int n = nums.size();
        if(goal < 0) return 0;
        long long left = 0, sum = 0, cnt = 0;
        for(int right=0;right<n;right++){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            cnt += right-left+1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal-1);
    }
};