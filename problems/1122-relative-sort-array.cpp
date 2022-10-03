class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> arr;
        vector<int> ans;
        
        for(int i=0; i<arr1.size(); i++) arr[arr1[i]]++;
        
        for(int i=0; i<arr2.size(); i++) {
            int temp = arr[arr2[i]];
            while(temp--) ans.push_back(arr2[i]);
            arr[arr2[i]] = 0;
        }
        
        for(auto num : arr) {
            int temp = num.second;
            while(temp--) ans.push_back(num.first);
        }
        
        return ans;
    }
};