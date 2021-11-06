class Solution {
public:
    string reverseWords(string s) {
        string word;
        stringstream str(s);                //creating object of stringstream
        vector<string> ss;
        
        while(str>>word){

            //storing individual string in the vector
            ss.push_back(word);
        }
        
        string ans ="";
        
        //traversing the string in the reverse order
        for(int i=ss.size()-1; i>=0; i--){
            
            //adding the individual strings in the ans string
            ans += ss[i];

            //adding spaces
            if(i>0) ans += " ";
        }
        
        return ans;
    }
};  