class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    
    void quickSort(vector<int>& nums, int low, int high) {
        if(high > low) {
            int pivotIdx = findPivot(nums, low, high);
            
            quickSort(nums, low, pivotIdx-1); 
            quickSort(nums, pivotIdx+1, high);
        }
    }
    
    int findPivot(vector<int>& nums, int low, int high) {
        int mid = low + ((high - low) >> 1);
        swap(nums[mid], nums[high]);
    
        int pivot = nums[high];
        int i = low;
        
        for(int j=low; j<high; j++) {
            if(nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[high]);
        
        return i;
    }
};