class Solution {
    vector<string> ans;
    
public:
    vector<string> removeInvalidParentheses(string s) {
        if(s.size() == 0) return ans;
	
        int left = 0, right = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') left++;
           
            else if(s[i] == ')') {
                if(left > 0) left--;
                else right++;
            }   
        }

        removeInvalidParenthesesRec(s, 0, left, right);

        return ans;
    }
    
    bool isValid(string &s) { 
        int pair = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') pair++;
            
            else if(s[i] == ')') {
                pair--;
                if(pair < 0) return false;
            } 
        }

        return pair == 0;
    }
    
    void removeInvalidParenthesesRec(string input, int index, int left, int right){
        if(left == 0 && right == 0) {
            if(isValid(input)) ans.push_back(input);
            return;
        }

        for(int i=index; i<input.size(); i++) {
            if(i > index && input[i] == input[i-1]) continue;
            string str = input;

            if(right == 0 && left > 0 && input[i] == '(') {
                 str.erase(i, 1);
                 removeInvalidParenthesesRec(str, i, left-1, right);
            }
            
            else if(right > 0 && input[i] == ')') {
                str.erase(i, 1);
                removeInvalidParenthesesRec(str, i, left, right-1);
            }
        }
    }
};