class Solution {
public:
    int totalMoney(int n) {
        int weekCount = n / 7;
        int remainingDays = n % 7;
        
        int total = ((weekCount * (weekCount - 1)) / 2) * 7; 
        total += weekCount * 28;
        total += ((remainingDays * (remainingDays + 1)) / 2) + (weekCount * remainingDays); 
        
        return total;
    }
};
