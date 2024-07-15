class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        if (n == 1) return 1;
        
        vector<pair<int, double>> startPosAndTravelTime(n);
        
        for (int i = 0; i <n;  i++) 
            startPosAndTravelTime[i] = {position[i], ((double) target - position[i]) / speed[i]};
        
        sort(startPosAndTravelTime.begin(), startPosAndTravelTime.end());
        
        double currTime = startPosAndTravelTime[n-1].second;
        int ans = 1;
        
        for (int i=n-2; i>=0; i--) {
            if (startPosAndTravelTime[i].second <= currTime)
                continue;
            
            ans++;
            currTime = startPosAndTravelTime[i].second;
        }
        
        return ans;
    }
};