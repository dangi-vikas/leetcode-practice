class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int temp = (unsigned) (a & b) << 1;
            a ^= b;
            b = temp;
        }
        
        return a;
    }
};