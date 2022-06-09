class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int, int>> indexes; 
        
        for(int i=0; i<n; i++)
            indexes.push_back({nums2[i], i});
       
        sort(indexes.begin(), indexes.end(), greater<pair<int, int>>()); 
        sort(nums1.begin(), nums1.end(), greater<int>()); 
        
        int low = 0, high = n-1;
       
        for(int i=0; i<n; i++) {
            if(nums1[low] > indexes[i].first) nums2[indexes[i].second] = nums1[low++]; 
            else nums2[indexes[i].second] = nums1[high--];
        }
        
        return nums2;
    }
};