class MyCalendarTwo {
    map<int, int> record;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        record[start]++;
        record[end]--;
        
        int sum = 0; 
        
        for(auto it=record.begin(); it!=record.end(); it++) {
            sum += it->second;
            
            if(sum > 2) {
                record[start]--;
                record[end]++;
                
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */