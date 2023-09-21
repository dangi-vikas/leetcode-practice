class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0; 
        
        for(int num2 : nums2) nums1.push_back(num2);
        
        sort(nums1.begin(), nums1.end());
        
        int n = nums1.size();
        int h = n >> 1;
        
        if(n%2 == 0) median = (double) (nums1[h] + nums1[h-1]) / 2;
        else median = nums1[h];
        
        return median;
    }
};