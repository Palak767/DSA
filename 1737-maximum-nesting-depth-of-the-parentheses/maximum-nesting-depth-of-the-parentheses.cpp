class Solution {
public:
    int maxDepth(string s) { //sub-optimal(stack is not needed to solve this essentially)
        int curr_depth = 0;
        int max_depth = 0;
        stack<char> st;
        for(char c : s){
            if(c == '('){
                st.push(c);
                curr_depth++;
                max_depth = max(max_depth,curr_depth);
            }else if(c == ')'){
                if(!st.empty()){
                    st.pop();
                    curr_depth--;
                }
            }
        }
        return max_depth;
    }
};