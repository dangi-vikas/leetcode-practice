class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen; 
        unordered_set<string> repeat;
        
        int i = 0, j = 0;
        while(j<s.size()) {

            //moving the j pointer to make a window of size 10
            if(j-i+1 < 10) j++;
            
            else if(j-i+1 == 10){  

                //substring of size 10
                string dna = s.substr(i, 10);
                
                //if the string is repeated, then inserting in the repeat map
                if(seen.find(dna) != seen.end()) repeat.insert(dna);

                //if new, insert in seen map
                else seen.insert(dna);
            
                i++; j++;
            }
        }
        
        vector<string> ans;
        for(string i : repeat) ans.push_back(i);
        
        return ans;
    }
};