class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 0, high = 1e9;
        int mid = low + ((high - low) >> 1) , ans = -1;
        
        while(low <= high) {
            int count = 0, bouquet = 0;
            
            for(int i=0; i<bloomDay.size(); i++) {
                if(bloomDay[i] <= mid) {
                    count++;
                    
                    if(count >= k) {
                        bouquet++;
                        count = 0;
                    }
                }
                
                else count = 0;
            }

            if(bouquet >= m) {
                ans = mid;
                high = mid - 1;
            }
            
            else low = mid + 1;
            
            mid = low + ((high - low) >> 1);
        }
        
        return ans;
    }
};
