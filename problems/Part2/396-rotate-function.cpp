class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, product = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            product += nums[i]*i;
            sum += nums[i];
        }
        
        int mx = product;
        
        for(int i=n-1; i>=0; i--){
            product = product + sum - (nums[i]*n);
            mx = max(mx, product);
        }
        
        return mx;
    }
};