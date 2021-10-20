
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> a = {0};

        for (int i = 0; i < n; i++) 
            for (int size = a.size(), j = size-1; j >= 0; --j)

                // inserting one or zero in front of the (n-1)th gray code
                //since 1<<3 is 1000(binary) and doing |(or) will place it in front of a[j]
                a.push_back(a[j] | (1 << i));

        return a;
    }
};