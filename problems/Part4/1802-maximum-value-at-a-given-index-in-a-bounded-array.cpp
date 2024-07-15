class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long rLen = n - index - 1, lLen = index;
        long high = maxSum, low = 1;
        int ans = 0;

        while(low <= high) {
            long mid = low + ((high - low) >> 1);
            long totalSum = 0, lSum = 0, rSum = 0;
            long pivot = mid - 1;

            if(rLen <= pivot) 
                rSum = (pivot * (pivot+1) / 2) - ((pivot-rLen) * (pivot-rLen+1) / 2);
            else rSum = (pivot * (pivot+1) / 2) + ((rLen - pivot));

            if(lLen <= pivot) 
                lSum = (pivot * (pivot+1) / 2) - ((pivot-lLen) * (pivot-lLen+1) / 2);
            else lSum = (pivot * (pivot+1) / 2) + ((lLen - pivot));

            totalSum = lSum + mid + rSum;

            if(totalSum <= maxSum) {
                low = mid + 1;
                ans = mid;
            } 
            
            else high = mid - 1;
        } 

        return ans;
    }
};