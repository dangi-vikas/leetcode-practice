class SmallestInfiniteSet {
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> search;
    int min;

public:
    SmallestInfiniteSet() {
        min = 1;
    }
    
    int popSmallest() {
        if(!pq.empty()){
            int smallest = pq.top();
            pq.pop();
            search.erase(smallest);
            return smallest;
        }

        min++;
        return min - 1;
    }
    
    void addBack(int num) {
        if(min > num && search.find(num) == search.end()) {
            pq.emplace(num);
            search.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */