class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n = fronts.size();
        unordered_map<int, int> counts;
        set<int> integer;
        
        for(int i=0; i<n; i++){
            if(fronts[i] == backs[i]) counts[fronts[i]]++;
            
            integer.insert(fronts[i]);
            integer.insert(backs[i]);
        }
        
        for(int i : integer) {
            if(counts[i] >= 1) continue;
            return i;
        }
        
        return 0;
    }
};