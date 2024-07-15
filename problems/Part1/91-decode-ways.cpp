class Solution {
public:
    int numDecodings(string s) {

        //edge conditions
        if(s.size() == 0 || s[0] == '0') return 0;
        if(s.size() == 1) return 1;
        
        //number of way upto any particular digit
        //count1= previous digit  count2= second previous digit
        int count1 = 1, count2 =1; 

        for(int i=1; i<s.size(); i++) {

            //getting the integer of one digit or two digits
            int d1 = s[i] - '0';
            int d2 = 10 * (s[i-1] - '0') + d1;
            
            int count = 0; 
            
            //getting the number of ways
            if(d1 > 0) count += count2;
            if(d2 >= 10 && d2 <= 26) count += count1;
            
            count1 = count2;
            count2 = count;
        }
        
        return count2;
    }
};
