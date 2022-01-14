class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minElement = INT_MAX, sum = 0;
        
        for(int num : nums){
            minElement = min(minElement, num);
            sum += num;
        }
        
        return sum - (nums.size() * minElement);
    }
};