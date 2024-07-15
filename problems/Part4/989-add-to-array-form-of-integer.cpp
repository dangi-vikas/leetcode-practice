class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int numInd = num.size()-1, carry = 0;

        while(numInd >= 0) {
            int sum = num[numInd] + (k % 10) + carry;
            
            carry = sum / 10;
            num[numInd] = sum % 10;
            numInd--;
            k /= 10;
        }

        while(k > 0) {
            int sum = (k % 10) + carry;

            carry = sum / 10;
            num.insert(num.begin(), (sum % 10));
            k /= 10;
        }

        if(carry) num.insert(num.begin(), carry);

        return num;
    }
};