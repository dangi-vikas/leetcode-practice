class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int count = 0;
        queue<string> q;
        
        q.push(start);
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0; i<size; i++){
                string temp = q.front(); q.pop();
                
                if(temp == end) return count;
                
                for(auto it=bank.begin(); it!=bank.end(); it++){
                    if(diff(temp, *it) == 1){
                        q.push(*it);
                        bank.erase(it);
                        it--;
                    }
                }
            }
            
            count++;
        }
        
        return -1;
    }
    
    int diff(string s1, string s2){
        int count = 0; 
        
        for(int i=0; i<s1.length(); i++)
            if(s1[i] != s2[i]) count++; 
        
        return count;
    }
};