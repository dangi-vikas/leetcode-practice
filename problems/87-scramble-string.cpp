class Solution {
    unordered_map<string, bool> dp;

public:
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length()) return false;

        int n = s1.length();

        if(n == 0) return true;
        if(s1 == s2) return true;

        string s1Copy = s1, s2Copy = s2;

        sort(s1Copy.begin(), s1Copy.end());
        sort(s2Copy.begin(), s2Copy.end());
        if(s1Copy != s2Copy) return false;

        string key = s1 + "$" + s2;

        if(dp.find(key) != dp.end()) return dp[key];

        for(int i=1; i<n; i++) {
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, n-i), s2.substr(i, n-i))) 
                return dp[key] = true;
                 
            if(isScramble(s1.substr(0, i), s2.substr(n-i, i)) && isScramble(s1.substr(i, n-i), s2.substr(0, n-i))) 
                return dp[key] = true;
        }

        return dp[key] = false; 
    }
};