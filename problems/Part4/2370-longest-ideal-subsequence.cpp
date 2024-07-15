class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> seq(26);
        int ans = 0;
        
        for(char c : s) {
            int i = c - 'a';
            int j0 = max(0, i-k), j1 = min(i+k, 25);
            
            for(int j=j0; j<=j1; j++) {
                seq[i] = max(seq[i], seq[j]);
            }

            seq[i]++;    
        }
        
        return *max_element(seq.begin(), seq.begin() + 26);   
    }
