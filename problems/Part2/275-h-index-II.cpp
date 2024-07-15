class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int high=n-1, low=0;
        
        while(low<=high){
            int mid = low + ((high-low) >> 1);
            
            if(citations[mid] == n-mid) return n-mid;
            if(citations[mid] > n-mid) high = mid-1;
            else low = mid+1;
        }
            
        return n-low;
    }
};