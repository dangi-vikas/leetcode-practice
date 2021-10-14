//Greedy Approach

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        
        for(int i=0; i<nums.size(); i++){
            
            //if the current number cannot be reached
            if(maxReach<i) return false;
            
            //if the current reachable range is greater than maxReach
            if(i+nums[i]>maxReach) maxReach = i+nums[i];
        }
        
        return true;
    }
};