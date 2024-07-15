class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;
        int r;
        string ans = " ";
        char store[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        
        if(n == 0) ans = "0";
        
        while(n){
            r = n % 16;
            ans = store[r] + ans;
            n = n/16;
        }

        return ans;
    }
}; 