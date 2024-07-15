class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        int n = name.length(), m = typed.length();
        
        while (i < n && j < m) {
            if (typed[j] != name[i])
                return false;

            char c = name[i];

            for(; i < n && name[i] == c && typed[j] == c; ++i, ++j); 
            for(; j < m && typed[j] == c; ++j);
        }
        
        return i == n && j == m;
    }
};
