class Solution {
public:
  string reverseWords(string s) {
        int sz = s.size();
        int current_index, till;
        char c;
        
        for (int start_index = 0; start_index < sz;) {
            current_index = start_index;
            
            while (current_index < sz && s[current_index] != ' ') 
                current_index++;
            
            till = (current_index - start_index) / 2;
            
            for (int j = 0; j < till; j++) {
                c = s[start_index + j];
                s[start_index + j] = s[current_index - 1 - j];
                s[current_index - 1 - j] = c;
            }
            
            start_index = current_index + 1;
            
        }
        
        return s;
    }
};
