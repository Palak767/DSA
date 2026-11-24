class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int best = 2, left = 0, prod = 1;
        for(int right=0; right<n; right++){
            int x = nums[right];
            while(gcd(prod, x) > 1) prod /= nums[left++];
            prod *= x;
            best = max(best, right-left+1);
        }
        return best;
    }
};