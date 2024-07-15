class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagrams;
        
        //iterating through strs
        for(string str : strs) {
            string temp = str;

            /*sorting the string in strs as anagrams will then have 
            same string in temp*/
            sort(temp.begin(), temp.end());

            //mapping the strings in strs with temp
            anagrams[temp].push_back(str);
        }
        
        //pushing the strings in the anagrams map to the vector of vector
        for(auto anagram = anagrams.begin(); anagram != anagrams.end(); anagram++)
            ans.push_back(anagram->second);
        
        return ans;
    }
};
