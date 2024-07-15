class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans;
        int numLines = 1, width = 0; 
        
        for(char ch : s) {
            if(widths[ch - 'a'] + width > 100) {
                numLines++;
                width = 0;
            } 
            
            width += widths[ch - 'a'];
        }
        
        return {numLines, width}; 
    }
};