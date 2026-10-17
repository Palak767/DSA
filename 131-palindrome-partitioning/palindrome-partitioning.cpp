class Solution {
public:
    bool isPal(int i, int j, string s){
        if(i > j) return false;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(int idx, string s, vector<string>& output, vector<vector<string>>& res){
        if(idx == s.size()){
            res.push_back(output);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPal(idx,i,s)){
                output.push_back(s.substr(idx,i-idx+1));
                backtrack(i+1,s,output,res);
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        backtrack(0,s,output,ans);
        return ans;
    }
};