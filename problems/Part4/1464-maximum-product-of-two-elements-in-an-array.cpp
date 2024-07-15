class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = 0;
        int secondMax = 0;

        for(int num : nums) {
            if(num > firstMax) {
                swap(secondMax, firstMax);
                firstMax = num;
            }
            
            else secondMax = max(secondMax, num);
        }

        return (firstMax - 1) * (secondMax - 1);        
    }
};
