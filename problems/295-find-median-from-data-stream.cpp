class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lSize = maxHeap.size();
        int rSize = minHeap.size();
        
        if(lSize == 0) maxHeap.push(num);
        
        else if(lSize == rSize) {
            if(num < minHeap.top()) maxHeap.push(num);
            
            else {
                int temp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
        }
        
        else {
           if (minHeap.size() == 0) {
                if(num > maxHeap.top()) minHeap.push(num);
                else {
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
            }
            
            else if(num >= minHeap.top()) minHeap.push(num);
            
            else {
                if(num < maxHeap.top()) {
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
                
                else minHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        int lSize = maxHeap.size();
        int rSize = minHeap.size();
        
        if(lSize > rSize) return (double) (maxHeap.top());
        else return (((double) maxHeap.top() + (double) minHeap.top()) / 2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */