class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(52, 0);
        
        for(char &c: s){
            if(c>='A' && c<='Z') count[c - 'A' + 26]++;
            if(c>='a' && c<='z') count[c - 'a']++;
        }
        
        int ans = 0, c = 0;
        
        for(int i=0; i<count.size(); i++){
            if(count[i] % 2) c = 1;
            ans += count[i] / 2;
        }
        
        return ans*2 + c;
    }
};