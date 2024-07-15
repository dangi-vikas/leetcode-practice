class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int i=0, j=0;
        
        while(j<nums.size()){

            //if duplicate is found in window of length k
            if(count.find(nums[j]) != count.end())
                return true;

            //counting number of same element
            count[nums[j]]++;
            
            //creating a window of length k
            if((j-i) < k) j++;
            
            //sliding the window
            else if (j-i == k){
                count[nums[i]]--;
                if(!count[nums[i]]) count.erase(nums[i]);
                
                i++; j++;
            }
        }
        
        return false;
    }
};