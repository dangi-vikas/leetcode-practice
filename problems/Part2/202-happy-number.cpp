class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> happySet;
        int val, index;
        
        while(1){
            val = 0;
            
            //getting the value of after squaring and adding each digit 
            while(n){
                index = n%10;
                val += index*index;
                n /= 10;
            }
            
            //if it equals one
            if(val == 1) return true;

            //if the val is already in set then there must be a cycle
            else if(happySet.find(val) != happySet.end()) return false;
            
            //if val is distinct then inserting in the set
            happySet.insert(val);
            n = val;
        }
        
        return false;
    }
};