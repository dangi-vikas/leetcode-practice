class Solution {
public:
 int maxValue(vector<vector<int>>& events, int k){
    sort(events.begin(),events.end());

    int n = events.size();
    vector<vector<int>> dp(n+5, vector<int>(k+1, -1));

    return maxValue(0, events, k, dp);
  }

  int maxValue(int i,vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
    if(i >= events.size() || k == 0 || i == -1) return 0;
    if(dp[i][k] != -1) return dp[i][k];

    int index = search(i+1, events, events[i][1]);
    int choose = events[i][2] + maxValue(index, events, k-1, dp);
    int notChoose = maxValue(i+1, events, k, dp);

    return dp[i][k] = max(choose, notChoose);
  }

  int search(int index, vector<vector<int>>& events, int value) {
      int low = index, high = events.size() - 1;
      int ans = -1;

      while(high >= low) {
        int mid = low + ((high - low) >> 1);

        if(events[mid][0] > value) {
          ans = mid;
          high = mid - 1;
        }

        else low = mid + 1;
      }

      return ans;
  }
};