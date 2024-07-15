class RLEIterator {
    int index = 0;
	vector<int> encoding;


public:
    RLEIterator(vector<int>& encoding) {
        this->encoding = encoding;
		this->index = 0;
    }
    
    int next(int n) {
        int len = encoding.size();

		while(index < len && n > 0) {
			if(encoding[index] == 0) {
				index += 2;
				continue;
			}

			if(n <= encoding[index]) {
				encoding[index] -= n;
				n = 0;
			} 
            
            else {
				n -= encoding[index];
				index += 2;
			}
		}
        
		return n == 0 && index < len ? encoding[index + 1] : -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */