class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> groups;
        
        for(string& word : words) {
            vector<int> even(26, 0), odd(26, 0);
            
            for(int i=0; i<word.length(); i++) {
                if(i % 2 == 0) even[word[i] - 'a']++;
                else odd[word[i] - 'a']++;
            }
            
            string key = string(odd.begin(), odd.end()) + string(even.begin(), even.end());
            groups.insert(key);
        }
        
        return groups.size();
    }
};