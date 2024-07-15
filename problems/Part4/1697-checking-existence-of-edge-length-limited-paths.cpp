class DisjointSet{
public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void UnionBySize(int u, int v){
        int pu = find(u);
        int pv = find(v);
        
        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b) {
        return a[2] < b[2];
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        
        for(int i=0; i<queries.size(); i++)
            queries[i].push_back(i);

        vector<bool> ans(queries.size(), false);

        sort(queries.begin(), queries.end(), compare);
        sort(edgeList.begin(), edgeList.end(), compare);

        int j = 0;

        for(int i=0; i<queries.size(); i++){
            while(j < edgeList.size() && edgeList[j][2] < queries[i][2]) { 
                ds.UnionBySize(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            if(ds.find(queries[i][0]) == ds.find(queries[i][1]))
                ans[queries[i][3]] = true;
            
        }

        return ans;
    }
};
