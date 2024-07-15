class Solution {
public:
    vector<string> letterCombinations(string digits) {

        //mapping the alphabets with the key number(index of array)
        string keys[10] = {"0", "1", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> ans;
        string str;
        
        //if the string is empty return []
        if(digits == "") return ans;
        
        letterCombinations(keys, ans, str, 0, digits);
        
        return ans;
    }
    
    //backtracking helper function
    void letterCombinations(string keys[], vector<string>& ans, string& str, 
                             int ind, string& digits){
        
        //base condition: if the ind reaches digits string's size then we push the string in ans array
        if(ind == digits.size()) ans.push_back(str);

        //runs till all the alphabets associated perticular number are traversed
        for(int i=0; i<keys[digits[ind]-'0'].size(); i++) {
            
            //pushing the alphabets associated with the number in string
            str.push_back(keys[digits[ind]-'0'][i]);

            //recursively traversing all the alphabets associated with next number in digits
            letterCombinations(keys, ans, str, ind+1, digits);

            //backtracking step: removing the last number added, after each step to check the next one
            str.pop_back();
        }  
    }
};