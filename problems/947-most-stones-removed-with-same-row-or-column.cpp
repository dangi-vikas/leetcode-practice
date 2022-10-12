class Solution {
    vector<int> parent, rank;
    int islands;
    
public:
    int _find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = _find(parent[x]);
    }
    
    void _union(int x, int y){
        int px = _find(x), py = _find(y);
        
        if(px != py) {
            if(rank[px] < rank[py]) parent[px] = py;
            
            else {
                parent[py] = px;
                if(rank[px] == rank[py]) rank[px]++;
            }
            
            islands--;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        parent.resize(n);
        rank.resize(n);
        islands = n;
        
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        unordered_map<int, unordered_set<int>> mapx;
        unordered_map<int, unordered_set<int>> mapy;
        
        for(int i=0; i<stones.size(); i++){
            mapx[stones[i][0]].insert(i);
            mapy[stones[i][1]].insert(i);
        }
        
        for(auto itr : mapx) {
            int grpLead = *itr.second.begin();
            
            for(auto it : itr.second)
                _union(grpLead, it);
        }
        
        
        for(auto itr : mapy) {
            int grpLead = *itr.second.begin();
            
            for(auto it : itr.second)
                _union(grpLead, it);
        }
        
        return n - islands;
    }
};