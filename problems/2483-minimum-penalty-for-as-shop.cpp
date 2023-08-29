class Solution {
public:
    int bestClosingTime(string customers) {
        int currScore = 0, maxScore = 0;
        int bestHour = -1;

        for(int i=0; i<customers.size(); i++) {
            currScore += (customers[i] == 'Y') ? 1 : -1;

            if(currScore > maxScore) {
                maxScore = currScore;
                bestHour = i;
            }
        }

        return bestHour + 1;
    }
};