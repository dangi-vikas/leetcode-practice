class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = 0;
        queue<string> q;
        
        q.push(start);
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                string temp = q.front();
                q.pop();

                if(temp == end) return ans;

                for(auto it=bank.begin(); it!=bank.end(); it++) {
                    if(isUnitDiff(temp, *it)) {
                        q.push(*it);
                        bank.erase(it);
                        it--;
                    } 
                }
            }
            
            ans++;
        }
   
        return -1;
    }
    
    bool isUnitDiff(string& s1, string& s2) {
        int diffCount = 0;
        
        for(int i=0; i<s1.size(); i++) 
            if(s1[i] != s2[i]) diffCount++;
        
        return diffCount == 1;
    }
};