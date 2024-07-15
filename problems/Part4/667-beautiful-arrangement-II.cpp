class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int high = n , low = 1;
        int index = 0;
        bool isHigh = false;
        
        ans[index++] = low++;
        
        while(k > 1) {
            ans[index++] = high--;
            k--;
            isHigh = true;
            
            if(k > 1) {
                ans[index++] = low++;
                k--;
                isHigh = false;
            }
        }
        
        while(index < n) 
            if(isHigh) ans[index++] = high--;
            else ans[index++] = low++;
        
        return ans;
    }
};