class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        
        //when zigzag pattern is not possible
        if(numRows>len || numRows<2 || len<=2) return s;
        
        int next = numRows*2 - 2;
        string ans = "";
        
        for(int i=0; i<numRows; i++){
            string str = "";
            
            //printing the (2numRows -2)th number after the current number when it is number in the first or the last row
            if(i==0 || i==numRows-1){
                int j=i;
                while(j<len){
                    str += s[j];
                    j += next;
                }
            }
            
            else{
                int j=i, nextUp = next-i;
                
                while(j<len){
                    //printing the vertical row numbers
                    str += s[j];

                    //printing inclined row numbers
                    if(nextUp<len){
                        str += s[nextUp];
                        nextUp += next;
                    }
                    j += next;
                }
            }
            ans += str;
        }
        
        return ans;
    }
};