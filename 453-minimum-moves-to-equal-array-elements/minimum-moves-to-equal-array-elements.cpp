class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int target = *std::min_element(nums.begin(),nums.end());
        long long moves = 0;
        for(int num : nums){
            moves += num - target;
        }
        return moves;
    }
};