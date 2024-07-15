    class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        
        letterCasePermutationRec(s, 0, ans);
        
        return ans;
    }
    
    void letterCasePermutationRec(string& s, int idx, vector<string>& ans) {
        if(idx >= s.length()) {
            ans.push_back(s);
            return;
        }
        
        letterCasePermutationRec(s, idx+1, ans);
        
        if(isalpha(s[idx])) {
            if(islower(s[idx])) {
                s[idx] = toupper(s[idx]);
                letterCasePermutationRec(s, idx+1, ans);
                s[idx] = tolower(s[idx]);
            }
            
            else {
                s[idx] = tolower(s[idx]);
                letterCasePermutationRec(s, idx+1, ans);
                s[idx] = toupper(s[idx]);
            }
        }
    }
};