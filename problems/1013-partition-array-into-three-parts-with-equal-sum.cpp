class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if (sum%3 != 0) return false;
        
        int val = sum/3, leftSum = 0;
        
        for(int i=0; i<arr.size()-2; i++) {
            leftSum += arr[i];  
            
            if (leftSum == val) {
                int midSum = 0;
                
                for(int j=i+1; j<arr.size()-1; j++) { 
                    midSum += arr[j];                    
                    if (midSum == val) return true;
                }
            }
        }
        
        return false; 
    }
};