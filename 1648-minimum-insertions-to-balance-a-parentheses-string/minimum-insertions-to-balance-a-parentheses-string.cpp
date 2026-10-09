class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int res = 0;
        for(char c : s){
            if(c == '('){
                if(insertions % 2 != 0){
                    insertions--;
                    res++;
                }
                insertions += 2;
            }else{
                insertions--;
                if(insertions < 0){
                    insertions += 2;
                    res++;
                }
            }
        }
        return res + insertions;
    }
};