class Solution {
public:
    bool judgeCircle(string moves) {
        int lr=0, ud=0;
        
        for(char move : moves) {
            if(move == 'U') ud++;
            if(move == 'D') ud--;
            if(move == 'L') lr++;
            if(move == 'R') lr--;
        }
        
        return lr==0 && ud==0;
    }
};