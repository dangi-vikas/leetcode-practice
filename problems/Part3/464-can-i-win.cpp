class Solution { 
    bool dp[4194303], mem[4194303];
    
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        bitset<20> bts;
        
        if(desiredTotal <= maxChoosableInteger) return 1;
        if(maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal) return 0;
        
        return canIWinRec(maxChoosableInteger, desiredTotal, 1, bts);
    }
    
    bool canIWinRec(int maxChoosableInteger, int desiredTotal, bool p, bitset<20> bts){
        bool &ret = dp[bts.to_ulong()];
        
        if(desiredTotal <= 0) return ret=!p;
        if(mem[bts.to_ulong()]) return ret;

        mem[bts.to_ulong()] = 1;

        for(int i=1; i<=maxChoosableInteger; i++){
            bitset<20> bts2 = bts;
            
            if(bts[i-1]) continue;
            
            bts2[i-1]=1;
            
            if(canIWinRec(maxChoosableInteger, desiredTotal-i, !p, bts2) == p)
                return ret=p;
        }
         
        return ret =! p;
    }
};