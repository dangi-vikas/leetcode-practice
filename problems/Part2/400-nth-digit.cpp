class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1, cnt = 9, start = 1;
        while(n > len * cnt){
            n -= len * cnt;
            cnt *= 10;
            start *= 10;
            len++;
        }
        
        start += (n - 1) / len;
        string s = to_string(start);
        
        return s[(n - 1) % len] - '0';
    }
};