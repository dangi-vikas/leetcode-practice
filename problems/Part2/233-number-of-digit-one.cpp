class Solution {
typedef long long ll;

public:
    int countDigitOne(int n) {
        ll ans = 0;
        ll m = 1, k = 0;
        
        while(n >= m) {
            ll a = (n / (m * 10)) * m;
            ll b = (n % (m * 10)) - k;
            
            if(b <= 0) b = 0;
            else if(b >= m) b = m;
            
            ans = ans + a + b;
            m *= 10;
            k = k * 10 + 9;
        }
        
        return ans;
    }
};