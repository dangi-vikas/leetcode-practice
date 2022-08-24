class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        unordered_map<char, int> freq;
        
        for(auto w: words[0]) freq[w]++;
        
        for(string word : words){
            unordered_map<char, int> freq2;
            
            for(char w : word)
                if(freq[w] != 0 && freq2[w]< freq[w])
                    freq2[w]++; 
            
            for(auto fr: freq) freq[fr.first] = freq2[fr.first];
        }
        
        for(auto fr : freq)
            for(int i = 0 ; i < fr.second;i++)
                ans.push_back({fr.first });
        
        return ans;
    }
};