class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> target(26, 0);
        
        for(string word : words2) {
            vector<int> temp(26, 0);
            
            for(char ch : word) {
                temp[ch-'a']++;
                target[ch-'a'] = max(temp[ch-'a'], target[ch-'a']);
            }
        }
        
        for(string word : words1) {
            vector<int> arr(26, 0);
            
            for(char ch : word) arr[ch-'a']++;
            
            if(isSubset(arr, target))
                ans.push_back(word);
        }
        
        return ans;
    }
    
    bool isSubset(vector<int> arr, vector<int> target) {
        for(int i=0; i<26; i++)
            if(target[i] > arr[i]) return false;
        
        return true;
    }
};