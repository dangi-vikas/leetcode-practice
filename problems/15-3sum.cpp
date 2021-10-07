class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        //Size should be atleast 3 to make triplets
        if(n<3) return ans;
        
        //traversing through the array once for first number
        for(int i=0; i<nums.size()-2; i++){
            
            //checking only if the first number is not repeated
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){

                /*initialising two pointers for each will traverse in opposite direction towards the other
                  forgetting the other two numbers*/ 
                int low=i+1, high=nums.size()-1, sum= -nums[i]; 
                
                while(low<high){

                    //as nums[i] + nums[low] + nums[high] == 0
                    if(nums[high]+nums[low] == sum){
                        vector<int> temp;
                        
                        //pushing the three numbers in temporary vector 
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]); temp.push_back(nums[high]); 

                        //pushing the temporary vector in answer vector
                        ans.push_back(temp);
                        
                        //traversing till the next digit is unique
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        
                        low++; high--;
                    }
                    
                    //if three numbers do not sum to 0
                    else if(nums[high]+nums[low] < sum) low++;
                    else high--;
                }
            }
        }
    
        return ans;
    }
};