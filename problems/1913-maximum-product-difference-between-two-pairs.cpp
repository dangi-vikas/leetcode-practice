class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int greatest = 0, secondGreatest = 0;
        int smallest = INT_MAX, secondSmallest = INT_MAX;

        for(int num : nums) {
            if(num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            }

            else if(num < secondSmallest) 
                secondSmallest = num;

            if(num > greatest) {
                secondGreatest = greatest;
                greatest = num;
            }

            else if(num > secondGreatest) 
                secondGreatest = num;
        }

        return (greatest * secondGreatest) - (smallest * secondSmallest);
    }
};