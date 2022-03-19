class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto index = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
      
        int low = index-1, high = index;

        for(int i=0; i < k; ++i) {
            bool lowIsValid = low>=0 && low<arr.size();
            bool highIsValid = high>=0 && high<arr.size();
            
            if(lowIsValid && highIsValid) {
                if(abs(arr[low] - x) <= abs(arr[high] - x))
                    low--;
                else high++;
            }
            
            else if(lowIsValid) low--;
            
            else high++;
        }

        vector<int> result;
        for(int i=low+1; i<high; i++)
            result.push_back(arr[i]);

        return result;
    }
};