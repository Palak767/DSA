class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int Len1 = 1, Len2 = 1, maxLen = 1;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                Len1++;
                Len2 = 1;
            }
            else if(nums[i] < nums[i-1]){
                Len2++;
                Len1 = 1;
            }else{
                Len1 = 1;
                Len2 = 1;
            }
            maxLen = max(maxLen, max(Len1,Len2));
        }
        return maxLen;
    }
};