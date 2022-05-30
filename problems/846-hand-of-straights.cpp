class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        
        int groupCount = 0;
        map<int, int> cardCount;
        
        for(int card : hand) cardCount[card]++;
        
        for(auto it=cardCount.begin(); it!=cardCount.end(); it++) {
            while(it->second) {
                int curr = it->first;
                for(int card=curr; card<curr+groupSize; card++) {
                    if(cardCount.find(card) == cardCount.end() || cardCount[card] == 0) 
                        return false;
                    
                    cardCount[card]--;
                }
                
                groupCount++;
                
                if(groupCount == (int) hand.size() / groupSize) return true;
            }
        }
        
        return false;
    }
};