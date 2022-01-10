class Solution {
public:
    int findKthNumber(int n, int k) {
        int base = 1, finalLen = 1;
        
        while (n / base >= 9) {
            base *= 10;
            base++; 
            finalLen *= 10;
        }
            
        
        if (n != 9 * base) base /= 10;
        
        int rest = n - 9 * base;
        int ans = 0;
        
        findKthNumber(ans, base, rest, finalLen, k+1, 1);
        
        return ans;
    }
    
    void findKthNumber(int &ans, int base, int rest, int finalLen, int k, int start) {
        if (k-- == 1) return; 
        int i;
        
        for (i = start;; ++i) {
            int v = base + min(finalLen, rest);
            if (v >= k) break;
            rest = max(0, rest-finalLen);
            k -= v;   
        }
        
        ans = ans * 10 + i;
        
        findKthNumber(ans, base/10, rest, finalLen/10, k, 0);
    }
};