class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int mxSize = maxHeap.size(), mnSize = minHeap.size();
        
        if(mxSize == 0) maxHeap.push(num);
        
        else if(mxSize == mnSize) {
            if(num < minHeap.top()) maxHeap.push(num);
            
            else {
                minHeap.push(num);
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
            }  
        }
        
        else {
            if(minHeap.size() == 0) {
                if(num > maxHeap.top()) minHeap.push(num);
                else {
                    maxHeap.push(num);
                    int top = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(top);
                }
            }
            
            else if(num >= minHeap.top()) minHeap.push(num);
            
            else {
                if(num < maxHeap.top()) {
                    maxHeap.push(num);
                    int top = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(top);
                }
                
                else minHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        int mxSize = maxHeap.size(), mnSize = minHeap.size();
        
        if(mxSize == mnSize) return ((double) (maxHeap.top() + minHeap.top())) / 2;
        return (double) maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */