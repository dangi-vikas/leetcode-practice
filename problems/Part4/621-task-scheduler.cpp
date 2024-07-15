class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        unordered_map<char, int> freq;
        
        for(auto &task : tasks) freq[task]++;
        
        vector<pair<int, char>> frequencies;
        int n = freq.size();
        frequencies.reserve(n);
         
        for(auto &it : freq) 
          frequencies.push_back({it.second, it.first});
        
        sort(frequencies.begin(), frequencies.end(), [](auto &p1, auto &p2) {
            return p1.first > p2.first; 
        });
        
        int maxFreq = frequencies[0].first;
        int idleTime = (maxFreq - 1) * k; 
        
        for (int i=1; i<n; i++) 
          idleTime -= min(maxFreq - 1, frequencies[i].first);
        
        return max(0, idleTime) + tasks.size();
    }
};
