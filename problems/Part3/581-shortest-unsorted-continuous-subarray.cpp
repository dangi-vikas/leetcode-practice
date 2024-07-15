class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mn=INT_MAX, mx=INT_MIN;
        int n = nums.size();
        
        int i=1, j=n-2;
        while(i<n || j>=0) {
            if(nums[i] < nums[i-1]) 
                mn = min(mn, nums[i]);
            
            if(nums[j] > nums[j+1])
                mx = max(mx, nums[j]);
            
            i++; j--;
        }
        
        if(mn==INT_MAX && mx==INT_MIN) return 0;
        
        int start=0, end=n-1;
        
        while(start<n) {
            if(nums[start] > mn) break;
            start++;
        }
        
        while(end>=0) {
            if(nums[end] < mx) break;
            end--;
        }
            
         return end - start + 1;   
            
    }
};