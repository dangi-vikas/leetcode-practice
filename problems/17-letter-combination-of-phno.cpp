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
        
        letterCombinationsT(keys, ans, str, 0, digits);
        
        return ans;
    }
    
    //backtracking helper function
    void letterCombinationsT(string keys[], vector<string>& ans, string& str, 
                             int index, string& digits){
        
        //base condition: if the index reaches digits string's size then we push the string in ans array
        if(index == digits.size()) ans.push_back(str);

        else
            
            //runs till all the alphabets associated perticular number are traversed
            for(int i=0; i<keys[digits[index]-'0'].size(); i++){
                
                //pushing the alphabets associated with the number in string
                str.push_back(keys[digits[index]-'0'][i]);

                //recursively traversing all the alphabets associated with next number in digits
                letterCombinationsT(keys, ans, str, index+1, digits);

                //backtracking step: removing the last number added, after each step to check the next one
                str.pop_back();
            }
    }
};