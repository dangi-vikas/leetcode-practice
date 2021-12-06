class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        vector<int> count(26,0), visited(26,0);
        
        for(int i=0; i<s.size(); i++) count[s[i]-'a']++;
        
        for(int i=0; i<s.size(); i++){
            count[s[i]-'a']--;
            
            if(visited[s[i]-'a']) continue;
            visited[s[i]-'a'] = 1;
            
            while(!ans.empty() && ans.back()>s[i] && count[ans.back()-'a']){
                visited[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            
            ans.push_back(s[i]);
        }
        
        return ans;
    }
};