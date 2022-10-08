class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        
        if(n == 0) return 0;
        if(n == 1 || n == 2) return b;
        
        else {
            for(int i=3; i<=n; i++) {
                int temp = a + b + c;
                a = b;
                b = c;
                c = temp;
            }
        }
        
        return c;
    }
};