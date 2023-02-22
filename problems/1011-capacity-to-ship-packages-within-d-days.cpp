class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int capacity = 0, maxWeight = 0, sumOfWeights = 0;
        
        for(int weight : weights) {
            maxWeight = max(maxWeight, weight);
            sumOfWeights += weight;
        }

        int high = sumOfWeights, low = maxWeight;

        while(low <= high) {
            int mid = low + ((high - low) >> 1);

            if(canShip(weights, days, mid)) {
                capacity = mid;
                high = mid - 1;
            }

            else low = mid + 1;
        }

        return capacity;
    }

    bool canShip(vector<int>& weights, int days, int maxCapacity) {
        int currDays = 1, currCapacity = 0;

        for(int weight : weights) {
            if(weight > maxCapacity) return false;

            if(weight + currCapacity > maxCapacity) {
                currDays++;
                if(currDays > days) return false;
                currCapacity = weight;
            }

            else currCapacity += weight;
        }

        return true;
    }
};