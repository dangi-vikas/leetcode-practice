class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> freq;
        string temp;
        
        for (char ch : paragraph) {
            if (isalpha(ch) && ch != ' ') temp += (ch | 32);
            
            else {
                if (!temp.empty() && !isBanned(temp, banned)) freq[temp]++;
                temp = "";
            }
        }
        
        if (!temp.empty() && !isBanned(temp, banned)) 
                freq[temp]++;
        
        int currFreq = 0;
        for (const pair<string, int>& p : freq) {
            if (currFreq < p.second) {
                currFreq = p.second;
                temp = p.first;
            }
        }
        
        return temp;
    }
    
    bool isBanned(const string& s, const vector<string>& banned) {
        for (const string& b : banned) 
            if (s.compare(b) == 0) return true;
        
        return false;
    }
};