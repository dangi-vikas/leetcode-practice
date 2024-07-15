class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;

        while(a!=0 || b!=0 || c!=0) {
            int la = a & 1;
            int lb = b & 1;
            int lc = c & 1;

            if((la | lb) != lc) {
                if (la == 1 && lb == 1) ans += 2;
                else ans += 1;
            } 

            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }

        return ans;
    }
};