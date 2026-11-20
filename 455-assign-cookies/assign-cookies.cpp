class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int low = 0, high = 0, cnt = 0;
        while(low < m && high < n){
            if(s[high] >= g[low]){
                cnt++;
                low++;
                high++;
            }
            else{
                high++;
            }
        }
        return cnt;
    }
};