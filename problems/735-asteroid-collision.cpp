class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int ast : asteroids) {
            bool isDestroyed = false;
            
            while(!st.empty() && ast<0 && st.top()>0) {
                if(-ast > st.top()) st.pop();
                
                else if(-ast < st.top()) {
                    isDestroyed = true;
                    break;
                }

                else {
                    st.pop();
                    isDestroyed = true;
                    break;
                }
            }
            
            if(!isDestroyed) st.push(ast);
        }
        
        vector<int> ans(st.size());
        int i = st.size() - 1;
        
        while(!st.empty()) {
            ans[i--] = st.top();
            st.pop();
        }
        
        return ans;
    }
};