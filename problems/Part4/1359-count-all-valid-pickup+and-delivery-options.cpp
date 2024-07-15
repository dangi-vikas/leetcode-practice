class Solution {
    public:
    int MOD = (int)1e9 + 7; 

    long long calculateOrdersCount(long long remainingPairs) {
        if (remainingPairs == 0)
            return 1;

        long long currentResult = calculateOrdersCount(remainingPairs - 1) * (2 * remainingPairs - 1) * remainingPairs % MOD;

        return currentResult;
    }

    int countOrders(int numPairs) {
        return calculateOrdersCount(numPairs);
    }
};
