class NumArray {
    vector<int> m_nums;
    
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        m_nums.resize(n + 1);
        
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            m_nums[i + 1] = s;
        }
    }
    
    int sumRange(int left, int right) {
        return m_nums[right + 1] - m_nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */