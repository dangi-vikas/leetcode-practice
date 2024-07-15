class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int maxLen = INT_MIN;
        
        for(int i=0; i<n; i++) {
            int flag = 0;
            
            for(int j=0; j<n; j++) {
                if(i!=j && issubsequence(strs[i],strs[j])) {
                    flag = 1;
                    break;
                }
            }
            
            if(flag==0) {
                int x = strs[i].size();
                maxLen = max(maxLen, x);
            }
        }
        
        if(maxLen == INT_MIN) return -1;
        return maxLen;
    }
    
    bool issubsequence(string a, string b) {
        int n=a.size(), m=b.size();
        int i=0, j=0;
        
        while(i<n && j<m) {
            if(a[i] == b[j]) i++;
            j++;
        }    
        
        return i==n;
    }
};