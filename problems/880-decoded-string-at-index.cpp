class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long count = 0;
        int n = s.length();
        string ans;
        
        for(char ch : s) {
            if(isdigit(ch)) count *= (ch - '0');
            else count++;
        }
        
        for(int i=n-1; i>=0; i--) {
            k %= count;
            
            if(k == 0 && isalpha(s[i])) 
                return (ans = s[i]);

            if(isdigit(s[i])) count /= (s[i] - '0');
            else count--;
        }
        
        return NULL;
    }
};