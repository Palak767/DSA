class Solution {
public:
    string removeOuterParentheses(string s) { // optimal
        string ans = "";
        int count = 0;
        for(int c : s){
            if(c == '(') {
                if(count > 0){
                    ans += c;
                }
                count++;
            }else{
                count--;
                if(count > 0){
                    ans += c;
                }
            }
        }
        return ans;
    }
};