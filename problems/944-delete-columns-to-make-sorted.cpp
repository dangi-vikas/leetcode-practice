class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deleteCount = 0;
        
        for(int i=0; i<strs[0].length(); i++) {
            char ch = strs[0][i];
            int passed = 0;
            
            for(int j=1; j<strs.size(); j++) {
                if(ch <= strs[j][i]) {
                    passed = 1;
                    ch = strs[j][i];
                }
                
                else {
                    passed = 0; 
                    break;
                }
            }
            
            if(!passed) deleteCount++;
        }
        
        return deleteCount;
    }
};
