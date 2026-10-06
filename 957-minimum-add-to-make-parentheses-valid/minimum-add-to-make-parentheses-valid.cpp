class Solution {
public:
    int minAddToMakeValid(string s) { // sub-optimal sol
        int count = 0;
        stack<char> st;
        for(char c : s){
            if(c == '('){
                st.push(c);
            }else{
                if(!st.empty()){
                    st.pop();
                }else{
                    count++;
                }
            }
        }
        return count + st.size();
    }
};