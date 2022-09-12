class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int left = 0, right = tokens.size()-1;
        int score = 0;
        
        while(left <= right) {
            if(power >= tokens[left]) {
                power -= tokens[left++];
                score++;
            }
            
            else {
                if(power+tokens[right] >= tokens[left] && score != 0 && left != right) {
                    power += tokens[right--];
                    score--;
                }
                
                else break;
            }
        }
        
        return score;
    }
};