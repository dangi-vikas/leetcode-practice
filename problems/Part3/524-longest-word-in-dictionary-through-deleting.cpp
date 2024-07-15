class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        
        for(string str : dictionary) {
            if(isSubsequence(str, s)) {
                if(str.size()>ans.size() || str.size()==ans.size() && str<ans)
                    ans = str;
            }
        }
        
        return ans;
    }
    
    bool isSubsequence(string str1, string str2) {
        int i=0, j=0;
        
        if(str1.size() > str2.size()) return false;
        
        while(i < str2.size() && j < str1.size()) {
            if(str2[i] == str1[j]) j++;
            i++;
        }
        
        return j == str1.size();
    }
};