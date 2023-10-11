class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans(people.size());

        vector<int> flowerStarts;
        vector<int> flowerEnds;

        for(const auto& flower : flowers) {
            flowerStarts.push_back(flower[0]);
            flowerEnds.push_back(flower[1] + 1);
        }

        vector<pair<int, int>> peopleWithId;
        peopleWithId.reserve(people.size());

        for (int i=0; i<people.size(); i++)
            peopleWithId.push_back(make_pair(people[i], i));
        
        sort(flowerStarts.begin(), flowerStarts.end());
        sort(flowerEnds.begin(), flowerEnds.end());
        sort(peopleWithId.begin(), peopleWithId.end());
        
        int nextFlowerStart = 0;
        int nextFlowerEnd = 0;
        int numFlowers = 0;

        for (int i=0; i<peopleWithId.size(); i++) {
            int targetTime = peopleWithId[i].first;
            int personId = peopleWithId[i].second;
            
            while (nextFlowerStart < flowerStarts.size() &&
                flowerStarts[nextFlowerStart] <= targetTime) {
                numFlowers++;
                nextFlowerStart++;
            }

            while(nextFlowerEnd < flowerEnds.size() && flowerEnds[nextFlowerEnd] <= targetTime) {
                numFlowers--;
                nextFlowerEnd++;
            }

            ans[personId] = numFlowers;
        }

        return ans;
    }
};