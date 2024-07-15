class Solution {
public:
    vector<int> topologicalSort(auto& adj, vector<int>& degree, int size){
        queue<int> q;
        vector<int> ans;

        for(int i=0; i<size; i++)
            if(degree[i] == 0) q.push(i);

        while(!q.empty()) {
            int src = q.front();

            q.pop();
            ans.push_back(src);

            for(int nbr : adj[src]) {
                degree[nbr]--;
                if(degree[nbr] == 0) q.push(nbr);
            }
        }

        for(int i=0; i<size; i++)
            if(degree[i] > 0) return {};

        return ans;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0; i<n; i++)
            if (group[i] == -1) group[i] = m++;

        vector<vector<int>> adjItem(n);
        vector<int> degGroup(m, 0), degItem(n, 0);
        vector<unordered_set<int>> adjGroupSet(m);

        for(int i=0; i<n; i++) {
            int toI = group[i];

            for(int from: beforeItems[i]) {
                int fromJ = group[from];

                if(toI != fromJ && adjGroupSet[fromJ].count(toI) == 0) {
                    adjGroupSet[fromJ].insert(toI);
                    degGroup[toI]++;
                }

                adjItem[from].push_back(i);
                degItem[i]++;
            }
        }
        
        vector<int> sortGroup = topologicalSort(adjGroupSet, degGroup, m);
        vector<int> sortItem = topologicalSort(adjItem, degItem, n); 
  
        if (sortGroup.empty() || sortItem.empty()) return {};

        vector<vector<int>> itemGrp(m);

        for(int i: sortItem)
            itemGrp[group[i]].push_back(i);
        
        vector<int> ans;

        for(int i : sortGroup) 
            for(int item : itemGrp[i]) 
                ans.push_back(item);
           
        return ans;
    }
};