class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> ans;
        
        for(auto i : nums1) count[i]++;
        
        for(auto i : nums2) {
            if(count[i]) {
                ans.push_back(i); 
                count[i] = 0; 
            }
        }
        
        return ans;
    }
};
