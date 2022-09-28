class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> temp, ans;
        
        stringstream s(text);
        string word;
 
        while (s >> word) temp.push_back(word);
        
        for(int i=0; i<temp.size()-2; i++)
            if(temp[i] == first && temp[i+1] == second)
                ans.push_back(temp[i+2]);
        
        return ans;     
    }
};