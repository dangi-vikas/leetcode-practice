class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, count = 0;
        
        for(char c : s) {
            if(c == 'b') {
                count++;
            } else if (count) {
                ans++;
                count--;
            }
        }
        
        return ans;
    }
};