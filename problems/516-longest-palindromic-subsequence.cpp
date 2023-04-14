class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string p = s;
        vector<int> prev(n+1, 0); 

        reverse(p.begin(), p.end());

        for(int i=1; i<n+1; i++) {
            vector<int> curr(n+1, 0);

            for(int j=1; j<n+1; j++) {
                if(s[i-1] == p[j-1]) 
                    curr[j] = 1 + prev[j-1];
                    
                else curr[j] = max(prev[j], curr[j-1]);
            }

            prev = curr;
        }

        return prev[n];
    }
};