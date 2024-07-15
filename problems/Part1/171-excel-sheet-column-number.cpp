class Solution {
public:
    int titleToNumber(string columnTitle) {
        int l = columnTitle.length();
        int x = l-1;
        int sum = 0;
        
        for(int i = 0; i < l; i++)
        {
            int index = columnTitle[i] - 'A';
            sum = sum + (index * pow(26,x));
            x = x-1;
        }

        int prev_val = 0;

        for(int i = 1; i < l; i++)
        {
            prev_val= prev_val + pow(26,i);
        }

        int ans = sum + prev_val+1;

        return ans;
    }
};