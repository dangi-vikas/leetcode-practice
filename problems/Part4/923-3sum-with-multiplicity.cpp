class Solution {
    int mod = 1000000007;
    
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long ans = 0;
        vector<long> count(101, 0);
        
        for(int i : arr) count[i]++;
        
        for(int i=0; i<101; i++) {
            for(int j=i; j<101; j++) {
                int k = target - i - j;
                
                if(k < 0 || k > 100) continue;
                if(i == j && j == k) 
                    ans += (count[i] * (count[i]-1) * (count[i]-2)) / 6;
                
                else if(i == j && j != k) 
                    ans += (count[i] * (count[i]-1) / 2) * count[k];
                
                else if(i < j && j < k) 
                    ans += count[i] * count[j] * count[k];
            }
        }
        
        return (int) (ans % mod);
    }
};