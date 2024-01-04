class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> counts;
        int count;
        int ans = 0;
        
        for(auto num: nums) counts[num]++;
        
        for(auto itr : counts) {
            count = itr.second;
            
            if(count == 1) return -1;
            if(count % 3 == 1) {
                ans += (count / 3) - 1;
                ans += 2;
            } 
            
            else {
                ans += (count / 3);
                ans += ((count % 3) / 2);
            }
        }
        
        return ans;
    }
};
