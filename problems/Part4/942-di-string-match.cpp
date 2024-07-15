class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i=0, n=s.length(), ind=0;
        vector<int> ans;
        
        while(i != n) {
            if(s[ind] == 'I') {
                ans.push_back(i);
                i++;
            }
            
            else {
                ans.push_back(n);
                n--;
            }
            
            ind++;
        }
        
        ans.push_back(n);
        
        return ans;
    }
};