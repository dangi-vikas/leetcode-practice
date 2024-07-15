    class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int num;
        vector<string> ans;
        
        for(int i=0 ; i<words.size(); i++){
            num = row(words[i][0]);
            bool istrue = true;
            
            for(int j=1; j<words[i].size(); j++){
                if(row(words[i][j]) != num){
                    istrue = false; break;
                }
            }

            if(istrue) ans.push_back(words[i]);
        }

        return ans;
    }
    
    int row(char x){
        if(x < 97) x += 32;
        
        if(x == 'q' || x == 'w' || x == 'e' || x == 'r' || x == 't' || x == 'y' ||
        x == 'u' || x == 'i' || x == 'o' || x == 'p' ) return 1;
        
        else if(x == 'a' || x == 's' || x == 'd' || x == 'f' || x == 'g' || x == 'h' ||
        x == 'j' || x == 'k' || x == 'l' ) return 2;
        
        else return 3;
    }
};