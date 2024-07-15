class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        int count = 0, minCount = s.size();
        int winStart = -1, winEnd = -1;
        int start = 0, end = 0;
        
        for(int ch : t) freq[ch]++;
        
        for(; end<s.size(); end++) {
            if(freq.find(s[end]) != freq.end()) {
                freq[s[end]]--;
                if(freq[s[end]] == 0) count++; 
            }
            
            while(count == freq.size()) {
                if(end-start+1 <= minCount) {
                    minCount = end - start + 1;
                    winEnd = end;
                    winStart = start;
                }
                
                if(freq.find(s[start]) != freq.end()) {
                    if(freq[s[start]] == 0) count--;
                    freq[s[start]]++;
                }
                
                start++;
            }
        }
        
        string ans = ""; 
        
        if(winStart != -1)
            for(int i=winStart; i<=winEnd; i++)
                ans += s[i];
            
        return ans;
    }
};
