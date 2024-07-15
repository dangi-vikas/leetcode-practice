class Solution {
public:
    string largestNumber(vector<int>& nums) {
	    
        //sorting on comparison with each element
        sort(nums.begin(),nums.end(),comparator);
        string ans="";
        
        for(int i=0;i<nums.size();i++) ans+=to_string(nums[i]);
        
        if(nums[0]==0) return "0";   
        
        return ans;
    }
    
    //function to compare two numbers in nums
    static bool comparator(int a ,int b){
        string x = to_string(a) + to_string(b);
        string y = to_string(b) + to_string(a);
        return x > y;
    }
};