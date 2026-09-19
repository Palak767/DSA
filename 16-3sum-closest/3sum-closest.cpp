class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int clos = nums[0] + nums[1] + nums[2];
        for(int i=0;i<n-2;i++){
            int left = i + 1;
            int right = n - 1;
            while(left < right){
                int curr = nums[i] + nums[left] + nums[right];
                if(abs(target - curr) < abs(target - clos)){
                    clos = curr;
                }
                if(curr < target){
                    left++;
                }else if(curr > target){
                    right--;
                }else{
                    return curr;
                }
            }
        }
        return clos;
    }
};