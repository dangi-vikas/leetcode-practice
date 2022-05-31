class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = 0, val = 0;
        
        if(seats.size() == 0) return ans;
        
        for(int i=0; i<n; i++) {
            if(seats[i] == 1) val = 0;
            else {
                val++;
                ans = max(ans, (val+1) / 2);
            }
        }
        
        for(int i=0; i<n; i++) {
            if(seats[i] == 1) {
                ans = max(ans, i);
                break;
            }
        }
        
        for(int i=n-1; i>=0; i--) {
            if(seats[i] == 1) {
                ans = max(ans, n-1-i);
                break;
            }
        }
        
        return ans;
    }
};