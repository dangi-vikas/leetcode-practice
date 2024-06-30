class DisjointSet {
    vector<int> parent; 
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n+1, 0);
        rank.resize(n+1, 0);
        
        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu; 
        } else if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }       
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n), bob(n);
        
        int removedEdge = 0, aliceEdge = 0, bobEdge = 0;
        
        for(auto edge : edges) {
            if(edge[0] == 3) {
                if(alice.find(edge[1]) != alice.find(edge[2])) {
                    alice.unionByRank(edge[1], edge[2]);
                    bob.unionByRank(edge[1], edge[2]);
                    aliceEdge++;
                    bobEdge++;
                } else removedEdge++;
            }
        }
            
         for(auto edge : edges) {
            if(edge[0] == 2) {
                if(bob.find(edge[1]) != bob.find(edge[2])) {
                    bob.unionByRank(edge[1], edge[2]);
                    bobEdge++; 
                } else removedEdge++;
            }  else if(edge[0] == 1) {
                if(alice.find(edge[1]) != alice.find(edge[2])) {
                    alice.unionByRank(edge[1], edge[2]);
                    aliceEdge++;
                } else removedEdge++;
            }
        }  
        
        return (aliceEdge == n-1 && bobEdge == n-1) ? removedEdge : -1;
    }
};
