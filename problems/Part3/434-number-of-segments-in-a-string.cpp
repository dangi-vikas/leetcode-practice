class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        istringstream ss(s);
        string i;
        
        while(getline(ss, i, ' '))
            if(i != "") count++;
        
        return count;
    }
};