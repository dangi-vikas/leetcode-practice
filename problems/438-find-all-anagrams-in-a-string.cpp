class Solution {
public:
    vector<int> findAnagrams(string s, string p) {\
        vector<int> ans;
        vector<int> sHash(26, 0), pHash(26, 0);
        int window = p.size(), n = s.size();
         
        if(n < window) return ans;
                   
        int i=0, j=0;
        
        while(j < window){
            pHash[p[j] - 'a']++;
            sHash[s[j++] - 'a']++; 
        }
        
        j--;
        
        while(j < n){
            if(pHash == sHash) ans.push_back(i);
            
            j++;
            
            if(j != n) sHash[s[j] - 'a']++;
            sHash[s[i] - 'a']--;
            
            i++;
        }
                                                  
        return ans;
    }
};