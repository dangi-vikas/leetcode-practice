class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        string ans;
        
        for(char ch : s) freq[ch - 'a']++;
        
        for(char orderCh : order) {
            while(freq[orderCh - 'a']--) 
                ans.push_back(orderCh);
        }
        
        for(int i=0; i<26; i++) {
            while(freq[i]-- > 0)
                ans.push_back((char) (i + 'a'));
        }
        
        return ans;
    }
};