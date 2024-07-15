class Solution {
public:
    int numPrimeArrangements(int n) {
        static const vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};   
        const int k = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
        const auto mod = (long long)1e9 + 7;
        long long res = 1;
        
        for(int i=2; i<=k; i++) {
            res*=i; 
            res%=mod;
        }
        
        for(int i=2; i<=n-k; i++) {
            res*=i; 
            res%=mod;
        }
        
        return res;
    }
};