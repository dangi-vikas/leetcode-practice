class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INT_MAX), dist2(n , INT_MAX);
        int ans = -1, minDist = INT_MAX;

        dfs(edges, node1, dist1);
        dfs(edges, node2, dist2);

        for(int i=0; i<n; i++) {
            int currDist = max(dist1[i], dist2[i]);
            if(currDist < minDist) {
                ans = i;
                minDist = currDist;
            }
        }
        
        return ans;
    }

    void dfs(vector<int>& edges, int node, vector<int>& dist) {
        int dis = 0;

        while(true) {
            dist[node] = dis;
            int nbr = edges[node];

            if(nbr == -1 || dist[nbr] < dis) break;
            
            node = nbr;
            dis++;
        }
    }
};