class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const auto rows = matrix.size();
        const auto cols = matrix.front().size();
        vector<vector<int>> table( rows, vector<int>( cols, 0 ) );
        int squares = 0;

        for( int i = 0; i < rows; i++){
            for( int j = 0; j < cols; ++j ){
                table[i][j] = matrix[i][j] - '0';
                if ( i != 0 && j != 0 && table[i][j] != 0 )
                    table[i][j] += min(min( table[i - 1][j - 1], table[i][j - 1] ), table[i - 1][j] );
                
                squares = max( squares, table[i][j] );
            }
        }

        return squares * squares;
    }
};
