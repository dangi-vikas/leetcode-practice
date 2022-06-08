class Solution {
public:
    int primePalindrome(int n) {
        int x, mirroredN, temp;

        if(n <= 1) return 2;
        if (1e7 <= n && n <= 1e8) return 100030001;
       
        while(true) {         
            mirroredN = 0;
            temp = n;

            do {
                mirroredN = mirroredN * 10 + temp % 10;
                temp /= 10;
            } while(temp > 0);

            if(mirroredN == n) {
                temp = sqrt(n);
                
                for(x=2; x<=temp; ++x) {
                    if((n % x) == 0) break;
                }
                
                if(x > temp) return n;              
            }

            ++n;
        }
    }
};