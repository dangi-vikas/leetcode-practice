class Solution {
public:
    string countAndSay(int n) {
        vector<string> str(n);
        
        //for n=1 initial string will be "1"
        str[0] = "1";
        
        for(int i=1; i<n; i++){
            string current = "";
            
            //checking for occurances in the previous iteration i.e. n-1
            for(int j=0; j<str[i-1].size(); j++){
                int k = j;
                
                //finding the identical consecutive number
                while(k<str[i-1].size()-1 && str[i-1][k]==str[i-1][k+1]) k++;
                
                //converting the count of number in string and adding it to current 
                current += to_string(k-j+1);
                
                //adding the number in current
                current.append(1, str[i-1][j]);
                
                //updating to get the next distinct number
                j = k;
            }
            
            //adding current to str vector
            str[i] = current;
        }
        
        return str[n-1];
    }
};