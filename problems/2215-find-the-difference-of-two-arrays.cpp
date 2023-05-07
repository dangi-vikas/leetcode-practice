class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1, freq2;
        vector<vector<int>> ans(2);
        
        for(int num : nums1) freq1[num]++;
        for(int num : nums2) freq2[num]++;
        
        for(auto it=freq1.begin(); it!=freq1.end(); it++) 
            if(freq2.find(it->first) == freq2.end()) ans[0].push_back(it->first);
        
        for(auto it=freq2.begin(); it!=freq2.end(); it++) 
            if(freq1.find(it->first) == freq1.end()) ans[1].push_back(it->first);
        
        return ans;
    }
};
