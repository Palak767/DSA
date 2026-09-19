class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int clos = nums[0] + nums[1] + nums[2];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int curr = nums[i] + nums[j] + nums[k];
                    if(abs(target - curr) < abs(target - clos)){
                        clos = curr;
                    }
                }
            }
        }
        return clos;
    }
};