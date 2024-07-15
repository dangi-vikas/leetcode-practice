class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 
        
        vector<vector<int>>ans;
        int mindiff = INT_MAX;
        int idx = 0;
        
        while(idx < arr.size()) {
            if(idx < arr.size()-1 && abs(arr[idx]-arr[idx+1]) < mindiff)
               mindiff = min(mindiff, abs(arr[idx]-arr[idx+1]));
            
            idx++;
        }
        
        idx = 0;
        
        while(idx < arr.size()) {
            if(idx < arr.size()-1 && abs(arr[idx] - arr[idx+1]) == mindiff)
                ans.push_back({arr[idx], arr[idx+1]});
            
            idx++;
        }
        
        return ans;
    }
};