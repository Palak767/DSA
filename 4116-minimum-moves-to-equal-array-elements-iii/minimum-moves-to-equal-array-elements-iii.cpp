class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int moves = 0;
        int target = *std::max_element(nums.begin(),nums.end());
        for(int num : nums){
            moves += abs(target - num);
        }
        return moves;
    }
};