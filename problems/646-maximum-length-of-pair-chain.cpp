class Solution {
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; 
    }
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comparator);
        
        int ans = 1, prev = pairs[0][1];
        
        for(int i=1; i<pairs.size(); i++) {
            if(prev < pairs[i][0]) {
                prev = pairs[i][1];
                ans++; 
            }
        }
        
        return ans;
    }
};