class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> counts(n, 0);
        int len = trust.size();
        
        for(int i=0; i<len; i++) {
            counts[trust[i][0] - 1]--;
            counts[trust[i][1] - 1]++;
        }
        
        for(int i=0; i<n; i++)
            if(counts[i] == n-1) return i+1;
        
        return -1; 
    }
};