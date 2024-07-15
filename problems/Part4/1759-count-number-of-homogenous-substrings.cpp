class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int start = 0;
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] != s[start]) {
                int appear = i - start;

                while(appear > 0) {
                    ans += appear;
                    appear--;
                }

                start = i;
            }
        }

        int appear = s.size() - start;

        while(appear > 0) {
            ans += appear;
            appear--;
        }

        return (int)(ans % (1000000007)); 
    }
};