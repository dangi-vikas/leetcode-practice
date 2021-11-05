class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber>0){
            int curr = columnNumber%26;
            
            if(curr == 0){
                ans += 'Z';
                columnNumber = columnNumber/26-1;
            }
            else{
                ans += ('A'+curr-1);
                columnNumber = columnNumber/26;
            }
            
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};