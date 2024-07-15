class Solution {
public:
    bool winnerOfGame(std::string colors) {
        int alicePlays = 0, bobPlays = 0, count = 0;
        
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i-1]) count++;
            
            else {
                if (colors[i - 1] == 'A') 
                    alicePlays += max(0, count - 1);
                else bobPlays += max(0, count - 1);
                
                count = 0;
            }
        }

        if (colors.back() == 'A')
            alicePlays += max(0, count - 1);
        else bobPlays += max(0, count - 1);
      
        return alicePlays > bobPlays;
    }
};