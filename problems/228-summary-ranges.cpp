class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        
        if(n == 0) return ans;
        
        int a = nums[0];
        
        for(int i=0; i<n; i++){

            //when the number is not consecutive or is last element
            if(i == n-1 || nums[i]+1 != nums[i+1]){
                
                //a not equal to b
                if(a != nums[i])
                    ans.push_back(to_string(a) + "->" + to_string(nums[i]));
                
                //a equal to b
                else ans.push_back(to_string(a));

                //changing a if the numbers are not consecutive
                if(i != n-1) a = nums[i+1];
            }
        }
        
        return ans;
    }
};