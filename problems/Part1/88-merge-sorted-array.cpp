class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //if nums1 is empty
        if(m==0){
            for(int i=0; i<n; i++) nums1[i] = nums2[i];
        }

        //if nums2 is empty
        if(n==0) return;
        
        int i = m-1, j = n-1, p = i+j+1;
        
        //traversing the arrays
        while(j>=0){

            //filling the nums1 array with the greater number at the end
            (i>=0 && nums1[i]>nums2[j]) ? 
                nums1[p--] = nums1[i--]:
                nums1[p--] = nums2[j--];
        }
    }
};