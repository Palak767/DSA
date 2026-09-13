class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    triplets.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }else if(sum < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return triplets;
    }
};
   
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> triplets;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(i == j) continue;
//                 for(int k=0;k<n;k++){
//                     if(k == i || j == k) continue;
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         vector<int> temp = {nums[i],nums[j],nums[k]};
//                         sort(temp.begin(),temp.end());
//                         triplets.insert(temp);
//                     }
//                 }
//             }
//         }
//         return vector<vector<int>>(triplets.begin(),triplets.end());
//     }
// };