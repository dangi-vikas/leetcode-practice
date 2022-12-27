class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0; i<capacity.size(); i++) capacity[i] -= rocks[i];
        
        sort(capacity.begin(), capacity.end());
        int ans = 0;

        for(int i=0; i<capacity.size(); i++) {
            int currCapacity = capacity[i];

            if(currCapacity == 0) ans++;

            else if(additionalRocks -  currCapacity >= 0){
                additionalRocks -= currCapacity;
                ans++;
            }
            
            else break;
        }

        return ans;
    }
};