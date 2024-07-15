class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> endIndex(26, 0);
        vector<int> ans;
        int start = 0, end = 0;
        
        for(int i=0; i<n; i++) endIndex[s[i] -'a'] = i;
        
        int i=0; 
        while(i < n) {
            end = max(end, endIndex[s[i] - 'a']);
            
            if(i == end) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
            
            i++;
        }
        
        return ans;
    }
};