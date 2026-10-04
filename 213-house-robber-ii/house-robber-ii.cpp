class Solution {
public:
    int solve(vector<int>& nums,int start,int end){
        int length = end - start + 1;
        if(length == 1) return nums[start];
        int prev2 = nums[start];
        int prev1 = max(nums[start],nums[start+1]);
        for(int i=2;i<length;i++){
            int curr = max(prev1, prev2 + nums[start + i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int case1 = solve(nums,0,n-2);
        int case2 = solve(nums,1,n-1);
        return max(case1,case2);
    }
};