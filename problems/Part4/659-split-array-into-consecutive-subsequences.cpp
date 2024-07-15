class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size() < 3) return false;
        
        unordered_map<int, int> freqMap; 
        unordered_map<int, int> subseqMap; 
        
        for(auto n : nums) freqMap[n]++;
        
        for(int n : nums) {
            if(freqMap[n] == 0) continue;
            
            else if(subseqMap[n-1] > 0) {
                subseqMap[n-1]--;
                subseqMap[n]++;
            }
            
            else if(freqMap[n+1] > 0 && freqMap[n+2] > 0) {
                subseqMap[n+2]++;
                freqMap[n+1]--;
                freqMap[n+2]--;
            }
            
            else return false;
            
            freqMap[n]--;
        }
        
        return true;
    }
};