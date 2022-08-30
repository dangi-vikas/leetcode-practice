class Solution {
    int mod = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> previousLess(n, n), nextLess(n, -1);
        stack<int> st;
        long long sum = 0;
        
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            
            if(!st.empty()) 
                previousLess[i] = st.top();
            
            st.push(i);
        }

        st = {};

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            
            if(!st.empty()) 
                nextLess[i] = st.top();
            
            st.push(i);
            
            sum += (long long) (previousLess[i] - i) * (i - nextLess[i]) * (long long) arr[i];
            
            sum %= mod;
        }
            
        
        return sum;
    }
};