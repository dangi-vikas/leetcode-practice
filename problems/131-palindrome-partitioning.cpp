class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> container;
 
        partitionRec(s, ans, container, 0);
        
        return ans;
    }
    
    void partitionRec(string& s, vector<vector<string>>& ans, vector<string>& container, int index){
        
        //base condition
        if(index == s.size()) {
            ans.push_back(container);
            return;
        }
        
        //iterating through string
        for(int i=index; i<s.size(); i++) {
            if(isPalindrome(s, index, i)) {

                //inserting a palindromic substring
                container.push_back(s.substr(index, i-index+1));

                //recursively funding others substrings
                partitionRec(s, ans, container, i+1);

                //backtracking step
                container.pop_back();  
            }
        }
    }
    
    //function to check if the string is palindrome
    bool isPalindrome(string& str, int l, int r) {
        while(l<=r) {
            if(str[l++] != str[r--]) 
                return false;
        }
        
        return true;
    }
};
