class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
        set<string> transformations;
        
        for(int i=0; i<words.size(); i++){
            string temp = "";
            
            for(int j=0; j<words[i].length(); j++)
                  temp += (morse[words[i][j] - 'a']);
            
            transformations.insert(temp);              
        }     
        
        return transformations.size();
    }
};
