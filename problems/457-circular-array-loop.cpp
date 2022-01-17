class Solution {
    
    int N = 0;
    
public:
    bool circularArrayLoop(vector<int>& nums) {
        N = nums.size();
        
		for (int& n : nums) 
			n %= N; 
        
		for (int i = 0; i < N; i++) {
			if (nums[i] == 0) continue;
            
			int sign = nums[i]/abs(nums[i]);
			int slow = i; 
            int fast = i;
            
			while (true) {
				fast = get_index(nums, fast);
					
                if (nums[fast] * sign <= 0) 
					break;
				
				fast = get_index(nums, fast);
                
				if (nums[fast] * sign <= 0) 
					break;
                
				i = get_index(nums, i); 
                
				if (i == fast) return true;
			}
            
			slow = i; 
            
			while (slow != fast) {
				int l = slow;
				slow = get_index(nums, slow);
				nums[l] = 0;
			}
		}
        
		return false;
    }
    
	int get_index(vector<int>& nums, int k) {
		return (k + nums[k] + N) % N;
	}
};