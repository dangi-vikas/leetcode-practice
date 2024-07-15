class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int left = 0, right = 1;
        int ans = 0;
         
        while(right < n){
            if(intervals[left][1] <= intervals[right][0]){
                left = right;
                right++;
            }
            
            else if(intervals[left][1] <= intervals[right][1]){
                right++; ans++;
            }  
            
            else if(intervals[left][1] > intervals[right][1]){
                left = right;
                right++; ans++;
            }
        }
        
        return ans;
    }
};