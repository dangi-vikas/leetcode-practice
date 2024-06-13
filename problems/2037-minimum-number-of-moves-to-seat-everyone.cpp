class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> pos(101, 0);
        int n = seats.size();
        
        for(int i=0; i<n; i++) {
            pos[seats[i]]++;
            pos[students[i]]--;
        }
        
        int ans = 0;
        int current = 0;
        
        for(int i : pos) {
            ans += abs(current);
            current += i;
        }
        
        return ans;
    }
};
