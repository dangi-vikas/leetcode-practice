class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(), countT = 0, countF = 0;
        int i = 0, j = 0, maxCons = INT_MIN;
        
        while(j < n) {
            if(answerKey[j] == 'T') countT++;
            else countF++;
            
            while(countT > k && countF > k){
                if(answerKey[i] == 'T') countT--;
                else countF--;
                i++;
            }
            
            maxCons = max(maxCons, j-i+1);
            j++;
        }
        
        return maxCons;  
    }
};