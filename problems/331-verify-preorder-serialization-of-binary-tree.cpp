class Solution {
public:
    bool isValidSerialization(string preorder) {
        int vacancy = 1;
        istringstream ss(preorder);
        string i;
        
        while(getline(ss, i, ',')){
            vacancy--;
            
            if(vacancy < 0) return false;
            
            if(i != "#") vacancy += 2;
        }
        
        return vacancy == 0 ;
    }
};