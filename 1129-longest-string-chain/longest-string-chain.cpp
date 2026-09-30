class Solution {
public:
    bool isPredecessor(string& a, string& b){
        if(b.size() != a.size() + 1) return false;
        int i=0, j=0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
            }
            j++;
        }
        return i == a.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[](string& a, string& b){
            return a.size() < b.size();
        });
        vector<int> dp(n,1); // dp[i] represents the longest valid word chain that ends exactly at words[i]
        int maxChain = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(words[i].size() - words[j].size() > 1) continue;
                if(isPredecessor(words[j],words[i])){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            maxChain = max(maxChain,dp[i]);
        }
        return maxChain;
    }
};