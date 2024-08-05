class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        vector<string> sortedArr(arr.begin(), arr.end());
        
        sort(sortedArr.begin(), sortedArr.end());

        for(string& s: arr) {
            int i = lower_bound(sortedArr.begin(), sortedArr.end(), s) - sortedArr.begin();
            if (i == n-1 || sortedArr[i] != sortedArr[i+1]) k--;
            if (k == 0) return s;
        }
        
        return "";  
    }
};