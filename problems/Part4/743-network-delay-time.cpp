class Solution { 
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if (n == 0) return 0;

        unordered_map<int, vector<pair<int, int>>> graph;
        
        for (vector<int> &time: times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].push_back({v, w});
        }
        
        static auto comparator = [](auto a, auto b) {
            return a.second > b.second;
        };

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);

        pq.push({k, 0});
        
        while(pq.size()) {
            auto [node, weight] = pq.top();
            pq.pop();

            for(auto [neigh, edgeWeight]: graph[node]) {
                if(weight+edgeWeight < dist[neigh]) {
                    dist[neigh] = weight + edgeWeight;
                    pq.push({neigh, dist[neigh]});
                }
            }
        }

        for(int i=1; i<dist.size(); i++) 
            if(dist[i] == INT_MAX) return -1;
        
        return *max_element(dist.begin()+1, dist.end());

    }
};