class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int size = trust.size();
        vector<int> trustCount(n, 0);

        for(int i=0; i<size; i++) {
            trustCount[trust[i][0] - 1]--;
            trustCount[trust[i][1] - 1]++;
        }

        for(int i=0; i<n; i++) 
            if(trustCount[i] == n-1) return i+1;

        return -1;
    }
};