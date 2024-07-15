class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> check = { 0, 0, 1, -1, -1, 1, 1, -1, 0, 1 };
        int ans = 0;
        
        for(int i=2; i<=n; i++) {
            bool isValid = false;
            int temp =  i;
            
            while(temp) {
                if(check[temp % 10] == -1) break;
                if(check[temp % 10] == 1) isValid = true;
                
                temp /= 10;
            }
            
            if(temp == 0 && isValid) ans++;
        }
        
        return ans;
    }   
};