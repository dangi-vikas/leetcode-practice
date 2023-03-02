class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int validIndex = 0;
        int n = chars.size();

        while(i < n) {
            int j = i + 1;

            while(j < n && chars[i] == chars[j]) j++;

            chars[validIndex++] = chars[i];
            int count = j - i;

            if(count > 1) {
                string countString = to_string(count);
                for(char ch : countString) chars[validIndex++] = ch;
            }

            i = j;
        }

        return validIndex;  
    }


};