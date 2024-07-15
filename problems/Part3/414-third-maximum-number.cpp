class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        bool flag = false;
        
        for(int i=0; i<nums.size(); i++) {
            if(first < nums[i]) {
                third = second;
                second = first;
                first = nums[i];
            }
            
            else if(first > nums[i] && second < nums[i]) {
                third = second;
                second = nums[i];
            }
            
            else if(second > nums[i] && third<nums[i]) {
                third = nums[i];
            }
            
            if(nums[i] == INT_MIN) flag = true;
        }
        
        if(flag) {
            if(first!=second && second!=third) return third;
            return first;
        }
        
        return (third==INT_MIN) ? first : third;
    }
};