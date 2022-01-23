class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        for(int i=0; i<s.size(); i++)
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 32;

        int j = s.size()-2, i = s.size()-1;
        int c = 0;
        
        while(j >= 0){
            if(s[i] != '-') c++;
            else s.erase(s.begin() + i, s.begin() + i + 1);

            if(c == k){
                s.insert(i, "-");
                c = 0;
            }

            j--; i--;
        }

        while(s[0] == '-') s.erase(0, 1);

        return s;
    }
};