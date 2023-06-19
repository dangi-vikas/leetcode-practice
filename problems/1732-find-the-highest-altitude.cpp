class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currHeight = 0, maxHeight = INT_MIN;

        for(int g : gain) {
            currHeight += g;
            maxHeight = max(maxHeight, currHeight);
        }

        return maxHeight >= 0 ? maxHeight : 0;
    }
};