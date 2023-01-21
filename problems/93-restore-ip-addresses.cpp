class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string container = "";
        
        restoreIpAddressesRec(ans, container, 0, 0, s);
        
        return ans;
    }
    
    void restoreIpAddressesRec(vector<string>& ans, string container, int index, 
                               int part, string s){
        
        //if the string is traversed completely or part is greater than 3 digit
        if(index ==  s.size() || part==4){

            //pushing in the temporary string
            if(index ==  s.size() && part==4)
                ans.push_back(container.substr(0, container.size()-1));

            return;
        }
        
        //adding first digit of part
        restoreIpAddressesRec(ans, container+s[index]+".", index+1, part+1, s);
        
        //adding second digit of part
        if((index+2)<=s.size() && isValid(s.substr(index, 2)))
            restoreIpAddressesRec(ans, container+s.substr(index,2)+".", index+2, part+1, s);

        //adding third digit of part  
        if((index+3)<=s.size() && isValid(s.substr(index, 3)))
            restoreIpAddressesRec(ans, container+s.substr(index,3)+".", index+3, part+1, s);
    }
    
    bool isValid(string str){
        
        //if the part is preceeded by a 0
        if(str[0]=='0') return false;

        //check if the part is in range of [0,25]
        return stoi(str)<=255;
    }
}; 
