class UnionFind {
    unordered_map<int, int> parent, rank;
    
public:
    int groups;
    
    UnionFind(vector<vector<int>> stones) {
        for(vector<int> stone : stones) {
            int row = -(stone[0] + 1);
            int col = stone[1] + 1;
            parent[row] = row;
            parent[col] = col;
        }
        
        groups = parent.size();
    }
    
    int _find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = _find(parent[x]);
    }
    
    void _union(int x, int y) {
        int px = _find(x), py = _find(y);
        
        if(px != py) {
            if(rank[px] < rank[py]) parent[px] = py;
            else {
                parent[py] = px;
                if(rank[px] == rank[py]) rank[px]++;
            }
            
            groups--;
        } 
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(stones);
        
        for(vector<int> stone : stones) {
            int row = -(stone[0] + 1);
            int col = stone[1] + 1;
            
            uf._union(row, col);
        }
        
        return stones.size() - uf.groups;
    }
};