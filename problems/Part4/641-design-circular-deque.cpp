class MyCircularDeque {
    vector<int> v;
	int l; 
	int front = -1, rear = -1;
    
public:
    MyCircularDeque(int k) {
        v = vector<int>(k);
        l = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
		if(isEmpty()) front = rear = 0;
		else front = (front-1 + l) % l;
        
		v[front] = value;
		return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
		if(isEmpty()) front = rear = 0;
		else rear = (rear+1) % l;
        
		v[rear] = value;
		return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
		else if(front == rear) front = rear = -1;
		else front = (front+1) % l;
		return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
		if(front == rear) front = rear = -1;
		else rear = (rear-1 + l) % l;
		return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
		return v[front];

    }
    
    int getRear() {
        if(isEmpty()) return -1;
		return v[rear];
    }
    
    bool isEmpty() {
        if(front==-1 &&  rear==-1)
			return true;
        
		return false;
    }
    
    bool isFull() {
        if((rear+1) % l == front) return true;
		return false;
    }
};
/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */