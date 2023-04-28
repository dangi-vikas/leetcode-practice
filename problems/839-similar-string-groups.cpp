class DisjointSet{
private:
    vector<int> size;
    vector<int> parent;

public:
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);

        for(int i=0; i<=n; i++){
            size[i] = 1;
            parent[i]=i;
        }
    }

    int find(int node){
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    void unionBySize(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return;

        else if(size[pu] < size[pv]) {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        } 

        else {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet ds(n);
        int ans = n;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(areSimilar(strs[i], strs[j]) && (ds.find(i) != ds.find(j))){
                    ds.unionBySize(i, j);
                    ans--;
                }
            }
        }

        return ans;
    }

    bool areSimilar(string &str1, string &str2){
        int diff = 0; 

        for(int i=0; i<str1.length(); i++)
            if(str1[i] != str2[i]) diff++;
        
        return (diff == 0 or diff == 2);
    }

};