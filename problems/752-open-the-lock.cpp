class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target.length() == 0)
            return 0; 
        
        unordered_set<string> visited;
        
        for(string deadend : deadends)
            visited.insert(deadend);
        
        queue<string> q;
        q.push("0000");
        int level = 0;
        
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                string curr = q.front();
                q.pop();
                
                if(visited.find(curr) != visited.end()) continue;
                if(curr == target) return level;
                
                for(string next : getNextStates(curr))
                    if(visited.find(next) == visited.end())
                        q.push(next);
                
                visited.insert(curr);
            }
            
            level++;
        }
        
        return -1;
    }
    
    unordered_set<string> getNextStates(string lock) {
        unordered_set<string> newLocks;
        
        for(int i=0; i<4; i++) {
            char c = lock[i];
            lock[i] = c == '9' ? '0' : (char)(c+1);
            newLocks.insert(lock);
            lock[i] = c == '0' ? '9' : (char)(c-1);
            newLocks.insert(lock);
            lock[i] = c;
        }
        
        return newLocks;
    }
};
