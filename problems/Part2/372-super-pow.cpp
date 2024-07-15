class Solution {
public:
    int superPow(int a, vector<int>& b) {
        long curr_power_of_10 = a;
        long ret = 1;
        
        for(int i=b.size()-1; i>=0; i--){
            int digit = b[i];

            for(int j=0; j<digit; j++){
                ret *= curr_power_of_10;
                ret %= 1337;
            }
            
            long new_curr_pow = 1;
            
            for(int i=0; i<10; i++){
                new_curr_pow *= curr_power_of_10;
                new_curr_pow %= 1337;
            }
            
            curr_power_of_10 = new_curr_pow;
        }
        
        return ret;
    }
};