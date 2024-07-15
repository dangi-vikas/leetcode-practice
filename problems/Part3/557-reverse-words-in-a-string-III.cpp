class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, k = 0;
        int n = s.length();

        while(k < n) {
            while(s[j] != ' ' && j != n) j++;

            k = j;
            j--;

            while(i <= j) {
                swap(s[i], s[j]);
                i++; 
                j--;
            }

            k++;
            i = k;
            j = k;
        }

        return s;
    }
};