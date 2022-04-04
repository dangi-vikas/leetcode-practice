class KthLargest {
    priority_queue<int> minHeap;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for (int &num : nums) {
            minHeap.push(-1 * num);
            if (minHeap.size() > k) 
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(-1 * val);
        if (minHeap.size() > k) 
            minHeap.pop();
        
        return minHeap.top() * -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */