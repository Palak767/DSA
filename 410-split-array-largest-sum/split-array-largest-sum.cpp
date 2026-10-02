class Solution {
public:
    bool canSplit(vector<int>& nums, int k, int maxSum){
        int subArr_cnt = 1;
        int currSum = 0;
        for(int num : nums){
            if(currSum + num > maxSum){
                subArr_cnt++;
                currSum = num;
            }else{
                currSum += num;
            }
        }
        return subArr_cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low = std::ranges::max(nums);
        long long high = std::accumulate(nums.begin(),nums.end(),0);
        long long ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canSplit(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};