class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};

// Print subarray

// int print(vector<int>& nums){
// int n = nums.size();
// int maxi = INT_MIN;
// int sum = 0;

// int start = 0;
// int ansSt = -1;
// int ansEnd = -1;
// for(int i=0;i<n;i++){
//     i(sum == 0){
//         start = i;
//     }
//     sum += nums[i];
//     if(sum > maxi){
//         maxi = sum;
//         ansSt = start;
//         ansEnd = i;
//     }
//     if(sum < 0){
//         sum = 0;
//     }
// }
// cout<<"Max SubArray : [";
// for(int i=ansSt;i<=ansEnd;i++){
//     cout<<nums[i]<<(i == ansEnd ? "" : ", ");
// }
// cout<<"]"<<endl;
// return maxi;
// }
