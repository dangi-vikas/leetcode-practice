class Solution {
    vector<int> randoms;
    
public:
    Solution(vector<int>& w) {
        int s = 0;
        for(auto x : w) 
            randoms.push_back(s += x);
    }
    
    int pickIndex() {
        int random = rand() % randoms.back();
        int x = upper_bound(randoms.begin(),randoms.end(), random) - randoms.begin();
        
        return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */