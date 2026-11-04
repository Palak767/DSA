class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp; 
        int left = 0, maxCnt = 0, maxLen = 0;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            maxCnt = max(maxCnt, mp[s[right]]);
            if((right-left+1) - maxCnt > k){
                mp[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};