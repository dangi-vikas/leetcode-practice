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

//space optimised solution

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.length();
        string ans = "";
        
        while(i<n) {
            while(s[i] == ' ') i++;
            
            if(i >= n) break;
            
            int j = i+1;
            
            while(s[j] != ' ' && j < n) j++;
            
            string word = s.substr(i, (j-i));
            if(ans.empty()) ans += word;
            else ans = word + " " + ans;
            
            i = j;
        }
        
        return ans;
    }
};