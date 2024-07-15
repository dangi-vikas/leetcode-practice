class Solution {
public:
    int romanToInt(string s) {
        //preparing a map for roman-integer conversion
        map<char, int> romanInt = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int i=0;
        int integer = 0;
        
        //iterating through the string
        while(i<s.size()){

            /*getting the corresponding integer from the map and adding to the (integer) 
            ** only if the current symbol is greater than next, eg: "VI" ** */
            if(romanInt[s[i+1]] <= romanInt[s[i]]) integer += romanInt[s[i]];

            // if current symbol is lesser than the next eg: "IV"
            else integer -= romanInt[s[i]];
            
            i++;
        }
        
        return integer;
    }
};