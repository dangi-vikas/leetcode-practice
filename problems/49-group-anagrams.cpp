class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagramMap;
        
        //iterating through strs 
        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];

            /*sorting the string in strs as anagrams will then have 
              same string in temp*/
            sort(temp.begin(), temp.end());

            //mapping the strings in strs with temp
            anagramMap[temp].push_back(strs[i]);
        }
        
        //pushing the strings in the anagramMap to vector of vector
        for(auto i=anagramMap.begin(); i!=anagramMap.end(); ++i){
            ans.push_back(i->second);
        }
        
        return ans;
    }
};