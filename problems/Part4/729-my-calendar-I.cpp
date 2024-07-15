class MyCalendar {
    map<int, int> record;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        record[start]++; 
        record[end]--;
        
        int sum = 0;
        
        for(auto it=record.begin(); it!=record.end(); it++) {
            sum += it->second;
            
            if(sum>1) {
                record[start]--;
                record[end]++;
                
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */