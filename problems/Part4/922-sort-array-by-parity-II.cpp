class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
      int n = nums.size();
      vector<int> ans(n, 0);
      int posIndex = 0, negIndex = 1;

      for(auto n : nums) {
        if(n % 2 == 0) {
          ans[posIndex] = n;
          posIndex = posIndex + 2;
        } 
        
        else {
          ans[negIndex] = n;
          negIndex = negIndex + 2;
        }
      }

      return ans;
    }
};
