class ExamRoom {
    int size, seatsTaken = 0;
    set<int> pq;
    
public:
    ExamRoom(int n) {
        size = n;
    }
    
    int seat() {
        int ans = 0, pos = 0;
        
        if(!seatsTaken) {
           pq.insert(0);
           seatsTaken++;
           return 0;
        }
        
        int prev = 0;
        int val = *pq.begin();
        if(val != 0) ans = val;          

        prev = val;
        
        for(auto iter=pq.begin(); iter!=pq.end(); iter++){
            int val =* iter;
            if(ans < (val-prev) / 2) {
                    ans = (val - prev) / 2; 
                    pos = prev + (val - prev) / 2;
            } 
            
            prev = val;
        }
        
        if(*pq.rbegin() != size-1) 
            if((size - 1 - prev) > ans) pos = size - 1;
        
        seatsTaken++;
        pq.insert(pos);
        return pos;

    }
    
    void leave(int p) {
        seatsTaken--;
        pq.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */