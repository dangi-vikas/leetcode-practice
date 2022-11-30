class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        unordered_set<int> freqSet;
        
        for(int x : arr) freq[x]++;
        for(auto f : freq) freqSet.insert(f.second);
        
        return freq.size() == freqSet.size();
    }
};