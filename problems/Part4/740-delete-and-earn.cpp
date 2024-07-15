class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001, 0);
        
        for(int num : nums) count[num]++;
        
        int inc=0, exc=0;
        
        for(int i=1; i<=10000; i++) {
            int ni = exc + count[i] * i;
            int ne = max(inc, exc);
            
            inc = ni;
            exc = ne;
        }
        
        return max(inc, exc);
    }
};