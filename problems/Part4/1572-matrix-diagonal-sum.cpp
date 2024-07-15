class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size() - 1;
        int sum = 0;

        for(int i=0; i<=n; i++) {
            sum += (mat[i][i] + mat[i][n-i]);
            sum -= (i == (n-i)) ? mat[i][i] : 0;
        }

        return sum;
    }
};