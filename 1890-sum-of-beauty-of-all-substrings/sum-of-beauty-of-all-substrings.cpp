class Solution {
public:
    int beautySum(string s) {   // brute force using hash map
        int n = s.size();
        int totalBeauty = 0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
                int maxFreq = 0;
                int minFreq = INT_MAX;
                for(auto& pair : freq){
                    maxFreq = max(maxFreq,pair.second);
                    minFreq = min(minFreq,pair.second);
                }
                totalBeauty += (maxFreq - minFreq);
            }
        }
        return totalBeauty;
    }
};