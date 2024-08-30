class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<pair<int,int>> g[n];
        vector<vector<int>> ans;
        set<pair<int,int>> dup;

        for(auto& e: edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }

        int e = dijkstra(g, n, source, destination, target);

        if(e < target) return ans;

        bool found = false;

        for(int i=0; i<n; i++) {
            for(auto&& [v, wt] : g[i]) {
                if(wt == -1) {
                    wt = 1; 

                    for(auto&& [u, _wt] : g[v]){
                        if(u == i) {
                            _wt = 1; 
                            break;
                        }
                    }

                    int e = dijkstra(g, n, source, destination, target);

                    if(e <= target) {
                        int req = target - e;
                        wt += req;

                        for(auto&&[u,_wt] : g[v]) {
                            if(u == i) {_wt += req; break;}
                        }

                        found = true;
                        break;
                    }
                }
            }

            if(found) break;
        }

        for(int i=0; i<n; i++) {
            for(auto& [j,wt] : g[i]) {
                int u = i, v = j;

                if(wt == -1) wt = (int)2e9;

                if(!dup.count({min(u,v), max(u,v)})) {
                    ans.push_back({min(u, v), max(u, v), wt});
                } 

                dup.insert({min(u, v), max(u, v)});
            }
        }

        e = dijkstra(g, n, source, destination, target);

        if(e != target) ans.clear();

        return ans;
    }

    int dijkstra(vector<pair<int,int>> g[],int n,int source,int destination,int target){
        vector<int> dist(n,1e9);
        dist[source] = 0;

        set<pair<int,int>> st;
        st.insert({0,source});

        while(!st.empty()) {
            auto top = *st.begin();
            st.erase(st.begin());

            int node = top.second;
            int wt = top.first;

            for(auto& [child,weight] : g[node]) {
                if(weight == -1) continue;

                if(dist[child] > wt + 0ll + weight){
                    dist[child] = wt + weight;
                    st.insert({dist[child],child});
                }
            }
        }

        return dist[destination];
    }
};