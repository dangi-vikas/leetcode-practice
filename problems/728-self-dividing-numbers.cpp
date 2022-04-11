class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        
        for(int num=left; num<=right; num++){
            int temp = num, flag = 0;
            
            while(temp){
                int rem = temp % 10;
                
                if(rem == 0){
                    flag = -1;
                    break;
                }
                
                if(num % rem != 0) {
                    flag = -1;
                    break;
                }
                
                temp /= 10;
            }
            
            if(flag == 0) ans.push_back(num);
        }
        
        return ans;
    }
};