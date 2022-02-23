class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>counts;   
        
        for(auto it : s1) counts[it]++;
        
        int count = counts.size();       
        int i=0, j=0;
        int k = s1.size();  
        
        while(j<s2.size()){
            if(counts.find(s2[j]) != counts.end()){     
                counts[s2[j]]--;
                if(counts[s2[j]] == 0) count--;
            }
            
            if(j-i+1 < k) j++;
            
            else if(j-i+1 == k){
				if(count == 0)  return true;  

                if(counts.find(s2[i]) != counts.end()){  
                    counts[s2[i]]++;
                    if(counts[s2[i]] == 1) count++;
                }
                
                i++; j++;
            }
        }
        
        return false;
    }
};