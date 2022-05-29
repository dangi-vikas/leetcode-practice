class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int i = 0, ans = 0;
        
        while(i < n){
            if(i+1 < n && arr[i+1] <= arr[i]) i++;
            
            else {
                int cnt = 1;
                int j, k ;              
                for(j = i+1; j<n && arr[j] > arr[j-1]; j++) cnt++;
                if(j==n || arr[j] == arr[j-1]){
                    i = j;
                    cnt = 1;
                }
                
                else {
                    for(int k=j; k<n && arr[k] < arr[k-1]; k++) cnt++;
                    ans = max(cnt, ans);
                    cnt = 1;
                    i = k;           
                }
            }
        }
        
        if(ans < 3) return 0;
        
        return ans;
    }
};