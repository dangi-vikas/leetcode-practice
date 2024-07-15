class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
         
        while(i>=0 || j>=0){
            int sum = carry;
            
            //adding the two digits of a and b
            if(i>=0) sum += a[i--] - '0';
            if(j>=0) sum += b[j--] - '0';
            
            //updating the carried value
            carry = sum > 1 ? 1 : 0;
            
            //inserting the sum to ans string
            ans += to_string(sum%2);
        }
        
        //if any carried value is left inserting it in the array
        if(carry) ans += to_string(carry);
        
        reverse(ans.begin(), ans.end());
            
        return ans;
    }
};