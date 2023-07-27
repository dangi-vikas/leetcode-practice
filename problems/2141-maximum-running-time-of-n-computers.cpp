class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long sumPower = 0;

        for(int power : batteries)
            sumPower += power;

        long left = 1, right = sumPower / n;
        
        while(left < right) {
            long time = (left + right + 1) / 2;

            if(canRun(batteries, n, time)) left = time;
            else right = time - 1;
        }

        return left;
    }
    
    bool canRun(vector<int>& batteries, int n, long time) {
        long sum = 0;

        for (int battery : batteries) 
            sum += min((long) battery, time);
        
        return (sum >= (long) time * n);
    }
};