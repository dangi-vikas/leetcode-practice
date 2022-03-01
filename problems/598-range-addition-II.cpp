class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int i = m, j = n;
        
        for (int k=0; k<ops.size(); k++) {
            if (ops[k][0] < i) 
                i = ops[k][0];
            
            if (ops[k][1] < j) 
                j = ops[k][1];
        }
        
        return i * j;
    }
};