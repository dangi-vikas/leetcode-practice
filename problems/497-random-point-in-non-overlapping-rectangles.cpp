class Solution {
    map<int, vector<int>> domains;
    int totalArea;
    
public:
    Solution(vector<vector<int>>& rects) {
        int start = 0;
        
        for(auto rect : rects) {
            vector<int> domain{rect[0], rect[1], rect[2]-rect[0]+1, rect[3]-rect[1]+1};
            domains[start] = domain;
            start += domain[2] * domain[3];
        } 
        
        totalArea = start;
    }
    
    
    vector<int> pick() {
        int randIndex = rand();
        randIndex %= totalArea;
        
        auto it = domains.upper_bound(randIndex);
        
        int startIndex = (--it)->first;
        vector<int> rect = it->second;
        
        int x = rect[0] + (randIndex-startIndex)%rect[2];
        int y = rect[1] + (randIndex-startIndex)/rect[2];
        
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */