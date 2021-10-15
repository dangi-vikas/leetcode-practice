class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1;
        
        //if digits is empty
        if(!(n+1)) return digits;
        
        for(int i=n; i>=0; i--){
            
            //if the digit on addition do not carry over
            if(digits[i]<9){
                digits[i] += 1;
                break;
            }
            
            //if its carries
            else{
                // incrementing the digits without adding carry to current digit
                digits[i] += 1-10;

                // inserting 1 at beginning if the first digit is 9
                if(i==0) digits.insert(digits.begin(), 1);
            }
        }
            
        return digits;
    }
};