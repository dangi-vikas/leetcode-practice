class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;

        //checking the common bits
        while(left != right) {
            left >>= 1;
            right >>= 1;
            count++;
        }
        
        //returning the bits after adding count zeroes at end
        return left << count;
    }
};
