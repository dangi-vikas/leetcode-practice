class Solution {
public:
   int largestVariance(string s) {
        int ans = 0;
        unordered_set<char> unique(begin(s), end(s));

        for(char a : unique)
            for(char b : unique) {
                int var = 0, hasB = 0, firstB = 0;

                for(auto ch : s) {
                    var += (ch == a);

                    if(ch == b) {
                        hasB = true;

                        if(firstB && var >= 0) firstB = false;
                        else if (--var < 0) {
                            firstB = true;
                            var = -1;
                        }
                    }

                    ans = max(ans, hasB ? var : 0);
                }
            }

        return ans;
    }
};