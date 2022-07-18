class Solution {
public:
    string shortestPalindrome(string s) {
        string str1 = s;
        reverse(str1.begin(), str1.end());

        string temp = s + '$' + str1;
        int len = findPrefix(temp);

        string str2 = s.substr(len);
        reverse(str2.begin(), str2.end());

        return str2 + s;
    }

    int findPrefix(string& s){
        int n = s.size();
        vector<int> prefix(n, 0);

        for(int i=1; i<n; i++){
            int j = prefix[i-1];

            while(j > 0 && s[i] != s[j])
                j = prefix[j-1];

            if(s[i] == s[j]) j++;

            prefix[i] = j;
        }

        return prefix[n-1];
    }
};