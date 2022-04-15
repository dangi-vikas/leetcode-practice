class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size()-1;
        int count = 0;
      
        if(letters[high] <= target && letters[low] != letters[high]){
          return letters[0];  
        }
        
        while(high >= low) {
            int mid = count + low + ((high-low) >> 1);
            
            if(letters[mid] == target) { 
                if(letters[mid+1] != target) return letters[mid+1]; 
                else count++;
            }
            
            else if(letters[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        
        return letters[low];
    }
};