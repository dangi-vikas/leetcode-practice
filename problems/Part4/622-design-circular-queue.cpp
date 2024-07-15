class MyCircularQueue {
    vector<int> q;
    int front=0, rear=0, size=0;
    
public:
    MyCircularQueue(int k) {
       q = vector<int>(k, -1);
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        
        if(isEmpty()) {
            front = rear = 0;
            size++;
            q[rear] = value;
            return true;
        }
        
        rear++;
        size++;
        rear = rear % q.size();
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        q[front] = -1;
        front++;
        size--;
        front = front % q.size();
        return true;
    }
    
    int Front() {
        return q[front];
    }
    
    int Rear() {
        return q[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == q.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */