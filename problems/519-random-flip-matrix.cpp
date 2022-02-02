class Solution {
    unordered_set<int> count;
    int total;
    int n;
    
public:
    Solution(int m, int n) {
        count = {};
        this->n = n;
        total = m*n;  
    }
    
    vector<int> flip() {
        int random  = rand() % total;
        
        while(count.count(random)) {
            random++;
            random %= total;    
        }
        
        count.insert(random);
        
        return {random/n, random%n};
    }
    
    void reset() {
        count = {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */