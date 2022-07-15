class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 1) return ratings.size();
        
        int up = 0, down = 0;
        int prevSlope = 0;
        int candies = 0;
        
        for(int i=1; i<ratings.size(); i++) {
            int currSlope = ratings[i] > ratings[i-1] ? 1 :
                            ratings[i] < ratings[i-1] ? -1 : 0;
            
            if((prevSlope<0 && currSlope>=0) || (prevSlope>0 && currSlope==0)) {
                candies += sum(up) + sum(down) + max(up, down);
                up = 0; down = 0;
            }
            
            if(currSlope > 0) up++;
            else if(currSlope < 0) down++;
            else candies++;
            
            prevSlope = currSlope;
        } 
       
        candies += sum(up) + sum(down) + max(up, down) + 1;
        
        return candies;
    }

    int sum(int n) {
        return (n * (n+1)) >> 1; 
    }
};