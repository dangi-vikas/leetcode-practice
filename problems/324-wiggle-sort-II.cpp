class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> ans(nums.size(), 0);
        
        int start = (nums.size()%2==0) ? nums.size()-2 : nums.size()-1;
        int i , k ;
        
        for( i = 0 , k = start ; k >= 0 ; k-= 2 , i++ )
            ans[k] = nums[i];
        
        start = (nums.size()%2==0) ? nums.size()-1 : nums.size()-2;
        
        for( k= start ; k > 0 ; k-=2 , i++ )
            ans[k] = nums[i];
       
        nums = ans;
    }
};