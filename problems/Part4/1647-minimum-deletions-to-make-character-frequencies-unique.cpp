class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> count;
        int deletions = 0;
        unordered_set<int> usedFrequencies;
        
        for(char c : s) count[c]++;
        
        for(auto& kv : count) {
            int freq = kv.second;

            while(freq > 0 && usedFrequencies.find(freq) != usedFrequencies.end()) {
                freq--;
                deletions++;
            }

            usedFrequencies.insert(freq);
        }
        
        return deletions;
    }
};
