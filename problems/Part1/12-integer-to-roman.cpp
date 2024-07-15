class Solution {
public:
    string intToRoman(int num) {
        //preparing a pair for integer-roman conversion
        pair<int,string> intRoman[] = {
            {1000,"M"}, 
            {900,"CM"}, 
            {500, "D"}, 
            {400, "CD"}, 
            {100, "C"}, 
            {90, "XC"}, 
            {50, "L"}, 
            {40, "XL"}, 
            {10,"X"},
            {9,"IX"},
            {5, "V"}, 
            {4,"IV"}, 
            {1, "I"}
        };
        
        int i=0;
        string roman = "";
        
        while(num){

            //finding the greatest integer that has a roman symbol less than num
            if(num >= intRoman[i].first){
                //getting the corresponding symbol from pair and adding to the string
                roman += intRoman[i].second;

                //reducing the num to get the next digit
                num -= intRoman[i].first;
            }
            
            else i++;
        }
        
        return roman;
    }
};