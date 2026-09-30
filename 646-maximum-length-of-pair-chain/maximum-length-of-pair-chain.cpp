class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int>& a,vector<int>& b){
            return a[1] < b[1];
        });
        int currEnd = -1001;
        int maxLen = 0;
        for(auto& pair : pairs){
            if(pair[0] > currEnd){
                maxLen++;
                currEnd = pair[1];
            }
        }
        return maxLen;
    }
};