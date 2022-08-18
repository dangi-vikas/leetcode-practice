class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size()-1, carry = 0;
        
        while(n >= 0) {
            int sum = num[n] + (k % 10);
            int add = sum + carry;

            carry = add / 10;
            num[n] = add % 10;
            k /= 10;
            n--;
        } 
         
        while(k > 0) {
            int add = k % 10 + carry;
            
            carry = add / 10;
            num.insert(num.begin(), add %10);
            k /= 10;
        }
        
        if(carry != 0) 
            num.insert(num.begin(), 1);
        
        return num;
    }
};