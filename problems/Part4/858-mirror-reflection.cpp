class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ext = q, ref = p;
        
        while(ext%2 == 0 && ref%2 == 0) {
            ref /= 2; 
            ext /= 2;
        }
        
        if(ext%2 == 0 && ref%2 != 0) return 0;
        if(ext%2 != 0 && ref%2 != 0) return 1;
        if(ext%2 != 0 && ref%2 == 0) return 2;
        
        return -1;
    }
};