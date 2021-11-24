class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> count;
        
        for(int i=0; i<s.size(); i++){
            count[s[i]]++;
            count[t[i]]--;
        }
        
        /*if the count of a character is equal it second
          in count map will be zero*/
        for(auto i=count.begin(); i!=count.end(); ++i)
            if(i->second != 0) return false;
        
        return true;   
    }
};