class Solution {
public:
    vector<string> solve(string current, int open, int close, int n){
        if(current.size() == 2*n) return {current};
        vector<string> ans;
        if(open < n){
            vector<string> next = solve(current + "(", open+1,close,n);
            ans.insert(ans.end(),next.begin(),next.end());
        }
        if(close < open){
            vector<string> next = solve(current + ")", open, close+1, n);
            ans.insert(ans.end(),next.begin(),next.end());
        }
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        return solve("",0,0,n);
    }
};