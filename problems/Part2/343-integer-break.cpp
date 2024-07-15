    class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        
        int count3 = n/3;
        int rem = n%3;
        
        rem = (rem==1) ? 4 : (rem==0) ? 1 : 2;
        count3 = (rem==4) ? count3 - 1 : count3;

        int ans = (int) pow(3, count3) * rem;

        return ans;
    }
};