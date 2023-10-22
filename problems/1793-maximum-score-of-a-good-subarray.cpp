class Solution {
public:

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), score = 0;
        vector<int> leftSmallest = nearestSmallestLeft(nums);
        vector<int> rightSmallest = nearestSmallestRight(nums);
 
        for(int i=0; i<n; i++) {
            int left = leftSmallest[i], right = rightSmallest[i];

            if(k > left && k < right) 
                score = max(score, nums[i] * (right - left - 1)); 
        }

        return score;
    }

    vector<int> nearestSmallestRight(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> rightMin(n);

        rightMin[n-1] = n;
        st.push(n-1);

        for(int i=n-2; i>=0; i--) {
            while(st.size() && nums[st.top()] >= nums[i]) st.pop();

            if(st.empty()) rightMin[i] = n;
            else rightMin[i] = st.top();

            st.push(i);
        }

        return rightMin;
    }
    
    vector<int> nearestSmallestLeft (vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int> leftMin(n);

        leftMin[0] = -1;
        st.push(0);

        for(int i=1; i<n; i++){
            whilclass Solution {
public:

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), score = 0;
        vector<int> leftSmallest = nearestSmallestLeft(nums);
        vector<int> rightSmallest = nearestSmallestRight(nums);
 
        for(int i=0; i<n; i++) {
            int left = leftSmallest[i], right = rightSmallest[i];

            if(k > left && k < right) 
                score = max(score, nums[i] * (right - left - 1)); 
        }

        return score;
    }

    vector<int> nearestSmallestRight(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> rightMin(n);

        rightMin[n-1] = n;
        st.push(n-1);

        for(int i=n-2; i>=0; i--) {
            while(st.size() && nums[st.top()] >= nums[i]) st.pop();

            if(st.empty()) rightMin[i] = n;
            else rightMin[i] = st.top();

            st.push(i);
        }

        return rightMin;
    }
    
    vector<int> nearestSmallestLeft (vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int> leftMin(n);

        leftMin[0] = -1;
        st.push(0);

        for(int i=1; i<n; i++){
            while(st.size() && nums[st.top()] >= nums[i]) st.pop();

            if(st.empty()) leftMin[i] = -1;
            else leftMin[i] = st.top();

            st.push(i);
        }

        return leftMin;
    }
};e(st.size() && nums[st.top()] >= nums[i]) st.pop();

            if(st.empty()) leftMin[i] = -1;
            else leftMin[i] = st.top();

            st.push(i);
        }

        return leftMin;
    }
};