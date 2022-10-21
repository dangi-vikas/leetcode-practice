class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int i = 0;
        
        sort(arr.begin(), arr.end());
        
        while(i < n){
            int count = 1;
            
            for(int j=i+1; j<n; j++) {
                if(arr[i] == arr[j]) count++;
                else break;
            }
            
            ans.push_back(count);
            i += count;
        }
        
        n = ans.size();
        sort(ans.begin(), ans.end());
        
        for(int i=0; i<n-1; i++)
            if(ans[i] == ans[i+1])
                return false;
           
        return true;   
    }
};