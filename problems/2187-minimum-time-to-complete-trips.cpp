class Solution {
    typedef long long ll;
    
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll low = 0, high = (ll) *max_element(time.begin(), time.end()) * totalTrips;

        while (low < high) {
            ll mid = low + ((high - low) >> 1);
            long long tripsCompleted = 0;

            for (int t : time) tripsCompleted += mid / t;
            if (tripsCompleted >= totalTrips) high = mid;
            else low = mid + 1;
        }

        return low;
    }
}; 