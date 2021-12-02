class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if(pattern.size() != (count(s.begin(), s.end(), ' ') + 1))
            return false;
        
        unordered_map<char, string> check1;
        unordered_map<string, int> check2;
        
        istringstream ss(s);
        string word;
        
        for(auto i : pattern){
            ss >> word;
            
            if((check1[i] == "" && check2[word] == 0) || check1[i] == word){
                check1[i] = word;
                check2[word] = i;
            }
            
            else return false;
        }
        
        return true;
    }
};