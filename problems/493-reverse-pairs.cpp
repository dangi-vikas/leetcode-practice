class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
    int mergeSort(vector<int>& nums, int low, int high) {
        if(high == low) return 0;
        int mid = low + ((high - low) >> 1);
        
        int inv = mergeSort(nums, low, mid);
        inv += mergeSort(nums, mid+1, high);
        inv += merge(nums, low, mid, high);
        
        return inv;
    }
    
    int merge(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;
        
        for(int i=low; i<=mid; i++) {
            while(j <= high && nums[i] > (2 * (long) nums[j])) j++;
            count += j - (mid + 1);
        }
        
        vector<int> temp;
        int left = low, right = mid+1;
        
        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) 
                temp.push_back(nums[left++]);
            
            else temp.push_back(nums[right++]);
        }
        
        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= high) temp.push_back(nums[right++]);
        
        for(int i=low; i<=high; i++)
            nums[i] = temp[i - low];
        
        return count;
    }
};