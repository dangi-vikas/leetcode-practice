class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        
        for(int i=left; i<=right; i++){
            int num = i, count = 0;
            
            while(num){
                num = num & (num - 1);
                count++;
            } 
            
            if(count==2 || count==3 || count== 5 || count==7 || count==11 || count==13 ||               count==17 || count== 19) ans++;
        }
        
        return ans;      
    }
};  