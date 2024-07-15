class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int low = 1, high = position.back() - position[0];
        int ans = -1;
        
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            int lastPosition = position[0], balls = 1;
            
            for(int i=1; i<position.size(); i++) {
                if(position[i] - lastPosition >= mid) {
                    lastPosition = position[i];
                    balls++;
                }
            }
            
            if(balls >= m) {
                ans = mid;
                low = mid + 1;
            } 
            
            else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
