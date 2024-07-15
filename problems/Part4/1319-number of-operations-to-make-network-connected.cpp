class DisjointSet {
public:
    vector<int> parent, size; 
    
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0; i<=n; i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findParent(int node) {
        if(node == parent[node]) return node; 
        return parent[node] = findParent(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u); 
        int pv = findParent(v); 

        if(pu == pv) return; 
        if(size[pu] < size[pv]) {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int edges = 0;
        int ans = 0;

        for(auto nbr : connections) {
            int u = nbr[0];
            int v = nbr[1];

            if(ds.findParent(u) == ds.findParent(v)) edges++;
            else ds.unionBySize(u, v);
        }

        for(int i=0; i<n; i++) {
            if(ds.parent[i] == i) ans++;
        }

        ans--;

        return (edges >= ans) ? ans : -1; 
    }
};