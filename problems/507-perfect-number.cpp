class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        
        int ans = 1, i = 2;
            
        while (i <= sqrt(num)){
            if (num % i == 0)
                ans += i + num/i;
            
            i++;
        }
            
        return ans == num ;
    }
};