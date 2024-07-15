class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closestSum = nums[0]+ nums[1] + nums[n-1];
        
        sort(nums.begin(), nums.end());

        //Size should be atleast 3 to make triplets   
        if(n<3) return 0;

        //traversing through the array once for first number    
        for(int i=0; i<n-2; i++){
            
            //checking only if the first number is not repeated
            if(i==0 || (i>0 && nums[i-1]!=nums[i])){
                
                /*initialising two pointers for each will traverse in opposite direction towards the other
                  forgetting the other two numbers*/ 
                int low=i+1, high=n-1;
                
                while(high>low){

                    //storing the current sum of the three numbers
                    int sum = nums[high] + nums[low] + nums[i];
                    
                    //moving the pointer to get closer to sum
                    if(sum <= target) low++;
                    else high--;
                    
                    //updating the closestSum if current sum is lesser
                    if(abs(sum-target)<abs(closestSum-target)) closestSum = sum;
                }
            }
        }
        
        return closestSum;
    }
};