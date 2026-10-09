class Solution {
public:
    int minInsertions(string s) {
        int needed_close = 0;  //Tracks required ')' balance
        int insertion = 0;  // Track actual added characters
        for(char c : s){
            if(c == '('){
                if(needed_close % 2 != 0){  // An odd needed_close means we have a single ')' waiting
                    needed_close--;
                    insertion++;  // Add 1 missing ')'
                }
                needed_close += 2;  // Each '(' expects '))'
            }else{
                needed_close--;
                if(needed_close < 0){
                    needed_close += 2;   // Insert a missing '('
                    insertion++;
                }
            }
        }
        return insertion + needed_close;
    }
};