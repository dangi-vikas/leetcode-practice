class Solution {
public:
    string originalDigits(string s) {
        int n = s.length();
        
        vector<int> count(26, 0);
        vector<int> nums(10);
            
        string ans;
        
        for(auto& ch : s) count[ch - 'a']++;
        
        nums[0] = count['z' - 'a'];
        nums[2] = count['w' - 'a'];
        nums[4] = count['u' - 'a'];
        nums[6] = count['x' - 'a'];
        nums[8] = count['g' - 'a'];
        
        nums[1] = count['o'-'a'] - nums[0] - nums[2] - nums[4];
        nums[3] = count['h'-'a'] - nums[8];
        nums[5] = count['f'-'a'] - nums[4];
        nums[7] = count['s'-'a'] - nums[6];
        nums[9] = count['i'-'a'] - nums[5] - nums[6] - nums[8];
        
        for(int i=0; i<10; i++)
            while (nums[i]--) ans += (i + '0');
        
        return ans;
    }
};