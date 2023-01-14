class UnionFind {
public:
    vector<int> parent;

    UnionFind() {
        parent = vector<int>(26, -1);
    }
    
    int findParent(int node){
        if(parent[node] == -1) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int x, int y) {
        int px = findParent(x);
        int py = findParent(y);
        
        if (px != py) 
            parent[max(px, py)] = min(px, py); 
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        UnionFind uf = UnionFind();
        
        for (auto i=0; i<s1.size(); ++i) 
            uf.unionBySize(s1[i] - 'a', s2[i] - 'a');
        
        for(auto i=0; i<baseStr.size(); i++) 
            baseStr[i] = uf.findParent(baseStr[i] - 'a') + 'a';

        return baseStr;
    }
};