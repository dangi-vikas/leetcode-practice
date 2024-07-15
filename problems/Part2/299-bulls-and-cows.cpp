class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows=0;
        vector<int> numbers(10, 0);
        
        for(int i=0; i<secret.length(); i++){
            char s = secret[i];
            char g = guess[i];
            
            if(s == g) bulls++;
            else{
                if(numbers[s-'0']++ < 0) cows++;
                if(numbers[g-'0']-- > 0) cows++;
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};