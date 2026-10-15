class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int totalCnt = 0;
        for(int i=0;i<n;i++){
            unordered_set<int> distinctElements;
            for(int j=i;j<n;j++){
                distinctElements.insert(nums[j]);
                int cnt = distinctElements.size();
                totalCnt += cnt*cnt;
            }
        }
        return totalCnt;
    }
};