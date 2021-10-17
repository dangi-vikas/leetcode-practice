class Solution {
public:
    int uniquePaths(int m, int n) {
        
        //Total number of directions possible
        int N = n + m -2;
        
        //number of choices of direction for n direcion
        int r = m-1;
        long long ans = 1;

        //C(N,r) = C(n-m+2, m-1)
        
        //using combination formula finding out number of ways
        for(int i=1; i<=r; i++){
            ans = ans * (N-r+i) / i;
        }
        
        return ans;
    }
};