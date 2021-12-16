class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;

        if(ransomNote.length() > magazine.length()) return false;
        
        for(auto &ch : magazine) map[ch]++;

        for(auto &ch : ransomNote) 
        {
            if(map[ch]) map[ch]--;
            else return false;
        }

        return true;
    }
};
