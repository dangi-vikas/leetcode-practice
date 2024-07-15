class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> red[n], blue[n];
        queue<int> q;
        vector<int> ans(n);
        vector<int> redDis(n, 1e9), blueDis(n, 1e9);

        for(auto it : redEdges) red[it[0]].push_back(it[1]);
        for(auto it : blueEdges) blue[it[0]].push_back(it[1]);

        q.push(0);
        redDis[0] = 0;
        blueDis[0] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(redDis[node] != 1e9) {
                for(auto it : blue[node]) {
                    if(blueDis[it] > redDis[node] + 1) {
                        blueDis[it] = redDis[node] + 1;
                        q.push(it);
                    }
                }
            }

            if(blueDis[node] != 1e9) {
                for(auto it : red[node]) {
                    if(redDis[it] > blueDis[node] + 1) {
                        redDis[it] = blueDis[node] + 1;
                        q.push(it);
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            ans[i] = min(redDis[i], blueDis[i]);
            if(ans[i] == 1e9) ans[i] = -1;
        }

        return ans;
    }
};