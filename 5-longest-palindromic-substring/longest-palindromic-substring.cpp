class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        if(i >= j) return true;
        if(s[i] != s[j]) return false;
        return isPalindrome(s,i+1,j-1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;
        for(int len=n;len>=0;len--){
            for(int i=0;i<=n-len;i++){
                int j = i + len - 1;
                if(isPalindrome(s,i,j)){
                    return s.substr(i,len);
                }
            }
        }
        return "";
    }
};