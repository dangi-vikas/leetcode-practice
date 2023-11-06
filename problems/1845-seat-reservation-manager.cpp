class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    int front;

public:
    SeatManager(int n): n(n), front(1){

    }
    
    int reserve() {
        if (pq.empty()) return front++;
            
        else {
            int x=pq.top();
            pq.pop();
            return x;
        }
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    int front;

public:
    SeatManager(int n): n(n), front(1){

    }
    
    int reserve() {
        if (pq.empty()) return front++;
            
        else {
            int x=pq.top();
            pq.pop();
            return x;
        }
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */