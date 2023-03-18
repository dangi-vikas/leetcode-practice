class BrowserHistory {
    vector<string> history;
    int x;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        x = 0;
    }
    
    void visit(string url) {
        int length = history.size() - 1;

        while(length > x) {
            history.pop_back();
            length--;
        }

        x++;
        history.push_back(url);
    }
    
    string back(int steps) {
        x -= steps;
        if(x < 0) x = 0;
        return history[x];
    }
    
    string forward(int steps) {
        x += steps;
        if(x >= history.size())  x = history.size() - 1;
        return history[x];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */