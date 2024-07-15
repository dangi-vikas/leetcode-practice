class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> ans(n, 0);
        
        bool end = true;
        int lastTime = 0;
        
        for(auto &a : logs) {
            auto d = a.find_first_of(':');
            int task = stoi(a.substr(0, d));
            int time = stoi(a.substr(a.find_last_of(':')+1));
            
            if(a[d+1] == 's') {
                if(!end) 
                    ans[st.top()] += time - lastTime;
                
                else
                    if(st.size()>0)
                        ans[st.top()] += time - lastTime - 1;
                
                end = false;
                st.push(task);
            }
            
            else {
                if(end) ans[task] += time - lastTime;
                else ans[task] += time - lastTime + 1;
                
                st.pop();
                end = true;
            }
            
            lastTime = time;
        }
        
        return ans;
    }
};