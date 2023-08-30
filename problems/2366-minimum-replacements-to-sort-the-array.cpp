class Solution {
public:
    long long minimumReplacement(std::vector<int>& nums) {
        long long operations = 0;
        long long prevBound = nums.back();
        
        for(auto it = nums.rbegin() + 1; it != nums.rend(); ++it) {
            long long num = *it;
            long long noOfTimes = (num + prevBound - 1) / prevBound;
            operations += noOfTimes - 1;
            prevBound = num / noOfTimes;
        }
        
        return operations;
    }
};