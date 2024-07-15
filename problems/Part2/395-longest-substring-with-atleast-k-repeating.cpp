class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        
        if(s.size() == 0 || k > n) return 0;
        if(k == 0)  return s.size();
        
        vector<int> count(26, 0);
        int length = 0;
        
        for(auto i : s) count[i-'a']++;
    
        int i;
        for(i=0; i<n; i++)
            if(count[s[i]-'a'] < k) break;
            
        if(i == n) return n;
        
        int left = longestSubstring(s.substr(0,i), k);
        
        while(i<n && count[s[i]-'a'] < k)i++;
        
        int right = longestSubstring(s.substr(i), k);
        
        return max(left, right);
    }
};