class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp, mp1;
        string Q = "";
        vector<string> P;
        
        for(int i=0; i<s1.length(); i++) {
            if(s1[i] == ' ') {
                mp[Q]++;
                Q = "";
            }
            
            else Q += s1[i];
        }
        
        mp[Q]++;
        Q = "";
        
        for(int i=0; i<s2.length(); i++){
            if(s2[i] == ' ') {
                mp1[Q]++;
                Q = "";
            }
            else Q += s2[i];
        }
        
        mp1[Q]++;
        
        for(auto i : mp) {
            if(mp1[i.first] == 0 && i.second == 1) P.push_back(i.first);
        }
        
        for(auto i : mp1) {
            if(mp[i.first] == 0 && i.second == 1) P.push_back(i.first);
        }
        
        return P;
    }
};
