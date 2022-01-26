class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;
        stack<int> st;
        
        for(auto num2 : nums2){ 
            while(!st.empty() && st.top()<num2){
                nge[st.top()] = num2;
                st.pop();
            }
            
            st.push(num2);
        }
        
        while(!st.empty()){
            nge[st.top()] = -1;
            st.pop();
        }
        
        vector<int> ans;
        
        for(auto num1 :nums1) 
            ans.push_back(nge[num1]);
        
        return ans;
    }
};