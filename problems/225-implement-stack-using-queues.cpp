class MyStack {
public:
    queue<int> q;
    queue<int> qTemp;
    
    MyStack() {
        
    }
    
    void push(int x) {
        qTemp.push(x);
        
        while(!q.empty()){
            qTemp.push(q.front()); q.pop();
        }
        
        queue<int> temp = q;
        q = qTemp;
        qTemp = temp;
    }
    
    int pop() {
        int temp = q.front(); q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */ 
