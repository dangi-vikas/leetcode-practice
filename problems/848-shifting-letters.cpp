class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int shift = 0;
        
        for(int i=shifts.size()-1; i>=0; i--) {
            shift = (shift + shifts[i]) % 26;
            s[i] = char((s[i] - 'a' + shift) % 26 + 'a');
        }
        
        return s;
    }
};