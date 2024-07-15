class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> differentTypes(candyType.begin(), candyType.end());
        int sheCanEat = n/2;
        
        if(sheCanEat > differentTypes.size())
            return differentTypes.size();
        
        return sheCanEat;
    }
};