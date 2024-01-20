class Solution {
    int mod = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMin(n, n), rightMin(n, -1);
        stack<int> st;
        long long sum = 0;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if(!st.empty()) leftMin[i] = st.top();

            st.push(i);
        }

        st = {};

        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if(!st.empty()) rightMin[i] = st.top();

            st.push(i);

            int leftLen = i - leftMin[i];
            int rightLen = rightMin[i] - i;

            sum = (sum + ((long) arr[i] * leftLen * rightLen) % mod) % mod;
        }

        return sum;
    }
};
