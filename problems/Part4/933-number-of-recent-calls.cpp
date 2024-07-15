class RecentCounter {
    vector<int> pings;
    
public:
    RecentCounter() {
        pings.clear();
    }
    
    int ping(int t) {
        pings.push_back(t);
    
        int left = t - 3000;
        int right = t;

        int uBound = upper_bound(pings.begin(), pings.end(), right) - pings.begin();
        int lBound = lower_bound(pings.begin(), pings.end(), left) - pings.begin();

        return uBound - lBound;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */