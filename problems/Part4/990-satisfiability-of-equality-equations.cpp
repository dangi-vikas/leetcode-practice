class Solution {
    vector<int> parent = vector(26, 0);
    vector<int> rank = vector(26, 0);
    
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i=0; i<26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        for(string equation : equations) {
            if(equation[1] == '=') 
                _union(equation[0] - 'a', equation[3] - 'a');
        }
        
        for(string equation : equations) {
            if(equation[1] == '!') {
                int px = _find(equation[0] -'a'); 
                int py = _find(equation[3] - 'a');
                if (px == py) return false;
            }
        }
        
        return true;
    }
    
    int _find(int x) {
        if(parent[x] == x) return x;
        
        int temp = _find(parent[x]);
        parent[x] = temp;
        
        return temp;
    }
    
    void _union(int x, int y) {
        int px = _find(x);
        int py = _find(y);
        
        if(px != py) {
            if(rank[px] > rank[py]) parent[py] = px;
            else if(rank[px] < rank[py]) parent[px] = py;
            else {
                parent[px] = py;
                rank[py]++;
            }
        }
    }
};