class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(int it : st){
            if(st.find(it-1) == st.end()){
                int count = 1;
                int curr = it;
                while(st.find(curr+1) != st.end()){
                    curr++;
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};