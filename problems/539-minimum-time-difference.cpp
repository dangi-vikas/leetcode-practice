class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> arr(2160);
        
        for (string time : timePoints) {
            int id = convertTime(time);
            if (arr[id]) return 0; 
            arr[id] = true;
        }
        
        for (int i = 0; i<720; i++) arr[i + 1440] = arr[i]; 
        
        int ans = 720, p = -1;
        for (int i=0; i<arr.size(); i++) {
            if (arr[i]) {
                if (p != -1) ans = min(ans, i - p);
                p = i;
            }
        }
        return ans;
    }
    
    int convertTime(string& time) {
        int hour = (time[0] - '0') * 10 + (time[1] - '0');
        int minute = (time[3] - '0') * 10 + (time[4] - '0');
        return hour * 60 + minute;
    }
};