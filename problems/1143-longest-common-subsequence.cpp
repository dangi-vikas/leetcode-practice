class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<int> prev(m+1, 0);

        for(int i=1; i<=n; i++) {
            vector<int> curr(m+1, 0);

            for(int j=1; j<=m; j++) {
                if(text1[i-1] == text2[j-1]) 
                    curr[j] = 1 + prev[j-1];

                else curr[j] = max(prev[j], curr[j-1]);
            }

            prev = curr;
        }

        return prev[m];
    }
};