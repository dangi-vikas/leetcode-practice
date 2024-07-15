class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, firstSeen;
        int degree = 0, ans = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(firstSeen.find(nums[i]) == firstSeen.end())
                firstSeen[nums[i]] = i;
            
            freq[nums[i]]++;
            
            if(freq[nums[i]] > degree){
                degree = freq[nums[i]];
                ans = i - firstSeen[nums[i]] + 1;
            } 
            
            else if(freq[nums[i]] == degree) 
                ans = min(ans, (i - firstSeen[nums[i]] + 1));
            
        }
           
        return ans;
    }
};