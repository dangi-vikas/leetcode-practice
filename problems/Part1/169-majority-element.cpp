class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityEl = nums[0];
        
        for(int i=1, effVotes=1; i<nums.size(); i++){
            if(effVotes == 0) {
                effVotes = 1;
                majorityEl = nums[i];
            }
            else {
                if(majorityEl == nums[i]) effVotes++;
                else effVotes--;
            }
        } 
        
        return majorityEl;
    }
};
