class Solution {
public:
    int nextGreaterElement(int m) {
        long n = m; 
        vector<int> count(10);
        int currRem = -1, prevRem = -1;
        
        
        while(n) {
            currRem = n % 10;
            n /= 10;
            count[currRem]++;
            
            if(prevRem > currRem) {
                int num = currRem + 1;
                while(count[num] == 0) num++;
                count[num]--;
                n = n*10 + num;
                
                for(int i=0; i<10; i++) 
                    while(count[i]--) 
                        n = n*10 + i;
                
                return n > INT_MAX ? -1 : n;
            }
            
            prevRem = currRem;
        }
        
        return -1;
    }
};