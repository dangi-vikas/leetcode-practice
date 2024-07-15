class Solution {
    unordered_map<int, bool> container;
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k > nums.size()) return false;
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum % k != 0) return false;
        
        int target = sum / k;
        
        return canPartitionKSubsetsRec(k, 0, nums, 0, 0, target);
    }
    
     bool canPartitionKSubsetsRec(int k, int sum, vector<int>& nums, int start, int used, int target) {
        if(k == 0) return true;
        
        if(sum == target) {
            bool ans = canPartitionKSubsetsRec(k - 1, 0, nums, 0, used, target);
            container.insert({used, ans});
            return ans;
        }
        
        if(container.find(used) != container.end()) return container[used];
        
        for(int i = start; i < nums.size(); i++) {
            if(((used >> i) & 1) == 1) continue;
            if(sum + nums[i] > target) continue;
            
            used |= 1 << i;
            sum += nums[i];
            
            if(canPartitionKSubsetsRec(k, sum, nums, i+1, used, target))
                return true;
            
            used ^= 1 << i;
            sum -= nums[i];
        }
        
        return false;
    }
};