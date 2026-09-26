class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_prod = INT_MIN;
        for(int i=0;i<n;i++){
            int curr_prod = 1;
            for(int j=i;j<n;j++){
                curr_prod *= nums[j];
                max_prod = max(max_prod,curr_prod);
            }
        }
        return max_prod;
    }
};