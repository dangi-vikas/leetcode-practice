class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int prev = INT_MIN;
        
        for(int i=n-1; i>=0; i--) {
            if(nums[i] < prev) return true;
            
            while(st.size() && st.top() < nums[i]) {
                prev = max(prev, st.top());
                st.pop();
            }
                
            st.push(nums[i]);
        }
        
        return false;
    }
};