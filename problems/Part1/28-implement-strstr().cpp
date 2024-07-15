class Solution {
public:
    int strStr(string haystack, string needle) {

        //if the needle string id empty
        if(needle == "") return 0;
        
        int m=needle.size(), n=haystack.size();
        
        //getting the LPS vector
        vector<int> lps(m, 0);
        LPS(needle, lps, m);
        
        int i=0, j=0;
        
        //traversing the haystack string
        while(i<n){

            //if the character in the haystack and needle matches
            if(needle[j] == haystack[i]){
                i++; j++;
            }
            
            else {
                
                /*if j is not at starting position then move it to the position
                  of matching prefix character*/
                if (j != 0) j = lps[j - 1];

                else i++;
            }

            //if all the characters in needle are matched to a substring in haystack
            //return its length
            if (j == m) return i - j;
        }
        
        return -1;
    }
    
    //preparing the LPS vector for KMP Algorithm
    //finding the longest prefix which is same as some suffix
    void LPS(string& needle ,vector<int> &lps, int m){
        int len = 0;
        lps[0] = 0;
        int i=1;
        
        while(i<m){

            //if the current character is matching to prefix charcter
            if(needle[i] == needle[len]) {
                len++;
                lps[i] = len;                           //giving the matched character the index of prefix character 
                i++;
            }

            //in case it doesnt match
            else {
                if(len!=0){
                    len = lps[len-1];                   //checking it with the previous prefix character
                }
                else {

                    //if the current charcter is not matched with any character in prefix
                    //assign it a value of zero
                    lps[i]=0;     

                    i++;
                }
            }
        }
       
    }
};