class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int cndt1 = INT_MIN, cndt2 = INT_MIN;
        for(int num : nums){
            if(num == cndt1) cnt1++;
            else if(num == cndt2) cnt2++;
            else if(cnt1 == 0){
                cndt1 = num;
                cnt1 = 1;
            }else if(cnt2 == 0){
                cndt2 = num;
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int num : nums){
            if(num == cndt1) cnt1++;
            else if(num == cndt2) cnt2++;
        }
        vector<int> ans;
        if(cnt1 > n/3) ans.push_back(cndt1);
        if(cnt2 > n/3) ans.push_back(cndt2);
        return ans;
    }
};