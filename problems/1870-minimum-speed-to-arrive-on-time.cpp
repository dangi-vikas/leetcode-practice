class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();

        if(hour <= n-1) return -1;

        int low = 1 , high = 1e7;

        while(low < high){
            int mid = low + ((high - low) >> 1);
            double time = 0;

            for(int i=0; i<n-1; i++) time += ceil((double) dist[i] / mid);
            
            time += (double) dist[n-1] / mid;

            if(time <= hour) high = mid;
            else low = mid + 1;
        }

        return low;
    }
};