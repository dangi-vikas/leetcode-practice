class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size(); 
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());

        //Size should be atleast 4 to make quadruplets
        if(n<4) return ans;

        //traversing through the array once for first number
        for(int i=0; i<n; i++){

            //traversing through the array once for second number
            for(int j=i+1; j<n; j++){
                int sum = target - nums[i] -nums[j];

                /*initialising two pointers for each will traverse in opposite direction towards the other
                  for getting the other two numbers*/
                int high = n-1, low = j+1;
                
                while(high>low){
                    int tempSum = nums[low] + nums[high];
                    
                    //moving the pointer to get the required sum
                    if(tempSum<sum) low++;
                    else if(tempSum>sum) high--;
                    
                    else{
                        vector<int> temp;

                        //if the sums comes out equal to the required sum; pushing the numbers in the temporary vector
                        temp.push_back(nums[i]); temp.push_back(nums[j]);
                        temp.push_back(nums[low]); temp.push_back(nums[high]);
                        
                        //pushing the temporary vector in answer vector
                        ans.push_back(temp);
                        
                        //traversing till the next digit is unique
                        while(low<high && nums[low]==temp[2]) ++low;
                        while(low<high && nums[high]==temp[3]) --high;
                    }
                }

                //traversing till the next digit is unique
                while(j+1<n && nums[j]==nums[j+1]) ++j;
            }
            
            //traversing till the next digit is unique
            while(i+1<n && nums[i]==nums[i+1]) ++i;
        }
        
        return ans;
    }
};