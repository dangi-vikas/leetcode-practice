class Solution {
public:
    bool isUgly(int n) {
        if(n==0) return false;
        
        int res=n;
        
        while(true){
            if(res%2==0) res=res/2;
            else if(res%3==0) res=res/3;
            else if(res%5==0) res=res/5;
            
            else if (res==1) return true;
            else return false;
        }
        
        return true;
    }
};