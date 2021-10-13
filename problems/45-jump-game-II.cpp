//used greedy approach

class Solution {
public:
    int jump(vector<int>& nums) {
        int currReach=0, maxReach=0; 
        int jumps=0;
        
        //traversing the array 
        for(int i=0; i<nums.size()-1; i++){

            /*if the any reach greater than current maxReach is found in currReach range
              then updating the maxReach*/
            if(i+nums[i] > maxReach) maxReach = i+nums[i];
            
            /*if all the elements in the range of currReach are explored then updating the
              currReach to maxReach and making a jump*/
            if(i == currReach){
                jumps++;
                currReach = maxReach;
            }
        }
        
        return jumps;
    }
};