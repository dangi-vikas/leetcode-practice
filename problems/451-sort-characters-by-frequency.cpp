class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> count('z' + 1, {0, 0});
        
        for(char ch : s)
            count[ch] = {count[ch].first + 1, ch};
        
        sort(count.begin(), count.end());
        
        string ans = "";
        
        for(auto p : count)
            ans = string(p.first, p.second) + ans;
        
        return ans;
    }
};