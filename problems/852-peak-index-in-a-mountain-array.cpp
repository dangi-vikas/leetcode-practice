class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size()-1;

        while(high > low) {
            int mid = low + ((high - low) >> 1);

            if(arr[mid] > arr[mid+1]) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};