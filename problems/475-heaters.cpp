class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end()); 
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        
        for(auto house: houses){
            
            int high = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            if(high == heaters.size()) high = INT_MAX;
            else high = heaters[high];
            
            int low = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            if(low == heaters.size()) low = heaters.back();
            else if(low && heaters[low] > house) low = heaters[low - 1];
            else if(heaters[low] > house) low = INT_MIN >> 1;
            else low = heaters[low];
            
            ans = max(ans, min(house-low, high-house));
        }
        
        return ans;
    }
};