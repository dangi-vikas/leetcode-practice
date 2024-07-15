class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        
        for(int i=0; i<words.size(); i++)
           if(isStretchy(s, words[i])) ans++;
        
        return ans;
    }
    
    bool isStretchy(string& s, string& word) {
        int n = s.length(), m = word.length();
        int i = 0, j = 0;
        
        if(n < m) return false;
        
        while(i < m && j < n) {
            int c = 0, d = 0;
            
            if(s[j] != word[i]) return false;
            
            while(i+1 < m && word[i] == word[i+1]) i++, d++;
            while(j+1 < n && s[j] == s[j+1]) j++, c++;
            
            if(d > c || (c != d && (c > 0 && c < 2))) return false;   
            
            i++; j++;
        }
        
        return (i == m && j == n) ? true : false;
    }
};