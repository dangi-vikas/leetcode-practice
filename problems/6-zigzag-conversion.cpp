class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        
        //when zigzag pattern is not possible
        if(numRows>n || numRows<2 || n<=2) return s;
        
        int next = numRows*2 - 2;
        string ans = "";
        
        for(int i=0; i<numRows; i++){
            string str = "";
            
            //printing the (2numRows -2)th number after the current number when it is number in the first or the last row
            if(i==0 || i==numRows-1){
                int j=i;
                while(j<n){
                    str += s[j];
                    j += next;
                }
            }
            
            else{
                int j=i, nextUp = next-i;
                
                while(j<n){
                    //printing the vertical row numbers
                    str += s[j];

                    //printing inclined row numbers
                    if(nextUp<n){
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