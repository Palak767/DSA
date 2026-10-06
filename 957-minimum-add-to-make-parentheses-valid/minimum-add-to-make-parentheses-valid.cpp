class Solution {
public:
    int minAddToMakeValid(string s) { // optimal sol
        int unmatchedClose = 0;
        int unmatchedOpen = 0;
        for(char c : s){
            if(c == '('){
                unmatchedOpen++;
            }else{
                if(unmatchedOpen > 0){
                    unmatchedOpen--;
                }else{
                    unmatchedClose++;
                }
            }
        }
        return unmatchedClose + unmatchedOpen;
    }
};