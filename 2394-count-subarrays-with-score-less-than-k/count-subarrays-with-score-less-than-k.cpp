class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long left = 0, cnt = 0, sum = 0, score = 1;
        for(int right=0;right<n;right++){
            sum += nums[right];
            score = sum * (right-left+1);
            while(score >= k){
                sum -= nums[left];
                left++;
                score = sum * (right-left+1);
            }
            cnt += right-left+1;
        }
        return cnt;
    }
};