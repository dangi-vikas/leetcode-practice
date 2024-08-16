class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int smallest = arrays[0][0];
        int biggest = arrays[0].back();
        int maxDistance = 0;

        for(int i=1; i<arrays.size(); i++) {
            maxDistance = max(maxDistance, abs(arrays[i].back() - smallest));
            maxDistance = max(maxDistance, abs(biggest - arrays[i][0]));
            smallest = min(smallest, arrays[i][0]);
            biggest = max(biggest, arrays[i].back());
        }

        return maxDistance;
    }
};